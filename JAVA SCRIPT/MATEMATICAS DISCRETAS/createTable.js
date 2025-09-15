function createTable(datos, div){
    const tabla = document.createElement("table");
    tabla.classList.add("tabla");
    
    datos.forEach((fila, index) => {
        const tr = document.createElement("tr");

        fila.forEach((celda) => {
            const celdaElem = index === 0 ? document.createElement("th") : document.createElement("td");

            if (index !== 0) {
                celdaElem.textContent = celda === true ? "V" : "F";
                celdaElem.style.backgroundColor = (celda === true)  ? "rgb(117, 255, 170)" : "rgb(226, 70, 117)"
                celdaElem.style.color = (celda === true) ? "rgba(52, 114, 76, 1)" : "rgba(121, 28, 56, 1)"
            } else {
                celdaElem.innerHTML = celda;
            }

            tr.appendChild(celdaElem);
        });

        tabla.appendChild(tr);
    });

    const contenedor = document.getElementById(div);
    contenedor.innerHTML = "";
    contenedor.appendChild(tabla);
}