## 0060 · calloc e realloc

Você abriu uma vaquinha para o churrasco e os Pix vão chegando: R$ 50,
R$ 120, R$ 35... Você não sabe quantos vão ser. No TypeScript, seria um
`pix.push(valor)` e pronto: o array cresce sozinho. No C, quem faz o array
crescer é você, com o `realloc`.

Antes dele, um primo do `malloc`: o **`calloc`**. Ele recebe a quantidade e o
tamanho separados e entrega o bloco **zerado**:

```c
int *contagem = calloc(5, sizeof(int)); // 5 ints, todos valendo 0
```

Use quando o zero inicial importa: contadores, placares, tabelas de
frequência. Com `malloc`, você teria lixo e precisaria de um laço para zerar.

Agora o **`realloc(p, novo_tamanho)`**. Ele muda o tamanho de um bloco que
veio do heap e **preserva o conteúdo** (até o menor dos dois tamanhos). Se der
para esticar o bloco onde ele está, ótimo. Se não der, ele aloca um bloco
novo em outro lugar, copia tudo, libera o antigo e devolve o **endereço
novo**. A parte que cresceu vem com lixo.

Daí sai a regra mais importante do assunto: **depois do `realloc`, o endereço
antigo pode não valer mais**. Qualquer ponteiro que apontava para dentro do
bloco velho virou um ponteiro solto.

E se faltar memória, o `realloc` devolve `NULL` e **não mexe no bloco
antigo**. Por isso nunca escreva `pix = realloc(pix, ...)`: se vier `NULL`,
você perde o único endereço do bloco, que continua ocupado. Guarde o
resultado num ponteiro **temporário** e só depois troque.

Para o vetor crescer sem gastar tempo demais, a estratégia clássica é guardar
duas contas: a **quantidade** (quantos elementos você usa) e a **capacidade**
(quantos cabem). Encheu? **Dobra** a capacidade. Assim os `realloc` ficam
raros: para guardar 1000 elementos, começando com 1, são só 10.

Vamos ver na prática. Chegam 5 Pix (R$ 50, 120, 35, 80 e 15). O vetor nasce
com capacidade 2, dobra para 4 no terceiro Pix e para 8 no quinto. No fim, 5
posições usadas e 3 livres:

{{ideia}}

O mesmo "vetor que cresce" em C. É a semente da lista sequencial que você vai
transformar num TAD no assunto 0080:

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

Repara no fluxograma: a pergunta "encheu?" é feita a cada Pix, mas o desvio
para o `realloc` só acontece duas vezes. Na maior parte das voltas, guardar
custa só uma atribuição:

{{fluxograma}}

> [!WARNING]
> `v = realloc(v, n)` é o erro clássico, e muito livro ensina assim. Se o
> `realloc` falhar, `v` vira `NULL`, o bloco antigo fica no heap sem ninguém
> apontando para ele (vazamento) e os dados se perdem. Use sempre um
> temporário. E não guarde endereços de elementos (`int *ultimo = &v[3];`)
> antes de um `realloc`: o bloco pode ter mudado de lugar.

> [!TIP]
> **Por dentro do C:** dobrar a capacidade faz o custo **médio** do push ser
> constante. Para chegar a 1024 elementos, o `realloc` copia no pior caso
> 1 + 2 + 4 + ... + 512 = 1023 elementos: menos de uma cópia por push. Se
> crescesse de 1 em 1, seriam 1 + 2 + ... + 1023, mais de 500 mil cópias. É
> exatamente o que o `Array` do V8 e o `std::vector` do C++ fazem por baixo.
> Com o rodar, o AddressSanitizer **sempre** muda o bloco de lugar no
> `realloc`, de propósito: assim o erro de usar o endereço antigo aparece logo,
> em vez de só às vezes.

> [!NOTE]
> **Pergunta para você:** se a capacidade inicial fosse 1, quantas vezes
> apareceria "Capacidade: ..." para os mesmos 5 Pix? E qual seria a
> capacidade final?

{{pratique}}
