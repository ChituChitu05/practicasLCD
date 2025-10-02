function generateTable() {
    let letras = ['p', 'q', 'r', 's', 't'];
    const MAX_ROWS = 2 ** letras.length;
    const SELECTS = document.querySelectorAll("select");
    let datos = [];
    for (let i = 0; i < MAX_ROWS; i++) {
        datos.push([
            i < (MAX_ROWS / 2),
            Math.floor(i / 8) % 2 === 0,
            Math.floor(i / 4) % 2 === 0,
            Math.floor(i / 2) % 2 === 0,
            i % 2 === 0
        ]);
    }

    for (let i = 0; i < MAX_ROWS; ++i) {
        datos[i].push(SELECTS[0].value === "¬" ? !operators(datos[i][letras.indexOf('p')], datos[i][letras.indexOf('q')], SELECTS[1].value) : operators(datos[i][letras.indexOf('p')], datos[i][letras.indexOf('q')], SELECTS[1].value)),
            datos[i].push(SELECTS[2].value === "¬" ? !operators(datos[i][letras.indexOf('p')], datos[i][letras.indexOf('r')], SELECTS[3].value) : operators(datos[i][letras.indexOf('p')], datos[i][letras.indexOf('r')], SELECTS[3].value)),
            datos[i].push(SELECTS[4].value === "¬" ? !mod(SELECTS[5].value, SELECTS[6].value, SELECTS[7].value, datos[i][letras.indexOf('p')], datos[i][letras.indexOf('s')]) : mod(SELECTS[5].value, SELECTS[6].value, SELECTS[7].value, datos[i][letras.indexOf('p')], datos[i][letras.indexOf('s')])),
            datos[i].push(SELECTS[8].value === "¬" ? !operators(datos[i][letras.indexOf('r')], datos[i][letras.indexOf('t')], SELECTS[9].value) : operators(datos[i][letras.indexOf('r')], datos[i][letras.indexOf('t')], SELECTS[9].value)),
            datos[i].push(mod(SELECTS[10].value, SELECTS[11].value, SELECTS[12].value, datos[i][letras.indexOf('p')], datos[i][letras.indexOf('s')]))
    }
    for (let i = 0; i < MAX_ROWS; ++i) {
        datos[i].push(operators((datos[i][5] && datos[i][6] && datos[i][7] && datos[i][8]), datos[i][9], "→"))
    }
    let final= null;
    for(let i = 0; i < MAX_ROWS; ++i){
        final = (i === 0)? datos[i][10]:final&&datos[i][10]

    }

    document.getElementById("resultado").textContent = final ?  "Inferencia válida" :"Inferencia inválida";
}



window.onload = function () {
    generateTable();
};