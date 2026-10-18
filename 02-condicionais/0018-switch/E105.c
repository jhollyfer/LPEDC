// 0018 · switch, case, break e fall-through
// Exercício E105 · ★★☆
//
// O atendimento por telefone do banco tem um menu de teclas: 1 → "Consultar
// saldo."; 2 → "Segunda via da fatura."; 9 → "Transferindo para um
// atendente..."; 0 → "Repetindo o menu.". Qualquer outra tecla mostra
// "Opção inválida." e, em seguida, também repete o menu. Escreva com UM
// switch em que o default fica no meio, logo antes do case 0, e cai nele
// de propósito (sem repetir o printf do menu).
//
//   Tecla: 7
//   Opção inválida.
//   Repetindo o menu.
//
// Dicas:
// 1. O default não precisa ser o último: o switch pula para ele quando
//    nenhum case bate, esteja onde estiver.
// 2. Ordem dos rótulos: case 1, case 2, case 9, default, case 0. Todos com
//    break, menos o default; no lugar do break dele, escreva o comentário
//    "// fall through" (o gcc entende e não avisa).
// 3. Resposta esperada: 1 → "Consultar saldo."; 2 → "Segunda via da
//    fatura."; 9 → "Transferindo para um atendente..."; 0 → só "Repetindo
//    o menu."; 7 → "Opção inválida." e "Repetindo o menu.".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
