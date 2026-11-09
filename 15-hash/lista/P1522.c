// Lista · Módulo 15 · Tabelas hash
// Exercício P1522 · ★★★ · Quando as lápides tomam conta
//
// A lápide resolve a remoção no endereçamento aberto, mas cobra um preço: a
// busca SEM sucesso só para no VAZIO, então as lápides deixam as buscas tão
// caras quanto se as chaves ainda estivessem lá. Meça isso.
//
// Tabela global int t[11] (VAZIO = -1, LAPIDE = -2), sondagem linear,
// h(k) = k % 11. Escreva busca(k, &sondagens), insere(k) (não duplica,
// reaproveita lápide), remove_chave(k) (marca lápide), reconstroi() (tira as
// chaves vivas, limpa a tabela e reinsere só elas) e relatorio(quando), que
// mostra a tabela (_ vazio, X lápide), as vivas, as lápides e a média de
// sondagens de 11 buscas sem sucesso, uma começando em cada posição (use as
// chaves 1100 a 1110: 1100 + h começa em h). Use printf("%-11s", quando).
//
// Insira 22, 34, 46, 58, 13, 70, 81, 92; remova 22, 46, 13, 81, 92;
// reconstrua.
//
//   Saída esperada:
//   cheia:      22 34 46 58 13 70 81 92 _ _ _
//     vivas 8, lápides 0, busca sem sucesso: 4.27 sondagens
//   removidas:  X 34 X 58 X 70 X X _ _ _
//     vivas 3, lápides 5, busca sem sucesso: 4.27 sondagens
//   refeita:    _ 34 _ 58 70 _ _ _ _ _ _
//     vivas 3, lápides 0, busca sem sucesso: 1.36 sondagens
//
// Dicas:
// 1. Uma sondagem é cada posição olhada, inclusive o VAZIO que encerra.
// 2. Depois das remoções, a tabela tem 3 chaves, mas as buscas custam o
//    mesmo que com 8: a lápide conta como ocupada para quem procura.
// 3. Na reconstrução, o 70 (h = 4) sai da posição 5 e volta para a 4.
// 4. Por isso bibliotecas reconstroem a tabela quando vivas + lápides passam
//    de um limite, e não só quando as vivas passam.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define M 11
#define VAZIO -1
#define LAPIDE -2

int t[M];

int main(void) {

    return 0;
}
