## 0043 · Juntando tudo

A escola do bairro abriu uma enquete para o mascote da festa junina: arara,
boto ou capivara. Os votos chegam um por linha, como cada pessoa digitou:
`boto`, `Arara`, `CAPIVARA`, `Tatu`... Você precisa contar, desenhar um
gráfico de barras e anunciar o vencedor.

O problema usa o módulo inteiro:

- **`fgets` num laço** (0042) lê um voto por linha até devolver `NULL`;
- **caracteres** (0040): `tolower` iguala "BOTO" e "boto";
- **strings** (0041): `strcspn` tira o `'\n'` e `strcmp` compara o voto com
  cada candidato;
- **matriz de `char`** (0039): os nomes dos candidatos, um por linha;
- **vetor de contadores** (0037): `votos[i]` conta os votos do candidato `i`,
  na mesma posição do nome na matriz;
- **funções que recebem vetores** (0038): `normalizar` altera a linha lida,
  `buscar` só lê.

O `main` cuida do laço e do resultado; cada função faz uma coisa só. `buscar`
devolve a posição ou -1, como no A076, e assim "Tatu" cai nos inválidos sem
`if` especial. O `(unsigned char)` no `tolower` protege contra votos com acento
(assunto 0040).

Cada linha passa pela mesma esteira: lê, normaliza, procura na matriz de nomes
e soma 1 no contador. "Tatu" não está na matriz e vai para os inválidos:

{{ideia}}

Para testar sem digitar, salve o código num `.c`, compile com o gcc e mande os
votos com `printf 'boto\nArara\n...' | ./programa`:

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

É um laço com sentinela (assunto 0025), e a sentinela é o `NULL` do `fgets`.
Dentro dele, uma decisão: achou o candidato ou não. O resultado só sai quando a
entrada acaba:

{{fluxograma}}

Para ordenar os nomes em ordem alfabética, como string não se atribui com `=`,
trocar dois nomes é um `strcpy` triplo, com uma string auxiliar. O exemplo A086
ordena uma lista de chamada assim, prévia da ordenação por seleção (assunto
0092).

> [!WARNING]
> **Empate.** Com `votos[i] > votos[vencedor]`, o empate fica com quem aparece
> primeiro na matriz; com `>=`, com o último. É uma regra de negócio escondida
> no operador: decida de propósito. E `"boto "`, com espaço no fim, é inválido
> para o `strcmp`: `normalizar` não corta espaços.

> [!TIP]
> **Por dentro do C:** `char nomes[3][12]` são 36 bytes contínuos; "arara"
> usa 6 da linha 0 e o resto da linha é zero. `nomes[i]` fica em início +
> i × 12, e é essa conta que exige `[TAM_NOME]` no parâmetro de `buscar`. Nomes
> de tamanhos muito diferentes desperdiçam espaço; no módulo 07, a memória
> dinâmica guarda cada nome com o tamanho exato.

> [!NOTE]
> **Pergunta para você:** se a entrada tivesse uma linha em branco no meio, o
> que aconteceria com ela? E se um voto tivesse 50 letras, maior que o
> `linha[40]`? Pense no que o `fgets` faz com o resto da linha.

{{pratique}}
