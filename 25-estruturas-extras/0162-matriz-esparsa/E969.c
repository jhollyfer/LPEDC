// 0162 · Matriz esparsa
// Exercício E969 · ★★☆
//
// A matriz notas tem os clientes nas linhas e os filmes nas colunas. A
// locadora agora quer o contrário: a média de cada FILME. Andar por coluna
// numa lista por linha é ruim (teria que visitar todas as linhas). Então:
// 1. escreva transposta(m), que devolve uma nova Esparsa com linhas e
//    colunas trocadas (m->colunas x m->linhas), percorrendo as células de m;
// 2. no main, use a transposta para mostrar, para cada filme com nota,
//    quantas notas ele tem e a média; libere as duas matrizes.
//
//   Saída esperada:
//   Filme 0: 2 notas, média 4.50
//   Filme 2: 3 notas, média 2.67
//   Filme 5: 1 nota, média 1.00
//   Células: 6 e 6
//
// Dicas:
// 1. Crie t = esp_cria(m->colunas, m->linhas). Para cada linha i de m e cada
//    célula c dessa linha, faça esp_define(t, c->col, i, c->valor).
// 2. Na transposta, a linha f é o filme f: percorra t->linha[f] somando.
//    Pule os filmes cuja linha é NULL (e escreva "nota" quando for uma só).
// 3. Resposta esperada: a saída acima (os dois nao_zeros são iguais).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "esparsa.h"

int main(void) {
    Esparsa *notas = esp_cria(4, 6); // 4 clientes x 6 filmes
    esp_define(notas, 0, 0, 5);
    esp_define(notas, 0, 2, 3);
    esp_define(notas, 1, 2, 1);
    esp_define(notas, 2, 0, 4);
    esp_define(notas, 3, 2, 4);
    esp_define(notas, 3, 5, 1);

    esp_libera(notas);
    return 0;
}
