const CONTENEDOR_PRINCIPAL = document.getElementById("container");

function validarEntradaNumeros(valor) {
    const partes = valor.split(",");
    const ultimaParte = partes[partes.length - 1];
    const soloDigitos = ultimaParte.replace(/\D/g, "");
    const digitosLimitados = soloDigitos.slice(0, 2);
    const numero = parseInt(digitosLimitados, 10);
    const esValido = !isNaN(numero) && numero >= 0 && numero <= 31;
    
    partes[partes.length - 1] = esValido ? digitosLimitados : "";
    
    return partes.join(",");
}

function residuoDivision(numero, divisor = 2) {
    if (!esEnteroSeguro(numero)) {
        throw new Error("Residuo inválido");
    }
    if (!esEnteroSeguro(divisor) || divisor <= 0) {
        throw new Error("Divisor inválido");
    }

    while (numero >= divisor) {
        numero -= divisor;
    }
    return numero;
}

function esEnteroSeguro(numero) {
    return Number.isInteger(numero) && numero >= Number.MIN_SAFE_INTEGER && numero <= Number.MAX_SAFE_INTEGER;
}

function completarConCeros(binario, longitud) {
    if (typeof binario !== "string" || longitud < binario.length) {
        throw new Error("Longitud inválida");
    }
    return binario.padStart(longitud, "0");
}

function valorAbsoluto(numero) {
    return numero < 0 ? -numero : numero;
}

function esEntero(numero) {
    return typeof numero === "number" && isFinite(numero) && numero === (numero | 0);
}

function limpiarContenedor() {
    CONTENEDOR_PRINCIPAL.innerHTML = "";
}
