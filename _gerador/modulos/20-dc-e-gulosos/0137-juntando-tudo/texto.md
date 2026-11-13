## 0137 · Juntando tudo

- **Compactador**: grava uma versão menor de um arquivo; o
  **descompactador** devolve o original, byte por byte
  (SZWARCFITER; MARKENZON, 2010).
- **Bits de verdade**: o código vira bits, juntados 8 por vez num
  `unsigned char` com `<<` e `|`; o último byte quase nunca enche e vai
  completado com zeros (KERNIGHAN; RITCHIE, 1989).
- **Cabeçalho**: o arquivo começa com a assinatura `HUF1`, o tamanho original
  e as 256 frequências, para o descompactador montar a **mesma** árvore
  (TENENBAUM; LANGSAM; AUGENSTEIN, 1995, seção 5.3).
- **Fim dos dados**: os zeros do último byte não são dados; o descompactador
  para ao escrever o tamanho original (LINTZMAYER; MOTA, 2023).
- **Duas leituras**: o compactador conta as frequências e depois, com a
  árvore pronta, troca cada byte pelo código; `rewind` volta ao começo
  (KERNIGHAN; RITCHIE, 1989).
- **Decodificar**: anda na árvore bit a bit (`0` esquerda, `1` direita); na
  folha, escreve o byte e volta à raiz (CORMEN et al., 2024, cap. 15).
- **Tamanho fixo**: `uint64_t` e `uint32_t` de `stdint.h` têm sempre o mesmo
  tamanho; `long` varia entre sistemas (CPPREFERENCE, s.d.).
- **Limite**: nenhum código sem perda comprime abaixo da **entropia** da
  fonte (SHANNON, 1948).

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
