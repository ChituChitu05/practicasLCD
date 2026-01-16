let elementoSVG;
const NAMESPACE_SVG = "http://www.w3.org/2000/svg";

function establecerRetrasoAnimacion(elemento, tiempo) {
    elemento.style.animationDelay = `${tiempo}s`;
}

function crearPuertaAND(posicionX, posicionY, tiempo = 0) {
    const camino = document.createElementNS(NAMESPACE_SVG, "path");
    camino.setAttribute("d", `
        M ${posicionX} ${posicionY}
        L ${posicionX+40} ${posicionY}
        A 40 40 0 0 1 ${posicionX+40} ${posicionY+80}
        L ${posicionX} ${posicionY+80}
        Z
    `);
    camino.setAttribute("class", "puerta");
    establecerRetrasoAnimacion(camino, tiempo);
    elementoSVG.appendChild(camino);
    return camino;
}

function crearPuertaOR(posicionX, posicionY, tiempo = 0) {
    const camino = document.createElementNS(NAMESPACE_SVG, "path");
    camino.setAttribute("d", `
        M ${posicionX} ${posicionY}
        Q ${posicionX+25} ${posicionY+40} ${posicionX} ${posicionY+80}
        Q ${posicionX+70} ${posicionY+40} ${posicionX} ${posicionY}
        Z
    `);
    camino.setAttribute("class", "puerta");
    establecerRetrasoAnimacion(camino, tiempo);
    elementoSVG.appendChild(camino);
    return camino;
}

function crearBurbujaNOT(posicionX, posicionY, tiempo = 0) {
    const circulo = document.createElementNS(NAMESPACE_SVG, "circle");
    circulo.setAttribute("cx", posicionX);
    circulo.setAttribute("cy", posicionY);
    circulo.setAttribute("r", 4);
    circulo.setAttribute("class", "puerta burbuja-not");
    establecerRetrasoAnimacion(circulo, tiempo);
    elementoSVG.appendChild(circulo);
    return circulo;
}

function crearCableHorizontal(posicionX1, posicionY, posicionX2, tiempo = 0, clase = "cable") {
    const camino = document.createElementNS(NAMESPACE_SVG, "path");
    camino.setAttribute("d", `M ${posicionX1} ${posicionY} L ${posicionX2} ${posicionY}`);
    camino.setAttribute("class", clase);
    elementoSVG.appendChild(camino);

    const longitud = Math.abs(posicionX2 - posicionX1);
    camino.style.strokeDasharray = longitud;
    camino.style.strokeDashoffset = longitud;

    establecerRetrasoAnimacion(camino, tiempo);
    return camino;
}

function crearCableVertical(posicionX, posicionY1, posicionY2, tiempo = 0, clase = "cable") {
    const camino = document.createElementNS(NAMESPACE_SVG, "path");
    camino.setAttribute("d", `M ${posicionX} ${posicionY1} L ${posicionX} ${posicionY2}`);
    camino.setAttribute("class", clase);
    elementoSVG.appendChild(camino);

    const longitud = Math.abs(posicionY2 - posicionY1);
    camino.style.strokeDasharray = longitud;
    camino.style.strokeDashoffset = longitud;

    establecerRetrasoAnimacion(camino, tiempo);
    return camino;
}

function crearPuntoConexion(posicionX, posicionY, tiempo = 0, color = "#00e0ff") {
    const punto = document.createElementNS(NAMESPACE_SVG, "circle");
    punto.setAttribute("cx", posicionX);
    punto.setAttribute("cy", posicionY);
    punto.setAttribute("r", 3);
    punto.setAttribute("fill", color);
    punto.setAttribute("class", "punto-conexion");
    establecerRetrasoAnimacion(punto, tiempo);
    elementoSVG.appendChild(punto);
    return punto;
}

function crearEtiquetaCircuito(texto, posicionX, posicionY, tiempo = 0, clase = "texto-circuito") {
    const elementoTexto = document.createElementNS(NAMESPACE_SVG, "text");
    elementoTexto.textContent = texto;
    elementoTexto.setAttribute("x", posicionX);
    elementoTexto.setAttribute("y", posicionY);
    elementoTexto.setAttribute("class", clase);
    establecerRetrasoAnimacion(elementoTexto, tiempo);
    elementoSVG.appendChild(elementoTexto);
    return elementoTexto;
}

function parsearExpresionSumaProductos(expresion) {
    expresion = expresion.replace(/\s+/g, ' ');
    expresion = expresion.trim();
    const terminos = expresion.split('+').map(termino => termino.trim());
    
    return terminos.map(termino => {
        const variables = {};

        const coincidencias = termino.match(/[¬]?\(x\d+\)/g) || termino.match(/[¬]?x\d+/g);
        
        if (coincidencias) {
            coincidencias.forEach(coincidencia => {
                const numero = coincidencia.match(/\d+/)[0];
                const valor = coincidencia.includes('¬') ? 0 : 1;
                variables[`x${numero}`] = valor;
            });
        }
        
        for (let i = 1; i <= 5; i++) {
            const nombreVariable = `x${i}`;
            if (variables[nombreVariable] === undefined) {
                variables[nombreVariable] = 1;
            }
        }
        
        return variables;
    });
}

let configuracionLayout = {
    margen: 60,
    columnas: 5,
    ancho: 800,
    alto: 500
};

function calcularLayout(variables, numeroTerminos) {
    const anchoMinimo = 800; 
    const altoMinimo = 400;   
    
    // Aumentar ancho según número de términos
    const anchoBase = Math.max(anchoMinimo, 250 + numeroTerminos * 120); 
    
    // Aumentar altura según número de términos
    const altoBase = Math.max(altoMinimo, 150 + numeroTerminos * 80); 
    
    configuracionLayout.ancho = anchoBase;
    configuracionLayout.alto = altoBase;
    configuracionLayout.anchoInterno = configuracionLayout.ancho - configuracionLayout.margen * 2;
    configuracionLayout.altoInterno = configuracionLayout.alto - configuracionLayout.margen * 2;
    configuracionLayout.numeroTerminos = numeroTerminos;
    
    // Ajustar el SVG
    if (elementoSVG) {
        elementoSVG.setAttribute("width", configuracionLayout.ancho);
        elementoSVG.setAttribute("height", configuracionLayout.alto);
        elementoSVG.setAttribute("viewBox", `0 0 ${configuracionLayout.ancho} ${configuracionLayout.alto}`);
    }
}

function obtenerPosicionColumna(indice) {
    const espaciadoColumnas = configuracionLayout.anchoInterno / (configuracionLayout.columnas - 1);
    return configuracionLayout.margen + espaciadoColumnas * indice;
}

function obtenerPosicionFila(indice, total) {
    const ALTURA_BASE = 80; // Aumentar base
    const ESPACIADO = 100; // Aumentar espaciado
    
    let espaciadoActual = ESPACIADO;
    if (total > 5) {
        espaciadoActual = 80;
    }
    if (total > 10) {
        espaciadoActual = 60;
    }
    
    return ALTURA_BASE + (espaciadoActual * indice);
}

function generarCircuitoSOP(terminosSumaProductos) {
    const variables = ['x1', 'x2', 'x3', 'x4', 'x5'];
    const numeroTerminos = terminosSumaProductos.length;
    
    calcularLayout(variables, numeroTerminos);
    if (elementoSVG) {
        elementoSVG.setAttribute("width", configuracionLayout.ancho);
        elementoSVG.setAttribute("height", configuracionLayout.alto);
    }
    
    const columnaBase = obtenerPosicionColumna(0);
    const espaciado = 25;
    const posicionYInicio = configuracionLayout.margen;
    const posicionYFin = configuracionLayout.alto - configuracionLayout.margen;
    const posicionYEtiqueta = posicionYInicio - 8;
    const posicionesXEntrada = variables.map((_, indice) => columnaBase + indice * espaciado);
    
    variables.forEach((variable, indice) => {
        crearCableVertical(posicionesXEntrada[indice], posicionYInicio, posicionYFin, indice * 0.05);
        crearEtiquetaCircuito(variable, posicionesXEntrada[indice] - 6, posicionYEtiqueta, 0.2 + indice * 0.05);
    });
    
    const columnaNOT = obtenerPosicionColumna(1);
    const columnaAND = obtenerPosicionColumna(2);
    const salidasAND = [];
    const espaciadoConexiones = 8;
    const alturaAND = 90;
    const alturaGrupoConexiones = variables.length * espaciadoConexiones;
    
    terminosSumaProductos.forEach((termino, indiceTermino) => {
        const posicionYAND = obtenerPosicionFila(indiceTermino, numeroTerminos);
        
        // Dibujar puerta AND
        crearPuertaAND(columnaAND, posicionYAND - alturaAND/2, 0.4 + indiceTermino * 0.1);
        
        const posicionYBaseConexion = posicionYAND - alturaGrupoConexiones/2 + espaciadoConexiones/2;
        
        variables.forEach((variable, indiceVariable) => {
            const posicionXEntrada = posicionesXEntrada[indiceVariable];
            const posicionYConexion = posicionYBaseConexion + indiceVariable * espaciadoConexiones;
            
            if (termino[variable] === 0) {
                crearCableHorizontal(posicionXEntrada, posicionYConexion, columnaNOT - 10, 0.6 + indiceTermino * 0.1 + indiceVariable * 0.02);
                crearBurbujaNOT(columnaNOT - 5, posicionYConexion, 0.7 + indiceTermino * 0.1 + indiceVariable * 0.02);
                crearCableHorizontal(columnaNOT + 5, posicionYConexion, columnaAND, 0.8 + indiceTermino * 0.1 + indiceVariable * 0.02);
            } else {
                crearCableHorizontal(posicionXEntrada, posicionYConexion, columnaAND, 0.8 + indiceTermino * 0.1 + indiceVariable * 0.02);
            }
        });
        
        const posicionXSalidaAND = columnaAND + 80;
        const posicionYSalidaAND = posicionYAND;
        salidasAND.push({x: posicionXSalidaAND, y: posicionYSalidaAND});
        crearEtiquetaCircuito(`T${indiceTermino+1}`, columnaAND + 40, posicionYAND + 5, 0.9 + indiceTermino * 0.1);
    });
    
    const columnaOR = obtenerPosicionColumna(3);
    const posicionYOR = configuracionLayout.alto / 2;
    crearPuertaOR(columnaOR, posicionYOR - 45, 1.0);
    
    salidasAND.forEach((salida, indice) => {
        const retrasoTiempo = 1.1 + indice * 0.1;
        
        crearCableVertical(salida.x, salida.y, posicionYOR, retrasoTiempo, "cable and-a-or");
        crearCableHorizontal(salida.x, posicionYOR, columnaOR, retrasoTiempo + 0.05, "cable and-a-or");
        crearPuntoConexion(salida.x, posicionYOR, retrasoTiempo + 0.1, "#ff0066");
        crearPuntoConexion(salida.x, salida.y, retrasoTiempo - 0.05, "#00e0ff");
    });
    
    // Salida final
    const columnaSalida = obtenerPosicionColumna(4);
    const posicionXSalidaOR = columnaOR + 90;
    crearCableHorizontal(posicionXSalidaOR, posicionYOR, columnaSalida, 1.5, "cable salida");
    crearPuntoConexion(posicionXSalidaOR, posicionYOR, 1.45, "#00ffaa");
    crearEtiquetaCircuito("F", columnaSalida + 10, posicionYOR + 5, 1.6, "texto-circuito texto-salida");
}

function dibujarCircuitoDesdeExpresion(expresion, idSVG = "circuito-svg") {
    // Obtener elemento SVG
    elementoSVG = document.getElementById(idSVG);
    
    if (!elementoSVG) {
        console.error(`No se encontró el SVG con id: ${idSVG}`);
        return false;
    }
    
    while (elementoSVG.firstChild) {
        elementoSVG.removeChild(elementoSVG.firstChild);
    }
    
    try {
        const terminosSumaProductos = parsearExpresionSumaProductos(expresion);
        if (terminosSumaProductos.length === 0) {
            crearEtiquetaCircuito("Expresión vacía o inválida", 50, 50, 0, "texto-circuito");
            return false;
        }
        
        generarCircuitoSOP(terminosSumaProductos);
        return true;
    } catch (error) {
        console.error("Error al generar circuito:", error);
        crearEtiquetaCircuito("Error: Expresión inválida", 50, 50, 0, "texto-circuito");
        crearEtiquetaCircuito("Formato: (x1)·¬(x2)·(x3) + (x4)·¬(x5)", 50, 70, 0.1, "texto-circuito");
        return false;
    }
}

function limpiarCircuito(idSVG = "circuito-svg") {
    const svg = document.getElementById(idSVG);
    if (svg) {
        while (svg.firstChild) {
            svg.removeChild(svg.firstChild);
        }
    }
}

window.dibujarCircuitoDesdeExpresion = dibujarCircuitoDesdeExpresion;
window.limpiarCircuito = limpiarCircuito;
window.parsearExpresionSumaProductos = parsearExpresionSumaProductos;
