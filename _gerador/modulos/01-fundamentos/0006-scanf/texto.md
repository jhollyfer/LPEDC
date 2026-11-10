## 0006 · scanf

No app do banco, você agenda um Pix: digita o valor, R$ 150,75, e o dia do
mês, 12. O app lê, guarda e confirma. Até aqui os programas só falavam; agora
vão **ouvir**: a **entrada** do modelo entrada → processamento → saída vem do
teclado.

Quem lê é o **`scanf`**, o espelho do `printf`. O formato diz o que esperar e
os outros argumentos dizem **onde guardar**:

```c
scanf("%d", &dia);
```

O `&` é obrigatório: `&dia` é o **endereço** da variável. O `scanf` não quer o
valor de `dia` (ainda lixo), e sim os bytes onde escrever o número digitado.
No `printf` não vai `&`; no `scanf`, vai em toda variável simples.

Os especificadores quase repetem os do `printf`, com uma diferença: **`double`
se lê com `%lf`** e se mostra com `%f`.

| Tipo | Lê com | Mostra com |
| --- | --- | --- |
| `int` | `%d` | `%d` |
| `float` | `%f` | `%f` |
| `double` | `%lf` | `%f` |
| `char` | `%c` (ou `" %c"`) | `%c` |

O que você digita vai para um **buffer**, uma fila de caracteres, e só chega
ao programa no Enter. O `scanf` tira da fila só o que o formato pede. `%d` e
`%lf` pulam espaços e Enters antes do número e param no primeiro caractere
inválido. O resto **fica na fila** para a próxima leitura, inclusive o `'\n'`
do Enter.

Caracteres comuns no formato precisam aparecer na entrada:
`scanf("%d/%d/%d", &d, &m, &a)` lê `7/9/2026`. O `scanf` **devolve** quantos
itens guardou: 1, 2, 3..., 0 se o primeiro já falhou, ou `EOF` (-1) se a
entrada acabou. É assim que o programa sabe se a leitura deu certo; no módulo
02, o `if` vai usar esse número. Por enquanto, apenas mostre e observe.

Você digita `150.75`, Enter, `12`, Enter. O `%lf` tira `150.75` da fila e
escreve em `valor`. O `%d` pula o `'\n'` que sobrou, tira o `12` e escreve em
`dia`. O último `'\n'` continua na fila:

{{ideia}}

O agendamento em C:

```c
#include <stdio.h>

int main(void) {
    double valor;
    int dia;

    printf("Valor do Pix: R$ ");
    scanf("%lf", &valor);            // %lf: double no scanf
    printf("Dia do mês: ");
    int lidos = scanf("%d", &dia);   // devolve quantos itens leu

    printf("Pix de R$ %.2f agendado para o dia %d\n", valor, dia);
    printf("O último scanf leu %d item\n", lidos);
    return 0;
}
// Exemplo de execução:
// Valor do Pix: R$ 150.75
// Dia do mês: 12
// Pix de R$ 150.75 agendado para o dia 12
// O último scanf leu 1 item
```

Para testar sem digitar, salve como `pix.c`, compile com o gcc e use o cano
(`|`) apresentado no começo do módulo: `printf '150.75\n12\n' | ./pix`.

No fluxograma, as duas leituras são paralelogramos de entrada; cada uma guarda
o valor numa caixinha. A saída vem depois:

{{fluxograma}}

> [!WARNING]
> Esquecer o `&` é o erro clássico: `scanf("%d", dia)` entrega o lixo de `dia`
> como se fosse um endereço, e o `scanf` escreve num lugar qualquer da
> memória. O programa quebra (`Segmentation fault`) ou estraga outra variável.
> O gcc avisa: `format '%d' expects argument of type 'int *', but argument 2
> has type 'int'`. Outro erro comum: `%f` para ler um `double`. Compila com
> aviso e o número sai errado.

> [!TIP]
> Com `%lf`, o `scanf` escreve 8 bytes no endereço; com `%f`, escreve só 4, no
> formato de `float`, e o `double` fica errado. No `printf` não há esse
> problema porque todo `float` vira `double`; no `scanf` vão endereços, e
> endereço não se converte.

> [!NOTE]
> **Pergunta para você:** se no dia você digitar `doze`, quanto vale `lidos`?
> E o que aparece no lugar do dia? Teste com
> `printf '150.75\ndoze\n' | ./programa`.

{{pratique}}
