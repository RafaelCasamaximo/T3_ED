#ifndef __QRY_H
#define __QRY_H

#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "densidadeDemografica.h"
#include "doublyLinkedList.h"

//T1_ED
//i?
/*
Verifica se um ponto é interno ao circulo
PRE: Coordenadas do Circulo e do ponto
POS: -1: Impossivel/ 0: Externo/ 1: Interno/ 2: Borda
*/
int insideCirculo(float x, float y, float cx, float cy, float r);
/*
Verifica se um ponto é interno ao retangulo
PRE: Coordenadas do Retangulo e do ponto
POS: -1: Impossivel/ 0: Externo/ 1: Interno/ 2: Borda
*/
int insideRetangulo(float x, float y, float rx, float ry, float rw, float rh);
/*
Função responsável pelo i?
PRE: Parâmetros do i?
POS: -1: Impossivel/ 0: Externo/ 1: Interno/ 2: Borda
*/
int inside(DoublyLinkedList* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY, FILE* fileTxt);

//o?
/*
Verifica se um circulo sobrepõe um retângulo
PRE: Circulo c, Retangulo r
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlayCirculoRetangulo(Circulo c, Retangulo r);

/*
Verifica se um circulo sobrepõe um retângulo
PRE: Circulo c, Retangulo r
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlayCirculoCirculo(Circulo c1, Circulo c2);

/*
Verifica se um circulo sobrepõe um retângulo
PRE: Circulo c, Retangulo r
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2);

/*
Função responsável pelo o?
PRE: Parâmetros do o?
POS: -1: Impossivel/ 0: Externo/ 1: Sobrepõe
*/
int overlay(DoublyLinkedList* listas, int j, int k, float* x, float* y, float* w, float* h, FILE* fileTxt);

//pnt e pnt*
/*
Função responsável pelo pnt. Altera a cor de uma figuras entre j e k.
PRE: ID j e novas cores da figura
*/
void pnt(DoublyLinkedList* listas, int j, char* cb, char* cp, FILE* fileTxt);

/*
Função responsável pelo pnt. Altera a cor de n figura.
PRE: IDs j e k e novas cores da figura
*/
void pntAst(DoublyLinkedList* listas, int j, int k, char* cb, char* cp, FILE* fileTxt);

//delf e delf*
/*
Função responsável pelo delf. Remove uma figura.
PRE: ID j da figura que será removida.
*/
void delf(DoublyLinkedList* listas, int j, FILE* fileTxt);

/*
Função responsável pelo delf. Remove uma figura.
PRE: IDs j e k da figura que será removida.
*/
void delfAst(DoublyLinkedList* listas, int j, int k, FILE* fileTxt);


//T2_ED
/*
Deleta um equipamento urbano ou quadra.
PRE: cep ou id da quadra ou equipamento urbano
*/
void del(DoublyLinkedList* listas, char* cep, FILE* fileTxt);
void cbq(DoublyLinkedList* listas, float x, float y, float r, char* cb, FILE* fileTxt);
void crd(DoublyLinkedList* listas, char* id, FILE* fileTxt);
void car(DoublyLinkedList* listas, float x, float y, float w, float h, int id, FILE* fileTxt);
void dq(DoublyLinkedList* listas, char* id, float r, int hashtag, int identificadorFigura, FILE* fileTxt);


//T3_ED
void cv(DoublyLinkedList* listas, int n, char* cep, char face, int num);
void soc(DoublyLinkedList* listas, int k, char* cep, char face, int num, FILE* fileTxt);
int circInsideDensidadeDemografica(DensidadeDemografica dd, float x, float y, float r);
void ci(DoublyLinkedList* listas, float x, float y, float r, FILE* fileTxt);

#endif
