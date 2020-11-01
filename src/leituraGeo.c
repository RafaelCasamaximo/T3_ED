//Standart Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Custom Headers
#include "leituraGeo.h" 
#include "corPadrao.h"
#include "doublyLinkedList.h"

//Custem Headers Formas
//Incluir formas


enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

typedef struct nx{
    int i;
    int nq;
    int nh;
    int ns;
    int nr;
}Nx;


void readGeo(DoublyLinkedList* listas, char* dirGeo, CorPadrao cores){
    FILE* fileGeo = NULL;
    fileGeo = fopen(dirGeo, "r");
    if(!fileGeo){
        exit(1);
    }
    printf("Arquivo GEO aberto com sucesso!");

    //Numeros maximos de Elementos em cada lista;
     Nx dft;
     dft.i = 1000;
     dft.nq = 1000;
     dft.nh = 1000;
     dft.ns = 1000;
     dft.nr = 1000;

    //Quantidade atual de Elementos em cada lista
     Nx atual;
     atual.i = 0;
     atual.nq = 0;
     atual.nh = 0;
     atual.ns = 0;
     atual.nr = 0;

    //Variaveis auxiliares
    char comando[3], cp[22], cb[22], cep[20], sw[22], cw[22], rw[22], cfill[22], cstrk[22], buffer;
    int id, bufferSize = 0;
    float r, x, y, w, h, d;
    char* txt = NULL;


    while(1){
        fscanf(fileGeo, "%s", comando);

        if(feof(fileGeo)){
            break;
        }

        //T1_ED
        //Comando: nx
        //nx i(circulos, retangulos ?e textos?) quadras hidrantes semaforos radiobases 
        else if(strcmp(comando, "nx") == 0){
            fscanf(fileGeo, "%d %d %d %d %d", &dft.i, &dft.nq, &dft.nh, &dft.ns, &dft.nr);
        }
        //Comando: c
        else if(strcmp(comando, "c") == 0){
            fscanf(fileGeo, "%d %f %f %f %s %s", &id, &r, &x, &y, cb, cp);
        }
        //Comando: r
        else if(strcmp(comando, "r") == 0){
            fscanf(fileGeo, "%d %f %f %f %f %s %s", &id, &w, &h, &x, &y, cb, cp);
        }
        //Comando: t
        else if(strcmp(comando, "t") == 0){
            fscanf(fileGeo, "%d %f %f %s %s", &id, &x, &y, cb, cp);
        }
        //T2_ED
        //Comando: q
        else if(strcmp(comando, "q") == 0){
            fscanf(fileGeo, "%s %f %f %f %f", cep, &x, &y, &w, &h);
        }
        //Comando: h
        else if(strcmp(comando, "h") == 0){
            fscanf(fileGeo, "%s %f %f", cep, &x, &y);
        }
        //Comando: s
        else if(strcmp(comando, "s") == 0){
            fscanf(fileGeo, "%s %f %f", cep, &x, &y);
        }
        //Comando: rb
        else if(strcmp(comando, "rb") == 0){
           fscanf(fileGeo, "%s %f %f", cep, &x, &y);
        }
        //Comando: cq
        else if(strcmp(comando, "cq") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
        }   
        //Comando: ch
        else if(strcmp(comando, "ch") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
        }
        //Comando: cr
        else if(strcmp(comando, "cr") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
        }
        //Comando: cs
        else if(strcmp(comando, "cs") == 0){
            fscanf(fileGeo, "%s %s %s", sw, cfill, cstrk);
        }
        //Comando: sw
        else if(strcmp(comando, "sw") == 0){
            fscanf(fileGeo, "%s %s", cw, rw);
        }
        //T3_ED
        //Comando ps
        else if(strcmp(comando, "ps") == 0){
            fscanf(fileGeo, "%f %f", &x, &y);
        }
        //Comando dd
        else if(strcmp(comando, "dd") == 0){
            fscanf(fileGeo, "%f %f %f %f %f", &x, &y, &w, &h, &d);
        }
    }

    fclose(fileGeo);
    
}