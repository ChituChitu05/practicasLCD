
const BOTON_CIRCUITOS = document.getElementById("circuitLogic");
const NUMEROS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31];

BOTON_CIRCUITOS.addEventListener("click", inicializarVistaCircuitos);

function inicializarVistaCircuitos() {
    limpiarContenedor();
    crearSeccionEntradaNumeros();
    crearSeccionFuncionYCircuito();
}

function crearSeccionEntradaNumeros() {
    CONTENEDOR_PRINCIPAL.appendChild(
        crearTitulo("CIRCUITOS LÓGICOS")
    );

    const seccionEntrada = crearSeccion("seccion-entrada");
    seccionEntrada.appendChild(
        crearEtiqueta("Números (0-31):", "entrada-numeros")
    );

    const campoEntrada = crearCampoTexto("entrada-numeros", "Ejemplo: 1,3,4,5,2");
    seccionEntrada.appendChild(campoEntrada);
    
    const botonCrear = crearBoton("crear-circuito", "Generar Tabla y Circuito");
    botonCrear.addEventListener("click", function() {
        crearTablaCircuito();
        actualizarFuncionYCircuito();
    });
    seccionEntrada.appendChild(botonCrear);

    CONTENEDOR_PRINCIPAL.appendChild(seccionEntrada);

    configurarValidacionEntrada();
}

function crearSeccionFuncionYCircuito() {
    const seccionFuncion = crearSeccion("seccion-funcion");
    seccionFuncion.appendChild(
        crearEtiqueta("Función Booleana Generada:", "funcion-booleana")
    );
    const areaFuncion = document.createElement("div");
    areaFuncion.id = "funcion-booleana";
    areaFuncion.className = "area-funcion";
    seccionFuncion.appendChild(areaFuncion);
    const seccionDiagrama = crearSeccion("seccion-diagrama");
    seccionDiagrama.appendChild(crearTitulo("Diagrama del Circuito Lógico", 3));
    
    const contenedorSVG = document.createElement("div");
    contenedorSVG.id = "contenedor-circuito";
    contenedorSVG.className = "circuito-contenedor";

    const contenedorScroll = document.createElement("div");
    contenedorScroll.className = "svg-scroll-wrapper";
    const svg = crearContenedorSVG("circuito-svg", 900, 400);
    contenedorScroll.appendChild(svg);
    contenedorSVG.appendChild(contenedorScroll);
    seccionDiagrama.appendChild(contenedorSVG);
    
    CONTENEDOR_PRINCIPAL.appendChild(seccionFuncion);
    CONTENEDOR_PRINCIPAL.appendChild(seccionDiagrama);
}

function crearTablaCircuito() {
    eliminarSeccionExistente("seccion-tabla");
    
    const numerosUsuario = obtenerNumerosDesdeCampo("entrada-numeros");
    const seccionTabla = crearSeccion("seccion-tabla");
    
    const tablaHTML = construirTablaHTML(NUMEROS, numerosUsuario);
    seccionTabla.appendChild(tablaHTML);
    
    CONTENEDOR_PRINCIPAL.appendChild(seccionTabla);
}

function eliminarSeccionExistente(id) {
    const seccion = document.getElementById(id);
    if (seccion) seccion.remove();
}

function construirTablaHTML(NUMEROS, numerosUsuario) {
    const tablaBinaria = generarTablaBinaria(NUMEROS);
    const tablaArray = convertirTablaAArray(tablaBinaria);
    
    tablaArray.forEach((fila, indice) => {
        const numeroFila = NUMEROS[indice];
        const estaPresente = numerosUsuario.includes(numeroFila) ? "1" : "0";
        fila.push(estaPresente);
    });
    
    const contenedorTabla = document.createElement("div");
    contenedorTabla.id = "tabla-circuito";
    contenedorTabla.className = "tabla-circuito";
    
    if (tablaArray.length === 0) {
        contenedorTabla.textContent = "No hay datos para mostrar.";
        return contenedorTabla;
    }
    
    const numeroColumnasOriginal = tablaArray[0].length - 1; 
    contenedorTabla.appendChild(crearEncabezadoTabla(numeroColumnasOriginal + 1)); 

    tablaArray.forEach(fila => {
        contenedorTabla.appendChild(crearFilaTabla(fila));
    });
    
    return contenedorTabla;
}

function crearEncabezadoTabla(numeroColumnas) {
    const filaEncabezado = document.createElement("div");
    filaEncabezado.className = "fila-encabezado";

    for (let indice = 0; indice < numeroColumnas; indice++) {
        const celda = document.createElement("div");
        celda.className = "celda-encabezado";
        celda.textContent = indice < numeroColumnas - 1 ? `x${indice + 1}` : "f(x)";
        filaEncabezado.appendChild(celda);
    }

    return filaEncabezado;
}

function crearFilaTabla(valores) {
    const fila = document.createElement("div");
    fila.className = "fila-datos";

    valores.forEach(valor => {
        const celda = document.createElement("div");
        celda.className = "celda-dato";
        celda.textContent = valor;
        fila.appendChild(celda);
    });

    return fila;
}

function actualizarFuncionYCircuito() {
    const numerosUsuario = obtenerNumerosDesdeCampo("entrada-numeros");
    const areaFuncion = document.getElementById("funcion-booleana");
    
    if (!areaFuncion) return;
    
    if (numerosUsuario.length === 0) {
        areaFuncion.textContent = "Ingrese números (0-31) para generar la función";
        limpiarCircuito("circuito-svg");
        return;
    }
    
    try {
        const tablaBinaria = generarTablaBinaria(NUMEROS);
        let tablaArray = convertirTablaAArray(tablaBinaria);
        
        tablaArray.forEach((fila, indice) => {
            const numeroFila = NUMEROS[indice];
            const estaPresente = numerosUsuario.includes(numeroFila) ? "1" : "0";
            fila.push(estaPresente);
        });
        
        const expresion = generarExpresionBooleana(tablaArray);
        areaFuncion.textContent = expresion;
        
        if (expresion && expresion.trim() !== "") {
            dibujarCircuitoDesdeExpresion(expresion, "circuito-svg");
        } else {
            limpiarCircuito("circuito-svg");
            const svg = document.getElementById("circuito-svg");
            if (svg) {
                const texto = document.createElementNS("http://www.w3.org/2000/svg", "text");
                texto.setAttribute("x", "50");
                texto.setAttribute("y", "50");
                texto.setAttribute("class", "texto-circuito");
                texto.textContent = "No hay expresión booleana para dibujar";
                svg.appendChild(texto);
            }
        }
    } catch (error) {
        console.error("Error al generar función booleana o circuito:", error);
        areaFuncion.textContent = "Error: " + error.message;
        limpiarCircuito("circuito-svg");
    }
}

// Inicializar al cargar si estamos en la vista de circuitos
if (window.location.hash === "#circuitos" || document.getElementById("circuitLogic").classList.contains("active")) {
    inicializarVistaCircuitos();
}
