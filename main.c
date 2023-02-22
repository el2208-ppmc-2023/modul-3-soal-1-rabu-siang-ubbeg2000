/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

int kembalianUang(int totalHarga, int pembayaran){
    int kembalian;
    kembalian = pembayaran - totalHarga;
    return kembalian;
}

int penghitungKembalian(int kembalian, int *seratus, int *limaPuluh, int *duaPuluh, int *sepuluh, int *lima, int *dua, int *satu, int *koin){
    while (kembalian != 0){
        if (kembalian >= 100000){
            *seratus += 1;
            kembalian -= 100000;
        }
        else if (kembalian >= 50000){
            *limaPuluh += 1;
            kembalian -= 50000;
        }
        else if (kembalian >= 20000){
            *duaPuluh += 1;
            kembalian -= 20000;
        }
        else if (kembalian >= 10000){
            *sepuluh += 1;
            kembalian -= 10000;
        }
        else if (kembalian >= 5000){
            *lima += 1;
            kembalian -= 5000;
        }
        else if (kembalian >= 2000){
            *dua += 1;
            kembalian -= 2000;
        }
        else if (kembalian >= 1000){
            *satu += 1;
            kembalian -= 1000;
        }
        else {
            *koin += 1;
            kembalian -= 1;
        }
    }
}

void printKembalian(int *seratus, int *limaPuluh, int *duaPuluh, int *sepuluh, int *lima, int *dua, int *satu, int *koin){
    if (*seratus != 0){
        printf("%d lembar uang 100.000\n", *seratus);
    }
    if (*limaPuluh != 0){
        printf("%d lembar uang 50.000\n", *limaPuluh);
    }
    if (*duaPuluh != 0){
        printf("%d lembar uang 20.000\n", *duaPuluh);
    }
    if (*sepuluh != 0){
        printf("%d lembar uang 10.000\n", *sepuluh);
    }
    if (*lima != 0){
        printf("%d lembar uang 5.000\n", *lima);
    }
    if (*dua != 0){
        printf("%d lembar uang 2.000\n", *dua);
    }
    if (*satu != 0){
        printf("%d lembar uang 1.000\n", *satu);
    }
    if (*koin != 0){
        printf("%d uang koin\n", *koin);
    }
}

int main(){
    printf("-- Program Penghitung Kembalian --\n\n");

    int seratus = 0;
    int limaPuluh = 0;
    int duaPuluh = 0;
    int sepuluh = 0;
    int lima = 0; 
    int dua = 0;
    int satu = 0;
    int koin = 0;
    int totalHarga, pembayaran, tambahBayar, kembalian;

    // input total harga barang
    printf("Masukkan total harga barang  : ");
    scanf("%d",&totalHarga);
    
    // input pembayaran
    printf("Masukkan pembayaran customer : ");
    scanf("%d",&pembayaran);

    // output kembalian [silahkan gunakan perkondisian]
    while (pembayaran < totalHarga){
        printf("Pembayaran tidak cukup!\n");
        printf("Masukkan tambahan pembayaran : ");
        scanf("%d",&tambahBayar);
        pembayaran += tambahBayar;
    }
    
    if (pembayaran == totalHarga){
        printf("Tidak ada kembalian!\n");
    }

    else {
        kembalian = kembalianUang(totalHarga, pembayaran);
        penghitungKembalian(kembalian, &seratus, &limaPuluh, &duaPuluh, &sepuluh, &lima, &dua, &satu, &koin);

        printf("Kembaliannya adalah\n");
        printKembalian(&seratus, &limaPuluh, &duaPuluh, &sepuluh, &lima, &dua, &satu, &koin);
    }

    return 0;
}
