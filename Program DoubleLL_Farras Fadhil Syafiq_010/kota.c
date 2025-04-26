#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked.h"
#include "utils.h"
#include "warga.h"
#include "kota.h"

void createEmptyKota(ListKota *ListKota) {
    ListKota->First = Nil;
}

void findKota(ListKota *listKota, char **temp) {
    printf(" List Kota: \n");
    printKota(*listKota);

    printf("======================================================\n");
    
    char *kt = NULL;
    
    if (*temp == NULL) {
        printf(" Masukkan nama kota yang ingin dicari: ");
        inputString(&kt);
    } else {
        kt = *temp;
    }
    
    addressKota cursor = listKota->First;

    while (cursor != NULL) {
        if (strcmp(cursor->kt, kt) == 0) {
            printf(" Kota %s ditemukan\n", kt);
            printWarga(*cursor);
            *temp = kt;
            return;
        }
        cursor = cursor->next;
    }
    

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void addKota(ListKota *listKota) {
    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);

    Kota *newKota = (Kota *)malloc(sizeof(Kota));
    if (newKota == NULL) {
        printf(" Gagal menambahkan kota\n");
        free(kt);
        return;
    }

    newKota->kt = kt;
    newKota->p = NULL;
    newKota->next = NULL;

    if (listKota->First == NULL) {
        listKota->First = newKota;
    } else {
        addressKota cursor = listKota->First;

        while (cursor->next != NULL) {
            cursor = cursor->next;
        }

        cursor->next = newKota;
    }

    printf(" Kota %s berhasil ditambahkan\n", kt);
    sleep(1);
}

void deleteKota(ListKota *listKota) {
    printf(" List Kota: \n");
    printKota(*listKota);

    printf("======================================================\n");

    char *kt = NULL;
    printf(" Masukkan nama kota yang ingin dihapus: ");
    inputString(&kt);

    addressKota cursor = listKota->First;
    Kota *prev = NULL;

    while (cursor != NULL) {
        if (strcmp(cursor->kt, kt) == 0) {
            if (prev == NULL) {
                listKota->First = cursor->next;
            } else {
                prev->next = cursor->next;
            }

            free(cursor->kt);

            listKota->First = cursor->next;

            free(cursor);
            printf(" Kota %s berhasil dihapus\n", kt);
            sleep(1);
            return;
        }
        prev = cursor;
        cursor = cursor->next;
    }

    printf(" Kota %s tidak ditemukan\n", kt);
    sleep(1);
}

void printKota(ListKota kota) {
    if (kota.First == NULL) {
        printf(" List Kota Kosong\n");
        return;
    }

    addressKota cursor = kota.First;

    int i = 1;
    while (cursor != NULL) {
        printf(" %d. %s\n", i, cursor->kt);
        cursor = cursor->next;
        i++;
    }
}
