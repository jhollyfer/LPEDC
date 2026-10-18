## 0005 · Do .c ao executável

No TypeScript, você escreve, roda `tsx arquivo.ts` e pronto. O código é
traduzido na hora, enquanto roda. No C é diferente: antes de rodar, o arquivo
`.c` passa por uma linha de montagem e vira um **executável**, um arquivo com
instruções de máquina que o processador entende direto. Quem faz isso é o
**compilador**, e o nosso é o `gcc`.

A linha de montagem tem quatro estações:

1. **pré-processador** (`gcc -E`): trata as linhas que começam com `#`. O
   `#include <stdio.h>` é literalmente **colar** o conteúdo do arquivo
   `stdio.h` no lugar da linha. O `#define` troca um nome por um texto. Ele não
   entende C: só recorta e cola texto.
2. **compilador** (`gcc -S`): lê o C, confere a gramática e os tipos, otimiza e
   escreve **assembly**, a língua do processador em forma de texto
   (`mov`, `add`, `call`).
3. **montador** (`gcc -c`): transforma o assembly em **código objeto** (`.o`),
   já em binário, mas ainda com buracos: ele sabe que você chamou `printf`, mas
   não sabe onde o `printf` está.
4. **ligador** (*linker*): junta o seu `.o` com as bibliotecas (onde mora o
   `printf`), tapa os buracos e grava o executável.

Na prática você chama tudo de uma vez:

```bash
gcc ola.c -o ola    # as quatro estações
./ola               # roda o executável
```

O `rodar` do curso faz isso por você, com mais cuidado: liga todos os avisos
(`-Wall -Wextra -pedantic`), usa o padrão C17 (`-std=c17`) e ativa o
**AddressSanitizer** (`-fsanitize=address,undefined`), que vigia a memória
enquanto o programa roda.

Vamos ver na prática. O arquivo `ola.c` entra na linha de montagem, passa pelas
quatro estações e sai como o executável `ola`, que mostra a mensagem no
terminal:

{{ideia}}

O primeiro programa de todo curso de C. No módulo 01 você vai dissecar cada
linha:

```c
#include <stdio.h>

int main(void) {
    printf("Olá, LPEDC!\n");
    return 0;
}
// Saída:
// Olá, LPEDC!
```

Repara no fluxograma: cada estação pode parar a linha de montagem. Se uma
reclamar, as seguintes nem começam:

{{fluxograma}}

> [!WARNING]
> Saber **qual estação reclamou** é meio caminho para consertar. Arquivo do
> `#include` não encontrado é erro do pré-processador. Falta de `;` ou tipo
> errado é erro do compilador (aparece com o número da linha). `undefined
> reference to 'prinft'` é erro do **ligador**: o código está gramaticalmente
> certo, mas a função não existe em lugar nenhum. E tem o pior tipo: o programa
> compila e só dá errado quando roda.

> [!TIP]
> **Por dentro do C:** rode `gcc -E A009.c | wc -l` e veja que o seu programa
> de 6 linhas vira centenas de linhas depois do pré-processador: é o
> `stdio.h` colado. Rode `gcc -S A009.c` e abra o `A009.s`: você vai achar o
> texto "Olá, LPEDC!" e uma chamada a `puts`, não a `printf`. O compilador
> percebeu que você só queria imprimir um texto fixo com `\n` e trocou por uma
> função mais simples. Ele não traduz palavra por palavra: ele entende e
> melhora o seu código.

> [!NOTE]
> **Pergunta para você:** o executável `ola` gerado no Linux roda no Windows?
> E o `ola.c`? Pense no que cada um contém antes de responder.

{{pratique}}
