#ifndef __QRY_H
#define __QRY_H

#include <stdlib.h>
#include <stdio.h>
#include "doublyLinkedList.h"

int inside(DoublyLinkedList* list, int id, float xp, float yp);
void pnt(DoublyLinkedList* listas, int j, char* cb, char* cp, FILE* fileTxt);
void pntAst(DoublyLinkedList* listas, int j, int k, char* cb, char* cp, FILE* fileTxt);
void delf(DoublyLinkedList* listas, int j);
void delfAst(DoublyLinkedList* listas, int j, int k);

#endif