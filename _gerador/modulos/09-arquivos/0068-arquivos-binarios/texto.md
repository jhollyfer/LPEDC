## 0068 · Arquivos binários

O mercadinho guarda o estoque em fichas do mesmo tamanho. Para achar a
terceira, ninguém lê as duas primeiras: mede com o dedo e puxa. No arquivo
texto isso não dá, porque cada linha tem um tamanho ("Luz 98.75" tem 9
caracteres, "Internet 99.90" tem 14). Para chegar à linha 500, lê-se as 499
anteriores.

Um **arquivo binário** grava os bytes **exatamente como estão na memória**,
sem converter em texto. Um `int` ocupa sempre 4 bytes; uma struct, sempre
`sizeof` da struct. Com **registros de tamanho fixo**, o registro `i` começa
no byte `i * sizeof(registro)`.

| | texto (`fprintf`) | binário (`fwrite`) |
| --- | --- | --- |
| o `int` 12345678 | 8 bytes: `'1' '2' ... '8'` | 4 bytes: `4E 61 BC 00` |
| abre no editor? | sim | vira lixo na tela |
| converte na ida e na volta? | sim (mais lento) | não, só copia bytes |
| acesso direto ao registro `i`? | não | sim, com `fseek` |
| lê em outra máquina? | sim | só se `int`, alinhamento e ordem dos bytes forem iguais |

Ferramentas:

- **Modo com `b`**: `"wb"`, `"rb"`, `"ab"`, `"rb+"`. No Linux e no Mac o `b`
  não muda nada; no Windows, sem ele, a biblioteca troca `\n` por `\r\n` e
  estraga os bytes. Escreva sempre.
- **`fwrite(endereco, tamanho, quantidade, arq)`** copia `tamanho *
  quantidade` bytes a partir do endereço. Variável e struct vão com `&`; vetor
  já é endereço. Devolve **quantos itens** gravou.
- **`fread(endereco, tamanho, quantidade, arq)`** faz o caminho de volta e
  devolve quantos itens leu. Menos que o pedido indica fim do arquivo ou erro.
  Esse retorno vai no `while`.
- **`fseek(arq, deslocamento, origem)`** muda a posição. A origem é `SEEK_SET`
  (começo), `SEEK_CUR` (posição atual) ou `SEEK_END` (fim). O deslocamento é
  `long` e pode ser negativo.
- **`ftell(arq)`** devolve a posição atual em bytes e **`rewind(arq)`** volta
  ao byte 0. `fseek` até o fim seguido de `ftell` mede o arquivo.

No exemplo, o estoque tem três produtos de 32 bytes cada. Um `fwrite` grava
os três (96 bytes). Para ler o café, o programa pula 2 × 32 = 64 bytes desde o
começo e faz um `fread` de um registro:

{{ideia}}

O arquivo fica em `/tmp/estoque.bin` e é apagado no fim:

```c
#include <stdio.h>

typedef struct {
    char nome[20];
    int qtd;
    double preco;
} Produto;

int main(void) {
    const char *caminho = "/tmp/estoque.bin";
    Produto estoque[3] = {
        {"Arroz", 12, 25.90},
        {"Feijão", 7, 8.75},
        {"Café", 4, 18.50},
    };

    FILE *arq = fopen(caminho, "wb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    size_t gravados = fwrite(estoque, sizeof(Produto), 3, arq); // vetor: sem &
    fclose(arq);
    printf("Cada registro: %zu bytes\n", sizeof(Produto));
    printf("Gravados: %zu registros\n", gravados);

    arq = fopen(caminho, "rb");
    if (arq == NULL) {
        perror(caminho);
        return 1;
    }
    fseek(arq, 0, SEEK_END);                    // vai para o fim...
    printf("Arquivo: %ld bytes\n", ftell(arq)); // ...e pergunta a posição

    Produto p;
    fseek(arq, 2 * sizeof(Produto), SEEK_SET);  // byte 64: começo do registro 2
    if (fread(&p, sizeof(Produto), 1, arq) == 1) {
        printf("Registro 2: %s, %d un., R$ %.2f\n", p.nome, p.qtd, p.preco);
    }
    fclose(arq);
    remove(caminho);
    return 0;
}
// Saída:
// Cada registro: 32 bytes
// Gravados: 3 registros
// Arquivo: 96 bytes
// Registro 2: Café, 4 un., R$ 18.50
```

No fluxograma não há laço até o café: são dois `fseek` e um `fread`, com 3
registros ou 3 milhões:

{{fluxograma}}

Com os registros em ordem de código, dá para fazer **busca binária direto no
arquivo**: `fseek` no registro do meio, `fread`, compara e descarta metade.
São uns 20 `fread` para 1 milhão de registros, sem carregar o arquivo na RAM
(a busca binária é o assunto 0090).

> [!WARNING]
> `fwrite` copia bytes, não "dados". Se a struct tiver ponteiro (`char *nome`
> em vez de `char nome[20]`), o arquivo guarda o **endereço**, que não aponta
> para nada na próxima execução. Use vetores de tamanho fixo dentro da struct.
> E um `.bin` de um PC pode não ser lido igual em outra máquina: tamanho do
> `int`, alinhamento e ordem dos bytes mudam. Para trocar dados entre
> máquinas, prefira texto (CSV, JSON).

> [!TIP]
> **Por dentro do C:** o `fseek` não lê nada: só troca um número no `FILE`.
> Pular para o registro 2 custa o mesmo que pular para o registro 2 milhões.
> Aqui 20 + 4 + 8 dá exatamente 32 bytes, sem enchimento, porque o `double`
> já cai em endereço múltiplo de 8.

> [!NOTE]
> **Pergunta para você:** se `nome` fosse `char nome[21]`, quanto daria
> `sizeof(Produto)`? Lembre que o `int` gosta de começar em múltiplo de 4 e o
> `double` em múltiplo de 8. Responda e depois confira com um `printf`.

{{pratique}}
