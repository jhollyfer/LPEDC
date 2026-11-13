## 0030 · Escopo e tempo de vida

- **Escopo**: **onde** no código o nome pode ser usado (DEITEL; DEITEL, 2011,
  cap. 5).
- **Tempo de vida** (duração): **quando** a variável existe na memória.
  Automática nasce e morre com o bloco; estática dura o programa todo
  (DEITEL; DEITEL, 2011, cap. 5).
- **Local**: declarada dentro de `{ }`; parâmetros e o `i` do `for` também
  são locais. Sem valor inicial, começa com lixo (BACKES, 2013, cap. 9).
- **Global**: declarada fora das funções; qualquer função pode mudá-la, o que
  dificulta achar erros. Prefira parâmetro e `return` (BACKES, 2013, cap. 9).
- **`static` local**: escopo de local, vida de global. A inicialização roda
  uma vez, e o valor fica entre as chamadas (KERNIGHAN; RITCHIE, 1989, cap. 4).
- **Esconder nomes**: um nome declarado num bloco interno esconde o de fora até
  o bloco acabar (DEITEL; DEITEL, 2011, cap. 5).
- **`static` fora de função**: global visível só naquele `.c` (assunto 0034)
  (KERNIGHAN; RITCHIE, 1989, cap. 4).

| Tipo | Onde declara | Escopo | Tempo de vida |
| --- | --- | --- | --- |
| **local** (automática) | dentro de `{ }` | só aquele bloco | nasce ao entrar no bloco, morre ao sair |
| **global** | fora de qualquer função | do ponto da declaração até o fim do arquivo | o programa todo |
| **`static` local** | dentro de `{ }`, com `static` | só aquele bloco | o programa todo |

> [!WARNING]
> `static int senha = 100;` não volta a 100 a cada chamada. Globais e `static`
> sem valor começam em 0; locais começam com lixo. Esconder nomes compila sem
> aviso com `-Wall`: só o `-Wshadow` reclama.

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
