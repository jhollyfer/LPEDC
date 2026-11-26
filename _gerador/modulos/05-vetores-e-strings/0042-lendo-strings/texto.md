## 0042 · Lendo strings

No cadastro de um app de consultas, a pessoa digita "Maria Clara" e o
programa responde "Olá, Maria!". O "Clara" sumiu. O culpado é o `scanf`, que
com `%s` lê **uma palavra** e para no primeiro espaço. O "Clara" fica
esperando na entrada e atrapalha a próxima leitura. Ler texto do teclado pede
ferramentas próprias, e cada uma tem uma regra que você precisa conhecer.

Comece pelo `scanf("%s", nome)`. Ele não leva `&`, porque o nome do vetor já
é o endereço do começo dele (assunto 0038). Ele pula os espaços iniciais, lê
letras até o primeiro espaço, tab ou Enter, e põe o `'\0'` no fim (BACKES,
2013, cap. 7). Serve para uma palavra solta, como uma sigla ou um login.

O `scanf` também não sabe quantos bytes o vetor tem. Se a pessoa digitar 60
letras num `char nome[40]`, ele escreve as 60 e passa do fim do vetor. A
proteção é a **largura**, um número entre o `%` e o `s`: `scanf("%39s",
nome)` lê no máximo 39 letras e deixa a 40ª posição para o `'\0'` (BACKES,
2013, cap. 7).

Para ler uma **linha inteira**, com espaços, a ferramenta é o **`fgets`**:

```c
fgets(nome, sizeof(nome), stdin);
```

Os três argumentos são onde guardar, quantos bytes cabem ali e de onde ler; o
`stdin` é a entrada padrão, normalmente o teclado. O `fgets` lê até o Enter
**ou** até encher o vetor, o que vier primeiro, guardando no máximo
`tamanho - 1` caracteres, e **sempre** põe o `'\0'` no fim. Com
`sizeof(nome)` no segundo argumento, ele nunca passa do fim do vetor. Se a
entrada acabar (Ctrl+D no Linux), ele devolve `NULL` (LINUX MAN-PAGES
PROJECT, s.d.).

O `fgets` tem uma diferença que pega todo mundo: ele **guarda o `'\n'`** do
Enter, se couber. "Maria Clara" chega como `"Maria Clara\n"`, e um `printf`
depois dela pula uma linha a mais. Para tirar esse `'\n'`, use o
**`strcspn`** do `<string.h>`: `strcspn(s, "\n")` devolve a posição do
primeiro `'\n'` da string ou, se não houver nenhum, o tamanho dela. Trocar
essa posição por `'\0'` termina o texto antes do Enter (LINUX MAN-PAGES
PROJECT, s.d.):

```c
nome[strcspn(nome, "\n")] = '\0';
```

A linha funciona nos dois casos. Com `'\n'`, ele vira `'\0'`; sem `'\n'`
(a linha encheu o vetor), a posição devolvida já é a do `'\0'`, que é trocado
por ele mesmo.

Para entender o warning abaixo, falta saber como a entrada chega. O terminal
junta o que você digita num **buffer**, uma área de espera, e só entrega
quando você aperta Enter. `scanf`, `getchar` e `fgets` tiram bytes desse
mesmo buffer, em fila: o que uma leitura deixa, a próxima pega (DEITEL;
DEITEL, 2011, cap. 8). Por isso o "Clara" do começo não se perde; ele fica no
buffer até alguém lê-lo.

Em material antigo você ainda vai encontrar o `gets`. Ele lia uma linha sem
receber o tamanho do vetor e escrevia além do fim quando a linha era longa.
Essa falha foi a brecha usada pelo worm de Morris, em 1988, que parou boa
parte da internet da época (SPAFFORD, 1989). O `gets` foi removido no C11;
use o `fgets`.

> [!WARNING]
> `scanf("%d")` seguido de `fgets` "pula" a leitura: o `scanf` deixa o Enter
> no buffer, e o `fgets` o lê como uma linha vazia. Descarte o resto com
> `while ((c = getchar()) != '\n' && c != EOF) {}`, com `int c`. Não use
> `fflush(stdin)`: é comportamento indefinido.

{{exemplo}}

No cadastro, a pessoa digita "Maria Clara" num `char nome[40]`. O `fgets` copia
os 11 caracteres, o `'\n'` e o `'\0'`; o `strcspn` acha o `'\n'` na posição 11,
e ele vira o novo fim:

{{ideia}}

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char nome[40];

    printf("Nome completo: ");
    if (fgets(nome, sizeof(nome), stdin) == NULL) { // NULL: a entrada acabou
        printf("Nada foi digitado.\n");
        return 1;
    }
    printf("Lido: [%s]", nome);                     // o '\n' veio junto

    nome[strcspn(nome, "\n")] = '\0';               // troca o '\n' pelo fim
    printf("Limpo: [%s]\n", nome);

    printf("Olá, %s! Seu nome tem %zu caracteres.\n", nome, strlen(nome));
    return 0;
}
// Nome completo: Maria Clara
// Lido: [Maria Clara
// ]Limpo: [Maria Clara]
// Olá, Maria Clara! Seu nome tem 11 caracteres.
```

O teste do `NULL` vem primeiro: se a entrada acabou, não há nome para limpar.

{{fluxograma}}
