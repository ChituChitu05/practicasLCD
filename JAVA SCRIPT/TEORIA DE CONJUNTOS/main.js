function main() {
    const DIV_U = document.getElementById("divU");
    const CON_U = document.getElementById("conU");
    const CON_A = document.getElementById("conA");
    const CON_B = document.getElementById("conB");
    const CON_C = document.getElementById("conC");
    const DIV_RS = document.getElementById("resultados");
    const MAX_LEN = document.getElementById("max-len");

    let U = createSetU(MAX_LEN.value);
    let A = createSetA(U, MAX_LEN.value);
    let B = createSetB(U, MAX_LEN.value);
    let C = createSetC(U);
    CON_U.innerHTML = U;
    CON_A.value = A;
    CON_B.value = B;
    CON_C.innerHTML = C;
    actualizarResultados(U, A, B, C, DIV_RS);

    MAX_LEN.addEventListener("keyup", (event) => {
        const n = Number(MAX_LEN.value);
        if (n >= 0 && n <= 27) {
            U = createSetU(MAX_LEN.value);
            DIV_U.innerHTML = `<strong>U =</strong> <span id="conU">{${U}}</span>`;
            
            [A, B, C] = actualizarSubconjuntos(U, A, B);

            actualizarDOM(U, A, B, C, CON_A, CON_B, CON_C, DIV_RS);
        } else {
            DIV_U.innerHTML = "El rango de números debe ser de 0 a 27";
            U = [];
            [A, B, C] = actualizarSubconjuntos(U, A, B);
            recalcularABCDOM(U, A, B, C, CON_A, CON_B, CON_C, DIV_RS);
        }
    });

    CON_A.addEventListener("keyup", (event) => {
        A = [...CON_A.value.toUpperCase()].filter(x => ABCDARIO.includes(x) && U.includes(x)).sort((a, b) => a.localeCompare(b, "es"));
        A = [...new Set(A)];
        CON_A.value = A;
        actualizarResultados(U, A, B, C, DIV_RS);
    });

    CON_B.addEventListener("keyup", (event) => {
        B = [...CON_B.value.toUpperCase()].filter(x => ABCDARIO.includes(x) && U.includes(x)).sort((a, b) => a.localeCompare(b, "es"));
        B = [...new Set(B)];
        CON_B.value = B;
        actualizarResultados(U, A, B, C, DIV_RS);
    });

}

function actualizarResultados(U, A, B, C, DIV_RS) {
    DIV_RS.innerHTML = `
                        <h2>OPERACIONES</h2>
                        <p class="resultado"><strong>((A ∩ B) ∪ (A ∩ C))ᶜ =</strong> {${complemento(U, union(intersection(A, B), intersection(A, C)))}}</p>
                        <p class="resultado"><strong>(A - B) Δ (A - C) =</strong> {${symmetricalDifference(difference(A, B), difference(A, C))}}</p>
                        <p class="resultado"><strong>(Aᶜ Δ Bᶜ) Δ Cᶜ =</strong> {${symmetricalDifference(symmetricalDifference(complemento(U, A), complemento(U, B)), complemento(U, C))}}</p>
    `;
}

function actualizarDOM(U, A, B, C, CON_A, CON_B, CON_C, DIV_RS) {
    CON_A.value = A;
    CON_B.value = B;
    CON_C.innerHTML = C;
    actualizarResultados(U, A, B, C, DIV_RS);
}

function actualizarSubconjuntos(U, A, B) {
    return [[...A.filter(x => U.includes(x))], [...B.filter(x => U.includes(x))], [...createSetC(U)]];
}
window.onload = main;