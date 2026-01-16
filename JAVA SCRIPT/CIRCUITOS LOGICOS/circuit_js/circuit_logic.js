function convertirDecimalABinario(numero) {
    if (!esEntero(numero)) {
        throw new Error("Entrada inválida: solo enteros finitos");
    }

    if (numero === 0) return "0";

    let valorAbsoluto = valorAbsoluto(numero);
    let binario = "";

    while (valorAbsoluto > 0) {
        binario = residuoDivision(valorAbsoluto) + binario;
        valorAbsoluto = (valorAbsoluto / 2) | 0;
    }

    return binario;
}

function generarTablaBinaria(numeros, longitudBits = 5) {
    if (!Array.isArray(numeros)) {
        throw new Error("Se esperaba un array");
    }

    return numeros.map(numero => {
        const binario = convertirDecimalABinario(numero);
        if (binario.length > longitudBits) {
            throw new Error("Overflow de bits");
        }
        return completarConCeros(binario, longitudBits);
    });
}

function convertirTablaAArray(tablaBinaria) {
    if (!Array.isArray(tablaBinaria)) {
        throw new Error("Tabla inválida");
    }

    return tablaBinaria.map(fila => {
        if (typeof fila !== "string") {
            throw new Error("Fila inválida");
        }
        return fila.split("");
    });
}

function generarExpresionBooleana(tabla) {
    if (!Array.isArray(tabla) || tabla.length === 0) return "";

    const ancho = tabla[0].length;
    const terminos = [];

    tabla.forEach(fila => {
        if (!Array.isArray(fila) || fila.length !== ancho) {
            throw new Error("Filas inconsistentes");
        }

        const salida = fila[ancho - 1];
        if (salida === "1") {
            terminos.push(construirTerminoProducto(fila));
        }
    });

    return terminos.join(" + ");
}

function construirTerminoProducto(fila) {
    const variables = [];

    for (let indice = 0; indice < fila.length - 1; indice++) {
        if (fila[indice] !== "0" && fila[indice] !== "1") {
            throw new Error("Bit inválido");
        }
        variables.push(
            fila[indice] === "1" ? `(x${indice + 1})` : `¬(x${indice + 1})`
        );
    }

    return variables.join(" · ");
}

function configurarValidacionEntrada() {
    const campoEntrada = document.getElementById("entrada-numeros");
    const RETRASO_VALIDACION = 800;
    let temporizador = null;

    campoEntrada.addEventListener("input", (evento) => {
        clearTimeout(temporizador);

        const valorValidado = validarEntradaNumeros(evento.target.value);
        actualizarValorCampo("entrada-numeros", valorValidado);

        if (esUltimoBloqueCompleto(valorValidado)) {
            temporizador = setTimeout(
                () => agregarComaAutomatica(campoEntrada),
                RETRASO_VALIDACION
            );
        }
        crearTablaCircuito();
        actualizarFuncionYCircuito();
    });
}

function esUltimoBloqueCompleto(valor) {
    const ultimoBloque = valor.split(",").pop();
    return ultimoBloque !== "";
}

function agregarComaAutomatica(campoEntrada) {
    if (!campoEntrada.value.endsWith(",")) {
        actualizarValorCampo("entrada-numeros", campoEntrada.value + ",");
    }
}