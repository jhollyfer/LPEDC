## 0068 · Arquivos binários

- **Arquivo binário**: grava os bytes **exatamente como estão na memória**, sem
  converter em texto. Um `int` ocupa sempre 4 bytes (BACKES, 2013, cap. 12).
- **Registro de tamanho fixo**: o registro `i` começa no byte
  `i * sizeof(registro)`, e dá para ir direto a ele
  (DEITEL; DEITEL, 2011, cap. 11).
- **Modo com `b`**: `"wb"`, `"rb"`, `"ab"`, `"rb+"`. No Linux não muda nada; no
  Windows, sem ele, `\n` vira `\r\n` e estraga os bytes (BACKES, 2013, cap. 12).
- **`fwrite(endereco, tamanho, quantidade, arq)`** e **`fread`**: copiam
  `tamanho * quantidade` bytes e devolvem **quantos itens** processaram. Menos
  que o pedido indica fim ou erro (BACKES, 2013, cap. 12).
- **`fseek(arq, deslocamento, origem)`**: muda a posição a partir de `SEEK_SET`
  (começo), `SEEK_CUR` (atual) ou `SEEK_END` (fim). Não lê nada: pular para o
  registro 2 custa o mesmo que para o 2 milhões (DEITEL; DEITEL, 2011, cap. 11).
- **`ftell`** devolve a posição em bytes e **`rewind`** volta ao byte 0.
  `fseek` até o fim e `ftell` medem o arquivo (BACKES, 2013, cap. 12).
- **Busca binária no arquivo**: com registros em ordem, uns 20 `fread` acham
  um em 1 milhão, sem carregar tudo na RAM (assunto 0090) (ZIVIANI, 2010).

| | texto (`fprintf`) | binário (`fwrite`) |
| --- | --- | --- |
| o `int` 12345678 | 8 bytes: `'1' '2' ... '8'` | 4 bytes: `4E 61 BC 00` |
| abre no editor? | sim | vira lixo na tela |
| converte na ida e na volta? | sim (mais lento) | não, só copia bytes |
| acesso direto ao registro `i`? | não | sim, com `fseek` |
| lê em outra máquina? | sim | só se `int`, alinhamento e ordem dos bytes forem iguais |

> [!WARNING]
> `fwrite` copia bytes, não dados. Struct com ponteiro (`char *nome`) grava o
> **endereço**, que não vale na próxima execução: use `char nome[20]`. E um
> `.bin` pode não ser lido igual em outra máquina; para trocar dados, use texto.

{{exemplo}}

O estoque do mercadinho tem três produtos de 32 bytes cada. Um `fwrite` grava
os três (96 bytes). Para ler o café, o programa pula 2 × 32 = 64 bytes e faz um
`fread` de um registro:

{{ideia}}

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

Não há laço até o café: são dois `fseek` e um `fread`, com 3 registros ou 3
milhões:

{{fluxograma}}
