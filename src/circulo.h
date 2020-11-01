#ifndef __CIRCULO_H_
#define __CIRCULO_H_

typedef void* Circulo;


//Create
Circulo criaCirculo(int id, float x, float y, float r, char* cb, char* cp);

//Getters
int circuloGetId(Circulo circulo);
float circuloGetX(Circulo circulo);
float circuloGetY(Circulo circulo);
float circuloGetRaio(Circulo circulo);
char* circuloGetCorBorda(Circulo circulo);
char* circuloGetCorPreenchimento(Circulo circulo);

//Setters
void circuloSetId(Circulo circulo, int id);
void circuloSetX(Circulo circulo, float x);
void circuloSetY(Circulo circulo, float y);
void circuloSetRaio(Circulo circulo, float r);
void circuloSetCorBorda(Circulo circulo, char* cb);
void circuloSetCorPreenchimento(Circulo circulo, char* cp);

#endif
