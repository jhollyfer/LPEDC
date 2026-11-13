## 0004 · Constantes

Imagine a tarifa do ônibus escrita à mão em dez lugares do sistema: no
letreiro, no cálculo de ida e volta, no recibo, no relatório. Em janeiro ela
sobe de R$ 4,40 para R$ 4,90, e alguém precisa caçar os dez lugares. Se
esquecer um, o recibo mostra um preço e o relatório outro. O jeito certo é
escrever o valor **uma vez só**, com um nome, e usar o nome no resto do
código.

Antes de dar nome a um valor, repare em como você o escreve. Todo valor
escrito direto no código é um **literal**, e o jeito de escrever decide o
tipo dele: `101` é `int`, `4.90` é `double` e `4.90f` é `float`
(BACKES, 2013, cap. 2). Isso importa porque o tipo do literal entra nas
contas. Sem nenhuma marca, todo número com ponto é `double`; o sufixo `f`
pede um `float`.

Os inteiros também aceitam marcas. Os sufixos `L`, `LL` e `U` pedem `long`,
`long long` e `unsigned`, e o prefixo muda a base: `0x1F` é hexadecimal e
vale 31; `017`, com zero à esquerda, é **octal**, base 8, e vale 15. Já
`1.5e3` é notação científica, 1,5 × 10³ = 1500 (KERNIGHAN; RITCHIE, 1988,
cap. 2). O zero à esquerda é uma armadilha: quem escreve `017` pensando em
dezessete leva quinze.

Aspas simples e duplas também não são a mesma coisa. `'A'` é um caractere,
e no C ele vale o seu código numérico, 65. `"A"` é um texto: a letra
seguida de um byte zero, que marca o fim do texto (DEITEL; DEITEL, 2011).
Por isso `sizeof("A")` vale 2 e `sizeof('A')` vale 4, o tamanho de um `int`.

| Literal | Tipo | Observação |
| --- | --- | --- |
| `101` | `int` | inteiro sem ponto |
| `4.90` | `double` | todo real é `double`, a não ser que... |
| `4.90f` | `float` | ...tenha o sufixo `f` |
| `5000000000LL` | `long long` | sufixos `L`, `LL`, `U` |
| `0x1F`, `017` | `int` | hexadecimal (31) e **octal** (15): zero à esquerda muda a base! |
| `1.5e3` | `double` | notação científica: 1,5 × 10³ = 1500 |
| `'A'` | `int` | um caractere: vale o código, 65 |
| `"A"` | texto | aspas duplas: `'A'` seguido do byte zero |

O C tem dois jeitos de dar nome a um valor fixo. O primeiro é o
**`#define`**, uma ordem para o pré-processador, a etapa que roda antes da
compilação (0001). Ele faz um "localizar e substituir" no texto do código:
com `#define TARIFA 4.90`, cada `TARIFA` vira `4.90`, e o compilador nem
chega a ver o nome (BACKES, 2013, cap. 2). Como é só troca de texto, o
`#define` não tem tipo e não ocupa memória. Por convenção o nome vai em
MAIÚSCULAS, e a linha não leva `=` nem `;`.

O segundo é o **`const`**. Ele cria uma variável de verdade, com tipo,
endereço e tamanho, mas **só de leitura**: `const int linha = 101;`. Você
pode ver o endereço com `&linha`, e `sizeof linha` vale 4. Qualquer tentativa
de mudar o valor depois é erro de compilação, e por isso o valor tem de vir
na própria declaração (BACKES, 2013, cap. 2).

Por fim, dentro das aspas a barra invertida tem papel especial: ela inicia
uma **sequência de escape**, um jeito de escrever um caractere que não dá
para digitar direto no texto. O `\n` pula linha, o `\t` é uma tabulação, o
`\"` põe aspas dentro do texto, o `\\` é a própria barra e o `\0` é o byte
zero. O `%` não é escape; para mostrá-lo no `printf`, escreva `%%`
(DEITEL; DEITEL, 2011, cap. 9).

> [!WARNING]
> O `#define` cola **exatamente** o texto que vem depois do nome. Com
> `#define TARIFA 4.90;`, `2 * TARIFA` vira `2 * 4.90;` e não compila; com
> `#define TARIFA = 4.90`, vira `2 * = 4.90`. O erro aparece na linha em que
> o nome é **usado**, não na do `#define`.

{{exemplo}}

A tarifa do ônibus aparece em vários lugares do sistema e muda todo ano: fica
escrita uma vez só, com nome. O pré-processador troca `TARIFA` e `EMPRESA`
pelos valores; a `linha` é uma caixinha com cadeado:

{{ideia}}

```c
#include <stdio.h>

#define TARIFA 4.90          // muda aqui, muda no programa todo
#define EMPRESA "Viação Sol"

int main(void) {
    const int linha = 101;   // variável só de leitura

    printf("%s\n", EMPRESA);
    printf("Linha %d \"Centro - Bairro\"\n", linha);
    printf("Tarifa: R$ %.2f\n", TARIFA);
    printf("Ida e volta: R$ %.2f\n", 2 * TARIFA); // o compilador vê 2 * 4.90
    return 0;
}
// Saída:
// Viação Sol
// Linha 101 "Centro - Bairro"
// Tarifa: R$ 4.90
// Ida e volta: R$ 9.80
```

A troca de texto acontece na compilação; o executável já nasce só com os
números:

{{fluxograma}}
