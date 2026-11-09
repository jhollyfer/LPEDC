<!-- Gerado por _gerador. Para mudar este arquivo, edite _gerador/modulos/27-c-detalhes/ e rode: cd _gerador && npm run gerar -->

# Módulo 27 · Detalhes de C que caem em prova

Você já escreve C há 26 módulos. Mesmo assim, uma linha como
`x & 1 == 0`, `i < u` ou `n - 1` com `size_t` pode enganar, porque o
compilador lê a expressão por regras que o olho não aplica sozinho. Uma prova
de múltipla escolha adora esse tipo de linha: o código é curto, compila, e
as alternativas trazem justamente o resultado que a intuição sugere.

Este módulo junta as regras que decidem o valor dessas linhas: quem pega os
operandos primeiro (precedência e associatividade), em que ordem as partes
rodam e quando a resposta é "comportamento indefinido"; o que acontece quando
um número com sinal encontra um sem sinal, e por que `-1 > 0u` é verdadeiro;
e o vetor de tamanho variável (VLA), o único vetor do C cujo `sizeof` é
calculado com o programa rodando.

A mudança na cabeça é ler a expressão como o compilador, e não como
matemática: primeiro os tipos (promoção e conversão), depois a árvore
(precedência), e só então os valores. Aí a pegadinha vira conta.

## O que você vai aprender

- ler qualquer expressão com a **tabela de precedência e associatividade**, incluindo bit a bit, `?:`, vírgula e atribuição composta
- separar **agrupamento** de **ordem de avaliação**, reconhecer **efeito colateral** e o **comportamento indefinido** de `i = i++`
- prever o que acontece quando **com sinal e sem sinal** se misturam: promoção inteira, conversão aritmética usual, `-1 > 0u`
- usar `>>`, máscaras e `size_t` sem cair nas armadilhas do negativo e do laço que desce
- criar e passar **VLAs** (`void f(int l, int c, int m[l][c])`), entender o `sizeof` em tempo de execução, o `__STDC_NO_VLA__` e o risco da pilha
- juntar tudo num controle de acesso com struct, enum, máscaras e VLA

## Antes de começar

Este módulo usa os operadores dos módulos 01 e 02 (aritmética, atribuição,
`++`, lógicos, ternário), os bits e máscaras do 0065, struct e enum do
módulo 08, e `malloc`/`free` do módulo 07. Se `p &= ~MASCARA;` ainda não
parece natural, revise o 0065 antes.

Os valores dos comentários são os de um PC de 64 bits com Linux e gcc: `int`
e `unsigned` de 4 bytes, `long` e `size_t` de 8. Algumas respostas (como
`-17 >> 2`) dependem do compilador, e o texto avisa quando for o caso.

O `rodar` compila com `-Wall -Wextra`, e esses avisos pegam vários erros
deste módulo. Os exemplos compilam limpos; quando o texto mostra uma linha
que o gcc avisaria, ela aparece fora do programa ou com a conversão escrita
à vista. Ao rodar, tire um parêntese, troque `unsigned` por `int`, aumente o
VLA e leia o que o gcc diz.


```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/A339.c
```

| # | Assunto | Pasta |
| --- | --- | --- |
| [0170](#0170--precedência-e-ordem-de-avaliação) | Precedência e ordem de avaliação | [`0170-precedencia-e-avaliacao/`](27-c-detalhes/0170-precedencia-e-avaliacao/) |
| [0171](#0171--com-sinal-e-sem-sinal) | Com sinal e sem sinal | [`0171-com-e-sem-sinal/`](27-c-detalhes/0171-com-e-sem-sinal/) |
| [0172](#0172--vetor-de-tamanho-variável-vla) | Vetor de tamanho variável (VLA) | [`0172-vla/`](27-c-detalhes/0172-vla/) |
| [0173](#0173--juntando-tudo-o-controle-de-acesso) | Juntando tudo: o controle de acesso | [`0173-juntando-tudo/`](27-c-detalhes/0173-juntando-tudo/) |

---

## 0170 · Precedência e ordem de avaliação

Você pede 3 pacotes de café a R$ 18 no app do mercado, e o frete é R$ 12. A
conta é `18 * 3 + 12`. Ninguém pensa duas vezes: dá 66. Mas por que não
`18 * (3 + 12)`, que dá 270? Porque o C, como a matemática da escola, tem uma
regra fixa de quem vai primeiro, e a prova gosta de esconder essa regra numa
linha só.

Duas regras decidem como o C **agrupa** uma expressão. A **precedência** diz
qual operador pega os operandos primeiro: `*` antes de `+`. A
**associatividade** desempata operadores do mesmo nível: `100 - 66 - 20` é
`(100 - 66) - 20`, da esquerda para a direita, mas `a = b = 5` é
`a = (b = 5)`, da direita para a esquerda.

| Nível | Operadores | Agrupa |
| --- | --- | --- |
| 1 | `()` `[]` `->` `.` `x++` `x--` | esquerda → direita |
| 2 | `++x` `--x` `+x` `-x` `!` `~` `*p` `&x` `(tipo)` `sizeof` | direita → esquerda |
| 3 | `*` `/` `%` | esquerda → direita |
| 4 | `+` `-` | esquerda → direita |
| 5 | `<<` `>>` | esquerda → direita |
| 6 | `<` `<=` `>` `>=` | esquerda → direita |
| 7 | `==` `!=` | esquerda → direita |
| 8 | `&` | esquerda → direita |
| 9 | `^` | esquerda → direita |
| 10 | `\|` | esquerda → direita |
| 11 | `&&` | esquerda → direita |
| 12 | `\|\|` | esquerda → direita |
| 13 | `?:` | direita → esquerda |
| 14 | `=` `+=` `-=` `*=` `/=` `%=` `<<=` `>>=` `&=` `^=` `\|=` | direita → esquerda |
| 15 | `,` | esquerda → direita |

Três pontos dessa tabela caem em prova. Os bit a bit `&`, `^` e `|` ficam
**abaixo** do `==`. O `?:` fica abaixo de quase tudo, então
`compra + compra >= 50 ? 0 : frete` é uma pergunta sobre a soma inteira. E a
atribuição composta trata o lado direito como um bloco: `a *= 2 + 1` é
`a = a * (2 + 1)`.

Agrupar não é calcular. A precedência diz que em `f() + g()` a soma junta os
dois resultados, mas **não** diz qual função roda primeiro: a **ordem de
avaliação** dos operandos não é especificada, e cada compilador escolhe. Só
alguns pontos fixam a ordem: `&&`, `||`, `?:` e a vírgula avaliam o lado
esquerdo inteiro antes do direito, e uma função só começa depois de todos os
argumentos prontos.

Um **efeito colateral** é tudo que uma expressão muda além de produzir valor:
`i++` muda `i`, `x = 3` muda `x`, `printf` escreve na tela. Mudar a mesma
variável duas vezes, ou mudar e ler sem ordem garantida, na mesma expressão,
é **comportamento indefinido**: `i = i++`, `v[i] = i++` e
`printf("%d %d", i, i++)` não têm resposta certa. O programa pode dar
qualquer coisa.

O desenho mostra como o C monta a árvore de cada conta:
o operador de menor precedência fica na raiz e é o último a agir. Na
pegadinha do frete grátis, a raiz é o `?:`, e o `+` foi parar lá embaixo:

<p align="center"><img src="27-c-detalhes/0170-precedencia-e-avaliacao/ideia.svg" alt="Diagrama da ideia: Precedência e ordem de avaliação" width="882"></p>

O programa faz as contas do carrinho e mostra cada agrupamento:

```c
#include <stdio.h>

int main(void) {
    int preco = 18, qtd = 3, frete = 12; // 3 pacotes de café a R$ 18

    int total = preco * qtd + frete;    // * antes de +: (18 * 3) + 12
    int outro = preco * (qtd + frete);  // parênteses mandam: 18 * 15
    printf("total = %d, outro = %d\n", total, outro);

    int sobra = 100 - total - 20;       // - é da esquerda: (100 - 66) - 20
    printf("sobra = %d\n", sobra);

    int a, b;
    a = b = 5;                          // = é da direita: a = (b = 5)
    a *= 2 + 1;                         // a = a * (2 + 1), não a * 2 + 1
    printf("a = %d, b = %d\n", a, b);

    int compra = preco * qtd;           // 54
    // frete grátis a partir de R$ 50: o ?: fica ABAIXO do +
    int pegadinha = compra + compra >= 50 ? 0 : frete; // ((54 + 54) >= 50) ? 0 : 12
    int certo = compra + (compra >= 50 ? 0 : frete);   // 54 + 0
    printf("pegadinha = %d, certo = %d\n", pegadinha, certo);

    int gratis = compra >= 50 && qtd >= 3; // relacionais antes de &&: (54 >= 50) && (3 >= 3)
    printf("frete grátis? %d\n", gratis);
    return 0;
}
// Saída:
// total = 66, outro = 270
// sobra = 14
// a = 15, b = 5
// pegadinha = 0, certo = 54
// frete grátis? 1
```

No fluxograma, o `?:` aparece como o que ele é: uma pergunta escondida dentro
da expressão. O que entra na pergunta depende só dos parênteses, e no `certo`
ela olha apenas o `compra`:


<p align="center"><img src="27-c-detalhes/0170-precedencia-e-avaliacao/fluxograma.svg" alt="Fluxograma: Precedência e ordem de avaliação" width="529"></p>

> [!WARNING]
> `i = i++` não "soma 1 e guarda", nem "guarda o antigo": é comportamento
> indefinido, e a pergunta "quanto vale `i`?" não tem resposta. Com `-Wall`, o
> gcc avisa:
>
> ```text
> warning: operation on 'i' may be undefined [-Wsequence-point]
> ```
>
> Ele também avisa `x & 3 == 3` ("suggest parentheses around comparison") e
> `a || b && c`. Mas **não** avisa `compra + compra >= 50 ? 0 : frete`. Na
> dúvida, ponha parênteses: eles não custam nada no programa pronto.

> [!TIP]
> **Por dentro do C:** o compilador transforma cada expressão numa árvore,
> como a do desenho, e gera instruções de baixo para cima. A precedência fixa
> o **formato** da árvore; a ordem em que ele visita os galhos é livre, e o gcc
> usa essa liberdade para guardar valores em registradores e economizar
> instruções. É por isso que o padrão não promete a ordem de `f() + g()`. Os
> pontos que fixam a ordem (`&&`, `||`, `?:`, `,` e o fim de cada instrução)
> viram, no código de máquina, um teste e um salto: o lado direito do `&&`
> nem chega a rodar quando o esquerdo dá 0.

> [!NOTE]
> **Pergunta para você:** quanto vale `x` depois de `int x = 10; x -= 2 * 3 - 1;`?
> E `1 + 2 << 1`, que o gcc avisa mas compila?

### Hora de praticar

Arquivos em [`0170-precedencia-e-avaliacao/`](27-c-detalhes/0170-precedencia-e-avaliacao/).

**Exemplo A339 · O lado direito que nem roda**

```c
#include <stdbool.h>
#include <stdio.h>

int consultas = 0; // quantas vezes o "banco" foi consultado

bool tem_saldo(int saldo, int valor) {
    consultas++;
    printf("  (consultou o saldo)\n");
    return saldo >= valor;
}

int main(void) {
    // && e ||: o lado esquerdo vai primeiro, e o direito só roda se precisar
    bool conta_ativa = false;
    printf("Pix de R$ 80 numa conta bloqueada:\n");
    if (conta_ativa && tem_saldo(200, 80)) {
        printf("  enviado\n");
    } else {
        printf("  recusado\n");
    }

    conta_ativa = true;
    printf("Pix de R$ 80 numa conta ativa:\n");
    if (conta_ativa && tem_saldo(200, 80)) {
        printf("  enviado\n");
    }
    printf("consultas ao saldo: %d\n", consultas);

    // ?: encadeado agrupa da direita: a ? x : (b ? y : z)
    int distancias[] = {3, 12, 40};
    for (int i = 0; i < 3; i++) {
        int km = distancias[i];
        int frete = km <= 5 ? 8 : km <= 15 ? 14 : 25;
        printf("%2d km -> frete R$ %d\n", km, frete);
    }

    // a vírgula: avalia a esquerda, descarta, e o valor é o da direita
    int fila[] = {1, 2, 3, 4, 5};
    for (int i = 0, j = 4; i < j; i++, j--) { // duas variáveis andando juntas
        int t = fila[i];
        fila[i] = fila[j];
        fila[j] = t;
    }
    printf("fila invertida:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", fila[i]);
    }
    printf("\n");
    return 0;
}
// Saída:
// Pix de R$ 80 numa conta bloqueada:
//   recusado
// Pix de R$ 80 numa conta ativa:
//   (consultou o saldo)
//   enviado
// consultas ao saldo: 1
//  3 km -> frete R$ 8
// 12 km -> frete R$ 14
// 40 km -> frete R$ 25
// fila invertida: 5 4 3 2 1
```

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/A339.c
```

**Exemplo A340 · A ordem que o padrão não promete**

```c
#include <stdio.h>

int passo = 0; // marca a ordem em que as funções rodam

int pedir_pao(void) {
    printf("  pão chegou em %d\n", ++passo);
    return 7; // R$ 7
}

int pedir_cafe(void) {
    printf("  café chegou em %d\n", ++passo);
    return 5; // R$ 5
}

int main(void) {
    // a soma é sempre 12; QUEM roda primeiro, o padrão não diz
    printf("conta junta:\n");
    int conta = pedir_pao() + pedir_cafe();
    printf("  conta = %d\n", conta);

    // quando a ordem importa, separe em instruções: o ; fixa a ordem
    passo = 0;
    printf("conta em passos:\n");
    int pao = pedir_pao();
    int cafe = pedir_cafe();
    printf("  conta = %d\n", pao + cafe);

    // pré e pós-incremento, cada um sozinho na sua instrução
    int senha = 41;
    int chamada = senha++; // usa 41, depois senha vira 42
    printf("chamou %d, próxima senha %d\n", chamada, senha);
    chamada = ++senha;     // senha vira 43, depois usa 43
    printf("chamou %d, próxima senha %d\n", chamada, senha);

    // sizeof não avalia a expressão: o ++ abaixo NÃO acontece
    int n = 10;
    size_t bytes = sizeof(n++);
    printf("sizeof(n++) = %zu, n continua %d\n", bytes, n);
    return 0;
}
// Saída (a ordem da "conta junta" é a do gcc deste PC; outro compilador
// pode chamar o café primeiro):
// conta junta:
//   pão chegou em 1
//   café chegou em 2
//   conta = 12
// conta em passos:
//   pão chegou em 1
//   café chegou em 2
//   conta = 12
// chamou 41, próxima senha 42
// chamou 43, próxima senha 43
// sizeof(n++) = 4, n continua 10
```

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/A340.c
```

#### Exercícios

**Exercício E1015** · ★☆☆

As três fórmulas abaixo foram digitadas sem parênteses e dão resultados
absurdos. Conserte cada uma pondo parênteses só onde precisa, para que a
média das notas 7, 8 e 9 dê 8, os 104 °F virem 40 °C (C = (F - 32) * 5 / 9)
e a área de um quadro de 4 x 3 com 1 de moldura de cada lado dê 30.


```text
Saída esperada:
media = 8
celsius = 40
area = 30
```

**Dicas:**

1. Rode antes de mexer: sai 18, 87 e 12. Descubra por que, olhando a
   tabela de precedência.
2. Na moldura, cada lado ganha 2: (4 + 2) * (3 + 2).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/E1015.c
```

**Exercício E1016** · ★☆☆

Escreva um programa que mostre, para cada expressão abaixo, o valor dela
como está e o valor da mesma conta com todos os parênteses no jeito que o
C agrupa. Os dois números de cada linha têm que bater. Para as duas
últimas, que são atribuições, mostre as variáveis depois da instrução.


```text
100 / 10 / 5      2 - 3 - 4      2 * 3 % 4
a = b = c = 7     x = 5; x -= 1 + 2
```



```text
Saída esperada:
100 / 10 / 5 = 2   ((100 / 10) / 5) = 2
2 - 3 - 4 = -5   ((2 - 3) - 4) = -5
2 * 3 % 4 = 2   ((2 * 3) % 4) = 2
a = b = c = 7 -> a = 7, b = 7, c = 7
x -= 1 + 2 -> x = 2
```

**Dicas:**

1. *, / e % estão no mesmo nível e agrupam da esquerda para a direita.
2. A atribuição agrupa da direita: a = (b = (c = 7)).
3. x -= 1 + 2 é x = x - (1 + 2), não x = x - 1 + 2.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/E1016.c
```

**Exercício E1017** · ★★☆

Para entender de vez o x++ e o ++x, escreva duas funções que fazem o
mesmo trabalho que eles, recebendo o endereço da variável:


```text
int pos_incremento(int *p)  // devolve o valor antigo, depois soma 1
int pre_incremento(int *p)  // soma 1, depois devolve o valor novo
```


O main já calcula b e c com os operadores. Refaça as mesmas contas com as
suas funções, em variáveis a2, b2 e c2, e mostre as duas linhas.


```text
Saída esperada:
com ++:      a = 7, b = 10, c = 14
com funcoes: a = 7, b = 10, c = 14
```

**Dicas:**

1. Em pos_incremento, guarde *p numa variável antes de somar.
2. b2 = pos_incremento(&a2) * 2; c2 = pre_incremento(&a2) * 2;
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/E1017.c
```

**Exercício E1018** · ★★☆

Quatro amigos alugaram uma casa de praia por R$ 2400 para 3 dias. O
programa abaixo compila sem nenhum aviso, mas as três contas estão
erradas. Conserte cada uma:


```text
- o custo por pessoa por dia é o total dividido por (pessoas x dias);
- cada um paga a sua parte do total mais R$ 50 de limpeza quando a
  estadia passa de 2 dias;
- pagando à vista, o grupo ganha 10% de desconto sobre o total.
```



```text
Saída esperada:
por pessoa por dia: R$ 200
cada um paga: R$ 650
desconto à vista: R$ 240
```

**Dicas:**

1. Rode antes: sai 1800, 50 e 0. Para cada linha, escreva no papel a
   árvore que o C montou.
2. O ?: fica abaixo do + e do >: ele engoliu a conta inteira.
3. 10 / 100 em inteiros é 0. Multiplique antes de dividir.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/E1018.c
```

**Exercício E1019** · ★★★

As três macros abaixo têm defeito. #define só troca texto: DOBRO(n) vira
"n + n" colado no meio da expressão, e MAIOR(fila++, limite) copia o
fila++ duas vezes. Conserte:


```text
- DOBRO e AREA: ponha parênteses em volta de cada parâmetro e do
  resultado inteiro;
- MAIOR: troque a macro por uma função int maior(int a, int b), que
  avalia cada argumento uma vez só.
```



```text
Saída esperada:
100 / DOBRO(5) = 10
AREA(2 + 1, 4) = 12
maior = 3, fila = 4
```

**Dicas:**

1. Rode antes: sai 25, 6 e "maior = 4, fila = 5". Escreva no papel o
   texto que cada macro gera.
2. #define DOBRO(x) ((x) + (x))
3. Com a função, a chamada fica maior(fila++, limite).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/E1019.c
```

**Exercício E1020** · ★★★

Um colega escreveu a busca de um código no estoque assim:


```text
while (v[i] != alvo && i < n) i++;
```


Quando o código não existe, ele lê v[n], que fica fora do vetor (o
AddressSanitizer acusa). Escreva a versão segura:


```text
int procurar(const int *v, int n, int alvo, int *lidos)
```


Ela devolve o índice do alvo, ou -1, e conta em *lidos quantas vezes leu
uma casa do vetor. Teste com os códigos {12, 7, 30, 7, 55}, procurando 30
e 99, e com um vetor vazio (n = 0).


```text
Saída esperada:
procurar 30: indice 2, leituras 3
procurar 99: indice -1, leituras 5
vetor vazio: indice -1, leituras 0
```

**Dicas:**

1. Troque a ordem: i < n tem que vir antes, porque o && só avalia o lado
   direito se o esquerdo der verdadeiro.
2. Para contar só as leituras que acontecem, use o operador vírgula no
   lado direito: (++*lidos, v[i] != alvo).
3. Comece *lidos em 0 dentro da função.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0170-precedencia-e-avaliacao/E1020.c
```

---

## 0171 · Com sinal e sem sinal

A loja virtual tinha 2 fones em estoque e vendeu 3 numa promoção relâmpago.
O sistema, em vez de mostrar -1, passou a anunciar **4294967295 fones
disponíveis**. Ninguém errou a conta: o estoque era `unsigned`, e um número
sem sinal não sabe ser negativo.

Todo inteiro do C vem em duas versões. O **com sinal** (`int`, `signed char`,
`long`) guarda negativos: num `int` de 32 bits, de -2147483648 a 2147483647. O
**sem sinal** (`unsigned`, `unsigned char`, `size_t`) usa os mesmos 32 bits só
para o zero e os positivos: de 0 a 4294967295 (`UINT_MAX`). O `size_t`, que o
`sizeof` e o `strlen` devolvem, é sem sinal.

Os bits não sabem que tipo são. O -1 de um `int` são 32 bits ligados, e os
mesmos 32 bits lidos como `unsigned` valem 4294967295. Por isso a conta sem
sinal **dá a volta**, como um odômetro: `2u - 3u` é 4294967295, e
`UINT_MAX + 1u` é 0. Isso é definido pelo padrão (conta módulo 2³²). Já
estourar um `int` com sinal, como `INT_MAX + 1`, é comportamento indefinido.

Quando uma conta mistura tipos, o C aplica duas regras antes de calcular:

1. **Promoção inteira**: `char`, `short`, `unsigned char`, `bool` e `enum`
   viram `int` antes de qualquer conta. `unsigned char` 200 + 100 dá 300, um
   `int`, e só perde o excesso se você guardar o resultado num byte.
2. **Conversão aritmética usual**: os dois operandos viram o tipo "maior".
   Entre `int` e `unsigned` do mesmo tamanho, ganha o `unsigned`: o `int`
   vira sem sinal. Se o com sinal for maior e couber todo o sem sinal (um
   `long` de 64 bits contra um `unsigned` de 32), ganha o com sinal. E se
   houver um `double`, tudo vira `double`.

A regra 2 produz a pegadinha mais famosa de C: `-1 > 0u` é **verdadeiro**. O
`-1` vira `unsigned`, 4294967295, que é maior que 0. Já `-1L < 1u`
é verdadeiro no Linux de 64 bits, porque ali o `unsigned` cabe no `long` e
nada vira sem sinal.

O desenho mostra os 4 bytes do saldo -1, todos com os
oito bits ligados, e as duas leituras possíveis deles. A comparação com
`0u` escolhe a leitura sem sinal:

<p align="center"><img src="27-c-detalhes/0171-com-e-sem-sinal/ideia.svg" alt="Diagrama da ideia: Com sinal e sem sinal" width="858"></p>

O programa repete as três situações: o estoque que dá a volta, a comparação
misturada e a promoção do `unsigned char`:

```c
#include <limits.h>
#include <stdio.h>

int main(void) {
    unsigned estoque = 2;  // 2 fones na prateleira
    estoque = estoque - 3; // vendeu 3: unsigned não tem negativo, dá a volta
    printf("estoque = %u (UINT_MAX = %u)\n", estoque, UINT_MAX);

    int saldo = -1;        // R$ -1 na conta
    unsigned zero = 0u;
    // saldo > zero misturaria int e unsigned: o int viraria unsigned.
    // O gcc avisa (-Wsign-compare); aqui a conversão vai escrita, à vista
    printf("(unsigned)saldo = %u\n", (unsigned)saldo);
    printf("-1 > 0u? %s\n", (unsigned)saldo > zero ? "sim" : "não");
    printf("-1 > 0?  %s\n", saldo > 0 ? "sim" : "não");

    unsigned char a = 200, b = 100; // dois bytes de 0 a 255
    printf("a + b = %d\n", a + b);  // promoção: os dois viram int antes da soma
    unsigned char c = a + b;        // guardar num byte corta: 300 - 256
    printf("c = %d\n", c);
    return 0;
}
// Saída:
// estoque = 4294967295 (UINT_MAX = 4294967295)
// (unsigned)saldo = 4294967295
// -1 > 0u? sim
// -1 > 0?  não
// a + b = 300
// c = 44
```

No fluxograma, a comparação não pergunta "-1 é maior que 0?". Antes dela já
houve uma conversão, e a pergunta real é sobre 4294967295:

<p align="center"><img src="27-c-detalhes/0171-com-e-sem-sinal/fluxograma.svg" alt="Fluxograma: Com sinal e sem sinal" width="435"></p>

> [!WARNING]
> O laço que desce com `size_t` nunca termina:
> `for (size_t i = n - 1; i >= 0; i--)`. Um `size_t` é sempre `>= 0`; quando
> `i` passa de 0, ele vira 18446744073709551615 e o laço lê fora do vetor. O
> gcc avisa ("comparison of unsigned expression in '>= 0' is always true").
> Escreva `for (size_t i = n; i-- > 0;)`: testa e depois desce, e funciona até
> com `n = 0`. Primo do mesmo erro, e sem aviso nenhum:
> `if (strlen(a) - strlen(b) > 0)` é verdadeiro sempre que os tamanhos são
> diferentes, porque a subtração de dois `size_t` nunca dá negativo.

> [!TIP]
> **Por dentro do C:** o processador usa o **complemento de dois**: o negativo
> de `x` é `~x + 1`. Com isso, somar com ou sem sinal é **a mesma
> instrução** (`add`), e a conversão entre `int` e `unsigned` não custa
> nada: os bits ficam iguais. O que muda é a instrução que lê o
> resultado: comparações com sinal usam `jl`/`jg`, sem sinal usam `jb`/`ja`,
> e o deslocamento à direita vira `sar` (copia o bit de sinal: `-16 >> 2` dá
> -4 no gcc) ou `shr` (entra zero). Deslocar um negativo para a direita é
> "definido pela implementação"; para a esquerda, é indefinido. Para bits e
> máscaras, use sempre `unsigned`.

> [!NOTE]
> **Pergunta para você:** com `unsigned char x = 0x0F;`, quanto vale `~x`? É
> 0xF0 (240) ou um número negativo? Pense na promoção inteira antes de rodar
> `printf("%d\n", ~x);`.

### Hora de praticar

Arquivos em [`0171-com-e-sem-sinal/`](27-c-detalhes/0171-com-e-sem-sinal/).

**Exemplo A341 · Descendo com size_t sem cair do zero**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    int notas[] = {7, 9, 6, 10};
    size_t n = sizeof notas / sizeof notas[0]; // sizeof devolve size_t

    // testa e depois desce: i vale n-1, n-2, ..., 0 dentro do laço
    printf("de trás para a frente:");
    for (size_t i = n; i-- > 0;) {
        printf(" %d", notas[i]);
    }
    printf("\n");

    // a mesma forma não faz nada com um vetor vazio
    size_t vazio = 0;
    int voltas = 0;
    for (size_t i = vazio; i-- > 0;) {
        voltas++;
    }
    printf("com n = 0: %d voltas\n", voltas);

    // por que "for (size_t i = n - 1; ...)" é perigoso: n - 1 com n = 0
    printf("vazio - 1 = %zu\n", vazio - 1);

    // diferença de tamanhos: size_t menos size_t nunca é negativo
    const char *a = "Ana";
    const char *b = "Bernardo";
    printf("strlen(a) - strlen(b) = %zu\n", strlen(a) - strlen(b));
    printf("Ana é mais longo? %s (com a subtração)\n", strlen(a) - strlen(b) > 0 ? "sim" : "não");
    printf("Ana é mais longo? %s (comparando direto)\n", strlen(a) > strlen(b) ? "sim" : "não");
    return 0;
}
// Saída:
// de trás para a frente: 10 6 9 7
// com n = 0: 0 voltas
// vazio - 1 = 18446744073709551615
// strlen(a) - strlen(b) = 18446744073709551611
// Ana é mais longo? sim (com a subtração)
// Ana é mais longo? não (comparando direto)
```

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/A341.c
```

**Exemplo A342 · Promoção, conversão e deslocamento**

```c
#include <stdio.h>

int main(void) {
    // promoção inteira: o byte vira int antes do ~
    unsigned char x = 0x0F; // 0000 1111
    printf("~x = %d\n", ~x);                          // ~15 em int
    printf("(unsigned char)~x = %d\n", (unsigned char)~x); // de volta a 1 byte
    printf("sizeof x = %zu, sizeof(x + x) = %zu\n", sizeof x, sizeof(x + x));

    // conversão aritmética usual
    int i = -1;
    unsigned u = 1u;
    printf("i + u = %u\n", i + u);  // i vira unsigned: 4294967295 + 1 dá a volta
    printf("i - u = %u\n", i - u);  // seria -2, mas o resultado é unsigned
    long l = -1;                    // long de 64 bits cabe todo unsigned
    printf("l - u = %ld\n", l - u); // aqui o u vira long, e o -2 sobrevive

    // deslocamento à direita: divide por 2 a cada casa, mas arredonda diferente
    int queda = -17;
    // (o >> de um negativo depende do compilador; o gcc copia o bit de sinal)
    printf("-17 / 4 = %d, -17 >> 2 = %d\n", queda / 4, queda >> 2);
    unsigned positivo = 17u;
    printf(" 17 / 4 = %u,  17 >> 2 = %u\n", positivo / 4, positivo >> 2);

    // máscara: o cartão guarda o mês da validade nos 4 bits de baixo
    // e o ano (desde 2000) nos bits de cima
    unsigned validade = (31u << 4) | 9u; // 09/2031
    printf("validade: %02u/%u\n", validade & 0xFu, 2000u + (validade >> 4));
    return 0;
}
// Saída:
// ~x = -16
// (unsigned char)~x = 240
// sizeof x = 1, sizeof(x + x) = 4
// i + u = 0
// i - u = 4294967294
// l - u = -2
// -17 / 4 = -4, -17 >> 2 = -5
//  17 / 4 = 4,  17 >> 2 = 4
// validade: 09/2031
```

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/A342.c
```

#### Exercícios

**Exercício E1021** · ★☆☆

Um unsigned char é um odômetro de 0 a 255. Escreva um programa que:


```text
- começa um unsigned char contador em 250 e, num laço de 10 voltas,
  soma 1 e mostra o valor, tudo na mesma linha;
- começa um unsigned char vidas em 2 e, num laço de 3 voltas, tira 1 e
  mostra o valor.
```



```text
Saída esperada:
contador: 251 252 253 254 255 0 1 2 3 4
vidas: 1 0 255
```

**Dicas:**

1. contador++ num unsigned char: 255 + 1 dá a volta para 0, e isso é
   definido pelo padrão (conta módulo 256).
2. Para mostrar, %d serve: o byte vira int ao entrar no printf.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/E1021.c
```

**Exercício E1022** · ★☆☆

Usando as constantes de <limits.h> (SCHAR_MIN, SCHAR_MAX, UCHAR_MAX,
SHRT_MIN, SHRT_MAX, USHRT_MAX, INT_MIN, INT_MAX, UINT_MAX, LONG_MIN,
LONG_MAX, ULONG_MAX) e o sizeof, mostre o tamanho e a faixa de cada tipo
inteiro, com e sem sinal. Os valores abaixo são os de um PC de 64 bits com
Linux.


```text
Saída esperada:
signed char:    1 bytes, -128 a 127
unsigned char:  1 bytes, 0 a 255
short:          2 bytes, -32768 a 32767
unsigned short: 2 bytes, 0 a 65535
int:            4 bytes, -2147483648 a 2147483647
unsigned:       4 bytes, 0 a 4294967295
long:           8 bytes, -9223372036854775808 a 9223372036854775807
unsigned long:  8 bytes, 0 a 18446744073709551615
```

**Dicas:**

1. sizeof devolve size_t: mostre com %zu.
2. Formato certo: %d para o que cabe em int (inclusive UCHAR_MAX e
   USHRT_MAX), %u para UINT_MAX, %ld para long, %lu para unsigned long.
3. O mesmo número de bits dá a mesma quantidade de valores: o com sinal
   só divide metade para os negativos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/E1022.c
```

**Exercício E1023** · ★★☆

Este laço, que deveria mostrar a fila de trás para a frente, nunca
termina (e o gcc avisa que "i >= 0" é sempre verdadeiro):


```text
for (size_t i = n - 1; i >= 0; i--) printf(" %s", fila[i]);
```


Escreva, com índices size_t que descem sem cair do zero:


```text
- void mostrar_ao_contrario(const char *fila[], size_t n): mostra os
  nomes do último ao primeiro, ou "(nada)" se n for 0;
- size_t ultimo_par(const int *v, size_t n): procura de trás para a
  frente e devolve o índice do último número par, ou n se não houver.
```


Teste com a fila {"Ana", "Bia", "Caio"}, com uma fila vazia, e com os
vetores {3, 8, 5, 4, 7} e {1, 3}.


```text
Saída esperada:
fila: Caio Bia Ana
fila vazia: (nada)
ultimo par em {3, 8, 5, 4, 7}: indice 3
ultimo par em {1, 3}: nenhum
```

**Dicas:**

1. for (size_t i = n; i-- > 0;) testa i > 0 e só então desce: dentro do
   laço, i vai de n - 1 até 0.
2. "Não achei" com size_t não pode ser -1: devolva n, que nunca é um
   índice válido.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/E1023.c
```

**Exercício E1024** · ★★☆

As duas funções abaixo compilam sem nenhum aviso, mas erram por causa do
size_t, que nunca é negativo:


```text
- mais_longo devolve o nome mais comprido (no empate, o segundo);
- restantes diz quantos caracteres ainda cabem numa mensagem de até
  limite caracteres, e deve dar 0 quando a mensagem já passou.
```


Conserte as duas sem mudar a assinatura nem o main.


```text
Saída esperada:
mais longo: Bernardo
mais longo: Bernardo
restam 7 caracteres
restam 0 caracteres
```

**Dicas:**

1. Rode antes: a primeira linha sai Ana, e a última, um número enorme.
2. strlen(a) - strlen(b) > 0 é verdadeiro sempre que os tamanhos são
   diferentes. Compare os dois direto.
3. Em restantes, teste se a mensagem passou do limite ANTES de subtrair.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/E1024.c
```

**Exercício E1025** · ★★★

Um leitor de código de barras manda os bytes de um boleto e, no fim, um
byte verificador: o número que, somado a todos os bytes, dá 0 módulo 256.
Escreva:


```text
- unsigned char verificador(const unsigned char *d, size_t n);
- bool confere(const unsigned char *d, size_t n, unsigned char v), que
  soma os bytes e o v e diz se o byte da soma é 0.
```


Teste com os bytes {0x12, 0xA0, 0xFF, 0x31} e depois troque o 0xA0 por
0xA1, como se um bit tivesse se perdido na transmissão.


```text
Saída esperada:
verificador = 0x1E
original: confere
alterado: nao confere
```

**Dicas:**

1. A soma dos bytes é 482, e 482 % 256 = 226. Falta 30 (0x1E) para 256.
2. Some num unsigned char e devolva (unsigned char)(0u - soma): a conta
   sem sinal dá a volta exatamente como precisa.
3. Cuidado com a promoção: soma + v vira int, e 226 + 30 = 256, que não é
   0. Escreva (unsigned char)(soma + v) == 0.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/E1025.c
```

**Exercício E1026** · ★★★

Escreva três funções que fazem contas com unsigned sem cair nas
pegadinhas, e teste com os valores da saída:


```text
- unsigned sub_saturada(unsigned a, unsigned b): a - b, mas para em 0
  em vez de dar a volta;
- bool soma_cabe(unsigned a, unsigned b): diz se a + b cabe num
  unsigned, SEM fazer a soma que estoura;
- int compara(int a, unsigned b): devolve -1, 0 ou 1 conforme a é menor,
  igual ou maior que b na matemática de verdade (-1 é menor que 0u!).
```



```text
Saída esperada:
sub_saturada(2, 3) = 0
sub_saturada(10, 3) = 7
soma_cabe(4000000000, 300000000) = nao
soma_cabe(4000000000, 294967295) = sim
compara(-1, 0) = -1
compara(5, 5) = 0
compara(7, 3) = 1
```

**Dicas:**

1. sub_saturada: se a < b, devolva 0.
2. a + b cabe quando a <= UINT_MAX - b (essa subtração nunca dá a volta).
3. compara: trate a < 0 primeiro. Depois a já é positivo, e
   (unsigned)a é seguro.
4. (x > y) - (x < y) dá -1, 0 ou 1 numa linha só.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0171-com-e-sem-sinal/E1026.c
```

---

## 0172 · Vetor de tamanho variável (VLA)

A academia do bairro quer uma planilha de treinos: uma linha por aluno, uma
coluna por semana. Só que o número de alunos e de semanas muda a cada
turma, e só é conhecido quando o professor digita. Até aqui, você teria duas
saídas: reservar uma matriz enorme "por garantia" ou chamar o `malloc`.

O C99 trouxe uma terceira: o **VLA** (*variable length array*, vetor de
tamanho variável). É um vetor local cujo tamanho é uma expressão calculada
na hora, não uma constante: `int treinos[alunos][semanas];`. Ele mora na
**pilha**, como qualquer variável local, e some sozinho no fim do bloco. Não
tem `free`.

Com o VLA, o `sizeof` deixa de ser uma constante do compilador: `sizeof
treinos` é calculado **em tempo de execução**, e vale `alunos * semanas *
sizeof(int)`. O VLA também tem limites: não pode ser `static` nem global, e
não aceita inicialização (`int v[n] = {0};` é erro no C17). Preencha com um
laço.

O uso mais útil é como **parâmetro**. Uma função comum precisa saber a
largura da matriz já ao compilar (`int m[][4]`). Com VLA, a função recebe as
dimensões e a matriz: `void f(int l, int c, int m[l][c])`. A ordem importa:
`l` e `c` vêm **antes**, porque o tipo `m[l][c]` usa os dois. Assim uma
só função serve para matrizes de qualquer tamanho.

Um detalhe de versão: no C99 o VLA é obrigatório; no C11 e no C17 virou
**opcional**. Um compilador sem VLA define a macro `__STDC_NO_VLA__`. O gcc
e o clang suportam; o compilador da Microsoft, não. Quem quer garantir
escreve:

```c
#ifdef __STDC_NO_VLA__
#error "este programa precisa de VLA"
#endif
```

Com 3 alunos e 4 semanas, a planilha tem 12 `int`:
48 bytes, reservados na pilha no momento em que a linha do VLA roda. O
desenho mostra a matriz e onde ela fica:

<p align="center"><img src="27-c-detalhes/0172-vla/ideia.svg" alt="Diagrama da ideia: Vetor de tamanho variável (VLA)" width="858"></p>

O programa lê as dimensões, confere, cria o VLA e passa para as funções:

```c
#include <stdio.h>

// treinos fictícios de cada aluno em cada semana (1 a 5)
void preencher(int l, int c, int m[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = (3 * i + 2 * j) % 5 + 1;
        }
    }
}

// as dimensões vêm ANTES da matriz: o tipo m[l][c] usa l e c
int total_do_aluno(int l, int c, int m[l][c], int aluno) {
    int soma = 0;
    for (int j = 0; j < c; j++) {
        soma += m[aluno][j];
    }
    return soma;
}

int main(void) {
    int alunos, semanas;
    printf("Alunos e semanas: ");
    if (scanf("%d %d", &alunos, &semanas) != 2 || alunos < 1 || alunos > 100 ||
        semanas < 1 || semanas > 52) {
        printf("valores inválidos\n"); // VLA de tamanho <= 0 é indefinido
        return 1;
    }

    int treinos[alunos][semanas]; // VLA: o tamanho só existe agora
    printf("sizeof treinos = %zu bytes\n", sizeof treinos); // calculado na hora

    preencher(alunos, semanas, treinos);
    for (int i = 0; i < alunos; i++) {
        printf("aluno %d:", i + 1);
        for (int j = 0; j < semanas; j++) {
            printf(" %d", treinos[i][j]);
        }
        printf("  total %d\n", total_do_aluno(alunos, semanas, treinos, i));
    }
    return 0;
}
// Saída (digitando 3 4):
// Alunos e semanas: 3 4
// sizeof treinos = 48 bytes
// aluno 1: 1 3 5 2  total 11
// aluno 2: 4 1 3 5  total 13
// aluno 3: 2 4 1 3  total 10
```

No fluxograma, a validação vem **antes** do VLA. Depois que a linha
`int treinos[alunos][semanas];` roda, não há como desistir nem como saber se
deu certo:

<p align="center"><img src="27-c-detalhes/0172-vla/fluxograma.svg" alt="Fluxograma: Vetor de tamanho variável (VLA)" width="532"></p>

> [!WARNING]
> O VLA não avisa quando falha. O `malloc` devolve `NULL` se não houver
> memória; o VLA pede o espaço à pilha, e a pilha de um programa
> no Linux tem uns **8 MB** (confira com `ulimit -s`). Um `int v[n]` com `n`
> igual a 3 milhões pede 12 MB e derruba o programa com *segmentation
> fault*, sem chance de tratar. E um `n` que veio do usuário pode ser 0,
> negativo ou gigante. Regra prática: VLA só para tamanhos **pequenos e
> conferidos**; para dados grandes ou de tamanho desconhecido, `malloc`.

> [!TIP]
> **Por dentro do C:** um vetor comum tem tamanho fixo, e o compilador já
> sabe, ao compilar, quanto descer o ponteiro da pilha (`sub rsp, 48`). Com
> VLA, ele gera código que calcula `alunos * semanas * 4` na hora e desce o
> ponteiro da pilha por esse valor: é tão rápido quanto uma variável local,
> muito mais que o `malloc`. Por isso o `sizeof` de um VLA é uma conta feita
> em tempo de execução. Dá para ter o melhor dos dois: `int (*m)[c] =
> malloc(l * sizeof *m);` cria a matriz no heap, com tipo VLA, e você
> continua escrevendo `m[i][j]` (veja o A344).

> [!NOTE]
> **Pergunta para você:** se o professor digitar `100 52`, quantos bytes
> o `sizeof treinos` mostra? E quantas planilhas desse tamanho caberiam numa
> pilha de 8 MB?

### Hora de praticar

Arquivos em [`0172-vla/`](27-c-detalhes/0172-vla/).

**Exemplo A343 · O sizeof que é calculado na hora**

```c
#include <stdio.h>

// uma barra do gráfico de vendas: o tamanho do vetor muda a cada chamada
void barra(const char *dia, int vendas) {
    char linha[vendas + 1]; // as estrelas + o '\0'
    for (int i = 0; i < vendas; i++) {
        linha[i] = '#';
    }
    linha[vendas] = '\0';
    printf("%s %-9s (sizeof linha = %zu)\n", dia, linha, sizeof linha);
}

int main(void) {
#ifdef __STDC_NO_VLA__
    printf("este compilador não tem VLA\n");
    return 1;
#else
    printf("este compilador tem VLA\n");
#endif

    const char *dias[] = {"seg", "ter", "qua", "qui"};
    int vendas[] = {3, 7, 5, 8};
    for (int i = 0; i < 4; i++) {
        barra(dias[i], vendas[i]); // cada chamada cria e destrói o seu VLA
    }

    // sizeof de um tipo VLA também é uma conta em tempo de execução
    int n = 6;
    printf("sizeof(int[n]) com n = %d: %zu\n", n, sizeof(int[n]));
    printf("sizeof(double[n][2]):      %zu\n", sizeof(double[n][2]));
    return 0;
}
// Saída:
// este compilador tem VLA
// seg ###       (sizeof linha = 4)
// ter #######   (sizeof linha = 8)
// qua #####     (sizeof linha = 6)
// qui ########  (sizeof linha = 9)
// sizeof(int[n]) com n = 6: 24
// sizeof(double[n][2]):      96
```

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/A343.c
```

**Exemplo A344 · A matriz grande vai para o heap**

```c
#include <stdio.h>
#include <stdlib.h>

// a função não sabe se a matriz veio da pilha ou do heap: tanto faz
long long somar(int l, int c, int m[l][c]) {
    long long soma = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            soma += m[i][j];
        }
    }
    return soma;
}

int main(void) {
    int l = 2000, c = 1000; // 2 milhões de int: 8 MB, a pilha inteira

    // int m[l][c]; aqui derrubaria o programa. No heap, cabe:
    // m é um ponteiro para linhas de c int (um tipo VLA)
    int (*m)[c] = malloc(l * sizeof *m);
    if (m == NULL) {
        printf("sem memória\n"); // o malloc avisa; o VLA não avisaria
        return 1;
    }
    printf("sizeof *m = %zu bytes por linha\n", sizeof *m);
    printf("total = %zu bytes\n", l * sizeof *m);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = i + j; // continua m[i][j], como numa matriz comum
        }
    }
    printf("m[1999][999] = %d\n", m[1999][999]);
    printf("soma = %lld\n", somar(l, c, m));

    free(m); // um malloc, um free: a matriz é um bloco só
    return 0;
}
// Saída:
// sizeof *m = 4000 bytes por linha
// total = 8000000 bytes
// m[1999][999] = 2998
// soma = 2998000000
```

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/A344.c
```

#### Exercícios

**Exercício E1027** · ★☆☆

Escreva void multiplos(int base, int n), que cria um VLA int t[n], guarda
nele os n primeiros múltiplos de base, mostra os valores e, no fim da
linha, o sizeof t. Chame com (7, 3) e com (9, 5).


```text
Saída esperada:
7: 7 14 21 (12 bytes)
9: 9 18 27 36 45 (20 bytes)
```

**Dicas:**

1. t[i] = base * (i + 1).
2. sizeof t de um VLA é calculado na hora: n * sizeof(int). Mostre com
   %zu.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/E1027.c
```

**Exercício E1028** · ★☆☆

Uma rede tem 3 lojas, e a matriz guarda as vendas (em mil reais) de cada
loja em cada trimestre. Escreva, com a matriz como parâmetro VLA:


```text
int soma_linha(int l, int c, int m[l][c], int i)   // total da loja i
int soma_coluna(int l, int c, int m[l][c], int j)  // total do trimestre j
```


e mostre o total de cada loja e de cada trimestre.


```text
Saída esperada:
loja 1: 100
loja 2: 80
loja 3: 32
trimestre 1: 23
trimestre 2: 43
trimestre 3: 63
trimestre 4: 83
```

**Dicas:**

1. Uma matriz comum int m[3][4] pode ser passada para um parâmetro VLA:
   soma_linha(3, 4, vendas, 0).
2. As dimensões vêm antes da matriz na lista de parâmetros.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/E1028.c
```

**Exercício E1029** · ★★☆

Escreva duas funções com parâmetros VLA:


```text
void mostrar(int l, int c, int m[l][c])
void transpor(int l, int c, int a[l][c], int t[c][l])
```


A transposta troca linhas por colunas: t[j][i] = a[i][j]. No main, com
int l = 2, c = 3, crie os VLAs a[l][c] e t[c][l], preencha a com 1 a 6
(linha por linha), transponha e mostre as duas.


```text
Saída esperada:
original (2 x 3):
  1  2  3
  4  5  6
transposta (3 x 2):
  1  4
  2  5
  3  6
```

**Dicas:**

1. Um VLA não aceita "= {...}": preencha com a[i][j] = i * c + j + 1.
2. Cuidado: t tem as dimensões trocadas, t[c][l].
3. Cada número com %3d.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/E1029.c
```

**Exercício E1030** · ★★☆

O programa abaixo calcula o preço médio de n produtos guardados num VLA.
Com n = 10 ele funciona. Mas o cliente tem 3 milhões de produtos: 24 MB,
três vezes a pilha. Refatore:


```text
- troque o VLA por double *precos = malloc(...), confira NULL e libere
  com free no fim;
- mude n para 3000000.
```



```text
Saída esperada:
n = 3000000, media = R$ 50.00
```

**Dicas:**

1. Rode antes, com n = 10: sai media = R$ 5.00.
2. malloc(n * sizeof *precos). Se der NULL, mostre "sem memória" e
   devolva 1.
3. O resto do código não muda: precos[i] funciona igual com o ponteiro.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/E1030.c
```

**Exercício E1031** · ★★★

Duas lojas fazem a compra do mês de 3 produtos (arroz, feijão, café), e
dois fornecedores, A e B, cobram preços diferentes. Multiplique a matriz
de quantidades (lojas x produtos) pela de preços (produtos x
fornecedores) para obter o custo de cada loja em cada fornecedor:


```text
void multiplicar(int l, int m, int c, int a[l][m], int b[m][c], int r[l][c])
```


Depois mostre o custo e o fornecedor mais barato para cada loja.


```text
quantidades:  loja 1: 10, 0, 5     loja 2: 2, 8, 4
preços:       arroz: A 3, B 4      feijão: A 6, B 5    café: A 2, B 1
```



```text
Saída esperada:
loja 1: A = R$ 40, B = R$ 45 -> melhor A
loja 2: A = R$ 62, B = R$ 52 -> melhor B
```

**Dicas:**

1. r[i][j] é a soma, para k de 0 a m - 1, de a[i][k] * b[k][j].
2. As três dimensões vêm antes das matrizes. Crie r como VLA no main,
   com int lojas = 2, fornecedores = 2.
3. Zere r[i][j] antes de acumular: VLA não pode ser inicializado com {0}.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/E1031.c
```

**Exercício E1032** · ★★★

Escreva long long soma_quadrados(int n), que soma 1² + 2² + ... + n²
guardando os quadrados num vetor antes de somar. A função escolhe onde
pôr o vetor:


```text
- n <= 0: não cria nada e devolve -1;
- n <= 1000: um VLA long long v[n] na pilha (mostra "pilha, ");
- n maior: malloc (mostra "heap, "), com NULL conferido e free.
```


No main, para n = 0, 10 e 100000, mostre "n = ...: " e depois "invalido"
ou "soma = ...".


```text
Saída esperada:
n = 0: invalido
n = 10: pilha, soma = 385
n = 100000: heap, soma = 333338333350000
```

**Dicas:**

1. O VLA vai dentro do bloco do if: ele só existe ali, e só é criado
   quando o n já foi conferido.
2. Para o quadrado não estourar o int, converta antes de multiplicar:
   (long long)(i + 1) * (i + 1).
3. Confira com a fórmula n(n + 1)(2n + 1) / 6.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0172-vla/E1032.c
```

---

## 0173 · Juntando tudo: o controle de acesso

O coworking do centro tem porta com crachá, sala de reunião, impressora,
garagem e painel de configuração. Cada pessoa tem um papel (visitante, membro
ou admin), e o papel dá um pacote de permissões. Mas há exceções: o Bruno,
membro, aluga uma vaga na garagem; a Carla estourou a cota da impressora.

Cada peça do módulo entra numa parte. As permissões são **bits** num
`unsigned`, e o papel é um **enum** que indexa o vetor `base` com o pacote de
cada um. A **struct** `Usuario` guarda o papel e duas máscaras de exceção:
`extra` (o que ganhou a mais) e `bloqueio` (o que perdeu). A permissão
efetiva sai de uma expressão só:

`(base[u->papel] | u->extra) & ~u->bloqueio`

Leia com a tabela de precedência na mão. O `|` junta o pacote e os extras;
os parênteses são obrigatórios, porque `&` vem antes de `|`. O `~` (nível 2)
inverte o bloqueio antes de tudo, e o `&` com ele apaga os bits bloqueados:
**o bloqueio vence**. E a pergunta "pode tudo desta máscara?" é
`(efetivas & mascara) == mascara`, de novo com parênteses, porque o `==` vem
antes do `&`.

Tudo é `unsigned`, de propósito: `~` num `int` daria um negativo, e misturar
com sinal e sem sinal abre a porta para o `-1 > 0u`. A planilha final,
usuário × permissão, é um **VLA** `bool
acesso[n][QTD_PERMS]`: o `n` é uma variável, o tamanho é decidido na hora, e
uma equipe maior não muda o código.

A Carla é membro (`00111`: imprimir, reunião, entrar),
sem extras e com a impressora bloqueada. O desenho faz a conta bit a bit:

<p align="center"><img src="27-c-detalhes/0173-juntando-tudo/ideia.svg" alt="Diagrama da ideia: Juntando tudo: o controle de acesso" width="858"></p>

O programa monta a planilha e responde quem pode usar a sala de reunião **e**
imprimir:

```c
#include <stdbool.h>
#include <stdio.h>

typedef enum { VISITANTE, MEMBRO, ADMIN, QTD_PAPEIS } Papel;

// cada permissão é um bit
#define ENTRAR   (1u << 0) // E
#define REUNIAO  (1u << 1) // R
#define IMPRIMIR (1u << 2) // I
#define GARAGEM  (1u << 3) // G
#define CONFIG   (1u << 4) // C
#define QTD_PERMS 5

typedef struct {
    char nome[16];
    Papel papel;
    unsigned extra;    // concedidas além do papel
    unsigned bloqueio; // retiradas, mesmo que o papel dê
} Usuario;

// o que cada papel ganha de saída (na ordem do enum)
const unsigned base[QTD_PAPEIS] = {
    ENTRAR,                                          // visitante
    ENTRAR | REUNIAO | IMPRIMIR,                     // membro
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,  // admin
};

unsigned efetivas(const Usuario *u) {
    return (base[u->papel] | u->extra) & ~u->bloqueio; // o bloqueio vence
}

bool pode(const Usuario *u, unsigned mascara) {
    return (efetivas(u) & mascara) == mascara; // tem TODAS da máscara
}

int main(void) {
    Usuario equipe[] = {
        {"Ana", ADMIN, 0, 0},
        {"Bruno", MEMBRO, GARAGEM, 0},
        {"Carla", MEMBRO, 0, IMPRIMIR}, // estourou a cota da impressora
        {"Davi", VISITANTE, REUNIAO, 0},
    };
    int n = 4; // uma variável: a matriz abaixo é um VLA
    const char *papeis[QTD_PAPEIS] = {"visitante", "membro", "admin"};

    bool acesso[n][QTD_PERMS]; // usuário x permissão
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < QTD_PERMS; b++) {
            acesso[i][b] = pode(&equipe[i], 1u << b);
        }
    }

    printf("usuario  papel      E R I G C\n");
    for (int i = 0; i < n; i++) {
        printf("%-8s %-10s", equipe[i].nome, papeis[equipe[i].papel]);
        for (int b = 0; b < QTD_PERMS; b++) {
            printf(" %c", acesso[i][b] ? 'X' : '-');
        }
        printf("\n");
    }

    printf("pode REUNIAO | IMPRIMIR:");
    for (int i = 0; i < n; i++) {
        if (pode(&equipe[i], REUNIAO | IMPRIMIR)) {
            printf(" %s", equipe[i].nome);
        }
    }
    printf("\n");
    return 0;
}
// Saída:
// usuario  papel      E R I G C
// Ana      admin      X X X X X
// Bruno    membro     X X X X -
// Carla    membro     X X - - -
// Davi     visitante  X X - - -
// pode REUNIAO | IMPRIMIR: Ana Bruno
```

O fluxograma responde "pode `REUNIAO | IMPRIMIR`?" com um laço pela equipe e
uma única comparação de bits por pessoa. A máscara pode ter uma permissão ou
cinco, e o custo é o mesmo:

<p align="center"><img src="27-c-detalhes/0173-juntando-tudo/fluxograma.svg" alt="Fluxograma: Juntando tudo: o controle de acesso" width="553"></p>

> [!WARNING]
> Duas linhas parecidas, dois programas diferentes. `efetivas(u) & mascara ==
> mascara` é lido como `efetivas(u) & (mascara == mascara)`, isto é,
> `efetivas(u) & 1`: só olha o bit de ENTRAR (o gcc avisa). E
> `p = p | ~IMPRIMIR` em vez de `p = p & ~IMPRIMIR` não tira a impressora:
> **liga todas as outras** permissões, até as que não existem. Esse erro
> compila sem aviso nenhum.

> [!TIP]
> **Por dentro do C:** um `Usuario` ocupa 28 bytes: 16 do nome, 4 do enum e 4
> de cada máscara. Cinco permissões como `bool` seriam 5 campos e cinco `if`;
> como bits, são 4 bytes para até 32 permissões, e `pode` vira três
> instruções (`or`, `and`, `cmp`). O VLA `acesso[4][5]` são 20 bytes na
> pilha; com 10 milhões de usuários, troque por `malloc`.

> [!NOTE]
> **Pergunta para você:** que máscara de `extra` o Davi precisaria para poder
> imprimir? E se a Ana ganhar `bloqueio = CONFIG | GARAGEM`, como fica a linha
> dela na planilha?

### Hora de praticar

Arquivos em [`0173-juntando-tudo/`](27-c-detalhes/0173-juntando-tudo/).

**Exemplo A345 · Auditoria: quem fugiu do pacote do papel**

```c
#include <stdio.h>

typedef enum { VISITANTE, MEMBRO, ADMIN, QTD_PAPEIS } Papel;

#define ENTRAR   (1u << 0)
#define REUNIAO  (1u << 1)
#define IMPRIMIR (1u << 2)
#define GARAGEM  (1u << 3)
#define CONFIG   (1u << 4)
#define QTD_PERMS 5

typedef struct {
    char nome[16];
    Papel papel;
    unsigned extra;
    unsigned bloqueio;
} Usuario;

const unsigned base[QTD_PAPEIS] = {
    ENTRAR,
    ENTRAR | REUNIAO | IMPRIMIR,
    ENTRAR | REUNIAO | IMPRIMIR | GARAGEM | CONFIG,
};

unsigned efetivas(const Usuario *u) {
    return (base[u->papel] | u->extra) & ~u->bloqueio;
}

// escreve as letras dos bits ligados, ou "nada"
void letras(unsigned m, char saida[QTD_PERMS + 1]) {
    const char nomes[] = "ERIGC";
    int k = 0;
    for (int b = 0; b < QTD_PERMS; b++) {
        if (m & (1u << b)) {
            saida[k++] = nomes[b];
        }
    }
    saida[k] = '\0';
}

int contar_bits(unsigned m) {
    int n = 0;
    while (m != 0) {
        m &= m - 1; // apaga o bit 1 mais baixo
        n++;
    }
    return n;
}

int main(void) {
    Usuario equipe[] = {
        {"Ana", ADMIN, 0, 0},
        {"Bruno", MEMBRO, GARAGEM, 0},
        {"Carla", MEMBRO, 0, IMPRIMIR},
        {"Davi", VISITANTE, REUNIAO, ENTRAR | CONFIG}, // bloqueio de algo que nem tinha
    };
    for (int i = 0; i < 4; i++) {
        unsigned b = base[equipe[i].papel];
        unsigned e = efetivas(&equipe[i]);
        unsigned diferentes = b ^ e;     // XOR: 1 onde o papel e o real discordam
        unsigned ganhou = e & ~b;        // tem, mas o papel não dava
        unsigned perdeu = b & ~e;        // o papel dava, mas não tem
        char g[QTD_PERMS + 1], p[QTD_PERMS + 1];
        letras(ganhou, g);
        letras(perdeu, p);
        printf("%-6s %d diferença(s)  ganhou: %-3s perdeu: %s\n", equipe[i].nome,
               contar_bits(diferentes), g[0] ? g : "-", p[0] ? p : "-");
    }
    return 0;
}
// Saída:
// Ana    0 diferença(s)  ganhou: -   perdeu: -
// Bruno  1 diferença(s)  ganhou: G   perdeu: -
// Carla  1 diferença(s)  ganhou: -   perdeu: I
// Davi   2 diferença(s)  ganhou: R   perdeu: E
```

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/A345.c
```

**Exemplo A346 · O que a equipe inteira tem**

```c
#include <stdio.h>

#define ENTRAR   (1u << 0)
#define REUNIAO  (1u << 1)
#define IMPRIMIR (1u << 2)
#define GARAGEM  (1u << 3)
#define CONFIG   (1u << 4)
#define QTD_PERMS 5

void mostrar(const char *titulo, unsigned m) {
    const char nomes[] = "ERIGC";
    for (int b = 0; b < QTD_PERMS; b++) {
        printf("%c", (m & (1u << b)) ? nomes[b] : '-');
    }
    printf("  %s\n", titulo);
}

int main(void) {
    // as permissões efetivas de uma equipe de tamanho variável
    unsigned todas[] = {
        ENTRAR | REUNIAO | IMPRIMIR | GARAGEM,
        ENTRAR | REUNIAO | GARAGEM,
        ENTRAR | REUNIAO,
        ENTRAR | REUNIAO,
        ENTRAR | IMPRIMIR,
    };
    int n = 5;
    unsigned equipe[n]; // VLA: só a equipe deste turno
    for (int i = 0; i < n; i++) {
        equipe[i] = todas[i];
    }

    unsigned alguem = 0;     // começa sem nada: o OU vai acendendo
    unsigned todo_mundo = ~0u; // começa com tudo: o E vai apagando
    for (int i = 0; i < n; i++) {
        alguem |= equipe[i];
        todo_mundo &= equipe[i];
    }
    mostrar("alguém tem", alguem);
    mostrar("todo mundo tem", todo_mundo);
    mostrar("ninguém tem (dos 5 bits)", ~alguem & ((1u << QTD_PERMS) - 1)); // só 5 bits

    // contagem por permissão numa matriz VLA permissão x pessoa
    int perms = QTD_PERMS;
    int tem[perms][n];
    for (int b = 0; b < perms; b++) {
        for (int i = 0; i < n; i++) {
            tem[b][i] = (equipe[i] >> b) & 1u;
        }
    }
    printf("quantos têm cada uma:");
    for (int b = 0; b < perms; b++) {
        int soma = 0;
        for (int i = 0; i < n; i++) {
            soma += tem[b][i];
        }
        printf(" %c=%d", "ERIGC"[b], soma);
    }
    printf("\n");
    return 0;
}
// Saída:
// ERIG-  alguém tem
// E----  todo mundo tem
// ----C  ninguém tem (dos 5 bits)
// quantos têm cada uma: E=5 R=4 I=2 G=2 C=0
```

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/A346.c
```

#### Exercícios

**Exercício E1033** · ★☆☆

Escreva as três operações básicas sobre as permissões de uma pessoa:


```text
void conceder(unsigned *p, unsigned m)  // liga os bits de m
void revogar(unsigned *p, unsigned m)   // desliga os bits de m
bool tem(unsigned p, unsigned m)        // p tem TODOS os bits de m?
```


Comece com p = ENTRAR, conceda REUNIAO | IMPRIMIR, revogue IMPRIMIR e
teste REUNIAO e depois REUNIAO | IMPRIMIR, mostrando p a cada passo.


```text
Saída esperada:
inicio: 1
conceder R|I: 7
revogar I: 3
tem R? sim
tem R|I? nao
```

**Dicas:**

1. Ligar: *p |= m. Desligar: *p &= ~m.
2. "Todos": (p & m) == m, com os parênteses (o == vem antes do &).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/E1033.c
```

**Exercício E1034** · ★☆☆

Escreva as duas conversões entre as permissões e o texto do relatório,
na ordem E R I G C (bit 0 a bit 4), com '-' para a que falta:


```text
void para_texto(unsigned p, char s[QTD_PERMS + 1])  // 21 -> "E-I-C"
unsigned de_texto(const char *s)                     // "ER-G-" -> 11
```



```text
Saída esperada:
E-I-C
ER-G- = 11
```

**Dicas:**

1. Guarde as letras numa string "ERIGC": a letra do bit b é letras[b].
2. Em de_texto, qualquer caractere diferente de '-' na posição b liga o
   bit b: p |= 1u << b.
3. Não esqueça o '\0' em s[QTD_PERMS].
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/E1034.c
```

**Exercício E1035** · ★★☆

As duas funções abaixo compilam sem nenhum aviso, mas estão erradas:


```text
- revogar deveria tirar as permissões de m, e devolve um número enorme;
- tem_todas deveria responder se p tem TODAS as permissões de m, e
  responde se tem ALGUMA.
```


Conserte as duas, sem mexer no main.


```text
Saída esperada:
depois de revogar: 3
tem R e I? nao
tem E e R? sim
```

**Dicas:**

1. Rode antes: sai 4294967295 e "sim" duas vezes.
2. p | ~m liga todos os bits que NÃO estão em m. Para apagar, o
   operador é outro.
3. (p & m) != 0 é "sobrou algum". "Sobraram todos" compara com m.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/E1035.c
```

**Exercício E1036** · ★★☆

O coworking quer descobrir permissões que ninguém usa. A matriz uso guarda,
para cada pessoa (linha) e cada dia (coluna), a máscara dos recursos que
ela usou. Escreva, com a matriz como parâmetro VLA:


```text
unsigned usado(int n, int d, unsigned uso[n][d], int i)
```


que junta (com |) tudo o que a pessoa i usou nos d dias. Depois mostre,
para cada pessoa, o que usou e o que tem mas nunca usou (as efetivas
estão no vetor efetivas), no formato E R I G C com '-'.


```text
Saída esperada:
Ana: usou ER--C, nunca usou --IG-
Bruno: usou ERIG-, nunca usou -----
Carla: usou E----, nunca usou -R---
```

**Dicas:**

1. Comece com 0 e faça m |= uso[i][j] para cada dia.
2. "Tem mas não usou" = efetivas[i] & ~usado(...).
3. Uma função que escreve a máscara como texto ajuda (veja o E1034).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/E1036.c
```

**Exercício E1037** · ★★★

Quando alguém pede um conjunto de permissões, o coworking oferece o
papel mais barato que cobre o pedido. Escreva:


```text
int menor_papel(unsigned pedido)
```


que devolve o primeiro papel (VISITANTE, MEMBRO, ADMIN, nessa ordem) cujo
pacote base tem TODAS as permissões do pedido, ou -1 se nenhum tem. E,
para cada pedido, mostre também o que falta ao visitante (o que o pedido
tem e o pacote do visitante não tem), como texto E R I G C.

Teste com os pedidos ENTRAR, REUNIAO | IMPRIMIR, GARAGEM e 1u << 5 (uma
sexta permissão, que nenhum papel dá).


```text
Saída esperada:
pedido E----: visitante (falta ao visitante: -----)
pedido -RI--: membro (falta ao visitante: -RI--)
pedido ---G-: admin (falta ao visitante: ---G-)
pedido -----: nenhum (falta ao visitante: -----)
```

**Dicas:**

1. Percorra p de 0 a QTD_PAPEIS - 1 e teste (base[p] & pedido) == pedido.
2. Falta = pedido & ~base[VISITANTE].
3. Repare na última linha: o bit 5 não aparece no texto de 5 letras, mas
   ainda impede todos os papéis. Só os 5 bits de baixo viram texto.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/E1037.c
```

**Exercício E1038** · ★★★

Em vez de papel único, agora cada pessoa participa de vários grupos. Um
grupo concede algumas permissões e pode negar outras, e a negação de
qualquer grupo vence a concessão de qualquer outro. Escreva:


```text
unsigned calcular(int k, const int ids[k], const Grupo grupos[])
```


que recebe os índices dos k grupos da pessoa (um parâmetro VLA) e devolve
as permissões finais: (OU de todos os concede) & ~(OU de todos os nega).


```text
grupos: equipe   concede E R
        financeiro concede I
        estagio  nega G C
        motorista concede G
Lia participa de equipe, financeiro e motorista.
Teo participa de equipe, motorista e estagio.
```



```text
Saída esperada:
Lia: ERIG-
Teo: ER---
```

**Dicas:**

1. Acumule duas máscaras separadas no laço: concede e nega. Só no fim
   aplique a negação; se aplicar grupo a grupo, a ordem dos grupos
   mudaria o resultado.
2. No main, os ids podem ser VLAs: int k = 3; int ids_lia[k]; e preencha
   um por um (VLA não aceita = {...}).
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/0173-juntando-tudo/E1038.c
```

---

## Desafios do módulo

Problemas para resolver num arquivo seu, misturando os assuntos do módulo. Do
médio ao difícil.

**1. A tabela na prática.** Escreva um programa que mostre o valor de cada
expressão abaixo e, ao lado, a mesma expressão com todos os parênteses do
jeito que o C agrupa: `2 + 3 * 4 % 5`, `1 << (2 + 1)`, `(5 & 3) | 8`,
`10 - 2 - 3`, `!0 + 1`, `-3 % 2`, `(7 > 3) > 1` e `~0u >> 28`.

<details><summary>Resposta</summary>

4, 8, 9, 5, 2, -1, 0 e 15. Os que mais enganam: `%` está no nível do `*`,
então `3 * 4 % 5` é `(3 * 4) % 5` = 2; `7 > 3 > 1` compara o **resultado**
de `7 > 3` (que é 1) com 1, e dá 0; `-3 % 2` é -1, porque o resto tem o sinal
do dividendo; e `~0u >> 28` desloca 32 bits ligados e sobram 4: 15.
Algumas dessas, sem os parênteses, fazem o gcc avisar: deixe os parênteses.

</details>

**2. Ano bissexto numa linha.** Escreva `bool bissexto(int a)` com uma
expressão só e teste com 1900, 2000, 2024 e 2026.

<details><summary>Resposta</summary>

`(a % 4 == 0 && a % 100 != 0) || a % 400 == 0`. Sem os parênteses o valor é
o mesmo, porque `&&` vem antes de `||`, mas o gcc avisa ("suggest parentheses
around '&&' within '||'"), e com razão: quem lê não precisa lembrar da
tabela. Resultado: 1900 não, 2000 sim, 2024 sim, 2026 não.

</details>

**3. Contar bits ligados.** Escreva `int contar_bits(unsigned x)` com o
truque `x &= x - 1` e teste com `0xF0F0`. Por que o parâmetro precisa ser
`unsigned`?

<details><summary>Resposta</summary>

`x - 1` apaga o bit 1 mais baixo e liga os zeros à direita dele; o `&` com
`x` apaga exatamente esse bit. O laço roda uma vez por bit ligado: `0xF0F0`
dá **8**. Com `int`, um `x` negativo faria `x - 1` estourar em `INT_MIN - 1`,
comportamento indefinido; com `unsigned`, a conta dá a volta e está definida.

</details>

**4. Girar bits.** Escreva `unsigned girar(unsigned x, unsigned n)`, que
empurra os bits `n` casas para a esquerda e traz de volta, pela direita, os
que caíram. Teste `girar(0x80000001, 1)` e `girar(x, 0)`.

<details><summary>Resposta</summary>

`(x << n) | (x >> (32 - n))`, mas com cuidado: com `n = 0`, o `x >> 32`
desloca pela largura inteira do tipo, o que é comportamento indefinido (o
UBSan acusa). Faça `n &= 31;` e, se `n == 0`, devolva `x`. `girar(0x80000001,
1)` dá **0x00000003**: o bit 31 voltou como bit 0.

</details>

**5. O valor absoluto que não cabe.** `abs(INT_MIN)` é comportamento
indefinido, porque 2147483648 não cabe num `int`. Escreva `unsigned
modulo(int x)` que funcione para qualquer `int`, inclusive `INT_MIN`.

<details><summary>Resposta</summary>

`x < 0 ? 0u - (unsigned)x : (unsigned)x`. A conversão `(unsigned)x` é sempre
definida (soma 2³² ao negativo), e a subtração sem sinal também. Para
`INT_MIN`, `(unsigned)x` é 2147483648, e `0u - 2147483648u` dá **2147483648**,
o valor certo, agora num tipo que comporta.

</details>

**6. A média que não estoura.** Com `unsigned a = 4000000000u, b =
4000000002u;`, `(a + b) / 2` dá um valor absurdo. Escreva duas versões
corretas da média.

<details><summary>Resposta</summary>

`a + b` passa de `UINT_MAX` e dá a volta. Versão 1: `a + (b - a) / 2`, com
`a <= b` (a diferença nunca estoura). Versão 2, sem exigir ordem:
`(a & b) + ((a ^ b) >> 1)`: os bits comuns contam inteiros, os diferentes
contam pela metade. As duas dão **4000000001**. É o mesmo erro clássico do
`meio = (ini + fim) / 2` da busca binária.

</details>

**7. Espiral numa matriz VLA.** Leia `l` e `c`, crie `int m[l][c]` e preencha
de 1 até `l * c` em espiral, no sentido horário, começando no canto de cima à
esquerda. Mostre o resultado para 3 x 4.

<details><summary>Resposta</summary>

Guarde quatro limites (cima, baixo, esquerda, direita) e ande: a linha de
cima para a direita, a coluna da direita para baixo, a linha de baixo para a
esquerda, a coluna da esquerda para cima, fechando um limite a cada lado.
Pare quando o contador passar de `l * c`. Para 3 x 4: `1 2 3 4` / `10 11 12
5` / `9 8 7 6`. Confira `l` e `c` antes de criar o VLA.

</details>

**8. Triângulo de Pascal.** Leia `n` (até 30), crie `long long t[n][n]` e
mostre a linha 10 do triângulo de Pascal.

<details><summary>Resposta</summary>

`t[i][0] = t[i][i] = 1` e, no meio, `t[i][j] = t[i - 1][j - 1] + t[i -
1][j]`. A linha 10 (contando a primeira como 0) é **1 10 45 120 210 252 210
120 45 10 1**. Com `n = 30`, o VLA tem 30 × 30 × 8 = 7200 bytes, tranquilo
na pilha. Use `long long`: os valores do meio passam de `INT_MAX` perto da
linha 34.

</details>

**9. O byte com dois nomes.** Mostre os 8 bits de `signed char s = -5` e o
valor dos mesmos bits lidos como `unsigned char`. Depois calcule `~5 + 1` e
compare.

<details><summary>Resposta</summary>

Os bits são `11111011`. Como `unsigned char`, valem **251** (= 256 - 5). E
`~5 + 1` dá -5: é o complemento de dois, a regra que o processador usa para
negativos. Para mostrar os bits sem armadilha, converta antes:
`unsigned char u = (unsigned char)s;` e desloque `u`, nunca o negativo.

</details>

**10. Soma com aviso de estouro.** Escreva `bool somar(int a, int b, int
*r)`, que guarda `a + b` em `*r` e devolve `true`, ou devolve `false` sem
somar quando o resultado não caberia num `int`. Teste com `INT_MAX` e 1, e
com -5 e 3.

<details><summary>Resposta</summary>

Não dá para somar e conferir depois: o estouro com sinal já é comportamento
indefinido. Teste antes: se `b > 0 && a > INT_MAX - b`, estoura para cima; se
`b < 0 && a < INT_MIN - b`, para baixo. Nenhuma dessas subtrações estoura.
`somar(INT_MAX, 1, &r)` devolve `false`; `somar(-5, 3, &r)` devolve `true`
com `r = -2`.

</details>

## Lista de exercícios práticos

30 exercícios que misturam os assuntos do módulo, no ritmo da prova do PPGI. Arquivos em [`lista/`](27-c-detalhes/lista/); resoluções em `_respostas/27-c-detalhes/lista/`.

### ★☆☆ Aquecimento

**Exercício P2701** · ★☆☆ · A calculadora do caixa

Escreva int calcular(int a, char op, int b, int *resultado), que usa um
switch sobre op ('+', '-', '*', '/') para fazer a conta e guardar em
*resultado. Ela devolve 1 se deu certo, 0 se a divisão é por zero e -1 se
a operação não existe. No main, faça as contas abaixo e mostre cada uma.


```text
12 + 5    12 - 5    12 * 5    12 / 5    7 / 0    12 % 5
```



```text
Saída esperada:
12 + 5 = 17
12 - 5 = 7
12 * 5 = 60
12 / 5 = 2
7 / 0: divisão por zero
12 % 5: operação inválida
```

**Dicas:**

1. Cada case termina com break ou return; sem isso, a execução cai no
   case de baixo.
2. O default pega qualquer char que não tem case.
3. No printf, o % sozinho se escreve %%; o char da operação sai com %c.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2701.c
```

---

**Exercício P2702** · ★☆☆ · Dígitos com do/while

Escreva int contar_digitos(unsigned n) e unsigned somar_digitos(unsigned n),
as duas com do/while. O do/while roda o corpo pelo menos uma vez, e é
exatamente isso que faz o 0 ter 1 dígito. Teste com 0, 7, 2026 e 1000000.


```text
Saída esperada:
0: 1 dígito(s), soma 0
7: 1 dígito(s), soma 7
2026: 4 dígito(s), soma 10
1000000: 7 dígito(s), soma 1
```

**Dicas:**

1. O último dígito é n % 10; tirar o último dígito é n /= 10.
2. do { ... } while (n > 0); com ponto e vírgula depois do while.
3. Com while comum, o 0 daria 0 dígitos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2702.c
```

---

**Exercício P2703** · ★☆☆ · A conta de luz

A conta de luz cobra cada kWh pela tarifa mais a bandeira, e soma uma taxa
fixa. Com 250 kWh, tarifa de 80 centavos, bandeira de 10 centavos por kWh e
taxa de R$ 15,00, a conta é R$ 240,00. O programa abaixo compila sem aviso,
mas as duas contas estão erradas. Conserte só com parênteses e com a ordem
das operações.


```text
Saída esperada:
total: R$ 240.00
bandeira: 11% do preço do kWh
```

**Dicas:**

1. Rode antes: sai R$ 215.10 e 0%.
2. O consumo multiplica a soma da tarifa com a bandeira.
3. 10 / 90 em inteiros é 0: multiplique por 100 antes de dividir.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2703.c
```

---

**Exercício P2704** · ★☆☆ · Quatro operações sobre um bit

Escreva as funções abaixo, com n de 0 a 7, e uma void mostrar(unsigned x)
que escreve os 8 bits de baixo de x:


```text
bool testar(unsigned x, int n)
unsigned ligar(unsigned x, int n)
unsigned desligar(unsigned x, int n)
unsigned inverter(unsigned x, int n)
```


Comece com x = 0x2C e mostre o que se pede.


```text
Saída esperada:
x = 00101100
bit 3 ligado? sim
ligar 0 -> 00101101
desligar 5 -> 00001100
inverter 7 -> 10101100
```

**Dicas:**

1. A máscara do bit n é 1u << n.
2. Ligar é |, desligar é & com ~, inverter é ^, testar é (x >> n) & 1u.
3. Cada operação parte do x original: as funções não mudam x.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2704.c
```

---

**Exercício P2705** · ★☆☆ · Para onde vai o negativo

Converter um valor para um tipo sem sinal é sempre definido: o C soma ou
subtrai 2^bits até o valor caber. Escreva um programa que guarde cada valor
abaixo numa variável do tipo pedido e mostre o resultado:


```text
-1 em unsigned char      256 em unsigned char    300 em unsigned char
-2 em unsigned short     -3 em unsigned
```



```text
Saída esperada:
(unsigned char)-1 = 255
(unsigned char)256 = 0
(unsigned char)300 = 44
(unsigned short)-2 = 65534
(unsigned)-3 = 4294967293
```

**Dicas:**

1. unsigned char tem 8 bits: a conta é módulo 256. unsigned short tem 16:
   módulo 65536.
2. Use o cast para o gcc não reclamar de constante grande demais:
   unsigned char a = (unsigned char)300;
3. unsigned char e unsigned short viram int no printf: %d serve. O
   unsigned vai com %u.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2705.c
```

---

**Exercício P2706** · ★☆☆ · Três idades em ordem

Escreva void trocar(int *a, int *b) e void ordenar3(int *a, int *b, int *c),
que deixa os três valores em ordem crescente usando só trocar. No main, as
idades da família são 30, 12 e 25, em três variáveis separadas.


```text
Saída esperada:
antes: 30 12 25
depois: 12 25 30
```

**Dicas:**

1. Três comparações bastam: (a, b), (b, c) e de novo (a, b).
2. Dentro de ordenar3, a, b e c já são ponteiros: trocar(a, b), sem &.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2706.c
```

---

**Exercício P2707** · ★☆☆ · A lista da feira no arquivo

Grave a lista da feira no arquivo p2707_feira.txt, um item por linha no
formato nome;preço, com fopen e fprintf. Feche, abra de novo para leitura,
leia cada linha com fscanf e some os preços. No fim, apague o arquivo com
remove.


```text
banana 6.50    tomate 8.90    alface 3.00    queijo 22.40
```



```text
Saída esperada:
gravados 4 itens
banana: R$ 6.50
tomate: R$ 8.90
alface: R$ 3.00
queijo: R$ 22.40
total da feira: R$ 40.80
```

**Dicas:**

1. Sempre confira se o fopen devolveu NULL.
2. fscanf(f, " %31[^;];%lf", nome, &preco) lê o nome até o ; e depois o
   número. O espaço no começo pula o \n da linha anterior.
3. O laço continua enquanto o fscanf devolver 2.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2707.c
```

---

**Exercício P2708** · ★☆☆ · Dia útil ou fim de semana

Crie typedef enum { DOM, SEG, TER, QUA, QUI, SEX, SAB } Dia; e um vetor com
os nomes. Escreva const char *tipo(Dia d) com um switch em que DOM e SAB
dividem o mesmo case (um embaixo do outro, sem break entre eles) e os
outros dias caem no default. Mostre o tipo de DOM, QUA e SAB e, no fim, o
dia que fica 2 depois de QUA, usando que um enum é um int.


```text
Saída esperada:
DOM: fim de semana
QUA: dia útil
SAB: fim de semana
QUA + 2 = SEX (5)
```

**Dicas:**

1. case DOM:
   case SAB:
       return "fim de semana";
2. O enum começa em 0: QUA vale 3, e QUA + 2 vale 5, que é SEX.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2708.c
```

---

**Exercício P2709** · ★☆☆ · Notas válidas com macros

Defina, com #define, a constante QTD_NOTAS (5) e as macros
QUADRADO(x) e ENTRE(x, a, b) (verdadeiro se a <= x <= b), com todos os
parênteses que uma macro precisa. Para as notas {7, 11, -1, 10, 5}, diga
quais são válidas (de 0 a 10) e some os quadrados das válidas.


```text
Saída esperada:
nota 7: válida
nota 11: inválida
nota -1: inválida
nota 10: válida
nota 5: válida
válidas: 3, soma dos quadrados: 174
```

**Dicas:**

1. #define QUADRADO(x) ((x) * (x))
2. #define ENTRE(x, a, b) ((x) >= (a) && (x) <= (b))
3. Teste a macro com QUADRADO(1 + 2): tem que dar 9, não 5.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2709.c
```

---

**Exercício P2710** · ★☆☆ · A semana mais quente

As máximas da semana em Manaus foram {28, 31, 33, 29, 35, 30, 27}, de
domingo (dia 0) a sábado (dia 6). Escreva um programa que mostre a média
com duas casas, quantos dias ficaram acima da média e o dia mais quente.


```text
Saída esperada:
média = 30.43
acima da média: 3 dias
mais quente: 35 no dia 4
```

**Dicas:**

1. A média precisa de divisão real: (double)soma / 7.
2. Calcule o tamanho com sizeof v / sizeof v[0] em vez de escrever 7.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2710.c
```

### ★★☆ Para pensar

**Exercício P2711** · ★★☆ · O estoque que não fica negativo

Com typedef struct { char nome[20]; unsigned qtd; double preco; } Produto;,
escreva:


```text
bool vender(Produto *p, unsigned q)  // recusa se não houver q unidades
double valor_estoque(const Produto v[], int n)
```


Como qtd é unsigned, uma venda maior que o estoque daria a volta para um
número enorme: vender tem que conferir ANTES de subtrair. Estoque inicial:
café (10 a R$ 18.00), açúcar (4 a R$ 5.50), leite (12 a R$ 6.00). Venda 3
cafés, 5 açúcares e 12 leites.


```text
Saída esperada:
vender 3 café: ok
vender 5 açúcar: recusada (só 4)
vender 12 leite: ok
café: 7, açúcar: 4, leite: 0
valor em estoque: R$ 148.00
```

**Dicas:**

1. if (q > p->qtd) return false; e só depois p->qtd -= q.
2. O valor é a soma de qtd * preco: 7 * 18 + 4 * 5.5 + 0 * 6.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2711.c
```

---

**Exercício P2712** · ★★☆ · A célula da planilha (union com etiqueta)

Uma célula de planilha guarda um inteiro, um número real ou um texto, um
de cada vez. Monte uma union com etiqueta:


```text
typedef enum { INTEIRO, REAL, TEXTO } Tipo;
typedef struct { Tipo tipo; union { int i; double d; char s[16]; } v; } Celula;
```


Escreva void mostrar(const Celula *c), com um switch sobre c->tipo que lê
só o campo certo da union. Mostre as células 42, 3.14 e "feira" e, no fim,
o sizeof de Celula e da union.


```text
Saída esperada:
inteiro: 42
real: 3.14
texto: feira
sizeof(Celula) = 24, sizeof da union = 16
```

**Dicas:**

1. Na union, os três campos começam no mesmo byte: o tamanho é o do maior
   (16, o vetor de char), e não a soma.
2. A struct tem 4 bytes do enum, 4 de sobra para alinhar o double da
   union e os 16 da union: 24.
3. Para o texto, use strcpy(c.v.s, "feira") depois de pôr c.tipo = TEXTO.
4. sizeof c.v mede só a union.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2712.c
```

---

**Exercício P2713** · ★★☆ · Quem ganhou o jogo da velha

Escreva char vencedor(char t[3][3]), que devolve 'X' ou 'O' se alguma linha,
coluna ou diagonal tem três iguais, ou '-' se ninguém ganhou. Teste com os
dois tabuleiros abaixo ('.' é casa vazia).


```text
tabuleiro 1:  X O .     tabuleiro 2:  X O X
              O X .                   X O O
              . O X                   O X X
```



```text
Saída esperada:
tabuleiro 1: vencedor X
tabuleiro 2: vencedor -
```

**Dicas:**

1. Uma função auxiliar trinca(a, b, c) que devolve a se a == b == c e a
   não é '.', ou 0, deixa o código curto.
2. São 8 trincas: 3 linhas, 3 colunas e 2 diagonais.
3. Inicialize com strings: char t1[3][3] = {{'X','O','.'}, ...}.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2713.c
```

---

**Exercício P2714** · ★★☆ · Um processador de brinquedo

Um processador de brinquedo tem instruções de 1 byte: os bits 7-6 são o
código da operação (00 LOAD, 01 ADD, 10 SUB, 11 JMP) e os bits 5-0 são o
operando (0 a 63). Escreva um programa que, com um switch, execute os bytes
{0x05, 0x47, 0x83, 0xC0} sobre um acumulador que começa em 0, mostrando
cada instrução decodificada.


```text
Saída esperada:
0x05: LOAD 5 -> acc = 5
0x47: ADD 7 -> acc = 12
0x83: SUB 3 -> acc = 9
0xC0: JMP 0 (fim do programa)
```

**Dicas:**

1. Código: (b >> 6) & 3u. Operando: b & 0x3Fu.
2. Um enum { LOAD, ADD, SUB, JMP } deixa os case legíveis: os valores 0 a
   3 batem com os bits.
3. Guarde os bytes em unsigned char e mostre com 0x%02X.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2714.c
```

---

**Exercício P2715** · ★★☆ · O inverno em Gramado

O programa abaixo compila sem nenhum aviso, mas as duas funções erram por
misturar int e unsigned:


```text
- media devolve a média das temperaturas, e sai um número absurdo;
- compara devolve -1, 0 ou 1 conforme a é menor, igual ou maior que b, e
  diz que 3 é maior que 7.
```


Conserte as duas sem mudar as assinaturas.


```text
Saída esperada:
média: -2.00
compara(3, 7) = -1
compara(7, 3) = 1
compara(5, 5) = 0
```

**Dicas:**

1. Em soma / n, o int soma vira unsigned (conversão aritmética usual):
   -8 vira 4294967288. Converta para double antes de dividir.
2. a - b > 0 com unsigned é verdadeiro sempre que a != b. Compare a e b
   direto.
3. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2715.c
```

---

**Exercício P2716** · ★★☆ · A tabela de distâncias da BR

Quatro cidades ficam na mesma rodovia, nos quilômetros {0, 12, 30, 45}.
Com int n = 4, crie um VLA int d[n][n] com a distância entre cada par
(|km[i] - km[j]|), mostre a tabela e o par mais distante. Escreva o
preenchimento e a busca como funções com parâmetro VLA.


```text
Saída esperada:
  0 12 30 45
 12  0 18 33
 30 18  0 15
 45 33 15  0
mais distantes: 0 e 3 (45 km)
```

**Dicas:**

1. void preencher(int n, const int km[n], int d[n][n])
2. A tabela é simétrica: basta olhar j > i na busca.
3. Cada número com %3d.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2716.c
```

---

**Exercício P2717** · ★★☆ · Boletim em arquivo binário

Com typedef struct { char nome[16]; float nota; } Aluno;, grave os 4
alunos abaixo de uma vez no arquivo p2717_boletim.bin com fwrite. Feche,
abra de novo, leia registro por registro com fread e mostre só os
aprovados (nota >= 7). No fim, apague o arquivo.


```text
Ana 8.5    Bruno 6.0    Caio 7.0    Duda 4.5
```



```text
Saída esperada:
gravados 4 registros (80 bytes)
aprovado: Ana (8.5)
aprovado: Caio (7.0)
```

**Dicas:**

1. Modo "wb" para gravar e "rb" para ler: o arquivo guarda os bytes da
   struct, como estão na memória.
2. fwrite(v, sizeof v[0], 4, f) devolve quantos registros gravou.
3. while (fread(&a, sizeof a, 1, f) == 1) lê um por vez.
4. sizeof(Aluno) = 16 + 4 = 20 bytes.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2717.c
```

---

**Exercício P2718** · ★★☆ · A catraca do ônibus

A catraca tem dois estados, typedef enum { TRAVADA, LIBERADA } Estado;, e
recebe dois eventos: 'M' (moeda) e 'P' (empurrar). Travada, a moeda
libera e o empurrão é bloqueado; liberada, o empurrão deixa passar e trava
de novo, e uma moeda a mais é desperdiçada. Processe a sequência "PMPMMPP"
com um do/while sobre a string e um switch sobre o estado, contando
passagens, moedas, moedas desperdiçadas e bloqueios.


```text
Saída esperada:
passagens: 2
moedas: 3 (1 desperdiçada)
bloqueios: 2
```

**Dicas:**

1. const char *p = eventos; do { ... p++; } while (*p != '\0'); serve
   porque a string tem pelo menos um evento.
2. Dentro do switch (estado), um if sobre o evento decide o que fazer.
3. Comece em TRAVADA.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2718.c
```

---

**Exercício P2719** · ★★☆ · Ordenar andando com ponteiros

Sem usar índice nenhum (nada de v[i]), só aritmética de ponteiros, escreva:


```text
int *maior(int *ini, int *fim)   // o maior em [ini, fim); fim fica de fora
void ordenar(int *ini, int *fim) // ordem crescente, por seleção
```


Ordenar coloca o maior do trecho na última posição, encurta o trecho e
repete. Use com o vetor {42, 7, 19, 88, 3} e mostre o índice do maior
com a diferença de ponteiros.


```text
Saída esperada:
maior: 88 no índice 3
ordenado: 3 7 19 42 88
```

**Dicas:**

1. for (int *p = ini + 1; p < fim; p++) percorre o trecho.
2. p - v dá o índice, do tipo ptrdiff_t: mostre com %td.
3. Na ordenação, troque *maior(ini, fim) com *(fim - 1) e faça fim--.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2719.c
```

---

**Exercício P2720** · ★★☆ · Uma biblioteca de bits em macros

Escreva quatro macros para mexer em bits de um uint8_t, com todos os
parênteses que uma macro precisa:


```text
BIT(n)        o número só com o bit n ligado
LIGA(x, n)    x com o bit n ligado
DESLIGA(x, n) x com o bit n desligado
TESTA(x, n)   1 se o bit n de x está ligado, senão 0
```


Para provar que as macros estão blindadas, use argumentos com
expressões: comece com uint8_t flags = 0; ligue o bit 1 + 1 e o bit 6,
desligue o bit 2 * 3 e teste !TESTA(flags, 2) e TESTA(flags, 7 - 1).


```text
Saída esperada:
BIT(1 + 1) = 4
depois de ligar 2 e 6: 68
depois de desligar 6: 4
!TESTA(flags, 2) = 0
TESTA(flags, 7 - 1) = 0
```

**Dicas:**

1. #define BIT(n) (1u << (n)): sem os parênteses em volta de n,
   1u << 1 + 1 até daria certo, mas BIT(a) * 2 não.
2. #define TESTA(x, n) (((x) >> (n)) & 1u): sem os parênteses de fora,
   !TESTA(...) aplicaria o ! só ao primeiro pedaço.
3. Guarde de volta com cast: flags = (uint8_t)LIGA(flags, 1 + 1);
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2720.c
```

### ★★★ Desafio

**Exercício P2721** · ★★★ · Calculadora de notação polonesa reversa

Na notação polonesa reversa, o operador vem depois dos operandos e não
existe precedência nem parênteses: "3 4 + 2 *" é (3 + 4) * 2. Escreva
int avaliar(const char *expr, int *resultado), que percorre a string com um
ponteiro, empilha cada dígito (só operandos de 0 a 9) num vetor e, a cada
operador (+ - * /), desempilha dois, faz a conta com um switch e empilha o
resultado. Devolve 1 se deu certo e 0 se a expressão é inválida (faltou
operando, divisão por zero ou sobrou mais de um número).


```text
Saída esperada:
3 4 + 2 * = 14
5 1 2 + 4 * + 3 - = 14
9 2 3 * - = 3
4 + = expressão inválida
8 0 / = expressão inválida
```

**Dicas:**

1. Pilha num vetor: int pilha[32]; int topo = 0; empilhar é
   pilha[topo++] = x; desempilhar é pilha[--topo].
2. Cuidado com a ordem: o primeiro desempilhado é o operando da DIREITA.
   Em "9 2 3 * -", a conta é 9 - 6.
3. Um dígito c vira número com c - '0'. Espaço, pule.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2721.c
```

---

**Exercício P2722** · ★★★ · O byte de trás para a frente

Escreva, para uint8_t, as funções abaixo e mostre os resultados para o
byte 0x1D (00011101):


```text
int contar(uint8_t b)          // quantos bits 1
int paridade(uint8_t b)        // 1 se a quantidade de bits 1 é ímpar
uint8_t espelhar(uint8_t b)    // bit 0 vira bit 7, bit 1 vira bit 6...
uint8_t girar(uint8_t b, int n) // gira n casas à esquerda (0 a 7)
```



```text
Saída esperada:
b = 00011101 (0x1D)
bits ligados: 4
paridade: 0
espelhado: 10111000 (0xB8)
girado 3: 11101000 (0xE8)
girado 0: 00011101 (0x1D)
```

**Dicas:**

1. Espelhar: para cada b de 0 a 7, se o bit b está ligado, ligue o bit
   7 - b do resultado.
2. Girar: (b << n) | (b >> (8 - n)), guardado num uint8_t. Com n = 0,
   b >> 8 é definido (o b virou int de 32 bits), mas trate o caso
   separado para ficar claro.
3. A promoção inteira transforma o uint8_t em int antes do <<: corte de
   volta com (uint8_t)(...).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2722.c
```

---

**Exercício P2723** · ★★★ · O sensor que manda bytes

Um sensor de temperatura manda cada leitura num byte em complemento de
dois (-128 a 127), e um segundo sensor manda leituras de 12 bits. Sem
depender de conversão "definida pela implementação", escreva:


```text
int de_byte(uint8_t b)       // 0x80 a 0xFF são negativos
uint8_t para_byte(int v)     // o caminho de volta, de -128 a 127
int de_12_bits(unsigned x)   // estende o sinal: o bit 11 é o sinal
```


Converta os bytes {0x00, 0x7F, 0x80, 0xFF, 0xF6}, volte o -10 para byte e
leia os valores de 12 bits 0x7FF e 0xFF6.


```text
Saída esperada:
0x00 -> 0
0x7F -> 127
0x80 -> -128
0xFF -> -1
0xF6 -> -10
-10 -> 0xF6
12 bits: 0x7FF -> 2047, 0xFF6 -> -10
```

**Dicas:**

1. Se b >= 128, o valor é b - 256. Isso é conta com int: sempre definida.
2. Converter para unsigned é sempre definido: (uint8_t)v soma 256 aos
   negativos.
3. Com 12 bits, a régua é 4096: se o bit 11 (0x800) está ligado, o valor é
   x - 4096.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2723.c
```

---

**Exercício P2724** · ★★★ · Figuras lidas de um arquivo

Grave no arquivo p2724_figuras.txt as linhas abaixo (uma letra e as
medidas) e depois leia o arquivo com fscanf. Cada figura vai para uma
struct com etiqueta: typedef enum { CIRCULO, RETANGULO, TRIANGULO } Forma;
e uma union com as medidas de cada forma. Calcule a área de cada uma com
um switch (triângulo pelos três lados, com a fórmula de Heron) e a soma.
Apague o arquivo no fim.


```text
C 2
R 3 4
T 3 4 5
```



```text
Saída esperada:
círculo de raio 2.0: 12.57
retângulo 3.0 x 4.0: 12.00
triângulo 3.0, 4.0, 5.0: 6.00
área total: 30.57
```

**Dicas:**

1. Leia a letra com fscanf(f, " %c", &letra) e, conforme ela, leia 1, 2
   ou 3 números.
2. Heron: s = (a + b + c) / 2 e área = sqrt(s(s - a)(s - b)(s - c)).
3. Use acos(-1.0) para o pi; o rodar já liga a libm (-lm).
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2724.c
```

---

**Exercício P2725** · ★★★ · Girar a foto 90 graus

Uma foto em tons de cinza é uma matriz de pixels. Escreva, com parâmetros
VLA:


```text
void girar(int l, int c, int a[l][c], int r[c][l])  // 90° no sentido horário
void mostrar(int l, int c, int m[l][c])
bool iguais(int l, int c, int a[l][c], int b[l][c])
```


Gire a foto 2 x 3 abaixo e mostre o resultado. Depois, com uma 3 x 3
preenchida de 1 a 9, gire quatro vezes seguidas e confira que voltou à
original.


```text
1 2 3
4 5 6
```



```text
Saída esperada:
girada (3 x 2):
  4  1
  5  2
  6  3
4 giros na 3 x 3 voltam ao original? sim
```

**Dicas:**

1. Girando no sentido horário, a linha i da original vira a coluna
   l - 1 - i da girada: r[j][l - 1 - i] = a[i][j].
2. Para girar várias vezes, alterne entre duas matrizes 3 x 3 (ou copie
   de volta depois de cada giro).
3. VLA não aceita = {...}: preencha a 2 x 3 com a[i][j] = i * c + j + 1.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2725.c
```

---

**Exercício P2726** · ★★★ · A tabela do campeonato com qsort

Com typedef struct { char nome[16]; int pontos; int saldo; } Time; e
typedef enum { POR_PONTOS, POR_NOME } Criterio;, escreva duas comparadoras
para o qsort e uma função void ordenar(Time v[], int n, Criterio c) que
escolhe a comparadora com um switch, guardando-a num ponteiro para função.
Por pontos: mais pontos primeiro; no empate, maior saldo.


```text
Times: Remo (10, +3), Paysandu (12, +5), Nacional (10, +6), Fast (7, -2)
```



```text
Saída esperada:
por pontos: Paysandu 12, Nacional 10, Remo 10, Fast 7
por nome: Fast 7, Nacional 10, Paysandu 12, Remo 10
```

**Dicas:**

1. A comparadora recebe const void *: converta com
   const Time *x = a;
2. int (*cmp)(const void *, const void *) = NULL; e, no switch,
   cmp = comparar_pontos;
3. Para "mais pontos primeiro", devolva y->pontos - x->pontos.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2726.c
```

---

**Exercício P2727** · ★★★ · O wc de bolso

Escreva um programa que grave o texto abaixo no arquivo p2727_texto.txt,
feche, e depois o leia caractere por caractere com fgetc, contando linhas
(quantidade de '\n'), palavras (sequências de não espaços) e bytes, como o
comando wc do Linux. Apague o arquivo no fim.


```text
"Bom dia\nfeira no domingo\n\ncafe com pao\n"
```



```text
Saída esperada:
linhas: 4
palavras: 8
bytes: 39
```

**Dicas:**

1. O fgetc devolve int, não char: só assim dá para diferenciar o EOF de
   um byte válido. int c; while ((c = fgetc(f)) != EOF).
2. Uma palavra começa quando c não é espaço e o anterior era espaço (ou é
   o começo). Use isspace de <ctype.h>.
3. A linha em branco conta como linha, mas não tem palavra.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2727.c
```

---

**Exercício P2728** · ★★★ · O crivo de Eratóstenes em bits

Para achar os primos até 100, o crivo de Eratóstenes marca os múltiplos
de cada primo. Em vez de um vetor de 101 bool, use um vetor de uint32_t
em que cada bit é um número: o número k fica no bit k % 32 da palavra
k / 32. Escreva as macros ou funções para marcar e testar um bit, rode o
crivo e mostre quantos primos existem até 100, os maiores que 80 e
quantos bytes o vetor ocupou.


```text
Saída esperada:
primos até 100: 25
maiores que 80: 83 89 97
vetor de bits: 16 bytes
```

**Dicas:**

1. São 101 números: (101 + 31) / 32 = 4 palavras de 4 bytes.
2. Marcar k: v[k / 32] |= (uint32_t)1 << (k % 32). O 1 precisa ser de
   32 bits sem sinal antes de deslocar.
3. Comece o crivo em p = 2 e, para cada p não marcado, marque p * p,
   p * p + p, ... até 100.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2728.c
```

---

**Exercício P2729** · ★★★ · O relatório de vendas com quatro bugs

O relatório abaixo compila sem nenhum aviso e roda até o fim, mas tem
quatro bugs, cada um uma pegadinha deste módulo. Três aparecem na saída; o
quarto só aparece quando a função dos dias recebe n = 0. Conserte os quatro
sem reescrever o programa e acrescente, no fim do main, a linha que chama a
função com n = 0 e mostra quantos dias ela mostrou.


```text
Saída esperada:
total: R$ 1500
comissão (5%): R$ 75
média por vendedor: R$ 500
dias de trás para a frente: 600 500 400
vendas sem nenhum dia: 0 dias
```

**Dicas:**

1. Rode antes e compare linha por linha.
2. Olhe a macro, o ?: no meio de uma soma, a ordem de / e * com inteiros
   e o laço que desce com size_t quando n é 0.
3. Depois de consertar a função dos dias, chame-a também com n = 0: ela
   não pode mostrar nada nem ler fora do vetor.
4. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2729.c
```

---

**Exercício P2730** · ★★★ · O extrato do Pix

Juntando tudo. Grave o extrato abaixo no arquivo p2730_pix.txt (dia;tipo;
valor em centavos;flags), leia de volta para um vetor de structs e gere o
relatório. O tipo é 'R' (recebido) ou 'E' (enviado) e vira um enum; as
flags são bits: AGENDADO = 1u << 0 e CONTESTADO = 1u << 1.


```text
1;R;250000;0
1;E;12000;0
2;E;8990;2
2;E;4500;0
3;R;3000;1
3;E;30000;0
```


Descubra quantos dias o extrato tem (o maior dia lido) e crie dois VLAs,
long saldo_dia[dias] e long gasto_dia[dias]. Mostre o saldo de cada dia,
o saldo final, o dia de maior gasto e o total contestado.


```text
Saída esperada:
dia 1: +2380.00
dia 2: -134.90
dia 3: -270.00
saldo final: R$ 1975.10
maior gasto: dia 3 (R$ 300.00)
contestadas: 1 (R$ 89.90)
```

**Dicas:**

1. Leia cada linha com fscanf(f, "%d;%c;%ld;%u", ...) e confira que
   devolveu 4.
2. Um switch sobre a letra escolhe o enum; o recebido soma e o enviado
   subtrai.
3. Os VLAs só podem ser criados depois de saber dias, e não aceitam
   = {0}: zere com um laço (ou memset).
4. Valores em centavos, num long: mostre reais com v / 100 e v % 100, ou
   com v / 100.0 e %.2f.
5. Resposta esperada: a saída acima.

```bash
~/LPEDC/rodar 27-c-detalhes/lista/P2730.c
```

## Questões no estilo da prova

Questões de múltipla escolha, como as da prova do PPGI. Resolva no papel,
marque a letra e só então abra o gabarito. Os trechos de código estão dentro
de um `main` com `#include <stdio.h>`; foram compilados e rodados no gcc (os
que geram aviso, também: o aviso não impede de rodar).

**1.** O que o trecho abaixo mostra?

```c
int a = 5, b = 10;
int r = a + b > 12 ? 1 : 0 + 100;
printf("%d", r);
```

- (A) 1
- (B) 101
- (C) 100
- (D) 16
- (E) 0

<details><summary>Gabarito</summary>

**(A).** O `?:` tem precedência menor que `+` e `>`: a expressão é
`((a + b) > 12) ? 1 : (0 + 100)`. Como 15 > 12, vale 1. O `+ 100` faz parte
só do ramo do "senão". Veja 0170.

</details>

**2.** Qual a saída?

```c
int x = 6;
if (x & 1 == 0) printf("par");
else printf("impar");
```

- (A) par
- (B) impar
- (C) erro de compilação
- (D) comportamento indefinido
- (E) nada é impresso

<details><summary>Gabarito</summary>

**(B).** O `==` vem antes do `&`: a condição é `x & (1 == 0)`, isto é,
`6 & 0`, que é 0. Cai no `else`, mesmo com 6 sendo par. Compila (com um
aviso do gcc). O certo é `(x & 1) == 0`. Veja 0170 e 0065.

</details>

**3.** Qual a saída?

```c
unsigned int u = 1;
int i = -1;
printf("%s", i < u ? "menor" : "maior");
```

- (A) menor
- (B) erro de compilação
- (C) maior
- (D) depende do valor de lixo de `i`
- (E) comportamento indefinido

<details><summary>Gabarito</summary>

**(C).** Pela conversão aritmética usual, o `int` vira `unsigned`: -1 vira
4294967295, que é maior que 1. A conversão é definida pelo padrão; o gcc
avisa com `-Wsign-compare`. Veja 0171.

</details>

**4.** Sobre o laço abaixo, é correto afirmar:

```c
for (unsigned i = 3; i >= 0; i--)
    printf("%u ", i);
```

- (A) mostra `3 2 1 0` e termina.
- (B) mostra `3 2 1` e termina.
- (C) não mostra nada.
- (D) nunca termina: depois do 0, `i` vira 4294967295.
- (E) não compila, porque `i` é `unsigned`.

<details><summary>Gabarito</summary>

**(D).** Um `unsigned` é sempre `>= 0`, então a condição nunca é falsa. Ao
descer de 0, `i` dá a volta para `UINT_MAX`. O certo é
`for (unsigned i = 4; i-- > 0;)`. Veja 0171.

</details>

**5.** Qual a saída?

```c
unsigned char c = 250;
int s = c + 10;
c = c + 10;
printf("%d %d", s, c);
```

- (A) comportamento indefinido
- (B) 4 4
- (C) 260 260
- (D) 4 260
- (E) 260 4

<details><summary>Gabarito</summary>

**(E).** Na soma, `c` sofre promoção inteira e vira `int`: 250 + 10 = 260,
guardado em `s`, um `int`. Ao guardar de volta em `c`, sobra o resto da
divisão por 256: 4. Conversão para sem sinal é sempre definida. Veja 0171.

</details>

**6.** Sobre `switch`, operadores bit a bit, `union` e `enum`, num sistema com
`int` de 32 bits, analise as afirmações.

- I. Com `unsigned char c = 0xF0;`, a expressão `~c` vale -241, porque `c` é
  promovido a `int` antes do `~`.
- II. Num `switch`, um `case` sem `break` no fim deixa a execução seguir para
  o `case` seguinte.
- III. Numa `union` com um `int` e um `char[8]`, o tamanho é a soma dos
  tamanhos dos membros, 12 bytes.
- IV. Num `enum` sem valores explícitos, o primeiro enumerador vale 0 e os
  seguintes crescem de 1 em 1.

Marque a alternativa **CORRETA**.

- (A) I, II e IV, apenas.
- (B) I e III, apenas.
- (C) II e III, apenas.
- (D) II, III e IV, apenas.
- (E) I, II, III e IV.

<details><summary>Gabarito</summary>

**(A).** I: `~0x000000F0` é `0xFFFFFF0F`, que como `int` vale -241. Só ao
guardar de volta num `unsigned char` sobraria o byte `0x0F`. II: é o "cair para o
próximo caso" do `switch` (fall-through). III é falsa: os membros da `union`
**compartilham** o mesmo espaço, e o tamanho é o do maior membro (arredondado
pelo alinhamento): 8 bytes. IV: é a regra do `enum`. Veja 0170, 0171 e 0172.

</details>

**7.** Sobre os vetores de tamanho variável (VLA) no C17, analise as
afirmações.

- I. `int v[n] = {0};`, com `n` variável, é válido sempre que `n > 0`.
- II. O `sizeof` de um VLA é calculado em tempo de execução.
- III. Desde o C11 o suporte a VLA é opcional, e o compilador que não o aceita
  define `__STDC_NO_VLA__`.
- IV. Se faltar memória, a declaração do VLA devolve `NULL`.

Marque a alternativa **CORRETA**.

- (A) I e II, apenas.
- (B) II e III, apenas.
- (C) I e IV, apenas.
- (D) III e IV, apenas.
- (E) II, III e IV, apenas.

<details><summary>Gabarito</summary>

**(B).** II: como o tamanho só é conhecido na execução, o `sizeof` também é.
III: é o que o padrão diz. I é falsa: VLA não aceita inicializador no C17
(um `memset` ou um laço faz o serviço). IV é falsa: VLA não é ponteiro e não
avisa falha; quem devolve `NULL` é o `malloc`. Veja 0172.

</details>

**8.** Qual protótipo recebe corretamente uma matriz de `l` linhas e `c`
colunas, com `l` e `c` conhecidos só na execução?

- (A) `void f(int m[l][c], int l, int c);`
- (B) `void f(int l, int c, int m[][]);`
- (C) `void f(int l, int c, int m[l][c]);`
- (D) `void f(int m[][], int l, int c);`
- (E) `void f(int l, int c, int m[l][]);`

<details><summary>Gabarito</summary>

**(C).** Num parâmetro VLA, as dimensões precisam ser declaradas **antes** da
matriz, porque o tipo `m[l][c]` usa os dois nomes. Em (A), `l` e `c` ainda
não existem quando `m` é lida. Em (B), (D) e (E), falta o número de colunas,
e o compilador precisa dele para calcular `m[i][j]`. Veja 0172.

</details>

**9.** Qual a saída?

```c
int i = 0, j = 0;
if (i++ || ++j) i += 10;
printf("%d %d", i, j);
```

- (A) 1 1
- (B) 10 1
- (C) 11 0
- (D) 11 1
- (E) 10 0

<details><summary>Gabarito</summary>

**(D).** `i++` vale 0 (o valor antigo) e deixa `i` = 1. Como o lado esquerdo
do `||` deu falso, o direito roda: `++j` deixa `j` = 1 e vale 1. A condição
é verdadeira e `i += 10` dá 11. O `||` garante que o lado esquerdo termina,
`++` incluído, antes do direito. Veja 0170.

</details>

**10.** Qual a saída?

```c
#define QUAD(x) x * x
printf("%d", QUAD(2 + 3));
```

- (A) 25
- (B) erro de compilação
- (C) 13
- (D) 10
- (E) 11

<details><summary>Gabarito</summary>

**(E).** O `#define` só troca texto: `QUAD(2 + 3)` vira `2 + 3 * 2 + 3`, que
pela precedência é 2 + 6 + 3 = 11. Para dar 25, a macro precisa de
parênteses: `#define QUAD(x) ((x) * (x))`. Veja 0170 (E1019) e 0004.

</details>

## Para ler mais

- DEITEL, P.; DEITEL, H. *C: como programar*. 6. ed. São Paulo: Pearson, 2011. Cap. 2 a 4: operadores, precedência, associatividade e ordem de avaliação; cap. 10: manipulação de bits; apêndice D: sistemas de numeração e complemento de dois.
- KERNIGHAN, B. W.; RITCHIE, D. M. *The C programming language*. 2. ed. Englewood Cliffs: Prentice Hall, 1988. Cap. 2: tipos, operadores e expressões (seção 2.7, conversões de tipo; 2.12, precedência e ordem de avaliação).
- BACKES, A. *Linguagem C: completa e descomplicada*. Rio de Janeiro: Elsevier, 2013. Cap. 2 e 3: tipos, modificadores `signed`/`unsigned` e operadores.
- ISO/IEC. *ISO/IEC 9899:2018: Information technology: programming languages: C*. Genebra: ISO, 2018. Seções 6.3.1 (conversões aritméticas), 6.5 (expressões) e 6.7.6.2 (declaradores de vetor, VLA).
- CPPREFERENCE. *C operator precedence*; *Order of evaluation*; *Implicit conversions*; *Array declaration* (VLA). Disponível em: <https://en.cppreference.com/w/c/language>.
- GNU. *Using the GNU Compiler Collection (GCC)*: *Warning options* (`-Wparentheses`, `-Wsign-compare`, `-Wsequence-point`, `-Wtype-limits`). Disponível em: <https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html>.
