## 0041 · Strings

- **String**: vetor de `char` terminado pelo caractere nulo `'\0'` (código 0).
  O C não tem tipo "string"; o `'\0'` marca o fim, e o que vem depois é
  ignorado (DEITEL; DEITEL, 2011, cap. 8).
- **N + 1**: as aspas duplas já põem o `'\0'`. `"Bruna"` ocupa 6 bytes; um
  texto de N caracteres precisa de N + 1 posições (BACKES, 2013, cap. 7).
- **Aspas simples e duplas**: `'B'` é um `char` (o número 66); `"B"` é uma
  string de 2 bytes (BACKES, 2013, cap. 7).
- **`<string.h>`**: como string é vetor, não se atribui com `=` nem se compara
  com `==`; usam-se funções. O destino vem primeiro, como em `dest = orig`
  (KERNIGHAN; RITCHIE, 1989, cap. 5).
- **`strlen`**: anda até o `'\0'` a cada chamada e devolve `size_t` (`%zu`).
  Calcule antes do laço, não no `i < strlen(s)` (CPPREFERENCE, s.d.).
- **Lista de nomes**: uma matriz de `char`, uma string por linha
  (`char nomes[3][10]`) (CELES; CERQUEIRA; RANGEL, 2016).

```c
char nome[] = "Bruna";   // 6 posições: 'B' 'r' 'u' 'n' 'a' '\0'
char cracha[20];         // cabem até 19 caracteres + o '\0'
char letra = 'B';        // aspas simples: UM char (o número 66)
char texto[] = "B";      // aspas duplas: uma string, 2 bytes ('B' e '\0')
```

| função | faz |
| --- | --- |
| `strlen(s)` | conta os caracteres até o `'\0'` (sem ele) |
| `strcpy(dest, orig)` | copia `orig` para dentro de `dest` |
| `strcat(dest, orig)` | cola `orig` no fim de `dest` |
| `strcmp(a, b)` | 0 se iguais; negativo se `a` vem antes; positivo se depois |

> [!WARNING]
> `strcpy` e `strcat` não sabem o tamanho do destino: "Bruna Matos" num
> `char cracha[8]` é **estouro de buffer**. E `strcmp` devolve **0 quando são
> iguais**: escreva sempre `== 0`.

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
