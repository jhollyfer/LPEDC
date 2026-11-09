// Lista · Módulo 09 · Arquivos e linha de comando
// Exercício P0925 · ★★★ · Ordenar a fila da vacina dentro do arquivo
//
// O posto de saúde tem a lista de espera da vacina num arquivo binário, e a
// regra é: mais velho primeiro. O arquivo pode ser grande demais para a
// memória, então ordene-o NO DISCO, com a ordenação por seleção: para cada
// posição i, procure (lendo do arquivo) o paciente mais velho entre i e o
// fim e troque-o com o da posição i. Nunca guarde mais que 3 registros na
// memória ao mesmo tempo, e conte quantos fread e quantos fwrite fez.
//
// Grave em /tmp/p0925_fila.bin: Ana 34, Beto 71, Ceci 18, Davi 65, Eva 80,
// Fabio 42. Ordene, liste e apague o arquivo. Só faça a troca (2 fwrite)
// quando o mais velho não estiver já na posição i.
//
//   Saída esperada:
//   1. Eva    80 anos
//   2. Beto   71 anos
//   3. Davi   65 anos
//   4. Fabio  42 anos
//   5. Ana    34 anos
//   6. Ceci   18 anos
//   Leituras: 20, escritas: 6
//
// Dicas:
// 1. Na passada i, leia o registro i (ele é o "mais velho até agora") e
//    depois cada j de i + 1 a n - 1. São 1 + (n - 1 - i) leituras.
// 2. Com n = 6 há 5 passadas: 6 + 5 + 4 + 3 + 2 = 20 leituras. A seleção
//    sempre lê a mesma quantidade, esteja o arquivo como estiver: Θ(n²).
// 3. Só 3 passadas precisam trocar (i = 0, 2 e 3): 6 escritas.
// 4. Resposta esperada: a saída acima. Não conte as leituras da listagem.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

typedef struct {
    char nome[12];
    int idade;
} Paciente;

int main(void) {

    return 0;
}
