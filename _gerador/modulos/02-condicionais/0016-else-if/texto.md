## 0016 · else if, if aninhado e o else pendurado

O `if/else` do 0015 escolhe entre dois caminhos. Muita regra, porém, tem
mais de duas saídas: uma nota vira conceito A, B, C ou D; uma conta de luz
cai numa de várias faixas de tarifa. Você precisa de um jeito de fazer
várias perguntas em sequência e ficar com a primeira que der certo.

Pense no radar de uma avenida com limite de 60 km/h. O Código de Trânsito
divide o excesso em faixas: até 20% acima do limite, infração média; de
20% a 50% acima, grave; acima de 50%, gravíssima. Com o limite de 60, as
faixas terminam em 72 e 90 km/h. O agente olha a velocidade e procura a
primeira faixa em que ela cabe, começando pela menor. Quatro caminhos, e só
um vale.

Para isso, o C encadeia perguntas com **`else if`**: cada `else` traz uma
nova pergunta, e só um bloco da cadeia roda (DEITEL; DEITEL, 2011, cap. 3).

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

O C testa as condições **de cima para baixo** e **para no primeiro Sim**:
roda aquele bloco e pula todo o resto da cadeia, sem fazer os testes que
faltam (BACKES, 2013, cap. 4). Isso tem uma consequência útil. Quando o
programa chega em `velocidade <= 72`, já se sabe que a velocidade passou
de 60, senão ele teria parado no primeiro teste. Por isso não é preciso
escrever `velocidade > 60 && velocidade <= 72`: a parte de baixo da faixa
já está garantida pelos testes anteriores. Com 80 km/h, o C pergunta
"80 <= 60?", não; "80 <= 72?", não; "80 <= 90?", sim, e para ali.

A mesma regra faz a **ordem importar**. Se o primeiro teste fosse
`velocidade <= 90`, os 65 km/h cairiam nele e virariam "grave", porque 65
também é menor que 90. Percorra as faixas sempre num sentido só, da menor
para a maior ou o contrário (DEITEL; DEITEL, 2011, cap. 3). O `else` final
é opcional e pega o que sobrou, o caso em que nenhuma pergunta deu Sim.

O `else if` é um caso particular de algo mais geral: o **`if` aninhado**,
um `if` dentro do bloco de outro `if`. Ele serve quando a segunda pergunta
só faz sentido depois de um Sim na primeira: "o usuário existe? Se existe,
a senha confere?". Não adianta conferir a senha de quem não existe. E o
`else if` nem é uma palavra-chave do C. Ele é um `else` cuja única
instrução é um `if`, escrito na mesma linha para evitar uma escada de
recuos (KERNIGHAN; RITCHIE, 1988, cap. 3).

Quando há `if` dentro de `if` sem chaves, surge uma dúvida: a qual `if`
pertence um `else`? A regra do C é fixa e não olha para o recuo. Um `else`
pertence ao `if` **mais próximo**, acima dele, que ainda não tem `else`
(BACKES, 2013, cap. 4). Esse caso tem nome: o **else pendurado**. Com
chaves em volta do `if` de dentro, a dúvida desaparece, porque o bloco
fecha antes do `else`.

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
