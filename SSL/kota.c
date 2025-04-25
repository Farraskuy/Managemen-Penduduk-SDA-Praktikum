#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked.h"
#include "utils.h"
#include "warga.h"
#include "kota.h"

void createEmptyKota(ArrayKota *arrayKota) {
    arrayKota->kota = NULL;
    arrayKota->size = 0;
}

void findKota(ArrayKota *kota, char **temp) {
    char *kt = NULL;
    
    if (*temp == NULL) {
        printf(" Masukkan nama kota yang ingin dicari: ");
        inputString(&kt);
    } else {
        kt = *temp;
    }
    
    for (size_t i = 0; i < kota->size; i++) {
        if (strcmp(kota->kota[i].kt, kt) == 0) {
            printf(" Kota %s ditemukan\n", kt);
            printWarga(kota->kota[i]);
            *temp = kt;
            return;
        }
    }

    printf(" Kota %s tidak ditemukan.\n", kt);
    sleep(1);
}

void addKota(ArrayKota *kota) {
    char *kt = NULL;
    printf(" Masukkan nama kota: ");
    inputString(&kt);

    kota->kota = realloc(kota->kota, (kota->size + 1) * sizeof(Kota));
    if (kota->kota == NULL) {
        printf( "Memory allocation failed\n");
        return;
    }
    kota->kota[kota->size].kt = strdup(kt);
    kota->kota[kota->size].p = NULL;
    kota->size++;

    printf(" Kota %s berhasil ditambahkan\n", kt);
    sleep(1);
}

void updateKota(ArrayKota *kota) {
    char *kt = NULL;
    char *new_kt = NULL;

    printf(" Masukkan nama kota yang ingin diubah: ");
    inputString(&kt);
    
    printf(" Masukkan nama kota baru: ");
    inputString(&new_kt);

    for (size_t i = 0; i < kota->size; i++) {
        if (strcmp(kota->kota[i].kt, kt) == 0) {
            free(kota->kota[i].kt);
            kota->kota[i].kt = strdup(new_kt);
            break;
        }
    }
}

void deleteKota(ArrayKota *kota) {
    printf(" List Kota: \n");
    printKota(*kota);

    printf("======================================================\n");

    char *kt = NULL;
    printf(" Masukkan nama kota yang ingin dihapus: ");
    inputString(&kt);

    for (size_t i = 0; i < kota->size; i++) {
        if (strcmp(kota->kota[i].kt, kt) == 0) {
            free(kota->kota[i].kt);
            
            List list;
            list.First = kota->kota[i].p;
            DelAll(&list);
            kota->kota[i].p = NULL;

            for (size_t j = i; j < kota->size - 1; j++) {
                kota->kota[j] = kota->kota[j + 1];
            }
            kota->size--;
            kota->kota = realloc(kota->kota, kota->size * sizeof(Kota));
            break;
        }
    }
}

void printKota(ArrayKota kota) {
    for (size_t i = 0; i < kota.size; i++) {
        printf("%d. %s\n", i + 1, kota.kota[i].kt);
    }
}
