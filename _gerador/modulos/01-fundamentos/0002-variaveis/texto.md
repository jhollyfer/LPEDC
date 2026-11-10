## 0002 · Variáveis

Na matrícula da academia, a recepcionista preenche uma ficha: idade 25,
altura 1,75 m, peso 72,5 kg, plano B. Um mês depois, apaga o peso e escreve
71,8. A ficha é a mesma; só o conteúdo de um campo mudou.

Uma **variável** é um campo dessa ficha: um pedaço da memória com **nome**,
**tipo**, **valor** e **endereço**. O nome é para você. O endereço é o número
do primeiro byte que o valor ocupa. O tipo diz quantos bytes a variável ocupa
e como lê-los.

O tipo vem **antes** do nome e não muda. Os quatro tipos básicos (tamanhos de
um PC de 64 bits; o padrão do C só garante mínimos):

| Tipo | Guarda | Tamanho típico | Exemplo |
| --- | --- | --- | --- |
| `int` | inteiro | 4 bytes | `int idade = 25;` |
| `float` | real, uns 7 dígitos | 4 bytes | `float altura = 1.75;` |
| `double` | real, uns 15 dígitos | 8 bytes | `double peso = 72.5;` |
| `char` | um caractere (um número pequeno) | 1 byte | `char plano = 'B';` |

Esses são os **tipos primitivos** (também chamados **tipos simples** ou
**dados simples**): cada variável guarda um valor só. Vetores e structs, que
juntam vários valores, são os **dados compostos** (módulos 05 e 08).

**Declarar** é criar a variável: `int idade;`. **Inicializar** é dar o
primeiro valor junto: `int idade = 25;`. O `printf` usa `%d` para `int`, `%f`
para `float` e `double`, `%c` para `char`; `%.1f` limita a uma casa decimal
(o `printf` completo vem no 0005).

Guardar um valor novo **apaga** o antigo; ler a variável não muda nada. O
operador **`sizeof`** dá o tamanho em bytes de um tipo ou variável; o
`printf` o mostra com `%zu`. O `&peso` é o endereço da variável (`%p`
mostra endereços).

Nome de variável: letras, dígitos e `_`, sem começar por dígito, sem acento e
sem espaço; `peso` e `Peso` são diferentes; palavras do C (`int`, `return`...)
não valem. O curso usa `snake_case`: `peso_atual`, `valor_total`.

A ficha vira quatro caixinhas, cada uma com tipo, tamanho e endereço. Depois,
o peso recebe um valor novo e o antigo desaparece:

{{ideia}}

A ficha em C:

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

Criar as variáveis (reservar memória) é um passo; trocar o peso é outro.
Ainda é sequência pura:

{{fluxograma}}

> [!WARNING]
> Variável sem valor não vale zero: vale **lixo**, o que já estava naqueles
> bytes. `int total; printf("%d", total);` pode mostrar 0, 32767 ou -1294; o
> gcc avisa `'total' is used uninitialized`. Inicialize sempre. E o separador
> decimal do C é o **ponto**: `double peso = 72,5;` nem compila.

> [!NOTE]
> **Pergunta para você:** o `char` guarda um número pequeno. O que você acha
> que `printf("%d\n", plano);` mostra? Teste no programa acima.

{{pratique}}
