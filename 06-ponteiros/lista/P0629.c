// Lista · Módulo 06 · Ponteiros
// Exercício P0629 · ★★★ · Embaralhar qualquer vetor
//
// O app do bingo da igreja precisa embaralhar vetores de vários tipos, e o
// resultado tem que ser repetível para a auditoria. Escreva:
//
//   unsigned sorteio(unsigned *semente, unsigned n);
//   void embaralhar(void *v, size_t n, size_t tam, unsigned *semente);
//
// sorteio atualiza a semente com *semente = *semente * 1103515245u + 12345u
// e devolve (*semente / 65536) % n (um número de 0 a n - 1). embaralhar usa o
// algoritmo de Fisher-Yates: para i de n - 1 até 1, sorteia j entre 0 e i
// e troca o elemento i com o j, byte a byte. Com a semente 2026, embaralhe
// as 10 bolas e depois, com a mesma semente continuando, os 4 nomes:
//
//   int bolas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   char nomes[4][12] = {"Dona Lia", "Seu Ze", "Rita", "Padre Joao"};
//
//   Saída esperada:
//   Bolas: 3 2 8 6 1 10 5 4 7 9
//   Ordem de chamada: Seu Ze, Dona Lia, Padre Joao, Rita
//   Semente final: 3469224078
//
// Dicas:
// 1. A conta usa unsigned: quando passa do maior valor, ela "dá a volta"
//    (módulo 2³²) sem comportamento indefinido. Com int, estourar é erro.
// 2. O elemento i começa em (unsigned char *) v + i * tam. Escreva uma
//    troca_bytes(void *a, void *b, size_t tam) como no P0622.
// 3. j = sorteio(semente, i + 1) sorteia de 0 a i. Pule a troca se j == i.
// 4. A semente é passada por ponteiro para que a segunda chamada continue
//    a sequência da primeira.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int bolas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char nomes[4][12] = {"Dona Lia", "Seu Ze", "Rita", "Padre Joao"};
    (void) bolas, (void) nomes; // apague esta linha quando escrever

    return 0;
}
