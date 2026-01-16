
function relacionMultiplicacion(x, y, parametroM, parametroN) {
    // xRy si (x * y) mod n = m mod n
    return residuoDivision((x * y), parametroN) === residuoDivision(parametroM, parametroN);
}

function relacionSuma(x, y, parametroM, parametroN) {
    // xRy si (x + y) mod n = m mod n
    return residuoDivision((x + y), parametroN) === residuoDivision(parametroM, parametroN);
}

function construirRelacion(parametroM, parametroN, funcionRelacion) {
    let pares = [];
    for (let x = 0; x < parametroN; x++) {
        for (let y = 0; y < parametroN; y++) {
            if (funcionRelacion(x, y, parametroM, parametroN)) {
                pares.push([x, y]);
            }
        }
    }
    return pares;
}

function construirGrafo(parametroM, parametroN, funcionRelacion) {
    let grafo = {};
    for (let i = 0; i < parametroN; i++) grafo[i] = [];

    for (let x = 0; x < parametroN; x++) {
        for (let y = 0; y < parametroN; y++) {
            if (funcionRelacion(x, y, parametroM, parametroN)) {
                grafo[x].push(y);
            }
        }
    }
    return grafo;
}

function analizarRelacion(parametroM, parametroN, funcionRelacion) {
    let esReflexiva = true;
    let esSimetrica = true;
    let esAntisimetrica = true;
    let esTransitiva = true;

    // Reflexiva: ∀x, xRx
    for (let x = 0; x < parametroN; x++) {
        if (!funcionRelacion(x, x, parametroM, parametroN)) {
            esReflexiva = false;
            break;
        }
    }

    // Simétrica: si xRy entonces yRx
    // Antisimétrica: si xRy y yRx entonces x=y
    for (let x = 0; x < parametroN; x++) {
        for (let y = 0; y < parametroN; y++) {
            if (funcionRelacion(x, y, parametroM, parametroN) && !funcionRelacion(y, x, parametroM, parametroN)) {
                esSimetrica = false;
            }
            
            if (x !== y && funcionRelacion(x, y, parametroM, parametroN) && funcionRelacion(y, x, parametroM, parametroN)) {
                esAntisimetrica = false;
            }
        }
    }
    
    // Transitiva: si xRy y yRz entonces xRz
    for (let x = 0; x < parametroN; x++) {
        for (let y = 0; y < parametroN; y++) {
            for (let z = 0; z < parametroN; z++) {
                if (funcionRelacion(x, y, parametroM, parametroN) && funcionRelacion(y, z, parametroM, parametroN) && !funcionRelacion(x, z, parametroM, parametroN)) {
                    esTransitiva = false;
                }
            }
        }
    }

    return {
        reflexiva: esReflexiva,
        simetrica: esSimetrica,
        antisimetrica: esAntisimetrica,
        transitiva: esTransitiva
    };
}

// Variables globales para el ejemplo
let parametroM = 8;
let parametroN = 10;