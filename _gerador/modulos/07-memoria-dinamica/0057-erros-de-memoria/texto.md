## 0057 · Erros de memória

- **Vazamento** (*memory leak*): bloco que ninguém libera e ninguém mais acha.
  O programa fica lento e trava depois de horas (DEITEL; DEITEL, 2011, cap. 12).
- **Ponteiro solto** (*dangling pointer*): depois de `free(p)`, `p` guarda o
  mesmo endereço. Usar `p` pode ler o valor antigo por sorte, até o `malloc`
  entregar o pedaço a outro (BACKES, 2013, cap. 11).
- **Free duplo**: liberar o mesmo bloco duas vezes (GOOGLE, s.d.).
- **Estouro** no heap: passar do fim do bloco estraga o cabeçalho do vizinho, e
  o programa quebra depois, num `free` sem culpa
  (KERNIGHAN; RITCHIE, 1989, seção 8.7).
- **AddressSanitizer** (ASan): `gcc -fsanitize=address -g`. Confere cada acesso,
  para no primeiro erro e mostra onde o bloco foi alocado e liberado. No fim, o
  **LeakSanitizer** lista o que vazou (GOOGLE, s.d.).
- **valgrind**: roda o executável sem recompilar, 20 a 50 vezes mais lento, e
  pega leitura de memória que nunca recebeu valor. Instale com `sudo pacman -S
  valgrind` (Arch) ou `sudo apt install valgrind` (Debian/Ubuntu) e rode
  `valgrind ./programa` (VALGRIND DEVELOPERS, s.d.).

| Erro | O que é | O AddressSanitizer diz |
| --- | --- | --- |
| **vazamento** | um bloco que ninguém libera e ninguém mais acha | `detected memory leaks` |
| **uso depois do free** | ler ou escrever num bloco já devolvido (ponteiro solto) | `heap-use-after-free` |
| **free duplo** | liberar o mesmo bloco duas vezes | `attempting double-free` |
| **estouro** | passar do fim (ou do começo) de um bloco | `heap-buffer-overflow` |

> [!WARNING]
> "Rodou e deu a saída certa" não prova nada em C. Uso depois do `free`,
> estouro e leitura de lixo são **comportamento indefinido**. Rode com o ASan
> (flags de estudo) e, na dúvida, com `valgrind ./programa`.

{{exemplo}}

A função `total_do_pedido` copia os 4 preços de um pedido para um bloco de 16
bytes e soma. A primeira versão esquecia o `free`: cada um dos 3 pedidos
deixava 16 bytes perdidos, e o ASan mostra isso no fim:

{{ideia}}

O relatório da versão sem o `free` (salva como `pedido.c`): o tipo do erro,
quanto vazou e a pilha de chamadas do `malloc`:

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
