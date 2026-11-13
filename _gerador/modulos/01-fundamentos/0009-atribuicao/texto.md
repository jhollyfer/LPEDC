## 0009 · Atribuição, ++ e --

Muita conta de programa não começa do zero: ela parte de um valor que já
existe e o atualiza. O saldo recebe uma recarga, o contador de viagens sobe
um, o total da compra ganha mais um item. Para isso você precisa entender
bem o que o `=` faz e conhecer os atalhos que o C oferece para essas
atualizações.

Pense no bilhete único com R$ 20,00. Você recarrega R$ 30,00 e ele passa a
ter R$ 50,00. Você pega um ônibus de R$ 4,40 e ele fica com R$ 45,60. Em
nenhum momento o saldo é recalculado do zero: cada valor novo sai do
anterior, e o anterior desaparece do visor.

No C, o **`=`** é a **atribuição**: guarde o valor da direita na variável da
esquerda. Ele não é o "igual" da matemática, que afirma que dois lados são
iguais (BACKES, 2013, cap. 3). Por isso `saldo = saldo + 30.00` faz sentido:
o C calcula o lado direito com o valor antigo de `saldo` e depois escreve o
resultado por cima. Do lado esquerdo só pode ficar algo que tenha endereço,
uma variável. `30 = saldo` e `saldo + 1 = 5` não compilam, porque 30 e
`saldo + 1` não são lugares da memória (BACKES, 2013, cap. 3).

Atualizar uma variável é tão comum que o C tem **operadores compostos**
para isso: `+=`, `-=`, `*=`, `/=` e `%=`. `saldo += 30.00` quer dizer
`saldo = saldo + 30.00`, com o nome escrito uma vez só. Um detalhe: o
composto age sobre **toda** a expressão da direita, como se ela estivesse
entre parênteses. `x *= y + 1` é `x = x * (y + 1)`, e não `x * y + 1`
(DEITEL; DEITEL, 2011, cap. 3).

| Atalho | Quer dizer | Com `x = 10` |
| --- | --- | --- |
| `x += 3` | `x = x + 3` | 13 |
| `x -= 3` | `x = x - 3` | 7 |
| `x *= 3` | `x = x * 3` | 30 |
| `x /= 3` | `x = x / 3` | 3 (divisão inteira!) |
| `x %= 3` | `x = x % 3` | 1 |

Somar ou tirar 1 é mais comum ainda, e ganhou operadores próprios: o
**`++`** (incremento) e o **`--`** (decremento). Sozinhos na linha,
`viagens++` e `++viagens` fazem a mesma coisa: `viagens` passa a valer um a
mais (DEITEL; DEITEL, 2011, cap. 3).

A diferença entre os dois aparece quando o valor é **usado** na mesma
expressão. No **pós-incremento**, `x++`, a expressão vale o valor
**antigo** e só depois `x` aumenta. No **pré-incremento**, `++x`, o `x`
aumenta primeiro e a expressão vale o valor **novo** (FEOFILOFF, 2009). Com
`int x = 5;`, a linha `int y = x++ * 2;` deixa `y` com 10 e `x` com 6. Já
`int y = ++x * 2;` deixa `y` com 12 e `x` com 6.

```c
int x = 5;
int y = x++ * 2;   // y vale 10, x vale 6
```

A própria atribuição também é uma expressão: ela vale o valor que acabou de
guardar. E ela se resolve **da direita para a esquerda**. Em
`a = b = c = 7`, o C faz primeiro `c = 7`, que vale 7; depois `b = 7`; por
fim `a = 7` (DEITEL; DEITEL, 2011, cap. 3). É assim que uma linha zera três
variáveis de uma vez.

Esses atalhos voltam o tempo todo no módulo 03: o `+=` vira o acumulador de
um laço, e o `++`, o contador.

> [!WARNING]
> Nunca altere a mesma variável duas vezes na mesma expressão, nem altere e
> leia ao mesmo tempo: `i = i++;` e `printf("%d %d", n++, n);` são
> **comportamento indefinido**: o padrão não define a ordem, e cada
> compilador faz de um jeito. O `-Wall` avisa (`operation on 'i' may be undefined`).

{{exemplo}}

Um bilhete único com R$ 20,00 recebe uma recarga e paga duas viagens. O saldo
passa por quatro valores na mesma caixinha, e as viagens sobem de um em um:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double saldo = 20.00;
    int viagens = 0;

    saldo += 30.00;   // recarga: saldo = saldo + 30.00
    saldo -= 4.40;    // 1ª viagem
    viagens++;        // viagens = viagens + 1
    saldo -= 4.40;    // 2ª viagem
    viagens++;

    printf("Saldo: R$ %.2f depois de %d viagens\n", saldo, viagens);

    int antes = viagens++;   // pós: usa o 2, depois soma (viagens vira 3)
    int depois = ++viagens;  // pré: soma primeiro (vira 4), depois usa o 4
    printf("antes = %d, depois = %d, viagens = %d\n", antes, depois, viagens);
    return 0;
}
// Saída:
// Saldo: R$ 41.20 depois de 2 viagens
// antes = 2, depois = 4, viagens = 4
```

Cada atualização é um retângulo sobre as mesmas duas variáveis. No módulo 03,
esses passos viram laço, com `+=` e `++` como acumulador e contador:

{{fluxograma}}
