#include <stdio.h>
#include <stdlib.h>

#include "utilitario.h"
#include "doublyLinkedList.h"

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
                    float circR = circuloGetR(getInfo(aux));

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
                    float retW = retanguloGetW(getInfo(aux));
                    float retH = retanguloGetH(getInfo(aux));

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