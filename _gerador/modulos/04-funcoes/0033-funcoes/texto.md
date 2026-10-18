## 0033 · Funções

Você abre o app de corrida e ele mostra o preço antes de você confirmar: R$
5,00 de bandeirada mais R$ 2,50 por quilômetro. O app faz essa conta para
cada corrida pedida, o dia inteiro. Ninguém escreveu a fórmula mil vezes:
escreveu **uma vez**, deu um nome, e chama sempre que precisa.

Isso é uma **função**: um pedaço de código com nome, que recebe dados, faz uma
tarefa e devolve um resultado. Você já usa funções desde o primeiro dia:
`printf`, `scanf` e `sqrt` foram escritas por outra pessoa. Agora você escreve
as suas.

A forma geral em C:

```c
tipo_de_retorno nome(tipo parametro1, tipo parametro2) {
    // corpo
    return valor;
}
```

- o **tipo de retorno** diz o que a função devolve (`int`, `double`...). Se
  ela não devolve nada, o tipo é `void`;
- os **parâmetros** são as variáveis que recebem os dados de quem chama. Cada
  um com o seu tipo: `double a, double b`, nunca `double a, b`;
- o **`return`** devolve o valor e **encerra a função na hora**. O que vem
  depois dele, naquele caminho, não roda.

No TypeScript seria `function precoCorrida(km: number): number { ... }`. A
ideia é a mesma, mas no C o tipo vem antes do nome e é obrigatório.

Tem um detalhe que o JS não tem: o compilador do C lê o arquivo **de cima para
baixo**, uma vez só. Se o `main` chama `preco_corrida` antes de o compilador
ter visto essa função, ele não sabe que tipo ela devolve nem quantos
parâmetros recebe. A solução é o **protótipo**: o cabeçalho da função com `;`
no fim, colocado antes do `main`. É uma promessa: "essa função existe, recebe
um `double` e devolve um `double`; a definição vem depois".

Vamos ver na prática. O `main` chama `preco_corrida(4.0)`: o valor 4.0 é
copiado para o parâmetro `km`, a função calcula `5.00 + 2.50 * 4.0`, devolve
15.00, e o `main` continua de onde parou, já com o resultado na mão:

{{ideia}}

O mesmo exemplo em C, com as três corridas:

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

Repara no fluxograma: a chamada é um desvio. O programa sai do `main`, executa
o corpo da função e **volta para o mesmo ponto**, trazendo o valor. Isso se
repete a cada corrida:

{{fluxograma}}

Três vocabulários que você vai ver o tempo todo: a **definição** é o corpo
inteiro (`double preco_corrida(double km) { ... }`); a **chamada** é o uso
(`preco_corrida(4.0)`); o **protótipo** é só o cabeçalho com `;`. O valor que
você passa na chamada (`4.0`) se chama **argumento**; a variável que o recebe
(`km`) é o **parâmetro**.

Uma função boa faz **uma** tarefa, e o nome diz qual. Se você não acha um nome
curto, ela está fazendo coisas demais: quebre em duas. E repare que
`preco_corrida` não usa `printf`. Quem mostra o resultado é o `main`. Uma
função que só calcula serve para a tela, para um arquivo ou para outra conta.

> [!WARNING]
> Chamar a função antes de ela aparecer no arquivo, sem protótipo. O gcc 13
> avisa `implicit declaration of function 'preco_corrida'`, e o gcc 14 já
> recusa compilar. No C antigo, o compilador **inventava** que a função
> devolvia `int`: o `double` voltava como lixo. Outro erro clássico é
> esquecer o `return` numa função que não é `void`: o `-Wall` avisa
> `control reaches end of non-void function`, e quem chamou recebe um valor
> qualquer. Leve os dois avisos a sério.

> [!TIP]
> **Por dentro do C:** o código de `preco_corrida` existe **uma vez só** na
> memória, não importa quantas vezes você chama. A chamada vira a instrução
> `call` do processador, que guarda o endereço de volta e pula para a função;
> o `return` vira `ret`, que pula de volta. No Linux de 64 bits, o argumento
> `double` vai num registrador do processador (`xmm0`) e o resultado volta
> pelo mesmo registrador. Rode `gcc -S A065.c` e procure `call preco_corrida`
> no arquivo `A065.s`.

> [!NOTE]
> **Pergunta para você:** o que mostra
> `printf("%.2f\n", preco_corrida(preco_corrida(0.0)));`? Resolva de dentro
> para fora, antes de rodar.

{{pratique}}
