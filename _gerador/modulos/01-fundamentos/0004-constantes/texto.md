## 0004 · Constantes

A tarifa do ônibus aparece em dez lugares do sistema da empresa: no letreiro,
no cálculo da ida e volta, no recibo, no relatório... Em janeiro ela sobe de
R$ 4,40 para R$ 4,90. Se o valor estiver escrito à mão em cada lugar, alguém
vai esquecer um. O certo é escrever o número **uma vez só**, com um nome.

Todo valor escrito direto no código é um **literal**, e todo literal tem um
tipo, decidido pelo jeito de escrever:

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

Para dar nome a um valor, o C tem dois jeitos. O **`#define`** é uma ordem
para o pré-processador: `#define TARIFA 4.90` faz um "localizar e substituir"
no arquivo antes de o compilador ver o código. O nome `TARIFA` nunca chega ao
compilador; ele só vê `4.90`. A convenção é escrever em MAIÚSCULAS. Sem `=` e
sem `;`.

O outro jeito é o **`const`**: `const int linha = 101;` cria uma variável de
verdade, com tipo, endereço e tamanho, mas **só de leitura**. Tentar mudar dá
erro de compilação, e por isso o valor precisa vir na própria declaração.

Dentro das aspas, a barra invertida avisa que o próximo caractere não é ele
mesmo: é uma **sequência de escape**. `\n` pula linha, `\t` é tabulação, `\"`
põe aspas dentro do texto, `\\` é a própria barra e `\0` é o byte zero. Para
mostrar `%` no `printf`, escreva `%%` (isso é regra do `printf`, não escape).

Vamos ver na prática. O pré-processador troca `TARIFA` por `4.90` e `EMPRESA`
pelo nome da viação. A `linha` é uma caixinha com cadeado: tem endereço, mas
ninguém escreve nela:

{{ideia}}

O mesmo exemplo em C:

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

Repara no fluxograma: o primeiro passo acontece antes de o programa existir.
A troca de texto é feita na compilação; quando o executável roda, ele só tem
os números:

{{fluxograma}}

> [!WARNING]
> O `#define` cola **exatamente** o texto que vem depois do nome. Com
> `#define TARIFA 4.90;`, a linha `printf("%.2f\n", 2 * TARIFA);` vira
> `printf("%.2f\n", 2 * 4.90;);` e não compila. Com `#define TARIFA = 4.90`,
> vira `2 * = 4.90`. Nada de `=` nem de `;` no `#define`. E o erro aparece na
> linha onde o nome é **usado**, não na linha do `#define`, o que confunde.

> [!TIP]
> **Por dentro do C:** salve o programa acima como `tarifa.c`, rode
> `gcc -E tarifa.c | tail -12` e veja: não sobrou nenhum `TARIFA`, só
> `4.90`. Por isso um `#define` não ocupa memória, não tem
> tipo e não aparece no depurador. Já a `const int linha` mora na memória:
> `&linha` tem endereço e `sizeof linha` vale 4. E os literais têm tamanho:
> `sizeof(4.90)` é 8 (`double`), `sizeof(4.90f)` é 4 e `sizeof('A')` é 4,
> porque no C um caractere entre aspas simples é um `int`. Já `sizeof("A")`
> é 2: a letra e o byte zero que marca o fim do texto.

> [!NOTE]
> **Pergunta para você:** o pré-processador troca `TARIFA` dentro das aspas?
> O que `printf("TARIFA\n");` mostra? Teste no programa acima.

{{pratique}}
