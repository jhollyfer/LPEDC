// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0918 · ★★☆ · Salvar e carregar o orçamento da reforma
//
// Complete as duas funções do programa:
//
//   int salva(const char *caminho, const Item *itens, int n)
//   int carrega(const char *caminho, Item *itens, int max)
//
// O formato do arquivo texto é: na 1ª linha, quantos itens vêm; depois, um
// item por linha, "descricao quantidade preco". salva devolve 1 se deu
// certo. carrega lê no máximo max itens e devolve quantos leu (ou -1 se não
// abriu o arquivo). O main já grava, carrega num OUTRO vetor e mostra.
//
//   Saída esperada:
//   Carregados: 3 itens
//   cimento      10 x R$  32.90 = R$  329.00
//   areia         3 x R$ 120.00 = R$  360.00
//   tijolo      500 x R$   0.85 = R$  425.00
//   Total: R$ 1114.00
//
// Dicas:
// 1. Em salva: fprintf(arq, "%d\n", n) e depois um fprintf por item.
// 2. Em carrega: leia o n com fscanf, e no laço pare em i < n e i < max.
//    Confira se cada fscanf devolveu 3.
// 3. Resposta esperada: a saída acima; o total é 329 + 360 + 425 = 1114.
//
// Escreva sua resposta abaixo (complete as duas funções):

#include <stdio.h>

typedef struct {
    char descricao[20];
    int quantidade;
    double preco;
} Item;

int salva(const char *caminho, const Item *itens, int n) {
    (void) caminho; // apague estas linhas quando escrever a função
    (void) itens;
    (void) n;
    return 0;
}

int carrega(const char *caminho, Item *itens, int max) {
    (void) caminho; // apague estas linhas quando escrever a função
    (void) itens;
    (void) max;
    return -1;
}

int main(void) {
    const char *caminho = "/tmp/p0918_orcamento.txt";
    Item obra[3] = {{"cimento", 10, 32.90}, {"areia", 3, 120.00}, {"tijolo", 500, 0.85}};

    if (!salva(caminho, obra, 3)) {
        printf("Não salvou\n");
        return 1;
    }
    Item lidos[10];
    int n = carrega(caminho, lidos, 10);
    remove(caminho);
    if (n < 0) {
        printf("Não carregou\n");
        return 1;
    }
    printf("Carregados: %d itens\n", n);
    double total = 0;
    for (int i = 0; i < n; i++) {
        double sub = lidos[i].quantidade * lidos[i].preco;
        printf("%-10s %4d x R$ %6.2f = R$ %7.2f\n", lidos[i].descricao, lidos[i].quantidade,
               lidos[i].preco, sub);
        total += sub;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
