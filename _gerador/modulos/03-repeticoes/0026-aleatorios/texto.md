## 0026 · Aleatórios

No jogo de tabuleiro, você caiu na prisão. Para sair, precisa tirar **dupla**
nos dois dados. Joga, não sai, joga de novo. A estrutura é um `do...while`
(assunto 0021), mas com uma peça que você ainda não tem: o resultado de cada
volta é sorteado. Até aqui, todo valor vinha de uma conta ou do teclado. Para
jogos, simulações e testes, o programa precisa de números que pareçam acaso.

O problema é que o computador não sorteia. Ele é **determinístico**: a mesma
entrada dá sempre a mesma saída. A saída é gerar números
**pseudoaleatórios**, uma sequência produzida por uma conta fixa em que cada
número sai do anterior, mas que, olhada de fora, parece não seguir regra
nenhuma (DEITEL; DEITEL, 2011, cap. 5). Pense num baralho que vem de fábrica
sempre embaralhado na mesma ordem. As cartas parecem misturadas, mas quem
souber a ordem prevê todas.

Em C, o gerador fica em `<stdlib.h>`. A função **`rand()`** devolve o próximo
número da sequência, um inteiro de 0 até a constante **`RAND_MAX`**. O padrão
da linguagem garante que `RAND_MAX` vale pelo menos 32767; na glibc, a
biblioteca do Linux, ele vale 2147483647 (CPPREFERENCE, s.d.). Como o valor
muda de um sistema para outro, o programa nunca deve contar com um `RAND_MAX`
específico.

Um dado só tem 6 faces, então você precisa trazer o número para a faixa
certa. A ferramenta é o resto da divisão (assunto 0007). O resto de qualquer
número por 6 fica entre 0 e 5; somando 1, fica entre 1 e 6. Daí vem
`1 + rand() % 6`. Para uma faixa qualquer de `a` até `b`, a quantidade de
valores possíveis é `b - a + 1`, e a fórmula vira
`a + rand() % (b - a + 1)` (DEITEL; DEITEL, 2011, cap. 5). Para sortear de 10
a 20, por exemplo: `10 + rand() % 11`.

Falta escolher onde a sequência começa. Esse ponto de partida é a
**semente**, e a função **`srand(semente)`** o define. A mesma semente dá
sempre a mesma sequência. Se o programa não chamar `srand`, vale `srand(1)`, e
toda execução sorteia os mesmos números (LINUX MAN-PAGES PROJECT, s.d.). No
baralho de fábrica, a semente diz de que ponto da pilha você começa a tirar
cartas.

A semente certa depende do objetivo (DEITEL; DEITEL, 2011, cap. 5). Uma
**semente fixa**, como `srand(2022)`, sorteia sempre os mesmos números. Isso
ajuda a testar e depurar, porque o erro que apareceu uma vez volta a aparecer.
Os exemplos do curso usam semente fixa para a saída do comentário bater com a
sua. Já a **semente do relógio**, `srand(time(NULL))` com `<time.h>`, usa
`time(NULL)`, que devolve os segundos passados desde 1º de janeiro de 1970.
Cada execução começa num segundo diferente e sorteia outra sequência. Um jogo
de verdade usa esta.

Como a sequência inteira sai da semente, quem descobre a semente prevê todos
os números. Por isso o `rand` nunca serve para senha, token ou criptografia
(LINUX MAN-PAGES PROJECT, s.d.). Para esses casos o Linux oferece o
`getrandom`, e existem bibliotecas de criptografia feitas para isso.

> [!WARNING]
> `srand(time(NULL))` **dentro** do laço reinicia a sequência a cada volta. O
> laço roda em milissegundos, no mesmo segundo, então a semente é sempre a
> mesma e o dado "sorteia" 4, 4, 4... O `srand` vai uma vez, no começo do
> `main`. E ele não devolve nada (é `void`): quem sorteia é o `rand`.

{{exemplo}}

No jogo de tabuleiro, só sai da prisão quem tira **dupla**. A semente 2022
entra no gerador, o `% 6 + 1` vira cada número numa face, e na quarta jogada
sai 4 e 4. A saída é a da glibc (Linux); em outro sistema, a sequência muda:

{{ideia}}

```c
#include <stdio.h>
#include <stdlib.h> // rand e srand

int main(void) {
    srand(2022); // semente fixa: a mesma sequência a cada execução

    int dado1, dado2;
    int jogadas = 0;

    do {
        dado1 = 1 + rand() % 6; // rand() % 6 vai de 0 a 5; + 1 vira 1 a 6
        dado2 = 1 + rand() % 6;
        jogadas++;
        printf("Jogada %d: %d e %d\n", jogadas, dado1, dado2);
    } while (dado1 != dado2);

    printf("Dupla de %d na jogada %d. Saiu da prisão!\n", dado1, jogadas);
    return 0;
}
// Saída (glibc, Linux; em outro sistema a sequência pode ser outra):
// Jogada 1: 1 e 5
// Jogada 2: 5 e 1
// Jogada 3: 1 e 6
// Jogada 4: 4 e 4
// Dupla de 4 na jogada 4. Saiu da prisão!
```

O `srand` fica **fora** do laço e roda uma vez; o sorteio fica dentro, e a
seta do Sim volta do losango para ele:

{{fluxograma}}
