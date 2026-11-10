// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2911 · ★★☆ · Circuito com ruas paralelas
//
// O mapa da varrição tem cinco esquinas (0 a 4) e sete ruas, numeradas na
// ordem da lista; entre 0 e 1 há duas ruas paralelas, e entre 2 e 4 também:
//
//   r0: 0-1   r1: 1-0   r2: 1-2   r3: 2-3   r4: 3-1   r5: 2-4   r6: 4-2
//
// A matriz 0/1 não guarda ruas paralelas, então trabalhe com a lista e um
// vetor bool usada[7]. Escreva o Hierholzer com pilha: no topo u, pegue a
// rua livre de MENOR número que toca u, marque-a e empilhe a outra ponta.
// Mostre o circuito (esquinas) e a ordem das ruas usadas.
//
//   Saída esperada:
//   Circuito: 0 1 2 4 2 3 1 0
//   Ruas: r0 r2 r5 r6 r3 r4 r1
//
// Dicas:
// 1. Empilhe pares (esquina, rua pela qual chegou). Ao desempilhar, guarde a
//    esquina e a rua: lidos de trás para frente, são o circuito e as ruas.
// 2. A outra ponta da rua k a partir de u é rua[k][0] + rua[k][1] - u.
// 3. Resposta esperada: a saída acima. Todos os graus são pares (2, 4, 4, 2,
//    2), então o circuito existe.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
