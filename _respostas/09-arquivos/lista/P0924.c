// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0924 · ★★★ · Os produtos entre R$ 10 e R$ 20

#include <stdio.h>

typedef struct {
    int preco; // em centavos
    char nome[20];
} Produto;

int le(FILE *arq, long i, Produto *p) {
    fseek(arq, i * (long) sizeof(Produto), SEEK_SET);
    return fread(p, sizeof *p, 1, arq) == 1;
}

long primeiro_maior_igual(FILE *arq, long n, int alvo, int *leituras) {
    long ini = 0, fim = n; // a resposta está em [ini, fim]
    *leituras = 0;
    while (ini < fim) {
        long meio = (ini + fim) / 2;
        Produto p;
        if (!le(arq, meio, &p)) {
            return n;
        }
        (*leituras)++;
        if (p.preco >= alvo) {
            fim = meio;
        } else {
            ini = meio + 1;
        }
    }
    return ini;
}

int main(void) {
    const char *caminho = "/tmp/p0924_precos.bin";
    Produto lista[10] = {
        {299, "Agua"}, {450, "Pao"}, {699, "Leite"}, {899, "Biscoito"}, {1050, "Cafe"},
        {1290, "Queijo"}, {1599, "Mel"}, {1890, "Manteiga"}, {2100, "Sabao"}, {3490, "Azeite"},
    };
    FILE *arq = fopen(caminho, "wb+");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fwrite(lista, sizeof(Produto), 10, arq);
    fseek(arq, 0, SEEK_END);
    long n = ftell(arq) / (long) sizeof(Produto);

    int leituras;
    long pos = primeiro_maior_igual(arq, n, 1000, &leituras);
    printf("Busca: %d leituras, primeiro na posição %ld\n", leituras, pos);

    Produto p;
    int na_faixa = 0;
    fseek(arq, pos * (long) sizeof(Produto), SEEK_SET);
    while (fread(&p, sizeof p, 1, arq) == 1 && p.preco <= 2000) {
        printf("R$ %d.%02d %s\n", p.preco / 100, p.preco % 100, p.nome);
        na_faixa++;
    }
    printf("%d produtos na faixa\n", na_faixa);
    fclose(arq);
    remove(caminho);
    return 0;
}
