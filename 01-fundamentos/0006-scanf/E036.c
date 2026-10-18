// 0006 · scanf
// Exercício E036 · ★★★
//
// Bancos de dados e APIs usam a data no formato ISO: aaaa-mm-dd. Leia uma
// data no formato brasileiro e mostre no ISO, sempre com mês e dia de dois
// dígitos. O programa precisa aceitar qualquer separador: 7/9/2026,
// 7-9-2026 e 7.9.2026 dão o mesmo resultado.
//
//   Exemplo de execução:
//   Data: 7/9/2026
//   ISO: 2026-09-07
//
// Dicas:
// 1. Para mostrar: %04d-%02d-%02d.
// 2. O %*c lê um caractere e joga fora, sem guardar em variável nenhuma (e
//    sem contar no retorno). Serve para "qualquer separador".
// 3. Resposta esperada: scanf("%d%*c%d%*c%d", &dia, &mes, &ano); e a saída
//    "ISO: 2026-09-07" para as três entradas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
