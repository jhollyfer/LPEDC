// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2228 · ★★★ · O parente comum mais próximo
//
// Na árvore genealógica da família Bezerra (uma árvore geral com filho e
// irmão, e agora também um ponteiro pai em cada nó), escreva do zero:
// (1) profundidade(x), contando os passos até a raiz; (2) lca(a, b), o
// ANCESTRAL COMUM MAIS PRÓXIMO: suba o mais fundo até os dois ficarem na
// mesma profundidade e depois suba os dois juntos até se encontrarem; (3) a
// distância entre a e b na árvore, prof(a) + prof(b) - 2 · prof(lca).
// Responda os pares do main.
//
//   Severino
//   ├── Antônio
//   │   ├── Carla
//   │   │   └── Igor
//   │   └── Diego
//   └── Benedita
//       ├── Elaine
//       │   ├── Júlia
//       │   └── Kauã
//       ├── Fábio
//       └── Glória
//           └── Hugo
//
//   Saída esperada:
//   Igor e Diego: Antônio (distância 3)
//   Júlia e Hugo: Benedita (distância 4)
//   Kauã e Elaine: Elaine (distância 1)
//   Igor e Hugo: Severino (distância 6)
//
// Dicas:
// 1. A função filho(p, f) do assunto 0144 ganha uma linha: f->pai = p.
// 2. Para achar um nó pelo nome, uma busca em pré-ordem (filho, depois
//    irmão) com strcmp.
// 3. Resposta esperada: Igor e Diego têm Antônio em comum (distância 3);
//    Júlia e Hugo, Benedita (distância 4); Kauã e Elaine, a própria Elaine
//    (1); Igor e Hugo, Severino (6).
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    return 0;
}
