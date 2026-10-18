// 0087 · Pilha
// Exercício E522 · ★★★
//
// A bancada da cozinha tem 6 lugares e guarda duas pilhas ao mesmo tempo:
// os pratos limpos crescem a partir da esquerda (posição 0) e os sujos a
// partir da direita (posição 5), uma em direção à outra. Assim nenhuma das
// duas fica com espaço sobrando enquanto a outra está cheia: a bancada só
// enche quando os 6 lugares estão ocupados.
//
// Escreva do zero (sem o pilha.h) uma struct Bancada com um vetor de 6 int e
// dois índices, e as funções empilha_limpo, empilha_sujo, desempilha_limpo e
// desempilha_sujo, todas devolvendo bool. Teste assim: empilhe os limpos 1, 2
// e 3; os sujos 10, 20 e 30; tente empilhar o limpo 4 (tem que falhar);
// desempilhe um sujo; empilhe o limpo 4 de novo; e esvazie as duas pilhas
// mostrando o que sai.
//
//   Saída esperada:
//   Limpo 4: bancada cheia
//   Saiu o sujo 30
//   Limpo 4: ok
//   Limpos: 4 3 2 1
//   Sujos: 20 10
//
// Dicas:
// 1. Use n_limpos (próxima vaga da esquerda, começa em 0) e topo_sujos
//    (começa em 6 e diminui antes de cada empilhamento sujo).
// 2. A bancada está cheia quando n_limpos == topo_sujos.
// 3. Desempilhar limpo: n_limpos > 0. Desempilhar sujo: topo_sujos < 6.
// 4. Resposta esperada: as cinco linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
