// Lista · Módulo 25 · Estruturas especiais
// Exercício P2521 · ★★★ · O cache de CEPs em O(1)
//
// O LRU com vetor gasta O(capacidade) por consulta: procurar e empurrar.
// O jeito profissional faz tudo em O(1) com DUAS estruturas juntas:
// - uma lista DUPLAMENTE encadeada, da frente (usado agora) para o fundo
//   (usado há mais tempo): tirar um nó do meio e pôr na frente é O(1);
// - uma tabela hash (13 baldes, cep % 13, encadeamento pelo campo irmao)
//   que leva do CEP direto ao nó da lista.
// Escreva do zero, com capacidade 3, consulta(cep), que devolve 1 no
// acerto. Mostre os 10 pedidos com o cache depois de cada um. Depois
// confira contra uma versão simples com vetor em 5000 consultas sorteadas
// (o gerador do esqueleto), com CEPs múltiplos de 13 para cair todos no
// mesmo balde.
//
//   Pedidos: 69050 69060 69050 69077 69083 69060 69050 69083 69091 69077
//
//   Saída esperada:
//   69050 falta  cache: 69050
//   69060 falta  cache: 69060 69050
//   69050 acerto cache: 69050 69060
//   69077 falta  cache: 69077 69050 69060
//   69083 falta  cache: 69083 69077 69050
//   69060 falta  cache: 69060 69083 69077
//   69050 falta  cache: 69050 69060 69083
//   69083 acerto cache: 69083 69050 69060
//   69091 falta  cache: 69091 69083 69050
//   69077 falta  cache: 69077 69091 69083
//   Acertos: 2 de 10
//   5000 consultas: 1885 acertos, igual a versão simples
//
// Dicas:
// 1. struct No { int cep; struct No *ant, *prox; struct No *irmao; }.
//    Escreva desliga(x), na_frente(x) e tira_do_balde(x).
// 2. Na falta com o cache cheio, o que sai é o do FUNDO: desligue, tire do
//    balde, free. Só então crie o novo.
// 3. Resposta esperada: 2 acertos nos 10 pedidos; 1885 nas 5000 consultas,
//    iguais aos da versão simples.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int pedidos[] = {69050, 69060, 69050, 69077, 69083, 69060, 69050, 69083, 69091, 69077};
    unsigned s = 99;
    for (int k = 0; k < 3; k++) {
        s = s * 1103515245u + 12345u;
        int cep = 69000 + (int)((s >> 16) % 8) * 13;
        printf("%d %d\n", pedidos[k], cep);
    }
    return 0;
}
