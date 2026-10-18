// A298 · O corretor que aprende palavras novas

#include <stdio.h>
#include "corretor.h"

// Lê o texto linha por linha. Uma linha que começa com '+' ensina palavras
// novas ao dicionário; as outras são conferidas.
//
//   printf 'hoje tem fieira na rua\n+ pastel esquina\na fiera da esquina tem pastel\n' | ~/LPEDC/rodar 22-arvores-avancadas/0149-juntando-tudo/A298.c

int main(void) {
    NoC *dic = cor_cria();
    cor_carrega_basico(dic);
    int nos_antes = cor_nos(dic);

    char linha[256], palavra[COR_MAX], sug[3][COR_MAX];
    int num = 0, aprendidas = 0;
    while (fgets(linha, sizeof linha, stdin) != NULL) {
        num++;
        const char *p = linha;
        if (linha[0] == '+') {
            int antes = aprendidas;
            while (cor_proxima(&p, palavra)) {
                if (!cor_contem(dic, palavra) && cor_insere(dic, palavra)) {
                    aprendidas++;
                }
            }
            printf("linha %d: aprendi %d palavra(s)\n", num, aprendidas - antes);
            continue;
        }
        int erros = 0;
        while (cor_proxima(&p, palavra)) {
            if (cor_contem(dic, palavra)) {
                continue;
            }
            erros++;
            int k = cor_sugere(dic, palavra, sug, 3);
            printf("linha %d: \"%s\"?", num, palavra);
            for (int i = 0; i < k; i++) {
                printf(" %s", sug[i]);
            }
            printf("\n");
        }
        if (erros == 0) {
            printf("linha %d: tudo certo\n", num);
        }
    }
    printf("Palavras aprendidas: %d (a trie foi de %d para %d nós)\n",
           aprendidas, nos_antes, cor_nos(dic));

    cor_libera(dic);
    return 0;
}
// Saída:
// linha 1: "fieira"? feira
// linha 2: aprendi 2 palavra(s)
// linha 3: "fiera"? feira
// Palavras aprendidas: 2 (a trie foi de 239 para 247 nós)
