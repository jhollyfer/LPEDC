## 0171 · Com sinal e sem sinal

- **Com sinal** (`int`, `signed char`, `long`): guarda negativos; num `int` de
  32 bits, de -2147483648 a 2147483647 (BACKES, 2013).
- **Sem sinal** (`unsigned`, `unsigned char`, `size_t`): vai de 0 a
  4294967295 (`UINT_MAX`). `sizeof` e `strlen` devolvem `size_t`
  (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Volta do sem sinal**: a conta é módulo 2³², como um odômetro. `2u - 3u` é
  4294967295 e `UINT_MAX + 1u` é 0. Estourar um `int` com sinal é
  comportamento indefinido (ISO/IEC, 2018).
- **Complemento de dois**: o -1 de um `int` são 32 bits ligados, que lidos como
  `unsigned` valem 4294967295 (DEITEL; DEITEL, 2011, apêndice D).
- **Promoção inteira**: `char`, `short`, `unsigned char`, `bool` e `enum`
  viram `int` antes da conta. `unsigned char` 200 + 100 dá 300 (ISO/IEC, 2018).
- **Conversão aritmética usual**: os operandos viram o tipo "maior". Entre
  `int` e `unsigned` do mesmo tamanho, ganha o `unsigned`; se o com sinal for
  maior e couber o sem sinal todo (`long` de 64 contra `unsigned` de 32), ganha
  o com sinal (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Bits e máscaras**: use `unsigned`; deslocar negativo é indefinido ou
  depende da implementação (DEITEL; DEITEL, 2011, cap. 10).

| Expressão | Resultado | Por quê |
| --- | --- | --- |
| `-1 > 0u` | verdadeiro | o `-1` vira 4294967295 |
| `-1L < 1u` | verdadeiro (Linux 64 bits) | o `unsigned` cabe no `long` |
| `2u - 3u` | 4294967295 | volta módulo 2³² |

> [!WARNING]
> `for (size_t i = n - 1; i >= 0; i--)` nunca termina: o `size_t` passa de 0
> para 18446744073709551615. Escreva `for (size_t i = n; i-- > 0;)`. E
> `strlen(a) - strlen(b) > 0` é verdadeiro sempre que os tamanhos diferem.

{{exemplo}}

Uma loja vendeu 3 fones de um estoque `unsigned` de 2. O desenho mostra os 4
bytes do saldo -1 e as duas leituras; a comparação com `0u` usa a sem sinal:

{{ideia}}

```c
#include <limits.h>
#include <stdio.h>

int main(void) {
    unsigned estoque = 2;  // 2 fones na prateleira
    estoque = estoque - 3; // vendeu 3: unsigned não tem negativo, dá a volta
    printf("estoque = %u (UINT_MAX = %u)\n", estoque, UINT_MAX);

    int saldo = -1;        // R$ -1 na conta
    unsigned zero = 0u;
    // saldo > zero misturaria int e unsigned: o int viraria unsigned.
    // O gcc avisa (-Wsign-compare); aqui a conversão vai escrita, à vista
    printf("(unsigned)saldo = %u\n", (unsigned)saldo);
    printf("-1 > 0u? %s\n", (unsigned)saldo > zero ? "sim" : "não");
    printf("-1 > 0?  %s\n", saldo > 0 ? "sim" : "não");

    unsigned char a = 200, b = 100; // dois bytes de 0 a 255
    printf("a + b = %d\n", a + b);  // promoção: os dois viram int antes da soma
    unsigned char c = a + b;        // guardar num byte corta: 300 - 256
    printf("c = %d\n", c);
    return 0;
}
// Saída:
// estoque = 4294967295 (UINT_MAX = 4294967295)
// (unsigned)saldo = 4294967295
// -1 > 0u? sim
// -1 > 0?  não
// a + b = 300
// c = 44
```

No fluxograma, a pergunta real é sobre 4294967295:

{{fluxograma}}
