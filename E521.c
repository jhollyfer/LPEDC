// 0087 · Deque
// Exercício E521 · ★★★
//
// O deque também pode ser feito com nós, mas com lista DUPLA: para retirar do
// fim, o último nó precisa conhecer o penúltimo (o ant). Com os tipos abaixo,
// escreva dl_insere_inicio, dl_insere_fim, dl_retira_inicio, dl_retira_fim (todas
// bool, as retiradas devolvem o valor por ponteiro e liberam o nó) e void
// dl_libera(DequeLista *d). No main, simule a fila de músicas: insira no fim as
// faixas 5, 8 e 3 e no início a 11; toque (retire do início) uma, remova (retire
// do fim) uma e mostre as que sobraram.
//
//   Saída esperada:
//   Tocando a faixa 11
//   Removida a faixa 3
//   Ainda na fila: 5 8
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int valor;
    struct nod *ant;
    struct nod *prox;
} NoD;

typedef struct {
    NoD *inicio;
    NoD *fim;
} DequeLista;

int main(void) {

    return 0;
}
