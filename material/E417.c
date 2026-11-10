// 0070 · Juntando tudo
// Exercício E417 · ★★☆
//
// Agenda em arquivo binário com cabeçalho. O arquivo /tmp/agenda.bin começa
// com um int com a quantidade de contatos, seguido dos contatos, registros de
// tamanho fixo (struct { char nome[8]; char telefone[16]; }). Escreva criar
// (grava só o cabeçalho, com 0), adicionar(nome, telefone) (abre com "rb+",
// lê a quantidade, vai até a vaga com fseek, grava o contato, soma 1 e regrava
// o cabeçalho) e listar (mostra a quantidade, o tamanho do arquivo e os
// contatos, nome com %-11s). Adicione Marta, Joel e Iara e liste.
//
//   Saída esperada:
//   3 contatos (arquivo de 76 bytes)
//   0. Marta       (11) 98888-1234
//   1. Joel        (21) 97777-4321
//   2. Iara        (31) 96666-0000
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
