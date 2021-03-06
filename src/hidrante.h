#ifndef __HIDRANTE_H
#define __HIDRANTE_H

typedef void* Hidrante;

//Função responsável para criar Hidrante. Retorna um pointer instanciado.
Hidrante criaHidrante(char* id, float x, float y);

/*
Setters: Define o atributo do título da função
PRE: Objeto e atributo
*/
void hidranteSetId(Hidrante hidrante, char* id);
void hidranteSetX(Hidrante hidrante, float x);
void hidranteSetY(Hidrante hidrante, float y);

/*
Getters: Retorna o atributo do título da função
PRE: Objeto
POS: Atributo especificado
*/
char* hidranteGetId(Hidrante hidrante);
float hidranteGetX(Hidrante hidrante);
float hidranteGetY(Hidrante hidrante);

#endif
