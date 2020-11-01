#ifndef __LINHA_H_
#define __LINHA_H_

typedef void* Linha;

//Create
Linha criaLinha(float x1,  float x2, float y1, float y2, char* c);

//Getters
float linhaGetX1(Linha linha);
float linhaGetY1(Linha linha);
float linhaGetX2(Linha linha);
float linhaGetY2(Linha linha);
char* LinhaGetCor(Linha linha);

//Setters
void LinhaSetX1(Linha linha, float x1);
void LinhaSetY1(Linha linha, float y1);
void LinhaSetX2(Linha linha, float x2);
void LinhaSetY2(Linha linha, float y2);
void LinhaSetCor(Linha linha, char* c);

#endif
