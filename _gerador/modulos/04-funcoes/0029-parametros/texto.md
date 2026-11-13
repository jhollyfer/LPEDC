## 0029 · Parâmetros e passagem por valor

O assunto 0028 mostrou que a chamada leva um argumento até o parâmetro. Falta
saber o que exatamente viaja. A função recebe a própria variável de quem
chamou ou outra coisa? A resposta decide se uma função consegue mudar as
variáveis do `main`, e explica por que tantas funções "não funcionam" na
primeira tentativa.

Pense num boleto. Você fotografa o boleto e manda no grupo da família. Sua tia
rabisca "pago!" na foto. O boleto de papel, na sua gaveta, continua igual: ela
mexeu numa **cópia**. Toda chamada de função em C segue essa regra. Em
`reajustar(mensalidade, 10)`, o C calcula o valor de cada argumento e
**copia** esse valor para o parâmetro. Esse mecanismo é a **passagem por
valor**, e é a única forma de passagem que o C tem (DEITEL; DEITEL, 2011, cap.
5).

Os livros dão nomes às duas pontas da cópia (ROCHA; BORGES, s.d.). O
parâmetro escrito na definição, como o `mensalidade` de
`double reajustar(double mensalidade, double percentual)`, é o **parâmetro formal**.
O valor que aparece na chamada é o **argumento**, também chamado de
**parâmetro real**. Na prova, "formal" aponta para a definição e "real" para a
chamada.

O parâmetro formal é uma variável nova, **local** da função: nasce no momento
da chamada, já com a cópia dentro, e some quando a função termina (BACKES,
2013, cap. 9). A função pode mudá-lo à vontade. A variável de quem chamou fica
intacta, mesmo que as duas tenham o mesmo nome. São duas caixinhas em lugares
diferentes da memória, e o nome igual é coincidência.

Uma consequência ajuda a fixar a ideia: a função recebe **só o número**. As
chamadas `reajustar(mensalidade, 10)`, `reajustar(120.00, 10)` e
`reajustar(100 + 20, 5 * 2)` são idênticas para ela, porque em todas chega
120.00 e chega 10. Ela não sabe de onde o valor veio, então não tem como
alterar a variável original.

Se a função não mexe nas variáveis de quem chama, o resultado volta pelo
`return`, e quem chama precisa **guardá-lo**: `mensalidade = reajustar(...)`
(KERNIGHAN; RITCHIE, 1989, cap. 4). Ignorar o retorno é permitido; você faz
isso o tempo todo com o `printf`, que devolve quantos caracteres escreveu. Mas
um cálculo cujo retorno ninguém guarda é perdido.

A cópia também converte o tipo quando preciso. Se o argumento não for do tipo
do parâmetro, o C o converte como faria numa atribuição (KERNIGHAN; RITCHIE,
1989, cap. 4). Passar `2.9` para um parâmetro `int` entrega `2`: a parte
decimal some, e o `-Wall` não avisa. O protótipo é o que permite essa
conversão, porque é ele que diz ao compilador o tipo de cada parâmetro.

E a passagem **por referência**, que os livros de algoritmos citam? Nela a
função recebe a variável original e pode alterá-la. O C não tem esse
mecanismo, mas o simula: em vez do valor, você passa o **endereço** da
variável, e a função usa o endereço para chegar até ela (DEITEL; DEITEL, 2011,
cap. 5). O `&` do `scanf` faz exatamente isso. O assunto 0046 mostra como.

Por fim, uma função sem parâmetros. Escreva `void linha(void)`: o `void` entre
parênteses diz "não aceito argumento nenhum", e `linha(5)` vira erro. Já
`void linha()`, com parênteses vazios, no C17 quer dizer "não vou conferir os
argumentos", e `linha(5)` compila calado (BACKES, 2013, cap. 9). Use sempre
`(void)`.

> [!WARNING]
> A função que "deveria" mudar a variável e não muda. Em
> `void trocar(int a, int b)`, a troca ocorre entre as cópias e nada muda no
> `main`. Para a função mexer numa variável sua, passe o **endereço** dela (o
> `&` do `scanf`, assunto 0046).

{{exemplo}}

A academia reajusta a mensalidade de R$ 120,00 em 10%. Há duas `mensalidade`
na memória, a do `main` e a cópia da função, e só a cópia vira 132.00:

{{ideia}}

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

O valor sai por cópia e só volta pelo `return`; guardar ou não o retorno
decide se o `main` fica sabendo:

{{fluxograma}}
