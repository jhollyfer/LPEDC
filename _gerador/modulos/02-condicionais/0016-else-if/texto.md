## 0016 · else if, if aninhado e o else pendurado

Radar na avenida, limite de 60 km/h, e você passou a 80. O Código de Trânsito
tem **faixas**: até 20% acima do limite é infração média, de 20% a 50% é
grave, acima de 50% é gravíssima. São quatro caminhos, e só um vale.

Para mais de dois caminhos, encadeie perguntas com **`else if`**:

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

O C testa **de cima para baixo** e **para no primeiro Sim**; os demais testes
não são feitos. Por isso, ao chegar em `velocidade <= 72`, já se sabe que a
velocidade passou de 60: não precisa escrever
`velocidade > 60 && velocidade <= 72`.

Logo, **a ordem importa**. Se o primeiro teste fosse `velocidade <= 90`, os 65
km/h cairiam lá e virariam "grave". Percorra as faixas sempre num sentido, da
menor para a maior. O `else` final é opcional e pega "o que sobrou".

O **`if` aninhado** é um `if` dentro do bloco de outro. Serve quando a segunda
pergunta só faz sentido se a primeira deu Sim: "o usuário existe? Se existe,
a senha confere?". O `else if` é um caso particular dele, sem a escada de
recuos; não é palavra-chave, é um `else` cuja única instrução é um `if`.

Os 80 km/h passam em ordem: 80 <= 60? Não. <= 72? Não. <= 90? Sim, e a busca
para ali:

{{ideia}}

O radar em C. As faixas são calculadas a partir do limite da via, para valer
em qualquer avenida:

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

O fluxograma é uma escada de losangos, cada um no Não do anterior. O caminho
verde desce pelos Nãos até o primeiro Sim; os de baixo não são visitados:

{{fluxograma}}

> [!WARNING]
> **O `else` pendurado.** Sem chaves, um `else` pertence ao `if` **mais
> próximo** que ainda não tem `else`, não importa o recuo:
>
> ```c
> if (pessoas > 0)
>     if (pessoas == 1)
>         printf("Mesa para um.\n");
> else
>     printf("Restaurante vazio.\n");
> ```
>
> O recuo sugere que o `else` é do primeiro `if`, mas ele é do segundo. Com 4
> pessoas, aparece "Restaurante vazio."; com 0, nada aparece. O `-Wall` avisa
> ("suggest explicit braces to avoid ambiguous 'else'"). A cura: **chaves**
> em volta do `if` de dentro.

> [!NOTE]
> **Pergunta para você:** a 72 km/h, qual mensagem aparece? E a 90 km/h?
> Os limites das faixas usam `<=`. Depois confira mudando a velocidade no código acima.

{{pratique}}
