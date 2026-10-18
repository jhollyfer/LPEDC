## 0053 · Ponteiros e strings

Na recepção do evento, a moça imprime os crachás. O seu nome ela digita
numa ficha que é sua: dá para corrigir, passar para maiúsculas, riscar.
O apelido ela só aponta no cartaz da parede: você lê, mas não pode
escrever no cartaz. Em C, essas duas situações têm sintaxes quase iguais e
comportamentos bem diferentes.

Você já sabe que string é um vetor de `char` terminado em `'\0'` (assunto
0046). E já sabe que o nome de um vetor vira o endereço do primeiro
elemento (assunto 0052). Junte as duas coisas: toda função de string recebe
um **`char *`**, o endereço do primeiro caractere, e anda até achar o
`'\0'`.

Um texto entre aspas, como `"bia"`, é um **literal de string**. O
compilador guarda esse texto **uma vez só**, numa região da memória
**somente leitura**, junto com o código do programa. Agora compare:

- `char nome[] = "ana";` cria um **vetor** de 4 `char` na pilha e **copia**
  o literal para dentro dele. O vetor é seu: `nome[0] = 'A'` vale;
- `char *apelido = "bia";` cria só um **ponteiro** (8 bytes) que guarda o
  endereço do literal. Não há cópia. `apelido[0] = 'B'` tenta escrever na
  região só de leitura e o programa cai.

Por isso, quando o ponteiro aponta para literal, declare **`const char
*`**. Aí o compilador recusa `apelido[0] = 'B'` antes de rodar.

As diferenças continuam. O ponteiro pode mudar de alvo: `apelido =
"bibi";` vale. O vetor não: `nome = "joana";` nem compila (para trocar o
conteúdo, `strcpy`). E `sizeof nome` dá 4 (o vetor inteiro), enquanto
`sizeof apelido` dá 8 (o tamanho de um endereço).

Vamos ver na prática. No desenho, `nome` é uma cópia na pilha, onde o laço
passa cada letra para maiúscula. `apelido` é só uma seta para o literal
`"bia"`, que fica na área só de leitura:

{{ideia}}

No código, o ponteiro `p` percorre `nome` até o `'\0'`, trocando cada letra:

```c
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char nome[] = "ana";          // vetor de 4 chars, CÓPIA do literal: pode mudar
    const char *apelido = "bia";  // ponteiro para o literal: só leitura

    // passa o nome para maiúsculas andando com um ponteiro até o '\0'
    for (char *p = nome; *p != '\0'; p++) {
        *p = (char)toupper((unsigned char)*p);
    }
    printf("Crachá: %s (%s)\n", nome, apelido);

    printf("sizeof nome = %zu, sizeof apelido = %zu\n", sizeof nome, sizeof apelido);

    apelido = "bibi";  // vale: o ponteiro passa a apontar para outro literal
    // nome = "joana"; // não compila: vetor não pode receber outro endereço
    printf("Novo apelido: %s\n", apelido);
    return 0;
}
// Saída:
// Crachá: ANA (bia)
// sizeof nome = 4, sizeof apelido = 8
// Novo apelido: bibi
```

O `(unsigned char)` antes do `toupper` evita um problema com letras
acentuadas: os bytes delas podem ser negativos num `char` (assunto 0045). O `(char)` na
frente só deixa explícito que o resultado volta a caber num `char`.

Repara no fluxograma: é o laço clássico de string. A pergunta não é "já
andei `n` posições?", e sim "a gaveta atual é o `'\0'`?":

{{fluxograma}}

> [!WARNING]
> `char *s = "ola"; s[0] = 'O';` compila **sem aviso** no C,
> e derruba o programa quando roda: `segmentation fault`, porque a página do
> literal é só de leitura. Você vai ver muito `char *p = "..."` em material
> antigo. Escreva `const char *` sempre que apontar para literal, ou use
> `char s[] = "..."` quando precisar mudar o texto. Outro clássico:
> comparar strings com `==` compara **endereços**, não letras. Para o
> conteúdo, `strcmp`.

> [!TIP]
> **Por dentro do C:** os literais vão para uma seção do executável chamada
> `.rodata` (*read-only data*). Quando o programa carrega, o sistema marca
> essas páginas da memória como só leitura, e o processador barra qualquer
> escrita. Como o literal não muda, o compilador pode guardar **uma cópia
> só** para literais iguais: dois `"bia"` no programa podem ter o mesmo
> endereço. E o vetor de ponteiros do A106 (`const char *dias[]`) gasta 8
> bytes por nome mais o texto de cada um, enquanto a matriz `char[4][10]`
> reserva 10 bytes por linha mesmo para "sexta".

> [!NOTE]
> **Pergunta para você:** com `char a[] = "oi";` e `const char *b = "oi";`,
> quanto valem `sizeof a`, `sizeof b`, `strlen(a)` e `strlen(b)`? E `a == b`
> é verdadeiro?

{{pratique}}
