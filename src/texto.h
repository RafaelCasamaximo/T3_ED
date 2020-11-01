#ifndef __TEXTO_H_
#define __TEXTO_H_

typedef void* Texto;

//Create
Texto criaTexto(int id, int size, float x, float y, char* txt, char* cb, char* cp);


//Getters
int textoGetId(Texto texto);
float textoGetX(Texto texto);
float textoGetY(Texto texto);
char* textoGetTexto(Texto texto);
char* textoGetCorBorda(Texto texto);
char* textoGetCorPreenchimento(Texto texto);


//Setters
void textoSetId(Texto texto, int id);
void textoSetX(Texto texto, float x);
void textoSetY(Texto texto, float y);
void textoSetTexto(Texto texto, char* txt, int size);
void textoSetCorBorda(Texto texto, char* cb);
void textoSetCorPreenchimento(Texto texto, char* cp);



#endif
