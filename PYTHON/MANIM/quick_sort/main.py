from manim import *
import random

class QuickSortCustom(Scene):
    def construct(self):
        # Fondo negro
        self.camera.background_color = BLACK
        
        # Generar 9 números aleatorios únicos entre 1 y 100
        numeros = random.sample(range(1, 101), 9)
        
        # Inicializar
        self.numeros = numeros.copy()
        self.celdas = []
        self.ordenados = set()
        
        # Colores para diferentes segmentos
        self.colores_segmentos = [BLUE, TEAL, PURPLE, GOLD, PINK, LIGHT_BROWN]
        self.color_index = 0
        
        # Crear cada celda individualmente
        for num in self.numeros:
            rect = Rectangle(height=0.8, width=0.8, color=ORANGE, fill_opacity=0, stroke_width=2.5)
            texto = Text(str(num), font_size=22, color=WHITE)
            texto.move_to(rect.get_center())
            celda = VGroup(rect, texto)
            self.celdas.append(celda)
        
        # Organizar en el grupo principal
        self.grupo_principal = VGroup(*self.celdas)
        self.grupo_principal.arrange(RIGHT, buff=0.15)
        self.grupo_principal.scale(1.0)
        self.grupo_principal.move_to(ORIGIN)
        self.add(self.grupo_principal)
        
        # Guardar configuración
        self.escala_celdas = 1.0
        self.buff_celdas = 0.15
        
        # Área para el pivote extraído (abajo)
        self.texto_pivote_area = Text("PIVOTE", font_size=20, color=ORANGE)
        self.texto_pivote_area.to_edge(DOWN, buff=0.3)
        self.add(self.texto_pivote_area)
        
        # Posición fija para el pivote extraído
        self.pivote_extraido_pos = DOWN * 2.5
        
        # Animar aparición
        self.play(LaggedStart(*[Create(celda) for celda in self.celdas], lag_ratio=0.08), run_time=2.5)
        self.wait(1)
        
        # Ejecutar Quicksort
        self.quick_sort(0, len(self.numeros) - 1, es_primera=True)
        
        # Final
        self.play(FadeOut(self.texto_pivote_area), run_time=0.5)
        final_text = Text("¡ORDENADO!", font_size=36, color=GREEN)
        final_text.to_edge(DOWN, buff=0.3)
        self.play(Write(final_text), run_time=1)
        self.wait(2)
    
    def marcar_ordenados(self):
        """Marca en verde los elementos que ya están en su posición final"""
        for idx in self.ordenados:
            if idx < len(self.celdas):
                self.celdas[idx][0].set_stroke(GREEN, width=3)
    
    def marcar_segmento(self, inicio, fin, color):
        """Marca un segmento con un color específico y agrega una llave"""
        if inicio > fin or inicio >= len(self.celdas) or fin >= len(self.celdas):
            return
        
        # Cambiar color de los bordes del segmento
        for i in range(inicio, fin + 1):
            if i not in self.ordenados:
                self.play(self.celdas[i][0].animate.set_stroke(color, width=3), run_time=0.08)
        
        # Crear llave debajo del segmento - POSICIÓN AJUSTADA
        primera_celda = self.celdas[inicio].get_center()
        ultima_celda = self.celdas[fin].get_center()
        
        # Llave en DOWN * 1.2 (entre flechas y pivote)
        llave = BraceBetweenPoints(
            primera_celda + DOWN * 1.2,
            ultima_celda + DOWN * 1.2,
            color=color,
            stroke_width=3
        )
        
        texto_llave = Text(f"Segmento {self.color_index}", font_size=14, color=color)
        texto_llave.next_to(llave, DOWN, buff=0.1)
        
        self.play(GrowFromCenter(llave), Write(texto_llave), run_time=0.5)
        
        # Guardar para limpiar después
        if not hasattr(self, 'llaves_activas'):
            self.llaves_activas = []
        self.llaves_activas.append((llave, texto_llave))
        
        self.color_index += 1
    
    def limpiar_llaves(self):
        """Limpia todas las llaves activas"""
        if hasattr(self, 'llaves_activas'):
            for llave, texto in self.llaves_activas:
                self.play(FadeOut(llave), FadeOut(texto), run_time=0.3)
            self.llaves_activas = []
    
    def reorganizar_posiciones(self, offset_y=0):
        """Reorganiza todas las celdas en sus posiciones correctas con offset opcional"""
        ancho_celda = 0.8 * self.escala_celdas
        espaciado = self.buff_celdas * self.escala_celdas
        ancho_total = (ancho_celda + espaciado) * len(self.celdas)
        inicio_x = -ancho_total / 2 + ancho_celda / 2
        
        animaciones = []
        for j, celda in enumerate(self.celdas):
            nueva_x = inicio_x + j * (ancho_celda + espaciado)
            nueva_pos = np.array([nueva_x, offset_y, 0])
            animaciones.append(celda.animate.move_to(nueva_pos))
        
        self.play(*animaciones, run_time=0.4)
        self.wait(0.1)
        self.marcar_ordenados()
    
    def crear_flecha(self, punto, color, texto, direccion="down"):
        """Crea flecha con etiqueta"""
        altura_flecha = 1.3
        tamano_flecha = 0.35
        tamano_texto = 11
        
        if direccion == "down":
            flecha = Arrow(
                punto + DOWN * altura_flecha, 
                punto + DOWN * (altura_flecha - tamano_flecha), 
                color=color, 
                stroke_width=2.5,
                buff=0,
                tip_length=0.15
            )
            etiqueta = Text(texto, font_size=tamano_texto, color=color, weight=BOLD)
            etiqueta.next_to(flecha.get_start(), DOWN, buff=0.03)
        else:
            flecha = Arrow(
                punto + LEFT * altura_flecha, 
                punto + LEFT * (altura_flecha - tamano_flecha), 
                color=color, 
                stroke_width=2.5,
                buff=0,
                tip_length=0.15
            )
            etiqueta = Text(texto, font_size=tamano_texto, color=color, weight=BOLD)
            etiqueta.next_to(flecha.get_start(), LEFT, buff=0.03)
        return VGroup(flecha, etiqueta)
    
    def extraer_pivote(self, idx, es_detallado):
        """Extrae el pivote y lo muestra abajo"""
        # Mover todos los elementos hacia arriba
        self.reorganizar_posiciones(offset_y=0.8)
        
        pivote_celda = self.celdas[idx]
        pivote_valor = self.numeros[idx]
        
        tiempo = 0.8 if es_detallado else 0.4
        self.play(pivote_celda.animate.move_to(self.pivote_extraido_pos), run_time=tiempo)
        
        self.celdas.pop(idx)
        self.numeros.pop(idx)
        
        # Reorganizar sin el pivote, manteniendo la posición elevada
        self.reorganizar_posiciones(offset_y=0.8)
        
        return pivote_celda, pivote_valor
    
    def recolocar_pivote(self, pivote_objeto, posicion, es_detallado):
        """Reinserta el pivote en su posición"""
        self.celdas.insert(posicion, pivote_objeto)
        texto_num = pivote_objeto[1].text
        self.numeros.insert(posicion, int(texto_num))
        
        # Reorganizar con el pivote incluido, aún elevado
        self.reorganizar_posiciones(offset_y=0.8)
        
        self.ordenados.add(posicion)
        
        if es_detallado:
            self.play(pivote_objeto[0].animate.set_stroke(GREEN, width=4), run_time=0.5)
            self.play(pivote_objeto[0].animate.set_stroke(GREEN, width=3), run_time=0.3)
        
        # Volver a bajar todos los elementos a su posición normal
        self.reorganizar_posiciones(offset_y=0)
        self.marcar_ordenados()
    
    def animar_intercambio(self, idx1, idx2, es_detallado):
        """Intercambia dos celdas"""
        if idx1 == idx2:
            return
        
        pos1 = self.celdas[idx1].get_center()
        pos2 = self.celdas[idx2].get_center()
        tiempo = 0.6 if es_detallado else 0.35
        
        self.play(
            self.celdas[idx1].animate.move_to(pos2),
            self.celdas[idx2].animate.move_to(pos1),
            run_time=tiempo,
            rate_func=rate_functions.ease_in_out_quad
        )
        
        self.celdas[idx1], self.celdas[idx2] = self.celdas[idx2], self.celdas[idx1]
        self.numeros[idx1], self.numeros[idx2] = self.numeros[idx2], self.numeros[idx1]
    
    def animar_comparacion(self, celda, pivote_valor, es_menor):
        """Animación de comparación VISUAL entre i y el pivote"""
        valor_actual = int(celda[1].text)
        
        comparacion_texto = Text(f"{valor_actual} {'<' if es_menor else '>'} {pivote_valor}", 
                                  font_size=20, 
                                  color=GREEN if es_menor else RED,
                                  weight=BOLD)
        comparacion_texto.next_to(celda, UP, buff=0.5)
        
        self.play(Write(comparacion_texto), run_time=0.4)
        
        if es_menor:
            self.play(celda[0].animate.set_stroke(GREEN, width=5), run_time=0.3)
            self.play(celda[0].animate.set_stroke(ORANGE, width=2.5), run_time=0.2)
        else:
            self.play(celda[0].animate.set_stroke(RED, width=5), run_time=0.3)
            self.play(celda[0].animate.set_stroke(ORANGE, width=2.5), run_time=0.2)
        
        self.play(FadeOut(comparacion_texto), run_time=0.2)
    
    def partition(self, inicio, fin, es_detallado):
        # Marcar este segmento con llave y color
        color_segmento = self.colores_segmentos[self.color_index % len(self.colores_segmentos)]
        self.marcar_segmento(inicio, fin, color_segmento)
        
        # Extraer pivote
        pivote_objeto, pivote_valor = self.extraer_pivote(fin, es_detallado)
        fin -= 1
        
        peque = inicio - 1
        
        if inicio < len(self.celdas):
            punto_peque_inicial = self.celdas[inicio].get_center() + LEFT * 1.0
        else:
            punto_peque_inicial = LEFT * 3
        
        # Crear flechas
        if inicio < len(self.celdas):
            flecha_start = self.crear_flecha(self.celdas[inicio].get_bottom(), RED, "start", "down")
            flecha_end = self.crear_flecha(self.celdas[fin].get_bottom(), RED, "end", "down") if fin >= 0 else None
            flecha_i = self.crear_flecha(self.celdas[inicio].get_bottom(), BLUE, "i", "down")
        else:
            flecha_start = self.crear_flecha(UP * 2, RED, "start", "down")
            flecha_end = None
            flecha_i = self.crear_flecha(UP * 2, BLUE, "i", "down")
        
        flecha_peque = self.crear_flecha(punto_peque_inicial, GREEN, "peque", "down")
        
        animaciones = [FadeIn(flecha_start), FadeIn(flecha_i), FadeIn(flecha_peque)]
        if flecha_end:
            animaciones.append(FadeIn(flecha_end))
        self.play(*animaciones, run_time=0.5)
        
        i = inicio
        while i <= fin and i < len(self.celdas):
            # Mover flecha i
            if i < len(self.celdas):
                self.play(flecha_i.animate.move_to(self.celdas[i].get_bottom() + DOWN * 0.8), run_time=0.3)
            
            # Animación de comparación visual
            if i < len(self.celdas):
                es_menor = self.numeros[i] < pivote_valor
                self.animar_comparacion(self.celdas[i], pivote_valor, es_menor)
            
            if i < len(self.celdas) and self.numeros[i] < pivote_valor:
                peque += 1
                
                # Mover flecha peque
                if peque >= inicio and peque < len(self.celdas):
                    self.play(flecha_peque.animate.move_to(self.celdas[peque].get_bottom() + DOWN * 0.8), run_time=0.3)
                elif peque >= inicio:
                    punto = self.celdas[inicio].get_center() + LEFT * 1.0
                    self.play(flecha_peque.animate.move_to(punto), run_time=0.3)
                
                if peque != i and peque < len(self.celdas) and i < len(self.celdas):
                    self.animar_intercambio(peque, i, es_detallado)
            
            i += 1
        
        pivote_pos = peque + 1
        self.recolocar_pivote(pivote_objeto, pivote_pos, es_detallado)
        
        # Limpiar flechas
        animaciones_limpiar = [FadeOut(flecha_start), FadeOut(flecha_i), FadeOut(flecha_peque)]
        if flecha_end:
            animaciones_limpiar.append(FadeOut(flecha_end))
        self.play(*animaciones_limpiar, run_time=0.4)
        
        # Limpiar la llave de este segmento
        self.limpiar_llaves()
        
        return pivote_pos
    
    def quick_sort(self, inicio, fin, es_primera=False):
        if inicio >= fin or inicio < 0 or fin >= len(self.numeros):
            return
        pivote_idx = self.partition(inicio, fin, es_detallado=es_primera)
        self.quick_sort(inicio, pivote_idx - 1, es_primera=False)
        self.quick_sort(pivote_idx + 1, fin, es_primera=False)