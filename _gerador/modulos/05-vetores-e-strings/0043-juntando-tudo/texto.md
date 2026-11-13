## 0043 · Juntando tudo

- **Laço de leitura com `fgets`**: lê uma linha por vez até devolver `NULL`;
  é um laço com sentinela (assunto 0025) (LINUX MAN-PAGES PROJECT, s.d.).
- **Normalizar**: `strcspn` tira o `'\n'` e `tolower` iguala "BOTO" e "boto";
  o `(unsigned char)` protege contra acento (DEITEL; DEITEL, 2011, cap. 8).
- **Matriz de `char`**: os nomes dos candidatos, um por linha;
  `nomes[i]` fica em início + i × 12, por isso `[TAM_NOME]` no parâmetro
  (BACKES, 2013, cap. 9).
- **Vetor de contadores**: `votos[i]` conta os votos do candidato `i`, na
  mesma posição do nome na matriz (DEITEL; DEITEL, 2011, cap. 6).
- **Busca que devolve -1**: `buscar` devolve a posição ou -1, e o voto
  inválido cai fora sem `if` especial (BACKES, 2013, cap. 9).
- **Trocar strings**: como não se atribui com `=`, trocar dois nomes é um
  `strcpy` triplo com uma auxiliar; o A086 ordena uma lista assim (KERNIGHAN;
  RITCHIE, 1989, cap. 5).

> [!WARNING]
> **Empate**: com `>`, ganha quem aparece primeiro na matriz; com `>=`, o
> último. Decida de propósito. E `"boto "`, com espaço no fim, é inválido:
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
