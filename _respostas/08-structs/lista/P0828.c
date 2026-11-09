// Lista · Módulo 08 · Tipos compostos
// Exercício P0828 · ★★★ · O cabeçalho do pacote em 32 bits

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    unsigned versao, tipo, tamanho, id;
} Cabecalho;

typedef struct {
    unsigned id : 16;
    unsigned tamanho : 8;
    unsigned tipo : 4;
    unsigned versao : 4;
} Compacto;

bool empacotar(const Cabecalho *c, uint32_t *saida) {
    if (c->versao > 0xF || c->tipo > 0xF || c->tamanho > 0xFF || c->id > 0xFFFF) {
        return false; // algum campo não cabe nos seus bits
    }
    *saida = ((uint32_t) c->versao << 28) | ((uint32_t) c->tipo << 24)
           | ((uint32_t) c->tamanho << 16) | (uint32_t) c->id;
    return true;
}

Cabecalho desempacotar(uint32_t x) {
    Cabecalho c;
    c.versao = (x >> 28) & 0xFu;
    c.tipo = (x >> 24) & 0xFu;
    c.tamanho = (x >> 16) & 0xFFu;
    c.id = x & 0xFFFFu;
    return c;
}

int main(void) {
    Cabecalho cabs[3] = {{2, 5, 64, 1027}, {15, 0, 255, 65535}, {1, 3, 300, 7}};

    for (int i = 0; i < 3; i++) {
        const Cabecalho *c = &cabs[i];
        uint32_t x;
        printf("{%u, %u, %u, %u} -> ", c->versao, c->tipo, c->tamanho, c->id);
        if (!empacotar(c, &x)) {
            printf("recusado: campo grande demais\n");
            continue;
        }
        Cabecalho d = desempacotar(x);
        bool igual = d.versao == c->versao && d.tipo == c->tipo && d.tamanho == c->tamanho
                     && d.id == c->id;
        printf("0x%08X -> {%u, %u, %u, %u} %s\n", (unsigned) x, d.versao, d.tipo,
               d.tamanho, d.id, igual ? "ok" : "DIFERENTE");
    }
    Compacto k = {.id = 1027, .tamanho = 64, .tipo = 5, .versao = 2};
    printf("Campos de bits: {%u, %u, %u, %u}\n", (unsigned) k.versao, (unsigned) k.tipo,
           (unsigned) k.tamanho, (unsigned) k.id);
    printf("sizeof(Cabecalho) = %zu, sizeof(Compacto) = %zu\n", sizeof(Cabecalho),
           sizeof(Compacto));
    return 0;
}
