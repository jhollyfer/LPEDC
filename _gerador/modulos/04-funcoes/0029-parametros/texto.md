## 0029 · Parâmetros e passagem por valor

Você fotografa o boleto e manda no grupo da família. Sua tia rabisca "pago!" na
foto. O boleto de papel, na sua gaveta, continua igual: ela mexeu numa
**cópia**.

Toda chamada de função em C funciona assim. Em `reajustar(mensalidade, 10)`, o
C **calcula o valor** de cada argumento e **copia** esse valor para o
parâmetro. O parâmetro da definição é o **parâmetro formal**; o valor da
chamada é o **argumento** (ou parâmetro real). Isso é a **passagem por valor**,
a única do C: a passagem **por referência** dos livros se faz passando um
endereço (assunto 0046). O parâmetro é uma variável nova, local da função, que
nasce com a cópia. A função pode mudá-lo à vontade: a variável de quem chamou
não é afetada.

A função recebe **só o número**. `reajustar(mensalidade, 10)`,
`reajustar(120.00, 10)` e `reajustar(100 + 20, 5 * 2)` são idênticas para ela:
chega 120.00 e chega 10. Ela não sabe de onde o valor veio e não tem como
alterar a variável original.

Para mandar um resultado de volta, use o `return`, e quem chamou tem que
**guardar** o retorno: `mensalidade = reajustar(...)`. Ignorar o retorno é
permitido (você faz isso com o `printf`, que devolve quantos caracteres
escreveu), mas o resultado se perde.

No exemplo, a academia reajusta a mensalidade de R$ 120,00 em 10%. Há duas
caixinhas chamadas `mensalidade`, em lugares diferentes da memória: a do
`main` e a cópia da função. A função muda só a dela para 132.00:

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

O valor sai do `main` por cópia e só volta pelo `return`. A pergunta "guardou
o retorno?" decide se o `main` fica sabendo do reajuste:

{{fluxograma}}

Mais três regras sobre parâmetros:

- **conversão automática**: se o tipo do argumento não bate, o C converte para
  o do parâmetro, como numa atribuição. Um `int` vira `double` sem problema;
  um `2.9` passado a um `int` vira `2`, sem aviso;
- **`void` na lista**: `void linha(void)` diz "não recebe nada", e `linha(5)`
  é erro de compilação. Já `void linha()`, no C17, quer dizer "não declaro o
  que recebe": o compilador aceita `linha(5)` calado. Escreva sempre `(void)`.
  (No C23 os dois são iguais, mas há muito código C17.)
- **um tipo por parâmetro** (`double total, int vezes`), e a ordem importa: o
  primeiro argumento vai para o primeiro parâmetro.

> [!WARNING]
> A função que "deveria" mudar a variável e não muda. Em
> `void trocar(int a, int b)`, a troca ocorre entre as cópias e nada acontece
> no `main`. Do mesmo modo, `void f(int n) { n++; }` não muda o seu `n`. Para a
> função mexer numa variável sua, passe o **endereço** dela. É o que o `&` do
> `scanf` faz, e o assunto 0046 explica.

> [!NOTE]
> **Pergunta para você:** se você trocar o nome do parâmetro de `mensalidade`
> para `valor` (e ajustar o corpo da função), alguma linha da saída muda? Por
> quê?

{{pratique}}
