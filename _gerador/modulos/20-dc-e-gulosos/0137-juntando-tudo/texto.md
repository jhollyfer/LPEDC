## 0137 · Juntando tudo

A feira do bairro manda todo dia, por um rádio de dados lento, a lista de
preços para as bancas. Cada byte economizado é tempo de transmissão a menos.
A ideia é a do assunto anterior, agora de verdade: um **compactador** que
recebe um arquivo qualquer e grava uma versão menor, e um
**descompactador** que devolve o arquivo original, byte por byte.

O Huffman do assunto 0136 trabalhava com uma string na memória e códigos
escritos como texto (`"1110"`). Num arquivo de verdade, cada código vira
**bits de verdade**, e aparecem três problemas novos:

- **o arquivo é feito de bytes**, não de bits. É preciso juntar os bits dos
  códigos, 8 de cada vez, num `unsigned char`, e gravar o byte quando ele
  enche. No fim, o último byte quase nunca está cheio: completa-se com zeros;
- **o descompactador precisa da mesma árvore**. O arquivo compactado começa
  com um **cabeçalho**: uma assinatura (`HUF1`), o tamanho original e as 256
  frequências. Com elas, o descompactador monta a árvore idêntica, porque o
  `huf_constroi` desempata sempre do mesmo jeito;
- **os zeros do fim não são dados**. Por isso o tamanho original vai no
  cabeçalho: o descompactador para quando escreveu esse número de bytes, e
  ignora o enchimento.

O compactador lê o arquivo **duas vezes**: a primeira passada conta as
frequências; a segunda, depois de montar a árvore, troca cada byte pelo
código. O descompactador lê o cabeçalho, monta a árvore e anda nela bit a
bit: `0` para a esquerda, `1` para a direita, e na folha escreve o byte e
volta para a raiz.

Tudo junto, o projeto usa quase o curso inteiro: arquivos binários com
`fread`/`fwrite` (assunto 0068), bits e máscaras (0065), a árvore binária
(0098), o heap (0102), o guloso de Huffman (0136) e TADs em `.h` e `.c`
(0074). O TAD `compactador.h` usa o `huffman.h` por dentro e oferece duas
funções: `huf_compacta` e `huf_descompacta`.

Vamos ver na prática. A lista da feira tem 6 linhas, repetidas 40 vezes:
9560 bytes. Compactada, fica com 6156 bytes, dos quais 1036 são o cabeçalho
e 5120 são os bits dos códigos. O descompactador lê o cabeçalho, refaz a
árvore e devolve os 9560 bytes:

{{ideia}}

O coração do `compactador.c` é a dupla que escreve bits soltos. A struct
`Bits` guarda o byte em construção e quantos bits ele já tem:

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

O programa cria o arquivo da feira, compacta, descompacta, confere se o
resultado é igual ao original e apaga os arquivos de teste:

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

Sem o cabeçalho, os bits ocupam 5120 bytes, 53,6% do original: o texto tem
poucos símbolos diferentes e alguns muito frequentes (o ponto e o espaço).
O cabeçalho de 1036 bytes é um custo fixo, que pesa muito em arquivos
pequenos e quase nada em arquivos grandes.

Repara no fluxograma: é o laço do `huf_descompacta`. Para cada byte do
original, ele começa na raiz e lê bits até cair numa folha. O laço de fora
conta os bytes escritos e para no tamanho do cabeçalho, deixando os zeros de
enchimento sem ler:

{{fluxograma}}

> [!WARNING]
> Esquecer o `descarrega` no fim da compactação é o erro clássico. Os bits
> que sobraram no byte incompleto (até 7) nunca são gravados, e o
> descompactador perde o finalzinho do arquivo, ou devolve lixo nos últimos
> bytes. O teste que pega esse erro é o de ida e volta: compactar,
> descompactar e comparar **byte a byte** com o original, como o `iguais`
> faz. E abra os arquivos sempre em modo binário (`"rb"`, `"wb"`): o
> compactado tem bytes de todo tipo, inclusive o 26, que no Windows, em modo
> texto, é lido como fim de arquivo.

> [!TIP]
> **Por dentro do C:** o cabeçalho usa `uint64_t` e `uint32_t` (de
> `stdint.h`) porque o tamanho de `long` muda de sistema para sistema (8 bytes
> no Linux de 64 bits, 4 no Windows). Com tipos de largura fixa, o arquivo
> tem sempre 4 + 8 + 1024 = 1036 bytes de cabeçalho. Ainda falta um detalhe:
> o `fwrite` grava os bytes na ordem da máquina (*little-endian* no x86 e no
> ARM comum). Um formato portátil escolhe uma ordem e grava byte a byte com
> `>>` e `& 0xFF`. E o arquivo é lido duas vezes sem reabrir: o `rewind`
> volta para o começo.

> [!NOTE]
> **Pergunta para você:** um arquivo tem as 26 letras maiúsculas, cada uma
> repetida 100 vezes (2600 bytes). Quantos bits o Huffman dá a cada letra, e
> quantos bytes tem o `.huf`? Compensa compactar? Calcule e depois teste.

{{pratique}}
