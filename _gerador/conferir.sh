#!/usr/bin/env bash
# Compila e roda (sem entrada) a lista prática e as respostas de um módulo.
#   ./conferir.sh 10        (número do módulo, 2 dígitos)
# Mostra só o que deu warning, erro de compilação ou erro do sanitizer.
RAIZ="$(cd "$(dirname "$0")/.." && pwd)"; mod="$1"; falhas=0; cd "$RAIZ"
for f in material/P${mod}[0-9][0-9].c _respostas/${mod}-*/E[0-9]*.c _respostas/${mod}-*/lista/P[0-9]*.c; do
  [ -f "$f" ] && grep -q "main" "$f" || continue
  saida=$(timeout 10 "$RAIZ/rodar" "$f" </dev/null 2>&1)
  if grep -qE "warning:|error:|ERROR: (Address|Leak)Sanitizer|runtime error" <<<"$saida"; then
    echo "FALHOU: $f"; grep -m2 -E "warning:|error:|ERROR|runtime error" <<<"$saida" | sed 's/^/    /'; falhas=$((falhas+1))
  fi
done
echo "$mod: $falhas com problema"
