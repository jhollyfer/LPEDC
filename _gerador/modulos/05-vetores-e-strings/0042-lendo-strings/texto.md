## 0042 · Lendo strings

- **`scanf("%s", nome)`**: sem `&`, porque o nome do vetor já é o endereço
  (assunto 0038). Lê **uma palavra** e para no primeiro espaço (BACKES, 2013,
  cap. 7).
- **Largura**: o `scanf` não sabe o tamanho do vetor; limite com
  `scanf("%39s", nome)` num `char nome[40]` (BACKES, 2013, cap. 7).
- **`fgets`**: lê uma **linha inteira** até o Enter ou até `tamanho - 1`
  caracteres, e sempre põe o `'\0'`. Devolve `NULL` se a entrada acabar
  (LINUX MAN-PAGES PROJECT, s.d.).
- **O `'\n'` fica**: o `fgets` guarda o Enter, se couber.
  `strcspn(s, "\n")` dá a posição do primeiro `'\n'` (ou o tamanho), e trocá-la
  por `'\0'` limpa nos dois casos (LINUX MAN-PAGES PROJECT, s.d.).
- **Buffer**: o terminal só entrega no Enter, e `scanf`, `getchar` e `fgets`
  tiram bytes do mesmo buffer: o que um deixa, o próximo pega (DEITEL; DEITEL,
  2011, cap. 8).
- **`gets`**: lia sem limite e estourava a memória; foi a brecha do worm de
  Morris (SPAFFORD, 1989). Saiu no C11: use `fgets`.

```c
fgets(nome, sizeof(nome), stdin);
```

```c
nome[strcspn(nome, "\n")] = '\0';
```

> [!WARNING]
> `scanf("%d")` seguido de `fgets` "pula" a leitura: o Enter que sobrou vira
> uma linha vazia. Descarte o resto com
> `while ((c = getchar()) != '\n' && c != EOF) {}`. Não use `fflush(stdin)`.

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
