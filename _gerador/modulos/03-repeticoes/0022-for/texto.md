## 0022 · For

- **Laço com contador**: tem começo, condição e passo. Com `while`, o contador
  aparece em três lugares, e esquecer o passo dá laço infinito
  (DEITEL; DEITEL, 2011, cap. 4).

```c
int parcela = 1;              // começa
while (parcela <= 6) {        // pergunta
    printf("Parcela %d\n", parcela);
    parcela++;                // passo, lá no fim do corpo
}
```

- **`for`**: junta início, condição e passo numa linha
  (BACKES, 2013, cap. 5).

```c
for (int parcela = 1; parcela <= 6; parcela++) {
    printf("Parcela %d\n", parcela);
}
```

- **Ordem de execução**: o **início** roda uma vez; a **condição** é testada
  antes de cada volta; depois vem o **corpo**; o **passo** roda no fim da
  volta e volta para a condição (CARVALHO, 2010).
- **`for` e `while`**: o `for` é o `while` reorganizado. Use `for` com
  contador de começo, fim e passo conhecidos; `while` quando só se sabe a
  condição de parada (KERNIGHAN; RITCHIE, 1988, cap. 3).
- **Variações**: o `int` declarado no `for` só existe no laço (C99). O passo
  pode ser qualquer conta (`c += 10`, `x *= 3`), o contador pode ser `char` e
  a vírgula permite duas variáveis (A044). Partes vazias valem, mas os dois
  `;` não: `for (;;)` é laço infinito (BACKES, 2013, cap. 5).
- **Quantas voltas**: `for (i = a; i < b; i++)` dá `b - a`; com `<=`,
  `b - a + 1` (DEITEL; DEITEL, 2011, cap. 4).

> [!WARNING]
> **Erro por um** (*off-by-one*): `for (int p = 1; p < 6; p++)` mostra 5
> parcelas. Pergunte qual é o **primeiro** e o **último** valor que passa. E
> contador é sempre inteiro: `for (double x = 0.1; x != 1.0; x += 0.1)` nunca
> termina.

{{exemplo}}

Uma TV de R$ 1.800 em 6 parcelas. O carnê começa com `parcela = 1` uma vez
só, pergunta "parcela <= 6?", roda o corpo, dá o passo e volta à pergunta; na
sétima, a resposta é Não:

{{ideia}}

```c
#include <stdio.h>

int main(void) {
    double preco = 1800.0;
    int total_parcelas = 6;
    double valor = preco / total_parcelas;
    double falta = preco;

    for (int parcela = 1; parcela <= total_parcelas; parcela++) {
        falta = falta - valor;
        printf("Parcela %d/%d: R$ %.2f (falta R$ %.2f)\n",
               parcela, total_parcelas, valor, falta);
    }
    printf("Carnê quitado!\n");
    return 0;
}
// Saída:
// Parcela 1/6: R$ 300.00 (falta R$ 1500.00)
// Parcela 2/6: R$ 300.00 (falta R$ 1200.00)
// Parcela 3/6: R$ 300.00 (falta R$ 900.00)
// Parcela 4/6: R$ 300.00 (falta R$ 600.00)
// Parcela 5/6: R$ 300.00 (falta R$ 300.00)
// Parcela 6/6: R$ 300.00 (falta R$ 0.00)
// Carnê quitado!
```

O fluxograma é igual ao de um `while`: o passo `parcela++` fica no fim do
corpo, e a seta sai dele de volta ao losango:

{{fluxograma}}
