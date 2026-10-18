## 0005 · printf

O cupom do mercado sai da impressora com as colunas certinhas: o nome do
produto encostado à esquerda, a quantidade e o preço encostados à direita,
sempre com duas casas decimais. Ninguém conta espaços à mão. Quem faz isso é
o **formato**.

O primeiro argumento do `printf` é a **string de formato**: um texto com
**especificadores** (os `%`) que são buracos a preencher. Os outros
argumentos preenchem os buracos **na ordem**, um para cada `%`:

| Especificador | Mostra | Exemplo | Sai |
| --- | --- | --- | --- |
| `%d` | `int` em decimal | `printf("%d", 42)` | `42` |
| `%u`, `%ld`, `%lld` | `unsigned`, `long`, `long long` | `printf("%ld", 9L)` | `9` |
| `%f` | `double` ou `float` | `printf("%f", 2.5)` | `2.500000` |
| `%e`, `%g` | real em notação científica / o mais curto | `printf("%e", 1500.0)` | `1.500000e+03` |
| `%c` | um caractere | `printf("%c", 'A')` | `A` |
| `%s` | um texto | `printf("%s", "Pix")` | `Pix` |
| `%x`, `%X`, `%o` | inteiro em hexa e em octal | `printf("%X", 255)` | `FF` |
| `%p` | um endereço | `printf("%p", (void *)&n)` | `0x7ffe...` |
| `%zu` | o resultado do `sizeof` | `printf("%zu", sizeof n)` | `4` |
| `%%` | o próprio `%` | `printf("10%%")` | `10%` |

Entre o `%` e a letra cabem ajustes, nesta ordem:
`%[flags][largura][.precisão]letra`.

- **largura** é o **mínimo** de caracteres: `%6d` de 42 dá `    42`
  (alinhado à direita). Se o valor for maior, sai inteiro, nada é cortado;
- **flags**: `-` alinha à esquerda (`%-6d` dá `42    `), `0` completa com
  zeros (`%06d` dá `000042`), `+` mostra o sinal sempre;
- **precisão**: em real, o número de casas decimais (`%.2f`); em texto, o
  máximo de caracteres (`%.3s` de `"Brasil"` dá `Bra`).

A precisão **arredonda só na tela**: `%.2f` de 7.499 mostra `7.50`, mas a
variável continua valendo 7.499.

Vamos ver na prática. A linha do arroz tem três buracos: `%-10s` reserva 10
casas para o nome, encostado à esquerda; `%3d` reserva 3 casas para a
quantidade; `%9.2f` reserva 9 casas para o total, com 2 decimais:

{{ideia}}

O cupom inteiro em C:

```c
#include <stdio.h>

int main(void) {
    printf("%-10s %3s %9s\n", "Item", "Qtd", "Total");
    printf("%-10s %3d %9.2f\n", "Arroz 5kg", 2, 51.80);
    printf("%-10s %3d %9.2f\n", "Leite", 12, 71.88);
    printf("%-10s %3d %9.2f\n", "Banana", 1, 7.49);
    printf("%-10s %13.2f\n", "TOTAL", 131.17);
    return 0;
}
// Saída:
// Item       Qtd     Total
// Arroz 5kg    2     51.80
// Leite       12     71.88
// Banana       1      7.49
// TOTAL             131.17
```

Repara no fluxograma: cada `printf` é uma saída, e todas usam o mesmo
formato. Mudar a largura de uma coluna é mudar um número só, em cada linha:

{{fluxograma}}

> [!WARNING]
> O `printf` **confia** em você: se o especificador não combina com o tipo do
> argumento, ele lê os bytes do jeito errado. `printf("%d", 9.90)` não mostra 9
> nem 10: mostra lixo. `printf("%.2f", 5)` também. Faltar argumento é igual. O
> `-Wall` do `rodar` avisa (`format '%d' expects argument of type 'int'`).
> Nunca ignore esse aviso. E no `printf` não vai `&`: ele quer o valor, não o
> endereço.

> [!TIP]
> **Por dentro do C:** o `printf` aceita qualquer número de argumentos, mas
> não sabe os tipos deles: só o formato diz como ler cada um. Nessa passagem,
> todo `float` é convertido em `double`, e por isso o `%f` serve para os dois.
> A largura conta **bytes**, não letras: `"Feijão"` tem 6 letras e 7 bytes
> (o `ã` ocupa 2 no UTF-8), então `%-10s` deixa a coluna dele uma casa mais
> curta. E o `printf` devolve quantos bytes escreveu: `printf("Olá\n")` devolve
> 5. O A010 mostra isso.

> [!NOTE]
> **Pergunta para você:** o que `printf("[%5.1f]\n", 3456.78);` mostra? A
> largura 5 corta o número? Teste num programa seu.

{{pratique}}
