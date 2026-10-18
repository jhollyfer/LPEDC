// 0116 · DFS: busca em profundidade
// Exercício E695 · ★★★
//
// O gerenciador de pacotes reclamou de dependência circular no seu projeto. Os pacotes são
// app 0, api 1, auth 2, db 3, log 4 e utils 5, e uma seta A -> B quer dizer
// "A importa B":
//
//   app -> api, app -> auth, api -> db, api -> log, auth -> db,
//   db -> utils, utils -> log, log -> auth
//
// Escreva uma DFS com TRÊS cores para achar o ciclo e mostrá-lo:
//
// - BRANCO: ainda não visitado;
// - CINZA: a chamada dele está aberta (ele está na pilha de chamadas);
// - PRETO: a chamada já terminou.
//
// Uma seta para um vértice CINZA fecha um ciclo. Guarde pai[] para
// reconstruir o ciclo. Rode duas vezes: com o grafo acima e sem a seta
// log -> auth.
//
//   Saída esperada:
//   Com log -> auth: ciclo db -> utils -> log -> auth -> db
//   Sem log -> auth: sem ciclo
//
// Dicas:
// 1. Use enum { BRANCO, CINZA, PRETO } (assunto 0068).
// 2. Por que não basta "visitado"? Sem log -> auth, a DFS termina db pelo
//    caminho app -> api -> db; depois, vindo de app -> auth, a seta
//    auth -> db encontra db já visitado. Isso não é ciclo: db está PRETO,
//    não CINZA.
// 3. Achou a seta u -> v com v CINZA? O ciclo é v, ..., u, v. Siga pai[] de
//    u até v, guardando num vetor, e imprima de trás para frente.
// 4. Resposta esperada: a saída acima (a DFS começa no app e visita os
//    vizinhos em ordem de índice).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
