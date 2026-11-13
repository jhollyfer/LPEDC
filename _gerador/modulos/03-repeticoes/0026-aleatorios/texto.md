## 0026 · Aleatórios

- **Pseudoaleatório**: o computador é determinístico. Ele calcula uma
  sequência por uma conta fixa, cada número a partir do anterior, que parece
  aleatória (DEITEL; DEITEL, 2011, cap. 5).
- **`rand()`**, de `<stdlib.h>`: devolve o próximo número, de 0 até
  **`RAND_MAX`**. O padrão garante pelo menos 32767; na glibc, 2147483647
  (CPPREFERENCE, s.d.).
- **`srand(semente)`**: escolhe onde a sequência começa. A mesma **semente**
  dá sempre a mesma sequência; sem `srand`, vale `srand(1)`
  (LINUX MAN-PAGES PROJECT, s.d.).
- **Faixa**: `1 + rand() % 6` dá de 1 a 6; de `a` até `b`,
  `a + rand() % (b - a + 1)` (DEITEL; DEITEL, 2011, cap. 5).
- **Semente fixa** (`srand(2022)`): os mesmos números a cada execução, bom para
  testar e depurar; os exemplos do curso usam assim
  (DEITEL; DEITEL, 2011, cap. 5).
- **Semente do relógio** (`srand(time(NULL))`, com `<time.h>`): os segundos
  desde 1º/1/1970 mudam a cada execução. Um jogo real usa este
  (DEITEL; DEITEL, 2011, cap. 5).
- **Não é cofre**: o `rand` nunca serve para senha ou token; quem descobre a
  semente prevê tudo (LINUX MAN-PAGES PROJECT, s.d.).

> [!WARNING]
> `srand(time(NULL))` **dentro** do laço reinicia a sequência com a mesma
> semente a cada volta, no mesmo segundo, e o dado "sorteia" 4, 4, 4... O
> `srand` vai uma vez, no começo do `main`; quem sorteia é o `rand`.

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
