## 0028 · Funções

- **Função**: bloco de código com nome que recebe dados, faz uma tarefa e
  devolve um resultado. Escreve-se uma vez e chama-se quantas vezes precisar
  (DEITEL; DEITEL, 2011, cap. 5).
- **Partes**: o **tipo de retorno** (`void` se não devolve nada), os
  **parâmetros**, cada um com seu tipo (`double a, double b`, nunca
  `double a, b`), e o corpo (BACKES, 2013, cap. 9).
- **`return`**: devolve o valor e encerra a função na hora; o que vem depois,
  naquele caminho, não roda (KERNIGHAN; RITCHIE, 1989, cap. 4).
- **Função e procedimento**: em C tudo é função; a `void` faz o papel do
  **procedimento** dos livros. Dividir o programa em funções é a
  **modularização** (ROCHA; BORGES, s.d.).
- **Definição, chamada e protótipo**: a definição é o corpo inteiro; a chamada
  é o uso (`preco_corrida(4.0)`); o **protótipo** é só o cabeçalho com `;`,
  posto antes do `main` para o compilador conferir tipos e quantidade de
  argumentos (ROCHA; BORGES, s.d.).
- **Argumento e parâmetro**: o valor da chamada (`4.0`) é o argumento; a
  variável que o recebe (`km`) é o parâmetro (DEITEL; DEITEL, 2011, cap. 5).
- **Uma tarefa por função**: se não acha um nome curto, ela faz coisas demais.
  Entrada e saída ficam com quem chama (DEITEL; DEITEL, 2011, cap. 5).

```c
tipo_de_retorno nome(tipo parametro1, tipo parametro2) {
    // corpo
    return valor;
}
```

> [!WARNING]
> Chamar a função antes de ela aparecer, sem protótipo: o gcc 14 recusa
> (`implicit declaration`). E esquecer o `return` numa função não `void`: o
> `-Wall` avisa `control reaches end of non-void function`, e volta lixo.

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
