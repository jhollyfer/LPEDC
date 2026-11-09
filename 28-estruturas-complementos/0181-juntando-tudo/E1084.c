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
// Dicas:
// 1. A ordem importa: ag_marca recusa paciente que já tem consulta, então
//    primeiro ag_cancela, depois ag_marca.
// 2. ag_cancela devolve o cpf de quem assumiu (maior que 0) ou 0.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>
#include "agenda.h"

int main(void) {

    return 0;
}
