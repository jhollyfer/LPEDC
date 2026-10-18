## 0070 · Bits, máscaras e flags

Rode `ls -l` num terminal Linux e você vê algo como `-rwxr-xr-x` do lado de
cada arquivo. Para mudar isso, alguém digita `chmod 755`. Por que 755? Porque
cada permissão é **um bit**, e o C sabe mexer em bits um por um.

### Binário em cinco minutos

Um **bit** é um 0 ou um 1. Oito bits formam um **byte**. Um número inteiro na
memória é só uma fileira de bits, lida em **base 2**: cada casa vale o dobro
da casa à direita.

| casa | 2⁷ | 2⁶ | 2⁵ | 2⁴ | 2³ | 2² | 2¹ | 2⁰ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| vale | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |

Para ler um binário, some as casas que têm 1: `0110` = 4 + 2 = 6. Para
escrever um decimal em binário, tire a maior casa que cabe e repita: 13 =
8 + 4 + 1 = `1101`. Os bits se numeram da direita para a esquerda, a partir do
**bit 0** (o que vale 1).

Binário é comprido, então usamos atalhos. Na **base 16** (hexadecimal), cada
dígito, de 0 a 9 e de A (10) a F (15), vale **exatamente 4 bits**: `1110 1101`
= `0xED` = 237. Na **base 8** (octal), cada dígito vale **3 bits**, e é por
isso que ele aparece nas permissões: 3 bits por grupo. No C, `0x` começa um
hexadecimal e um **zero à esquerda** começa um octal: `0755` é octal, e vale
493, não 755.

### Os operadores bit a bit

Eles trabalham bit a bit, casa por casa, sobre inteiros. Com `a = 0110` (6) e
`b = 0011` (3):

| Operador | Nome | Regra para cada bit | `a op b` |
| --- | --- | --- | --- |
| `a & b` | E | 1 se os dois são 1 | `0010` (2) |
| `a \| b` | OU | 1 se algum é 1 | `0111` (7) |
| `a ^ b` | OU exclusivo | 1 se são diferentes | `0101` (5) |
| `~a` | NÃO | inverte cada bit | `...1001` |
| `a << 1` | desloca à esquerda | empurra, entra 0 à direita | `1100` (12) |
| `a >> 1` | desloca à direita | empurra, sai o bit 0 | `0011` (3) |

Deslocar 1 casa para a esquerda multiplica por 2; para a direita, divide por
2 (divisão inteira). E `1u << n` é o número que só tem o bit `n` ligado.

### Máscaras e flags

Uma **flag** é um bit que diz sim ou não. Várias flags cabem num inteiro só,
cada uma no seu bit: `LER` = 4 (`100`), `ESCREVER` = 2 (`010`), `EXECUTAR` = 1
(`001`). Um valor que escolhe certos bits é uma **máscara**. Com ela, quatro
receitas resolvem tudo:

- **ligar** um bit: `p |= ESCREVER;`
- **desligar**: `p &= ~ESCREVER;` (o `~` faz uma máscara com todos os bits
  ligados menos aquele)
- **testar**: `if (p & ESCREVER)` (sobra 0 se o bit estava desligado)
- **inverter**: `p ^= ESCREVER;`

Vamos ver na prática. Um arquivo começa com `rw-` (110). Para ligar a
execução, o OU com a máscara `001` acende só o último bit, e os outros ficam
como estavam:

{{ideia}}

O programa aplica as quatro receitas em sequência e mostra os bits a cada
passo:

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

O `(p >> 2) & 1u` é o jeito de ler o bit 2: empurra ele para a casa 0 e apaga
o resto com a máscara `1`. O `chmod 755` completo, no A140, é a mesma ideia
com três grupos de 3 bits: dono `111`, grupo `101`, outros `101`.

Repara no fluxograma: a pergunta "pode escrever?" é só um `&` com a máscara.
Sobrou algum bit, a resposta é Sim:

{{fluxograma}}

> [!WARNING]
> Três armadilhas. (1) **Precedência**: `&`, `^` e `|` ficam **abaixo** do
> `==`. Então `if (p & ESCREVER == 0)` é lido como `p & (ESCREVER == 0)`, que
> é `p & 0`, sempre falso. Use parênteses: `if ((p & ESCREVER) == 0)`. (2)
> `&` não é `&&`: `p && ESCREVER` só pergunta se os dois são diferentes de
> zero, e quase sempre dá verdadeiro. (3) Use **unsigned** para bits.
> Deslocar um número negativo, ou deslocar por mais casas do que o tipo tem
> (`1u << 32` num `unsigned` de 32 bits), é comportamento indefinido.

> [!TIP]
> **Por dentro do C:** cada operador bit a bit vira **uma** instrução do
> processador (`and`, `or`, `xor`, `not`, `shl`, `shr`), a operação mais
> barata que existe. Por isso flags estão em toda parte: o Linux abre arquivos
> com `open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644)`, flags no segundo
> argumento e permissões `rw-r--r--` no terceiro. E 32 flags cabem num
> `unsigned` de 4 bytes, onde 32 `bool` ocupariam 32 bytes. O C também tem
> **campos de bits** numa struct (`unsigned ler : 1;` usa um bit só), mas a
> ordem dos bits dentro do inteiro depende do compilador. Para formatos de
> arquivo e protocolos, máscaras explícitas são mais previsíveis.

> [!NOTE]
> **Pergunta para você:** partindo de `perm = 0`, qual a sequência mais
> curta de operações para chegar em `r-x`? E quanto vale `perm` se você fizer
> `perm ^= LER` duas vezes seguidas?

{{pratique}}
