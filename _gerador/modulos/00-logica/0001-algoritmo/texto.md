## 0001 · Algoritmo

Você abre o app do banco para mandar um Pix de R$ 50 para um amigo. Sem
pensar, segue uma receita: entra na área Pix, digita a chave, digita o valor,
confere e confirma com a senha.

Essa receita é um **algoritmo**: uma sequência **finita** de passos **sem
ambiguidade** que resolve um problema. Todo programa é um algoritmo escrito
numa língua que o computador entende.

Um bom algoritmo tem:

- **entrada**: os dados que chegam (a chave e o valor);
- **processamento**: o que se faz com eles (conferir o saldo, descontar);
- **saída**: o resultado (o comprovante);
- **fim**: ele termina. Um passo a passo que nunca acaba não resolve nada;
- **precisão**: cada passo tem um significado só. "Coloque um pouco de sal"
  não serve para um computador. "Coloque 5 g de sal" serve.

Agora a parte importante. Por mais complicado que seja um programa, ele é
montado com só **três peças**:

1. **sequência**: um passo depois do outro;
2. **decisão**: "se o saldo der, envia; senão, avisa";
3. **repetição**: "enquanto a senha estiver errada, peça de novo".

Isso tem nome: é o teorema de Böhm e Jacopini (1966). Qualquer algoritmo cabe
nessas três estruturas. Os módulos 01, 02 e 03 são, cada um, sobre uma delas.

Vamos ver na prática. Você tem R$ 120 na conta e quer mandar R$ 50. O
algoritmo recebe o saldo e o valor, pergunta se o saldo cobre o valor e, como
cobre, envia e mostra o saldo novo:

{{ideia}}

O mesmo algoritmo em C. Não se preocupe com a sintaxe: ela começa no módulo
01. Por enquanto, leia de cima para baixo e repare que cada linha é um passo:

```c
#include <stdio.h>

int main(void) {
    double saldo = 120.0; // entrada: quanto tem na conta
    double valor = 50.0;  // entrada: quanto quer mandar

    printf("Pix de R$ %.2f\n", valor);

    if (saldo >= valor) {                // decisão: o saldo cobre?
        saldo = saldo - valor;           // processamento: desconta
        printf("Pix enviado!\n");        // saída
        printf("Saldo: R$ %.2f\n", saldo);
    } else {
        printf("Saldo insuficiente.\n");
    }
    return 0;
}
// Saída:
// Pix de R$ 50.00
// Pix enviado!
// Saldo: R$ 70.00
```

Repara no fluxograma: é o mesmo caminho. O losango é a decisão, e o exemplo
segue pelo Sim, porque 120 cobre 50:

{{fluxograma}}

> [!WARNING]
> O computador não tem bom senso. Se o algoritmo diz "digite o valor" e não diz
> o que fazer com ele, nada acontece. Se diz "repita até dar certo" e nunca
> muda nada, repete para sempre. Todo passo precisa estar escrito, inclusive o
> que para você é óbvio.

> [!TIP]
> **Por dentro do C:** o processador não sabe o que é "Pix" nem "saldo". Ele
> só sabe fazer coisas minúsculas: copiar um número de um lugar da memória para
> outro, somar, comparar dois números e pular para outra instrução conforme o
> resultado. O `if` do C vira exatamente isso: compara e pula. Programar é
> traduzir o seu algoritmo até chegar nesses passinhos, e quem faz a última
> parte da tradução é o compilador (assunto 0005).

> [!NOTE]
> **Pergunta para você:** e se o valor fosse R$ 150? Por qual caminho o
> fluxograma iria e o que apareceria na tela? Mude `50.0` para `150.0` no
> exemplo A001 e rode para conferir.

{{pratique}}
