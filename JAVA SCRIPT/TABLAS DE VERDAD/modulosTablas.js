function mod1A(op1,op2,op3,p,q){
    if (op1 === "¬" && op3 !== "¬"){return operators(!p,q,op2)}
    if (op1 === "¬" && op3 === "¬"){return operators(!p,!q,op2)}
    if (op1 !== "¬" && op3 === "¬"){return operators(p,!q,op2)}
}
