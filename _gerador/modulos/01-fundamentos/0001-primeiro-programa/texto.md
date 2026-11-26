## 0001 · O primeiro programa

O processador do computador só entende números: sequências de instruções
em binário, cada uma muito simples. Escrever assim seria impossível para
qualquer pessoa. Um programa em C é um texto que você consegue ler e
escrever, e uma ferramenta, o **compilador**, traduz esse texto para a
língua da máquina. O curso inteiro parte daqui: um arquivo `.c` que vira um
executável e mostra alguma coisa na tela.

Pense numa receita de bolo. Ela tem um título, uma lista do que você precisa
ter à mão e os passos, que você segue de cima para baixo. Um programa em C
tem as mesmas partes. Ele é um conjunto de **funções**, blocos de
instruções com nome, e a execução sempre começa pela função **`main`**
(KERNIGHAN; RITCHIE, 1988, cap. 1). O sistema operacional procura a `main`,
entra nela e executa as instruções na ordem em que aparecem.

```c
#include <stdio.h>

int main(void) {
    printf("Bom dia\n");
    return 0;
}
```

Cada **instrução** é um comando completo e termina com ponto e vírgula. As
**chaves** `{ }` agrupam várias instruções num **bloco**, que funciona como
uma unidade: tudo o que está entre a `{` depois de `main(void)` e a `}` final
pertence à `main` (DEITEL; DEITEL, 2011, cap. 2). A linha
`int main(void)` diz duas coisas: a função não recebe nada de fora (`void`)
e devolve um número inteiro (`int`) para quem a chamou.

A primeira linha não é instrução. Tudo o que começa com `#` é uma ordem para
o **pré-processador**, a primeira etapa da tradução, e por isso não leva
`;`. O `#include <stdio.h>` manda colar ali o conteúdo do arquivo
`stdio.h`, que declara as funções de entrada e saída, entre elas o `printf`
(BACKES, 2013, cap. 1). Sem essa linha, o compilador não sabe que o
`printf` existe nem como chamá-lo.

O `printf("...\n")` mostra o texto entre aspas. O `\n` dentro das aspas é
um caractere especial que pula para a linha de baixo. O `return 0` encerra
a `main` e entrega o número 0 ao sistema, o código combinado para "terminou
bem" (BACKES, 2013, cap. 1). Um valor diferente de zero avisa que algo deu
errado.

Também cabe no arquivo texto que não é para a máquina. O **comentário** é
ignorado pelo compilador e serve só para quem lê. O `//` comenta até o fim
da linha; o par `/* ... */` comenta tudo o que fica entre eles, mesmo em
várias linhas (DEITEL; DEITEL, 2011, cap. 2). E o C diferencia maiúsculas de
minúsculas: `Main` e `Printf` são nomes que não existem.

| Linha | Para que serve |
| --- | --- |
| `#include <stdio.h>` | declara o `printf` |
| `int main(void) {` | começa a `main`; não recebe nada e devolve um `int` |
| `printf("...\n");` | mostra texto; `\n` pula a linha |
| `return 0;` | termina com sucesso |
| `}` | fecha o bloco |

Para o texto virar executável, o `gcc` passa por quatro etapas, uma depois
da outra (GNU, s.d.). O **pré-processador** trata as linhas com `#` e cola
o `stdio.h` no lugar do `#include`. O **compilador** confere a gramática e
os tipos e traduz o C para **assembly**, as instruções do processador
escritas como texto. O **montador** transforma o assembly em **código
objeto** (`.o`), já em binário, mas incompleto: ele sabe que você chamou o
`printf`, não onde o `printf` está. O **ligador** (*linker*) junta o `.o`
com a **biblioteca padrão**, onde mora o código do `printf`, e grava o
executável. Um comando faz tudo: `gcc padaria.c -o padaria`, e depois
`./padaria` roda o resultado.

Saber em que etapa o processo parou ajuda a consertar. Há três tipos de erro
(DEITEL; DEITEL, 2011, cap. 2). O **erro de compilação** aparece quando o
texto fere a gramática, como faltar um `;` ou escrever `Int` no lugar de
`int`: o gcc mostra arquivo, linha e coluna e não gera executável. O **erro
de ligação** aparece quando a gramática está certa, mas a função não existe
em lugar nenhum: com `prinft`, o ligador para com `undefined reference to
'prinft'`. O **erro de execução** é o pior, porque o programa compila,
roda e mostra um valor errado ou quebra no meio. O compilador não o vê; os
**avisos** (*warnings*) do gcc com `-Wall` e o AddressSanitizer pegam parte
deles.

> [!WARNING]
> O `printf` não pula linha sozinho: `printf("Pão"); printf("Quente");`
> mostra `PãoQuente`. Ponha o `\n` onde a linha acaba. Se faltar um `;`, o
> gcc reclama (`expected ';' before ...`) na linha **seguinte**, onde ele
> percebe a falta.

{{exemplo}}

Um aviso de três linhas para o painel de LED de uma padaria. O `padaria.c`
passa pelas quatro etapas até virar o executável:

{{ideia}}

```c
// Aviso do painel da padaria
#include <stdio.h>

int main(void) {
    printf("Padaria Pão Quente\n");
    printf("Pão francês saindo às 17h\n");
    printf("R$ 0,90 a unidade\n");
    return 0; // 0 = terminou bem
}
// Saída:
// Padaria Pão Quente
// Pão francês saindo às 17h
// R$ 0,90 a unidade
```

Cada etapa pode parar o processo; aqui todas passam:

{{fluxograma}}
