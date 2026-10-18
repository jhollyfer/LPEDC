// 0018 · Lógicos: E, OU, NÃO
// Exercício E108 · ★★★
//
// Este programa deveria dizer se o número é par e se está entre 10 e 20
// (sem incluir os extremos). Ele compila, mas com dois avisos, e erra.
// Teste com 14 (deveria dar 1 e 1) e com 25 (deveria dar 0 e 0). Explique
// cada erro e conserte. Lembrete: n & 1 pega o último bit de n em
// binário: 0 para par, 1 para ímpar (o & bit a bit vem no assunto 0070).
//
// Dicas:
// 1. Leia os avisos do gcc: eles apontam exatamente as duas linhas.
// 2. Na tabela de precedência, o == fica ACIMA do &. E 10 < n < 20 é
//    (10 < n) < 20.
// 3. Resposta esperada: n & 1 == 0 é n & (1 == 0), que é n & 0, sempre 0;
//    o certo é (n & 1) == 0. 10 < n < 20 compara 0 ou 1 com 20, sempre 1;
//    o certo é n > 10 && n < 20. Consertado: 14 → 1 e 1; 25 → 0 e 0.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int n;
    printf("Número: ");
    scanf("%d", &n);

    bool par = n & 1 == 0;
    bool na_faixa = 10 < n < 20;

    printf("Par? %d\n", par);
    printf("Entre 10 e 20? %d\n", na_faixa);
    return 0;
}
