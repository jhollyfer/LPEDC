#!/usr/bin/env bash
# Compila e roda (sem entrada) todos os exemplos, exercícios e respostas de um módulo.
#   ./conferir.sh 10-analise
# Mostra só o que deu warning, erro de compilação ou erro do sanitizer (sair com
# código diferente de 0 sozinho não conta: é o caso de quem pede argumentos).
# entrada vazia, então podem terminar cedo: isso não é falha.
RAIZ="$(cd "$(dirname "$0")/.." && pwd)"
mod="$1"; falhas=0
for f in "$RAIZ/$mod"/*/[AE][0-9][0-9][0-9].c "$RAIZ/_respostas/$mod"/E[0-9][0-9][0-9].c; do
  [ -f "$f" ] || continue
  grep -q "main" "$f" || continue   # resposta só em comentário
  saida=$(timeout 10 "$RAIZ/rodar" "$f" </dev/null 2>&1); cod=$?
  if grep -qE "warning:|error:|ERROR: AddressSanitizer|runtime error" <<<"$saida"; then
    echo "FALHOU ($cod): ${f#$RAIZ/}"; grep -m2 -E "warning:|error:|ERROR|runtime error" <<<"$saida" | sed 's/^/    /'; falhas=$((falhas+1))
  fi
done
echo "$mod: $falhas com problema"
