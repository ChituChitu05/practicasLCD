function generateTable() {
    const operadores = document.getElementsByClassName("operadoresSelection1");
    const operadoresin = document.getElementsByClassName("operadores1");
    const datos = [[
            "p", "q", "s",
            `(${operadores[0].value}p${operadores[1].value}${operadores[2].value}q)<br><small>A</small>`,
            `(${operadores[4].value}p${operadores[5].value}s)<br><small>B</small>`,
            `(s${operadores[7].value}q)<br><small>C</small>`,
            `[A${operadores[3].value}B]<br><small>D</small>`,
            `[C]${operadores[6].value}D`
        ]];
    const MAX_ROWS = 8;

    for (let i = 0; i < operadores.length ;++i){
        operadoresin[i].value = operadores[i].value;
    }
    for (let i = 0; i < MAX_ROWS; i++) {
        datos.push([
            i < (MAX_ROWS / 2),
            Math.floor(i / 2) % 2 === 0,
            i % 2 === 0
        ]);
    }

    for(let i = 1; i < MAX_ROWS+1;++i){
        datos[i].push(operadores[0].value==="¬"|| operadores[2].value==="¬"? mod1A(operadores[0].value,operadores[1].value,operadores[2].value,datos[i][0],datos[i][1]):
                                                                             operators(datos[i][0],datos[i][1],operadores[1].value));
        datos[i].push(operadores[4].value==="¬" ? operators(!datos[i][0],datos[i][2],operadores[5].value):operators(datos[i][0],datos[i][2],operadores[5].value));
        datos[i].push(operators(datos[i][2],datos[i][1],operadores[7].value));
        datos[i].push(operators(datos[i][3],datos[i][4],operadores[3].value));
        datos[i].push(operators(datos[i][5],datos[i][6],operadores[6].value));
    }

    createTable(datos,"tabla1");
}

function generateTable2() {
    const operadores2 = document.getElementsByClassName("operadoresSelection2");
    const operadoresin = document.getElementsByClassName("operadores2");
    const datos = [[
            "p", "q","r","t",
            `(${operadores2[0].value}p${operadores2[1].value}${operadores2[2].value}q)<br><small>A</small>`,
            `(${operadores2[6].value}r${operadores2[7].value}${operadores2[8].value}t)<br><small>B</small>`,
            `(q${operadores2[10].value}t)<br><small>C</small>`,
            `[A${operadores2[3].value}${operadores2[4].value}r]<br><small>D</small>`,
            `[B${operadores2[9].value}C]<br><small>E</small>`,
            `[D]${operadores2[5].value}[E]`, 
        ]];
    const MAX_ROWS = 16;

    for (let i = 0; i < operadores2.length ;++i){
        operadoresin[i].value = operadores2[i].value;
    }
    for (let i = 0; i < MAX_ROWS; i++) {
        datos.push([
            i < (MAX_ROWS / 2),
            Math.floor(i / 4) % 2 === 0,
            Math.floor(i / 2) % 2 === 0,
            i % 2 === 0
        ]);
    }

    for(let i = 1; i < MAX_ROWS +1  ;++i){
        datos[i].push(operadores2[0].value ==="¬"|| operadores2[2].value==="¬"? mod1A(operadores2[0].value,operadores2[1].value,operadores2[2].value,datos[i][0],datos[i][1]):
                                                                            operators(datos[i][0],datos[i][1],operadores2[1].value)),
        datos[i].push(operadores2[6].value ==="¬"|| operadores2[8].value==="¬"? mod1A(operadores2[6].value,operadores2[7].value,operadores2[8].value,datos[i][2],datos[i][3]):
                                                                            operators(datos[i][2],datos[i][3],operadores2[7].value));
        datos[i].push(operators(datos[i][1],datos[i][3],operadores2[10].value)),
        datos[i].push(operadores2[4].value === "¬" ? operators(datos[i][4],!datos[i][2],operadores2[3].value):operators(datos[i][4],datos[i][2],operadores2[3].value)),
        datos[i].push(operators(datos[i][5],datos[i][6],operadores2[9].value)),
        datos[i].push(operators(datos[i][7],datos[i][8],operadores2[5].value))
       }
    

    createTable(datos,"tabla2");
}

window.onload = function() {
    generateTable();
    generateTable2();
};