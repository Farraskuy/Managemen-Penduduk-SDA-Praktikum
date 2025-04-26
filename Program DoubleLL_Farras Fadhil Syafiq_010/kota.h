#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

typedef struct Kota *addressKota;
typedef struct Kota{
    char *kt;       
    address p; 
    addressKota *next;
} Kota;

typedef struct {
    addressKota *First;
} ListKota;

void createEmptyKota(ListKota *ListKota);
void findKota(ListKota *listKota, char **temp);
void addKota(ListKota *listKota);
void editKota(ListKota *listKota);
void deleteKota(ListKota *listKota);
void printKota(ListKota listKota);

#endif
