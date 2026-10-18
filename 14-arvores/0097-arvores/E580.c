// 0097 · Árvores
// Exercício E580 · ★★☆
//
// Cada pasta guarda alguns arquivos soltos (o campo mb, em megabytes). A
// função tamanho, já pronta, soma a pasta com tudo que está dentro dela, sem
// imprimir nada. Escreva duas funções que mostram as pastas com o tamanho
// total de cada uma, em ordens diferentes:
//
// - du(n): imprime "<total> MB  <nome>" como o comando du do Linux, com cada
//   pasta aparecendo DEPOIS de todas as subpastas dela (a raiz por último);
// - arvore(n, prof): imprime como o gerenciador de arquivos, a pasta ANTES
//   das subpastas, recuada 2 espaços por nível.
//
//   Saída esperada:
//   -- du --
//   300 MB  praia
//   120 MB  natal
//   430 MB  fotos
//   5 MB  agua
//   8 MB  luz
//   15 MB  contas
//   450 MB  casa
//   -- arvore --
//   casa (450 MB)
//     fotos (430 MB)
//       praia (300 MB)
//       natal (120 MB)
//     contas (15 MB)
//       agua (5 MB)
//       luz (8 MB)
//
// Dicas:
// 1. As duas funções têm o mesmo laço pelos filhos. O que muda é onde fica o
//    printf: depois do laço (du) ou antes dele (arvore).
// 2. Em du, faça a função devolver o total: some n->mb com o que cada filho
//    devolve e imprima no fim. Assim cada pasta é somada uma vez só.
// 3. Resposta esperada: as duas listas acima; fotos = 10 + 300 + 120 = 430 e
//    casa = 5 + 430 + 15 = 450.
//
// Escreva sua resposta abaixo (complete du e arvore):

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 4

typedef struct No {
    char nome[16];
    int mb; // arquivos soltos dentro desta pasta
    struct No *filhos[MAX_FILHOS];
    int qtd;
} No;

No *novo(const char *nome, int mb) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    strcpy(n->nome, nome);
    n->mb = mb;
    n->qtd = 0;
    return n;
}

No *adiciona(No *pai, const char *nome, int mb) {
    No *filho = novo(nome, mb);
    pai->filhos[pai->qtd++] = filho;
    return filho;
}

void libera(No *n) {
    for (int i = 0; i < n->qtd; i++) {
        libera(n->filhos[i]);
    }
    free(n);
}

int tamanho(const No *n) {
    int total = n->mb;
    for (int i = 0; i < n->qtd; i++) {
        total += tamanho(n->filhos[i]);
    }
    return total;
}

int du(const No *n) {
    (void)n; // apague esta linha quando escrever a função
    return 0;
}

void arvore(const No *n, int prof) {
    (void)n; // apague estas duas linhas quando escrever a função
    (void)prof;
}

int main(void) {
    No *casa = novo("casa", 5);
    No *fotos = adiciona(casa, "fotos", 10);
    No *contas = adiciona(casa, "contas", 2);
    adiciona(fotos, "praia", 300);
    adiciona(fotos, "natal", 120);
    adiciona(contas, "agua", 5);
    adiciona(contas, "luz", 8);

    printf("-- du --\n");
    du(casa);
    printf("-- arvore --\n");
    arvore(casa, 0);
    libera(casa);
    return 0;
}
