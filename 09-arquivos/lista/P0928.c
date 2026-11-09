// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0928 · ★★★ · A tabela do Barezão
//
// Os jogos da rodada do campeonato estão num arquivo texto, um por linha,
// no formato "mandante gols visitante gols". Grave em /tmp/p0928_jogos.txt:
//
//   Nacional 2 Fast 1
//   Manaus 1 Amazonas 1
//   Fast 0 Manaus 3
//   Amazonas 2 Nacional 2
//   Nacional 1 Manaus 0
//   Amazonas 3 Fast 1
//
// Leia os jogos com fscanf e monte a tabela num vetor de structs (nome,
// pontos, vitórias, saldo de gols): vitória vale 3, empate 1. Ordene com
// qsort por pontos (maior primeiro), depois saldo, depois nome. Grave a
// classificação em /tmp/p0928_tabela.txt, mostre esse arquivo lendo com
// fgets e apague os dois.
//
//   Saída esperada:
//   1. Nacional   7 pts  2 V  saldo +2
//   2. Amazonas   5 pts  1 V  saldo +2
//   3. Manaus     4 pts  1 V  saldo +2
//   4. Fast       0 pts  0 V  saldo -6
//
// Dicas:
// 1. Escreva int acha_ou_cria(Time t[], int *n, const char *nome), que
//    devolve o índice do time no vetor e o cria (zerado) se ainda não existe.
// 2. Para cada jogo, atualize os dois times: saldo += gols feitos - gols
//    sofridos; pontos e vitórias conforme o placar.
// 3. O "%+d" do printf mostra o sinal sempre: +2, -6.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    int pontos;
    int vitorias;
    int saldo;
} Time;

int main(void) {

    return 0;
}
