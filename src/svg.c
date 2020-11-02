#include <stdio.h>
#include <stdlib.h>

#include "svg.h"
#include "doublyLinkedList.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "quadra.h"
#include "hidrante.h"
#include "semaforo.h"
#include "radioBase.h"
#include "linha.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

void desenhaSvgGeo(DoublyLinkedList* listas, CorPadrao cores, char* dirSaida){

    FILE *fileSvgGeo = NULL;
    fileSvgGeo = fopen(dirSaida, "w");
    if(!fileSvgGeo){
        exit(1);
    }
    printf("Arquivo SVG GEO criado com sucesso!");

    fprintf(fileSvgGeo, "<svg>");
    for(Node aux = getFirst(listas[CIRCULO]); aux != NULL; aux = getNext(aux)){
        //Circulo auxCirc = getInfo(aux);
        fprintf(fileSvgGeo, "<\tcircle cx=\"%f\" cy=\"%f\" r=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)), circuloGetRaio(getInfo(aux)), circuloGetCorBorda(getInfo(aux)), circuloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraCirculos(getInfo(cores)));
    }
    
    fprintf(fileSvgGeo, "\n</svg>");
    fclose(fileSvgGeo);
}