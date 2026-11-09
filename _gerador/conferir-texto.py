#!/usr/bin/env python3
"""Compara as fontes de texto (texto.md e modulo.md) de um módulo com o último
commit e reprova se a revisão de texto mexeu no que não pode mudar: blocos de
código, código inline, marcadores {{...}}, títulos "## NNNN · ...", callouts
obrigatórios e letras de gabarito.
  python3 _gerador/conferir-texto.py 14-arvores [15-hash ...]
"""
import re, subprocess, sys, pathlib

RAIZ = pathlib.Path(__file__).resolve().parent.parent

def partes(t):
    blocos = re.findall(r'^```.*?^```', t, flags=re.S | re.M)
    sem = re.sub(r'^```.*?^```', '', t, flags=re.S | re.M)
    return {
        'blocos de código': blocos,
        'código inline': sorted(re.findall(r'`[^`\n]+`', sem)),
        'marcadores {{}}': re.findall(r'\{\{\w+\}\}', t),
        'títulos de assunto': re.findall(r'^## \d{4} · .*$', t, flags=re.M),
        'callouts': re.findall(r'^> \[!(?:WARNING|TIP|NOTE|IMPORTANT)\]', t, flags=re.M),
        'Por dentro do C': [m for m in re.findall(r'\*\*Por dentro do C:?\*\*', t)],
        'Pergunta para você': re.findall(r'\*\*Pergunta para você:?\*\*', t),
        'gabaritos': re.findall(r'<summary>Gabarito</summary>\s*\n*\s*\**\(?([A-E])\)?', t),
    }

falhas = 0
for mod in sys.argv[1:]:
    base = RAIZ / '_gerador' / 'modulos' / mod
    for f in sorted(base.rglob('*.md')):
        rel = f.relative_to(RAIZ).as_posix()
        try:
            antes = subprocess.run(['git', 'show', f'HEAD:{rel}'], cwd=RAIZ, capture_output=True, text=True, check=True).stdout
        except subprocess.CalledProcessError:
            continue
        a, d = partes(antes), partes(f.read_text())
        for k in a:
            if k == 'código inline':
                perdidos = [x for x in a[k] if x not in d[k]]
                if perdidos:
                    falhas += 1; print(f'{rel}: {k} sumiu: {perdidos[:3]}')
            elif a[k] != d[k]:
                falhas += 1; print(f'{rel}: {k} mudou ({len(a[k])} -> {len(d[k])})')
print(f'{falhas} problema(s)')
sys.exit(1 if falhas else 0)
