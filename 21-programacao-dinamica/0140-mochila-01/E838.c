// 0140 · Mochila 0/1
// Exercício E838 · ★★☆
//
// Sua carteira tem estas cédulas: 2, 5, 5, 10, 10, 20, 20 e 50 reais. Você
// precisa separar exatamente R$ 30 para o rateio do churrasco. De quantos
// jeitos dá para escolher as cédulas? Cada cédula é um papel diferente: as
// duas notas de 20 contam como escolhas distintas.
//
// Resolva com PD num vetor só (jeitos[s] = quantos subconjuntos das cédulas
// vistas até agora somam s) e confira o resultado com a força bruta por bits
// do assunto 0125, testando os 2^8 subconjuntos.
//
//   Saída esperada:
//   PD: 7 jeitos de separar R$ 30
//   força bruta: 7 jeitos (256 subconjuntos testados)
//
// Dicas:
// 1. jeitos[0] = 1 (o subconjunto vazio soma 0); o resto começa em 0.
// 2. Para cada cédula, percorra s de 30 DESCENDO até o valor dela e faça
//    jeitos[s] += jeitos[s - cedula]. Subindo, a mesma cédula seria usada
//    duas vezes.
// 3. Na força bruta, o bit i da máscara diz se a cédula i entra.
// 4. Resposta esperada: a saída acima (20 + 10 de 4 jeitos, 20 + 5 + 5 de 2
//    jeitos e 10 + 10 + 5 + 5 de 1).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
