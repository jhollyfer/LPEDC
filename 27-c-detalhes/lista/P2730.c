// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2730 · ★★★ · O extrato do Pix
//
// Juntando tudo. Grave o extrato abaixo no arquivo p2730_pix.txt (dia;tipo;
// valor em centavos;flags), leia de volta para um vetor de structs e gere o
// relatório. O tipo é 'R' (recebido) ou 'E' (enviado) e vira um enum; as
// flags são bits: AGENDADO = 1u << 0 e CONTESTADO = 1u << 1.
//
//   1;R;250000;0
//   1;E;12000;0
//   2;E;8990;2
//   2;E;4500;0
//   3;R;3000;1
//   3;E;30000;0
//
// Descubra quantos dias o extrato tem (o maior dia lido) e crie dois VLAs,
// long saldo_dia[dias] e long gasto_dia[dias]. Mostre o saldo de cada dia,
// o saldo final, o dia de maior gasto e o total contestado.
//
//   Saída esperada:
//   dia 1: +2380.00
//   dia 2: -134.90
//   dia 3: -270.00
//   saldo final: R$ 1975.10
//   maior gasto: dia 3 (R$ 300.00)
//   contestadas: 1 (R$ 89.90)
//
// Dicas:
// 1. Leia cada linha com fscanf(f, "%d;%c;%ld;%u", ...) e confira que
//    devolveu 4.
// 2. Um switch sobre a letra escolhe o enum; o recebido soma e o enviado
//    subtrai.
// 3. Os VLAs só podem ser criados depois de saber dias, e não aceitam
//    = {0}: zere com um laço (ou memset).
// 4. Valores em centavos, num long: mostre reais com v / 100 e v % 100, ou
//    com v / 100.0 e %.2f.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
