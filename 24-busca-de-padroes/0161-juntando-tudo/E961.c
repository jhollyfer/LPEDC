// 0161 · Juntando tudo
// Exercício E961 · ★☆☆
//
// Use o TAD padroes.h (ele já está na pasta e o rodar compila junto). Conte
// quantas vezes "pix" aparece no extrato abaixo com os QUATRO algoritmos,
// mostre as comparações de cada um e confira se todos acharam o mesmo total:
//
//   "pix recebido; pix enviado; boleto pago; pix agendado; tarifa pix"
//
//   Saída esperada:
//   4 ocorrências,  71 comparações: força bruta
//   4 ocorrências,  65 comparações: KMP
//   4 ocorrências,  31 comparações: Horspool
//   4 ocorrências,  12 comparações: Rabin-Karp
//   os quatro concordam
//
// Dicas:
// 1. As quatro funções têm a mesma assinatura (o tipo Busca de padroes.h).
//    Guarde-as num vetor: Busca buscas[] = {pb_forca_bruta, pb_kmp, ...}.
// 2. As funções SOMAM em *comparacoes: zere o contador antes de cada uma.
//    Se só quer contar, passe NULL e 0 no lugar de pos e max.
// 3. O Rabin-Karp parece imbatível, mas só conta as comparações de letra da
//    conferência: as duas contas do hash por janela não entram no número.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include "padroes.h"

int main(void) {

    return 0;
}
