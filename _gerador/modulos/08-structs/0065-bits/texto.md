## 0065 · Bits, máscaras e flags

O `ls -l` mostra `-rwxr-xr-x` ao lado de cada arquivo, e o comando
`chmod 755` muda isso. Por que 755? Porque cada permissão (ler, escrever,
executar) é **um bit**, um sim ou não guardado numa casa de um número. Para
entender esse número e mexer nele, você precisa ver o inteiro como o
processador vê: uma fileira de zeros e uns.

Um **bit** é 0 ou 1, e oito bits formam um **byte**. Um inteiro na memória é
uma fileira de bits em **base 2**: cada casa vale o dobro da casa à direita,
1, 2, 4, 8, 16 e assim por diante. Para ler um binário, some as casas que têm
1: `0110` é 4 + 2 = 6. Para escrever 13 em binário, tire a maior casa que
cabe e repita com o resto: 13 = 8 + 4 + 1 = `1101`. Os bits se numeram da
direita para a esquerda, a partir do **bit 0**, o que vale 1 (FEOFILOFF,
2009, ap. C). O assunto 0003 tem a revisão completa.

Binário fica comprido rápido, e há dois atalhos. Na **base 16**
(hexadecimal), os dígitos vão de 0 a 9 e de A a F (10 a 15), e cada dígito
vale **exatamente 4 bits**: `1110 1101` = `0xED` = 237. Na **base 8**
(octal), cada dígito vale **3 bits**, e por isso ele aparece nas permissões,
que vêm em grupos de três. No C, `0x` começa um hexadecimal e um **zero à
esquerda** começa um octal: `0755` é octal e vale 493, não 755 (BACKES,
2013).

Para mexer nesses bits, o C tem os **operadores bit a bit**, que agem casa
por casa, comparando o bit 0 de um número com o bit 0 do outro, o bit 1 com o
bit 1, e assim por diante (BACKES, 2013). O `&` (E) dá 1 só se os dois bits
são 1; o `|` (OU) dá 1 se algum deles é 1; o `^` (OU exclusivo) dá 1 se os
bits são diferentes; o `~` (NÃO) inverte cada bit de um número só. Os
deslocamentos empurram a fileira: `a << 1` anda uma casa para a esquerda e
multiplica por 2; `a >> 1` anda para a direita e divide por 2, com divisão
inteira. Daí sai uma expressão que você vai usar sempre: `1u << n` é o
número com só o bit `n` ligado. A tabela resume, com `a = 0110` (6) e
`b = 0011` (3):

| Operador | Nome | Regra para cada bit | `a op b` |
| --- | --- | --- | --- |
| `a & b` | E | 1 se os dois são 1 | `0010` (2) |
| `a \| b` | OU | 1 se algum é 1 | `0111` (7) |
| `a ^ b` | OU exclusivo | 1 se são diferentes | `0101` (5) |
| `~a` | NÃO | inverte cada bit | `...1001` |
| `a << 1` | desloca à esquerda | empurra, entra 0 à direita | `1100` (12) |
| `a >> 1` | desloca à direita | empurra, sai o bit 0 | `0011` (3) |

Agora as permissões. Uma **flag** é um bit que responde sim ou não, e várias
cabem num inteiro, cada uma na sua casa: `LER` vale 4 (`100`), `ESCREVER`
vale 2 (`010`) e `EXECUTAR` vale 1 (`001`). Num `unsigned` de 4 bytes cabem
32 flags, no espaço que um só `bool` ocuparia se cada uma tivesse o seu
(DEITEL; DEITEL, 2011, cap. 10). É por isso que bibliotecas recebem opções
juntas com `|`, como em `O_WRONLY | O_CREAT | O_APPEND`.

Um valor que escolhe certos bits se chama **máscara**. Com ela, quatro
receitas resolvem tudo (DEITEL; DEITEL, 2011, cap. 10):

```c
p |= ESCREVER;          // liga: o OU acende o bit e não mexe nos outros
p &= ~ESCREVER;         // desliga: ~ESCREVER tem todos os bits menos esse
if (p & ESCREVER) { }   // testa: sobra 0 se o bit estava desligado
p ^= ESCREVER;          // inverte: o OU exclusivo troca 0 por 1 e 1 por 0
```

Cada receita funciona pelo mesmo motivo: nas casas em que a máscara tem 0, o
operador deixa o bit de `p` como estava. Para ler um bit qualquer como 0 ou
1, empurre-o para a casa 0 e apague o resto: `(p >> 2) & 1u` é o bit 2.

A struct também sabe guardar campos de poucos bits, os **campos de bits**:
`unsigned ler : 1;` reserva um bit só para `ler`. A ordem desses bits dentro
do inteiro, porém, fica a critério do compilador. Para formatos de arquivo e
protocolos de rede, em que a posição de cada bit é combinada, prefira
máscaras explícitas (BACKES, 2013, cap. 13).

> [!WARNING]
> `&`, `^` e `|` ficam **abaixo** do `==`: `if (p & W == 0)` vira `p & 0`,
> sempre falso; use `if ((p & W) == 0)`. `&` não é `&&`: `p && W` só pergunta
> se os dois são diferentes de zero. E use **unsigned**: deslocar negativo, ou
> por casas demais (`1u << 32`), é comportamento indefinido.

{{exemplo}}

As permissões de `ls -l` (`rwx`) são três bits: `LER` = 4, `ESCREVER` = 2,
`EXECUTAR` = 1. Um arquivo começa com `rw-` (110); o OU com a máscara `001`
acende só o último bit:

{{ideia}}

```c
#include <stdio.h>

// cada permissão é um bit: 4 = 100, 2 = 010, 1 = 001
#define LER      4u // r
#define ESCREVER 2u // w
#define EXECUTAR 1u // x

void mostrar(const char *passo, unsigned p) {
    printf("%-12s %u%u%u = %u  %c%c%c\n", passo,
           (p >> 2) & 1u, (p >> 1) & 1u, p & 1u, p, // os 3 bits, um por um
           (p & LER) ? 'r' : '-',
           (p & ESCREVER) ? 'w' : '-',
           (p & EXECUTAR) ? 'x' : '-');
}

int main(void) {
    unsigned perm = LER | ESCREVER; // liga dois bits de uma vez: 110
    mostrar("inicial", perm);

    perm |= EXECUTAR;               // OU liga um bit
    mostrar("liga x", perm);

    perm &= ~ESCREVER;              // E com o inverso desliga um bit
    mostrar("desliga w", perm);

    if (perm & ESCREVER) {          // E isola um bit para testar
        printf("pode escrever\n");
    } else {
        printf("não pode escrever\n");
    }

    perm ^= EXECUTAR;               // OU exclusivo inverte um bit
    mostrar("inverte x", perm);
    return 0;
}
// Saída:
// inicial      110 = 6  rw-
// liga x       111 = 7  rwx
// desliga w    101 = 5  r-x
// não pode escrever
// inverte x    100 = 4  r--
```

`(p >> 2) & 1u` lê o bit 2: empurra-o para a casa 0 e apaga o resto. A pergunta
"pode escrever?" é um `&` com a máscara; se sobrou algum bit, a resposta é Sim:

{{fluxograma}}
