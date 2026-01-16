function crearBoton(id, texto) {
    const boton = document.createElement("button");
    boton.id = id;
    boton.textContent = texto;
    boton.type = "button";
    return boton;
}

function crearCampoTexto(id, textoPlaceholder) {
    const campo = document.createElement("input");
    campo.type = "text";
    campo.id = id;
    campo.placeholder = textoPlaceholder;
    return campo;
}

function crearContenedorSVG(id, ancho = 600, alto = 400) {
    const svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
    svg.setAttribute("id", id);
    svg.setAttribute("width", ancho);
    svg.setAttribute("height", alto);
    svg.setAttribute("viewBox", `0 0 ${ancho} ${alto}`);
    svg.setAttribute("xmlns", "http://www.w3.org/2000/svg");
    return svg;
}

function crearEtiqueta(texto, idAsociado) {
    const etiqueta = document.createElement("label");
    etiqueta.textContent = texto;
    etiqueta.htmlFor = idAsociado;
    return etiqueta;
}

function crearSeccion(id) {
    const seccion = document.createElement("section");
    seccion.id = id;
    return seccion;
}

function crearTitulo(texto, nivel = 2) {
    const titulo = document.createElement(`h${nivel}`);
    titulo.textContent = texto;
    return titulo;
}

function actualizarValorCampo(id, valor) {
    const campo = document.getElementById(id);
    if (campo) {
        campo.value = valor;
    }
}

function obtenerNumerosDesdeCampo(id) {
    const campo = document.getElementById(id);
    if (!campo || !campo.value.trim()) return [];
    
    return campo.value
        .split(",")
        .map(numero => numero.trim())
        .filter(numero => numero !== "") 
        .map(numero => parseInt(numero, 10))
        .filter(numero => !isNaN(numero) && numero >= 0 && numero <= 31);
}