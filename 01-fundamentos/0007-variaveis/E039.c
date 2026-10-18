// 0007 · Variáveis
// Exercício E039 · ★★☆
//
// O cadastro de um aluno da autoescola guarda: idade (int, 19), nota da
// prova teórica (double, 8.5), nota da prova prática (double, 9.0),
// categoria da CNH (char, 'B') e número de aulas feitas (int, 20). Declare as cinco variáveis e
// mostre os valores e o sizeof de cada uma, uma por linha, no formato:
//
//   Saída esperada:
//   idade: 19 (4 bytes)
//   teorica: 8.5 (8 bytes)
//   pratica: 9.0 (8 bytes)
//   categoria: B (1 byte)
//   aulas: 20 (4 bytes)
//
// Depois responda, sem rodar: quantos bytes as cinco variáveis ocupam
// juntas? Se você trocasse as duas notas para float, quanto economizaria?
//
// Dicas:
// 1. sizeof nome_da_variavel e %zu no printf.
// 2. Some os tamanhos: 4 + 8 + 8 + 1 + 4.
// 3. Resposta esperada: as cinco linhas acima; juntas ocupam 25 bytes; com
//    float nas notas seriam 17 bytes (8 a menos). Na memória pode haver
//    folgas entre as variáveis, mas o total de dados é esse.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
