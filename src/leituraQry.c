#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraQry.h"
#include "doublyLinkedList.h"
#include "linha.h"
#include "retangulo.h"
#include "corPadrao.h"

enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

void readQry(DoublyLinkedList* listas, char* dirQry, char* dirTxt){

    FILE* fileTxt = NULL;
    fileTxt = fopen(dirTxt, "w");
    if(!fileTxt){
        exit(1);
    }
    printf("Arquivo TXT aberto com sucesso!");

    FILE* fileQry = NULL;
    fileQry = fopen(dirQry, "r");
    if(!fileQry){
        exit(1);
    }
    printf("Arquivo QRY aberto com sucesso!");

    int id = -1;
    
    int j = 0, k = 0;
    int interno = 0;
    int sobrepoe = 0;
    float x = 0, y = 0, w = 0, h = 0, r = 0;
    float centroDeMassaX = 0, centroDeMassaY = 0; 
    char comando[6];
    char cb[22], cp[22];
    char cep[20];

    Linha linhaAux = NULL;
    Retangulo retanguloAux = NULL;

    while(1){
        fscanf(fileQry, "%s", comando);

        if(feof(fileQry)){
            break;
        }

        //T1_ED
        //o?
        if(strcmp(comando, "o?") == 0){
            fscanf(fileQry, "%d %d", &j, &k);
        }
        //i?        
        if(strcmp(comando, "i?") == 0){
            fscanf(fileQry, "%d %f %f", &j, &x, &y);
        }
        //pnt
        if(strcmp(comando, "pnt") == 0){
            fscanf(fileQry, "%d %s %s", &j, cb, cp);

        }
        //pnt*
        if(strcmp(comando, "pnt*") == 0){
            fscanf(fileQry, "%d %d %s %s", &j, &k, cb, cp);
        }
        //delf
        if(strcmp(comando, "delf") == 0){
            fscanf(fileQry, "%d", &j);
        }
        // //delf*
        if(strcmp(comando, "delf*") == 0){
            fscanf(fileQry, "%d %d", &j, &k);
        }
        
        // //T2_ED
        // //dq
        // if(strcmp(comando, "dq") == 0){
        //     //Logica diferente
        // }
        // //del
        // if(strcmp(comando, "del") == 0){
        //     fscanf(fileQry, "%s", cep);
        // }
        // //cbq    
        // if(strcmp(comando, "cbq") == 0){
        //     fscanf(fileQry, "%f %f %f %s", &x, &y, &r, cb);
        // }   
        // //crd?      
        // if(strcmp(comando, "crd?") == 0){

        // }
        // //car
        // if(strcmp(comando, "car") == 0){
        //     fscanf(fileQry, "%f %f %f %f", &x, &y, &w, &h);
        // }   
        // id--;
    }

    fclose(fileTxt);
    fclose(fileQry);
}