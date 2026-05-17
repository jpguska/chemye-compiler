%{
#include <iostream>
#include <string>
#include <cstring>
#include "bison.tab.h"
%}

%option noyywrap
%option c++
%x COMMENT
%x TEMPLATE

delim     [ \t\n\r\a\b\f]
brancos   {delim}+

letra     [a-zA-Z]
digito    [0-9]

id        {letra}({letra}|{digito}|_)*
num_int   {digito}+

%%

<INITIAL,TEMPLATE>{brancos}      { }

    /* Ignora a linha "Arcanum:..." (Note o espaço antes do comentário) */
"Arcanum:"[^\n]*\n   { }

    /* Comentário multilinha: Arcanum[: ... :] */
"Arcanum[:"        { BEGIN(COMMENT); }

<COMMENT>":]"      { BEGIN(INITIAL); }
<COMMENT><<EOF>>   {
                      std::cerr << "Erro lexico: comentario multilinha nao fechado!\n";
                      exit(1);
                   }
<COMMENT>\n        { }
<COMMENT>.         { }


    /* --- MUDANÇA DE ESTADOS --- */


    /* --- REGRAS COMPARTILHADAS (INITIAL e TEMPLATE) --- */
    /* Isso evita duplicar código para operadores que existem nos dois contextos */

<INITIAL,TEMPLATE>"++" { return MAISMAIS; }
<INITIAL,TEMPLATE>"--" { return MENOSMENOS; }
<INITIAL,TEMPLATE>"==" { return IGUAL; }
<INITIAL,TEMPLATE>"!=" { return DIFERENTE; }
<INITIAL,TEMPLATE>"<=" { return MENORIGUAL; }
<INITIAL,TEMPLATE>">=" { return MAIORIGUAL; }

<INITIAL,TEMPLATE>"+"  { return MAIS; }
<INITIAL,TEMPLATE>"-"  { return MENOS; }
<INITIAL,TEMPLATE>"*"  { return MULT; }
<INITIAL,TEMPLATE>"/"  { return DIV; }
<INITIAL,TEMPLATE>"%"  { return MOD; }
<INITIAL,TEMPLATE>"<"  { return MENOR; }
<INITIAL,TEMPLATE>">"  { return MAIOR; }

<INITIAL,TEMPLATE>","  { return VIRGULA; }

    /* Acesso a vetores dentro e fora */
<INITIAL,TEMPLATE>"["  { return LCOLCHETES; }
<INITIAL,TEMPLATE>"]"  { return RCOLCHETES; }

    /* Delimitadores de bloco */
<INITIAL,TEMPLATE>"[:"   { return LCHAVES; }
<INITIAL,TEMPLATE>":]"   { return RCHAVES; }

<INITIAL,TEMPLATE>"|:|"    { return EMPTY_TEMPLATE; }

<INITIAL,TEMPLATE>"|:"      { return LPAR_EXPR; }
<INITIAL,TEMPLATE>":|"      { return RPAR_EXPR; }

<INITIAL,TEMPLATE>"."     { return PEV; }
<INITIAL,TEMPLATE>":"     { return DOISPONTOS; }

    /* Palavras reservadas (disponíveis em INITIAL e TEMPLATE) */
<INITIAL,TEMPLATE>"PRONUNTIARE"      { return PRINTF; }
<INITIAL,TEMPLATE>"INSCULPIRE"       { return SCANF; }
<INITIAL,TEMPLATE>"inteiro"          { return INT; }
<INITIAL,TEMPLATE>"float"            { return FLOAT; }
<INITIAL,TEMPLATE>"char"             { return CHAR; }
<INITIAL,TEMPLATE>"CIRCA"            { return FOR; }
<INITIAL,TEMPLATE>"ITERARE"          { return WHILE; }
<INITIAL,TEMPLATE>"SIVERITAS"        { return IF; }
<INITIAL,TEMPLATE>"ALITER"           { return ELSE; }
<INITIAL,TEMPLATE>"REVERSIO"         { return RETURN; }
<INITIAL,TEMPLATE>"SYMBOLUM"         { return DECLARACAO; }
<INITIAL,TEMPLATE>"ET"               { return AND; }
<INITIAL,TEMPLATE>"VEL"              { return OR; }
<INITIAL,TEMPLATE>"NON"              { return NOT; }
<INITIAL,TEMPLATE>"ACCIPIT"          { return ATRIB; }


    /* --- LITERAIS (INITIAL e TEMPLATE) --- */

<INITIAL,TEMPLATE>{num_int} {
    yylval.int_val = atoi(yytext);
    return NUM;
}

<INITIAL,TEMPLATE>{id} {
    yylval.str_val = new std::string(yytext);
    return ID;
}

<INITIAL,TEMPLATE>\"([^"\\]|\\.)*\" {
    std::string s(yytext);
    /* Remove as aspas */
    if (s.size() >= 2)
        s = s.substr(1, s.size() - 2);
    
    /* CORREÇÃO: Usando 's' em vez de yytext */
    yylval.str_val = new std::string(s);
    return STRING;
}


    /* --- TRATAMENTO DE ERROS --- */

<TEMPLATE><<EOF>> {
    std::cerr << "Erro lexico: template nao fechado (falta :|)\n";
    exit(1);
}

<TEMPLATE>. {
    std::cerr << "Erro lexico: token invalido no template '" << yytext << "'\n";
    exit(1);
}

    /* Catch-all para INITIAL */
. {
    std::cerr << "Erro lexico: token invalido '" << yytext << "'\n";
    exit(1);
}

%%