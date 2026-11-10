// 0181 · Juntando tudo
// Exercício E1084 · ★★☆
//
// Escreva remarca(a, cpf, novo), que muda a consulta do paciente para o
// horário novo (agenda.h). Ela recusa (devolve false) se o paciente não tem
// consulta ou se o horário novo já está ocupado (confira com ag_intervalo(a,
// novo, novo, ...)). Senão, desmarca o antigo com ag_cancela (se alguém da
// espera assumir, mostre quem) e marca o novo. Teste: Zeca (601000001) às
// 09:00, Alice (601000002) às 10:00 e Breno (601000003) na espera; remarque
// o Zeca para 10:00 e depois para 11:00.
//
//   Saída esperada:
//   Zeca para 10:00: recusado
//   Zeca para 11:00:
//     Breno assume as 09:00
//     ok
//   09:00  Breno
//   10:00  Alice
//   11:00  Zeca
//   Espera: (ninguém)
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "0181-agenda.h"

int main(void) {

    return 0;
}
