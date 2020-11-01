//Standart Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Custom Headers para configuração
#include "parametro.h"
#include "trataString.h"
#include "corPadrao.h"
#include "leituraGeo.h"

//Custom Headers para estruturas e organização
#include "doublyLinkedList.h"

//Enumeration para todas as listas utilizadas
enum LISTAS{CIRCULO, RETANGULO, TEXTO, LINHA, QUADRA, HIDRANTE, SEMAFORO, RADIOBASE};

int main(int argc, char* argv[]){
    CorPadrao cores = criaCorPadrao("0.5", "coral", "saddlebrown", "0.5", "red", "darkred", "0.5", "deeppink", "mediumvioletred", "0.5", "green", "red", "0.5", "0.5");

    //Variáveis passadas como parametro para o Path
    char* dirEntrada = NULL;
    char* arqGeo = NULL;
    char* arqQry = NULL;
    char* dirSaida = NULL;

    //Variaveis criadas para a localização dos arquivos de entrada e de saída
    //Armazena dirEntrada + arqGeo
    char* dirGeo = NULL;

    //Realiza a leitura dos parâmetros
    for(int i = 1; argc > i; i++){     
        if(strcmp(argv[i], "-e") == 0){     
            dirEntrada = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-f") == 0){        
            arqGeo = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-q") == 0){       
            arqQry = buscaParametros(argv, i);
        }
        else if(strcmp(argv[i], "-o") == 0){     
            dirSaida = buscaParametros(argv, i);
        }
        i++;
    }

    //Verifica se os parâmetros essenciais estão inseridos
    verificaExecucao(arqGeo, dirSaida);

    //Cria Listas
    DoublyLinkedList listas[8];
    for(int i = 0; i < 8; i++){
        listas[i] = create();
    }

    //Refatorar trataString para retornar char*
    concatenaCaminhos(dirEntrada, arqGeo, &dirGeo);
    readGeo(listas, dirGeo, cores);

    
    return 0;
}
