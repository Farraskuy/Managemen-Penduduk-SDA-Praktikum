#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "warga.h"
#include "kota.h"
#include "linked.h"
#include "utils.h"

void addWarga(ArrayKota *kota) {
    printf(" List Kota: \n");
    printKota(*kota);

    printf("======================================================\n");

    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);

	size_t i;
    for (i = 0; i < kota->size; i++) {
        if (strcmp(kota->kota[i].kt, kt) == 0) {
            char *nm = NULL;
            printf(" Masukkan nama warga: ");
            inputString(&nm);

            address warga = Alokasi(nm);

            if (warga == NULL) {
                printf(" Memory allocation failed\n");
                return;
            }

            List tempList;
            CreateList(&tempList);

            tempList.First = kota->kota[i].p;

            InsertFirst(&tempList, warga);

            kota->kota[i].p = tempList.First;

            printf(" Warga %s berhasil ditambahkan ke kota %s\n", nm, kt);
            sleep(1);
            return;
        } 
    }

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void editWarga(ArrayKota *arrayKota) {
    printKota(*arrayKota);

    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);

    char *nm = NULL;
    printf(" Masukkan nama warga yang ingin diedit: ");
    inputString(&nm);

    char *new_nm = NULL;
    printf(" Masukkan nama baru warga: ");
    inputString(&new_nm);

	size_t i;
    for (i = 0; i < arrayKota->size; i++) {
        if (strcmp(arrayKota->kota[i].kt, kt) == 0) {
            List list;
            list.First = arrayKota->kota[i].p;

            address P = Search(list, nm);

            if (P != NULL) {
                strcpy(P->info, new_nm);
                printf(" Warga %s berhasil diedit menjadi %s\n", nm, new_nm);
            } else {
                printf(" Warga %s tidak ditemukan di kota %s\n", nm, kt);
            }
            sleep(1);
            return;
        }
    }

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void deleteWarga(ArrayKota *arrayKota) {
    printf(" List Kota: \n");
    printKota(*arrayKota);

    printf("======================================================\n");

    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);
   
    size_t i;
    for (i = 0; i < arrayKota->size; i++) {
        if (strcmp(arrayKota->kota[i].kt, kt) == 0) {

            printWarga(arrayKota->kota[i]);
            printf("======================================================\n");

            char *nm = NULL;
            printf(" Masukkan nama warga yang ingin dihapus: ");
            inputString(&nm);

            Warga *cursor = arrayKota->kota[i].p;
            Warga *prev = NULL;

            while(cursor != NULL) {
                if (strcmp(cursor->info, nm) == 0) {
                    if (prev == NULL) {
                        arrayKota->kota[i].p = cursor->next;
                    } else {
                        prev->next = cursor->next;
                    }

                    free(cursor->info);
                    free(cursor);
                    printf(" Warga %s berhasil dihapus dari kota %s\n", nm, kt);
                    sleep(1);
                    return;
                }
                prev = cursor;
                cursor = cursor->next;
            }
            
            
            printf(" Warga %s tidak ditemukan di kota %s\n", nm, kt);
            sleep(1);
            return;
        }
    }

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void printWarga(Kota Kota) {
    printf(" List Warga: \n");
    if (Kota.p == NULL) {
        printf(" Tidak ada warga di kota %s\n\n", Kota.kt);
    } else {
        address P = Kota.p;
        while (P != NULL) {
            printf("  - %s\n", P->info);
            P = P->next;
        }
    }
}

void printAllWarga(ArrayKota arrayKota) {
    if (arrayKota.size == 0) {
        printf(" Tidak ada kota yang terdaftar.\n");
        return;
    }

	size_t i;
    for (i = 0; i < arrayKota.size; i++) {
        printf(" Kota %s:\n", arrayKota.kota[i].kt);
        printWarga(arrayKota.kota[i]);
    }
    printf("\n");
}
