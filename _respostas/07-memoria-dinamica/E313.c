// 0053 · Pilha e heap
// Exercício E313 · ★☆☆
//
// Resposta:
// a) recorde: dados (global)
// b) chamadas: dados (static dentro de função não fica no frame)
// c) jogos: pilha (parâmetro é uma local que já nasce com valor)
// d) gols: pilha
// e) o ponteiro placar: pilha (são 8 bytes no frame de ler_placar)
// f) o bloco apontado por placar: heap
// g) as instruções de ler_placar: código
//
// Depois do return continuam vivos: recorde, chamadas, o bloco do heap e o
// código. jogos, gols e o ponteiro placar somem com o frame. Por isso a
// função devolve o endereço: sem ele, ninguém mais acharia o bloco (e ele
// vazaria).

#include <stdio.h>

int main(void) {
    return 0;
}
