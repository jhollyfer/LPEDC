## 0016 · else if, if aninhado e o else pendurado

Radar na avenida, limite de 60 km/h, e você passou a 80. O Código de Trânsito
não tem só "multou ou não multou". Ele tem **faixas**: até 20% acima do limite
é infração média, de 20% a 50% é grave, acima de 50% é gravíssima. São quatro
caminhos possíveis, e só um vale.

Para mais de dois caminhos, você encadeia perguntas com **`else if`**:

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

O C testa **de cima para baixo** e **para no primeiro Sim**. Os outros testes
nem são feitos. Isso simplifica cada condição: quando o programa chega no
`velocidade <= 72`, ele já sabe que a velocidade passou de 60, porque senão
teria parado antes. Não precisa escrever `velocidade > 60 && velocidade <= 72`.

A consequência é que **a ordem importa**. Se o primeiro teste fosse
`velocidade <= 90`, os 65 km/h cairiam lá e virariam "grave". Comece pela
faixa mais restrita, ou percorra as faixas em ordem, sempre num sentido só. O
`else` do final é opcional e pega "tudo o que sobrou".

Existe outro jeito de montar decisões: o **`if` aninhado**, um `if` dentro do
bloco de outro. Ele serve quando a segunda pergunta só faz sentido se a
primeira deu Sim: "o usuário existe? Se existe, a senha confere?". O `else if`
é um caso particular disso, só que escrito sem a escada de recuos.

Vamos ver na prática. Os 80 km/h passam pelas perguntas em ordem: 80 é menor
ou igual a 60? Não. A 72? Não. A 90? Sim, e a busca para ali:

{{ideia}}

O mesmo exemplo em C. Os limites das faixas são calculados a partir do limite
da via, para valerem em qualquer avenida:

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

Repara no fluxograma: é uma escada de losangos, cada um pendurado no Não do
anterior. O caminho verde desce pelos Nãos até o primeiro Sim, e os
losangos de baixo nunca são visitados:

{{fluxograma}}

> [!WARNING]
> **O `else` pendurado.** Sem chaves, um `else` pertence ao `if` **mais
> próximo** que ainda não tem `else`, não importa o recuo. Veja:
>
> ```c
> if (pessoas > 0)
>     if (pessoas == 1)
>         printf("Mesa para um.\n");
> else
>     printf("Restaurante vazio.\n");
> ```
>
> O recuo diz que o `else` é do primeiro `if`, mas ele é do segundo. Com 4
> pessoas, aparece "Restaurante vazio."; com 0, não aparece nada. O `-Wall`
> avisa ("suggest explicit braces to avoid ambiguous 'else'"). A cura é a de
> sempre: **chaves**. Com `{ }` em volta do `if` de dentro, o `else` vai para
> onde você quer.

> [!TIP]
> **Por dentro do C:** `else if` **não é uma palavra-chave**. É um `else`
> comum cuja única instrução é um `if`. Para o compilador, a escada acima é um
> `if` dentro do `else` de outro `if`, dentro do `else` de outro. Só a
> formatação é que deixa tudo alinhado. Em máquina, cada degrau é um `cmp` e um
> salto: com 80 km/h, o processador faz três comparações; com 50 km/h, só uma.
> Por isso, quando uma faixa é muito mais comum que as outras, testar ela
> primeiro economiza trabalho.

> [!NOTE]
> **Pergunta para você:** a 72 km/h, qual mensagem aparece? E a 90 km/h?
> Repare que os limites das faixas usam `<=`. Depois confira no A031.

{{pratique}}
