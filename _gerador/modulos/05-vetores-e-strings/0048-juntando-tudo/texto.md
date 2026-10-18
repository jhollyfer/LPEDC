## 0048 · Juntando tudo

A escola do bairro abriu uma enquete para escolher o mascote da festa junina:
arara, boto ou capivara. Os votos chegam do formulário, um por linha, do jeito
que cada pessoa digitou: `boto`, `Arara`, `CAPIVARA`, `Tatu`... Você precisa
contar, desenhar um gráfico de barras e anunciar o vencedor.

O problema usa tudo o que o módulo ensinou:

- **`fgets` num laço** (assunto 0047) lê um voto por linha até a entrada
  acabar, quando ele devolve `NULL`;
- **caracteres** (0045): `tolower` em cada letra deixa "BOTO" e "boto" iguais;
- **strings** (0046): `strcspn` tira o `'\n'` e `strcmp` compara o voto com
  cada candidato;
- **matriz de `char`** (0044): os nomes dos candidatos, um por linha;
- **vetor de contadores** (0042): `votos[i]` conta os votos do candidato `i`.
  A posição do nome na matriz é a mesma do contador no vetor;
- **funções que recebem vetores** (0043): `normalizar` altera a linha lida,
  `buscar` só lê.

Divida assim: o `main` cuida do laço e do resultado; cada função faz uma coisa
só. `buscar` devolve a posição ou -1, como a busca do A086: é assim que "Tatu"
cai nos inválidos sem nenhum `if` especial. E o `(unsigned char)` dentro do
`tolower` protege contra votos com acento (veja o assunto 0045).

Vamos ver na prática. Cada linha passa pela mesma esteira: lê, normaliza,
procura na matriz de nomes e soma 1 no contador da posição certa. "Tatu" não
está na matriz, então vai para os inválidos:

{{ideia}}

O programa completo. Para testar sem digitar, mande os votos com `printf
'boto\nArara\n...' | ~/LPEDC/rodar` e o caminho do A095:

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

Repara no fluxograma: é um laço com sentinela (assunto 0030), só que a
sentinela é o `NULL` do `fgets`. Dentro dele, uma decisão: achou o candidato
ou não. O resultado só sai depois que a entrada acaba:

{{fluxograma}}

E se a lista de nomes precisasse sair em ordem alfabética? Como string não se
atribui com `=`, trocar dois nomes de lugar é um `strcpy` triplo, com uma
string auxiliar. O exemplo A096 ordena uma lista de chamada assim, uma prévia
da ordenação por seleção (assunto 0097).

> [!WARNING]
> **Empate.** Com `votos[i] > votos[vencedor]`, um empate fica com quem
> aparece primeiro na matriz. Isso é uma regra de negócio escondida no `>`:
> troque por `>=` e o empate passa a ir para o último. Decida de propósito e,
> se o empate importa, detecte e avise. E `"boto "`, com espaço no fim, é
> inválido para o `strcmp`: a `normalizar` não corta espaços.

> [!TIP]
> **Por dentro do C:** `char nomes[3][12]` são 36 bytes contínuos, como toda
> matriz. "arara" ocupa 6 deles na linha 0, e os 6 bytes restantes da linha
> são zeros (as chaves da inicialização zeram o que sobra). `nomes[1]` é o
> começo da linha 1, 12 bytes depois do começo. É por isso que o parâmetro
> de `buscar` precisa do `[TAM_NOME]`: para achar `nomes[i]`, a função calcula
> início + i × 12. Uma lista de nomes de tamanhos bem diferentes desperdiça
> espaço assim; no módulo 07 você vai guardar cada nome com o tamanho exato,
> usando memória dinâmica.

> [!NOTE]
> **Pergunta para você:** se a entrada tivesse uma linha em branco no meio, o
> que aconteceria com ela? E se um voto tivesse 50 letras, maior que o
> `linha[40]`? Pense no que o `fgets` faz com o resto da linha.

{{pratique}}
