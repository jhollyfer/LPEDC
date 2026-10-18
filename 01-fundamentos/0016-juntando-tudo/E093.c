// 0016 · Juntando tudo
// Exercício E093 · ★★☆
//
// Quanto tempo leva para baixar um jogo? Leia o tamanho em GB e a
// velocidade da internet em Mbps (megabits por segundo) e mostre o tempo em
// minutos e segundos. Atenção às unidades: 1 GB = 1000 MB, 1 byte = 8 bits.
//
//   Exemplo de execução:
//   Tamanho (GB): 4.7
//   Internet (Mbps): 100
//   Tempo: 376 s = 6 min 16 s
//
// Teste: printf '4.7\n100\n' | ~/LPEDC/rodar E093.c
//
// Dicas:
// 1. Megabits do arquivo = GB * 1000 * 8. Segundos = megabits / Mbps.
// 2. Passe os segundos para int (round e depois cast) antes de usar / e %.
// 3. Resposta esperada: 4.7 * 1000 * 8 = 37600 megabits; / 100 = 376 s;
//    376 / 60 = 6 min, 376 % 60 = 16 s.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
