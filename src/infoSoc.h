#ifndef __INFOSOC_H
#define __INFOSOC_H

typedef void* InfoSoc;


InfoSoc criaInfoSoc(float xPS, float yPS, float distancia);

float infoSocGetX(InfoSoc infoSoc);
float infoSocGetY(InfoSoc infoSoc);
float infoSocGetDistancia(InfoSoc infoSoc);
void infoSocSetX(InfoSoc infoSoc, float x);
void infoSocSetY(InfoSoc infoSoc, float y);
void infoSocSetDistancia(InfoSoc infoSoc, float distancia);

#endif