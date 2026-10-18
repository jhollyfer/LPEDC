## 0046 · Strings

Na entrada de um evento de tecnologia, a recepção imprime o crachá juntando o
nome e o sobrenome da inscrição: "Bruna" + " " + "Matos". Depois confere se o
crachá bate com o nome cadastrado. No C, nem `+` junta textos nem `==`
compara textos. Para entender por quê, você
precisa saber o que é uma string no C.

No C, **string é um vetor de `char` terminado pelo caractere `'\0'`** (o
caractere nulo, código 0). Não existe um tipo "string". O `'\0'` é o marcador
de fim: tudo o que vem depois dele no vetor é ignorado. Quem precisa saber
onde o texto acaba (o `printf` com `%s`, as funções de texto) anda pelo vetor
até achar o `'\0'`.

```c
char nome[] = "Bruna";   // 6 posições: 'B' 'r' 'u' 'n' 'a' '\0'
char cracha[20];         // cabem até 19 caracteres + o '\0'
char letra = 'B';        // aspas simples: UM char (o número 66)
char texto[] = "B";      // aspas duplas: uma string, 2 bytes ('B' e '\0')
```

As aspas duplas já colocam o `'\0'` no fim. Por isso `"Bruna"` ocupa 6 bytes,
e um vetor para guardar um texto de N caracteres precisa de **N + 1**
posições. Esquecer esse +1 é o erro mais comum com string.

Como string é vetor, valem as regras do assunto 0042: não dá para atribuir
com `=` depois da declaração, nem comparar com `==`. As operações de texto
são funções do **`<string.h>`**:

| função | faz |
| --- | --- |
| `strlen(s)` | conta os caracteres até o `'\0'` (sem ele) |
| `strcpy(dest, orig)` | copia `orig` para dentro de `dest` |
| `strcat(dest, orig)` | cola `orig` no fim de `dest` |
| `strcmp(a, b)` | 0 se iguais; negativo se `a` vem antes; positivo se depois |

O `strlen` devolve um `size_t` (inteiro sem sinal para tamanhos), que se
mostra com `%zu`. E repare na ordem dos argumentos de `strcpy` e `strcat`: o
**destino vem primeiro**, como numa atribuição (`dest = orig`).

E uma lista de nomes? É uma matriz de `char` (assunto 0044): cada linha é uma
string. Em `char nomes[3][10] = {"Ana", "Bia", "Caio"};`, `nomes[1]` é a
string "Bia", e cabem até 9 caracteres por nome.

Vamos ver na prática. O vetor `cracha` tem 20 posições. Depois do `strcpy` e
dos dois `strcat`, as 11 primeiras guardam "Bruna Matos", a 12ª guarda o
`'\0'`, e o resto não importa:

{{ideia}}

O código monta o crachá, compara `strlen` com `sizeof` e confere com
`strcmp`:

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

Repara no fluxograma: o `strcat` não sabe onde o crachá termina; ele procura
o `'\0'` do destino e começa a escrever ali, por cima dele, e põe um `'\0'`
novo no fim. Toda função de string é um laço "até achar o `'\0'`":

{{fluxograma}}

> [!WARNING]
> **`strcpy` e `strcat` não sabem o tamanho do destino.** Elas escrevem até
> acabar a origem, caiba ou não. Com `char cracha[8]`, o `strcat` de
> "Bruna Matos" escreve 12 bytes num vetor de 8: **estouro de buffer**, a
> falha de segurança mais famosa da história do C. Antes de copiar ou colar,
> confira: `strlen(dest) + strlen(orig) + 1 <= sizeof(dest)`. Outra pegadinha:
> `strcmp` devolve **0 quando são iguais**, e 0 é falso. `if (strcmp(a, b))`
> quer dizer "se forem **diferentes**". Escreva sempre `== 0`.

> [!TIP]
> **Por dentro do C:** a string do C não guarda o próprio tamanho. Para saber
> quantos caracteres "Bruna Matos" tem, o `strlen` anda byte a byte até o
> `'\0'`: custa proporcional ao tamanho, toda vez. Por isso, num laço, nunca escreva
> `for (i = 0; i < strlen(s); i++)`: o `strlen` roda a cada volta. Calcule uma
> vez antes. E cuidado com acento: o `strlen("Belém")` é **6**, porque o "é"
> em UTF-8 ocupa 2 bytes. O C conta bytes, não letras.

> [!NOTE]
> **Pergunta para você:** depois de `char s[10] = "banana";` e `s[3] = '\0';`,
> o que `printf("%s %zu %zu\n", s, strlen(s), sizeof(s));` mostra? As letras
> depois da posição 3 sumiram da memória?

{{pratique}}
