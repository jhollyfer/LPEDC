## 0041 · Strings

Na entrada de um evento, a recepção imprime o crachá juntando nome e
sobrenome: "Bruna", um espaço e "Matos". Depois confere se o nome bate com o
do cadastro. Em C, o `+` não junta textos e o `==` não compara textos. Para
entender por quê, você precisa saber o que um texto é na memória.

Em C não existe um tipo próprio para texto. Uma **string** é um vetor de
`char` que termina com o caractere nulo `'\0'`, o de código 0 (DEITEL;
DEITEL, 2011, cap. 8). Pense numa fita de etiquetas com um ponto final
impresso: quem lê vai letra por letra até o ponto e para ali, mesmo que a
fita continue. O `'\0'` é esse ponto final. O `printf` com `%s` e todas as
funções de texto andam pelo vetor até achá-lo, e o que vem depois dele é
ignorado.

```c
char nome[] = "Bruna";   // 6 posições: 'B' 'r' 'u' 'n' 'a' '\0'
char cracha[20];         // cabem até 19 caracteres + o '\0'
char letra = 'B';        // aspas simples: UM char (o número 66)
char texto[] = "B";      // aspas duplas: uma string, 2 bytes ('B' e '\0')
```

Quando você escreve um texto entre aspas duplas, o compilador já põe o `'\0'`
no fim. Por isso `"Bruna"` ocupa 6 bytes, e não 5. A regra geral: um texto de
N caracteres precisa de **N + 1** posições (BACKES, 2013, cap. 7). Esquecer
esse +1 é o erro mais comum com string; num vetor `char cracha[20]`, cabem 19
letras.

As aspas também mudam o tipo. `'B'`, entre aspas simples, é um `char`:
o número 66. `"B"`, entre aspas duplas, é uma string de 2 bytes: o `'B'`
e o `'\0'` (BACKES, 2013, cap. 7). Trocar uma pela outra dá erro ou aviso de
compilação.

Como string é vetor (assunto 0037), ela herda as limitações dele: não se
atribui com `=` depois da declaração e não se compara com `==`, que compararia
endereços e não letras. As operações com texto são funções da biblioteca
**`<string.h>`**. Nas que copiam, o **destino vem primeiro**, na mesma ordem
de `dest = orig` (KERNIGHAN; RITCHIE, 1989, cap. 5). A tabela reúne as quatro
que você mais vai usar:

| função | faz |
| --- | --- |
| `strlen(s)` | conta os caracteres até o `'\0'` (sem ele) |
| `strcpy(dest, orig)` | copia `orig` para dentro de `dest` |
| `strcat(dest, orig)` | cola `orig` no fim de `dest` |
| `strcmp(a, b)` | 0 se iguais; negativo se `a` vem antes; positivo se depois |

O `strlen` merece atenção. A string não guarda o próprio tamanho, então ele
anda pelo vetor contando até o `'\0'`, a cada chamada. O resultado é um
`size_t`, o inteiro sem sinal que o C usa para tamanhos, e se mostra com
`%zu`. Como cada chamada percorre o texto, escrever `for (i = 0; i <
strlen(s); i++)` refaz a contagem a cada volta; calcule o tamanho antes do
laço (CPPREFERENCE, s.d.). Ele conta bytes, não letras: `strlen("Belém")` é 6,
porque o "é" ocupa 2 bytes no UTF-8.

Uma lista de nomes é uma matriz de `char` (assunto 0039), com uma string por
linha. Em `char nomes[3][10] = {"Ana", "Bia", "Caio"};`, `nomes[1]` é "Bia" e
cada nome tem até 9 caracteres mais o `'\0'` (CELES; CERQUEIRA; RANGEL, 2016).

> [!WARNING]
> `strcpy` e `strcat` não sabem o tamanho do destino: escrevem até acabar a
> origem. "Bruna Matos" num `char cracha[8]` é **estouro de buffer**, falha de
> segurança clássica. E `strcmp` devolve **0 quando são iguais**; como 0 é
> falso, `if (strcmp(a, b))` quer dizer "se forem diferentes". Escreva `== 0`.

{{exemplo}}

A recepção monta o crachá juntando nome e sobrenome. No vetor de 20, as 11
primeiras posições guardam "Bruna Matos", a 12ª o `'\0'`, e o resto não
importa:

{{ideia}}

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

O `strcat` acha o `'\0'` do destino, escreve por cima e põe um novo no fim.
Toda função de string é um laço "até achar o `'\0'`":

{{fluxograma}}
