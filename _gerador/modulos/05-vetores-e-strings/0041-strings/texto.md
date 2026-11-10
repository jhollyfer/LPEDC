## 0041 · Strings

Na entrada de um evento, a recepção imprime o crachá juntando nome e
sobrenome: "Bruna" + " " + "Matos". Depois confere se bate com o cadastro. No
C, `+` não junta textos e `==` não compara textos, por causa do que uma string
é.

**String é um vetor de `char` terminado pelo caractere `'\0'`** (nulo, código
0). Não existe tipo "string". O `'\0'` marca o fim: o que vem depois é
ignorado. O `printf` com `%s` e as funções de texto andam pelo vetor até achar
o `'\0'`.

```c
char nome[] = "Bruna";   // 6 posições: 'B' 'r' 'u' 'n' 'a' '\0'
char cracha[20];         // cabem até 19 caracteres + o '\0'
char letra = 'B';        // aspas simples: UM char (o número 66)
char texto[] = "B";      // aspas duplas: uma string, 2 bytes ('B' e '\0')
```

As aspas duplas já colocam o `'\0'` no fim. Por isso `"Bruna"` ocupa 6 bytes, e
um texto de N caracteres precisa de **N + 1** posições. Esquecer esse +1 é o
erro mais comum com string.

Como string é vetor (assunto 0037), não se atribui com `=` depois da
declaração nem se compara com `==`. As operações são funções do
**`<string.h>`**:

| função | faz |
| --- | --- |
| `strlen(s)` | conta os caracteres até o `'\0'` (sem ele) |
| `strcpy(dest, orig)` | copia `orig` para dentro de `dest` |
| `strcat(dest, orig)` | cola `orig` no fim de `dest` |
| `strcmp(a, b)` | 0 se iguais; negativo se `a` vem antes; positivo se depois |

O `strlen` devolve `size_t` (inteiro sem sinal para tamanhos), mostrado com
`%zu`. Em `strcpy` e `strcat`, o **destino vem primeiro**, como em
`dest = orig`.

Uma lista de nomes é uma matriz de `char` (assunto 0039), cada linha uma
string. Em `char nomes[3][10] = {"Ana", "Bia", "Caio"};`, `nomes[1]` é "Bia" e
cabem 9 caracteres por nome.

O vetor `cracha` do exemplo tem 20 posições. Depois do `strcpy` e dos dois
`strcat`, as 11 primeiras guardam "Bruna Matos", a 12ª guarda o `'\0'` e o
resto não importa:

{{ideia}}

O código monta o crachá, compara `strlen` com `sizeof` e confere com `strcmp`:

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[] = "Bruna";       // 6 bytes: 5 letras + '\0'
    char sobrenome[] = "Matos";
    char cracha[20];             // espaço de sobra: até 19 letras + '\0'

    strcpy(cracha, nome);        // cracha = "Bruna"
    strcat(cracha, " ");         // cracha = "Bruna "
    strcat(cracha, sobrenome);   // cracha = "Bruna Matos"

    printf("Crachá: %s\n", cracha);
    printf("strlen: %zu caracteres\n", strlen(cracha)); // conta até o '\0'
    printf("sizeof: %zu bytes\n", sizeof(cracha));      // o vetor inteiro

    if (strcmp(cracha, "Bruna Matos") == 0) {           // 0 quer dizer iguais
        printf("Confere com a inscrição.\n");
    }
    return 0;
}
// Saída:
// Crachá: Bruna Matos
// strlen: 11 caracteres
// sizeof: 20 bytes
// Confere com a inscrição.
```

O `strcat` procura o `'\0'` do destino, escreve ali por cima e põe um `'\0'`
novo no fim. Toda função de string é um laço "até achar o `'\0'`":

{{fluxograma}}

> [!WARNING]
> **`strcpy` e `strcat` não sabem o tamanho do destino.** Escrevem até acabar
> a origem, caiba ou não. Com `char cracha[8]`, juntar "Bruna Matos" escreve 12
> bytes num vetor de 8: **estouro de buffer**, falha de segurança clássica.
> Antes, confira `strlen(dest) + strlen(orig) + 1 <= sizeof(dest)`. Outra
> pegadinha: `strcmp` devolve **0 quando são iguais**, e 0 é falso, então
> `if (strcmp(a, b))` significa "se forem **diferentes**". Escreva sempre
> `== 0`.

> [!TIP]
> **Por dentro do C:** a string não guarda o tamanho; o `strlen` anda até o
> `'\0'` a cada chamada. Por isso, nunca escreva `for (i = 0; i < strlen(s);
> i++)`: calcule antes do laço. E `strlen("Belém")` é **6**, porque o "é" em
> UTF-8 ocupa 2 bytes.

> [!NOTE]
> **Pergunta para você:** depois de `char s[10] = "banana";` e `s[3] = '\0';`,
> o que `printf("%s %zu %zu\n", s, strlen(s), sizeof(s));` mostra? As letras
> depois da posição 3 sumiram da memória?

{{pratique}}
