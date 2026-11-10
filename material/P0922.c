// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0922 · ★★★ · O banquinho do bairro processa o dia
//
// O banco comunitário guarda as contas em binário e recebe as operações do
// dia num arquivo texto. Escreva um programa que:
//
// 1. grave em /tmp/p0922_contas.bin as contas 101 Ana R$ 500.00,
//    102 Beto R$ 120.00 e 103 Caio R$ 0.00;
// 2. grave em /tmp/p0922_dia.txt as operações, uma por linha:
//
//   D 103 250.00
//   S 102 200.00
//   S 101 80.50
//   T 101 103 100.00
//   S 104 10.00
//
//    (D = depósito, S = saque, T = transferência da 1ª conta para a 2ª);
// 3. leia as operações com fscanf e aplique cada uma DIRETO no arquivo de
//    contas (abra com "rb+", ache o registro, altere e regrave). Saque ou
//    transferência sem saldo é recusado; conta que não existe também;
// 4. mostre o resultado de cada operação e os saldos finais, e apague os
//    dois arquivos.
//
//   Saída esperada:
//   D 103 250.00: ok
//   S 102 200.00: saldo insuficiente
//   S 101 80.50: ok
//   T 101 103 100.00: ok
//   S 104 10.00: conta inexistente
//   101 Ana    R$  319.50
//   102 Beto   R$  120.00
//   103 Caio   R$  350.00
//
// Dicas:
// 1. Escreva long acha(FILE *arq, int numero, Conta *c), que percorre o
//    arquivo e devolve a posição do registro (ou -1), e
//    void regrava(FILE *arq, long pos, const Conta *c).
// 2. Leia o tipo com fscanf(op, " %c %d", &tipo, &num): o espaço antes do
//    %c pula o '\n' da linha anterior. Na transferência, leia mais um %d.
// 3. Numa transferência, confira as duas contas e o saldo ANTES de mexer em
//    qualquer uma: ou as duas mudam, ou nenhuma.
// 4. Resposta esperada: a saída acima (Ana: 500 - 80.50 - 100 = 319.50).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    int numero;
    char titular[16];
    double saldo;
} Conta;

int main(void) {

    return 0;
}
