## 0005 · printf

Até aqui o programa calcula, mas quem usa só enxerga o que aparece na tela. O
`printf` é a ponte entre a memória e o terminal: ele pega valores que estão em
variáveis e os escreve como texto. A graça é que você não escreve o texto
pronto. Você escreve um **molde** e diz o que vai em cada lacuna.

Pense num formulário de papel: "Nome: ______  Idade: ___". O formulário já
traz o texto fixo e reserva os espaços; quem preenche só põe os dados. No
`printf` o formulário é o primeiro argumento, a **string de formato**, e cada
lacuna é um **especificador**, que começa com `%`. Os argumentos que vêm
depois preenchem as lacunas **na ordem**: o primeiro valor vai no primeiro
`%`, o segundo no segundo, e assim por diante (BACKES, 2013, cap. 2).

```c
printf("Idade: %d anos, altura: %.2f m\n", 34, 1.72);
// Idade: 34 anos, altura: 1.72 m
```

A letra depois do `%` diz **como ler** o valor. `%d` lê um inteiro e o mostra
em decimal; `%f` lê um real; `%c`, um caractere; `%s`, um texto. Isso importa
porque o `printf` não sabe o tipo das variáveis que você passou: ele só
recebe bytes e confia no molde para interpretá-los. Um detalhe dessa
passagem: todo `float` chega ao `printf` convertido em `double`, e é por isso
que o mesmo `%f` serve para os dois (KERRISK, s.d.). A tabela reúne as
letras que você vai usar no curso:

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

Só a letra já resolve a maior parte dos casos. Para alinhar colunas ou
controlar casas decimais, cabem ajustes entre o `%` e a letra, sempre nesta
ordem: `%[flags][largura][.precisão]letra` (KERRISK, s.d.). Vale ler um por
vez.

A **largura** é o número **mínimo** de caracteres que o valor ocupa. Se o
valor for menor, o `printf` completa com espaços à esquerda, e o número fica
encostado à direita: `%6d` de 42 sai `    42` (quatro espaços e o 42). Se o
valor for maior que a largura, ele sai inteiro; a largura nunca corta nada
(DEITEL; DEITEL, 2011, cap. 9). Um cuidado com acentos: a largura conta
**bytes**, e no UTF-8 o `ã` ocupa dois. `"Feijão"` tem 6 letras e 7 bytes,
então numa coluna `%-10s` ele parece uma casa mais curto que `"Arroz"`.

As **flags** mudam o preenchimento. O `-` encosta o valor à esquerda e põe
os espaços depois (`%-6d` sai `42    `); o `0` troca os espaços por zeros
(`%06d` sai `000042`); o `+` mostra o sinal mesmo quando o número é positivo
(DEITEL; DEITEL, 2011, cap. 9).

A **precisão** vem depois de um ponto. Num real, ela é o número de casas
decimais: `%.2f` de 3.14159 sai `3.14`. Num texto, é o máximo de caracteres:
`%.3s` de `"Brasil"` sai `Bra`. Repare que a precisão **arredonda só na
tela**: `%.2f` de 7.499 mostra `7.50`, mas a variável continua valendo 7.499
na memória (DEITEL; DEITEL, 2011, cap. 9). O cálculo seguinte usa o valor
completo, não o que você viu.

Por fim, o `printf` escreve na **saída padrão**, o `stdout`, que normalmente
é o terminal. No módulo 09, o `fprintf` usa exatamente o mesmo molde para
escrever num arquivo, então tudo o que você aprende aqui vale lá também
(DEITEL; DEITEL, 2011, cap. 9).

> [!WARNING]
> O `printf` **confia** no formato. Se a letra não combina com o tipo do
> valor, ele lê os bytes do jeito errado: `printf("%d", 9.90)` não mostra 9
> nem 10, mostra lixo. O `-Wall` avisa (`format '%d' expects argument of type
> 'int'`); nunca ignore. E no `printf` não vai `&`: ele quer o valor, não o
> endereço.

{{exemplo}}

O cupom do mercado sai com colunas alinhadas. Na linha do arroz, `%-10s`
reserva 10 casas para o nome, `%3d` reserva 3 para a quantidade e `%9.2f`
reserva 9 para o total, com 2 decimais:

{{ideia}}

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

Cada `printf` é uma saída com o mesmo formato. Para mudar uma coluna, troque
um número em cada linha:

{{fluxograma}}
