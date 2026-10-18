## 0062 · Erros de memória

O sistema do caixa da padaria funciona perfeitamente de manhã. Às seis da
tarde está lento, e no sábado trava. Ninguém mexeu no código. O que aconteceu
foi um **vazamento**: a cada venda, um pedacinho de memória ficava para trás,
e depois de milhares de vendas o heap acabou. Em inglês, *memory
leak*. No C, quem cria essa doença é você mesmo, e quem cura também.

O pior desses erros é que o programa costuma **funcionar**: mostra a saída
certa, termina sem reclamar e quebra só na máquina do cliente, dias depois.
Por isso o C tem ferramentas que vigiam a memória enquanto o programa roda.
Primeiro, os quatro erros clássicos:

| Erro | O que é | O AddressSanitizer diz |
| --- | --- | --- |
| **vazamento** | um bloco que ninguém libera e ninguém mais acha | `detected memory leaks` |
| **uso depois do free** | ler ou escrever num bloco já devolvido (ponteiro solto) | `heap-use-after-free` |
| **free duplo** | liberar o mesmo bloco duas vezes | `attempting double-free` |
| **estouro** | passar do fim (ou do começo) de um bloco | `heap-buffer-overflow` |

O **ponteiro solto** (*dangling pointer*) é a raiz de dois deles. Depois de
`free(p)`, `p` continua com o mesmo endereço. Se alguém usa `p`, pode até ler
o valor antigo, porque ninguém apagou os bytes. Funciona por sorte, até o
`malloc` entregar aquele pedaço para outra parte do programa.

O **estouro** no heap é ainda mais traiçoeiro: logo depois do seu bloco mora
o cabeçalho do bloco vizinho (lembra do 0059?). Escrever um byte a mais pode
estragar a contabilidade do `malloc`, e o programa quebra muito depois, num
`free` que não tem culpa nenhuma.

As ferramentas:

- **AddressSanitizer** (ASan): já vem no `rodar` (`-fsanitize=address`). O
  compilador põe vigias em volta de cada bloco e cada acesso é conferido.
  Para no primeiro erro e mostra três coisas: onde o erro aconteceu, onde o
  bloco foi alocado e onde foi liberado. No fim, o **LeakSanitizer** lista o
  que vazou;
- **valgrind**: roda o executável normal dentro de uma máquina virtual que
  vigia cada byte. É uns 20 a 50 vezes mais lento, não precisa recompilar e
  pega uma coisa que o ASan não pega: ler memória que nunca recebeu valor.
  Instale com `sudo pacman -S valgrind` no Arch Linux ou `sudo apt install
  valgrind` no Debian/Ubuntu e rode com `~/LPEDC/rodar --valgrind arquivo.c`.

Vamos ver na prática. A função `total_do_pedido` copia os 4 preços de um
pedido (R$ 30, 12, 45 e 8) para um bloco temporário de 16 bytes e soma tudo.
Na primeira versão, ela esquecia o `free`. Cada um dos 3 pedidos deixava 16
bytes perdidos: o endereço morria com o frame, mas o bloco ficava. O ASan
mostra isso no fim da execução:

{{ideia}}

O relatório da versão quebrada, sem o `free`. Leia de cima para baixo: o tipo
do erro, quanto vazou e a pilha de chamadas que fez o `malloc`:

```text
==12072==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 48 byte(s) in 3 object(s) allocated from:
    #0 0x7f1503afd9c7 in malloc
    #1 0x55bff3c602ef in total_do_pedido A123.c:8
    #2 0x55bff3c6071c in main A123.c:23

SUMMARY: AddressSanitizer: 48 byte(s) leaked in 3 allocation(s).
```

A versão corrigida tem uma linha a mais, e é ela que importa:

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

Repara no fluxograma: o `free` precisa estar no caminho antes do `return`,
porque o `return` destrói a única variável que sabia onde o bloco estava:

{{fluxograma}}

> [!WARNING]
> "Rodou e deu a saída certa" não prova nada em C. Uso depois do `free`,
> estouro de um byte e leitura de lixo são **comportamento indefinido**: o
> programa pode funcionar hoje, mostrar outro valor amanhã e quebrar só com
> outro compilador. Rode sempre com o ASan (o `rodar` já faz isso) e, quando
> desconfiar, com `rodar --valgrind`. Saída certa **e** relatório limpo.

> [!TIP]
> **Por dentro do C:** o ASan reserva 1 byte de "memória sombra" para cada 8
> bytes do programa. Em volta de cada bloco do `malloc` ele deixa uma zona
> envenenada (*redzone*); todo acesso confere a sombra antes. Os blocos
> liberados ficam um tempo de quarentena sem ser reaproveitados, e é por isso
> que ele consegue dizer "isto foi liberado lá na linha 31". O custo: o
> programa fica uns 2 vezes mais lento e usa mais memória. Por isso o ASan é
> ferramenta de desenvolvimento, não de produção.

> [!NOTE]
> **Pergunta para você:** se `free(p); p = NULL;` vira hábito, o que acontece
> com um `free(p)` repetido por engano? E com um `p[0] = 5;` depois disso?
> Qual dos dois o hábito resolve de vez?

{{pratique}}
