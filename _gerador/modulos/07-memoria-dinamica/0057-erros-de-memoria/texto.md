## 0057 · Erros de memória

O sistema do caixa da padaria funciona de manhã. Às seis da tarde está
lento, e no sábado trava. Ninguém mexeu no código. A cada venda, um
pedacinho de memória ficava para trás, e depois de milhares de vendas o heap
acabou. Com o heap nas mãos, você ganhou poder e uma responsabilidade nova:
no C, quem cria esse tipo de erro e quem o corrige é você.

O que torna esses erros perigosos é que o programa costuma **funcionar**.
Ele mostra a saída certa, termina sem reclamar e quebra só na máquina do
cliente, dias depois. Por isso existem ferramentas que vigiam a memória
durante a execução. Antes delas, vale conhecer os quatro erros clássicos, um
de cada vez.

O primeiro é o da padaria, o **vazamento de memória** (*memory leak*): um
bloco que ninguém liberou e cujo endereço ninguém mais guarda. Ele fica
ocupado até o programa acabar. Uma vez só não faz falta; repetido a cada
venda, deixa o programa lento e o derruba depois de horas (DEITEL; DEITEL,
2011, cap. 12). Acontece, por exemplo, quando uma função faz `malloc` num
ponteiro local e retorna sem `free`: o endereço morre com o frame, e o bloco
fica.

O segundo nasce do **ponteiro solto** (*dangling pointer*). Depois de
`free(p)`, a variável `p` continua guardando o mesmo endereço; o `free`
devolve o bloco, mas não apaga o ponteiro. Usar `p` depois disso é o **uso
depois do free**. O pior é que pode até ler o valor antigo, porque ninguém
apagou os bytes. Funciona por sorte, até o `malloc` entregar aquele pedaço a
outra parte do programa, que passa a dividir a memória com você sem saber
(BACKES, 2013, cap. 11).

O terceiro é o **free duplo**: liberar o mesmo bloco duas vezes, em geral
por dois ponteiros que apontavam para ele ou por um ponteiro solto que
ninguém anulou (GOOGLE, s.d.). O hábito `free(p); p = NULL;` do assunto 0054
ajuda, porque `free(NULL)` não faz nada.

O quarto é o **estouro** no heap: ler ou escrever além do fim (ou antes do
começo) de um bloco. Ele é traiçoeiro porque, logo depois do bloco, costuma
morar o cabeçalho escondido do bloco vizinho (assunto 0054). Um byte a mais
estraga a contabilidade do `malloc`, e o programa quebra depois, num `free`
que não tem culpa nenhuma (KERNIGHAN; RITCHIE, 1989, seção 8.7).

A primeira ferramenta é o **AddressSanitizer** (ASan), que vem no `gcc`.
Compile com `-fsanitize=address -g`. O compilador põe vigias em volta de
cada bloco e confere cada acesso; no primeiro erro, o programa para e mostra
a linha do erro, a linha em que o bloco foi alocado e a linha em que foi
liberado. No fim da execução, uma parte dele, o **LeakSanitizer**, lista o
que vazou (GOOGLE, s.d.). As flags de estudo do curso já o ligam.

A segunda é o **valgrind**. Ele roda o executável normal, sem recompilar,
numa máquina virtual que vigia cada byte. Fica de 20 a 50 vezes mais lento,
mas pega uma coisa que o ASan não pega: ler memória que nunca recebeu valor.
Instale com `sudo pacman -S valgrind` (Arch) ou `sudo apt install valgrind`
(Debian/Ubuntu) e rode `valgrind ./programa` (VALGRIND DEVELOPERS, s.d.). A
tabela junta os quatro erros e a mensagem do ASan para cada um:

| Erro | O que é | O AddressSanitizer diz |
| --- | --- | --- |
| **vazamento** | um bloco que ninguém libera e ninguém mais acha | `detected memory leaks` |
| **uso depois do free** | ler ou escrever num bloco já devolvido (ponteiro solto) | `heap-use-after-free` |
| **free duplo** | liberar o mesmo bloco duas vezes | `attempting double-free` |
| **estouro** | passar do fim (ou do começo) de um bloco | `heap-buffer-overflow` |

> [!WARNING]
> "Rodou e deu a saída certa" não prova nada em C. Uso depois do `free`,
> estouro de um byte e leitura de lixo são **comportamento indefinido**: o
> programa pode funcionar hoje e quebrar com outro compilador. Rode com o
> ASan (flags de estudo) e, na dúvida, com `valgrind ./programa`.

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
