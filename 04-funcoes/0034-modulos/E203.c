// 0034 · Módulos: .h, .c e compilação separada
// Exercício E203 · ★★★
//
// Escreva o módulo "placar" de um campeonato entre dois times, num arquivo
// só, com os blocos "// placar.h", "// main.c" e "// placar.c". Os dados
// moram em globais static no bloco do placar.c: os gols da partida atual de
// cada time e os pontos e gols de cada um no campeonato. Ninguém de fora mexe
// neles sem passar pelas funções:
//
//   void marcar_gol(int time)      time 1 (casa) ou 2 (visitante)
//   void encerrar_partida(void)    mostra "Partida N: X x Y", dá 3 pontos
//                                  para quem venceu (1 para cada no empate),
//                                  soma os gols no campeonato e zera o placar
//   int pontos(int time)
//   int gols(int time)             gols no campeonato
//
// Uma função static do placar.c, "void anotar(int time)", é a única que mexe
// nos gols da partida; marcar_gol só a chama. O main simula: 2 x 1, 0 x 0 e
// 1 x 3, e mostra a tabela.
//
//   Saída esperada:
//   Partida 1: 2 x 1
//   Partida 2: 0 x 0
//   Partida 3: 1 x 3
//   Casa: 4 pontos, 3 gols
//   Visitante: 4 pontos, 4 gols
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
