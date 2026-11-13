## 0022 · For

Você comprou uma TV de R$ 1.800 em 6 parcelas de R$ 300 e quer ver o carnê
inteiro, da parcela 1 à 6. Desta vez você **sabe** quantas voltas são antes de
começar. Esse é o **laço com contador**: uma variável começa num valor, anda
de passo em passo e para num valor conhecido (DEITEL; DEITEL, 2011, cap. 4).
Dá para escrever com `while`, mas o contador fica espalhado em três lugares:

```c
int parcela = 1;              // começa
while (parcela <= 6) {        // pergunta
    printf("Parcela %d\n", parcela);
    parcela++;                // passo, lá no fim do corpo
}
```

O começo está antes do laço, a pergunta no cabeçalho e o passo lá no fim do
corpo. Num corpo longo, o `parcela++` some de vista, e esquecer dele dá laço
infinito. O **`for`** junta as três peças numa linha só, o cabeçalho, e deixa
o corpo livre para o trabalho (BACKES, 2013, cap. 5):

```c
for (int parcela = 1; parcela <= 6; parcela++) {
    printf("Parcela %d\n", parcela);
}
```

Pense na catraca do ônibus com contador. Ela começa zerada uma vez, no início
do dia; antes de cada passageiro, confere se ainda cabe gente; o passageiro
passa; e só depois que ele passou o número sobe. O `for` roda nessa mesma
ordem, que não é a ordem em que você lê a linha (CARVALHO, 2010). O **início**
(`int parcela = 1`) roda **uma vez**, antes de tudo. A **condição**
(`parcela <= 6`) é testada antes de cada volta; se der falso, o laço acaba. Se
der verdadeiro, roda o **corpo**. Por fim roda o **passo** (`parcela++`), e o
fluxo volta para a condição. Repare que o passo, escrito no meio do cabeçalho,
só acontece depois do corpo.

O `for` é o `while` de cima reorganizado; o compilador trata os dois do mesmo
jeito (KERNIGHAN; RITCHIE, 1988, cap. 3). A escolha é de leitura. Use `for`
quando há um contador com começo, fim e passo conhecidos, como o carnê. Use
`while` quando só se sabe a condição de parada, como o cofrinho do assunto
0020, em que o número de meses é a resposta.

O cabeçalho aceita várias formas (BACKES, 2013, cap. 5). A variável declarada
no início, como o `int parcela`, só existe dentro do laço; isso vale do padrão
C99 em diante e evita que o contador vaze para o resto do programa. O passo
pode ser qualquer conta: `c += 10`, `s--`, `x *= 3`. O contador pode ser
`char`, porque em C um caractere é um número. A vírgula permite controlar duas
variáveis ao mesmo tempo: `for (int i = 1, j = 9; i < j; i++, j--)`. O exemplo
A044 mostra essas variações. Qualquer parte do cabeçalho pode ficar vazia, mas
os dois `;` são obrigatórios: `for (;;)` não tem condição, roda para sempre e
é um laço infinito escrito de propósito.

Para saber quantas voltas um `for` dá sem rodar o programa, olhe o primeiro e
o último valor que passam pela condição (DEITEL; DEITEL, 2011, cap. 4). Em
`for (i = a; i < b; i++)`, o contador vai de `a` até `b - 1`, o que dá
`b - a` voltas. Com `<=`, ele chega até o próprio `b` e dá `b - a + 1`. O
carnê, de 1 a 6 com `<=`, dá 6 voltas.

> [!WARNING]
> O erro mais comum é o **erro por um** (*off-by-one*): uma volta a mais ou a
> menos. `for (int p = 1; p < 6; p++)` mostra 5 parcelas. Pergunte qual é o
> **primeiro** e o **último** valor que passa. E contador é sempre inteiro:
> `for (double x = 0.1; x != 1.0; x += 0.1)` nunca termina, porque 0,1 não é
> exato em binário e `x` pula o 1,0.

{{exemplo}}

Uma TV de R$ 1.800 em 6 parcelas. O carnê começa com `parcela = 1` uma vez
só, pergunta "parcela <= 6?", roda o corpo, dá o passo e volta à pergunta; na
sétima, a resposta é Não:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double preco = 1800.0;
    int total_parcelas = 6;
    double valor = preco / total_parcelas;
    double falta = preco;

    for (int parcela = 1; parcela <= total_parcelas; parcela++) {
        falta = falta - valor;
        printf("Parcela %d/%d: R$ %.2f (falta R$ %.2f)\n",
               parcela, total_parcelas, valor, falta);
    }
    printf("Carnê quitado!\n");
    return 0;
}
// Saída:
// Parcela 1/6: R$ 300.00 (falta R$ 1500.00)
// Parcela 2/6: R$ 300.00 (falta R$ 1200.00)
// Parcela 3/6: R$ 300.00 (falta R$ 900.00)
// Parcela 4/6: R$ 300.00 (falta R$ 600.00)
// Parcela 5/6: R$ 300.00 (falta R$ 300.00)
// Parcela 6/6: R$ 300.00 (falta R$ 0.00)
// Carnê quitado!
```

O fluxograma é igual ao de um `while`: o passo `parcela++` fica no fim do
corpo, e a seta sai dele de volta ao losango:

{{fluxograma}}
