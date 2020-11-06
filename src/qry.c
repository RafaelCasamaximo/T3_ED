#include <stdio.h>
#include <stdlib.h>

#include "utilitario.h"
#include "doublyLinkedList.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};


int inside(DoublyLinkedList* list, int id, float xp, float yp){
    int idAux = 0;
    for(int i = CIRCULO; i <= RETANGULO; i++){
        for(Node aux = getFirst(list[i]); aux != NULL; aux = getNext(aux)){
            if(i == CIRCULO){
               idAux = circuloGetId(getInfo(aux));
            }
            else{
                idAux = retanguloGetId(getInfo(aux));
            }
        
            if(id == idAux){
                if(i == CIRCULO){
                    float circX = circuloGetX(getInfo(aux));
                    float circY = circuloGetY(getInfo(aux));
                    float circR = circuloGetRaio(getInfo(aux));

                    if(distanciaQuadrada(xp, yp, circX, circY) <= circR*circR){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    float retX = retanguloGetX(getInfo(aux));
                    float retY = retanguloGetY(getInfo(aux));
                    float retW = retanguloGetWidth(getInfo(aux));
                    float retH = retanguloGetHeight(getInfo(aux));

                    //x <= xp <= x+w
                    //y <= yp <= y+h
                    if((retX <= xp && xp <= retX+retW)&&(retY <= yp && yp <= retY+retH)){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
    return -1;
}




void pnt(DoublyLinkedList* listas, int j, char* cb, char* cp, FILE* fileTxt){
    int id = 0;

    Info info;

    for(int i = 0; i < 3; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            else if(i == TEXTO){
                id = textoGetId(info);
            }
            if(id == j){
                if(i == CIRCULO){
                    circuloSetCorBorda(info, cb);
                    circuloSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)));
                }
                else if(i == RETANGULO){
                    retanguloSetCorBorda(info, cb);
                    retanguloSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)));
                }
                else if(i == TEXTO){
                    textoSetCorBorda(info, cb);
                    textoSetCorPreenchimento(info, cp);
                    fprintf(fileTxt, "pnt %s %s\n%f %f\n\n", cb, cp, textoGetX(getInfo(aux)), textoGetY(getInfo(aux)));
                }
                return;
            }
        }
    }
}

void pntAst(DoublyLinkedList* listas, int j, int k, char* cb, char* cp, FILE* fileTxt){
    
    for(int i = min(j, k); i <= max(j, k); i++){
        pnt(listas, i, cb, cp, fileTxt);
    }
}
 

void delf(DoublyLinkedList* listas, int j){
    Info info;
    int id;
    
    for(int i = 0; i < 3; i++){
        for(Node aux = getFirst(listas[i]); aux != NULL; aux = getNext(aux)){
            info = getInfo(aux);
            if(i == CIRCULO){
                id = circuloGetId(info);
            }
            else if(i == RETANGULO){
                id = retanguloGetId(info);
            }
            else if(i == TEXTO){
                id = textoGetId(info);
            }
            if(id == j){
                if(i == TEXTO){
                    textoDeletaTxt(info);
                }
                removeNode(listas[i], aux);
                return;
            }
        }
    }
}


void delfAst(DoublyLinkedList* listas, int j, int k){
    for(int i = min(j, k); i <= max(j, k); i++){
        delf(listas, i);
    }
}