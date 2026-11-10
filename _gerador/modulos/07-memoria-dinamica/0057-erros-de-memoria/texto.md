## 0057 · Erros de memória

O sistema do caixa da padaria funciona de manhã. Às seis da tarde está lento,
e no sábado trava. Ninguém mexeu no código. Foi um **vazamento** (*memory
leak*): a cada venda, um pedacinho de memória ficava para trás, e depois de
milhares de vendas o heap acabou. No C, quem cria esse erro e quem o corrige
é você.

O pior é que o programa costuma **funcionar**: mostra a saída certa, termina
sem reclamar e quebra só na máquina do cliente, dias depois. Por isso existem
ferramentas que vigiam a memória durante a execução. Primeiro, os quatro
erros clássicos:

| Erro | O que é | O AddressSanitizer diz |
| --- | --- | --- |
| **vazamento** | um bloco que ninguém libera e ninguém mais acha | `detected memory leaks` |
| **uso depois do free** | ler ou escrever num bloco já devolvido (ponteiro solto) | `heap-use-after-free` |
| **free duplo** | liberar o mesmo bloco duas vezes | `attempting double-free` |
| **estouro** | passar do fim (ou do começo) de um bloco | `heap-buffer-overflow` |

O **ponteiro solto** (*dangling pointer*) está na raiz de dois deles. Depois
de `free(p)`, `p` guarda o mesmo endereço. Usar `p` pode até ler o valor
antigo, porque ninguém apagou os bytes. Funciona por sorte, até o `malloc`
entregar aquele pedaço a outra parte do programa.

O **estouro** no heap é mais traiçoeiro: logo depois do bloco mora o
cabeçalho do vizinho (assunto 0054). Um byte a mais estraga a contabilidade do
`malloc`, e o programa quebra depois, num `free` sem culpa.

As ferramentas:

- **AddressSanitizer** (ASan): use `-fsanitize=address -g` no `gcc`. O
  compilador põe vigias em volta de cada bloco e confere cada acesso. Para no
  primeiro erro e mostra onde ele aconteceu, onde o bloco foi alocado e onde
  foi liberado. No fim, o **LeakSanitizer** lista o que vazou;
- **valgrind**: roda o executável normal numa máquina virtual que vigia cada
  byte. É 20 a 50 vezes mais lento, não exige recompilar e pega o que o ASan
  não pega: ler memória que nunca recebeu valor. Instale com `sudo pacman -S
  valgrind` (Arch) ou `sudo apt install valgrind` (Debian/Ubuntu) e rode
  `valgrind ./programa`.

A função `total_do_pedido` copia os 4 preços de um pedido (R$ 30, 12, 45 e 8)
para um bloco temporário de 16 bytes e soma tudo. Na primeira versão, esquecia
o `free`. Cada um dos 3 pedidos deixava 16 bytes perdidos: o endereço morria
com o frame, mas o bloco ficava. O ASan mostra isso no fim da execução:

{{ideia}}

O relatório da versão quebrada, sem o `free` (salva como `pedido.c`). Leia de
cima para baixo: o tipo do erro, quanto vazou e a pilha de chamadas do
`malloc`:

```text
==12072==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 48 byte(s) in 3 object(s) allocated from:
    #0 0x7f1503afd9c7 in malloc
    #1 0x55bff3c602ef in total_do_pedido pedido.c:5
    #2 0x55bff3c6071c in main pedido.c:20

SUMMARY: AddressSanitizer: 48 byte(s) leaked in 3 allocation(s).
```

A versão corrigida tem uma linha a mais:

```c
#include <stdio.h>
#include <stdlib.h>

int total_do_pedido(const int *precos, int itens) {
    int *copia = malloc(itens * sizeof *copia);
    if (copia == NULL) {
        return -1;
    }
    int total = 0;
    for (int i = 0; i < itens; i++) {
        copia[i] = precos[i];
        total += copia[i];
    }
    free(copia); // sem esta linha, cada pedido deixaria 16 bytes para trás
    return total;
}

int main(void) {
    int pedido[] = {30, 12, 45, 8};
    for (int p = 1; p <= 3; p++) {
        printf("Pedido %d: R$ %d\n", p, total_do_pedido(pedido, 4));
    }
    return 0;
}
// Saída:
// Pedido 1: R$ 95
// Pedido 2: R$ 95
// Pedido 3: R$ 95
```

O `free` precisa vir antes do `return`, que destrói a única variável que sabia
onde o bloco estava:

{{fluxograma}}

> [!WARNING]
> "Rodou e deu a saída certa" não prova nada em C. Uso depois do `free`,
> estouro de um byte e leitura de lixo são **comportamento indefinido**: o
> programa pode funcionar hoje e quebrar com outro compilador. Rode sempre com
> o ASan (flags de estudo) e, na dúvida, com `valgrind ./programa`.

> [!NOTE]
> **Pergunta para você:** se `free(p); p = NULL;` vira hábito, o que acontece
> com um `free(p)` repetido por engano? E com um `p[0] = 5;` depois disso?
> Qual dos dois o hábito resolve de vez?

{{pratique}}
