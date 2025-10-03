function union(a, b) {
    return [...new Set([...a, ...b])].sort();
}
function intersection(a, b) {
    return [...new Set(a.filter(x => b.includes(x)))].sort();
}
function symmetricalDifference(a, b) {
    return [...new Set(a.filter(x => !b.includes(x))),...new Set(b.filter(x => !a.includes(x)))].sort();
}
function differennce(a, b) {
    return [...new Set(a.filter(x => !b.includes(x)))].sort();
}
function complemento(u,a){
    return [...new Set(u.filter(x => !a.includes(x)))].sort();
}