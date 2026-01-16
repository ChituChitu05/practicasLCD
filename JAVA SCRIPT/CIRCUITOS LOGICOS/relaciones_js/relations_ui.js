const BOTON_RELACIONES = document.getElementById("relaciones");

BOTON_RELACIONES.addEventListener("click", inicializarGrafos);

function inicializarGrafos(){
    limpiarContenedor();
    crearTituloGrafos();
    crearSeccionEntradaGrafos();
}

function crearTituloGrafos() {
    CONTENEDOR_PRINCIPAL.appendChild(
        crearTitulo("RELACIONES Y GRAFOS", 1)
    );
}

function crearSeccionEntradaGrafos() {
    const seccionEntrada = crearSeccion("seccion-entrada-grafos");
    
    const etiquetaParametroN = crearEtiqueta("Tamaño del conjunto (n):", "campo-grafos-n");
    const campoParametroN = crearCampoTexto("campo-grafos-n", "Ejemplo: 10");
    campoParametroN.value = "10";
    campoParametroN.type = "number";
    campoParametroN.min = "1";
    campoParametroN.max = "15";
    
    const etiquetaParametroM = crearEtiqueta("Valor del parámetro (m):", "campo-grafos-m");
    const campoParametroM = crearCampoTexto("campo-grafos-m", "Ejemplo: 8");
    campoParametroM.value = "8";
    campoParametroM.type = "number";
    campoParametroM.min = "0";
    
    const botonCrearGrafos = crearBoton("crear-grafos", "Generar Grafos");
    
    botonCrearGrafos.addEventListener("click", function() {
        const parametroN = parseInt(campoParametroN.value) || 10;
        const parametroM = parseInt(campoParametroM.value) || 8;
        
        if (parametroN > 15) {
            alert("Para mejor visualización, n ≤ 15");
            campoParametroN.value = "15";
            return;
        }
        
        crearSeccionRelaciones(parametroM, parametroN);
        crearSeccionGrafos(parametroM, parametroN);
    });
    
    seccionEntrada.appendChild(etiquetaParametroN);
    seccionEntrada.appendChild(campoParametroN);
    seccionEntrada.appendChild(etiquetaParametroM);
    seccionEntrada.appendChild(campoParametroM);
    seccionEntrada.appendChild(botonCrearGrafos);
    
    CONTENEDOR_PRINCIPAL.appendChild(seccionEntrada);
}

function limpiarSeccionRelaciones() {
    const seccionRelaciones = document.getElementById("seccion-relaciones");
    if (seccionRelaciones) {
        seccionRelaciones.remove();
    }
}

function crearSeccionRelaciones(parametroM, parametroN) {
    limpiarSeccionRelaciones();
    
    const seccionRelaciones = crearSeccion("seccion-relaciones");
    seccionRelaciones.appendChild(crearTitulo("Análisis de Relaciones", 2));
    
    // Obtener relaciones y análisis
    const relacionMulti = construirRelacion(parametroM, parametroN, relacionMultiplicacion);
    const relacionSum = construirRelacion(parametroM, parametroN, relacionSuma);
    const analisisRelacionMulti = analizarRelacion(parametroM, parametroN, relacionMultiplicacion);
    const analisisRelacionSum = analizarRelacion(parametroM, parametroN, relacionSuma);
    
    // Crear contenedor para ambas relaciones
    const contenedorRelaciones = document.createElement("div");
    contenedorRelaciones.style.display = "flex";
    contenedorRelaciones.style.flexWrap = "wrap";
    contenedorRelaciones.style.gap = "2rem";
    
    // Relación de Multiplicación
    const contenedorMulti = crearContenedorRelacion(
        "R1: (x * y) mod n = m mod n",
        relacionMulti,
        analisisRelacionMulti,
        "multi"
    );
    
    // Relación de Suma
    const contenedorSuma = crearContenedorRelacion(
        "R2: (x + y) mod n = m mod n",
        relacionSum,
        analisisRelacionSum,
        "suma"
    );
    
    contenedorRelaciones.appendChild(contenedorMulti);
    contenedorRelaciones.appendChild(contenedorSuma);
    seccionRelaciones.appendChild(contenedorRelaciones);
    
    CONTENEDOR_PRINCIPAL.appendChild(seccionRelaciones);
}

function crearContenedorRelacion(titulo, pares, analisis, idSufijo) {
    const contenedor = document.createElement("div");
    contenedor.style.flex = "1";
    contenedor.style.minWidth = "300px";
    
    const tituloElemento = crearTitulo(titulo, 3);
    tituloElemento.style.color = "#2c3e50";
    tituloElemento.style.marginTop = "0";
    contenedor.appendChild(tituloElemento);
    const infoPares = document.createElement("div");
    infoPares.className = "area-funcion";
    infoPares.style.marginBottom = "1rem";
    
    infoPares.innerHTML = `
        <p><strong>Número de pares:</strong> ${pares.length}</p>
        <p><strong>Pares ordenados:</strong></p>
    `;
    
    // Contenedor para mostrar los pares
    const contenedorPares = document.createElement("div");
    contenedorPares.id = `pares-${idSufijo}`;
    contenedorPares.className = "area-funcion";
    contenedorPares.style.maxHeight = "200px";
    contenedorPares.style.overflowY = "auto";
    contenedorPares.style.fontFamily = "'Courier New', monospace";
    contenedorPares.style.fontSize = "0.9rem";
    contenedorPares.style.padding = "0.75rem";
    
    // Formatear pares para mostrar
    if (pares.length === 0) {
        contenedorPares.textContent = "No hay pares en esta relación.";
    } else {
        const textoPares = pares.map(par => `(${par[0]}, ${par[1]})`).join(", ");
        contenedorPares.textContent = textoPares;
    }
    
    const contenedorAnalisis = document.createElement("div");
    contenedorAnalisis.className = "analisis";
    contenedorAnalisis.innerHTML = `
        <p><strong>Propiedades:</strong></p>
        <ul style="margin: 0; padding-left: 20px; list-style-type: none;">
            ${Object.entries(analisis).map(([prop, valor]) => 
                `<li>${prop.charAt(0).toUpperCase() + prop.slice(1)}: ${valor ? '✓' : '✗'}</li>`
            ).join('')}
        </ul>
    `;
    
    contenedor.appendChild(infoPares);
    contenedor.appendChild(contenedorPares);
    contenedor.appendChild(contenedorAnalisis);
    
    return contenedor;
}