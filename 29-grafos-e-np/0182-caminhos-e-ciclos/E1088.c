// 0182 · Caminhos e ciclos
// Exercício E1088 · ★☆☆
//
// Use o bairro do texto (G Garagem, P Praça, F Feira, E Escola, I Igreja,
// S Posto) com as ruas G-P, G-F, P-F, P-E, P-S, F-I, F-S, E-I. Escreva a
// função const char *classifica(const char *seq), que recebe uma sequência
// de letras e devolve o nome mais preciso da tabela do texto:
// "não é passeio" (falta alguma rua), "passeio" ou "passeio fechado" (repete
// rua), "trajeto" ou "circuito" (não repete rua, repete esquina), "caminho"
// ou "ciclo" (não repete nada). Teste com estas seis sequências:
//
//   Saída esperada:
//   GPFG      ciclo
//   GPEIFPS   trajeto
//   GPFPS     passeio
//   PEIF      caminho
//   GPFIEPSFG circuito
//   GE        não é passeio
//
// Dicas:
// 1. Converta cada letra para o índice e confira se cada par vizinho tem
//    rua. A sequência é fechada quando a primeira letra é igual à última.
// 2. Rua repetida: os pares (s[i], s[i+1]) e (s[j], s[j+1]) são a mesma rua
//    se forem iguais em qualquer ordem. Esquina repetida: compare as letras,
//    mas no fechado não conte a última (ela é a primeira de novo).
// 3. Resposta esperada: a saída acima. GPFIEPSFG é o circuito do texto: a
//    Praça e a Feira aparecem duas vezes, mas nenhuma rua.
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
