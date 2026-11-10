## 0001 · O primeiro programa

A padaria do bairro comprou um painel de LED e pediu um aviso de três linhas:
nome, horário da fornada e preço do pão. É só saída, sem entrada nem conta.

Um programa em C é um conjunto de **funções**. A função **`main`** é onde o
sistema começa a execução. Este esqueleto aparece em todo exemplo do curso:

| Linha | O que faz |
| --- | --- |
| `// Aviso do painel da padaria` | **comentário**: o compilador ignora; é para quem lê |
| `#include <stdio.h>` | cola aqui o arquivo que **declara** o `printf` |
| `int main(void) {` | começa a `main`: não recebe nada (`void`) e devolve um `int` |
| `printf("...\n");` | mostra um texto na tela; `\n` pula a linha |
| `return 0;` | termina a `main` e devolve 0 ao sistema: "deu tudo certo" |
| `}` | fecha o **bloco** da `main` |

Regras fixas: toda **instrução** termina em `;` (o `#include` não é
instrução e não leva); as **chaves** `{ }` agrupam instruções num bloco; o C
diferencia maiúsculas de minúsculas (`Main` não é `main`); comentário de uma
linha começa com `//` e o de várias linhas fica entre `/*` e `*/`.

### Do .c ao executável

O processador não entende C. O `gcc` comanda quatro estações:

1. **pré-processador**: trata as linhas com `#`. O `#include <stdio.h>`
   **cola** o conteúdo do `stdio.h` no lugar da linha;
2. **compilador**: confere a gramática e os tipos e traduz o C para
   **assembly**, a língua do processador em forma de texto;
3. **montador**: transforma o assembly em **código objeto** (`.o`), já em
   binário, mas com buracos: ele sabe que você chamou `printf`, não onde ele
   está;
4. **ligador** (*linker*): junta o `.o` com a **biblioteca padrão**, onde mora
   o código do `printf`, tapa os buracos e grava o **executável**.

Um comando só percorre as quatro: `gcc padaria.c -o padaria`, e depois
`./padaria`. Com as flags de estudo (`-Wall -Wextra -pedantic`, C17 e o
**AddressSanitizer**, que vigia a memória durante a execução), o gcc confere
mais coisas; veja "Antes de começar", acima.

O `padaria.c` ganha o `stdio.h`, vira assembly, vira `padaria.o`, é ligado ao
`printf` e sai como o executável `padaria`:

{{ideia}}

O programa completo:

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

Cada estação pode parar o processo. O exemplo passa por todas sem erro:

{{fluxograma}}

Saber **quem reclamou** ajuda a consertar. Há três tipos de erro:

- **de compilação**: `#include` de arquivo inexistente (pré-processador),
  falta de `;`, `Int` no lugar de `int`. O gcc mostra arquivo, linha e coluna
  e não gera executável;
- **de ligação**: a gramática está certa, mas a função não existe em lugar
  nenhum. Com `prinft`, o ligador para com `undefined reference to 'prinft'`;
- **de execução**: compila e roda, mas mostra o valor errado ou quebra no
  meio. É o pior tipo, porque o compilador não o vê. Os **avisos**
  (*warnings*) do gcc e o AddressSanitizer pegam parte deles.

> [!WARNING]
> O `printf` **não pula linha sozinho**. Sem `\n`, o próximo `printf`
> continua na mesma linha: `printf("Pão"); printf("Quente");` mostra
> `PãoQuente`. Se faltar um `;`, o gcc avisa `expected ';' before ...` na
> linha **seguinte**, onde ele percebe a falta.

> [!NOTE]
> **Pergunta para você:** se você apagar o `\n` do segundo `printf`, quantas
> linhas aparecem e como fica cada uma? E se escrever `Printf` com P
> maiúsculo, qual estação reclama? Responda e teste no `padaria.c`.

{{pratique}}
