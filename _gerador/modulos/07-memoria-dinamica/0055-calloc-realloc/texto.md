## 0055 · calloc e realloc

Você abriu uma vaquinha para o churrasco e os Pix vão chegando: R$ 50, R$ 120,
R$ 35... Não sabe quantos serão. O vetor não cresce sozinho: quem o faz
crescer é você, com o `realloc`.

Antes dele, um primo do `malloc`: o **`calloc`**, que recebe a quantidade e o
tamanho separados e entrega o bloco **zerado**:

```c
int *contagem = calloc(5, sizeof(int)); // 5 ints, todos valendo 0
```

Use quando o zero inicial importa: contadores, placares, tabelas de
frequência. Com `malloc`, você teria lixo e precisaria de um laço para zerar.

O **`realloc(p, novo_tamanho)`** muda o tamanho de um bloco do heap e
**preserva o conteúdo** (até o menor dos dois tamanhos). Se der para esticar o
bloco no lugar, estica. Se não, aloca um bloco novo em outro lugar, copia
tudo, libera o antigo e devolve o **endereço novo**. A parte nova vem com
lixo.

Daí a regra central: **depois do `realloc`, o endereço antigo pode não valer
mais**. Todo ponteiro para dentro do bloco velho virou ponteiro solto.

Se faltar memória, o `realloc` devolve `NULL` e **não mexe no bloco antigo**.
Por isso nunca escreva `pix = realloc(pix, ...)`: com `NULL`, você perde o
único endereço do bloco, que continua ocupado. Guarde o resultado num ponteiro
**temporário** e só depois troque.

Para o vetor crescer sem gastar tempo demais, guarde duas contas: a
**quantidade** (elementos usados) e a **capacidade** (quantos cabem). Encheu?
**Dobre** a capacidade. Os `realloc` ficam raros: para guardar 1000
elementos, começando com 1, são só 10.

Chegam 5 Pix (R$ 50, 120, 35, 80 e 15). O vetor nasce com capacidade 2, dobra
para 4 no terceiro Pix e para 8 no quinto. No fim, 5 posições usadas e 3
livres:

{{ideia}}

O código é a semente da lista sequencial que vira TAD no assunto 0075:

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

A pergunta "encheu?" é feita a cada Pix, mas o desvio para o `realloc` só
acontece duas vezes. Nas demais voltas, guardar custa uma atribuição:

{{fluxograma}}

> [!WARNING]
> `v = realloc(v, n)` é o erro clássico. Se o `realloc` falhar, `v` vira
> `NULL`, o bloco antigo fica no heap sem dono (vazamento) e os dados se
> perdem. Use um temporário. E não guarde endereços de elementos
> (`int *ultimo = &v[3];`) antes de um `realloc`: o bloco pode ter mudado de
> lugar.

> [!NOTE]
> **Pergunta para você:** se a capacidade inicial fosse 1, quantas vezes
> apareceria "Capacidade: ..." para os mesmos 5 Pix? E qual seria a
> capacidade final?

{{pratique}}
