#!/usr/bin/env python3
"""Compara as fontes de texto (texto.md e modulo.md) de um módulo com o último
commit e reprova se a revisão de texto mexeu no que não pode mudar: blocos de
código, títulos "## NNNN · ..." e letras de gabarito. Também confere a forma do
texto.md: conceito, um WARNING, {{exemplo}}, {{ideia}} e {{fluxograma}}, nessa ordem.
  python3 _gerador/conferir-texto.py 14-arvores [15-hash ...]
"""
import re, subprocess, sys, pathlib

RAIZ = pathlib.Path(__file__).resolve().parent.parent

def partes(t):
    return {
        'blocos de código': re.findall(r'^```.*?^```', t, flags=re.S | re.M),
        'títulos de assunto': re.findall(r'^## \d{4} · .*$', t, flags=re.M),
        'gabaritos': re.findall(r'<summary>Gabarito</summary>\s*\n*\s*\**\(?([A-E])\)?', t),
    }

def forma(t):
    """Problemas de forma de um texto.md novo."""
    erros = []
    marcas = re.findall(r'\{\{\w+\}\}', t)
    if marcas not in (['{{exemplo}}', '{{ideia}}', '{{fluxograma}}'],):
        erros.append(f'marcadores {marcas} (esperado exemplo, ideia, fluxograma)')
    conceito = t.split('{{exemplo}}')[0]
    if len(re.findall(r'^> \[!WARNING\]', conceito, flags=re.M)) != 1:
        erros.append('o conceito precisa de exatamente um WARNING')
    if re.search(r'Por dentro do C|Pergunta para você|^> \[!(TIP|NOTE)\]', t, flags=re.M):
        erros.append('sobrou TIP, NOTE, Por dentro do C ou Pergunta para você')
    if not re.search(r'\([A-ZÁÉÍÓÚ][A-ZÁÉÍÓÚ/.\- ]+(; [A-ZÁÉÍÓÚ][A-ZÁÉÍÓÚ/.\- ]+)*( et al\.)?, (\d{4}|s\.d\.)', conceito):
        erros.append('o conceito não cita nenhuma fonte (AUTOR, ano)')
    return erros

# compara com este commit (padrão: HEAD); CONFERIR_BASE=5ef8041 compara com o curso antigo
import os
BASE = os.environ.get('CONFERIR_BASE', 'HEAD')
CITA = re.compile(r'\(([A-ZÁÉÍÓÚ][A-ZÁÉÍÓÚ/.\- ]+)(?:;[^,()]*)?(?: et al\.)?, (?:\d{4}|s\.d\.)')
falhas = 0
for mod in sys.argv[1:]:
    base = RAIZ / '_gerador' / 'modulos' / mod
    # toda fonte citada nos conceitos tem a obra no "Para ler mais" do módulo
    leitura = (base / 'modulo.md').read_text().split('## Para ler mais')[-1]
    for t in sorted(base.glob('*/texto.md')):
        for autor in sorted(set(CITA.findall(t.read_text()))):
            if f'- {autor}' not in leitura and f'- {autor.split()[0]}' not in leitura:
                falhas += 1; print(f'{t.relative_to(RAIZ).as_posix()}: ({autor}, ...) não está no Para ler mais')
    for f in sorted(base.rglob('*.md')):
        rel = f.relative_to(RAIZ).as_posix()
        try:
            antes = subprocess.run(['git', 'show', f'{BASE}:{rel}'], cwd=RAIZ, capture_output=True, text=True, check=True).stdout
        except subprocess.CalledProcessError:
            continue
        novo = f.read_text()
        a, d = partes(antes), partes(novo)
        for k in a:
            if a[k] != d[k]:
                falhas += 1; print(f'{rel}: {k} mudou ({len(a[k])} -> {len(d[k])})')
        if f.name == 'texto.md':
            for e in forma(novo):
                falhas += 1; print(f'{rel}: {e}')
print(f'{falhas} problema(s)')
sys.exit(1 if falhas else 0)
