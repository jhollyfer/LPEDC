## 0016 · else if, if aninhado e o else pendurado

- **`else if`**: encadeia perguntas para mais de dois caminhos; só um vale
  (DEITEL; DEITEL, 2011, cap. 3).

```c
if (velocidade <= 60) {
    // dentro do limite
} else if (velocidade <= 72) {
    // média
} else if (velocidade <= 90) {
    // grave
} else {
    // gravíssima
}
```

- **Primeiro Sim**: o C testa de cima para baixo e **para no primeiro Sim**.
  Ao chegar em `velocidade <= 72`, já se sabe que passou de 60: não precisa
  de `velocidade > 60 &&` (BACKES, 2013, cap. 4).
- **A ordem importa**: com `velocidade <= 90` no topo, 65 km/h viraria
  "grave". Percorra as faixas num sentido só. O `else` final é opcional e pega
  o que sobrou (DEITEL; DEITEL, 2011, cap. 3).
- **`if` aninhado**: um `if` dentro do bloco de outro, para a pergunta que só
  faz sentido depois de um Sim. O `else if` não é palavra-chave: é um `else`
  cuja única instrução é um `if` (KERNIGHAN; RITCHIE, 1988, cap. 3).
- **Else pendurado**: sem chaves, o `else` pertence ao `if` **mais próximo**
  que ainda não tem `else`, não importa o recuo (BACKES, 2013, cap. 4).

> [!WARNING]
> **O `else` pendurado.** O recuo engana:
>
> ```c
> if (pessoas > 0)
>     if (pessoas == 1)
>         printf("Mesa para um.\n");
> else
>     printf("Restaurante vazio.\n");
> ```
>
> O `else` é do segundo `if`: com 4 pessoas aparece "Restaurante vazio.". O
> `-Wall` avisa; a cura são **chaves** em volta do `if` de dentro.

{{exemplo}}

O radar da avenida tem limite de 60 km/h e você passou a 80. As faixas saem
do limite: 80 <= 60? Não. <= 72? Não. <= 90? Sim, e a busca para ali:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int limite = 60;
    int velocidade = 80;
    int faixa_media = limite + limite / 5; // 72: até 20% acima
    int faixa_grave = limite + limite / 2; // 90: até 50% acima

    if (velocidade <= limite) {
        printf("Dentro do limite. Boa viagem!\n");
    } else if (velocidade <= faixa_media) {
        printf("Infração média: R$ 130.16\n");
    } else if (velocidade <= faixa_grave) {
        printf("Infração grave: R$ 195.23\n");
    } else {
        printf("Infração gravíssima: R$ 880.41\n");
    }
    return 0;
}
// Saída:
// Infração grave: R$ 195.23
```

O fluxograma é uma escada de losangos, cada um no Não do anterior; os de baixo
do primeiro Sim não são visitados:

{{fluxograma}}
