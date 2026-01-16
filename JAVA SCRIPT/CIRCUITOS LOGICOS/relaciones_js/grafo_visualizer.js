function crearSeccionGrafos(parametroM, parametroN) {
    console.log("Creando gráficos con m=" + parametroM + ", n=" + parametroN);
    
    // Limpiar sección existente
    const seccionExistente = document.getElementById("seccion-grafos");
    if (seccionExistente) {
        seccionExistente.remove();
    }
    
    const seccionGrafos = crearSeccion("seccion-grafos");
    seccionGrafos.appendChild(crearTitulo("Visualización de Grafos", 2));
    
    // Información simple
    const infoDiv = document.createElement("div");
    infoDiv.className = "area-funcion";
    infoDiv.innerHTML = `
        <p><strong>Parámetros:</strong> n = ${parametroN}, m = ${parametroM}</p>
        <p><strong>Conjunto:</strong> {0, 1, 2, ..., ${parametroN-1}}</p>
    `;
    seccionGrafos.appendChild(infoDiv);
    
    // Crear contenedor para ambos grafos
    const contenedorGrafos = document.createElement("div");
    contenedorGrafos.style.display = "flex";
    contenedorGrafos.style.flexWrap = "wrap";
    contenedorGrafos.style.gap = "2rem";
    contenedorGrafos.style.marginTop = "1rem";
    
    // Grafo multiplicación
    const contenedorGrafoMulti = document.createElement("div");
    contenedorGrafoMulti.style.flex = "1";
    contenedorGrafoMulti.style.minWidth = "400px";
    
    const tituloMulti = crearTitulo("Grafo R1: (x * y) mod n = m mod n", 3);
    contenedorGrafoMulti.appendChild(tituloMulti);
    
    const svgMulti = crearContenedorSVG("grafo-multiplicacion", 400, 400);
    svgMulti.style.border = "1px solid #ddd";
    svgMulti.style.backgroundColor = "white";
    svgMulti.style.display = "block";
    contenedorGrafoMulti.appendChild(svgMulti);
    
    // Grafo suma
    const contenedorGrafoSuma = document.createElement("div");
    contenedorGrafoSuma.style.flex = "1";
    contenedorGrafoSuma.style.minWidth = "400px";
    
    const tituloSuma = crearTitulo("Grafo R2: (x + y) mod n = m mod n", 3);
    contenedorGrafoSuma.appendChild(tituloSuma);
    
    const svgSuma = crearContenedorSVG("grafo-suma", 400, 400);
    svgSuma.style.border = "1px solid #ddd";
    svgSuma.style.backgroundColor = "white";
    svgSuma.style.display = "block";
    contenedorGrafoSuma.appendChild(svgSuma);
    
    contenedorGrafos.appendChild(contenedorGrafoMulti);
    contenedorGrafos.appendChild(contenedorGrafoSuma);
    seccionGrafos.appendChild(contenedorGrafos);
    
    CONTENEDOR_PRINCIPAL.appendChild(seccionGrafos);
    dibujarGrafoSVG(parametroM, parametroN, relacionMultiplicacion, svgMulti, "Multiplicación");
    dibujarGrafoSVG(parametroM, parametroN, relacionSuma, svgSuma, "Suma");
}

function dibujarGrafoSVG(parametroM, parametroN, funcionRelacion, elementoSVG, nombreRelacion) {
    const grafo = construirGrafo(parametroM, parametroN, funcionRelacion);
    const nodos = Object.keys(grafo);
    const ancho = 400;
    const alto = 400;
    const centroX = ancho / 2;
    const centroY = alto / 2;
    const radio = 150; // Radio del círculo
    
    // Limpiar SVG
    while (elementoSVG.firstChild) {
        elementoSVG.removeChild(elementoSVG.firstChild);
    }
    
    // Calcular posiciones de los nodos
    const posiciones = [];
    nodos.forEach((idNodo, indice) => {
        const angulo = (indice * 2 * Math.PI) / nodos.length;
        const x = centroX + radio * Math.cos(angulo);
        const y = centroY + radio * Math.sin(angulo);
        posiciones.push({ id: idNodo, x, y });
    });
    

    nodos.forEach((idFuente, indice) => {
        const posicionFuente = posiciones[indice];
        const destinos = grafo[idFuente];
        
        destinos.forEach(idDestino => {
            const indiceDestino = nodos.indexOf(idDestino.toString());
            if (indiceDestino === -1) return;
            
            const posicionDestino = posiciones[indiceDestino];
            
            const linea = document.createElementNS("http://www.w3.org/2000/svg", "line");
            linea.setAttribute("x1", posicionFuente.x);
            linea.setAttribute("y1", posicionFuente.y);
            linea.setAttribute("x2", posicionDestino.x);
            linea.setAttribute("y2", posicionDestino.y);
            linea.setAttribute("stroke", "#95a5a6");
            linea.setAttribute("stroke-width", "1.5");
            
            if (idFuente === idDestino) {
                linea.setAttribute("stroke", "#e74c3c");
                linea.setAttribute("stroke-dasharray", "5,5");
                
                const bucle = document.createElementNS("http://www.w3.org/2000/svg", "circle");
                bucle.setAttribute("cx", posicionFuente.x);
                bucle.setAttribute("cy", posicionFuente.y - 25);
                bucle.setAttribute("r", 20);
                bucle.setAttribute("fill", "none");
                bucle.setAttribute("stroke", "#e74c3c");
                bucle.setAttribute("stroke-width", "2");
                bucle.setAttribute("stroke-dasharray", "5,5");
                elementoSVG.appendChild(bucle);
            } else {
                const anguloLinea = Math.atan2(
                    posicionDestino.y - posicionFuente.y,
                    posicionDestino.x - posicionFuente.x
                );
                
                const longitudFlecha = 10;
                const flechaX = posicionDestino.x - 25 * Math.cos(anguloLinea);
                const flechaY = posicionDestino.y - 25 * Math.sin(anguloLinea);
                
                const flecha = document.createElementNS("http://www.w3.org/2000/svg", "polygon");
                flecha.setAttribute("points", 
                    `${flechaX},${flechaY} ` +
                    `${flechaX - longitudFlecha * Math.cos(anguloLinea - Math.PI/6)},${flechaY - longitudFlecha * Math.sin(anguloLinea - Math.PI/6)} ` +
                    `${flechaX - longitudFlecha * Math.cos(anguloLinea + Math.PI/6)},${flechaY - longitudFlecha * Math.sin(anguloLinea + Math.PI/6)}`
                );
                flecha.setAttribute("fill", "#95a5a6");
                elementoSVG.appendChild(flecha);
            }
            
            elementoSVG.appendChild(linea);
        });
    });
    
    posiciones.forEach(posicion => {
        const circulo = document.createElementNS("http://www.w3.org/2000/svg", "circle");
        circulo.setAttribute("cx", posicion.x);
        circulo.setAttribute("cy", posicion.y);
        circulo.setAttribute("r", "20");
        circulo.setAttribute("fill", "#3498db");
        circulo.setAttribute("stroke", "#2980b9");
        circulo.setAttribute("stroke-width", "2");
        
        const texto = document.createElementNS("http://www.w3.org/2000/svg", "text");
        texto.setAttribute("x", posicion.x);
        texto.setAttribute("y", posicion.y);
        texto.setAttribute("text-anchor", "middle");
        texto.setAttribute("dy", "0.35em");
        texto.setAttribute("fill", "white");
        texto.setAttribute("font-weight", "bold");
        texto.setAttribute("font-size", "14px");
        texto.textContent = posicion.id;
        
        elementoSVG.appendChild(circulo);
        elementoSVG.appendChild(texto);
    });
    
    const titulo = document.createElementNS("http://www.w3.org/2000/svg", "text");
    titulo.setAttribute("x", centroX);
    titulo.setAttribute("y", centroY);
    titulo.setAttribute("text-anchor", "middle");
    titulo.setAttribute("fill", "#2c3e50");
    titulo.setAttribute("font-size", "14px");
    titulo.setAttribute("font-weight", "bold");
    titulo.textContent = nombreRelacion;
    
    elementoSVG.appendChild(titulo);
    
    console.log("Grafo " + nombreRelacion + " dibujado");
}