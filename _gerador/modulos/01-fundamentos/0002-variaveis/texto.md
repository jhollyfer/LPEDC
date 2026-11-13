## 0002 · Variáveis

O primeiro programa só mostrava texto fixo. Para fazer conta, o programa
precisa guardar números em algum lugar enquanto trabalha: a idade de alguém,
o preço de um produto, o total de uma compra. Esse lugar é a memória do
computador, e a variável é a forma de usar um pedaço dela pelo nome.

Pense na ficha de matrícula de uma academia. Ela tem campos com rótulo
(idade, altura, peso, plano), e cada campo aceita um tipo de informação. Um
mês depois, a recepcionista apaga o peso e escreve o novo. A ficha continua
a mesma; só o conteúdo de um campo mudou. Uma **variável** é um campo dessa
ficha: um lugar na memória com **nome**, **tipo** e **valor**, e esse valor
pode mudar durante a execução (DEITEL; DEITEL, 2011, cap. 2).

O nome é para você, que escreve e lê o código. A máquina usa outra coisa: o
**endereço**, o número do primeiro byte que o valor ocupa na memória. Você
vê o endereço de uma variável com `&`, e o `printf` o mostra com `%p`. Por
enquanto o endereço é só curiosidade; no módulo de ponteiros ele vira
ferramenta.

O **tipo** diz quantos bytes a variável ocupa e como ler esses bytes
(BACKES, 2013). Ele vem antes do nome e não muda depois. Os mesmos quatro
bytes podem ser lidos como um inteiro ou como um real, e o resultado é
completamente diferente; o tipo é que decide. A tabela mostra os quatro
tipos básicos, com os tamanhos de um PC de 64 bits (o padrão do C só garante
mínimos, assunto do 0003):

| Tipo | Guarda | Tamanho típico | `printf` |
| --- | --- | --- | --- |
| `int` | inteiro | 4 bytes | `%d` |
| `float` | real, uns 7 dígitos | 4 bytes | `%f` |
| `double` | real, uns 15 dígitos | 8 bytes | `%f` |
| `char` | um caractere | 1 byte | `%c` |

Esses são os **tipos primitivos**, também chamados de tipos simples: cada
variável guarda um valor só. Vetores e structs juntam vários valores numa
variável e são os tipos **compostos**, que aparecem nos módulos 05 e 08
(CELES; CERQUEIRA; RANGEL, 2016). Repare que o `char` também guarda um
número, pequeno: a letra `'B'` fica na memória como o código 66.

Criar a variável é **declarar**: `int idade;` reserva quatro bytes e dá a
eles o nome `idade`. Dar o primeiro valor no mesmo comando é
**inicializar**: `int idade = 25;` (BACKES, 2013). As duas coisas parecem
iguais, mas não são. Uma variável declarada sem valor fica com o que já
estava naqueles bytes, e isso pode ser qualquer número.

```c
int idade = 25;        // declara e inicializa
double peso = 72.5;    // o decimal do C é o ponto
peso = 71.8;           // atribui: o 72.5 some
```

**Atribuir** é guardar um valor novo, com `=`, numa variável que já existe.
O valor antigo é apagado para sempre; não há histórico. Ler a variável, por
outro lado, não muda nada: você pode mostrar `peso` mil vezes e ele continua
71.8 (DEITEL; DEITEL, 2011, cap. 2).

Para saber quanto cada tipo ocupa na sua máquina, existe o operador
**`sizeof`**. Ele dá o tamanho em bytes de um tipo ou de uma variável:
`sizeof(double)` vale 8 num PC comum. O resultado tem um tipo próprio, e o
`printf` o mostra com `%zu` (KERNIGHAN; RITCHIE, 1988, cap. 2).

O nome da variável segue regras. Ele usa letras, dígitos e `_`, não começa
por dígito e não leva acento nem espaço. Palavras do próprio C, como `int`
e `return`, são reservadas e não servem de nome. E maiúscula conta: `peso`
e `Peso` são duas variáveis diferentes (KERNIGHAN; RITCHIE, 1988, cap. 2).
O curso usa `snake_case`, palavras em minúscula ligadas por `_`:
`peso_atual`, `valor_total`.

> [!WARNING]
> Variável sem valor não vale zero: vale **lixo**, o que já estava na
> memória. `int total; printf("%d", total);` pode mostrar 0, 32767 ou -1294,
> e o gcc avisa `'total' is used uninitialized`. Inicialize sempre. E o
> decimal do C é o **ponto**: `72,5` nem compila.

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
