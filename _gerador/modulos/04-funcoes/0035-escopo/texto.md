## 0035 · Escopo e tempo de vida

No banco, o painel chama a senha 101, depois a 102, depois a 103. Ele
**lembra** onde parou. Já o atendente que te chama zera a conversa a cada
cliente: não guarda nada da pessoa anterior. Programa precisa das duas
coisas, e o C dá ferramentas diferentes para cada uma.

Toda variável tem duas propriedades que é bom separar na cabeça:

- **escopo**: **onde** no código o nome pode ser usado;
- **tempo de vida**: **quando** a variável existe na memória.

São três tipos que você vai usar o tempo todo:

| Tipo | Onde declara | Escopo | Tempo de vida |
| --- | --- | --- | --- |
| **local** | dentro de `{ }` | só aquele bloco | nasce ao entrar no bloco, morre ao sair |
| **global** | fora de qualquer função | do ponto da declaração até o fim do arquivo | o programa todo |
| **`static` local** | dentro de `{ }`, com `static` | só aquele bloco | o programa todo |

A `static` local é a mais curiosa: o **escopo** é de local (ninguém de fora
enxerga), mas o **tempo de vida** é de global. A linha `static int senha =
100;` roda **uma vez só**, antes de o programa começar. Nas chamadas
seguintes, a variável continua lá, com o valor que tinha.

Parâmetros são locais da função, e a variável do `for (int i = 0; ...)` é
local do laço. Se um bloco interno declara um nome que já existe fora, o de
dentro **esconde** o de fora até o bloco acabar. Vale sempre a declaração mais
próxima.

Vamos ver na prática. A função `chamar` tem três contadores: a global
`atendidos`, a `static` `senha` e a local `vezes`. As duas primeiras moram
numa região da memória que dura o programa inteiro; a local mora no espaço da
chamada e some quando a função retorna. Depois de três chamadas, fica assim:

{{ideia}}

No código, repare que `vezes` mostra 1 sempre, enquanto os outros dois
avançam:

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

Repara no fluxograma: a cada chamada, a local é criada de novo com 0, e a
`static` já está esperando com o valor anterior. Não existe um passo
"criar senha" dentro da repetição:

{{fluxograma}}

E as globais? Funcionam, mas cobram caro. **Qualquer** função do arquivo pode
mudar `atendidos`, então, quando o valor sai errado, o culpado pode estar em
qualquer lugar. A mesma chamada pode dar resultados diferentes conforme o que
outra função fez antes. Prefira passar por parâmetro e devolver com `return`;
use global só para algo que é de fato do programa todo. No TS é o mesmo
conselho de evitar `let` no topo do módulo.

Uma última peça: `static` **fora** de função muda outra coisa. Uma global
`static int total;` continua vivendo o programa todo, mas só pode ser usada
**naquele arquivo**. Isso vai fazer sentido no assunto 0039, quando o programa
tiver mais de um `.c`.

> [!WARNING]
> Achar que `static int senha = 100;` volta a valer 100 a cada chamada. Não
> volta: a inicialização acontece uma vez, antes do `main`. O oposto também
> engana: uma local **sem** inicialização (`int total;`) não começa em 0, começa
> com o lixo que estava naquele pedaço da memória. Globais e `static` sem
> valor começam em 0; locais, não. E esconder nomes (`int nivel` dentro e
> fora) compila sem nenhum aviso com `-Wall`: só o `-Wshadow` reclama.

> [!TIP]
> **Por dentro do C:** a memória do programa tem regiões. Globais e `static`
> com valor inicial ficam na seção **`.data`**, gravada dentro do próprio
> executável; as que começam em zero ficam na **`.bss`**, que o sistema zera ao
> carregar o programa. As locais ficam na **pilha**, um espaço reaproveitado a
> cada chamada (o próximo assunto). Rode `gcc -c A069.c` e depois `nm A069.o`:
> aparecem `atendidos` (B, na `.bss`) e `senha.0` (d, na `.data`). A `vezes`
> nem aparece: ela não tem lugar fixo.

> [!NOTE]
> **Pergunta para você:** se você tirar o `static` de `senha`, quais números
> aparecem nas três linhas? E se, em vez disso, você mover `int vezes = 0;` para
> fora da função?

{{pratique}}
