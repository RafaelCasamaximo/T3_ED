#ifndef __QRY_H
#define __QRY_H

#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "doublyLinkedList.h"

//T1_ED
//i?
int insideCirculo(float x, float y, float cx, float cy, float r);
int insideRetangulo(float x, float y, float rx, float ry, float rw, float rh);
int inside(DoublyLinkedList* listas, int j, float x, float y, float* centroDeMassaX, float* centroDeMassaY, FILE* fileTxt);

//o?
int overlayCirculoRetangulo(Circulo c, Retangulo r);
int overlayCirculoCirculo(Circulo c1, Circulo c2);
int overlayRetanguloRetangulo(Retangulo r1, Retangulo r2);
int overlay(DoublyLinkedList* listas, int j, int k, float* x, float* y, float* w, float* h, FILE* fileTxt);

//pnt e pnt*
void pnt(DoublyLinkedList* listas, int j, char* cb, char* cp, FILE* fileTxt);
void pntAst(DoublyLinkedList* listas, int j, int k, char* cb, char* cp, FILE* fileTxt);

//delf e delf*
void delf(DoublyLinkedList* listas, int j, FILE* fileTxt);
void delfAst(DoublyLinkedList* listas, int j, int k, FILE* fileTxt);


//T2_ED
void del(DoublyLinkedList* listas, char* cep, FILE* fileTxt);

void cbq(DoublyLinkedList* listas, float x, float y, float r, char* cb, FILE* fileTxt);

void crd(DoublyLinkedList* listas, char* id, FILE* fileTxt);

void car(DoublyLinkedList* listas, float x, float y, float w, float h, int id, FILE* fileTxt);

void dq(DoublyLinkedList* listas, char* id, float r, int hashtag, int identificadorFigura, FILE* fileTxt);


//T3_ED
void cv(DoublyLinkedList* listas, int n, char* cep, char face, int num);
#endif