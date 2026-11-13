## 0065 · Bits, máscaras e flags

- **Bit e base 2**: um inteiro é uma fileira de bits, e cada casa vale o dobro
  da casa à direita. Os bits se numeram da direita, a partir do **bit 0** (o
  que vale 1). Revisão no assunto 0003 (FEOFILOFF, 2009, ap. C).
- **Hexa e octal**: um dígito hexadecimal vale 4 bits (`0xED` = 237); um octal
  vale 3, por isso aparece nas permissões. Zero à esquerda é octal: `0755` vale
  493 (BACKES, 2013).
- **Operadores bit a bit**: agem casa por casa em inteiros. Deslocar 1 casa à
  esquerda multiplica por 2; à direita, divide por 2. `1u << n` tem só o bit
  `n` ligado (BACKES, 2013).
- **Flag**: um bit que diz sim ou não. Várias cabem num inteiro: 32 num
  `unsigned` de 4 bytes (DEITEL; DEITEL, 2011, cap. 10).
- **Máscara**: valor que escolhe certos bits. Ligar `p |= W;`, desligar
  `p &= ~W;`, testar `if (p & W)`, inverter `p ^= W;`
  (DEITEL; DEITEL, 2011, cap. 10).
- **Campos de bits** (`unsigned ler : 1;`): a ordem depende do compilador. Para
  arquivos e protocolos, prefira máscaras explícitas (BACKES, 2013, cap. 13).

| Operador | Nome | Regra para cada bit | `a op b` |
| --- | --- | --- | --- |
| `a & b` | E | 1 se os dois são 1 | `0010` (2) |
| `a \| b` | OU | 1 se algum é 1 | `0111` (7) |
| `a ^ b` | OU exclusivo | 1 se são diferentes | `0101` (5) |
| `~a` | NÃO | inverte cada bit | `...1001` |
| `a << 1` | desloca à esquerda | empurra, entra 0 à direita | `1100` (12) |
| `a >> 1` | desloca à direita | empurra, sai o bit 0 | `0011` (3) |

Na tabela, `a = 0110` (6) e `b = 0011` (3).

> [!WARNING]
> `&`, `^` e `|` ficam **abaixo** do `==`: `if (p & W == 0)` vira `p & 0`,
> sempre falso; use `if ((p & W) == 0)`. `&` não é `&&`. E use **unsigned**:
> deslocar negativo, ou por casas demais (`1u << 32`), é comportamento indefinido.

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
