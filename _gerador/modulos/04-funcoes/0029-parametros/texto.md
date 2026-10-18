## 0029 · Parâmetros e passagem por valor

Você tira foto do boleto e manda no grupo da família. Sua tia rabisca a foto,
escreve "pago!" em cima. O boleto de papel, na sua gaveta, continua igual: ela
mexeu numa **cópia**.

Em C, toda chamada de função funciona assim. Quando você escreve
`reajustar(mensalidade, 10)`, o C **calcula o valor** de cada argumento e
**copia** esse valor para o parâmetro. Isso se chama **passagem por valor**. O
parâmetro é uma variável nova, local da função, que nasce já com a cópia. A
função pode mudar o parâmetro à vontade: a variável de quem chamou nem fica
sabendo.

Repare que a função recebe **só o número**. Para ela, `reajustar(mensalidade,
10)`, `reajustar(120.00, 10)` e `reajustar(100 + 20, 5 * 2)` são idênticas: chega
120.00 e chega 10. Ela não sabe de onde o valor veio nem onde mora a variável
original. Por isso não tem como alterá-la.

Se a função precisa mandar um resultado de volta, o caminho é o `return`. E
quem chamou tem que **guardar** o retorno: `mensalidade = reajustar(...)`.
Chamar e ignorar o retorno é permitido (você faz isso com o `printf`, que
devolve quantos caracteres escreveu), mas aí o resultado se perde.

Vamos ver na prática. A academia reajusta a mensalidade de R$ 120,00 em 10%.
Há duas caixinhas chamadas `mensalidade`, em lugares diferentes da memória: a
do `main` e a cópia da função. A função muda só a dela para 132.00:

{{ideia}}

O código mostra as duas situações: primeiro ignorando o retorno, depois
guardando:

```c
#include <stdio.h>

double reajustar(double mensalidade, double percentual);

int main(void) {
    double mensalidade = 120.00;

    printf("Antes: %.2f\n", mensalidade);
    reajustar(mensalidade, 10); // o resultado é jogado fora
    printf("Depois: %.2f\n", mensalidade); // continua 120.00

    mensalidade = reajustar(mensalidade, 10); // agora guarda o retorno
    printf("Guardando o retorno: %.2f\n", mensalidade);
    return 0;
}

// mensalidade aqui é uma CÓPIA: outra variável, com o mesmo nome
double reajustar(double mensalidade, double percentual) {
    mensalidade = mensalidade * (1 + percentual / 100);
    printf("Dentro: %.2f\n", mensalidade);
    return mensalidade;
}
// Saída:
// Antes: 120.00
// Dentro: 132.00
// Depois: 120.00
// Dentro: 132.00
// Guardando o retorno: 132.00
```

Repara no fluxograma: o valor sai do `main` por cópia e só volta pelo
`return`. A pergunta "guardou o retorno?" decide se o `main` fica sabendo do
reajuste:

{{fluxograma}}

Mais três regras sobre parâmetros:

- **conversão automática**: se o tipo do argumento não bate, o C converte para
  o tipo do parâmetro, como numa atribuição. Um `int` vira `double` sem
  problema; um `2.9` passado para um `int` vira `2`, sem aviso;
- **`void` na lista**: `void linha(void)` diz "não recebe nada", e
  `linha(5)` vira erro de compilação. Já `void linha()`, com os parênteses
  vazios, no C17 quer dizer "não vou dizer o que recebe": o compilador aceita
  `linha(5)` calado. Escreva sempre `(void)`. (No C23 os dois viraram a mesma
  coisa, mas você vai ver muito código C17.)
- **um tipo por parâmetro**: `double total, int vezes`. E a ordem importa: o
  primeiro argumento vai para o primeiro parâmetro, sempre.

> [!WARNING]
> A função que "deveria" mudar a variável e não muda. O exemplo clássico é
> `void trocar(int a, int b)` que troca `a` e `b` lá dentro: no `main`, nada
> acontece, porque a troca foi entre as cópias. Do
> mesmo jeito, `void f(int n) { n++; }` não muda o seu `n`. No C, para a função
> mexer numa variável sua, você precisa passar o **endereço** dela. É o que o
> `&` do `scanf` faz, e você vai entender de vez no assunto 0046.

> [!TIP]
> **Por dentro do C:** a cópia é literal. O `main` põe o valor 120.00 num
> registrador (`xmm0`) e a função começa copiando esse registrador para o
> seu próprio espaço na memória, num endereço diferente do da variável do
> `main`. Copiar um `double` custa quase nada: são 8 bytes. Mais para a
> frente, quando você passar uma `struct` grande por valor, a cópia inteira
> vai acontecer a cada chamada, e aí vale a pena passar o endereço.

> [!NOTE]
> **Pergunta para você:** se você trocar o nome do parâmetro de `mensalidade`
> para `valor` (e ajustar o corpo da função), alguma linha da saída muda? Por
> quê?

{{pratique}}
