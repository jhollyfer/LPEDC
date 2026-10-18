// 0002 · Variáveis
// Exercício E009 · ★★☆
//
// O cadastro de um aluno da autoescola guarda: idade (int, 19), nota da
// prova teórica (double, 8.5), nota da prova prática (double, 9.0),
// categoria da CNH (char, 'B') e número de aulas feitas (int, 20). Declare
// as cinco variáveis e mostre os valores e o sizeof de cada uma, uma por
// linha. Depois, mostre mais duas linhas, calculadas pelo programa: o total
// de bytes das cinco variáveis (somando os sizeof) e quanto seria o total
// se as duas notas fossem float (use sizeof(float) no lugar delas).
//
//   Saída esperada:
//   idade: 19 (4 bytes)
//   teorica: 8.5 (8 bytes)
//   pratica: 9.0 (8 bytes)
//   categoria: B (1 byte)
//   aulas: 20 (4 bytes)
//   total: 25 bytes
//   com float nas notas: 17 bytes
//
// Dicas:
// 1. sizeof nome_da_variavel e %zu no printf.
// 2. O sizeof pode entrar numa soma, direto no printf:
//    sizeof idade + sizeof teorica + ...
// 3. Resposta esperada: as sete linhas acima (4 + 8 + 8 + 1 + 4 = 25 e
//    4 + 4 + 4 + 1 + 4 = 17). Na memória pode haver folgas entre as
//    variáveis, mas o total de dados é esse.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
