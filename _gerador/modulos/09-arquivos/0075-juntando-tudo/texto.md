## 0075 · Juntando tudo: a caderneta de gastos

Fim de mês e a pergunta de sempre: para onde foi o dinheiro? Aplicativo de
finanças resolve, mas você agora tem tudo para fazer o seu, de terminal, do
jeito que os programas de linha de comando funcionam: um comando por
execução, com os dados guardados em arquivo entre uma execução e outra.

```bash
gastos novo mercado 152.40     # anota um gasto
gastos lista                   # mostra tudo e o total
gastos exporta /tmp/gastos.csv # gera uma planilha
gastos limpa                   # começa do zero
```

O programa junta as três peças do módulo, cada uma no papel em que é melhor:

- **argumentos** (0074): `argv[1]` diz **o que** fazer; os seguintes trazem
  os dados. É o mesmo desenho do `git` (`git commit`, `git log`): um
  programa, vários subcomandos. O `main` só confere o `argc` de cada comando e
  chama a função certa.
- **arquivo binário** (0073): a caderneta em si. Cada gasto é um registro
  `Gasto` de tamanho fixo, gravado com `fwrite` em modo `"ab"`: binário e
  sempre no fim, sem precisar ler o que já existe. Como os registros têm o
  mesmo tamanho, `ftell / sizeof(Gasto)` diz quantos já existem.
- **arquivo texto** (0072): a exportação. O binário é ótimo para o programa,
  mas ninguém abre um `.dat` na planilha. O `exporta` lê os registros e
  escreve um **CSV** com `fprintf`, separado por `;`, que o LibreOffice e o
  Google Planilhas abrem direto.

Três cuidados que valem para todo programa que guarda dados. **Valide antes de
gravar**: um `strtod` com `*fim != '\0'` impede que "abc" entre na caderneta
como R$ 0,00. **Não grave lixo**: o `memset` zera o vetor `categoria` antes
do `strncpy`, então os bytes que sobram no arquivo são zeros, e não restos da
pilha. **Arquivo que não existe não é erro** em toda situação: no `lista`,
quer dizer só "nenhum gasto ainda".

Vamos ver na prática. Cada linha do terminal é uma execução separada do
programa. O `novo` acrescenta um registro de 32 bytes em `gastos.dat`; o
`lista` lê os registros de volta com `fread`; o `exporta` transforma o binário
em texto:

{{ideia}}

O programa é longo, mas cada função cabe na cabeça:
`novo`, `lista` e `exporta` são os exemplos dos três assuntos anteriores, e o
`main` é só o despachante.

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
// $ rodar A149.c limpa
// Caderneta apagada.
// $ rodar A149.c novo mercado 152.40
// Gravado: mercado R$ 152.40 (registro 0)
// $ rodar A149.c novo luz 98.75
// Gravado: luz R$ 98.75 (registro 1)
// $ rodar A149.c novo farmacia 45.30
// Gravado: farmacia R$ 45.30 (registro 2)
// $ rodar A149.c lista
// 0  mercado      R$   152.40
// 1  luz          R$    98.75
// 2  farmacia     R$    45.30
// Total: R$ 296.45 em 3 gastos
// $ rodar A149.c exporta /tmp/gastos.csv
// 3 gastos exportados para /tmp/gastos.csv
```

Repara no fluxograma do comando `lista`: o `main` vai perguntando qual é o
comando até achar um que ele conhece. Comando desconhecido, ou com argumentos
de menos, cai no mesmo lugar: a mensagem de uso:

{{fluxograma}}

> [!WARNING]
> Trocar `"ab"` por `"wb"` no `novo` é o erro mais caro do módulo: cada gasto
> novo apagaria todos os anteriores, sem aviso. E não leia o que acabou de
> escrever pelo mesmo caminho com outro `FILE *` antes do `fclose` (ou
> `fflush`): os bytes ainda estão no buffer, e a leitura acha o arquivo vazio
> ou pela metade. O E449 junta os dois erros num programa só.

> [!TIP]
> **Por dentro do C:** em `"ab"` (ou `"a"`), **toda** escrita vai para o fim do
> arquivo, mesmo que você chame `fseek` antes. No Linux, o `fopen` pede ao
> sistema o modo `O_APPEND`, e o próprio núcleo posiciona no fim a cada
> `write`. Por isso dois programas anotando gastos ao mesmo tempo não
> sobrescrevem um ao outro (desde que cada registro saia num `write` só). Já o
> `return` do `main` vira o código de saída: rode `rodar A149.c novo x abc;
> echo $?` e veja o 1. É assim que scripts encadeiam comandos com `&&`.

> [!NOTE]
> **Pergunta para você:** a categoria tem 20 bytes. O que acontece com
> `gastos novo supermercado-do-bairro-novo 10`? O texto aparece inteiro no
> `lista`? Pense no `strncpy` com `sizeof g.categoria - 1` e só depois teste.

{{pratique}}
