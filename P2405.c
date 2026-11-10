// Lista · Módulo 24 · Busca de padrões em texto
// Exercício P2405 · ★☆☆ · Quanto o Horspool pula
//
// No cardápio da barraca de comida regional, quanto maior o padrão, maior
// o salto do Horspool. Complete horspool(t, p, &alinhamentos), que conta
// as ocorrências e os alinhamentos testados (a tabela de saltos já está
// pronta). Procure "pa", "pato" e "tapioca de coco" no texto do main.
//
//   Saída esperada:
//   texto com 73 letras
//   pa               m =  2: 1 ocorrência(s), 37 alinhamentos
//   pato             m =  4: 1 ocorrência(s), 21 alinhamentos
//   tapioca de coco  m = 15: 1 ocorrência(s),  8 alinhamentos
//
// Dicas:
// 1. Em cada alinhamento i, compare de j = m - 1 para trás. Achando ou
//    não, avance i += salto[(unsigned char)t[i + m - 1]].
// 2. Com m = 2 o salto máximo é 2: quase metade das posições é testada.
//    Com m = 15 o salto chega a 15.
// 3. Resposta esperada: 37, 21 e 8 alinhamentos, uma ocorrência de cada.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

void monta_saltos(const char *p, int m, int salto[256]) {
    for (int c = 0; c < 256; c++) salto[c] = m;
    for (int j = 0; j < m - 1; j++) salto[(unsigned char)p[j]] = m - 1 - j;
}

int horspool(const char *t, const char *p, int *alinhamentos) {
    (void)t; // apague estas linhas e escreva o Horspool
    (void)p;
    *alinhamentos = 0;
    return 0;
}

int main(void) {
    const char *cardapio = "tapioca de queijo coalho, tacaca quente, pato no tucupi e tapioca de coco";
    const char *pratos[] = {"pa", "pato", "tapioca de coco"};
    printf("texto com %d letras\n", (int)strlen(cardapio));
    for (int k = 0; k < 3; k++) {
        int al;
        int achou = horspool(cardapio, pratos[k], &al);
        printf("%-16s m = %2d: %d ocorrência(s), %2d alinhamentos\n", pratos[k], (int)strlen(pratos[k]), achou, al);
    }
    return 0;
}
