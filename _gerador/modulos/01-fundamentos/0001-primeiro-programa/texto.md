## 0001 · O primeiro programa

- **Programa em C**: um conjunto de **funções**. A execução sempre começa pela
  função **`main`** (KERNIGHAN; RITCHIE, 1988, cap. 1).
- **Instrução**: um comando terminado em `;`. As **chaves** `{ }` agrupam
  instruções num **bloco** (DEITEL; DEITEL, 2011, cap. 2).
- **`#include <stdio.h>`**: traz as declarações de entrada e saída, como a do
  `printf`. Linha com `#` é ordem para o pré-processador, não instrução, e
  não leva `;` (BACKES, 2013, cap. 1).
- **`return 0`**: encerra a `main` e avisa o sistema que deu tudo certo
  (BACKES, 2013, cap. 1).
- **Comentário**: texto que o compilador ignora. `//` vale até o fim da linha;
  `/* ... */` pode ocupar várias linhas (DEITEL; DEITEL, 2011, cap. 2).
- **Do `.c` ao executável**: o `gcc` passa por quatro etapas. O
  **pré-processador** trata as linhas com `#`, o **compilador** traduz para
  assembly, o **montador** gera o código objeto (`.o`) e o **ligador** junta
  o `.o` com a biblioteca padrão (GNU, s.d.).
- **Tipos de erro**: de **compilação** (falta `;`, `Int` no lugar de `int`),
  de **ligação** (função que não existe, como `prinft`) e de **execução**
  (roda, mas dá resultado errado ou quebra) (DEITEL; DEITEL, 2011, cap. 2).

| Linha | Para que serve |
| --- | --- |
| `#include <stdio.h>` | declara o `printf` |
| `int main(void) {` | começa a `main`; não recebe nada e devolve um `int` |
| `printf("...\n");` | mostra texto; `\n` pula a linha |
| `return 0;` | termina com sucesso |
| `}` | fecha o bloco |

> [!WARNING]
> O `printf` não pula linha sozinho: `printf("Pão"); printf("Quente");` mostra
> `PãoQuente`. E o C diferencia maiúsculas: `Main` e `Printf` não existem.

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
