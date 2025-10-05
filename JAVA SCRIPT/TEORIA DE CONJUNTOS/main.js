function main() {
    const CON_U = document.getElementById("conU");
    const CON_A = document.getElementById("conA");
    const CON_B = document.getElementById("conB");
    const CON_C = document.getElementById("conC");
    const RES_1 = document.getElementById("res1");
    const RES_2 = document.getElementById("res2");
    const RES_3 = document.getElementById("res3");

    const MAX_LEN = document.getElementById("max-len");

    let U = createSetU(MAX_LEN.value);
    let A = createSetA(U, MAX_LEN.value);
    let B = createSetB(U, MAX_LEN.value);
    let C = createSetC(U);

    CON_U.innerHTML = U;
    CON_A.value = A;
    CON_B.value = B;
    CON_C.innerHTML = C;
    actualizarResultados(U, A, B, C, RES_1, RES_2, RES_3);

    MAX_LEN.addEventListener("keyup", (event) => {
        const n = Number(MAX_LEN.value);
        if (n >= 0 && n <= 27) {
            
            U = createSetU(MAX_LEN.value);
            CON_U.innerHTML = `<strong>U =</strong> {${U}}`;
            
            C = createSetC(U);
            CON_C.innerHTML = C;
            actualizarResultados(U, A, B, C, RES_1, RES_2, RES_3);
        } else {
            CON_U.innerHTML = "El rango de números debe ser de 0 a 27";
        }
    });

    CON_A.addEventListener("keyup", (event) => {
        A = [...CON_A.value.toUpperCase()].filter(x => ABCDARIO.includes(x)).sort((a, b) => a.localeCompare(b, "es"));
        A = [...new Set(A)];
        CON_A.value = A;
        actualizarResultados(U, A, B, C, RES_1, RES_2, RES_3);
    });
    CON_B.addEventListener("keyup", (event) => {
        B = [...CON_B.value.toUpperCase()].filter(x => ABCDARIO.includes(x)).sort((a, b) => a.localeCompare(b, "es"));
        B = [...new Set(B)];
        CON_B.value = B;
        actualizarResultados(U, A, B, C, RES_1, RES_2, RES_3);
    });

}
window.onload = main;

function actualizarResultados(U, A, B, C, RES_1, RES_2, RES_3) {

    RES_1.innerHTML = complemento(U, union(intersection(A, B), intersection(A, C)));
    RES_2.innerHTML = symmetricalDifference(difference(A, B), difference(A, C));
    RES_3.innerHTML = symmetricalDifference(symmetricalDifference(complemento(U, A), complemento(U, B)), complemento(U, C));
}
