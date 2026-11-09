# Decisões

**LPEDC** · escolhas difíceis de desfazer, com o porquê e o custo aceito

> Leia antes de decidir para não reabrir o que já foi resolvido. Decisão nova entra no fim e não
> se edita: a linha nova diz "substitui #N".

| # | Data | Tema | Decisão | Por quê | Alternativas descartadas | Custo aceito |
|---|---|---|---|---|---|---|
| 1 | 2026-11-09 | Um `.md` por módulo na raiz | todo o texto de um módulo (assuntos, exercícios, lista, questões) num `.md` na raiz; as pastas guardam só `.c` e `.svg` | o GitHub não renderiza markdown de vários MB; o maior módulo tem ~200 KB e abre | um `README.md` único (~4,6 MB, não renderiza); um `README.md` por pasta (o dono não quer markdown em subpasta) | 29 arquivos na raiz ao lado das 29 pastas |
| 2 | 2026-11-09 | Só a `main`, sem PR | commit e push direto na `main` | curso pessoal com um único dono; o dono pediu uma branch só | branch e PR por mudança, como no `maiyu-pattern` | sem revisão antes de entrar; a conferência de `TEST-PLAN.md` é a barreira |
| 3 | 2026-11-09 | `maiyu-pattern` adaptado | adota `AGENTS.md`, `docs/`, autor único, commits Conventional e humanizer; não copia `_doc-lib/`, `_standards/` nem as skills de TypeScript | o curso é C e markdown, sem backend nem frontend; a régua de TS só ocuparia espaço (~23 MB) | sync completo do `maiyu-pattern` | o `sync-to-project.mjs --check` acusaria falta; `ENV.md`, `SECURITY.md` e `USER-FLOWS.md` não existem aqui (sem variável, sem dado pessoal, e o caminho de estudo está no `README.md`) |
| 4 | 2026-11-09 | Histórico reescrito | os commits antigos passaram a ter Jhollyfer como autor e perderam as linhas `Co-Authored-By` e `Claude-Session`, com push forçado na `main` | regra de autor único do `maiyu-pattern`, pedida pelo dono | manter o histórico como estava | todo clone anterior precisa de `git fetch` e `git reset --hard origin/main` |
| 5 | 2026-11-09 | Cormen como referência de nomes | quando os livros divergem, vale a definição e o nome do Cormen, citando o nome alternativo | a bibliografia da prova começa por ele | Ziviani ou Deitel como base | o texto às vezes carrega dois nomes para a mesma coisa |
