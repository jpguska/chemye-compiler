%{
/* synan.y - Parser final para Chemye++ gerador Raposeitor
 *
 * Compatível com lexan.l (estilo original)
 * Aceita apenas as formas de PRINTF:
 *  - PRONUNTIARE |:"texto":|.
 *  - PRONUNTIARE |:"%d, ", expr [, expr ...] :|.
 *
 * Erros:
 *  - Erro lexico -> produzido no lexer (lexan.l)
 *  - Erro sintatico -> yyerror()
 *  - Erro semantico -> sem_erro()
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include <FlexLexer.h>
yyFlexLexer lexer;
int yylex() { return lexer.yylex(); }

void yyerror(const char *s);

/* Tabela de simbolos */
struct simbolo {
    std::string id;
    int end;
};
std::vector<simbolo> tabsimb;
int auxEnd = 0;

/* Contadores */
int T = 0;  /* temporários %t */
int S = 0;  /* labels R... */

/* Pilhas para rótulos usadas nas ações mid-rule reescritas */
std::stack<int> lbl_stack;
/* Pilha para armazenar o índice %t resultante de reduções de 'condicoes' */
std::stack<int> val_stack;
/* Pilhas específicas para laços (loop / exit) */
std::stack<int> loop_stack;
std::stack<int> exit_stack;
  
/* Funções utilitárias */
int getend(const std::string &id) {
    for (auto &s : tabsimb)
        if (s.id == id) return s.end;
    return -1;
}

void sem_erro(const std::string &msg) {
    std::cerr << "Erro semantico: " << msg << std::endl;
    exit(1);
}

%}

/* tornar erros de parse mais verbosos */
%define parse.error verbose

/* ------------------------ TIPOS ------------------------ */
%union {
      int int_val;
      std::string* str_val;
}

/* tokens com valor */
%token <str_val> ID
%token <str_val> STRING
%token <int_val> NUM

/* operadores e símbolos */
%token MAIS MENOS MULT DIV MOD
%token MENOR MAIOR MENORIGUAL MAIORIGUAL
%token IGUAL DIFERENTE
%token MAISMAIS MENOSMENOS

%token LCHAVES RCHAVES
%token LCOLCHETES RCOLCHETES
%token PEV VIRGULA DOISPONTOS
%token ATRIB

%token IF ELSE
%token FOR WHILE
%token INT FLOAT CHAR
%token PRINTF SCANF
%token RETURN
%token DECLARACAO
%token AND OR NOT

/* tokens de template */
%token LPAR_EXPR RPAR_EXPR
%token EMPTY_TEMPLATE

/* não-terminais */
%type <int_val> expr termo fator condicoes condicao cremento_for

%%

programa:
    codigos
    ;

codigos:
      /* vazio */
    | codigos codigo
    ;

codigo:
      declara
    | atrib
    | imprime
    | ler
    | condicional
    | laco
    | retorno
    ;

/* ---------------- DECLARAÇÃO ---------------- */

declara:
      INT ID PEV {
            if (getend(*$2) != -1) sem_erro("variavel redeclarada: " + *$2);
            tabsimb.push_back({ *$2, auxEnd++ });
            delete $2;
      }
    | INT ID LCOLCHETES NUM RCOLCHETES PEV {
            if (getend(*$2) != -1) sem_erro("variavel redeclarada: " + *$2);
            tabsimb.push_back({ *$2, auxEnd });
            auxEnd += $4;
            delete $2;
      }
    ;

/* ---------------- ATRIBUIÇÃO ---------------- */

atrib:
      ID ATRIB expr PEV {
            int e = getend(*$1);
            if (e == -1) sem_erro("variavel nao declarada: " + *$1);

            std::cout << "mov %r" << e << ", %t" << $3 << std::endl;
            delete $1;
      }

    /* SUPORTE A TEMPLATE EM ATRIBUIÇÃO */
    | ID ATRIB LPAR_EXPR expr RPAR_EXPR PEV {
            int e = getend(*$1);
            if (e == -1) sem_erro("variavel nao declarada: " + *$1);

            std::cout << "mov %r" << e << ", %t" << $4 << std::endl;
            delete $1;
      }

    | ID LCOLCHETES expr RCOLCHETES ATRIB expr PEV {
            int e = getend(*$1);
            if (e == -1) sem_erro("variavel nao declarada: " + *$1);

            std::cout << "store %t" << $6 << ", %t" << $3
                      << "(" << e << ")" << std::endl;

            delete $1;
      }

    /* TEMPLATE EM ATRIBUIÇÃO PARA VETOR */
    | ID LCOLCHETES expr RCOLCHETES ATRIB LPAR_EXPR expr RPAR_EXPR PEV {
            int e = getend(*$1);
            if (e == -1) sem_erro("variavel nao declarada: " + *$1);

            std::cout << "store %t" << $7 << ", %t" << $3
                      << "(" << e << ")" << std::endl;

            delete $1;
      }
    ;

/* ---------------- EXPRESSÕES ---------------- */

expr:
      expr MAIS termo {
            std::cout << "add %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | expr MENOS termo {
            std::cout << "sub %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | termo { $$ = $1; }
    ;

termo:
      termo MULT fator {
            std::cout << "mult %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | termo DIV fator {
            std::cout << "div %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | termo MOD fator {
            std::cout << "mod %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | fator { $$ = $1; }
    ;

fator:
      ID {
            int e = getend(*$1);
            if (e == -1) sem_erro("variavel nao declarada: " + *$1);

            std::cout << "mov %t" << T << ", %r" << e << std::endl;
            $$ = T++;
            delete $1;
      }

    | NUM {
            std::cout << "mov %t" << T << ", " << $1 << std::endl;
            $$ = T++;
      }

    /* SUPORTE A TEMPLATE EM EXPRESSÕES */
    | LPAR_EXPR expr RPAR_EXPR {
            /* apenas retorna o valor da expressao interna */
            $$ = $2;
      }

    | ID LCOLCHETES expr RCOLCHETES {
            int e = getend(*$1);
            if (e == -1) sem_erro("variavel nao declarada: " + *$1);

            std::cout << "load %t" << T << ", %t" << $3
                      << "(" << e << ")" << std::endl;

            $$ = T++;
            delete $1;
      }
    ;

/* ---------------- CONDIÇÕES ---------------- */

condicoes:
      condicao { $$ = $1; val_stack.push($$); }
    | condicao OR condicoes {
            std::cout << "or %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
            val_stack.push($$);
      }
    | condicao AND condicoes {
            std::cout << "and %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
            val_stack.push($$);
      }
    | NOT condicoes {
            std::cout << "not %t" << T << ", %t" << $2 << std::endl;
            $$ = T++;
            val_stack.push($$);
      }
    ;

condicao:
      expr IGUAL expr {
            std::cout << "equal %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | expr DIFERENTE expr {
            std::cout << "diff %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | expr MAIORIGUAL expr {
            std::cout << "greatereq %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | expr MENORIGUAL expr {
            std::cout << "lesseq %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | expr MAIOR expr {
            std::cout << "greater %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    | expr MENOR expr {
            std::cout << "less %t" << T << ", %t" << $1 << ", %t" << $3 << std::endl;
            $$ = T++;
      }
    ;

/* ---------------- INCREMENTO usado no for ---------------- */

cremento_for:
      MAISMAIS { $$ = 1; }
    | MENOSMENOS { $$ = 2; }
    ;

/* ---------------- IMPRESSÃO (APENAS FORMAS 2 e 3: TEMPLATE) ---------------- */

/* arglist: gera printv para cada expr (executa ação no parse) */
arglist:
      expr {
            std::cout << "printv %t" << $1 << std::endl;
      }
    | expr VIRGULA arglist {
            std::cout << "printv %t" << $1 << std::endl;
      }
    ;
    
/* imprime: somente via TEMPLATE |: ... :| */
imprime:
      /* caso 2: somente string no template */
      PRINTF LPAR_EXPR STRING RPAR_EXPR PEV {
            std::cout << "printf \"" << *$3 << "\"" << std::endl;
            delete $3;
      }

    /* caso 3: string + lista de expressões no template
       Remover os placeholders "%d" da string; também remover '%' sobrando
       e garantir um espaço separador antes do printv. */
    | PRINTF LPAR_EXPR STRING VIRGULA arglist RPAR_EXPR PEV {
            std::string s = *$3;
            size_t pos;
            while ((pos = s.find("%d")) != std::string::npos) s.erase(pos, 2);
            while ((pos = s.find('%')) != std::string::npos) s.erase(pos, 1);
            if (s.empty()) {
                /* emit an empty printf so the runtime doesn't print a stray '%' */
                std::cout << "printf \"\"" << std::endl;
            } else {
                if (s.back() != ' ') s.push_back(' ');
                std::cout << "printf \"" << s << "\"" << std::endl;
            }
            delete $3;
      }
    ;

/* ---------------- LEITURA ---------------- */

ler:
      SCANF LPAR_EXPR ID RPAR_EXPR PEV {
            int e = getend(*$3);
            if (e == -1) sem_erro("variavel nao declarada: " + *$3);
            std::cout << "read %r" << e << std::endl;
            delete $3;
      }
    | SCANF LPAR_EXPR ID LCOLCHETES expr RCOLCHETES RPAR_EXPR PEV {
            int e = getend(*$3);
            if (e == -1) sem_erro("variavel nao declarada: " + *$3);
            std::cout << "read %t" << T << std::endl;
            std::cout << "store %t" << T << ", %t" << $5 << "(" << e << ")" << std::endl;
            T++;
            delete $3;
      }
    ;

/* ---------------- CONDICIONAL (IF / IF-ELSE) ---------------- */
  
opt_template:
    /* vazio */ 
  | EMPTY_TEMPLATE
  | LPAR_EXPR RPAR_EXPR
  ;

else_block:
    ELSE opt_template LCHAVES codigos RCHAVES
    {
        // ELSE isolado: não precisa de jumps ou labels
    }
    ;


condicional:
      IF LPAR_EXPR condicoes RPAR_EXPR LCHAVES
        {
            int cond_tmp;
            if (val_stack.empty()) {
                std::cout << "mov %t" << T << ", 1" << std::endl;
                cond_tmp = T++;
            } else {
                cond_tmp = val_stack.top(); val_stack.pop();
            }
            int else_label = S++;
            int end_label = S++;
            std::cout << "jf %t" << cond_tmp << ", R" << else_label << std::endl;
            lbl_stack.push(else_label);
            lbl_stack.push(end_label);
        }
    codigos RCHAVES
        {
            if (lbl_stack.empty()) sem_erro("lbl_stack vazio no IF");
            int end_label = lbl_stack.top(); lbl_stack.pop();
            if (lbl_stack.empty()) sem_erro("lbl_stack vazio no IF");
            int else_label = lbl_stack.top(); lbl_stack.pop();
            std::cout << "jump R" << end_label << std::endl;
            std::cout << "label R" << else_label << std::endl;
            lbl_stack.push(end_label);  /* push it back for else_part */
        }
    else_part
        {
            if (lbl_stack.empty()) sem_erro("lbl_stack vazio no IF");
            int end_label = lbl_stack.top(); lbl_stack.pop();
            std::cout << "label R" << end_label << std::endl;
        }
  ;

else_part:
    ELSE opt_template LCHAVES codigos RCHAVES
    | /* vazio */
    ;
/* ---------------- LAÇOS ---------------- */

/* mid-marker: start of loop -> create labels and emit label Rloop */
mid_loop_start:
    /* vazio */ {
        int loop = S++;
        int exit_label = S++;
        loop_stack.push(loop);
        exit_stack.push(exit_label);
        std::cout << "label R" << loop << std::endl;
    }
    ;

/* mid-marker: after condicoes -> emit jf using cond temp and exit_label */
mid_loop_jf:
    /* vazio */ {
        if (val_stack.empty()) sem_erro("condicao ausente no for/while");
        int cond_tmp = val_stack.top(); val_stack.pop();
        int exit_label = exit_stack.top();
        std::cout << "jf %t" << cond_tmp << ", R" << exit_label << std::endl;
    }
    ;

laco:
      /* for simplificado: for ( atrib ; condicoes ; id ++/-- ) { codigos } */
      FOR LPAR_EXPR atrib mid_loop_start condicoes mid_loop_jf PEV ID cremento_for RPAR_EXPR LCHAVES codigos RCHAVES {
            /* recuperar rótulos */
            int loop = loop_stack.top(); loop_stack.pop();
            int exit_label = exit_stack.top(); exit_stack.pop();

            /* valida var do incremento */
            int e = getend(*$8);
            if (e == -1) sem_erro("variavel nao declarada no for: " + *$8);

            if ($9 == 1)
                std::cout << "add %r" << e << ", %r" << e << ", 1" << std::endl;
            else
                std::cout << "sub %r" << e << ", %r" << e << ", 1" << std::endl;

            std::cout << "jump R" << loop << std::endl;
            std::cout << "label R" << exit_label << std::endl;

            delete $8;
      }

    /* while: emitir label, avaliar condicoes, jf, executar bloco, jump/label */
    | WHILE LPAR_EXPR mid_loop_start condicoes mid_loop_jf RPAR_EXPR LCHAVES codigos RCHAVES {
            int loop = loop_stack.top(); loop_stack.pop();
            int exit_label = exit_stack.top(); exit_stack.pop();

            std::cout << "jump R" << loop << std::endl;
            std::cout << "label R" << exit_label << std::endl;
    }
    ;

/* ---------------- RETURN ---------------- */

retorno:
      RETURN expr PEV {
            /* Raposeitor não precisa realmente de ret; colocar label/municao opcional */
            std::cout << "mov %r0, %t" << $2 << std::endl; /* coloca em r0 por exemplo */
      }
    ;

%%

/* ---------------- ERRO SINTÁTICO ---------------- */
void yyerror(const char *s) {
    std::cerr << "Erro sintatico: " << s << std::endl;
}

/* ---------------- MAIN ---------------- */
int main(int argc, char **argv) {
    if (argc > 1) {
        std::ifstream fin(argv[1]);
        if (!fin) { perror("open"); return 1; }
        lexer.switch_streams(&fin, nullptr);
    } else {
        lexer.switch_streams(&std::cin, nullptr);
    }
    yyparse();
    return 0;
}