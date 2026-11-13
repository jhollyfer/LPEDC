## 0044 · Memória e endereços

- **Memória**: uma fileira de gavetas de **1 byte**, cada uma com um número, o
  **endereço** (FEOFILOFF, 2009, ap. D).
- **Endereço da variável**: o da primeira gaveta que ela ocupa. Cada tipo
  ocupa um número de gavetas (`char` 1, `int` 4, `double` 8) (BACKES, 2013,
  cap. 10).
- **Nome e endereço**: você usa o nome; o processador só conhece endereços, e
  o compilador troca um pelo outro (BACKES, 2013, cap. 10).
- **`&`** (endereço de): `&idade` pergunta "em que gaveta você mora?". É o `&`
  do `scanf`: ele precisa saber **onde** guardar (DEITEL; DEITEL, 2011,
  cap. 7).
- **`%p`**: mostra um endereço em hexadecimal; espera um `void *`, então
  escreva `(void *)&idade` (assunto 0051) (DEITEL; DEITEL, 2011, cap. 7).

> [!WARNING]
> Nunca mostre endereço com `%d` ou `%x`: são 8 bytes, e o `%d` lê 4. Use `%p`
> com `(void *)`. E não deduza nada da ordem de variáveis soltas: só num vetor
> a ordem é garantida.

{{exemplo}}

No cadastro da academia, a idade (`int`), a mensalidade (`double`) e o plano
(`char`) ganham gavetas. Os endereços do desenho são fictícios:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int idade = 30;
    double mensalidade = 119.90;
    char plano = 'B';

    // & pergunta "em que gaveta você mora?"; %p mostra a resposta em hexa
    printf("idade:       %d, mora em %p, ocupa %zu bytes\n",
           idade, (void *)&idade, sizeof idade);
    printf("mensalidade: %.2f, mora em %p, ocupa %zu bytes\n",
           mensalidade, (void *)&mensalidade, sizeof mensalidade);
    printf("plano:       %c, mora em %p, ocupa %zu byte\n",
           plano, (void *)&plano, sizeof plano);
    return 0;
}
// Saída (os endereços mudam a cada execução):
// idade:       30, mora em 0x7f0440e00030, ocupa 4 bytes
// mensalidade: 119.90, mora em 0x7f0440e00040, ocupa 8 bytes
// plano:       B, mora em 0x7f0440e00020, ocupa 1 byte
```

Rode duas vezes: valores e tamanhos se repetem, endereços não (o sistema
sorteia onde o programa mora). Para cada
variável, as mesmas três perguntas: o que tem dentro, onde mora e quanto ocupa:

{{fluxograma}}
