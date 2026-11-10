// 0121 · Radix sort
// Exercício E724 · ★★☆
//
// O radix sort não precisa de dígitos: qualquer chave formada por "casas"
// serve. Uma data tem três casas: dia, mês e ano, do menos para o mais
// importante. Ordene os vencimentos dos boletos em ordem cronológica com
// três passadas de counting sort estável: primeiro pelo dia, depois pelo
// mês, por fim pelo ano. Mostre o vetor depois de cada passada.
//
//   Vencimentos (dia/mês/ano): 15/03/2025 05/11/2024 15/01/2025 28/02/2024
//   05/03/2025 10/11/2024 28/01/2025
//
//   Saída esperada:
//   início: 15/03/2025 05/11/2024 15/01/2025 28/02/2024 05/03/2025 10/11/2024 28/01/2025
//   dia:    05/11/2024 05/03/2025 10/11/2024 15/03/2025 15/01/2025 28/02/2024 28/01/2025
//   mês:    15/01/2025 28/01/2025 28/02/2024 05/03/2025 15/03/2025 05/11/2024 10/11/2024
//   ano:    28/02/2024 05/11/2024 10/11/2024 15/01/2025 28/01/2025 05/03/2025 15/03/2025
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int dia, mes, ano;
} Data;

int main(void) {

    return 0;
}
