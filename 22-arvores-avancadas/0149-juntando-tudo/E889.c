// 0149 · Juntando tudo
// Exercício E889 · ★☆☆
//
// Use o TAD do corretor (corretor.h) para conferir o recado da escola:
// separe o texto em palavras com cor_proxima, mostre as que não estão no
// dicionário básico e conte quantas são, de quantas no total.
//
//   Saída esperada:
//   desconhecidas: muitos alunos
//   2 de 13 palavras fora do dicionário
//
// Dicas:
// 1. Carregue o dicionário com cor_cria e cor_carrega_basico.
// 2. O laço é while (cor_proxima(&texto, palavra)) { ... }: a função avança
//    o ponteiro texto a cada chamada (por isso o &) e devolve false no fim.
// 3. Resposta esperada: a saída acima. O dicionário tem "muito" e "aluno",
//    mas não os plurais: um corretor de verdade trata as flexões à parte.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "corretor.h"

int main(void) {
    const char *texto = "a escola da cidade tem muitos alunos e um onibus amarelo na porta";
    (void)texto; // apague esta linha

    return 0;
}
