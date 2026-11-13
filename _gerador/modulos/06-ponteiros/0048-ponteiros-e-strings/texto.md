## 0048 · Ponteiros e strings

Na recepção do evento, o nome do crachá é digitado numa ficha sua: dá para
corrigir uma letra ou passar tudo para maiúsculas. O apelido só aparece num
cartaz pregado na parede: você lê, mas não escreve nele. Em C, essas duas
situações se escrevem quase igual e se comportam de jeitos bem diferentes. A
diferença está em quem é dono dos bytes do texto.

Junte duas coisas que você já sabe. Uma string é um vetor de `char`
terminado em `'\0'` (assunto 0041), e o nome de um vetor vira o endereço do
primeiro elemento (assunto 0047). Por isso toda função de string, de
`strlen` a `printf` com `%s`, recebe um **`char *`**: o endereço do primeiro
caractere. Com ele, a função anda gaveta por gaveta até achar o `'\0'`
(KERNIGHAN; RITCHIE, 1989, cap. 5).

Agora o texto entre aspas. Quando você escreve `"bia"` no código, cria um
**literal de string**. O compilador guarda cada literal **uma vez só**, numa
região de **somente leitura** da memória do programa, junto com o código
(DEITEL; DEITEL, 2011, cap. 7). Essa região se chama `.rodata` (*read-only
data*), e o sistema barra qualquer tentativa de escrever nela. Literais
iguais podem até dividir o mesmo endereço.

Com isso, as duas declarações do crachá ficam claras. `char nome[] = "ana";`
cria um **vetor** de 4 `char` na pilha e **copia** o literal para dentro
dele. O vetor é seu, como a ficha: `nome[0] = 'A'` vale (DEITEL; DEITEL,
2011, cap. 7). Já `const char *apelido = "bia";` cria só um **ponteiro**, de 8
bytes, com o endereço do literal, sem cópia nenhuma. Ele é a seta para o
cartaz. Escrever pelo ponteiro, como `apelido[0] = 'B'`, seria escrever na
região de somente leitura; o `const` faz o compilador recusar essa linha
antes de o programa rodar (DEITEL; DEITEL, 2011, cap. 7).

```c
char nome[] = "ana";            // vetor seu, cópia do literal
const char *apelido = "bia";    // seta para o literal
nome[0] = 'A';                  // vale: nome vira "Ana"
apelido = "bibi";               // vale: a seta aponta para outro literal
printf("%zu %zu\n", sizeof nome, sizeof apelido);  // 4 8
```

O código mostra a outra metade da diferença. O ponteiro pode mudar de alvo:
`apelido = "bibi";` só troca o endereço guardado. O vetor não pode:
`nome = "joana";` não compila, porque o nome do vetor é um endereço fixo; para
trocar o conteúdo, use `strcpy`. E o `sizeof` mede coisas diferentes:
`sizeof nome` dá 4, os bytes do vetor, enquanto `sizeof apelido` dá 8, o
tamanho de um endereço (BACKES, 2013, cap. 10).

A mesma escolha aparece numa lista de textos fixos, como os dias da semana.
Um vetor de ponteiros, `const char *dias[]`, gasta 8 bytes por nome mais os
bytes de cada literal. Uma matriz `char dias[4][10]` reserva 10 bytes por
linha, mesmo para um nome curto como "sexta" (DEITEL; DEITEL, 2011, cap. 7).
O vetor de ponteiros economiza quando os textos têm tamanhos diferentes e
não precisam mudar.

> [!WARNING]
> `char *s = "ola"; s[0] = 'O';` compila sem aviso e cai na execução
> (`segmentation fault`), porque o literal é só de leitura. Use
> `const char *` para apontar para literal, ou `char s[]` quando precisar
> mudar o texto. E `==` entre strings compara endereços: use `strcmp`.

{{exemplo}}

No crachá, `nome` é uma cópia na pilha e o laço passa cada letra para
maiúscula; `apelido` é só uma seta para o literal `"bia"`, na área de leitura:

{{ideia}}

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

É o laço clássico de string: em vez de contar posições, pergunta "a gaveta
atual é o `'\0'`?":

{{fluxograma}}
