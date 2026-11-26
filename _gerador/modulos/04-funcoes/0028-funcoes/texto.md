## 0028 · Funções

O app de corrida mostra o preço antes de você confirmar: R$ 5,00 de bandeirada
mais R$ 2,50 por quilômetro. Essa conta aparece na tela de estimativa, no
recibo e no histórico. Se cada lugar tivesse a fórmula copiada, uma mudança na
tarifa exigiria caçar todas as cópias, e bastaria esquecer uma para o recibo
discordar da estimativa. Ninguém escreveu a fórmula três vezes: escreveu
**uma vez**, deu um nome e chama quando precisa.

Esse pedaço de código com nome é uma **função**: um bloco que recebe dados,
faz uma tarefa e devolve um resultado, escrito uma vez e chamado quantas vezes
for preciso (DEITEL; DEITEL, 2011, cap. 5). Pense numa receita de bolo no
caderno. Você não reescreve a receita a cada festa; abre na página certa,
separa os ingredientes daquele dia e segue os passos. Você já usa funções
escritas por outras pessoas, como `printf`, `scanf` e `sqrt`. Agora vai
escrever as suas. A forma geral em C é esta:

```c
tipo_de_retorno nome(tipo parametro1, tipo parametro2) {
    // corpo
    return valor;
}
```

Cada parte tem um papel (BACKES, 2013, cap. 9). O **tipo de retorno** diz o
que a função devolve: `int`, `double`, e assim por diante. Se ela não devolve
nada, o tipo é `void` ("vazio"). Os **parâmetros**, entre parênteses, são as
variáveis que recebem os dados de quem chama, os ingredientes da receita.
Cada um leva o próprio tipo: `double a, double b`, nunca `double a, b`, que é
erro de compilação. O **corpo**, entre chaves, é a tarefa.

O **`return`** faz duas coisas ao mesmo tempo: devolve o valor para quem
chamou e **encerra a função na hora** (KERNIGHAN; RITCHIE, 1989, cap. 4). O
que vem depois dele, naquele caminho, não roda. Por isso uma função pode ter
vários `return`, um em cada ramo de um `if`, e o primeiro que for alcançado
decide o resultado.

Alguns nomes ajudam a falar de funções sem confusão. A **definição** é a função
inteira, cabeçalho e corpo. A **chamada** é o uso, como `preco_corrida(4.0)`.
Na chamada, o valor entre parênteses, o `4.0`, é o **argumento**; a variável
da definição que o recebe, o `km`, é o **parâmetro** (DEITEL; DEITEL, 2011,
cap. 5). Na chamada, o programa pula para o corpo da função, roda até o
`return` e volta ao ponto de onde saiu, trazendo o resultado.

Os livros e a prova usam outros termos (ROCHA; BORGES, s.d.). Toda função é
uma **sub-rotina**, ou subprograma. A que devolve valor se chama **função**;
a que só executa uma tarefa e não devolve nada se chama **procedimento**. Em C
as duas se escrevem do mesmo jeito, e o procedimento é a função `void`.
Dividir um programa em sub-rotinas, cada uma com sua tarefa, é a
**modularização**.

Falta um detalhe de ordem. O compilador lê o arquivo **de cima para baixo**,
uma vez só. Se o `main` chama `preco_corrida` antes de a definição aparecer,
o compilador ainda não sabe o tipo de retorno nem os parâmetros. A solução é o
**protótipo**: o cabeçalho da função terminado em `;`, posto antes do `main`
(ROCHA; BORGES, s.d.). Ele funciona como uma promessa: "essa função existe,
recebe um `double` e devolve um `double`; a definição vem depois". Com ele, o
compilador confere o tipo e a quantidade de argumentos de cada chamada.

Uma boa função faz **uma tarefa só** (DEITEL; DEITEL, 2011, cap. 5). Se você
não acha um nome curto para ela, provavelmente faz coisas demais e pede para
ser dividida. Pelo mesmo motivo, a função de cálculo recebe os dados por
parâmetro e devolve pelo `return`; ler do teclado e mostrar na tela fica com
quem chama. Assim a mesma `preco_corrida` serve para a estimativa e para o
recibo.

> [!WARNING]
> Chamar a função antes de ela aparecer no arquivo, sem protótipo: o gcc 14
> recusa compilar (`implicit declaration`). E esquecer o `return` numa função
> que não é `void`: o `-Wall` avisa `control reaches end of non-void function`,
> e quem chamou recebe lixo.

{{exemplo}}

O app de corrida cobra R$ 5,00 de bandeirada mais R$ 2,50 por km. O `main`
chama `preco_corrida(4.0)`, o 4.0 vai para `km`, e o 15.00 volta:

{{ideia}}

```c
#include <stdio.h>

// protótipo: avisa o compilador que a função existe e como chamá-la
double preco_corrida(double km);

int main(void) {
    printf("Corrida 1: R$ %.2f\n", preco_corrida(4.0));
    printf("Corrida 2: R$ %.2f\n", preco_corrida(10.0));
    printf("Corrida 3: R$ %.2f\n", preco_corrida(2.5));
    return 0;
}

// definição: bandeirada de R$ 5.00 mais R$ 2.50 por km
double preco_corrida(double km) {
    double preco = 5.00 + 2.50 * km;
    return preco; // devolve o valor para quem chamou
}
// Saída:
// Corrida 1: R$ 15.00
// Corrida 2: R$ 30.00
// Corrida 3: R$ 11.25
```

A chamada é um desvio: sai do `main`, roda a função e volta ao mesmo ponto
com o valor, uma vez por corrida:

{{fluxograma}}
