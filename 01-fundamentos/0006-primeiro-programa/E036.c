// 0006 · O primeiro programa
// Exercício E036 · ★★★
//
// Para cada situação, diga quem reclama: o pré-processador, o compilador, o
// ligador, ou ninguém (o erro só aparece quando o programa roda). Depois
// provoque cada uma no seu E031 e confira a mensagem.
//
//   a) #include <stdoi.h>
//   b) printf("Linha 077\n")   (sem o ponto e vírgula)
//   c) int Main(void) { ... }  (M maiúsculo)
//   d) prinft("Via Av. Brasil\n");
//   e) printf("Tarifa: R$ 9,40\n"); quando a tarifa certa é R$ 4,90
//   f) o } final apagado
//
// Dicas:
// 1. O pré-processador só cuida das linhas com #.
// 2. O ligador procura funções pelo nome, inclusive a main.
// 3. O compilador confere a gramática, mas não sabe qual é a tarifa certa.
// 4. Resposta esperada: a) pré-processador ("stdoi.h: No such file or
//    directory"); b) compilador ("expected ';'"); c) ligador: o código
//    compila, mas não existe main ("undefined reference to `main'"); d)
//    ligador ("undefined reference to `prinft'", depois do aviso de
//    "implicit declaration"); e) ninguém: compila, roda e mostra o valor
//    errado, um erro de execução (de lógica); f) compilador ("expected
//    declaration or statement at end of input").
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
