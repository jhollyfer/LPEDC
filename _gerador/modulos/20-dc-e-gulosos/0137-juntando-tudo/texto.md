## 0137 · Juntando tudo

A feira do bairro manda a lista de preços por um rádio lento, e cada byte
economizado conta. Um **compactador** grava uma versão menor de um arquivo e
um **descompactador** devolve o original, byte por byte.

O Huffman do 0136 usava códigos em texto (`"1110"`). Num arquivo, o código
vira **bits de verdade**, e surgem três problemas:

- **o arquivo é feito de bytes**: junte os bits, 8 por vez, num `unsigned
  char` e grave-o quando enche. O último quase nunca enche e vai com zeros;
- **o descompactador precisa da mesma árvore**: o arquivo começa com um
  **cabeçalho** (assinatura `HUF1`, tamanho original e 256 frequências), e o
  `huf_constroi` desempata sempre igual;
- **os zeros do fim não são dados**: o descompactador para ao escrever o
  tamanho original.

O compactador lê o arquivo **duas vezes**: conta as frequências e, com a
árvore pronta, troca cada byte pelo código. O descompactador monta a árvore
do cabeçalho e anda nela bit a bit (`0` esquerda, `1` direita); na folha,
escreve o byte e volta à raiz.

O projeto reúne `fread`/`fwrite` (0068), bits (0065), árvore binária (0098),
heap (0102), Huffman (0136) e TADs (0074). O `compactador.h` oferece
`huf_compacta` e `huf_descompacta`.

A lista da feira (6 linhas repetidas 40 vezes) tem 9560 bytes e compactada,
6156: 1036 de cabeçalho e 5120 de bits:

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

Os bits ocupam 53,6% do original, porque há poucos símbolos e alguns muito
frequentes. O cabeçalho é um custo fixo: pesado em arquivos pequenos,
irrelevante nos grandes.

No fluxograma do `huf_descompacta`, cada byte começa na raiz e lê bits até uma
folha; o laço de fora para no tamanho original:

{{fluxograma}}

> [!WARNING]
> Sem o `descarrega` no fim, os bits do byte incompleto (até 7) se perdem. O
> teste de ida e volta pega o erro: compare **byte a byte**, como o `iguais`.
> Abra os arquivos em modo binário (`"rb"`, `"wb"`): no Windows, em modo texto,
> o byte 26 é lido como fim de arquivo.

> [!TIP]
> **Por dentro do C:** o cabeçalho usa `uint64_t` e `uint32_t` (`stdint.h`)
> porque o tamanho de `long` varia (8 bytes no Linux de 64 bits, 4 no
> Windows): são sempre 4 + 8 + 1024 = 1036 bytes. O `rewind` volta ao começo
> para a segunda leitura.

> [!NOTE]
> **Pergunta para você:** um arquivo tem as 26 letras maiúsculas, cada uma
> repetida 100 vezes (2600 bytes). Quantos bits o Huffman dá a cada letra, e
> quantos bytes tem o `.huf`? Compensa compactar? Calcule e depois teste.

{{pratique}}
