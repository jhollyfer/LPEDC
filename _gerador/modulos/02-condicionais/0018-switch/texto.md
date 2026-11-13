## 0018 · switch, case, break e fall-through

- **`switch`**: a **seleção múltipla**. Calcula a expressão uma vez e **pula
  direto** para o `case` de mesmo valor; o **`default`** pega o que não casou
  (DEITEL; DEITEL, 2011, cap. 4).

```c
switch (codigo) {
case 1:
    // código igual a 1
    break;
case 2:
    // código igual a 2
    break;
default:
    // nenhum dos anteriores
}
```

- **Expressão inteira**: `int`, `char` ou parecido. `double` e texto não
  compilam (DEITEL; DEITEL, 2011, cap. 4).
- **`case` constante**: valor conhecido na compilação (`case 2:`,
  `case 'S':`); `case x:` e `case > 10:` não valem, nem dois `case` iguais
  (KERNIGHAN; RITCHIE, 1988, cap. 3).
- **Fall-through**: o `case` é só um **rótulo** de entrada. Depois de entrar,
  o C executa **tudo para baixo**, atravessando os outros `case`, até um
  **`break`** ou o fim do `switch` (BACKES, 2013, cap. 4).
- **Fall-through de propósito**: `case` empilhados dividem o mesmo trecho
  (`case 'S': case 's':`). Com código no meio, avise com `// fall through`,
  que o gcc reconhece (GNU, s.d.).

> [!WARNING]
> **Esquecer o `break`.** Sem o do `case 2`, pedir X-Salada mostra também
> "Misto quente" e o preço vira **9.00**. O compilador não vê erro; o
> `-Wextra` avisa ("this statement may fall through").

{{exemplo}}

Na lanchonete, 1 é X-Burger, 2 é X-Salada, 3 é Misto quente. O código 2
entra, o `switch` pula direto para o `case 2`, sem testar o 1 nem o 3, e o
`break` sai antes do `case 3`:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    int codigo = 2;
    int quantidade = 2;
    double preco = 0;

    switch (codigo) {
    case 1:
        printf("X-Burger\n");
        preco = 15.00;
        break;
    case 2:
        printf("X-Salada\n");
        preco = 18.00;
        break; // sem ele, cairia no case 3
    case 3:
        printf("Misto quente\n");
        preco = 9.00;
        break;
    default:
        printf("Código inválido\n");
    }
    printf("Total: R$ %.2f\n", quantidade * preco);
    return 0;
}
// Saída:
// X-Salada
// Total: R$ 36.00
```

O losango do `switch` tem **várias** saídas, uma por `case` e uma para o
`default`; as setas levam o valor no lugar de Sim e Não:

{{fluxograma}}
