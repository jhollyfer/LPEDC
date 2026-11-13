## 0070 · Juntando tudo: a caderneta de gastos

Fim de mês, e a pergunta de sempre: para onde foi o dinheiro? Com o que o
módulo mostrou, você monta um controle de gastos de terminal. Cada comando é
uma execução separada do programa, e os dados ficam guardados num arquivo
entre uma execução e outra:

```bash
gastos novo mercado 152.40     # anota um gasto
gastos lista                   # mostra tudo e o total
gastos exporta /tmp/gastos.csv # gera uma planilha
gastos limpa                   # começa do zero
```

Pense numa caderneta de papel que mora na gaveta. Cada vez que você gasta,
abre, anota no fim e guarda. No fim do mês, abre e soma. O programa faz o
mesmo, e cada peça do módulo cuida de uma parte do trabalho.

A primeira peça são os argumentos do assunto 0069. O `argv[1]` diz **o que**
fazer (`novo`, `lista`, `exporta`, `limpa`), e os argumentos seguintes trazem
os dados daquele comando. É o mesmo arranjo do `git`, um programa só com
vários **subcomandos** (`git commit`, `git log`). O `main` confere o `argc`,
compara o `argv[1]` com cada nome e chama a função certa; se nada bater, ou
se faltar argumento, mostra a mensagem de uso (FEOFILOFF, 2009, ap. H).

A segunda peça é o arquivo binário do assunto 0068, que serve de caderneta.
Cada gasto é um registro `Gasto`, de tamanho fixo, gravado com `fwrite`. O
modo `"ab"` abre para acrescentar no fim, sem ler nem apagar o que já existe.
Como todos os registros têm o mesmo tamanho, `ftell(arq) / sizeof(Gasto)`
diz quantos já estão gravados: logo depois de gravar o terceiro, a posição é
96 e a conta dá 3 (DEITEL; DEITEL, 2011, cap. 11).

A terceira peça é o arquivo texto do assunto 0067, para a exportação.
Ninguém abre um `.dat` numa planilha. O comando `exporta` lê os registros
binários com `fread` e escreve cada um com `fprintf` numa linha de **CSV**
(*comma-separated values*, valores separados por um sinal), um formato de
texto em que cada linha é uma linha da planilha e um separador divide as
colunas. Aqui o separador é o `;`, que as planilhas em português abrem direto
(BACKES, 2013, cap. 12).

Quem guarda dados precisa de três cuidados. O primeiro é **validar antes de
gravar**: `strtod` com o teste `*fim != '\0'` impede que um "abc" digitado
por engano entre na caderneta como R$ 0,00 (LINUX MAN-PAGES PROJECT, s.d.).
Depois de gravado, o erro fica lá para sempre.

O segundo cuidado é **não gravar lixo**. O campo `categoria` tem 20 bytes, e
"luz" ocupa só 4 com o `'\0'`. Os outros 16 guardariam o que estivesse antes
naquela parte da memória. O `memset` zera o campo inteiro antes do
`strncpy`, e os bytes que sobram vão para o arquivo como zeros.

O terceiro é lembrar que **arquivo inexistente nem sempre é erro**. Se o
`fopen` em `"rb"` devolve `NULL` no comando `lista`, quase sempre quer dizer
que ninguém anotou nada ainda. O programa responde "Nenhum gasto ainda." e
termina com sucesso, em vez de mostrar uma mensagem de falha.

Um detalhe do modo `"ab"` protege a caderneta: nele, **toda** escrita vai
para o fim do arquivo, mesmo que alguém tenha chamado `fseek` antes. O
sistema garante isso, e por isso dois programas anotando gastos ao mesmo
tempo não escrevem um por cima do outro (LINUX MAN-PAGES PROJECT, s.d.).

> [!WARNING]
> Trocar `"ab"` por `"wb"` no `novo` apaga os gastos anteriores a cada
> anotação, sem aviso. E não leia, por outro `FILE *`, o que acabou de
> escrever antes do `fclose` (ou `fflush`): os bytes ainda estão no buffer, e
> a leitura acha o arquivo vazio ou pela metade.

{{exemplo}}

O controle de gastos do mês roda no terminal, um comando por execução, com os
dados guardados em arquivo entre uma execução e outra:

```bash
gastos novo mercado 152.40     # anota um gasto
gastos lista                   # mostra tudo e o total
gastos exporta /tmp/gastos.csv # gera uma planilha
gastos limpa                   # começa do zero
```

O `novo` acrescenta um registro de 32 bytes em `gastos.dat`, o `lista` o lê de
volta com `fread` e o `exporta` transforma o binário em texto:

{{ideia}}

Cada função repete os exemplos dos três assuntos anteriores, e o `main` só
despacha. Salve como `gastos.c`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "/tmp/gastos.dat"

typedef struct {
    char categoria[20];
    double valor;
} Gasto;

void uso(const char *programa) {
    fprintf(stderr, "Uso: %s novo <categoria> <valor>\n", programa);
    fprintf(stderr, "     %s lista | exporta <arquivo.csv> | limpa\n", programa);
}

int novo(const char *categoria, const char *texto_valor) {
    Gasto g;
    char *fim;
    g.valor = strtod(texto_valor, &fim);
    if (*fim != '\0' || g.valor <= 0) {
        fprintf(stderr, "Valor inválido: %s\n", texto_valor);
        return 1;
    }
    memset(g.categoria, 0, sizeof g.categoria);          // sem lixo no arquivo
    strncpy(g.categoria, categoria, sizeof g.categoria - 1);

    FILE *arq = fopen(ARQUIVO, "ab"); // binário, sempre no fim
    if (arq == NULL) {
        perror(ARQUIVO);
        return 1;
    }
    if (fwrite(&g, sizeof g, 1, arq) != 1) {
        perror(ARQUIVO);
        fclose(arq);
        return 1;
    }
    long registro = ftell(arq) / (long) sizeof(Gasto) - 1;
    fclose(arq);
    printf("Gravado: %s R$ %.2f (registro %ld)\n", g.categoria, g.valor, registro);
    return 0;
}

int lista(void) {
    FILE *arq = fopen(ARQUIVO, "rb");
    if (arq == NULL) {
        printf("Nenhum gasto ainda.\n");
        return 0;
    }
    Gasto g;
    int n = 0;
    double total = 0.0;
    while (fread(&g, sizeof g, 1, arq) == 1) {
        printf("%d  %-12s R$ %8.2f\n", n, g.categoria, g.valor);
        total += g.valor;
        n++;
    }
    fclose(arq);
    printf("Total: R$ %.2f em %d gastos\n", total, n);
    return 0;
}

int exporta(const char *destino) {
    FILE *ent = fopen(ARQUIVO, "rb");
    if (ent == NULL) {
        perror(ARQUIVO);
        return 1;
    }
    FILE *sai = fopen(destino, "w"); // texto, para abrir na planilha
    if (sai == NULL) {
        perror(destino);
        fclose(ent);
        return 1;
    }
    fprintf(sai, "categoria;valor\n");
    Gasto g;
    int n = 0;
    while (fread(&g, sizeof g, 1, ent) == 1) {
        fprintf(sai, "%s;%.2f\n", g.categoria, g.valor);
        n++;
    }
    fclose(ent);
    fclose(sai);
    printf("%d gastos exportados para %s\n", n, destino);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        uso(argv[0]);
        return 1;
    }
    const char *comando = argv[1];

    if (strcmp(comando, "novo") == 0 && argc == 4) {
        return novo(argv[2], argv[3]);
    }
    if (strcmp(comando, "lista") == 0 && argc == 2) {
        return lista();
    }
    if (strcmp(comando, "exporta") == 0 && argc == 3) {
        return exporta(argv[2]);
    }
    if (strcmp(comando, "limpa") == 0 && argc == 2) {
        remove(ARQUIVO);
        printf("Caderneta apagada.\n");
        return 0;
    }
    uso(argv[0]);
    return 1;
}
// $ ./programa limpa
// Caderneta apagada.
// $ ./programa novo mercado 152.40
// Gravado: mercado R$ 152.40 (registro 0)
// $ ./programa novo luz 98.75
// Gravado: luz R$ 98.75 (registro 1)
// $ ./programa novo farmacia 45.30
// Gravado: farmacia R$ 45.30 (registro 2)
// $ ./programa lista
// 0  mercado      R$   152.40
// 1  luz          R$    98.75
// 2  farmacia     R$    45.30
// Total: R$ 296.45 em 3 gastos
// $ ./programa exporta /tmp/gastos.csv
// 3 gastos exportados para /tmp/gastos.csv
```

O fluxograma segue o comando `lista`. O `main` testa o comando até achar um
conhecido; comando desconhecido, ou com argumentos faltando, cai na mensagem de
uso:

{{fluxograma}}
