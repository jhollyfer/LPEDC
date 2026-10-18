// 0002 · Variáveis
// Exercício E008 · ★☆☆
//
// Resposta:
// válidos: preco_kg, _total, Preco, nota1.
// inválidos: 2via (começa com dígito); valor-final (o - é o operador de
// subtração: o C lê "valor menos final"); float (palavra reservada); média
// (acento não vale em nome); qtd$ (o $ não é do padrão; o gcc aceita como
// extensão, mas o código deixa de ser portável); dia util (espaço).
// preco e Preco podem existir juntas e são variáveis diferentes: o C
// diferencia maiúsculas de minúsculas. _total é válido, mas nomes que começam
// com _ são usados pelo compilador e pela biblioteca: evite.
