## 0069 · Argumentos da linha de comando

Fim do rodízio de pizza, conta de R$ 187,40 para 4 pessoas. Você poderia
fazer um programa que pergunta "qual o total?" e "quantas pessoas?" com
`scanf`. Mas os programas de terminal que você usa todo dia não perguntam
nada: `git commit -m "msg"`, `cp origem destino`, `gcc -o prog prog.c`. Os dados vão
**junto do comando**, na mesma linha. São os **argumentos da linha de
comando**.

No C, eles chegam como parâmetros do `main`, que até agora você escrevia com `void`:

```c
int main(int argc, char *argv[])
```

- **`argc`** (*argument count*): quantos itens vieram, **contando o nome do
  programa**. Sempre vale pelo menos 1.
- **`argv`** (*argument vector*): um vetor de `char *`, uma string para cada
  item. `argv[0]` é o nome (ou o caminho) do programa, `argv[1]` é o primeiro
  argumento seu, e `argv[argc]` é `NULL`, marcando o fim, do mesmo jeito que o
  `'\0'` marca o fim de uma string.

Quem corta a linha em pedaços é o **shell** (bash, zsh), antes de o programa
começar: ele separa nos espaços, tira as aspas e expande coringas como `*`.
`"São Paulo"` entre aspas chega como um argumento só; sem aspas, chega como
dois.

Tudo no `argv` é **texto**. O `4` chega como a string `"4"`, e
`argv[2] * 2` nem compila. Para virar número:

- **`strtol(texto, &fim, 10)`** converte para `long` e **`strtod(texto,
  &fim)`** para `double`. Os dois apontam `fim` para o primeiro caractere que
  não entrou na conversão. Se `*fim != '\0'`, sobrou lixo: `"4x"`, `"quatro"`.
- **`atoi`** e **`atof`** são mais curtos, mas não avisam nada:
  `atoi("quatro")` devolve 0 em silêncio. Servem para testes rápidos, não para
  entrada de usuário.

Duas convenções de todo programa de terminal. Mensagem de erro vai para
**`stderr`** (`fprintf(stderr, ...)`), não para `stdout`. Assim, quem redireciona
a saída para um arquivo (`./racha 10 2 > saida.txt`) continua vendo o erro na
tela. E o valor do `return` do `main` é o **código de saída**: 0 quer dizer
sucesso; qualquer outro, falha. O shell guarda esse valor em `$?`, e scripts e
o `&&` decidem o que fazer com base nele.

Vamos ver na prática. O comando `./racha 187.40 4` chega ao programa como
`argc = 3` e um `argv` com três strings mais o `NULL`. O programa confere a
quantidade, converte `argv[1]` e `argv[2]` em números e divide:

{{ideia}}

Salve o código como `racha.c`. Para passar argumentos com o `rodar`, escreva
depois do nome do arquivo: `~/LPEDC/rodar racha.c 187.40 4`.

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
// $ rodar racha.c 187.40 4
// Conta: R$ 187.40
// Pessoas: 4
// Cada um: R$ 46.85
//
// $ rodar racha.c 187.40 quatro
// Número de pessoas inválido: quatro
```

Repara no fluxograma: antes de qualquer conta, duas perguntas de
desconfiança. Veio a quantidade certa de argumentos? Eles são números de
verdade? Só no caminho verde o programa trabalha:

{{fluxograma}}

> [!WARNING]
> Nunca toque em `argv[1]` sem conferir o `argc`. Se a pessoa rodar o programa
> sem argumentos, `argv[1]` é `NULL`, e `atoi(NULL)` ou `strlen(NULL)` derruba
> o programa (o E412 mostra isso). E cuidado com o `*` numa calculadora:
> `./calc 9 * 3` não passa um asterisco. O shell troca o `*` pelos nomes dos
> arquivos da pasta antes de o seu programa rodar. Use aspas (`'*'`) ou outro
> símbolo, como `x`.

> [!TIP]
> **Por dentro do C:** quem chama o `main` não é você. O sistema operacional
> monta a pilha do processo novo e copia as strings dos argumentos para o alto
> dela, uma atrás da outra, cada uma com o seu `'\0'`. Logo abaixo ficam os
> ponteiros que formam o vetor `argv`, terminado em `NULL`. O código de
> partida da biblioteca C (o `_start`, que o ligador põe no executável) conta
> os ponteiros, chama `main(argc, argv)` e passa o valor do `return` para o
> `exit`. Por isso `char *argv[]` e `char **argv` são a mesma coisa na lista
> de parâmetros: um vetor como parâmetro vira ponteiro, como no assunto 0038.

> [!NOTE]
> **Pergunta para você:** quanto vale `argc` em `./racha "187.40 4"`? E em
> `./racha 187.40 4 > conta.txt`? Pense em quem trata as aspas e o `>` antes
> de rodar o A138 para conferir.

{{pratique}}
