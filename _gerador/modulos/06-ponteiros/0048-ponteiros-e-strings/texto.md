## 0048 · Ponteiros e strings

Na recepção do evento, o nome do crachá é digitado numa ficha sua: dá para
corrigir, passar para maiúsculas. O apelido só aparece num cartaz na parede:
você lê, mas não escreve nele. Em C, essas duas situações têm sintaxes quase
iguais e comportamentos bem diferentes.

String é um vetor de `char` terminado em `'\0'` (assunto 0041), e o nome de um
vetor vira o endereço do primeiro elemento (assunto 0047). Por isso toda função
de string recebe um **`char *`**, o endereço do primeiro caractere, e anda até
achar o `'\0'`.

Um texto entre aspas, como `"bia"`, é um **literal de string**: o compilador o
guarda **uma vez só**, numa região **somente leitura**, junto com o código.
Compare:

- `char nome[] = "ana";` cria um **vetor** de 4 `char` na pilha e **copia** o
  literal para ele. O vetor é seu: `nome[0] = 'A'` vale;
- `char *apelido = "bia";` cria só um **ponteiro** (8 bytes) com o endereço do
  literal, sem cópia. `apelido[0] = 'B'` tenta escrever na região só de leitura
  e o programa cai.

Por isso, ao apontar para literal, declare **`const char *`**: o compilador
recusa `apelido[0] = 'B'` antes de rodar.

O ponteiro pode mudar de alvo: `apelido = "bibi";` vale. O vetor não:
`nome = "joana";` não compila (para trocar o conteúdo, use `strcpy`). E
`sizeof nome` dá 4 (o vetor), enquanto `sizeof apelido` dá 8 (um endereço).

No desenho, `nome` é uma cópia na pilha, e o laço passa cada letra para
maiúscula. `apelido` é só uma seta para o literal `"bia"`, na área só de
leitura:

{{ideia}}

O ponteiro `p` percorre `nome` até o `'\0'`, trocando cada letra:

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

O `(unsigned char)` antes do `toupper` evita os bytes negativos das letras
acentuadas (assunto 0040). O `(char)` só deixa explícito que o resultado volta a
caber num `char`.

É o laço clássico de string: em vez de contar `n` posições, pergunta "a gaveta
atual é o `'\0'`?":

{{fluxograma}}

> [!WARNING]
> `char *s = "ola"; s[0] = 'O';` compila **sem aviso** e derruba o programa na
> execução (`segmentation fault`): a página do literal é só de leitura. Em
> material antigo é comum `char *p = "..."`; escreva `const char *` para apontar
> para literal, ou `char s[] = "..."` quando precisar mudar o texto. Outro
> clássico: `==` entre strings compara **endereços**, não letras; use `strcmp`.

> [!TIP]
> **Por dentro do C:** os literais ficam na seção `.rodata` (*read-only data*),
> e o sistema barra qualquer escrita nelas. Literais iguais podem compartilhar
> um endereço só. O vetor de ponteiros do A096 (`const char *dias[]`) gasta 8
> bytes por nome mais o texto; a matriz `char[4][10]` reserva 10 bytes por
> linha, até para "sexta".

> [!NOTE]
> **Pergunta para você:** com `char a[] = "oi";` e `const char *b = "oi";`,
> quanto valem `sizeof a`, `sizeof b`, `strlen(a)` e `strlen(b)`? E `a == b`
> é verdadeiro?

{{pratique}}
