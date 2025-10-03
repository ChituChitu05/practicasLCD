function main() {
    const MAX_LEN = document.getElementById("max-len").value;
    const U = createSetU(MAX_LEN);
    const A = createSetA(U, MAX_LEN);
    const B = createSetB(U, MAX_LEN);
    const C = createSetC(U);

    const resultadosDiv = document.getElementById('resultados');

    if (MAX_LEN > 27 || MAX_LEN < 1) {
        resultadosDiv.innerHTML = `<p class="resultado"><strong>EL RANGO DE LETRAS DEBE SER ENTRE 1 Y 27</strong></p>`;
    } else {
        resultadosDiv.innerHTML = `
                            <p class="resultado"><strong>U =</strong> {${U}}</p>
                            <p class="resultado"><strong>A =</strong> {${A}}</p>
                            <p class="resultado"><strong>B =</strong> {${B}}</p>
                            <p class="resultado"><strong>C =</strong> {${C}}</p>
                            <p class="resultado"><strong>((A ∩ B) ∪ (A ∩ C)  transform: translateY(-1px);
  box-shadow: 0 2px 4px rgba(0,0,0,0.5);)ᶜ =</strong> {${complemento(U, union(intersection(A, B), intersection(A, C)))}}</p>
                            <p class="resultado"><strong>(A - B) Δ (A - C) =</strong> {${symmetricalDifference(difference(A, B), difference(A, C))}}</p>
                            <p class="resultado"><strong>(Aᶜ Δ Bᶜ) Δ Cᶜ =</strong> {${symmetricalDifference(symmetricalDifference(complemento(U, A), complemento(U, B)), complemento(U, C))}}</p>
`;
    }
}

window.onload = main;