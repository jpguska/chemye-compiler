# Chemye++ — Compilador

Projeto de **CCH** da disciplina de **Compiladores**.

Compilador da linguagem **Chemye++**, uma linguagem imperativa de temática alquímica.
É necessário estar junto da máquina virtual **Raposeitor**, responsável por executar o código intermediário (`.rap`) gerado pelo compilador.

---

## Índice

- [Sobre o projeto](#sobre-o-projeto)
- [Como compilar e rodar](#como-compilar-e-rodar)
- [A linguagem Chemye++](#a-linguagem-chemye)
  - [Comentários](#comentários)
  - [Blocos e delimitadores](#blocos-e-delimitadores)
  - [Tipos e declarações](#tipos-e-declarações)
  - [Atribuição](#atribuição)
  - [Operadores](#operadores)
  - [Entrada e saída](#entrada-e-saída)
  - [Estruturas condicionais](#estruturas-condicionais)
  - [Laços](#laços)
  - [Retorno](#retorno)
- [A máquina virtual Raposeitor](#a-máquina-virtual-raposeitor)
- [Exemplo completo](#exemplo-completo)

---

## Sobre o projeto

O compilador é construído com as ferramentas clássicas da disciplina:

- **Flex (`flex++`)** — análise léxica (`lexan.l`)
- **Bison** — análise sintática e geração de código intermediário (`synan.y`)
- **C++17** — linguagem hospedeira do compilador e do interpretador

O fluxo de execução é:

```
código-fonte (.alch)  →  [compilador]  →  assembly.rap  →  [raposeitor]  →  saída
```

O compilador lê o programa-fonte e gera código de três endereços para uma máquina virtual de registradores (Raposeitor), que é executado em seguida pelo interpretador.

---

## Como compilar e rodar

O projeto inclui um `Makefile` que cuida de todas as etapas.

### Pré-requisitos

- `g++` com suporte a C++17
- `flex` (com o wrapper `flex++`)
- `bison`
- `make`

### Compilando

```bash
make
```

Isso gera dois executáveis:

- `compilador` — lê o código-fonte da entrada padrão e escreve o assembly na saída padrão
- `raposeitor` — interpreta um arquivo `.rap`

### Rodando um programa

Maneira manual, em duas etapas:

```bash
./compilador < meu_programa.alch > assembly.rap
./raposeitor assembly.rap
```

Ou usando o atalho do Makefile:

```bash
make run TESTFILE=meu_programa.alch
```

### Limpando os artefatos

```bash
make clean
```

---

## A linguagem Chemye++

Chemye++ é uma linguagem imperativa de tipagem estática inspirada em C, mas com palavras-chave em latim e uma sintaxe com um toque de "alquimia".

### Comentários

Existem duas formas de comentar código:

```
Arcanum: isto é um comentário de uma linha
```

```
Arcanum[:
   isto é um comentário
   de várias linhas
:]
```

### Blocos e delimitadores

Chemye++ não usa chaves `{}` nem parênteses `()` convencionais. No lugar deles:

| Símbolo Chemye++ | Equivalente em C | Função |
|------------------|------------------|--------|
| `[:` ... `:]`    | `{` ... `}`      | Bloco de comandos |
| `\|:` ... `:\|`    | `(` ... `)`      | Expressão / agrupamento |
| `\|:\|`            | `()`             | Parênteses vazios |
| `.`              | `;`              | Fim de comando (ponto final) |
| `,`              | `,`              | Separador de argumentos |
| `[` ... `]`      | `[` ... `]`      | Acesso/declaração de vetor |

### Tipos e declarações

Tipos disponíveis: `inteiro`, `float`, `char` (o suporte completo é apenas para `inteiro`, conforme a máquina virtual Raposeitor).

```
inteiro x.
inteiro vetor[10].
```

### Atribuição

A atribuição usa a palavra-chave `ACCIPIT` (do latim: "receba"):

```
x ACCIPIT 5 + 3.
vetor[2] ACCIPIT x * 2.
```

Também é possível agrupar a expressão com `|: :|`:

```
x ACCIPIT |: 5 + 3 :|.
```

### Operadores

**Aritméticos:** `+`, `-`, `*`, `/`, `%`

**Relacionais:** `<`, `>`, `<=`, `>=`, `==`, `!=`

**Lógicos:**

| Chemye++ | Significado |
|----------|-------------|
| `ET`     | E lógico (`&&`) |
| `VEL`    | OU lógico (`\|\|`) |
| `NON`    | Negação (`!`) |

**Incremento/Decremento:** `++` e `--` (usados nos laços `CIRCA`).

### Entrada e saída

A saída se faz com **`PRONUNTIARE`** ("anunciar"):

```
PRONUNTIARE |: "Olá, mundo!" :|.
PRONUNTIARE |: "valor: %d", x :|.
PRONUNTIARE |: "soma: %d, prod: %d", a + b, a * b :|.
```

> ⚠️ O argumento de `PRONUNTIARE` é sempre passado como um **template** entre `|:` e `:|`. A string pode conter placeholders `%d`, que são preenchidos pelas expressões seguintes.

A entrada se faz com **`INSCULPIRE`** ("gravar / inscrever"):

```
INSCULPIRE |: x :|.
INSCULPIRE |: vetor[i] :|.
```

### Estruturas condicionais

`SIVERITAS` significa "se for verdade" e `ALITER` significa "do contrário":

```
SIVERITAS |: x > 0 :| [:
    PRONUNTIARE |: "positivo" :|.
:]
ALITER [:
    PRONUNTIARE |: "não positivo" :|.
:]
```

O bloco `ALITER` é opcional.

### Laços

Existem duas formas. **`ITERARE`** ("iterar") é o equivalente de `while`:

```
ITERARE |: x < 10 :| [:
    x ACCIPIT x + 1.
:]
```

**`CIRCA`** ("ao redor de") é o equivalente de `for`, com inicialização, condição e incremento:

```
CIRCA |: i ACCIPIT 0. i < 10. i++ :| [:
    PRONUNTIARE |: "%d ", i :|.
:]
```

O incremento aceita apenas `++` ou `--` aplicados a uma variável.

### Retorno

`REVERSIO` ("retorno"):

```
REVERSIO x + 1.
```

O valor é armazenado em `%r0` na máquina virtual.

---

## A máquina virtual Raposeitor

O compilador não gera código de máquina nativo — ele emite um **assembly de três endereços** para uma máquina virtual de registradores chamada **Raposeitor**, definida em `raposeitor.cpp`.

### Modelo de execução

- **2048 registradores** de variáveis: `%r0`, `%r1`, ..., `%r2047`
- **2048 registradores** temporários: `%t0`, `%t1`, ..., `%t2047`
- Memória de vetores reside no banco `%r` com base + deslocamento

### Principais instruções

| Instrução | Significado |
|-----------|-------------|
| `mov dest, src` | Move valor |
| `add/sub/mult/div/mod dest, a, b` | Aritmética |
| `less/greater/lesseq/greatereq/equal/diff dest, a, b` | Comparações (resultado 0 ou 1) |
| `and/or dest, a, b`, `not dest, a` | Lógica booleana |
| `read dest` | Lê um inteiro do `stdin` |
| `printf "texto"` | Imprime literal (com suporte a `\n`) |
| `printv valor` | Imprime valor inteiro |
| `label Rn` | Marca posição para saltos |
| `jump Rn` | Salto incondicional |
| `jt val, Rn` / `jf val, Rn` | Salto se verdadeiro / se falso |
| `load dest, desl(base)` | Lê posição de vetor |
| `store val, desl(base)` | Escreve em posição de vetor |
| `nop` | Sem operação |

O Raposeitor lê o arquivo `.rap` linha a linha, monta uma lista de instruções e executa de modo sequencial, com saltos resolvidos por busca linear de `label`.

---

## Exemplo completo

Um programa que lê 10 números e imprime a soma:

```
Arcanum: soma de 10 numeros lidos

inteiro i.
inteiro n.
inteiro soma.

soma ACCIPIT 0.

CIRCA |: i ACCIPIT 0. i < 10. i++ :| [:
    INSCULPIRE |: n :|.
    soma ACCIPIT soma + n.
:]

PRONUNTIARE |: "soma = %d", soma :|.
PRONUNTIARE |: "\n" :|.
```

Para executar:

```bash
make
./compilador < soma.alch > assembly.rap
./raposeitor assembly.rap
```

---

## Estrutura do repositório

```
.
├── lexan.l           # Analisador léxico (Flex)
├── synan.y           # Analisador sintático + geração de código (Bison)
├── raposeitor.cpp    # Máquina virtual / interpretador
├── Makefile          # Script de build
└── README.md         # Este arquivo
```

---

## Autoria

Projeto desenvolvido para a disciplina de **Compiladores** por João Guska, Luiz Nagatani e Lucas Zanchet.
