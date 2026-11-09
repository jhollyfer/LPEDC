// Lista · Módulo 02 · Decisões
// Exercício P0225 · ★★★ · Choque de horários na agenda
//
// A agenda precisa avisar quando dois compromissos se sobrepõem. Escreva um
// programa que leia o início e o fim de dois compromissos no formato hh:mm e
// mostre se há conflito e de quantos minutos. Encostar (um acaba às 10:00 e o
// outro começa às 10:00) não é conflito. Duas interações:
//
//   Saída esperada:
//   Compromisso 1 (início fim): 14:00 15:30
//   Compromisso 2 (início fim): 15:00 16:00
//   Conflito de 30 minutos
//
//   Compromisso 1 (início fim): 09:00 10:00
//   Compromisso 2 (início fim): 10:00 11:00
//   Sem conflito
//
// Dicas:
// 1. Leia com scanf("%d:%d %d:%d", ...) e passe tudo para minutos.
// 2. A sobreposição começa no maior dos inícios e termina no menor dos fins.
//    Use ternários para achar os dois.
// 3. Se fim_comum > inicio_comum, há conflito de (fim_comum - inicio_comum)
//    minutos.
// 4. Resposta esperada: 30 minutos no primeiro caso; sem conflito no segundo.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
