## 0137 · Juntando tudo

A feira do bairro manda a lista de preços para as barracas por um rádio
lento, e cada byte economizado é tempo de transmissão a menos. Para isso
servem dois programas que andam juntos. Um **compactador** grava uma versão
menor de um arquivo; um **descompactador** recebe essa versão e devolve o
original, idêntico byte por byte (SZWARCFITER; MARKENZON, 2010). Este
projeto monta os dois em cima do Huffman (0136).

No 0136, os códigos eram textos como `"1110"`, um caractere por bit. Isso
serve para ver a árvore, mas não economiza nada: cada `'1'` ocupa um byte
inteiro. Num arquivo de verdade, o código vira **bits de verdade**. O arquivo
só sabe gravar bytes, então o programa junta os bits, 8 por vez, num
`unsigned char`, empurrando cada bit novo com `<<` e acendendo-o com `|`
(0065). Quando o byte enche, ele vai para o arquivo. O último byte quase
nunca enche, e vai completado com zeros (KERNIGHAN; RITCHIE, 1989).

Esses zeros criam um problema. O descompactador lê bits até o fim do
arquivo, e os zeros de enchimento parecem dados: um `0` pode ser o código do
A. Por isso o descompactador precisa saber quantos bytes o original tinha e
parar exatamente ao escrever o último (LINTZMAYER; MOTA, 2023).

O descompactador também precisa da **mesma** árvore que o compactador usou,
senão os códigos não batem. Ele não tem o texto original para contar as
frequências. A saída é gravar um **cabeçalho** no começo do arquivo
compactado: uma assinatura, `HUF1`, que identifica o formato; o tamanho
original; e as 256 frequências, uma por valor de byte. Com elas, o
descompactador chama o mesmo `huf_constroi`, que desempata sempre do mesmo
jeito, e chega à mesma árvore (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, seção
5.3).

O cabeçalho precisa ter o mesmo tamanho em qualquer máquina. O tamanho de
`long` varia: 8 bytes no Linux de 64 bits, 4 no Windows. Os tipos `uint64_t`
e `uint32_t`, de `stdint.h`, têm sempre 8 e 4 bytes (CPPREFERENCE, s.d.). Com
eles, o cabeçalho tem sempre 4 + 8 + 1024 = 1036 bytes.

O compactador lê o arquivo **duas vezes**. Na primeira passada, conta quantas
vezes cada byte aparece e monta a árvore. Na segunda, com a árvore pronta,
troca cada byte pelo seu código. Entre uma e outra, `rewind` volta a leitura
para o começo do arquivo (KERNIGHAN; RITCHIE, 1989).

O descompactador faz o caminho inverso. Ele lê o cabeçalho, monta a árvore
e anda nela bit a bit, a partir da raiz: `0` desce para a esquerda, `1` para
a direita. Ao chegar numa folha, escreve o byte dela e volta à raiz para o
próximo (CORMEN et al., 2024, cap. 15). Como o código é livre de prefixo,
nunca há dúvida sobre onde um símbolo termina.

Quanto dá para ganhar? Há um limite. Shannon mostrou que nenhum código sem
perda comprime abaixo da **entropia** da fonte, uma medida de quanta
incerteza cada símbolo carrega em média (SHANNON, 1948). Um arquivo com
poucos símbolos, alguns muito frequentes, tem entropia baixa e comprime bem.
Um arquivo em que todos os 256 bytes aparecem por igual quase não comprime,
e o cabeçalho de 1036 bytes ainda o deixa maior.

> [!WARNING]
> Sem o `descarrega` no fim, os bits do byte incompleto se perdem. Teste a ida
> e volta comparando **byte a byte**, e abra os arquivos em modo binário
> (`"rb"`, `"wb"`).

{{exemplo}}

A feira do bairro manda a lista de preços por um rádio lento. A lista (6
linhas repetidas 40 vezes) tem 9560 bytes; compactada, 6156: 1036 de
cabeçalho e 5120 de bits:

{{ideia}}

A peça central do `compactador.c` escreve bits soltos; a struct `Bits` guarda
o byte em construção e quantos bits ele já tem:

```c
static void escreve_bit(Bits *b, int bit) {
    b->byte = (unsigned char)((b->byte << 1) | bit); // entra pela direita
    b->n++;
    if (b->n == 8) {                                 // byte cheio: grava
        fputc(b->byte, b->f);
        b->byte = 0;
        b->n = 0;
    }
}

static void descarrega(Bits *b) {
    if (b->n > 0) {                                  // completa com zeros
        fputc((unsigned char)(b->byte << (8 - b->n)), b->f);
        b->byte = 0;
        b->n = 0;
    }
}
```

O programa cria o arquivo da feira, compacta, descompacta, compara com o
original e apaga os arquivos de teste:

```c
#include <stdio.h>
#include "compactador.h"

// grava a lista de preços da feira, repetida 40 vezes (um arquivo de uns 10 KB)
int cria_exemplo(const char *nome) {
    const char *linhas[] = {
        "Tomate italiano ........ R$ 8,90 o kg\n",
        "Banana prata ........... R$ 5,50 a dúzia\n",
        "Alface crespa .......... R$ 3,00 o pé\n",
        "Batata inglesa ......... R$ 6,20 o kg\n",
        "Ovos caipiras .......... R$ 18,00 a dúzia\n",
        "Queijo minas ........... R$ 42,00 o kg\n",
    };
    FILE *f = fopen(nome, "w");
    if (f == NULL) {
        return 0;
    }
    for (int r = 0; r < 40; r++) {
        for (int i = 0; i < 6; i++) {
            fputs(linhas[i], f);
        }
    }
    fclose(f);
    return 1;
}

// confere byte a byte se dois arquivos são iguais
int iguais(const char *a, const char *b) {
    FILE *fa = fopen(a, "rb");
    FILE *fb = fopen(b, "rb");
    int ok = fa != NULL && fb != NULL;
    while (ok) {
        int ca = fgetc(fa), cb = fgetc(fb);
        if (ca != cb) ok = 0;
        if (ca == EOF || cb == EOF) break;
    }
    if (fa) fclose(fa);
    if (fb) fclose(fb);
    return ok;
}

int main(void) {
    if (!cria_exemplo("feira.txt")) {
        return 1;
    }
    long original = arq_tamanho("feira.txt");
    long compacto = huf_compacta("feira.txt", "feira.huf");
    long volta = huf_descompacta("feira.huf", "feira2.txt");

    printf("feira.txt:  %ld bytes\n", original);
    printf("feira.huf:  %ld bytes (%.1f%% do original)\n", compacto, 100.0 * compacto / original);
    printf("feira2.txt: %ld bytes, %s\n", volta,
           iguais("feira.txt", "feira2.txt") ? "igual ao original" : "DIFERENTE");

    remove("feira.txt");
    remove("feira.huf");
    remove("feira2.txt");
    return 0;
}
// Saída:
// feira.txt:  9560 bytes
// feira.huf:  6156 bytes (64.4% do original)
// feira2.txt: 9560 bytes, igual ao original
```

O cabeçalho é custo fixo: pesado em arquivo pequeno, irrelevante nos grandes.
No `huf_descompacta`, cada byte começa na raiz e lê bits até uma folha; o laço
de fora para no tamanho original:

{{fluxograma}}
