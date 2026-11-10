// Lista · Módulo 04 · Funções e modularização
// Exercício P0428 · ★★★ · O cheque por extenso
//
// O cheque precisa do valor por extenso. Escreva "void extenso(int n)", para
// números de 0 a 999999, dividida em funções menores: uma para as unidades,
// uma para 10 a 19, uma para as dezenas, uma para "até 99" e outra para "até
// 999". Cuidado com as regras do português: 100 é "cem", mas 101 é "cento e
// um"; 1000 é "mil", não "um mil"; e entre o milhar e o resto vai " e " quando
// o resto é menor que 100 ou é uma centena redonda (2026, 2100), e só espaço
// nos outros casos (2150). Teste com estes valores:
//
//   Saída esperada:
//   0: zero
//   15: quinze
//   100: cem
//   101: cento e um
//   1000: mil
//   2026: dois mil e vinte e seis
//   2100: dois mil e cem
//   2150: dois mil cento e cinquenta
//   123456: cento e vinte e três mil quatrocentos e cinquenta e seis
//   999999: novecentos e noventa e nove mil novecentos e noventa e nove
//
// Dicas:
// 1. Cada função de nomes é um switch que só faz printf("um"), printf("dois")...
// 2. ate_99(n): se n < 10, unidade; se n < 20, de 10 a 19; senão, a dezena
//    e, se n % 10 > 0, " e " e a unidade.
// 3. ate_999(n): se n == 100, "cem"; senão a centena (cento, duzentos...) e,
//    se sobrar algo, " e " e ate_99 do resto.
// 4. extenso(n): milhar = n / 1000 e resto = n % 1000; milhar 1 é só "mil".
// 5. Resposta esperada: as dez linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
