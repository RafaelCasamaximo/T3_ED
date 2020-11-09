#include <stdio.h>
#include <stdlib.h>

#include "sorting.h"
#include "infoSoc.h"

void shellSorting(InfoSoc* vet, int n){
    int gap = n / 2;
    while(gap > 0){
        for(int i = gap; i < n; i++){
            InfoSoc temp = vet[i];
            int j = i;
            while(j >= gap && infoSocGetDistancia(vet[j - gap]) > infoSocGetDistancia(temp)){
                vet[j] = vet[j - gap];
                j -= gap;
            }
            vet[j] = temp;
        }
        gap = gap / 2;
    }
}