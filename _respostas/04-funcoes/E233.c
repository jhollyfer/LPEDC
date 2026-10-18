// 0039 · Módulos: .h, .c e compilação separada
// Exercício E233 · ★★★
//
// Resposta:
// a) "2 gols em 1 partida".
// b) O main.c compila (o extern promete que gols existe), mas o ligador dá
//    "undefined reference to gols": a gols de placar.c é static, o nome não
//    sai daquele arquivo.
// c) O mesmo: compila, e o ligador não acha anotar, que é static.
// d) Agora partidas é definida duas vezes (uma em cada .c): o ligador dá
//    "multiple definition of partidas". A definição fica num lugar só; nos
//    outros, extern.
// e) Encapsulamento: ninguém fora de placar.c altera gols direto. Só dá para
//    mudar o placar por marcar_gol, e o módulo pode trocar a forma de guardar
//    os gols sem quebrar quem usa.
