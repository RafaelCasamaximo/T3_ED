#ifndef __DENSIDADE_DEMOGRAFICA_H
#define __DENSIDADE_DEMOGRAFICA_H

typedef void* DensidadeDemografica;

DensidadeDemografica criaDensidadeDemografica(float x, float y, float w, float h, float d);

void densidadeDemograficaSetX(DensidadeDemografica densidade, float x);
void densidadeDemograficaSetY(DensidadeDemografica densidade, float y);
void densidadeDemograficaSetWidth(DensidadeDemografica densidade, float w);
void densidadeDemograficaSetHeight(DensidadeDemografica densidade, float h);
void densidadeDemograficaSetDensidadeDemografica(DensidadeDemografica densidade, float d);


float densidadeDemograficaGetX(DensidadeDemografica densidade);
float densidadeDemograficaGetY(DensidadeDemografica densidade);
float densidadeDemograficaGetWidth(DensidadeDemografica densidade);
float densidadeDemograficaGetHeight(DensidadeDemografica densidade);
float densidadeDemograficaGetDensidadeDemografica(DensidadeDemografica densidade);

#endif