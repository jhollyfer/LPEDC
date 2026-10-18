## 0003 · Fluxograma

No estacionamento do shopping, os primeiros 15 minutos são grátis. Passou
disso, você paga R$ 8. Você ficou 40 minutos. Quanto paga?

Pseudocódigo é texto. O **fluxograma** é o mesmo algoritmo **desenhado**: cada
passo vira uma forma, e as setas mostram a ordem. É ótimo para enxergar
decisões e repetições, porque os caminhos ficam visíveis.

As formas que o curso usa (a legenda do módulo mostra todas):

- **início/fim** (pílula cinza): onde o algoritmo começa e termina;
- **entrada/saída** (paralelogramo azul): ler do teclado ou mostrar na tela;
- **processo** (retângulo roxo): uma conta, guardar um valor;
- **decisão** (losango amarelo): uma pergunta de sim ou não. É a única forma
  com **duas** saídas.

E as regras que mantêm o desenho legível:

1. tem exatamente um início e pelo menos um fim;
2. as setas dizem a ordem; sem seta, não tem passo seguinte;
3. todo losango tem duas saídas, marcadas Sim e Não;
4. uma **repetição** aparece como uma seta que **volta** para um losango
   anterior.

Vamos ver na prática. Os 40 minutos entram, a pergunta "até 15 minutos?"
responde Não, e o caminho vai para a cobrança:

{{ideia}}

O mesmo algoritmo em C:

```c
#include <stdio.h>

int main(void) {
    int minutos = 40;

    if (minutos <= 15) {
        printf("Grátis. Boa compra!\n");
    } else {
        printf("Valor: R$ 8.00\n");
    }
    return 0;
}
// Saída:
// Valor: R$ 8.00
```

Agora o fluxograma completo. Repara que o caminho do exemplo sai do losango
pelo **Não**, e o caminho do Sim fica apagado porque, com 40 minutos, ninguém
passa por ele:

{{fluxograma}}

> [!WARNING]
> O erro mais comum é o **losango com uma saída só**: "minutos > 15?" com uma
> seta para "cobrar R$ 8" e nada mais. E quando a resposta é Não? O programa
> fica sem saber para onde ir. Toda pergunta tem duas respostas, e as duas
> precisam de um caminho, nem que seja direto para o Fim.

> [!TIP]
> **Por dentro do C:** o fluxograma é muito parecido com o que o compilador
> monta por dentro. Ele quebra o seu código em **blocos básicos** (trechos sem
> decisão, como os retângulos) ligados por **saltos** (as setas). Um `if` vira
> "compara e, se der falso, pula para o bloco do else". Por isso o fluxograma
> nunca sai de moda: é o desenho do programa do jeito que a máquina enxerga.

> [!NOTE]
> **Pergunta para você:** se a pessoa ficar exatamente 15 minutos, ela paga?
> Siga o fluxograma com o dedo antes de mudar `40` para `15` no exemplo A005 e
> rodar.

{{pratique}}
