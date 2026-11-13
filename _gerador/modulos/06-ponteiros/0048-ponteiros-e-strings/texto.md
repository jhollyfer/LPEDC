## 0048 · Ponteiros e strings

- **`char *`**: toda função de string recebe o endereço do primeiro caractere
  e anda até o `'\0'` (KERNIGHAN; RITCHIE, 1989, cap. 5).
- **Literal de string**: um texto entre aspas, guardado **uma vez só** numa
  região **somente leitura** (DEITEL; DEITEL, 2011, cap. 7).
- **`char nome[] = "ana";`**: cria um vetor de 4 `char` e **copia** o literal.
  O vetor é seu: `nome[0] = 'A'` vale (DEITEL; DEITEL, 2011, cap. 7).
- **`const char *apelido = "bia";`**: cria só um ponteiro para o literal. Com
  `const`, o compilador recusa `apelido[0] = 'B'` (DEITEL; DEITEL, 2011,
  cap. 7).
- **Mudar de alvo**: `apelido = "bibi";` vale; `nome = "joana";` não compila
  (use `strcpy`). `sizeof nome` dá 4 e `sizeof apelido` dá 8 (BACKES, 2013,
  cap. 10).
- **Vetor de ponteiros**: `const char *dias[]` gasta 8 bytes por nome mais o
  texto; a matriz `char[4][10]` reserva 10 bytes por linha (DEITEL; DEITEL,
  2011, cap. 7).

> [!WARNING]
> `char *s = "ola"; s[0] = 'O';` compila sem aviso e cai na execução
> (`segmentation fault`). Use `const char *` ou `char s[]`. E `==` entre
> strings compara endereços: use `strcmp`.

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
