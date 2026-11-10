// 0111 · DFS: busca em profundidade
// Exercício E665 · ★★★
//
// Os pacotes de um projeto são app 0, api 1, auth 2, db 3, log 4 e utils 5, e
// uma seta A -> B quer dizer "A importa B":
//
//   app -> api, app -> auth, api -> db, api -> log, auth -> db,
//   db -> utils, utils -> log, log -> auth
//
// Escreva uma DFS com TRÊS cores (branco, cinza, preto) que acha o ciclo e o
// mostra, reconstruído com pai[]: uma seta para um vértice CINZA fecha um
// ciclo. Rode com o grafo acima e sem a seta log -> auth.
//
//   Saída esperada:
//   Com log -> auth: ciclo db -> utils -> log -> auth -> db
//   Sem log -> auth: sem ciclo
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
