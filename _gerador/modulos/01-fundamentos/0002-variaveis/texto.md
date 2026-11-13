## 0002 · Variáveis

- **Variável**: um lugar na memória com **nome**, **tipo** e **valor**. O
  valor pode mudar durante a execução (DEITEL; DEITEL, 2011, cap. 2).
- **Tipo**: diz quantos bytes a variável ocupa e como ler esses bytes
  (BACKES, 2013).
- **Tipos primitivos**: guardam um valor só (`int`, `float`, `double`,
  `char`). Vetores e structs juntam vários e são **compostos** (módulos 05 e 08)
  (CELES; CERQUEIRA; RANGEL, 2016).
- **Declarar** é criar (`int idade;`); **inicializar** é dar o primeiro valor
  junto (`int idade = 25;`) (BACKES, 2013).
- **Atribuir apaga o valor antigo**; ler a variável não muda nada
  (DEITEL; DEITEL, 2011, cap. 2).
- **`sizeof`**: operador que dá o tamanho em bytes de um tipo ou variável;
  mostre com `%zu` (KERNIGHAN; RITCHIE, 1988, cap. 2).
- **Nome válido**: letras, dígitos e `_`, sem começar por dígito, sem acento e
  sem palavra reservada. `peso` e `Peso` são nomes diferentes
  (KERNIGHAN; RITCHIE, 1988, cap. 2).

| Tipo | Guarda | Tamanho típico | `printf` |
| --- | --- | --- | --- |
| `int` | inteiro | 4 bytes | `%d` |
| `float` | real, uns 7 dígitos | 4 bytes | `%f` |
| `double` | real, uns 15 dígitos | 8 bytes | `%f` |
| `char` | um caractere | 1 byte | `%c` |

> [!WARNING]
> Variável sem valor não vale zero: vale **lixo**, o que já estava na memória.
> Inicialize sempre. E o decimal do C é o **ponto**: `72,5` nem compila.

{{exemplo}}

A ficha de uma academia: idade, altura, peso e plano. Cada dado vira uma
caixinha com tipo, tamanho e endereço; depois o peso recebe um valor novo:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int idade = 25;       // inteiro
    float altura = 1.75;  // real com uns 7 dígitos
    double peso = 72.5;   // real com uns 15 dígitos
    char plano = 'B';     // um caractere, entre aspas simples

    printf("Idade: %d anos\n", idade);
    printf("Altura: %.2f m\n", altura);
    printf("Peso: %.1f kg\n", peso);
    printf("Plano: %c\n", plano);

    peso = 71.8; // um mês depois: o 72.5 some
    printf("Peso novo: %.1f kg\n", peso);
    printf("Bytes: %zu, %zu, %zu, %zu\n",
           sizeof idade, sizeof altura, sizeof peso, sizeof plano);
    return 0;
}
// Saída:
// Idade: 25 anos
// Altura: 1.75 m
// Peso: 72.5 kg
// Plano: B
// Peso novo: 71.8 kg
// Bytes: 4, 4, 8, 1
```

O caminho é sequência pura: criar as variáveis e depois trocar o peso.

{{fluxograma}}
