#!/usr/bin/env python3
"""Compara as fontes de texto (texto.html e modulo.html) de um módulo com o último
commit e reprova se a revisão de texto mexeu no que não pode mudar: blocos de
código (os que existiam continuam; trecho novo pode entrar), títulos "<h2>NNNN · ...</h2>"
e letras de gabarito. Também confere a forma do texto.html: conceito em texto corrido
(não lista de tópicos), com fonte, um WARNING, {{exemplo}}, {{ideia}} e
{{fluxograma}}, nessa ordem.
  python3 _gerador/conferir-texto.py 14-arvores [15-hash ...]
"""
import re, subprocess, sys, pathlib
from html import unescape

RAIZ = pathlib.Path(__file__).resolve().parent.parent

def partes(t):
    return {
        'blocos de código': re.findall(r'<pre><code(?: [^>]*)?>.*?</code></pre>', t, flags=re.S),
        'títulos de assunto': re.findall(r'<h2>\d{4} · .*?</h2>', t),
        'gabaritos': re.findall(r'<summary>Gabarito</summary>\s*(?:<[^>]+>\s*)*\(?([A-E])\b', t),
    }

def forma(t):
    """Problemas de forma de um texto.html novo."""
    erros = []
    marcas = re.findall(r'\{\{\w+\}\}', t)
    if marcas not in (['{{exemplo}}', '{{ideia}}', '{{fluxograma}}'],):
        erros.append(f'marcadores {marcas} (esperado exemplo, ideia, fluxograma)')
    conceito = t.split('{{exemplo}}')[0]
    if len(re.findall(r'<blockquote>\s*<p>\[!WARNING\]', conceito)) != 1:
        erros.append('o conceito precisa de exatamente um WARNING')
    if re.search(r'Por dentro do C|Pergunta para você|<p>\[!(TIP|NOTE)\]', t, flags=re.M):
        erros.append('sobrou TIP, NOTE, Por dentro do C ou Pergunta para você')
    # o conceito é explicação de livro: parágrafos corridos, não glossário
    sem_codigo = re.sub(r'<pre>.*?</pre>|<blockquote>.*?</blockquote>', '', conceito, flags=re.S)
    paragrafos = re.findall(r'^<p>', sem_codigo, flags=re.M)
    if len(paragrafos) < 4:
        erros.append(f'o conceito tem {len(paragrafos)} parágrafo(s) de texto corrido (mínimo 4)')
    sem_listas_numeradas = re.sub(r'<ol(?: [^>]*)?>.*?</ol>', '', sem_codigo, flags=re.S)
    topicos = len(re.findall(r'^<li><strong>', sem_listas_numeradas, flags=re.M))
    if topicos > 3:
        erros.append(f'o conceito virou lista de tópicos ({topicos} termos em negrito); explique em texto corrido')
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
    leitura = (base / 'modulo.html').read_text().split('<h2>Para ler mais</h2>')[-1]
    autores = [unescape(re.sub(r'<[^>]+>', '', item)) for item in re.findall(r'<li>(.*?)</li>', leitura, re.S)]
    for t in sorted(base.glob('*/texto.html')):
        for autor in sorted(set(CITA.findall(t.read_text()))):
            if not any(item.startswith((autor, autor.split()[0])) for item in autores):
                falhas += 1; print(f'{t.relative_to(RAIZ).as_posix()}: ({autor}, ...) não está no Para ler mais')
    for f in sorted(base.rglob('*.html')):
        rel = f.relative_to(RAIZ).as_posix()
        novo = f.read_text()
        if f.name == 'texto.html':
            for e in forma(novo):
                falhas += 1; print(f'{rel}: {e}')
        try:
            antes = subprocess.run(['git', 'show', f'{BASE}:{rel}'], cwd=RAIZ, capture_output=True, text=True, check=True).stdout
        except subprocess.CalledProcessError:
            continue
        a, d = partes(antes), partes(novo)
        for k in a:
            if k == 'blocos de código':
                sumiu = [b for b in a[k] if b not in d[k]]
                if sumiu:
                    falhas += 1; print(f'{rel}: {len(sumiu)} bloco(s) de código mudou ou sumiu')
            elif a[k] != d[k]:
                falhas += 1; print(f'{rel}: {k} mudou ({len(a[k])} -> {len(d[k])})')
print(f'{falhas} problema(s)')
sys.exit(1 if falhas else 0)
