// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2821 · ★★★ · A rubro-negra do Cormen, do zero
//
// Escreva a rubro-negra clássica com a sentinela nil (um nó preto global que
// faz o papel de toda folha e do pai da raiz): rotações à esquerda e à
// direita que acertam o pai, inserção como na BST com o nó novo vermelho e o
// conserto com os três casos do tio (e os espelhos). Conte quantas vezes
// cada caso rodou. Insira 30, 15, 60, 10, 20, 50, 70, 5, 1, 55, 65, 80 e 90
// e mostre a pré-ordem (vermelhos com *), as contagens, a altura negra e o
// resultado de um fiscal das propriedades 4 e 5.
//
//   Saída esperada:
//   pré: 30 15 5 1* 10* 20 60 50 55* 70* 65 80 90*
//   caso 1: 5 | caso 2: 0 | caso 3: 1
//   altura negra: 3 | fiscal: ok
//
// Dicas:
// 1. Caso 1: tio vermelho, recolore pai, tio e avô e faz z = avô. Caso 2:
//    tio preto e z em triângulo, z = pai e gira. Caso 3: tio preto e z em
//    linha, recolore e gira no avô.
// 2. Com a sentinela, o tio pode ser nil (preto) sem nenhum teste de NULL.
// 3. A altura negra pode ser contada descendo sempre pela esquerda.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
