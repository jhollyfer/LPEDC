// 0052 · Juntando tudo: o ranking da feira
// Exercício E311 · ★★★
//
// O programa do mercadinho tem TRÊS erros de memória de propósito, um de
// cada assunto do módulo. Ele deveria mostrar:
//
//   Mercadinho: total 125, desconto 15%
//
// Rode com o rodar, leia os avisos e os relatórios (conserte um erro, rode
// de novo) e explique cada um.
//
// Dicas:
// 1. Uma variável local some quando a função termina. O endereço dela
//    vale alguma coisa depois disso?
// 2. Quantos elementos o laço visita?
// 3. Para onde aponta loja? Dá para escrever lá?
// 4. Resposta esperada: (1) maior_desconto devolve o endereço de uma local
//    (aviso "function returns address of local variable"): devolva o
//    valor, int maior_desconto(void); (2) o laço vai até
//    p <= precos + 3 e lê depois do fim: use p < precos + 3; (3) loja
//    aponta para um literal (só leitura): declare char loja[] =
//    "mercadinho".
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

int *maior_desconto(void) {
    int desconto = 15;
    return &desconto;
}

int main(void) {
    int precos[3] = {40, 25, 60};
    char *loja = "mercadinho";
    int soma = 0;

    for (int *p = precos; p <= precos + 3; p++) {
        soma += *p;
    }
    loja[0] = 'M';
    int *d = maior_desconto();
    printf("%s: total %d, desconto %d%%\n", loja, soma, *d);
    return 0;
}
