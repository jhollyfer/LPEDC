// Lista · Módulo 08 · Tipos compostos
// Exercício P0809 · ★☆☆ · O mais velho da família
//
// Crie typedef struct { int dia, mes, ano; } Data; e typedef struct { char
// nome[20]; Data nascimento; } Pessoa; (uma struct dentro da outra). Escreva
// int compara_data(Data a, Data b), que devolve negativo se a vem antes de
// b, 0 se são iguais e positivo se a vem depois. Com a família abaixo,
// mostre o mais velho, o mais novo e quem faz aniversário em março:
//
//   Pessoa familia[5] = {{"Vó Nazaré", {12, 3, 1941}},
//                        {"Tio Edu", {30, 11, 1968}},
//                        {"Mãe", {5, 3, 1972}},
//                        {"Lucas", {19, 7, 2001}},
//                        {"Bia", {2, 1, 2009}}};
//
//   Saída esperada:
//   Mais velho: Vó Nazaré (1941)
//   Mais novo: Bia (2009)
//   Aniversário em março: Vó Nazaré (dia 12) Mãe (dia 5)
//
// Dicas:
// 1. Compare o ano; se for igual, o mês; se for igual, o dia:
//    if (a.ano != b.ano) return a.ano - b.ano; ...
// 2. O mais velho nasceu ANTES: é o de menor data.
// 3. Para chegar no mês: familia[i].nascimento.mes (dois pontos seguidos).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
