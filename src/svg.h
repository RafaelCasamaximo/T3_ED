#ifndef __SVG_H
#define __SVG_H

#include "doublyLinkedList.h"
#include "corPadrao.h"

/*
Desenha o arquivo SVG do GEO
Pré: As listas, as cores dos elementos e o caminho onde será criada as saídas
Pós: Nenhum
*/
void desenhaSvgGeo(DoublyLinkedList* listas, CorPadrao cores, char* dirSaida);
void desenhaSvgQry(DoublyLinkedList* listas, CorPadrao cores, char* dirSaida);

#endif
