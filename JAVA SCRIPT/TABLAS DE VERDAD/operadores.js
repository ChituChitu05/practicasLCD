function operators(a,b,op){
    if (op === "∧") return a && b;
    if (op === "∨") return a || b;
    if (op === "→") return (!a)||b;
    if (op === "↔") return ((!a)||b)&&((!b)||a);
}
