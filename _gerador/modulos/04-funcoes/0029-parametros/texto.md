## 0029 · Parâmetros e passagem por valor

- **Passagem por valor**: na chamada, o C calcula cada argumento e **copia** o
  valor para o parâmetro. É a única forma de passagem do C (DEITEL; DEITEL,
  2011, cap. 5).
- **Parâmetro formal e real**: o da definição é o **formal**; o valor da
  chamada é o **argumento** (ou parâmetro real) (ROCHA; BORGES, s.d.).
- **Parâmetro é local**: nasce com a cópia e pode mudar à vontade; a variável
  de quem chamou não muda (BACKES, 2013, cap. 9).
- **Por referência**: o C simula passando um endereço (assunto 0046)
  (DEITEL; DEITEL, 2011, cap. 5).
- **Retorno guardado**: o resultado volta só pelo `return`, e quem chama
  precisa guardá-lo (`x = f(x)`); senão se perde (KERNIGHAN; RITCHIE, 1989,
  cap. 4).
- **Conversão automática**: argumento de outro tipo é convertido como numa
  atribuição; `2.9` passado a um `int` vira `2`, sem aviso (KERNIGHAN;
  RITCHIE, 1989, cap. 4).
- **`(void)`**: `void linha(void)` não aceita argumento. `void linha()`, no
  C17, não confere nada e aceita `linha(5)` calado. Escreva `(void)`
  (BACKES, 2013, cap. 9).

> [!WARNING]
> `void trocar(int a, int b)` troca só as cópias: nada muda no `main`. Para a
> função mexer numa variável sua, passe o **endereço** (o `&` do `scanf`,
> assunto 0046).

{{exemplo}}

A academia reajusta a mensalidade de R$ 120,00 em 10%. Há duas `mensalidade`
na memória, a do `main` e a cópia da função, e só a cópia vira 132.00:

{{ideia}}

```c
#include <stdio.h>

double reajustar(double mensalidade, double percentual);

int main(void) {
    double mensalidade = 120.00;

    printf("Antes: %.2f\n", mensalidade);
    reajustar(mensalidade, 10); // o resultado é jogado fora
    printf("Depois: %.2f\n", mensalidade); // continua 120.00

    mensalidade = reajustar(mensalidade, 10); // agora guarda o retorno
    printf("Guardando o retorno: %.2f\n", mensalidade);
    return 0;
}

// mensalidade aqui é uma CÓPIA: outra variável, com o mesmo nome
double reajustar(double mensalidade, double percentual) {
    mensalidade = mensalidade * (1 + percentual / 100);
    printf("Dentro: %.2f\n", mensalidade);
    return mensalidade;
}
// Saída:
// Antes: 120.00
// Dentro: 132.00
// Depois: 120.00
// Dentro: 132.00
// Guardando o retorno: 132.00
```

O valor sai por cópia e só volta pelo `return`; guardar ou não o retorno
decide se o `main` fica sabendo:

{{fluxograma}}
