## 0043 · Juntando tudo

A escola do bairro abriu uma enquete para o mascote da festa junina: arara,
boto ou capivara. Os votos chegam um por linha, do jeito que cada pessoa
digitou: `boto`, `Arara`, `CAPIVARA`, `Tatu`. Você precisa contar os votos,
desenhar um gráfico de barras e anunciar o vencedor. Nenhuma peça é nova; o
trabalho está em encaixar as peças do módulo.

A entrada vem primeiro. O `fgets` (assunto 0042) lê um voto por linha e
devolve `NULL` quando a entrada acaba. Isso vira um **laço com sentinela**
(assunto 0025): o laço continua enquanto o `fgets` não devolve `NULL`, e você
não precisa saber de antemão quantos votos vão chegar (LINUX MAN-PAGES
PROJECT, s.d.).

Cada linha lida precisa de uma limpeza antes da comparação, um passo chamado
de **normalizar**. O `strcspn` tira o `'\n'` que o `fgets` guardou, e o
`tolower` (assunto 0040) passa cada letra para minúscula, para que "BOTO",
"Boto" e "boto" virem o mesmo texto. O `(unsigned char)` antes do `tolower`
protege contra votos com acento (DEITEL; DEITEL, 2011, cap. 8).

Os candidatos ficam numa **matriz de `char`** (assunto 0039), um nome por
linha: `char nomes[3][12]`. Ela ocupa 36 bytes contínuos; "arara" usa 6 bytes
da linha 0, e o resto da linha fica com zeros. `nomes[i]` começa em início +
i × 12, e é essa conta que obriga o `[TAM_NOME]` no parâmetro da função que
recebe a matriz (BACKES, 2013, cap. 9). Nomes de tamanhos muito diferentes
desperdiçam espaço; no módulo 07, a memória dinâmica guarda cada nome com o
tamanho exato.

A contagem usa um **vetor de contadores** (assunto 0037), `int votos[3]`. A
ideia é casar as posições: `votos[i]` conta os votos do candidato que está em
`nomes[i]`. Se a capivara é a linha 2 da matriz, os votos dela ficam em
`votos[2]` (DEITEL; DEITEL, 2011, cap. 6).

Falta ligar o voto à posição. A função `buscar` compara a linha com cada
nome usando `strcmp` e devolve a posição em que achou ou -1, como no A076. O
-1 resolve o voto inválido sem `if` especial: "Tatu" não está na matriz, a
busca devolve -1, e o `main` soma esse voto aos inválidos (BACKES, 2013,
cap. 9).

As funções seguem o assunto 0038. `normalizar` recebe a linha e a altera,
porque recebeu o endereço do vetor; `buscar` só lê, então os parâmetros dela
podem levar `const`. O `main` cuida do laço e do resultado, e cada função faz
uma coisa só.

Por fim, uma operação que aparece no exercício de ordenar uma lista: trocar
dois nomes de lugar. Como string não se atribui com `=`, a troca é um
`strcpy` triplo com uma variável auxiliar: copia o primeiro para a auxiliar,
o segundo para o primeiro e a auxiliar para o segundo. O A086 ordena uma
lista assim (KERNIGHAN; RITCHIE, 1989, cap. 5).

> [!WARNING]
> **Empate**: com `votos[i] > votos[vencedor]`, ganha quem aparece primeiro na
> matriz; com `>=`, o último. É uma regra escondida no operador: decida de
> propósito. E `"boto "`, com espaço no fim, é inválido para o `strcmp`:
> `normalizar` não corta espaços.

{{exemplo}}

A enquete do mascote da festa junina: arara, boto ou capivara. Cada linha lida
passa pela mesma esteira: normaliza, procura na matriz e soma 1. "Tatu" vai
para os inválidos:

{{ideia}}

Para testar sem digitar, mande os votos com
`printf 'boto\nArara\n...' | ./programa`:

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CANDIDATOS 3
#define TAM_NOME 12
#define TAM_LINHA 40

// tira o '\n' e deixa tudo em minúsculas: "BOTO\n" vira "boto"
void normalizar(char s[]) {
    s[strcspn(s, "\n")] = '\0';
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = (char) tolower((unsigned char) s[i]);
    }
}

// devolve a posição do candidato, ou -1 se o voto não bate com nenhum
int buscar(char nomes[][TAM_NOME], int n, const char voto[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nomes[i], voto) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrar_barra(const char nome[], int votos) {
    printf("%-9s ", nome);
    for (int i = 0; i < votos; i++) {
        putchar('#');
    }
    printf(" %d\n", votos);
}

int main(void) {
    char nomes[CANDIDATOS][TAM_NOME] = {"arara", "boto", "capivara"};
    int votos[CANDIDATOS] = {0};
    int invalidos = 0;
    char linha[TAM_LINHA];

    while (fgets(linha, sizeof(linha), stdin) != NULL) { // um voto por linha
        normalizar(linha);
        int pos = buscar(nomes, CANDIDATOS, linha);
        if (pos >= 0) {
            votos[pos]++;
        } else {
            invalidos++;
        }
    }

    int vencedor = 0;
    for (int i = 0; i < CANDIDATOS; i++) {
        mostrar_barra(nomes[i], votos[i]);
        if (votos[i] > votos[vencedor]) {
            vencedor = i;
        }
    }
    printf("Inválidos: %d\n", invalidos);
    printf("Vencedor: %s\n", nomes[vencedor]);
    return 0;
}
// Entrada (um voto por linha):
// boto, Arara, CAPIVARA, boto, Tatu, capivara, Boto, arara, boto
// Saída:
// arara     ## 2
// boto      #### 4
// capivara  ## 2
// Inválidos: 1
// Vencedor: boto
```

Dentro do laço há uma decisão: achou o candidato ou não. O resultado só sai
quando a entrada acaba:

{{fluxograma}}
