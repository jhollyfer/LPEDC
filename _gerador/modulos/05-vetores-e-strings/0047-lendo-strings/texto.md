## 0047 · Lendo strings

No cadastro de um app de consultas, a pessoa digita o nome completo: "Maria
Clara". O programa responde "Olá, Maria!". Cadê o "Clara"? O culpado é o
`scanf("%s", nome)`: ele lê **uma palavra** e para no primeiro espaço. O
"Clara" fica esperando na entrada e vai atrapalhar a próxima leitura.

Antes de ver a solução, as regras do `scanf` com string:

- **sem `&`**: `scanf("%s", nome)`. O nome do vetor já é o endereço do
  começo (assunto 0043), então o `&` não vai;
- para no primeiro espaço, tab ou Enter;
- **não sabe o tamanho do vetor**. Digitou 60 letras num `char nome[40]`? Ele
  escreve as 60. Dá para limitar com a largura: `scanf("%39s", nome)`.

Para ler uma **linha inteira**, com espaços, o C tem o **`fgets`**:

```c
fgets(nome, sizeof(nome), stdin);
```

São três argumentos: onde guardar, quantos bytes cabem e de onde ler (`stdin`
é o teclado). O `fgets` lê até o Enter **ou** até encher o vetor (no máximo
`tamanho - 1` caracteres) e **sempre** põe o `'\0'` no fim. Passando o
tamanho certo (`sizeof(nome)`), ele nunca estoura o vetor. Quando a entrada
acaba (Ctrl+D), ele devolve `NULL`.

Só tem um detalhe: o `fgets` **guarda o `'\n'`** do Enter, se couber. Você
digita "Maria Clara" e recebe `"Maria Clara\n"`. Para tirar, use o
**`strcspn`** do `<string.h>`: `strcspn(s, "\n")` devolve a posição do
primeiro `'\n'` (ou o tamanho da string, se não houver). Trocando essa posição
por `'\0'`, o texto termina antes do Enter:

```c
nome[strcspn(nome, "\n")] = '\0';
```

Uma linha só, que funciona nos dois casos: com `'\n'` ele é trocado; sem
`'\n'` o `'\0'` é trocado por ele mesmo. No Node, o `readline` já entrega a
linha sem o `\n`; no C, essa limpeza é sua.

Vamos ver na prática. O vetor `nome` tem 40 bytes. O `fgets` copia os 11
caracteres, depois o `'\n'`, depois o `'\0'`. O `strcspn` acha o `'\n'` na
posição 11, e ele vira o novo fim:

{{ideia}}

O código mostra a string entre colchetes antes e depois da limpeza, para você
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

Repara no fluxograma: o teste do `NULL` vem antes de qualquer uso. Se a
entrada acabou, não existe nome para limpar:

{{fluxograma}}

> [!WARNING]
> **`scanf("%d")` seguido de `fgets` "pula" a leitura.** O `scanf` lê o
> número e deixa o Enter na entrada. O `fgets` seguinte encontra esse `'\n'`
> e devolve uma linha vazia na hora, sem esperar você digitar. A solução é
> jogar fora o resto da linha depois do `scanf`:
> `while ((c = getchar()) != '\n' && c != EOF) {}` (com `int c`). O exemplo
> A094 faz isso. Você vai ver `fflush(stdin)` em material antigo: é
> comportamento indefinido pelo padrão. Não use.

> [!TIP]
> **Por dentro do C:** o teclado não manda as letras direto para o seu
> programa. O terminal junta o que você digita num **buffer** e só entrega
> quando você aperta Enter. `scanf`, `getchar` e `fgets` tiram bytes desse
> mesmo buffer, e o que um deixa o próximo pega. Agora, o **`gets`**: ele lia
> uma linha sem receber o tamanho do vetor, então qualquer linha comprida
> estourava a memória. Em 1988, o worm de Morris invadiu milhares de máquinas
> mandando uma linha longa para um programa que usava `gets`. A função foi
> **removida da linguagem no C11**. Se aparecer num livro, troque por `fgets`.

> [!NOTE]
> **Pergunta para você:** com `char s[5]` e o usuário digitando "uva" e
> Enter, quais bytes ficam em `s` depois do `fgets`? Quanto vale `strlen(s)`
> antes e depois da linha do `strcspn`? E se ele digitasse "melancia"?

{{pratique}}
