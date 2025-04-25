#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

typedef struct {
    char *kt;       
    address p;      
} Kota;

typedef struct {
    Kota *kota;
    size_t size;
} ArrayKota;

void createEmptyKota(ArrayKota *arrayKota);
void findKota(ArrayKota *kota, char **temp);
void addKota(ArrayKota *kota);
void editKota(ArrayKota *kota);
void deleteKota(ArrayKota *kota);
void printKota(ArrayKota kota);

#endif
