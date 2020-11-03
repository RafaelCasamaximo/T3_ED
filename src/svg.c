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

    //Desenho GEO do T2
    for(Node aux = getFirst(listas[QUADRA]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n\t\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", quadraGetX(getInfo(aux)), quadraGetY(getInfo(aux)), quadraGetWidth(getInfo(aux)), quadraGetHeight(getInfo(aux)), coresPadraoGetBordaQuadras(cores), coresPadraoGetPreenchimentoQuadras(cores), coresPadraoGetEspessuraQuadras(cores));
        fprintf(fileSvgGeo, "\n\t\t\t<text x=\"%f\" y=\"%f\" fill=\"black\" stroke=\"seashell\" stroke-width=\"0.5\" dominant-baseline=\"middle\" text-anchor=\"middle\">%s</text>", quadraGetX(getInfo(aux)) + (quadraGetWidth(getInfo(aux)) / 2), quadraGetY(getInfo(aux)) + (quadraGetHeight(getInfo(aux)) / 2), quadraGetCep(getInfo(aux)));
    }
    for(Node aux = getFirst(listas[SEMAFORO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n\t\t<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", semaforoGetX(getInfo(aux)), semaforoGetY(getInfo(aux)), coresPadraoGetPreenchimentoSemaforos(cores), coresPadraoGetBordaSemaforos(cores), coresPadraoGetEspessuraSemaforos(cores));
    }
    for(Node aux = getFirst(listas[HIDRANTE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n\t\t<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>", hidranteGetX(getInfo(aux)), hidranteGetY(getInfo(aux)), coresPadraoGetPreenchimentoHidrantes(cores), coresPadraoGetBordaHidrantes(cores), coresPadraoGetEspessuraHidrantes(cores));
    }
    for(Node aux = getFirst(listas[RADIOBASE]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n\t\t<circle cx=\"%f\" cy=\"%f\" r=\"3\" style=\"fill:%s;stroke:%s;stroke-widht:%s\"/>",radioBaseGetX(getInfo(aux)), radioBaseGetY(getInfo(aux)), coresPadraoGetPreenchimentoRadioBases(cores), coresPadraoGetBordaRadioBases(cores), coresPadraoGetEspessuraRadioBases(cores));
    }

    //Desenho GEO do T1
    for(Node aux = getFirst(listas[CIRCULO]); aux != NULL; aux = getNext(aux)){
        //Circulo auxCirc = getInfo(aux);
        fprintf(fileSvgGeo, "\n\t\t<circle cx=\"%f\" cy=\"%f\" r=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", circuloGetX(getInfo(aux)), circuloGetY(getInfo(aux)), circuloGetRaio(getInfo(aux)), circuloGetCorBorda(getInfo(aux)), circuloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraCirculos(cores));
    }
    for(Node aux = getFirst(listas[RETANGULO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n\t\t<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" style=\"stroke:%s;fill:%s;stroke-widht:%s\"/>", retanguloGetX(getInfo(aux)), retanguloGetY(getInfo(aux)), retanguloGetWidth(getInfo(aux)), retanguloGetHeight(getInfo(aux)), retanguloGetCorBorda(getInfo(aux)), retanguloGetCorPreenchimento(getInfo(aux)), coresPadraoGetEspessuraRetangulos(cores));
    }
    for(Node aux = getFirst(listas[TEXTO]); aux != NULL; aux = getNext(aux)){
        fprintf(fileSvgGeo, "\n\t\t<text x=\"%f\" y=\"%f\" stroke=\"%s\" fill=\"%s\" stroke-width=\"0.5\">%s</text>", textoGetX(getInfo(aux)), textoGetY(getInfo(aux)), textoGetCorBorda(getInfo(aux)), textoGetCorPreenchimento(getInfo(aux)), textoGetTexto(getInfo(aux)));
        //stroke-width não devia estar em cores padrao?
    }
    //testar com getLast();

    fprintf(fileSvgGeo, "\n</svg>");
    fclose(fileSvgGeo);
}
