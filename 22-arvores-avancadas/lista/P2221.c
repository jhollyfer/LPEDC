// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2221 · ★★★ · A rubro-negra que se fiscaliza
//
// Escreva do zero uma rubro-negra esquerdista completa (inserção com
// rot_esq, rot_dir e inverte) e um fiscal que confere as três regras da
// LLRB: (1) nenhum link vermelho à direita; (2) nunca dois links vermelhos
// seguidos (um vermelho com filho esquerdo vermelho); (3) todo caminho da
// raiz até um NULL tem o mesmo número de links pretos. Insira 1000 senhas
// de atendimento geradas por s = (s * 41 + 11) % 1000, começando em s = 0
// (essa fórmula passa por todos os números de 0 a 999), e, a cada 200
// inserções, rode o fiscal e mostre a altura (em nós) e a altura preta.
// Compare com 2 lg(n + 1), o limite do Cormen.
//
//   Saída esperada:
//   n =  200: aprovada, altura 10, altura preta 6, limite 15.3
//   n =  400: aprovada, altura 12, altura preta 7, limite 17.3
//   n =  600: aprovada, altura 13, altura preta 8, limite 18.5
//   n =  800: aprovada, altura 13, altura preta 8, limite 19.3
//   n = 1000: aprovada, altura 13, altura preta 8, limite 19.9
//
// Dicas:
// 1. O fiscal pode ser uma função que devolve a altura preta ou -1, com
//    as regras 1 e 2 testadas em cada nó antes de descer.
// 2. lg vem de <math.h>: log2(n + 1.0). Altura em nós: NULL vale 0.
// 3. Resposta esperada: o fiscal aprova todas as vezes, e a altura fica
//    bem abaixo do limite (veja os números).
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
