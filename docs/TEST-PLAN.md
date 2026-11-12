# Plano de testes

**LPEDC** · o que se confere antes de dar uma mudança como pronta

## 1. Código C

| O quê | Como | Passa quando |
|---|---|---|
| um arquivo | `gcc ... -o A013 && ./A013` com as flags de estudo (C17, `-Wall -Wextra -pedantic`, ASan e UBSan) | compila sem aviso, roda sem erro do sanitizer, e a saída bate com o comentário |
| arquivo que lê do teclado | `gcc ... -o A013 && printf '25\n' \| ./A013` | idem |
| vazamento difícil | `valgrind ./A013` (compilado com `-g`) | sem bloco perdido |

## 2. Módulo inteiro

`_gerador/conferir.sh <modulo>` compila e roda os exemplos, os exercícios, a lista e as respostas
do módulo. Exercício "conserte o bug" fica de fora (o esqueleto vem quebrado de propósito; a
resposta é conferida). Passa com `<modulo>: 0 com problema`.

## 3. Texto

| O quê | Como | Passa quando |
|---|---|---|
| revisão não mexeu no que não pode | `python3 _gerador/conferir-texto.py <modulo> ...` (compara com o `HEAD`: blocos de código, código inline, `{{...}}`, títulos de assunto, callouts, gabaritos) | `0 problema(s)` |
| humanizer | skill `humanizer-pt` e o script `auditoria_pos_edicao.py antes.txt depois.txt` | valores, força da norma, certeza e corte OK; o BLOQUEIO em "vestígios de ferramenta" é falso positivo se o arquivo do `HEAD` contra ele mesmo der o mesmo |
| `.md` gerado | o gerador do módulo (`ARCHITECTURE.md` §1) | sem erro, e o `git diff` do `.md` mostra só o que mudou na fonte |
| links | links e imagens relativos dos `.md` da raiz apontam para arquivo que existe | nenhum quebrado |
| desenho | `ver.mjs` e abrir o PNG (`DESIGN.md`) | sem sobreposição, texto cortado ou seta solta (`DESIGN.md`) |

## 3.1 Quiz das provas

| O quê | Como | Passa quando |
|---|---|---|
| dados do quiz | `cd _gerador && node quiz.mjs --check` (letra igual ao `PROVAS.md`, porquê de toda alternativa, dica no formato com 2 a 4 conceitos, cada um com definição e `Ex.:`, assunto `[NNNN]` que existe, cerca de código na própria linha) | `0 erros` |
| quiz no navegador | `cd _gerador && node quiz-navegador.mjs` (as 210 questões a 390px e a 1440px) | `0 com problema, 0 erros de script` nas duas larguras |

## 4. Definição de pronto

- [ ] `conferir.sh` do módulo tocado com 0 problema, rodado no `HEAD` atual.
- [ ] `conferir-texto.py` com 0 problema quando o texto mudou.
- [ ] `.md` do módulo gerado de novo no mesmo commit da fonte.
- [ ] Gabarito de questão nova conferido rodando o código.
- [ ] `docs/` atualizado no mesmo commit (`AGENTS.md`, "Ao terminar").
