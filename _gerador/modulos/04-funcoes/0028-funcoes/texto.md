## 0028 · Funções

O app de corrida mostra o preço antes de você confirmar: R$ 5,00 de bandeirada
mais R$ 2,50 por quilômetro. Ninguém escreveu a fórmula mil vezes: escreveu
**uma vez**, deu um nome e chama quando precisa.

Isso é uma **função**: um pedaço de código com nome, que recebe dados, faz uma
tarefa e devolve um resultado. Você já usa funções (`printf`, `scanf`, `sqrt`),
escritas por outras pessoas. Agora escreve as suas.

A forma geral em C:

```c
tipo_de_retorno nome(tipo parametro1, tipo parametro2) {
    // corpo
    return valor;
}
```

- o **tipo de retorno** diz o que a função devolve (`int`, `double`...). Se
  não devolve nada, é `void`;
- os **parâmetros** são as variáveis que recebem os dados de quem chama, cada
  uma com seu tipo: `double a, double b`, nunca `double a, b`;
- o **`return`** devolve o valor e **encerra a função na hora**. O que vem
  depois, naquele caminho, não roda.

Termos dos livros e da prova: toda função é uma **sub-rotina** (ou
subprograma). A que devolve valor é a **função**; a `void`, que só executa uma
tarefa, é o **procedimento**. No C as duas se escrevem igual. Dividir o
programa em sub-rotinas é a **modularização**.

O compilador lê o arquivo **de cima para baixo**, uma vez. Se o `main` chama
`preco_corrida` antes de ele ver a função, não sabe o tipo de retorno nem os
parâmetros. A solução é o **protótipo**: o cabeçalho da função com `;` no fim,
antes do `main`. É uma promessa: "essa função existe, recebe um `double` e
devolve um `double`; a definição vem depois".

Quando o `main` chama `preco_corrida(4.0)`, o 4.0 é copiado para o parâmetro
`km`, a função calcula `5.00 + 2.50 * 4.0`, devolve 15.00, e o `main` continua
de onde parou, com o resultado:

{{ideia}}

O app em C, com as três corridas:

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

A chamada é um desvio: o programa sai do `main`, executa o corpo da função e
**volta ao mesmo ponto**, trazendo o valor. Isso se repete a cada corrida:

{{fluxograma}}

Três termos: a **definição** é o corpo inteiro
(`double preco_corrida(double km) { ... }`); a **chamada** é o uso
(`preco_corrida(4.0)`); o **protótipo** é só o cabeçalho com `;`. O valor
passado na chamada (`4.0`) é o **argumento**; a variável que o recebe (`km`) é
o **parâmetro**.

Uma função boa faz **uma** tarefa, e o nome diz qual. Se não acha um nome
curto, ela faz coisas demais: quebre em duas. `preco_corrida` não usa
`printf`: quem mostra o resultado é o `main`. Assim a função serve para a tela,
para um arquivo ou para outra conta.

> [!WARNING]
> Chamar a função antes de ela aparecer no arquivo, sem protótipo. O gcc 13
> avisa `implicit declaration of function 'preco_corrida'`, e o gcc 14 recusa
> compilar. No C antigo, o compilador **supunha** retorno `int`, e o `double`
> voltava como lixo. Outro erro clássico: esquecer o `return` numa função que
> não é `void`. O `-Wall` avisa `control reaches end of non-void function`, e
> quem chamou recebe um valor qualquer.

> [!NOTE]
> **Pergunta para você:** o que mostra
> `printf("%.2f\n", preco_corrida(preco_corrida(0.0)));`? Resolva de dentro
> para fora, antes de rodar.

{{pratique}}
