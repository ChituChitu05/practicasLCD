const ABCDARIO = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ".split("");
const VOCALS = "AEIOU".split("");
const CONSONANTS = "BCDFGHJKLMNÑPQRSTVWXYZ".split("");

function createSetU(MAX_LEN) {
    let UNIVERSE = Array.from({ length: MAX_LEN }, (_, i) => ABCDARIO[i]);
    return UNIVERSE;
}

function createSetA(UNIVERSE,MAX_LEN) {
    let temp_universe = shuffle(UNIVERSE);
    let A = Array.from({ length: Math.floor((Math.random() * MAX_LEN)) }, (_, i) => temp_universe[i]).sort();
    return A;
}

function createSetB(UNIVERSE,MAX_LEN) {
    temp_universe = shuffle(UNIVERSE);
    let B = Array.from({ length: Math.floor((Math.random() * MAX_LEN)) }, (_, i) => temp_universe[i]).sort();
    return B;
}
function createSetC(UNIVERSE) {
    let C = []
    for (let i = 0; i < UNIVERSE.length; ++i) {
        if (VOCALS.includes(UNIVERSE[i])) {
            C.push(UNIVERSE[i])
        }
    }
    return C;
}