function mcd(a, b) {
    let bases
//mcd(a,b) = mcd (b,r)
// a = b(q) + r
// r es el residuo de a/b (a%b)


// siguientes rondas
// a = b 
// b = r
  while (b !== 0) {
    const r = a % b;
    a = b;
    b = r;
  }
  return a;
}

