// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0922 · ★★★ · O banquinho do bairro processa o dia

#include <stdio.h>

typedef struct {
    int numero;
    char titular[16];
    double saldo;
} Conta;

long acha(FILE *arq, int numero, Conta *c) {
    rewind(arq);
    long pos = 0;
    while (fread(c, sizeof *c, 1, arq) == 1) {
        if (c->numero == numero) {
            return pos;
        }
        pos++;
    }
    return -1;
}

void regrava(FILE *arq, long pos, const Conta *c) {
    fseek(arq, pos * (long) sizeof(Conta), SEEK_SET);
    fwrite(c, sizeof *c, 1, arq);
}

int main(void) {
    const char *caminho_contas = "/tmp/p0922_contas.bin";
    const char *caminho_dia = "/tmp/p0922_dia.txt";
    Conta iniciais[3] = {{101, "Ana", 500.00}, {102, "Beto", 120.00}, {103, "Caio", 0.00}};

    FILE *contas = fopen(caminho_contas, "wb");
    if (contas == NULL) {
        perror(caminho_contas);
        return 1;
    }
    fwrite(iniciais, sizeof(Conta), 3, contas);
    fclose(contas);

    FILE *op = fopen(caminho_dia, "w");
    if (op == NULL) {
        perror(caminho_dia);
        remove(caminho_contas);
        return 1;
    }
    fprintf(op, "D 103 250.00\nS 102 200.00\nS 101 80.50\nT 101 103 100.00\nS 104 10.00\n");
    fclose(op);

    contas = fopen(caminho_contas, "rb+");
    op = fopen(caminho_dia, "r");
    if (contas == NULL || op == NULL) {
        printf("Não abri os arquivos\n");
        if (contas != NULL) {
            fclose(contas);
        }
        if (op != NULL) {
            fclose(op);
        }
        return 1;
    }

    char tipo;
    int num;
    while (fscanf(op, " %c %d", &tipo, &num) == 2) {
        int destino = 0;
        double valor;
        if (tipo == 'T' && fscanf(op, "%d", &destino) != 1) {
            break;
        }
        if (fscanf(op, "%lf", &valor) != 1) {
            break;
        }
        if (tipo == 'T') {
            printf("T %d %d %.2f: ", num, destino, valor);
        } else {
            printf("%c %d %.2f: ", tipo, num, valor);
        }

        Conta a, b;
        long pa = acha(contas, num, &a);
        long pb = tipo == 'T' ? acha(contas, destino, &b) : 0;
        if (pa < 0 || pb < 0) {
            printf("conta inexistente\n");
        } else if (tipo == 'D') {
            a.saldo += valor;
            regrava(contas, pa, &a);
            printf("ok\n");
        } else if (a.saldo < valor) {
            printf("saldo insuficiente\n");
        } else {
            a.saldo -= valor;
            regrava(contas, pa, &a);
            if (tipo == 'T') {
                b.saldo += valor;
                regrava(contas, pb, &b);
            }
            printf("ok\n");
        }
    }
    fclose(op);

    rewind(contas);
    Conta c;
    while (fread(&c, sizeof c, 1, contas) == 1) {
        printf("%d %-6s R$ %7.2f\n", c.numero, c.titular, c.saldo);
    }
    fclose(contas);
    remove(caminho_contas);
    remove(caminho_dia);
    return 0;
}
