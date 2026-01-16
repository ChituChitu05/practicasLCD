const tema = document.getElementById("tema");
const controls = document.getElementById("controls");
const result = document.getElementById("result");


//crea botones
function clearControls() {
    controls.innerHTML = "";
    result.textContent = "";
}

function makeNumberInput(id, placeholder = "") {
    const inp = document.createElement("input");
    inp.type = "number";
    inp.id = id;
    inp.placeholder = placeholder;
    inp.step = "1";
    return inp;
}

function makeTextInput(id, placeholder = "") {
    const inp = document.createElement("input");
    inp.type = "text";
    inp.id = id;
    inp.placeholder = placeholder;
    return inp;
}

function makeButton(text, onClick) {
    const b = document.createElement("button");
    b.textContent = text;
    b.type = "button";
    b.addEventListener("click", onClick);
    return b;
}

function labelWrap(text, element) {
    const wrap = document.createElement("div");
    const lbl = document.createElement("label");
    lbl.textContent = text;
    wrap.appendChild(lbl);
    wrap.appendChild(element);
    return wrap;
}

// despliega menu de algoritmos.
function showDivision() {
    clearControls();
    //creaciopn de inputs
    const a = makeNumberInput("a", "dividendo");
    const b = makeNumberInput("b", "divisor");

    controls.appendChild(labelWrap("a:", a));
    controls.appendChild(labelWrap("b:", b));

    controls.appendChild(makeButton("Calcular", () => {
        //llama a la funcion de algoritmo division 
        result.innerHTML = "";
        try {
            const res = divisionEuclidea(Number(a.value), Number(b.value));
            result.textContent = `a = ${res.a}; b = ${res.b}; q = ${res.q}; r = ${res.r} \n \n  ${res.a} = ${res.b} (${res.q}) + ${res.r}`;
        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}

function showMCD() {
    clearControls();
    //creaciopn de inputs
    const a = makeNumberInput("a");
    const b = makeNumberInput("b");

    controls.appendChild(labelWrap("a:", a));
    controls.appendChild(labelWrap("b:", b));

    controls.appendChild(makeButton("Calcular MCD", () => {
        result.innerHTML = "";
        //llama a la funcion de MCD
        try {
            const g = euclidMCD(Number(a.value), Number(b.value));

            result.textContent = "";
            let texto = "";

            g.forEach(step => {
                texto += `${step.a} = ${step.b} * (${step.q}) + ${step.r}\n`;
            });
            const stepDiv = document.createElement("div");
            stepDiv.style.whiteSpace = "pre";
            stepDiv.textContent = texto;
            stepDiv.textContent += `\nMCD(${a.value}, ${b.value}) = ${g[g.length - 1].b}`;
            result.appendChild(stepDiv);
        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}

function showMCM() {
    clearControls();

    const a = makeNumberInput("a");
    const b = makeNumberInput("b");

    controls.appendChild(labelWrap("a:", a));
    controls.appendChild(labelWrap("b:", b));

    controls.appendChild(makeButton("Calcular MCM", () => {
        result.innerHTML = "";
        try {
            const A = Number(a.value);
            const B = Number(b.value);

            const { mcd, mcm } = calcularMCM(A, B);

            const div = document.createElement("div");
            div.style.whiteSpace = "pre";

            div.textContent =
                `MCD(${A}, ${B}) = ${mcd}\n` +
                `MCM(${A}, ${B}) = ((${A}) (${B})) / ${mcd}\n` +
                `MCM(${A}, ${B}) = ${mcm}`;

            result.appendChild(div);

        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}


function showBezout() {
    clearControls();

    const a = makeNumberInput("a");
    const b = makeNumberInput("b");

    controls.appendChild(labelWrap("a:", a));
    controls.appendChild(labelWrap("b:", b));

    controls.appendChild(makeButton("Calcular Bézout", () => {
        result.innerHTML = "";
        try {
            const A = Number(a.value);
            const B = Number(b.value);

            const { x, y, mcd, steps, sustitucion } = bezout(A, B);

            let txt = "Euclides:\n";
            steps.forEach(s => {
                txt += `${s.a} = ${s.b}*(${s.q}) + ${s.r}\n`;
            });

            txt += `\nMCD = ${mcd}\n`;
            txt += `${A}(${x}) + ${B}(${y}) = ${mcd}\n`;

            txt += `\nSustitución inversa:\n${sustitucion}`;
            txt += `\n${mcd} = ${A}(${x}) + ${B}(${y})\n`;

            const div = document.createElement("div");
            div.style.whiteSpace = "pre";
            div.textContent = txt;
            result.appendChild(div);

        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}

function showPrimo() {
    clearControls();

    const n = makeNumberInput("n");
    controls.appendChild(labelWrap("Número:", n));

    controls.appendChild(makeButton("Verificar primo", () => {
        result.innerHTML = "";

        const valor = Number(n.value);
        const { primo, divisor, steps } = esPrimo(valor);

        let texto = "Divisiones realizadas:\n";
        steps.forEach(s => texto += s + "\n");

        texto += "\n";

        if (primo) {
            texto += `${valor} es primo`;
        } else {
            if (divisor === null)
                texto += `${valor} no es primo`;
            else
                texto += `${valor} no es primo porque es divisible por ${divisor}`;
        }

        const div = document.createElement("div");
        div.style.whiteSpace = "pre";
        div.textContent = texto;
        result.appendChild(div);
    }));
}



function showCambioBase() {
    clearControls();

    const num = makeTextInput("num");
    const b1 = makeNumberInput("b1");
    const b2 = makeNumberInput("b2");

    controls.appendChild(labelWrap("Número:", num));
    controls.appendChild(labelWrap("Base origen:", b1));
    controls.appendChild(labelWrap("Base destino:", b2));

    controls.appendChild(makeButton("Convertir", () => {
        result.innerHTML = "";
        try {
            const N = num.value.trim();
            const B1 = Number(b1.value);
            const B2 = Number(b2.value);

            const r = cambioBase(N, B1, B2);

            const div = document.createElement("div");
            div.style.whiteSpace = "pre";

            let txt = "";
            txt += "Conversión a base 10:\n";
            r.pasosBase10.forEach(p => txt += p + "\n");

            txt += `\nValor en base 10 = ${r.base10}\n\n`;

            txt += `Conversión a base ${B2}:\n`;
            r.pasosDestino.forEach(p => txt += p + "\n");

            txt += `\nResultado final: ${r.resultado}`;

            div.textContent = txt;
            result.appendChild(div);

        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}

function showTFA() {
    clearControls();
    const n = makeNumberInput("n");
    controls.appendChild(labelWrap("Número:", n));

    controls.appendChild(makeButton("Descomponer", () => {
        result.innerHTML = "";
        try {
            const N = Number(n.value);
            if (N <= 1) {
                result.textContent = "Debe ser mayor que 1.";
                return;
            }
            const r = factorizarTFA(N);
            const div = document.createElement("div");
            div.style.whiteSpace = "pre";

            let texto = "";
            texto += "Pasos:\n";
            r.pasos.forEach(p => texto += p + "\n");

            texto += "\nFactorización:\n";
            texto += `${N} = `;
            let conteo = {};
            r.factores.forEach(f => conteo[f] = (conteo[f] || 0) + 1);

            const partes = Object.keys(conteo)
                                .map(p => `${p}^${conteo[p]}`)
                                .join(" * ");

            texto += partes;

            div.textContent = texto;
            result.appendChild(div);

        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}

function showDescifrado() {
    clearControls();
    result.innerHTML = "";

    const txt = makeTextInput("texto");
    const nInp = makeNumberInput("n_suma");
    const mInp = makeNumberInput("m_mult");

    const modo = document.createElement("select");
    modo.innerHTML = `
        <option value="suma">Solo suma</option>
        <option value="mult">Solo multiplicación</option>
        <option value="suma-mult">Suma → Multiplicación</option>
        <option value="mult-suma">Multiplicación → Suma</option>
    `;

    const opcionBusqueda = document.createElement("select");
    opcionBusqueda.innerHTML = `
        <option value="usar">Usar claves dadas (si las conoces)</option>
        <option value="bruteforce">Buscar todas las claves (fuerza bruta)</option>
    `;

    controls.appendChild(labelWrap("Texto cifrado:", txt));
    controls.appendChild(labelWrap("n (suma) — opcional:", nInp));
    controls.appendChild(labelWrap("m (mult) — opcional:", mInp));
    controls.appendChild(labelWrap("Modo de aplicación:", modo));
    controls.appendChild(labelWrap("Modo de búsqueda:", opcionBusqueda));

    controls.appendChild(makeButton("Descifrar", () => {
        result.innerHTML = "";
        try {
            const texto = String(txt.value || "").toUpperCase().trim();
            if (!texto) {
                result.textContent = "Introduce el texto cifrado.";
                return;
            }

            const modoBusqueda = opcionBusqueda.value;
            const modoAplic = modo.value;

            const div = document.createElement("div");
            div.style.whiteSpace = "pre";

            if (modoBusqueda === "usar") {
                // usar claves dadas: n y/o m deben ponerse
                const nVal = Number(nInp.value);
                const mVal = Number(mInp.value);
                let salida = texto;

                if (modoAplic === "suma") {
                    if (Number.isNaN(nVal)) { result.textContent = "Proporciona n para descifrar por suma."; return; }
                    salida = descifrarSuma(salida, nVal);
                    div.textContent = `Resultado (suma n=${nVal}):\n${salida}`;
                    result.appendChild(div);
                    return;
                }

                if (modoAplic === "mult") {
                    if (Number.isNaN(mVal)) { result.textContent = "Proporciona m para descifrar por multiplicación."; return; }
                    // intentamos inverso; si no existe, devolvemos todas las posibles cadenas
                    try {
                        // intentar inverso (bezout lanzará si no invertible o devolverá valor)
                        const inv = inversoMultiplicativo(mVal, M); // definimos abajo
                        // si existe inverso hacemos desifrado directo
                        let out = "";
                        for (const ch of salida) {
                            const c = ALFABETO.indexOf(ch);
                            if (c < 0) throw new Error("Carácter inválido: " + ch);
                            const p = residuo(inv * c, M);
                            out += ALFABETO[p];
                        }
                        div.textContent = `Resultado (mult m=${mVal} inv=${inv}):\n${out}`;
                        result.appendChild(div);
                        return;
                    } catch (err) {
                        // m no invertible -> usar la función que devuelve todas las posibilidades
                        const candidatos = descifrarMultiplicacionPosibles(texto, mVal);
                        div.textContent = `m no invertible módulo ${M}. Candidatos (${candidatos.length}):\n` + candidatos.join("\n");
                        result.appendChild(div);
                        return;
                    }
                }

                // modos compuestos
                if (modoAplic === "suma-mult") {
                    if (Number.isNaN(nVal) || Number.isNaN(mVal)) { result.textContent = "Proporciona n y m."; return; }
                    // Primero suma, luego mult. Pero si mult no invertible habrá ambigüedad.
                    const afterSuma = descifrarSuma(texto, nVal);
                    try {
                        const inv = inversoMultiplicativo(mVal, M);
                        // aplicar multiplicación (inverso) sobre afterSuma
                        let out = "";
                        for (const ch of afterSuma) {
                            const c = ALFABETO.indexOf(ch);
                            if (c < 0) throw new Error("Carácter inválido: " + ch);
                            out += ALFABETO[residuo(inv * c, M)];
                        }
                        div.textContent = `Resultado (suma ${nVal} → mult ${mVal} inv=${inv}):\n${out}`;
                        result.appendChild(div);
                        return;
                    } catch (err) {
                        // mult no invertible: calcular candidatos con brute-force para esa m y n
                        const resultados = bruteForceAll(texto)
                            .filter(r => r.m === mVal && r.n === nVal)
                            .map(r => r.candidates)
                            .flat();
                        div.textContent = `m no invertible. Candidatos (${resultados.length}):\n` + resultados.join("\n");
                        result.appendChild(div);
                        return;
                    }
                }

                if (modoAplic === "mult-suma") {
                    if (Number.isNaN(nVal) || Number.isNaN(mVal)) { result.textContent = "Proporciona n y m."; return; }
                    // primero mult, luego suma. mult puede ser no invertible.
                    try {
                        const inv = inversoMultiplicativo(mVal, M);
                        // aplicar inverso a texto
                        let inter = "";
                        for (const ch of texto) {
                            const c = ALFABETO.indexOf(ch);
                            if (c < 0) throw new Error("Carácter inválido: " + ch);
                            inter += ALFABETO[residuo(inv * c, M)];
                        }
                        // ahora aplicar suma (descifrarSuma)
                        const out = descifrarSuma(inter, nVal);
                        div.textContent = `Resultado (mult ${mVal} inv=${inv} → suma ${nVal}):\n${out}`;
                        result.appendChild(div);
                        return;
                    } catch (err) {
                        // mult no invertible -> candidatos
                        const resultados = bruteForceAll(texto)
                            .filter(r => r.m === mVal && r.n === nVal)
                            .map(r => r.candidates)
                            .flat();
                        div.textContent = `m no invertible. Candidatos (${resultados.length}):\n` + resultados.join("\n");
                        result.appendChild(div);
                        return;
                    }
                }

            } else {
                // modo brute force: probar todos los pares (m,n)
                const todos = bruteForceAll(texto);
                // prepararmos salida compacta: sólo mostrar (m,n) con candidatos y cuántos
                let textoOut = `Resultados brute-force para "${texto}":\n\n`;
                for (const r of todos) {
                    if (r.candidates.length === 0) continue;
                    textoOut += `m=${r.m}, n=${r.n} → ${r.candidates.length} candidato(s)\n`;
                    // si pocos candidatos, listarlos (limitar por legibilidad)
                    if (r.candidates.length <= 12) {
                        textoOut += r.candidates.join("\n") + "\n";
                    } else {
                        textoOut += r.candidates.slice(0, 12).join("\n") + `\n...(+${r.candidates.length - 12})\n`;
                    }
                    textoOut += "\n";
                }
                div.textContent = textoOut;
                result.appendChild(div);
                return;
            }

        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}

function showDescifrado() {
    clearControls();
    
    const txt = makeTextInput("cadena");
    controls.appendChild(labelWrap("Texto cifrado:", txt));

    // Selección del modo
    const modo = document.createElement("select");
    modo.innerHTML = `
        <option value="suma">Solo suma</option>
        <option value="multi">Solo multiplicación</option>
        <option value="suma-multi">Suma → Multiplicación</option>
        <option value="multi-suma">Multiplicación → Suma</option>
    `;
    controls.appendChild(labelWrap("Modo:", modo));

    controls.appendChild(makeButton("Descifrar", () => {
        result.innerHTML = "";

        try {
            const C = txt.value.trim().toUpperCase();
            if (!C) {
                result.textContent = "Ingrese texto cifrado.";
                return;
            }

            let salida = [];

            if (modo.value === "suma") {
                salida = descifrarPorSuma(C);
            } else if (modo.value === "multi") {
                salida = descifrarPorMultiplicacion(C);
            } else {
                salida = descifrarCombinado(C, modo.value);
            }

            const div = document.createElement("div");
            div.style.whiteSpace = "pre";

            let texto = "";
            salida.forEach(r => {
                if ("m" in r && "n" in r) {
                    texto += `n=${r.n}, m=${r.m}  →  ${r.texto}\n`;
                } else if ("n" in r) {
                    texto += `n=${r.n}  →  ${r.texto}\n`;
                } else if ("m" in r) {
                    texto += `m=${r.m}, inv=${r.inv}  →  ${r.texto}\n`;
                }
            });

            div.textContent = texto;
            result.appendChild(div);

        } catch (err) {
            result.textContent = "Error: " + err.message;
        }
    }));
}




function onChange() {
    switch (tema.value) {
        case "division": return showDivision();
        case "mcd": return showMCD();
        case "mcm": return showMCM();
        case "bezout": return showBezout();
        case "primo": return showPrimo();
        case "base": return showCambioBase();
        case "tfa": return showTFA();
        case "descifrado": return showDescifrado();
    }
}

tema.addEventListener("change", onChange);
onChange();