## 0006 · scanf

Até aqui os programas só falavam: todo valor estava escrito no código. Um
programa útil também precisa **ouvir**. No modelo entrada → processamento →
saída, falta a entrada, e a forma mais simples de entrada é o teclado. Quem
faz esse papel no C é o `scanf`, o espelho do `printf`.

Pense no app do banco quando você agenda um Pix. Ele pergunta o valor, você
digita R$ 150,75; pergunta o dia, você digita 12. O app pega o que você
digitou e guarda cada coisa no seu campo. O **`scanf`** faz o mesmo: o
primeiro argumento, o formato, diz o que esperar, e os argumentos seguintes
dizem **onde guardar** cada valor lido (BACKES, 2013, cap. 2).

```c
scanf("%d", &dia);
```

O `&` antes do nome é a peça nova. Ele dá o **endereço** da variável, o
lugar exato da memória em que ela mora (0002). O `scanf` não quer o valor
de `dia`, que ainda é lixo; quer saber em que bytes escrever o número
digitado. Por isso o `&` vai em toda variável simples no `scanf` e nunca no
`printf`, que só precisa do valor para mostrar (DEITEL; DEITEL, 2011,
cap. 9).

Os especificadores quase repetem os do `printf`, com uma diferença que pega
muita gente: o `double` se lê com **`%lf`** e se mostra com `%f`. O motivo
está no endereço. Com `%lf`, o `scanf` escreve 8 bytes, no formato de
`double`; com `%f`, escreve só 4, no formato de `float`, e o `double` fica
com um número sem sentido. No `printf` os dois servem porque ele recebe o
valor, e todo `float` vira `double` no caminho; endereço não se converte
(DEITEL; DEITEL, 2011).

| Tipo | Lê com | Mostra com |
| --- | --- | --- |
| `int` | `%d` | `%d` |
| `float` | `%f` | `%f` |
| `double` | `%lf` | `%f` |
| `char` | `%c` (ou `" %c"`) | `%c` |

O que você digita não vai direto para a variável. Os caracteres entram
numa fila, o **buffer**, e só chegam ao programa quando você aperta Enter.
O `scanf` tira da fila apenas o que o formato pede. O `%d` e o `%lf` pulam
espaços e Enters antes do número e param no primeiro caractere que não
serve; o resto **fica na fila** para a próxima leitura, inclusive o `'\n'`
do Enter (KERRISK, s.d.). Digitando `150.75`, Enter, `12`, Enter, o `%lf`
tira `150.75`, o `%d` pula o `'\n'` que sobrou e tira o `12`, e o último
`'\n'` continua lá. O `%c` não pula nada e leria esse `'\n'`; o espaço em
`" %c"` manda pular os brancos antes.

O formato também pode ter caracteres comuns, e eles precisam aparecer na
entrada exatamente como estão. Com `scanf("%d/%d/%d", &d, &m, &a)`, você
digita `7/9/2026`, e o `scanf` lê um número, consome a barra, lê outro
número e assim por diante (BACKES, 2013, cap. 2).

Por fim, o `scanf` **devolve** um número: quantos itens ele conseguiu
guardar. Se tudo deu certo na data acima, devolve 3. Se o primeiro valor já
falhou, como `doze` no lugar de `12`, devolve 0 e a variável fica como
estava. Se a entrada acabou, devolve `EOF`, que vale -1 (DEITEL; DEITEL,
2011, cap. 9). É assim que o programa descobre se a leitura funcionou; no
módulo 02, o `if` vai usar esse número para decidir o que fazer.

> [!WARNING]
> Sem o `&`, `scanf("%d", dia)` usa o lixo de `dia` como endereço e escreve
> num lugar qualquer: `Segmentation fault` ou outra variável estragada. O
> gcc avisa (`expects argument of type 'int *'`). Ler `double` com `%f`
> também compila e dá número errado.

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
