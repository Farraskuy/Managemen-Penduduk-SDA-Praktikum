
#ifndef WARGA_H
#define WARGA_H

#include "kota.h"

typedef struct Warga *addressWarga;
typedef struct tElmtList Warga;

void addWarga(ArrayKota *arrayKota);
void editWarga(ArrayKota *arrayKota);
void updateWarga(ArrayKota *arrayKota);
void deleteWarga(ArrayKota *arrayKota);

void printWarga(Kota Kota);
void printAllWarga(ArrayKota arrayKota);

#endif
