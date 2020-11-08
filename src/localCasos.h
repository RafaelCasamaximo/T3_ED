#ifndef __LOCAL_CASOS_H
#define __LOCAL_CASOS_H

typedef void* LocalCasos; 

LocalCasos criaLocalCasos(int n, int num, char* cep, char face, float x, float y);

int localCasosGetN(LocalCasos localCasos);
int localCasosGetNum(LocalCasos localCasos);
char* localCasosGetCep(LocalCasos localCasos);
char localCasosGetFace(LocalCasos localCasos);
float localCasosGetX(LocalCasos localCasos);
float localCasosGetY(LocalCasos localCasos);

void localCasosSetN(LocalCasos localCasos, int n);
void localCasosSetNum(LocalCasos localCasos, int num);
void localCasosSetCep(LocalCasos localCasos, char* cep);
void localCasosSetFace(LocalCasos localCasos, char face);
void localCasosSetX(LocalCasos localCasos, float x);
void localCasosSetY(LocalCasos localCasos, float y);

#endif