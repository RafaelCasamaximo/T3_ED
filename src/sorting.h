#ifndef __SORTING_H
#define __SORTING_H

#include "infoSoc.h"
#include "localCasos.h"
#include "doublyLinkedList.h"


void shellSorting(InfoSoc* vet, int n);

int orientacao(LocalCasos a, LocalCasos b, LocalCasos c);
int comparar(LocalCasos p0, LocalCasos a, LocalCasos b);
Node partition(DoublyLinkedList l, Node primeiro, Node ultimo);
void quickSortList(DoublyLinkedList l, Node primeiro, Node ultimo);
DoublyLinkedList envoltoriaConvexa(DoublyLinkedList lista);
float obterArea(DoublyLinkedList l);

#endif
