// 0181 · Juntando tudo
// Exercício E1086 · ★★★
//
// O relatório do mês: quais pacientes mais vieram? As 20 consultas do mês
// estão num vetor de CPFs (simplificados em 3 dígitos): 711, 305, 711, 902,
// 118, 305, 711, 640, 902, 305, 118, 711, 555, 640, 305, 902, 711, 118, 999,
// 640. Sem o TAD, escreva: (1) uma tabela de dispersão dupla com m = 31
// (h1 = cpf % 31, h2 = 1 + cpf % 30; cpf 0 é posição livre) que conta as
// consultas de cada CPF e guarda em que ordem ele apareceu pela primeira
// vez; (2) um pigeonhole sort estável pela quantidade de consultas, da
// maior para a menor, sobre os pacientes na ordem em que apareceram.
//
//   Saída esperada:
//   7 pacientes diferentes em 20 consultas
//   cpf 711: 5 consultas
//   cpf 305: 4 consultas
//   cpf 902: 3 consultas
//   cpf 118: 3 consultas
//   cpf 640: 3 consultas
//   cpf 555: 1 consultas
//   cpf 999: 1 consultas
//
// Dicas:
// 1. Uma função posicao(t, cpf) que devolve a posição do CPF, ou a primeira
//    livre da sequência dele, serve para inserir e para contar.
// 2. Copie os registros para um vetor lista[ordem]: assim a entrada do
//    pigeonhole está na ordem de chegada, e os empates (902, 118, 640) saem
//    nessa ordem.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
