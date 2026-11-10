## 0026 · Aleatórios

No jogo de tabuleiro, você caiu na prisão. Para sair, precisa tirar **dupla**
nos dois dados. Joga, não sai, joga de novo. É um `do...while` (assunto 0021)
com um ingrediente novo: o resultado de cada volta é sorteado.

O computador não sorteia de verdade: é determinístico, e a mesma entrada dá
sempre a mesma saída. Ele gera números **pseudoaleatórios**: uma sequência
calculada por uma conta fixa, em que cada número sai do anterior, e que parece
aleatória.

Em C, as peças ficam em `<stdlib.h>`:

- **`rand()`** devolve o próximo número da sequência, de 0 até **`RAND_MAX`**.
  O padrão garante `RAND_MAX` de pelo menos 32767; na glibc (Linux), vale
  2147483647;
- **`srand(semente)`** escolhe onde a sequência começa. A mesma **semente** dá
  sempre a mesma sequência.

Para trazer o número à faixa desejada, use o resto da divisão (assunto 0007):
`rand() % 6` dá de 0 a 5, e `1 + rand() % 6` dá de 1 a 6. Para uma faixa de `a`
até `b`: `a + rand() % (b - a + 1)`.

A semente depende do objetivo:

- **semente fixa** (`srand(2022)`): sorteia sempre os mesmos números, o que
  ajuda a **testar** e **depurar**, pois o erro volta a aparecer. Os exemplos
  do curso usam semente fixa para a saída do comentário bater com a sua;
- **semente do relógio** (`srand(time(NULL))`, com `<time.h>`): `time(NULL)`
  devolve os segundos desde 1º de janeiro de 1970. Cada execução começa num
  segundo diferente e sorteia números diferentes. Um jogo real usa este.

Sem nenhum `srand`, vale `srand(1)`: a mesma sequência sempre.

A semente 2022 entra no gerador, que produz números enormes, cada um calculado
a partir do anterior. O `% 6 + 1` transforma cada número numa face, e os pares
de faces são as jogadas. Na quarta, sai 4 e 4:

{{ideia}}

O mesmo jogo em C. A sequência exata depende da biblioteca: a saída abaixo é a
da glibc (Linux); no macOS ou no Windows, a semente 2022 dá outros números:

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

O `srand` fica **fora** do laço, antes de tudo, e roda uma vez. O sorteio fica
dentro, e a seta do Sim volta do losango para ele. No exemplo, o caminho passa
três vezes pelo Sim e, na quarta jogada, pelo Não:

{{fluxograma}}

> [!WARNING]
> O erro clássico é chamar `srand(time(NULL))` **dentro** do laço. O laço roda
> em milissegundos, no mesmo segundo, então toda volta reinicia a sequência com
> a **mesma** semente, e o `rand()` devolve sempre o mesmo primeiro número: o
> dado "sorteia" 4, 4, 4, 4... O `srand` vai uma vez, no começo do `main`.
> Outro tropeço: `srand` não devolve nada (é `void`). Quem sorteia é o `rand`.

> [!TIP]
> O `rand` **nunca** serve para senha, token ou criptografia: quem descobre a
> semente prevê tudo. Para isso existe `getrandom` (Linux) ou uma biblioteca de
> criptografia.

> [!NOTE]
> **Pergunta para você:** rode o A051 duas vezes. A saída muda? Agora troque
> o primeiro `srand(2026)` por `srand(time(NULL))` (e inclua `<time.h>`). O
> que muda na primeira linha, o que continua igual nas outras duas, e o que
> acontece se você rodar duas vezes dentro do mesmo segundo?

{{pratique}}
