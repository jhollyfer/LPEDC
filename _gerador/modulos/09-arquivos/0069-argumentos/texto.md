## 0069 · Argumentos da linha de comando

Fim do rodízio de pizza, conta de R$ 187,40 para 4 pessoas. Um programa
poderia perguntar o total e o número de pessoas com `scanf`. Mas repare nos
programas de terminal que você já usa: `cp origem destino`,
`gcc -o prog prog.c`, `git commit -m "msg"`. Nenhum deles pergunta nada. Os
dados vão escritos **junto do comando**, na mesma linha, e o programa já
começa sabendo o que fazer. Isso permite usar o programa dentro de scripts,
sem ninguém digitando.

É como pedir um café no balcão já dizendo tudo de uma vez: "um expresso
duplo, sem açúcar". O atendente não precisa fazer perguntas. Os dados que vão
junto do comando se chamam **argumentos da linha de comando**, e no C eles
chegam como parâmetros do `main` (BACKES, 2013, cap. 13). Até aqui o `main`
tinha `void` entre os parênteses; para receber argumentos, ele ganha dois
parâmetros:

```c
int main(int argc, char *argv[])
```

O primeiro, `argc` (*argument count*, contagem de argumentos), diz quantos
itens vieram na linha, **contando o nome do programa**. Por isso ele vale
pelo menos 1 (FEOFILOFF, 2009, ap. H). Em `./racha 187.40 4`, `argc` vale 3:
o nome do programa e os dois números.

O segundo, `argv` (*argument vector*, vetor de argumentos), é um vetor de
`char *`, com uma string por item. `argv[0]` é o nome do programa,
`./racha`; `argv[1]` é `"187.40"`, o primeiro argumento seu; `argv[2]` é
`"4"`. Depois do último vem `argv[argc]`, que vale `NULL` e marca o fim do
vetor, do mesmo jeito que o `'\0'` marca o fim de uma string (KERNIGHAN;
RITCHIE, 1989). Como vetor em parâmetro vira ponteiro, `char **argv` é outra
forma de escrever a mesma coisa.

Quem separa a linha em pedaços não é o seu programa, é o **shell**, o
programa que lê o que você digita no terminal (bash, zsh). Antes de o seu
programa começar, o shell corta a linha nos espaços, tira as aspas e troca
coringas como `*` pelos nomes de arquivos. Assim, `"São Paulo"` entre aspas
chega como um argumento só; sem aspas, chega como dois. E o `> saida.txt` de
um redirecionamento é tratado pelo shell e nem aparece no `argv`.

Tudo no `argv` é **texto**. O `4` chega como a string `"4"`, e
`argv[2] * 2` nem compila. Para virar número, é preciso converter. A função
`strtol(texto, &fim, 10)` converte para `long` na base 10, e
`strtod(texto, &fim)` converte para `double`. As duas apontam `fim` para o
primeiro caractere que não conseguiram converter. Se `*fim` não for `'\0'`,
sobrou lixo no texto, como em `"4x"` ou `"quatro"`, e o programa pode recusar
a entrada (LINUX MAN-PAGES PROJECT, s.d.).

Existem atalhos mais curtos, `atoi` e `atof`, mas eles não avisam erro:
`atoi("quatro")` devolve 0, igual a `atoi("0")`, e o programa não tem como
saber se o usuário digitou zero ou bobagem. Servem para um teste rápido, não
para entrada de usuário (BACKES, 2013, cap. 13).

Dois costumes de programas de terminal fecham o assunto (BACKES, 2013,
cap. 12). Mensagens de erro vão para o `stderr`, com
`fprintf(stderr, ...)`. Quem redireciona a saída para um arquivo continua
vendo o erro na tela, porque o `>` só desvia o `stdout`. E o `return` do
`main` vira o **código de saída** do programa: 0 quer dizer sucesso, e
qualquer outro valor quer dizer falha. O shell guarda esse número na variável
`$?`, e o `&&` só roda o comando seguinte se o anterior devolveu 0.

> [!WARNING]
> Nunca use `argv[1]` sem conferir o `argc`: sem argumentos, ele é `NULL` e
> `atoi(NULL)` derruba o programa. E em `./calc 9 * 3` o shell troca o `*`
> pelos nomes dos arquivos da pasta antes de o programa rodar; use aspas
> (`'*'`) ou outro símbolo, como `x`.

{{exemplo}}

Fim do rodízio de pizza: conta de R$ 187,40 para 4 pessoas. O comando
`./racha 187.40 4` chega com `argc = 3`. O programa confere a quantidade,
converte `argv[1]` e `argv[2]` e divide:

{{ideia}}

Salve como `racha.c`, compile com as flags de estudo e passe os argumentos
depois do executável: `./programa 187.40 4`.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <total> <pessoas>\n", argv[0]);
        return 1;                             // diferente de 0: deu errado
    }

    char *fim;
    double total = strtod(argv[1], &fim);     // texto -> double
    if (*fim != '\0' || total <= 0) {
        fprintf(stderr, "Total inválido: %s\n", argv[1]);
        return 1;
    }
    long pessoas = strtol(argv[2], &fim, 10); // texto -> inteiro, base 10
    if (*fim != '\0' || pessoas <= 0) {
        fprintf(stderr, "Número de pessoas inválido: %s\n", argv[2]);
        return 1;
    }

    printf("Conta: R$ %.2f\n", total);
    printf("Pessoas: %ld\n", pessoas);
    printf("Cada um: R$ %.2f\n", total / pessoas);
    return 0;
}
// $ ./programa 187.40 4
// Conta: R$ 187.40
// Pessoas: 4
// Cada um: R$ 46.85
//
// $ ./programa 187.40 quatro
// Número de pessoas inválido: quatro
```

Duas perguntas antes da conta: veio a quantidade certa de argumentos, e são
números de verdade? O programa só trabalha no caminho verde:

{{fluxograma}}
