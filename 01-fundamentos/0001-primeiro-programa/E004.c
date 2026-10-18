// 0001 · O primeiro programa
// Exercício E004 · ★★☆
//
// O aviso do cinema foi escrito com pressa: quase tudo numa linha só, sem
// recuo, e com um comentário no lugar errado. Ele compila sem aviso, mas
// mostra só duas das três linhas. Reorganize o código: uma instrução por
// linha, recuo de 4 espaços dentro da main, um comentário de bloco no topo
// dizendo o que o programa faz, e o comentário "sala 2" num lugar onde não
// engula nada. Rode e confira as três linhas.
//
//   Saída esperada:
//   Cine Estação
//   Sessão: 19h30 (sala 2)
//   Ingresso: R$ 28,00
//
// Dicas:
// 1. O // desliga tudo o que vem depois dele, até o fim da LINHA, e não até
//    o próximo ;.
// 2. O texto "(sala 2)" tem de ir para dentro das aspas do segundo printf.
// 3. Resposta esperada: três printf, cada um na sua linha, e as três linhas
//    acima. O comentário // pode ficar no fim de uma linha, depois do ;.
//
// Escreva sua resposta abaixo (reorganize o código):

#include <stdio.h>
int main(void){printf("Cine Estação\n");printf("Sessão: 19h30\n"); // sala 2 printf("Ingresso: R$ 28,00\n");
return 0;}
