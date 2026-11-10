## 0030 · Escopo e tempo de vida

No banco, o painel chama a senha 101, depois a 102, depois a 103: ele
**lembra** onde parou. O atendente zera a conversa a cada cliente: não guarda
nada do anterior. Programa precisa das duas coisas, e o C tem uma ferramenta
para cada.

Toda variável tem duas propriedades:

- **escopo**: **onde** no código o nome pode ser usado;
- **tempo de vida**: **quando** a variável existe na memória.

São três tipos:

| Tipo | Onde declara | Escopo | Tempo de vida |
| --- | --- | --- | --- |
| **local** (automática) | dentro de `{ }` | só aquele bloco | nasce ao entrar no bloco, morre ao sair |
| **global** | fora de qualquer função | do ponto da declaração até o fim do arquivo | o programa todo |
| **`static` local** | dentro de `{ }`, com `static` | só aquele bloco | o programa todo |

A `static` local tem escopo de local (ninguém de fora a enxerga) e tempo de
vida de global. A linha `static int senha = 100;` roda **uma vez**, antes de o
programa começar. Nas chamadas seguintes, a variável continua com o valor que
tinha.

Parâmetros são locais da função, e a variável do `for (int i = 0; ...)` é
local do laço. Se um bloco interno declara um nome que já existe fora, o de
dentro **esconde** o de fora até o bloco acabar: vale a declaração mais
próxima.

A função `chamar` tem três contadores: a global `atendidos`, a `static`
`senha` e a local `vezes`. As duas primeiras ficam numa região da memória que
dura o programa inteiro; a local fica no espaço da chamada e some quando a
função retorna. Depois de três chamadas:

{{ideia}}

No código, `vezes` mostra sempre 1, enquanto os outros dois avançam:

```c
#include <stdio.h>

int atendidos = 0; // global: vive o programa todo, todo mundo enxerga

int chamar(void) {
    static int senha = 100; // static: inicializada uma vez só, guarda o valor
    int vezes = 0;          // local: nasce de novo a cada chamada

    senha++;
    vezes++;
    atendidos++;
    printf("Senha %d | vezes: %d | atendidos: %d\n", senha, vezes, atendidos);
    return senha;
}

int main(void) {
    chamar();
    chamar();
    int ultima = chamar();
    printf("Última senha chamada: %d\n", ultima);
    return 0;
}
// Saída:
// Senha 101 | vezes: 1 | atendidos: 1
// Senha 102 | vezes: 1 | atendidos: 2
// Senha 103 | vezes: 1 | atendidos: 3
// Última senha chamada: 103
```

A cada chamada, a local nasce de novo com 0, e a `static` já espera com o
valor anterior. Não existe passo "criar senha" dentro da repetição:

{{fluxograma}}

As globais funcionam, mas cobram caro. **Qualquer** função do arquivo pode
mudar `atendidos`, então, quando o valor sai errado, o culpado pode estar em
qualquer lugar, e a mesma chamada pode dar resultados diferentes conforme o
que outra função fez antes. Prefira parâmetro e `return`; use global só para o
que é do programa todo.

`static` **fora** de função muda outra coisa: uma global `static int total;`
vive o programa todo, mas só pode ser usada **naquele arquivo**. Isso faz
sentido no assunto 0034, com mais de um `.c`.

> [!WARNING]
> `static int senha = 100;` não volta a valer 100 a cada chamada: a
> inicialização acontece uma vez, antes do `main`. O oposto também engana: uma
> local **sem** inicialização (`int total;`) começa com lixo, não com 0.
> Globais e `static` sem valor começam em 0; locais, não. E esconder nomes
> (`int nivel` dentro e fora) compila sem aviso com `-Wall`: só o `-Wshadow`
> reclama.

> [!TIP]
> Globais e `static` ficam numa região fixa da memória, gravada no executável
> (`.data`) ou zerada ao carregar (`.bss`). As locais ficam na **pilha**, que
> é o próximo assunto.

> [!NOTE]
> **Pergunta para você:** se você tirar o `static` de `senha`, quais números
> aparecem nas três linhas? E se, em vez disso, você mover `int vezes = 0;`
> para fora da função?

{{pratique}}
