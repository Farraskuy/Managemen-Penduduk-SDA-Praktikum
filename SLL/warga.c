#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "warga.h"
#include "kota.h"
#include "linked.h"
#include "utils.h"

void addWarga(ListKota *ListKota) {
    printf(" List Kota: \n");
    printKota(*ListKota);

    printf("======================================================\n");

    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);
    
    Kota *cursor = ListKota->First;

    while (cursor != NULL) {
        if (strcmp(cursor->kt, kt) == 0) {
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

            tempList.First = cursor->p;

            InsertFirst(&tempList, warga);

            cursor->p = tempList.First;

            printf(" Warga %s berhasil ditambahkan ke kota %s\n", nm, kt);
            sleep(1);
            return;
        } 

        cursor = cursor->next;
    }

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void editWarga(ListKota *ListKota) {
    printKota(*ListKota);

    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);

    char *nm = NULL;
    printf(" Masukkan nama warga yang ingin diedit: ");
    inputString(&nm);

    char *new_nm = NULL;
    printf(" Masukkan nama baru warga: ");
    inputString(&new_nm);

    Kota *cursor = ListKota->First;

    while(cursor != NULL) {
        if (strcmp(cursor->kt, kt) == 0) {
            List list;
            list.First = cursor->p;

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

        cursor = cursor->next;
    }

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void deleteWarga(ListKota *ListKota) {
    printf(" List Kota: \n");
    printKota(*ListKota);

    printf("======================================================\n");

    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);

    Kota *cursor = ListKota->First;

    while (cursor != NULL) {
        if (strcmp(cursor->kt, kt) == 0) {

            printWarga(*cursor);
            printf("======================================================\n");

            char *nm = NULL;
            printf(" Masukkan nama warga yang ingin dihapus: ");
            inputString(&nm);

            List list;
            list.First = cursor->p;

            address P = Search(list, nm);
            
            if (P != NULL) {
                List *list;
                list->First = cursor->p;

                DelP(list, nm);
                printf(" Warga %s berhasil dihapus dari kota %s\n", nm, kt);
            } else {
                printf(" Warga %s tidak ditemukan di kota %s\n", nm, kt);
            }
            sleep(1);
            return;
        }

        cursor = cursor->next;
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

void printAllWarga(ListKota ListKota) {
    Kota *cursor = ListKota.First;
    int count = 0;
    while (cursor != NULL) {
        printf(" Kota: %s\n", cursor->kt);
        printWarga(*cursor);
        count++;
        cursor = cursor->next;
    }

    if (count == 0) {
        printf(" Tidak ada warga yang terdaftar.\n");
        sleep(1);
    }
    
    
    printf("\n");
}
