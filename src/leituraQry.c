#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leituraQry.h"
#include "doublyLinkedList.h"
#include "linha.h"
#include "retangulo.h"
#include "corPadrao.h"
#include "qry.h"



enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE, POSTOSAUDE, DENSIDADEDEMOGRAFICA, LOCALCASOS, POLIGONO};


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
    
    int j = 0, k = 0, n = 0, num = 0;
    int interno = 0;
    int sobrepoe = 0;
    float x = 0, y = 0, w = 0, h = 0, r = 0;
    float centroDeMassaX = 0, centroDeMassaY = 0; 
    char comando[6];
    char cb[22], cp[22];
    char cep[20];
    char face;

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
            sobrepoe = overlay(listas, j, k, &x, &y, &w, &h, fileTxt);
            if(sobrepoe == 0){
                retanguloAux = criaRetangulo(id, 1, x, y, w, h, "black", "none");
                insert(listas[RETANGULO], retanguloAux);
            }
            if(sobrepoe == 1){
                retanguloAux = criaRetangulo(id, 0, x, y, w, h, "black", "none");
                insert(listas[RETANGULO], retanguloAux);
            }
            printf("%d", sobrepoe);
        }
        //i?        
        if(strcmp(comando, "i?") == 0){
            fscanf(fileQry, "%d %f %f", &j, &x, &y);
            interno = inside(listas, j, x, y, &centroDeMassaX, &centroDeMassaY, fileTxt);
            if(interno == 1){ //dentro
                linhaAux = criaLinha(x, y, centroDeMassaX, centroDeMassaY, 1, 1, "0");
            }
            else if(interno == 0 || interno == 2){ //Fora e/ou borda
                linhaAux = criaLinha(x, y, centroDeMassaX, centroDeMassaY, 1, 0, "0");
            }
            if(interno == 1 || interno == 0 || interno == 2){
                insert(listas[LINHA], linhaAux);
            }
        }
        //pnt
        if(strcmp(comando, "pnt") == 0){
            fscanf(fileQry, "%d %s %s", &j, cb, cp);
            pnt(listas, j, cb, cp, fileTxt);
        }
        //pnt*
        if(strcmp(comando, "pnt*") == 0){
            fscanf(fileQry, "%d %d %s %s", &j, &k, cb, cp);
            pntAst(listas, j, k, cb, cp, fileTxt);
        }
        //delf
        if(strcmp(comando, "delf") == 0){
            fscanf(fileQry, "%d", &j);
            delf(listas, j, fileTxt);
        }
        //delf*
        if(strcmp(comando, "delf*") == 0){
            fscanf(fileQry, "%d %d", &j, &k);
            delfAst(listas, j, k, fileTxt);
        }
        

        //T2_ED
        //dq
        if(strcmp(comando, "dq") == 0){
            char hashtag = getc(fileQry);
            hashtag = getc(fileQry);
            if(hashtag == '#'){
                fscanf(fileQry, "%s %f", cep, &r);
                dq(listas, cep, r, 1, id, fileTxt);
            }
            fseek(fileQry, -2, SEEK_CUR);
            fscanf(fileQry, "%s %f", cep, &r);
            dq(listas, cep, r, 0, id, fileTxt);
            id -= 2;
        }
        //del
        if(strcmp(comando, "del") == 0){
            fscanf(fileQry, "%s", cep);
            del(listas, cep, fileTxt);
        }
        //cbq    
        if(strcmp(comando, "cbq") == 0){
            fscanf(fileQry, "%f %f %f %s", &x, &y, &r, cb);
            cbq(listas, x, y, r, cb, fileTxt);
        }   
        //crd?      
        if(strcmp(comando, "crd?") == 0){
            fscanf(fileQry, "%s", cep);
            crd(listas, cep, fileTxt);
        }
        //car
        if(strcmp(comando, "car") == 0){
            fscanf(fileQry, "%f %f %f %f", &x, &y, &w, &h);
            car(listas, x, y, w, h, id, fileTxt);
        }   


        //T3_ED
        //cv
        if(strcmp(comando, "cv") == 0){
            fscanf(fileQry, "%d %s %c %d", &n, cep, &face, &num);
            cv(listas, n, cep, face, num);
        }
        //soc
        if(strcmp(comando, "soc") == 0){
            fscanf(fileQry, "%d %s %c %d", &k, cep, &face, &num);
            soc(listas, k, cep, face, num, fileTxt);
        }
        //ci        
        if(strcmp(comando, "ci") == 0){
            fscanf(fileQry, "%f %f %f", &x, &y, &r);
            ci(listas, x, y, r, fileTxt); 
        }
        id--;
    }

    fclose(fileTxt);
    fclose(fileQry);
}
