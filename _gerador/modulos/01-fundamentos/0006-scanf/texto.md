## 0006 · scanf

- **`scanf`**: lê do teclado. O formato diz o que esperar e os outros
  argumentos dizem **onde guardar** (BACKES, 2013, cap. 2).

```c
scanf("%d", &dia);
```

- **`&`**: dá o **endereço** da variável, os bytes onde o `scanf` escreve. Vai
  em toda variável simples no `scanf` e nunca no `printf`
  (DEITEL; DEITEL, 2011, cap. 9).
- **`%lf` para `double`**: no `scanf`, `%lf` escreve 8 bytes e `%f` escreve 4,
  no formato de `float`. No `printf` os dois servem, porque lá vai o valor, e
  aqui vai o endereço (DEITEL; DEITEL, 2011).
- **Buffer**: o que você digita entra numa fila e só chega ao programa no
  Enter. `%d` e `%lf` pulam espaços e Enters antes do número e param no
  primeiro caractere inválido. O resto **fica na fila**, inclusive o `'\n'`
  (KERRISK, s.d.).
- **Caracteres no formato** precisam aparecer na entrada:
  `scanf("%d/%d/%d", &d, &m, &a)` lê `7/9/2026` (BACKES, 2013, cap. 2).
- **Retorno**: quantos itens guardou; 0 se o primeiro já falhou; `EOF` (-1)
  se a entrada acabou. O `if` do módulo 02 usa esse número
  (DEITEL; DEITEL, 2011, cap. 9).

| Tipo | Lê com | Mostra com |
| --- | --- | --- |
| `int` | `%d` | `%d` |
| `float` | `%f` | `%f` |
| `double` | `%lf` | `%f` |
| `char` | `%c` (ou `" %c"`) | `%c` |

> [!WARNING]
> Sem o `&`, `scanf("%d", dia)` usa o lixo de `dia` como endereço e escreve
> num lugar qualquer: `Segmentation fault` ou outra variável estragada. O gcc
> avisa (`expects argument of type 'int *'`). Ler `double` com `%f` também
> compila e dá número errado.

{{exemplo}}

Um Pix agendado: você digita `150.75`, Enter, `12`, Enter. O `%lf` tira
`150.75` da fila, o `%d` pula o `'\n'` que sobrou e tira o `12`; o último
`'\n'` fica na fila:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double valor;
    int dia;

    printf("Valor do Pix: R$ ");
    scanf("%lf", &valor);            // %lf: double no scanf
    printf("Dia do mês: ");
    int lidos = scanf("%d", &dia);   // devolve quantos itens leu

    printf("Pix de R$ %.2f agendado para o dia %d\n", valor, dia);
    printf("O último scanf leu %d item\n", lidos);
    return 0;
}
// Exemplo de execução:
// Valor do Pix: R$ 150.75
// Dia do mês: 12
// Pix de R$ 150.75 agendado para o dia 12
// O último scanf leu 1 item
```

Para testar sem digitar: `printf '150.75\n12\n' | ./pix`. As duas leituras
são paralelogramos de entrada, e a saída vem depois:

{{fluxograma}}
