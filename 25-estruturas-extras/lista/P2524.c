// Lista · Módulo 25 · Estruturas especiais
// Exercício P2524 · ★★★ · Desfazer o mover para a frente
//
// O codificador "mover para a frente" troca cada letra pela posição dela
// num alfabeto que se reorganiza (a letra usada vai para a frente). Quem
// recebe os números consegue voltar ao texto? Sim: começa com o MESMO
// alfabeto e repete o MESMO movimento. Escreva do zero:
// - decodifica(cod, n, saida): para cada número p, a letra é alf[p], e ela
//   vai para a frente;
// - codifica(texto, saida), para conferir a ida.
// Decodifique a mensagem recebida, codifique o resultado e confira se dá
// os mesmos números. Por fim, codifique "aaaabbbbaaaabbbb".
//
//   Recebido: 1 1 13 1 1 1 2 1 2 1 1 1
//
//   Saída esperada:
//   Mensagem: bananabanana
//   Codificando de novo: mesmos números
//   Números menores que 3: 11 de 12
//   aaaabbbbaaaabbbb -> 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0
//
// Dicas:
// 1. Comece com char alf[27] = "abcdefghijklmnopqrstuvwxyz" nas duas
//    funções. Levar para a frente: desloque alf[0..p-1] uma casa e
//    ponha a letra em alf[0].
// 2. Os dois lados ficam com o alfabeto igual depois de cada letra: por
//    isso a volta funciona sem mandar o alfabeto junto.
// 3. Resposta esperada: a mensagem é bananabanana; o último texto vira
//    quase só zeros, com um 1 em cada troca de letra.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

int main(void) {

    return 0;
}
