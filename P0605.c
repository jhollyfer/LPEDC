// Lista · Módulo 06 · Ponteiros
// Exercício P0605 · ★☆☆ · Troca de plantão
//
// O hospital guarda quem está de plantão em dois ponteiros para string:
//
//   const char *dia = "Dra. Socorro";
//   const char *noite = "Dr. Wanderley";
//
// Escreva void troca_plantao(const char **a, const char **b), que troca para
// onde os dois ponteiros apontam (as strings não mudam de lugar: só os
// ponteiros). Mostre a escala antes e depois e, para provar que nenhum texto
// foi copiado, mostre o endereço guardado em dia antes e o guardado em noite
// depois (são o mesmo):
//
//   Saída esperada (os endereços mudam a cada execução):
//   Antes:  dia = Dra. Socorro, noite = Dr. Wanderley
//   Depois: dia = Dr. Wanderley, noite = Dra. Socorro
//   dia antes:    0x55d0c3a01004
//   noite depois: 0x55d0c3a01004
//
// Dicas:
// 1. Para mudar um int do main, a função recebe int *. Para mudar um
//    const char * do main, ela recebe const char ** (o endereço do ponteiro).
// 2. Dentro: const char *aux = *a; *a = *b; *b = aux;
// 3. Na chamada: troca_plantao(&dia, &noite).
// 4. Mostre os endereços com %p e um cast para (void *).
// 5. Resposta esperada: a saída acima, com as duas últimas linhas iguais.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    const char *dia = "Dra. Socorro";
    const char *noite = "Dr. Wanderley";
    (void) dia, (void) noite; // apague esta linha quando escrever

    return 0;
}
