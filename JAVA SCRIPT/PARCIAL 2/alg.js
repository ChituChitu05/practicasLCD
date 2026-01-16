function residuo(a, b) {
    if (b === 0) throw new Error("Divisor no puede ser cero");
    a = Math.trunc(a);
    b = Math.trunc(b);
    const q = Math.trunc(a / b);
    return a - q * b;
}

function divisionEuclidea(a, b) {
    a = Math.trunc(a);
    b = Math.trunc(b);
    if (b === 0) throw new Error("Divisor 0 no permitido");
    const q = Math.trunc(a / b);
    const r = a - q * b;
    return { a, b, q, r };
}

function euclidMCD(a, b) {
    a = Math.abs(Math.trunc(a));
    b = Math.abs(Math.trunc(b));
    let steps = [];
    if (a === 0 || b === 0) return steps;
    while (b !== 0) {
        const d = divisionEuclidea(a, b);
        steps.push({ a, b, r: d.r, q: d.q });
        a = b;
        b = d.r;
    }
    return steps;
}

function calcularMCM(a, b) {
    const A = Math.trunc(a);
    const B = Math.trunc(b);
    const pasos = euclidMCD(A, B);
    if (pasos.length === 0) {
        throw new Error("El MCM no está definido cuando uno de los valores es 0.");
    }
    const mcd = pasos[pasos.length - 1].b;
    const mcm_valor = Math.abs(A * B) / mcd;
    return { mcd, mcm: mcm_valor };
}

function bezout(a, b) {
    const A = Math.trunc(a);
    const B = Math.trunc(b);
    if (A === 0 || B === 0) throw new Error("No existe Bézout con 0.");
    const steps = euclidMCD(A, B);
    if (steps.length === 0) throw new Error("No hay suficientes pasos.");
    let x1 = 1, y1 = 0;
    let x2 = 0, y2 = 1;
    for (let i = 0; i < steps.length - 1; i++) {
        const q = steps[i].q;
        const xt = x1 - q * x2;
        const yt = y1 - q * y2;
        x1 = x2;
        y1 = y2;
        x2 = xt;
        y2 = yt;
    }
    const mcd = steps[steps.length - 1].b;
    let sustitucion = "";
    for (let i = steps.length - 2; i >= 0; i--) {
        const s = steps[i];
        sustitucion += `${s.r} = ${s.a} - ${s.b}*(${s.q})\n`;
    }
    return { x: x2, y: y2, mcd, steps, sustitucion };
}

function esPrimo(n) {
    n = Math.trunc(n);
    const steps = [];
    if (n <= 1) return { primo: false, divisor: null, steps };
    if (n === 2) return { primo: true, divisor: null, steps };
    // Probar división entre 2
    let d2 = divisionEuclidea(n, 2);
    steps.push(`${n} = 2*(${d2.q}) + ${d2.r}`);
    if (d2.r === 0) return { primo: false, divisor: 2, steps };
    // Probar divisores impares
    const limite = Math.floor(Math.sqrt(n));
    for (let i = 3; i <= limite; i += 2) {
        let d = divisionEuclidea(n, i);
        steps.push(`${n} = ${i}*(${d.q}) + ${d.r}`);
        if (d.r === 0) return { primo: false, divisor: i, steps };
    }
    return { primo: true, divisor: null, steps };
}


function convertirABase10(numStr, base) {
    const simbolos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let valor = 0;
    let pasos = [];
    

    for (let i = numStr.length - 1, pos = 0; i >= 0; i--, pos++) {
        const digito = simbolos.indexOf(numStr[i].toUpperCase());
        if (digito < 0 || digito >= base) throw new Error("Dígito inválido");

        valor += digito * (base ** pos);

        pasos.push(`${digito} * ${base}^${pos} = ${digito * (base ** pos)}`);
    }

    return { valor, pasos };
}

function convertirDesdeBase10(n, base) {
    if (n === 0) return { resultado: "0", pasos: ["0"] };
    const simbolos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let pasos = [];
    let restos = [];
    while (n > 0) {
        const d = divisionEuclidea(n, base);
        pasos.push(`${n} = ${base} * ${d.q} + ${d.r}`);
        restos.unshift(d.r);
        n = d.q;
    }
    const convertido = restos.map(r => simbolos[r]).join("");
    return { resultado: convertido, pasos };
}

function cambioBase(numStr, baseOrigen, baseDestino) {
    const paso1 = convertirABase10(numStr.trim(), baseOrigen);
    const paso2 = convertirDesdeBase10(paso1.valor, baseDestino);
    return {
        base10: paso1.valor,
        pasosBase10: paso1.pasos,
        resultado: paso2.resultado,
        pasosDestino: paso2.pasos
    };
}

function factorizarTFA(n) {
    n = Math.trunc(n);
    if (n <= 1) throw new Error("El número debe ser mayor que 1.");
    let pasos = [];
    let factores = [];
    let d = 2;
    let x = n;
    while (d * d <= x) {
        const div = divisionEuclidea(x, d);
        while (div.r === 0) {
            pasos.push(`${x} es divisible por ${d}`);
            factores.push(d);
            x = x / d;
            div.r = divisionEuclidea(x, d).r;
        }
        d++;
    }
    if (x > 1) {
        pasos.push(`${x} es primo.`);
        factores.push(x);
    }
    return { factores, pasos };
}


const ALFABETO = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
const MOD = ALFABETO.length;


function letraAValor(c) {
    return ALFABETO.indexOf(c.toUpperCase());
}

function valorALetra(v) {
    return ALFABETO[residuo(v, MOD)];
}
function inversoAditivo(n) {
    let k = 0;
    while (residuo(n + k, MOD) !== 0) {
        k = k + 1;   
    }
    return k;      
}
function descifrarPorSuma(cifrado) {
    const nums = cifrado.split("").map(letraAValor);
    let resultados = [];
    for (let n = 0; n < MOD; n++) {
        const plano = nums
            .map(x => valorALetra(residuo(x + inversoAditivo(n), MOD)))  // solo sumas
            .join("");

        resultados.push({ n, texto: plano });
    }

    return resultados;
}
function inversoMultiplicativo(m) {
    for (let i = 0; i < MOD; i++) {
        if (residuo((m * i) , MOD) === 1) return i;
    }
    return null;
}

function descifrarPorMultiplicacion(cifrado) {
    const nums = cifrado.split("").map(letraAValor);
    let resultados = [];

    for (let m = 1; m < MOD; m++) {
        const inv = inversoMultiplicativo(m);
        if (inv === null) continue;

        const plano = nums.map(x => valorALetra(residuo((inv * x) ,MOD))).join("");
        resultados.push({ m, inv, texto: plano });
    }

    return resultados;
}

function descifrarCombinado(cifrado, orden = "suma-multi") {
    let resultados = [];

    if (orden === "suma-multi") {
        for (let n = 0; n < MOD; n++) {
            const paso1 = descifrarPorSuma(cifrado)[n].texto;
            const paso2 = descifrarPorMultiplicacion(paso1);
            paso2.forEach(r => {
                resultados.push({ n, m: r.m, inv: r.inv, texto: r.texto });
            });
        }
    } else {
        const mult = descifrarPorMultiplicacion(cifrado);
        mult.forEach(rm => {
            const suma = descifrarPorSuma(rm.texto);
            suma.forEach(rs => {
                resultados.push({ n: rs.n, m: rm.m, inv: rm.inv, texto: rs.texto });
            });
        });
    }

    return resultados;
}

