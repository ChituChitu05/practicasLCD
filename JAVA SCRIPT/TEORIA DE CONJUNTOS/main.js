function main() {
    const MAX_LEN = 15;
    const U = createSetU(MAX_LEN);
    const A = createSetA(U,MAX_LEN);
    const B = createSetB(U,MAX_LEN);
    const C = createSetC(U);
    

    console.log(`A = ${A}`);
    console.log(`B = ${B}`);
    console.log(`A o B = ${union(A,B)}`);
    console.log(`A y B = ${intersection(A,B)}`);
    console.log(`A + B = ${symmetricalDifference(A,B)}`);
    console.log(`A - B = ${differennce(A,B)}`);
}

window.onload = function() {
    createSets()
};



