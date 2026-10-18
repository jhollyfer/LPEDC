// 0006 · O primeiro programa
// Exercício E036 · ★★★
//
// Resposta:
// a) pré-processador: "fatal error: stdoi.h: No such file or directory";
// b) compilador: "expected ';' before ...";
// c) ligador: o código compila, mas não existe nenhuma função chamada main
//    (o C diferencia maiúsculas): "undefined reference to `main'";
// d) ligador: o compilador só avisa "implicit declaration of function
//    'prinft'" e o ligador para com "undefined reference to `prinft'";
// e) ninguém: compila e roda, mas mostra a tarifa errada. É um erro de
//    execução (de lógica): o compilador não tem como saber o valor certo;
// f) compilador: "expected declaration or statement at end of input".
