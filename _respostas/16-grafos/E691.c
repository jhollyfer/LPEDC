// 0116 · DFS: busca em profundidade
// Exercício E691 · ★☆☆
//
// Resposta:
// a) Saída da DFS:
//      Hall
//        Praça
//          Cinema
//          Loja
//            Banco
//              Saída
//    Do Hall a DFS desce para a Praça (índice 2 < 4). Da Praça desce para o
//    Cinema, que é beco sem saída: volta para a Praça, que ainda tem a Loja.
//    Da Loja chega no Banco (nível 3) e dele na Saída (nível 4). Quando volta
//    ao Hall, o Banco já foi visitado.
// b) BFS a partir do Hall: Hall, Praça, Banco, Cinema, Loja, Saída. Na BFS o
//    Banco é visitado em 3º (distância 1); na DFS, em 5º.
