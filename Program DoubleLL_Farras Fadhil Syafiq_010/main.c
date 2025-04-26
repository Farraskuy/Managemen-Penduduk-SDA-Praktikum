#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "kota.h"
#include "warga.h"


int main(int argc, char *argv[]) {
    boolean finished = false;
    char *temp = NULL;
    ListKota kota;    
    
    createEmptyKota(&kota);

    int choice = 0;

    do {
        system("cls||clear");

        printf("======================================================\n");
        printf("            Penduduk Management System                \n");
        printf("======================================================\n");
        printf("======================================================\n");
        
        if (choice == 0) {
            printf(" List Kota: \n");

            printKota(kota);

            printf("======================================================\n");
            printf(" Avaliable Menu: \n");
            printf(" (1) Tambah Kota \n");
            printf(" (2) Delete Kota \n");
            printf(" (3) Tambah Warga\n");
            printf(" (4) Delete Warga\n");
            printf(" (5) Lihat Seluruh Warga\n");
            printf(" (6) Lihat Warga Dalam Kota\n");
            printf(" (7) Exit \n");
        }

        if (choice == 1) {
            addKota(&kota);
            finished = true;
        }  

        if (choice == 2) {
            deleteKota(&kota);
            finished = true;
        }
        
        if (choice == 3) {
            addWarga(&kota);
            finished = true;
        }
        
        if (choice == 4) {
            deleteWarga(&kota);
            finished = true;
        }

        if (choice == 5) {
            printAllWarga(kota);

            printf("======================================================\n");
            printf(" Avaliable Menu: \n");
            printf(" (1) Kembali \n");
            printf("======================================================\n");
            printf(" Select Menu (Input With Keyboard): ");
            scanf("%d", &choice);
            getchar();

            if (choice == 1) {
               finished = true;
               free(temp);
               temp = NULL;
            }

            if (choice > 1 || choice < 1) {
                choice = 1;
            }
        }
        
        if (choice == 6) {
            findKota(&kota, &temp);

            printf("======================================================\n");
            printf(" Avaliable Menu: \n");
            printf(" (1) Kembali \n");
            printf("======================================================\n");
            printf(" Select Menu (Input With Keyboard): ");
            scanf("%d", &choice);
            getchar();

            if (choice == 1) {
               finished = true;
               free(temp);
               temp = NULL;
            }

            if (choice > 1 || choice < 1) {
                choice = 2;
            }
        }

        if (choice == 7) {
            int counter = 5;
            while (counter > 0) {
                system("cls||clear");
                printf("======================================================\n");
                printf("      Terima Kasih Telah Menggunakan Program Ini      \n");
                printf("======================================================\n");
                printf(" Keluar aplikasi dalam 5 detik ...\n");
                sleep(1);
            }
            exit(0);

            break;
        }

        printf("\n======================================================\n");

        if (finished) {
            choice = 0;
            finished = false;
            continue;
        }

        if (choice > 0) {
            continue;
        }
        
        printf(" Select Menu (Input With Keyboard): ");
        scanf("%d", &choice);
        getchar();
        printf("======================================================\n");
    } while (1);

	return 0;
}
