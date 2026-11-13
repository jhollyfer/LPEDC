## 0055 · calloc e realloc

Você abriu uma vaquinha para o churrasco e os Pix vão chegando: R$ 50,
R$ 120, R$ 35. Você não sabe quantos serão. O `malloc` do assunto 0054 pede
um bloco de tamanho certo, mas o tamanho precisa ser conhecido na hora do
pedido. Aqui ele só se descobre no fim. O bloco não cresce sozinho; quem o
faz crescer é você, com o `realloc`. Antes dele, vale conhecer um parente do
`malloc` que resolve outro incômodo.

O **`calloc`** recebe a quantidade de itens e o tamanho de cada um em
argumentos separados, e entrega o bloco **zerado** (BACKES, 2013, cap. 11):

```c
int *contagem = calloc(5, sizeof(int)); // 5 ints, todos valendo 0
```

Use o `calloc` quando o zero inicial importa: contadores, placares, tabelas
de frequência. Com o `malloc`, o bloco viria com lixo e você precisaria de um
laço só para zerá-lo. Como o `malloc`, ele devolve `NULL` se faltar memória.

Agora o crescimento. O **`realloc(p, novo_tamanho)`** muda o tamanho de um
bloco que já está no heap e **preserva o conteúdo** até o menor dos dois
tamanhos. Se o bloco cresceu, a parte nova vem com lixo; se encolheu, o que
passava do novo tamanho se perde (BACKES, 2013, cap. 11).

Para crescer, o `realloc` tenta primeiro esticar o bloco no próprio lugar,
se o espaço logo depois dele estiver livre. Quando não está, ele faz uma
mudança completa: aloca um bloco novo em outro lugar, copia o conteúdo,
libera o antigo e devolve o **endereço novo** (BACKES, 2013, cap. 11). É
como trocar de casa quando a família cresce: os móveis vão junto, mas o
endereço muda. Daí a regra que mais pega: depois de um `realloc`, o endereço
antigo pode não valer mais. Todo ponteiro que apontava para dentro do bloco
velho virou um **ponteiro solto**, que aponta para memória devolvida.

O `realloc` também pode falhar. Se faltar memória, ele devolve `NULL` e **não
mexe no bloco antigo**, que continua inteiro e ocupado. Isso cria uma
armadilha: se você escrever o resultado direto no único ponteiro que tinha o
endereço do bloco, perde esse endereço. A saída é guardar o resultado num
ponteiro **temporário**, conferir se não é `NULL` e só então trocar (CELES;
RANGEL, 2002).

Resta decidir quanto crescer. Chamar o `realloc` a cada Pix funciona, mas
cada mudança de lugar copia o vetor inteiro. Para evitar isso, guarde dois
números: a **quantidade**, quantos elementos você já usou, e a
**capacidade**, quantos cabem no bloco. Enquanto a quantidade for menor que
a capacidade, o novo Pix entra sem `realloc`. Quando encher, **dobre** a
capacidade. Os `realloc` ficam raros: para guardar 1000 elementos começando
com capacidade 1, bastam 10 dobras (1, 2, 4, até 1024).

> [!WARNING]
> `v = realloc(v, n)` é o erro clássico: se falhar, `v` vira `NULL` e o bloco
> antigo fica no heap sem dono, com os dados perdidos. Use um temporário. E
> não guarde `&v[3]` antes de um `realloc`: o bloco pode ter mudado de lugar.

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
