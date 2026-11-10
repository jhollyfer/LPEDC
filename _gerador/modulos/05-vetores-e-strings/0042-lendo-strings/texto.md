## 0042 · Lendo strings

No cadastro de um app de consultas, a pessoa digita "Maria Clara" e o programa
responde "Olá, Maria!". Cadê o "Clara"? O `scanf("%s", nome)` lê **uma
palavra** e para no primeiro espaço. O "Clara" fica na entrada e atrapalha a
próxima leitura.

Regras do `scanf` com string:

- **sem `&`**: `scanf("%s", nome)`. O nome do vetor já é o endereço do começo
  (assunto 0038);
- para no primeiro espaço, tab ou Enter;
- **não sabe o tamanho do vetor**: 60 letras num `char nome[40]` são escritas
  todas. Limite com a largura: `scanf("%39s", nome)`.

Para ler uma **linha inteira**, com espaços, use o **`fgets`**:

```c
fgets(nome, sizeof(nome), stdin);
```

Os argumentos são onde guardar, quantos bytes cabem e de onde ler (`stdin` é o
teclado). O `fgets` lê até o Enter **ou** até encher o vetor (no máximo
`tamanho - 1` caracteres) e **sempre** põe o `'\0'` no fim. Com o tamanho
certo (`sizeof(nome)`), nunca estoura. Se a entrada acabar (Ctrl+D), devolve
`NULL`.

O `fgets` **guarda o `'\n'`** do Enter, se couber: "Maria Clara" chega como
`"Maria Clara\n"`. Para tirar, use o **`strcspn`** do `<string.h>`:
`strcspn(s, "\n")` devolve a posição do primeiro `'\n'` (ou o tamanho da
string, se não houver). Trocar essa posição por `'\0'` termina o texto antes do
Enter:

```c
nome[strcspn(nome, "\n")] = '\0';
```

Funciona nos dois casos: com `'\n'`, ele é trocado; sem, o `'\0'` é trocado por
ele mesmo. O `fgets` não tira o `\n` sozinho.

No exemplo, o vetor `nome` tem 40 bytes. O `fgets` copia os 11 caracteres, o
`'\n'` e o `'\0'`. O `strcspn` acha o `'\n'` na posição 11, e ele vira o novo
fim:

{{ideia}}

O código mostra a string entre colchetes antes e depois da limpeza, para
enxergar o `'\n'`:

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

> [!WARNING]
> **`scanf("%d")` seguido de `fgets` "pula" a leitura.** O `scanf` lê o número
> e deixa o Enter na entrada; o `fgets` pega esse `'\n'` e devolve uma linha
> vazia na hora. Descarte o resto da linha depois do `scanf`:
> `while ((c = getchar()) != '\n' && c != EOF) {}` (com `int c`). O exemplo A084
> faz isso. Não use `fflush(stdin)`, comum em material antigo: é
> comportamento indefinido.

> [!TIP]
> **Por dentro do C:** o terminal junta o que você digita num **buffer** e só
> entrega no Enter; `scanf`, `getchar` e `fgets` tiram bytes desse mesmo
> buffer, e o que um deixa o próximo pega. O **`gets`** lia uma linha sem
> receber o tamanho do vetor e estourava a memória (foi a brecha do worm de
> Morris, em 1988). Foi **removido no C11**; use `fgets`.

> [!NOTE]
> **Pergunta para você:** com `char s[5]` e o usuário digitando "uva" e
> Enter, quais bytes ficam em `s` depois do `fgets`? Quanto vale `strlen(s)`
> antes e depois da linha do `strcspn`? E se ele digitasse "melancia"?

{{pratique}}
