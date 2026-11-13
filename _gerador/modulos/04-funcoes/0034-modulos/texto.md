## 0034 · Módulos: .h, .c e compilação separada

- **Módulo**: um par de arquivos. O `.h` (cabeçalho) é a **interface**: diz
  **o que** o módulo oferece, com protótipos e constantes. O `.c` é a
  **implementação**: diz **como**, e inclui o próprio `.h` (BACKES, 2013,
  cap. 13).
- **`#include`**: cola o texto do arquivo ali. Com aspas, procura primeiro na
  pasta do `.c`; com `< >`, só nas pastas do sistema (DEITEL; DEITEL, 2011,
  cap. 5).
- **Compilação separada**: cada `.c` vira um **arquivo objeto** (`.o`) sem
  saber dos outros; o **ligador** (*linker*) junta os `.o` e resolve os nomes
  (KERNIGHAN; RITCHIE, 1989, cap. 4).
- **Include guard**: `#ifndef X_H` / `#define X_H` / `#endif` faz o `.h`
  entrar uma vez só por `.c`, mesmo incluído duas vezes (GNU, s.d.).
- **`static` fora de função**: esconde a global ou a função dos outros
  arquivos; o módulo muda por dentro sem quebrar quem o usa (KERNIGHAN;
  RITCHIE, 1989, cap. 4).
- **`extern`**: declara uma global definida noutro arquivo (`extern int
  limite;` no `.h`, `int limite = 10;` em um `.c` só) (BACKES, 2013, cap. 13).

```bash
gcc -std=c17 -Wall -Wextra -c conversao.c       # gera conversao.o
gcc -std=c17 -Wall -Wextra -c viagem.c            # gera viagem.o
gcc viagem.o conversao.o -o viagem                # o ligador junta
gcc -std=c17 -Wall -Wextra viagem.c conversao.c -o viagem   # ou tudo de uma vez
```

> [!WARNING]
> Corpo de função no `.h`: dois `.c` que o incluem geram
> `multiple definition of` no ligador, e o include guard não salva. Nunca
> escreva `#include "conversao.c"`.

{{exemplo}}

A conversão de unidades mora num módulo só. O `conversao.h` é incluído pelos
dois `.c`; cada um vira um `.o`, e o ligador junta os dois no executável
`viagem`:

{{ideia}}

O `conversao.h`:

```c
// conversao.h · a interface do módulo: O QUE ele oferece
#ifndef CONVERSAO_H
#define CONVERSAO_H

double celsius_para_fahrenheit(double celsius);
double km_para_milhas(double km);
double reais_para_dolares(double reais, double cotacao);
int conversoes_feitas(void);

#endif
```

O `conversao.c` (na pasta do assunto) tem o corpo das funções, um contador
`static` e uma função auxiliar `static`. O `viagem.c` só precisa do `.h`:

```c
#include <stdio.h>

#include "conversao.h" // aspas: procura primeiro na pasta deste arquivo

int main(void) {
    printf("30 °C = %.1f °F\n", celsius_para_fahrenheit(30));
    printf("100 km = %.1f milhas\n", km_para_milhas(100));
    printf("R$ 1000.00 = US$ %.2f\n", reais_para_dolares(1000, 5.40));
    return 0;
}
// Compilando à mão (o gcc com as flags de estudo faz isso sozinho):
//   gcc -std=c17 -Wall -Wextra viagem.c conversao.c -o viagem
// Saída:
// 30 °C = 86.0 °F
// 100 km = 62.1 milhas
// R$ 1000.00 = US$ 185.19
```

Cada `.c` passa pelo compilador separado; o erro de "função que não existe"
só aparece no ligador:

{{fluxograma}}
