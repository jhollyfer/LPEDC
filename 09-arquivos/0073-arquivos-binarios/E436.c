// 0073 · Arquivos binários
// Exercício E436 · ★★☆
//
// Escreva a função
//
//   long contar_registros(const char *caminho, size_t tamanho_registro);
//
// que descobre quantos registros um arquivo binário tem SEM ler nenhum
// deles: só olhando o tamanho do arquivo. Se não conseguir abrir, devolve -1.
//
// No main, grave em /tmp/notas.bin as notas de 7 alunos num vetor de
// struct { int matricula; float nota; } (os valores são livres), feche, e
// mostre:
//
//   Tamanho do registro: 8 bytes
//   Registros em /tmp/notas.bin: 7
//   Registros em /tmp/nao-existe.bin: -1
//
// Dicas:
// 1. fseek(arq, 0, SEEK_END) e depois ftell(arq) dão o tamanho em bytes.
// 2. Registros = tamanho / tamanho_registro.
// 3. sizeof de int + float = 4 + 4 = 8 bytes, sem sobra de alinhamento.
// 4. Resposta esperada: 8 bytes, 7 registros (56 / 8) e -1 para o arquivo
//    que não existe.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
