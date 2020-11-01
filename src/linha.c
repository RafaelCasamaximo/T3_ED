#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linha.h"

typedef struct{
    float x1, y1, x2, y2;
    char c[22];
    int tracejado;
}LinhaStruct;


//Create
Linha criaLinha(float x1,  float x2, float y1, float y2, char* c){
    LinhaStruct* lin = (LinhaStruct*)malloc(sizeof(LinhaStruct));

    lin->x1 = x1;
    lin->y1 = y1;
    lin->x2 = x2;
    lin->y2 = y2;
    strcpy(lin->c, c);

    return lin;
}

//Getters
float linhaGetX1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*)linha;

    return lin->x1;
}

float linhaGetY1(Linha linha){
    LinhaStruct* lin = (LinhaStruct*)linha;

    return lin->y1;
}

float linhaGetX2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*)linha;

    return lin->x2;
}

float linhaGetY2(Linha linha){
    LinhaStruct* lin = (LinhaStruct*)linha;

    return lin->y2;
}


char* LinhaGetCor(Linha linha){
    LinhaStruct* lin = (LinhaStruct*)linha;

    return lin->c;
}


//Setters
void LinhaSetX1(Linha linha, float x1){
    LinhaStruct* lin = (LinhaStruct*)linha;

    lin->x1 = x1;
}

void LinhaSetY1(Linha linha, float y1){
    LinhaStruct* lin = (LinhaStruct*)linha;

    lin->y1 = y1;
}

void LinhaSetX2(Linha linha, float x2){
    LinhaStruct* lin = (LinhaStruct*)linha;

    lin->x2 = x2;
}

void LinhaSetY2(Linha linha, float y2){
    LinhaStruct* lin = (LinhaStruct*)linha;

    lin->y2 = y2;
}

void LinhaSetCor(Linha linha, char* c){
    LinhaStruct* lin = (LinhaStruct*)linha;

    strcpy(lin->c, c);
}
