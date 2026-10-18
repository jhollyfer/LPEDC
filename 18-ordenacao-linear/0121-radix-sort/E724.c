// 0121 · Radix sort
// Exercício E724 · ★★☆
//
// O radix sort não precisa de dígitos: qualquer chave formada por "casas"
// serve. Uma data tem três casas: dia, mês e ano, do menos para o mais
// importante. Ordene os vencimentos dos boletos em ordem cronológica com
// três passadas de counting sort estável: primeiro pelo dia, depois pelo
// mês, por fim pelo ano. Mostre o vetor depois de cada passada.
//
//   Saída esperada:
//   início: 15/03/2025 05/11/2024 15/01/2025 28/02/2024 05/03/2025 10/11/2024 28/01/2025
//   dia:    05/11/2024 05/03/2025 10/11/2024 15/03/2025 15/01/2025 28/02/2024 28/01/2025
//   mês:    15/01/2025 28/01/2025 28/02/2024 05/03/2025 15/03/2025 05/11/2024 10/11/2024
//   ano:    28/02/2024 05/11/2024 10/11/2024 15/01/2025 28/01/2025 05/03/2025 15/03/2025
//
// Dicas:
// 1. Escreva int chave(Data d, int campo): campo 0 devolve o dia, 1 o mês e
//    2 o ano - 2020 (os anos vão de 2020 a 2029). Assim, uma passada só
//    serve para os três campos.
// 2. Com 32 contadores, cabem os dias (1 a 31), os meses e os anos.
// 3. Formato de cada data: " %02d/%02d/%d".
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

int main(void) {
    Data boletos[] = {{15, 3, 2025}, {5, 11, 2024}, {15, 1, 2025}, {28, 2, 2024},
                      {5, 3, 2025}, {10, 11, 2024}, {28, 1, 2025}};
    (void) boletos; // apague esta linha

    return 0;
}
