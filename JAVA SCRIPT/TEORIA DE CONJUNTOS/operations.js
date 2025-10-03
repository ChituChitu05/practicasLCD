function union(a, b) {
    return [...new Set([...a, ...b])].sort((a, b) => a.localeCompare(b, "es"));
}
function intersection(a, b) {
    return [...new Set(a.filter(x => b.includes(x)))].sort((a, b) => a.localeCompare(b, "es"));
}
function symmetricalDifference(a, b) {
    return [...new Set([...a.filter(x => !b.includes(x)), ...b.filter(x => !a.includes(x))])].sort((a, b) => a.localeCompare(b, "es"));
}
function difference(a, b) {
    return [...new Set(a.filter(x => !b.includes(x)))].sort((a, b) => a.localeCompare(b, "es"));
}
function complemento(u,a){
    return [...new Set(u.filter(x => !a.includes(x)))].sort((a, b) => a.localeCompare(b, "es"));
}