// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2215 · ★★☆ · Amizades e perguntas no aplicativo
//
// Um aplicativo de caronas de Manaus tem 8 usuários (0 a 7). Ao longo do
// dia chegam operações: "U a b" quer dizer que a e b viraram contatos;
// "P a b" pergunta se a e b estão ligados por alguma corrente de contatos
// (amigo de amigo de amigo...). Escreva do zero o union-find (posto e
// compressão) e processe as operações NA ORDEM, respondendo cada pergunta
// com o que se sabe naquele momento.
//
//   U 0 1   U 2 3   P 0 3   U 1 2   P 0 3   U 4 5   P 3 5
//   U 6 7   U 5 6   P 4 7   U 3 4   P 0 7
//
//   Saída esperada:
//   0 e 3: não
//   0 e 3: sim
//   3 e 5: não
//   4 e 7: sim
//   0 e 7: sim
//
// Dicas:
// 1. Guarde as operações num vetor de structs { char tipo; int a, b; }.
// 2. A resposta de uma pergunta depende só das uniões feitas ANTES dela:
//    por isso o union-find, que responde na hora, serve (uma busca em
//    largura a cada pergunta também serviria, mas custaria O(n + m) cada).
// 3. Resposta esperada: não, sim, não, sim, sim.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
