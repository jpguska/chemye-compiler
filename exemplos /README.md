# Casos de Teste - Compilador `.alch`

Este diretório contém uma suíte de arquivos de código-fonte escritos na linguagem customizada `.alch`. O objetivo destes testes é validar o comportamento, a robustez e as regras de derivação do compilador em diversos cenários práticos.

Os arquivos foram projetados para estressar diferentes etapas da compilação, desde o reconhecimento de tokens básicos e estruturas gramaticais até a validação da tabela de símbolos e captura de erros.

## 🗂️ Suíte de Validação

**Algoritmos e Lógica Clássica**
* `fibonacci.alch`: Teste de operações aritméticas e estruturas de repetição gerando a sequência de Fibonacci.
* `insertionSort.alch`: Algoritmo de ordenação focado em validar a manipulação de memória e acesso a índices de vetores dentro de laços aninhados.
* `maior3.alch`: Teste de operadores relacionais e lógica condicional para encontrar o maior entre três valores.

**Estruturas de Controle e Tipos de Dados**
* `forteste.alch`: Validação do fluxo do laço de repetição `for`.
* `elseteste.alch` e `teste_else.alch`: Testes de desvios condicionais, úteis para verificar a resolução de ambiguidades clássicas (como o *dangling else*).
* `vetorteste.alch`: Verifica a correta declaração, atribuição e dimensionamento de vetores na memória.

**Tratamento de Erros e Exceções**
* `erro_variavel_nao_declarada.alch`: Força um erro na análise semântica para garantir que a Tabela de Símbolos bloqueia o uso de identificadores não declarados no escopo.
* `erro_comentario_multilinha_nao_fechado.alch`: Força um erro léxico/sintático para testar o comportamento do compilador ao encontrar blocos de comentários sem fechamento válido.
