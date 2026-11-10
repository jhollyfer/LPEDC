// Lista · Módulo 14 · Árvores
// Exercício P1430 · ★★★ · O heapsort que embaralhava os empates
//
// O resultado da corrida de rua precisa sair por tempo e, no empate, pela
// ordem de inscrição (o número de peito). Os inscritos, em ordem:
//
//   #101 42 min, #102 38, #103 42, #104 35, #105 38, #106 42, #107 35
//
//   typedef struct { int numero; int tempo; int ordem; } Corredor;
//
// Escreva um heapsort de Corredor (heap de máximo, fase 1 com BUILD e fase 2
// trocando a raiz com o fim). Toda comparação passa por
// int maior(const Corredor *a, const Corredor *b). Com a global usa_ordem = 0,
// maior compara só o tempo; com usa_ordem = 1, desempata pelo campo ordem.
// Ordene duas cópias, uma de cada jeito, e mostre as duas.
//
//   Saída esperada:
//   só o tempo  : #104(35) #107(35) #102(38) #105(38) #106(42) #103(42) #101(42)
//   tempo, ordem: #104(35) #107(35) #102(38) #105(38) #101(42) #103(42) #106(42)
//
// Dicas:
// 1. O heapsort NÃO é estável: a troca da raiz com o fim joga elementos para
//    longe, por cima dos iguais. Os três de 42 minutos mostram o efeito.
// 2. Com o desempate pelo campo ordem, não existem mais chaves iguais, e a
//    estabilidade deixa de importar. É o mesmo truque que se usa com o qsort.
// 3. Use printf(" #%d(%d)", ...) para cada corredor.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int numero;
    int tempo;
    int ordem;
} Corredor;

int usa_ordem;

int main(void) {

    return 0;
}
