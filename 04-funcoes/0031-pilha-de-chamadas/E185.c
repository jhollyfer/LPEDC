// 0031 · A pilha de chamadas
// Exercício E185 · ★★★
//
// Um programa de notas travou com divisão por zero. No gdb, o comando bt
// (backtrace) mostrou a pilha do topo (#0) para a base:
//
//   #0  dividir (a=27, b=0) at notas.c:4
//   #1  media (soma=27, quantidade=0) at notas.c:9
//   #2  relatorio (turma=3, soma=27, quantidade=0) at notas.c:15
//   #3  main () at notas.c:22
//
// Reconstrua o programa com essa mesma pilha, mas sem o erro:
//
//   double dividir(int a, int b)        devolve a / b com casas decimais e
//                                       mostra a pilha naquele momento
//   double media(int soma, int quantidade)
//                                       devolve 0 quando quantidade é 0, sem
//                                       chamar dividir
//   void relatorio(int turma, int soma, int quantidade)
//                                       mostra "Turma N: média X"
//
// dividir também conta numa static quantas divisões já fez e mostra o número
// na linha da pilha. O main chama relatorio(3, 27, 3) e relatorio(3, 27, 0).
//
//   Saída esperada:
//     [divisão 1, pilha: main -> relatorio -> media -> dividir]
//   Turma 3: média 9.0
//   Turma 3: média 0.0
//
// Dicas:
// 1. Com a e b int, use (double)a / b para não perder as casas decimais.
// 2. dividir só faz a conta que pediram: quem conhece o sentido de
//    "quantidade" é media, então a conferência do zero fica lá.
// 3. Resposta esperada: a saída acima. Na segunda chamada, media devolve 0
//    antes de chamar dividir, e por isso só aparece uma linha de pilha.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
