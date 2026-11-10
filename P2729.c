// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2729 · ★★★ · O relatório de vendas com quatro bugs
//
// O relatório abaixo compila sem nenhum aviso e roda até o fim, mas tem
// quatro bugs, cada um uma pegadinha deste módulo. Três aparecem na saída; o
// quarto só aparece quando a função dos dias recebe n = 0. Conserte os quatro
// sem reescrever o programa e acrescente, no fim do main, a linha que chama a
// função com n = 0 e mostra quantos dias ela mostrou.
//
//   Saída esperada:
//   total: R$ 1500
//   comissão (5%): R$ 75
//   média por vendedor: R$ 500
//   dias de trás para a frente: 600 500 400
//   vendas sem nenhum dia: 0 dias
//
// Dicas:
// 1. Rode antes e compare linha por linha.
// 2. Olhe a macro, o ?: no meio de uma soma, a ordem de / e * com inteiros
//    e o laço que desce com size_t quando n é 0.
// 3. Depois de consertar a função dos dias, chame-a também com n = 0: ela
//    não pode mostrar nada nem ler fora do vetor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>

#define POR_VENDEDOR(total, n) total / n

// mostra os dias do último para o primeiro e devolve quantos mostrou
size_t de_tras_para_frente(const int *v, size_t n) {
    size_t mostrados = 0;
    for (size_t i = n - 1; i < n; i--) {
        printf(" %d", v[i]);
        mostrados++;
    }
    return mostrados;
}

int main(void) {
    int dias[] = {400, 500, 600};
    int bonus_meta = 0; // a meta não foi batida
    int total = dias[0] + dias[1] + dias[2] + bonus_meta > 0 ? 100 : 0;
    printf("total: R$ %d\n", total);

    int comissao = 5 / 100 * total;
    printf("comissão (5%%): R$ %d\n", comissao);

    printf("média por vendedor: R$ %d\n", POR_VENDEDOR(total, 1 + 2));

    printf("dias de trás para a frente:");
    de_tras_para_frente(dias, 3);
    printf("\n");
    return 0;
}
