## 0030 · Escopo e tempo de vida

Com funções, o programa passa a ter muitas variáveis espalhadas, e duas
perguntas aparecem. Uma variável do `main` pode ser usada dentro de outra
função? E o valor de uma variável da função sobrevive de uma chamada para a
seguinte? As duas respostas dependem de onde e de como a variável foi
declarada.

No banco, o painel chama a senha 101, depois a 102, depois a 103: ele
**lembra** onde parou. O atendente, ao contrário, começa a conversa do zero a
cada cliente e não guarda nada do anterior. Um programa precisa das duas
coisas, e o C tem uma ferramenta para cada. Para entender qual usar, separe
duas propriedades que toda variável tem (DEITEL; DEITEL, 2011, cap. 5). O
**escopo** diz **onde** no código o nome da variável pode ser usado. O
**tempo de vida**, também chamado de duração, diz **quando** a variável existe
na memória.

A variável **local** é declarada dentro de um bloco `{ }` e só pode ser usada
nele (BACKES, 2013, cap. 9). Os parâmetros são locais da função, e o `i` de
`for (int i = 0; ...)` é local do laço. O tempo de vida acompanha o escopo: a
local nasce quando o programa entra no bloco e morre quando sai. Por isso ela
também se chama **automática**. É o atendente: a cada chamada, uma local
começa de novo. E começa com **lixo**, se você não der um valor inicial,
porque a memória que ela ocupa guarda o que sobrou de antes.

A variável **global** é declarada fora de qualquer função. Seu escopo vai do
ponto da declaração até o fim do arquivo, e ela vive enquanto o programa roda
(BACKES, 2013, cap. 9). Parece prático, porque todas as funções a enxergam.
O custo aparece quando algo dá errado: se o valor está estranho, qualquer
função pode ter mexido nele, e você precisa ler o programa inteiro para achar
o culpado. Prefira passar dados por parâmetro e devolver pelo `return`.

O painel do banco pede uma terceira combinação: uma variável que só a função
enxerga, mas que lembra o valor entre as chamadas. É a **`static` local**,
declarada dentro do bloco com a palavra `static`. Ela tem o escopo de uma
local e o tempo de vida de uma global (KERNIGHAN; RITCHIE, 1989, cap. 4). A
linha `static int senha = 100;` roda **uma vez**, antes de o programa
começar. Nas chamadas seguintes, a variável continua com o valor que tinha
quando a função terminou da última vez.

Globais e `static` têm outra diferença em relação às locais: sem valor
inicial, começam em **0**. Elas ficam numa região fixa da memória, separada da
região das locais, e essa região é preparada quando o programa carrega. As
locais ficam na **pilha**, que é o assunto 0031.

Os escopos também podem se sobrepor. Se um bloco interno declara um nome que
já existe fora, o de dentro **esconde** o de fora até o bloco acabar (DEITEL;
DEITEL, 2011, cap. 5). Vale sempre a declaração mais próxima. O de fora não
mudou; ele só fica fora de alcance por um trecho.

A palavra `static` tem ainda um segundo uso. Escrita numa global, fora de
qualquer função, ela não muda o tempo de vida, que já é o programa todo; ela
restringe o escopo ao arquivo `.c` em que a global está (KERNIGHAN; RITCHIE,
1989, cap. 4). O assunto 0034 usa isso para esconder dados de um módulo.

A tabela resume os três tipos de variável:

| Tipo | Onde declara | Escopo | Tempo de vida |
| --- | --- | --- | --- |
| **local** (automática) | dentro de `{ }` | só aquele bloco | nasce ao entrar no bloco, morre ao sair |
| **global** | fora de qualquer função | do ponto da declaração até o fim do arquivo | o programa todo |
| **`static` local** | dentro de `{ }`, com `static` | só aquele bloco | o programa todo |

> [!WARNING]
> `static int senha = 100;` não volta a valer 100 a cada chamada: a
> inicialização acontece uma vez. O oposto também engana: uma local **sem**
> inicialização começa com lixo, não com 0. E esconder nomes compila sem aviso
> com `-Wall`: só o `-Wshadow` reclama.

{{exemplo}}

O painel do banco lembra a última senha; o atendente zera a conversa a cada
cliente. A função `chamar` tem a global `atendidos`, a `static` `senha` e a
local `vezes`. Depois de três chamadas:

{{ideia}}

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

A local nasce de novo com 0 a cada chamada; a `static` já espera com o valor
anterior:

{{fluxograma}}
