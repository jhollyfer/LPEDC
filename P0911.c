// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0911 · ★★☆ · Só os aprovados vão para o outro arquivo
//
// Grave em /tmp/p0911_turma.txt a turma do cursinho, uma pessoa por linha
// (nome e duas notas):
//
//   Ana 7.0 8.0
//   Beto 5.0 4.5
//   Caio 6.0 6.0
//   Dani 9.5 8.5
//   Edu 3.0 7.0
//
// Depois leia esse arquivo com fscanf e escreva em /tmp/p0911_aprovados.txt
// só quem tem média >= 6, no formato "nome média" (duas casas). Por fim,
// mostre o arquivo dos aprovados (lendo com fgets), quantos passaram e
// apague os dois arquivos.
//
//   Saída esperada:
//   Ana 7.50
//   Caio 6.00
//   Dani 9.00
//   Aprovados: 3 de 5
//
// Dicas:
// 1. Leia cada linha com fscanf(ent, "%19s %lf %lf", nome, &n1, &n2) e
//    pare quando o retorno for diferente de 3.
// 2. Deixe os dois arquivos abertos ao mesmo tempo: o da turma em "r" e o
//    dos aprovados em "w". Feche o de escrita antes de reabrir para ler.
// 3. Resposta esperada: Ana 7.50, Caio 6.00, Dani 9.00 e Aprovados: 3 de 5.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
