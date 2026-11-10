// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1015 · ★★☆ · O TAD Data e a contagem para a prova
//
// Escreva um TAD Data, num arquivo só ("data.h", "data.c" e cliente), com o
// invariante "a data guardada sempre existe no calendário" (ano bissexto:
// divisível por 4 e não por 100, ou divisível por 400). Operações:
//
//   Data *data_cria(int dia, int mes, int ano);   // NULL se a data não existe
//   Data *data_seguinte(const Data *d);           // o dia seguinte (nova Data)
//   int data_compara(const Data *a, const Data *b);  // < 0, 0 ou > 0
//   int data_dias_entre(const Data *a, const Data *b); // a <= b
//   void data_imprime(const Data *d);             // dd/mm/aaaa
//   void data_libera(Data *d);
//
// No cliente, mostre o dia seguinte de 28/02/2024, 28/02/2025 e
// 31/12/2026, tente criar 30/02/2025 e conte os dias do fim das
// inscrições do PPGI (09/11/2026) até a prova (27/11/2026).
//
//   Saída esperada:
//   Depois de 28/02/2024 vem 29/02/2024
//   Depois de 28/02/2025 vem 01/03/2025
//   Depois de 31/12/2026 vem 01/01/2027
//   30/02/2025: data inválida
//   De 09/11/2026 até 27/11/2026: 18 dias
//
// Dicas:
// 1. Uma função static int dias_no_mes(int mes, int ano) resolve a validação
//    e o dia seguinte.
// 2. data_dias_entre pode andar de dia em dia com data_seguinte até chegar
//    em b (O(dias)). Libere cada Data intermediária.
// 3. data_compara: compare ano, depois mês, depois dia.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
