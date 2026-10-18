// 0057 · Juntando tudo: o ranking da feira
// Exercício E341 · ★★★
//
// Resposta: (1) maior_desconto devolvia o endereço de uma variável local,
// que deixa de existir quando a função termina: devolva o valor;
// (2) o laço lia precos[3], depois do fim: a condição é p < precos + 3;
// (3) loja apontava para um literal, que é só leitura: vira um vetor.

#include <stdio.h>

int maior_desconto(void) {
    int desconto = 15;
    return desconto;
}

int main(void) {
    int precos[3] = {40, 25, 60};
    char loja[] = "mercadinho";
    int soma = 0;

    for (int *p = precos; p < precos + 3; p++) {
        soma += *p;
    }
    loja[0] = 'M';
    int d = maior_desconto();
    printf("%s: total %d, desconto %d%%\n", loja, soma, d);
    return 0;
}
