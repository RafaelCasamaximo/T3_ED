//Standart Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Custom Headers para configuração
#include "parametro.h"
#include "trataString.h"
#include "corPadrao.h"
#include "leituraGeo.h"
#include "leituraQry.h"
#include "svg.h"
#include "texto.h"

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
    //Armazena o nome do arquivo .geo
    char* nomeArquivoGeo = NULL;
    //Armazena o path de saida do arquivo .svg + nome do arquivo + extensão
    char* saidaSvgGeo = NULL;
    //Armazena o path de entrada do arquivo qry
    char* dirQry = NULL;
    //Armazena o nome do arquivo .geo sem extensão
    char* nomeGeoSemExtensao = NULL;
    //Armazena o nome do arquivo .qry sem extensão
    char* nomeQrySemExtensao = NULL;
    //Armazena o nome do arquivo geo com o arquivo qry
    char* nomeGeoQry = NULL;
    //Armazena o caminho de saida do SVG do geo+qry
    char* dirSaidaGeoQry = NULL;
    //Armazena o nome do arquivo de Log (TXT)
    char* nomeArquivoLogTxt = NULL;
    //Armazena o path de saida do arquivo de Log
    char* dirTxt = NULL;



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
    for(int i = CIRCULO; i <= RADIOBASE; i++){
        listas[i] = create();
    }

    //Refatorar trataString para retornar char*
    concatenaCaminhos(dirEntrada, arqGeo, &dirGeo);
    readGeo(listas, dirGeo, cores);
    
    //me retorna por ex. overlaps-01.svg
    getNomeConcatExtension(arqGeo, ".svg", &nomeArquivoGeo);
    //me retorna pastaSaida/resultados/overlaps-01.svg
    concatenaCaminhos(dirSaida, nomeArquivoGeo, &saidaSvgGeo);
    //Cria o arquivo do SVG e desenha a lista dentro dele
    desenhaSvgGeo(listas, cores, saidaSvgGeo);


    if(arqQry != NULL){
        //Comando para criar o caminho que será utilizado para abrir o .qry
        concatenaCaminhos(dirEntrada, arqQry, &dirQry);

        //Me retorna o nome do arquivo geo sem extensão (utilizado mais tarde no nome do svg)
        extraiNome(arqGeo, &nomeGeoSemExtensao);

        //Me retorna o nome do arquivo qry sem extensão (utilizado mais tarde no nome do svg)
        extraiNome(arqQry, &nomeQrySemExtensao);
        
        //Me retorna nomeDoArquivoGeo-NomeDoArquivoQry.Extensão (nomeDoArquivoGeo-NomeDoArquivoQry.svg)
        concatenaNomeGeoQry(nomeGeoSemExtensao, nomeQrySemExtensao, ".svg", &nomeGeoQry);
        
        //Concatena o caminho de saida com o nome gerado no comando acima (saida do SVG)
        concatenaCaminhos(dirSaida, nomeGeoQry, &dirSaidaGeoQry);
        
        //Me retorna nomeDoArquivoGeo-NomeDoArquivoQry.Extensão (nomeDoArquivoGeo-NomeDoArquivoQry.txt)
        concatenaNomeGeoQry(nomeGeoSemExtensao, nomeQrySemExtensao, ".txt", &nomeArquivoLogTxt);

        //Concatena o caminho de saida com o nome gerado no comando acima (saida do TXT)
        concatenaCaminhos(dirSaida, nomeArquivoLogTxt, &dirTxt);

        //Lê os comandos do QRY
        readQry(listas, dirQry, dirTxt);

        //Desenha o svg do QRY
        desenhaSvgQry(listas, cores, dirSaidaGeoQry);
    }

    //Deleta todas as listas
    for(int i = CIRCULO; i <= RADIOBASE; i++){
        //Caso a lista seja uma lista de texto, deleta todos os textos alocados
        if(i == TEXTO){
            for(Node aux = getFirst(listas[TEXTO]); aux != NULL; aux = getNext(aux)){
                textoDeletaTxt(getInfo(aux));
                printf("%d", TEXTO);
            }
        }
        removeList(listas[i]);
    }

    free(dirEntrada);
    free(arqGeo);
    free(arqQry);
    free(dirSaida);
    free(dirGeo);
    free(nomeArquivoGeo);
    free(saidaSvgGeo);
    free(dirQry);
    free(nomeGeoSemExtensao);
    free(nomeQrySemExtensao);
    free(nomeGeoQry);
    free(dirSaidaGeoQry);
    free(nomeArquivoLogTxt);
    free(dirTxt);
    free(cores);

    return 0;
}
