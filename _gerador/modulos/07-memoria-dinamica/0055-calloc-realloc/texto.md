## 0055 · calloc e realloc

- **`calloc(n, tam)`**: recebe quantidade e tamanho separados e entrega o bloco
  **zerado**. Serve para contadores, placares e tabelas de frequência
  (BACKES, 2013, cap. 11).

```c
int *contagem = calloc(5, sizeof(int)); // 5 ints, todos valendo 0
```

- **`realloc(p, novo_tamanho)`**: muda o tamanho de um bloco e **preserva o
  conteúdo** até o menor dos dois tamanhos. A parte nova vem com lixo
  (BACKES, 2013, cap. 11).
- **Bloco que muda de lugar**: se não der para esticar no lugar, o `realloc`
  aloca outro bloco, copia, libera o antigo e devolve o **endereço novo**.
  Ponteiros para o bloco velho viram soltos (BACKES, 2013, cap. 11).
- **Falha**: o `realloc` devolve `NULL` e não mexe no bloco antigo. Guarde o
  resultado num ponteiro **temporário** e só depois troque (CELES; RANGEL, 2002).
- **Quantidade e capacidade**: elementos usados e quantos cabem. Encheu,
  **dobre** a capacidade: para 1000 elementos, começando com 1, bastam 10
  `realloc`.

> [!WARNING]
> `v = realloc(v, n)` é o erro clássico: se falhar, `v` vira `NULL` e o bloco
> antigo fica no heap sem dono. Use um temporário. E não guarde `&v[3]` antes de
> um `realloc`: o bloco pode ter mudado de lugar.

{{exemplo}}

Os Pix de uma vaquinha vão chegando: R$ 50, 120, 35, 80 e 15. O vetor nasce
com capacidade 2, dobra para 4 no terceiro Pix e para 8 no quinto:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int chegando[] = {50, 120, 35, 80, 15}; // os Pix do dia, em R$
    int capacidade = 2;                      // cabem 2 por enquanto
    int quantidade = 0;                      // quantos já guardei
    int *pix = malloc(capacidade * sizeof *pix);
    if (pix == NULL) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (quantidade == capacidade) { // encheu: dobra a capacidade
            int nova = capacidade * 2;
            int *maior = realloc(pix, nova * sizeof *pix); // temporário!
            if (maior == NULL) {
                free(pix); // o bloco antigo continua valendo: libera
                return 1;
            }
            printf("Capacidade: %d -> %d\n", capacidade, nova);
            pix = maior;
            capacidade = nova;
        }
        pix[quantidade] = chegando[i]; // o "push"
        quantidade++;
    }

    int total = 0;
    for (int i = 0; i < quantidade; i++) {
        total += pix[i];
    }
    printf("%d Pix, total R$ %d\n", quantidade, total);
    printf("Sobram %d posições livres\n", capacidade - quantidade);
    free(pix);
    return 0;
}
// Saída:
// Capacidade: 2 -> 4
// Capacidade: 4 -> 8
// 5 Pix, total R$ 300
// Sobram 3 posições livres
```

A pergunta "encheu?" vem a cada Pix, mas o desvio para o `realloc` só acontece
duas vezes:

{{fluxograma}}
