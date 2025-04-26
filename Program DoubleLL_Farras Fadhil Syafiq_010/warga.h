
#ifndef WARGA_H
#define WARGA_H

#include "kota.h"

typedef struct Warga *addressWarga;
typedef struct tElmtList Warga;

void addWarga(ListKota *ListKota);
void editWarga(ListKota *ListKota);
void updateWarga(ListKota *ListKota);
void deleteWarga(ListKota *ListKota);

void printWarga(Kota Kota);
void printAllWarga(ListKota ListKota);

#endif
