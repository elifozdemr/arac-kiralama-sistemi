#include <stdio.h>
#include <string.h>
char isim[30];
char soyIsim[30];
char plaka[10];
char marka[30];
struct arac {
    char isim[30];
    char soyIsim[30];
    char plaka[10];
    char marka[30];
};
void bilgileriAl() {
FILE* fptr;
    fptr=fopen("arac.txt","a");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Bilgileri giriniz;\t Isim:\n Soy Isim:\n Plaka:\n Marka:\n");
        scanf("%s %s %s %s",isim,soyIsim,plaka,marka);
        fprintf(fptr,"%s %s %s %s\n",isim,soyIsim,plaka,marka);
    }
    fclose(fptr);
}
void listele() {
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        while (fscanf(fptr,"%s %s %s %s",isim,soyIsim,plaka,marka)==4) {
            printf("Arac Listesi: %s %s %s %s\n",isim,soyIsim,plaka,marka);
        }
    }
    fclose(fptr);
}
void ara() {
    char arananPlaka[10];
    int bulundu=0;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Aranan mevcut playaki giriniz: ");
        scanf("%s",arananPlaka);
        while (fscanf(fptr,"%s %s %s %s",isim,soyIsim,plaka,marka)==4) {
            if (strcmp(arananPlaka,plaka)==0) {
                bulundu=1;
                printf("Aranan mevcut plaka bulundu\n");
                break;
            }
        }
        if (bulundu==0) {
            printf("Aranan mevcut plaka bulunamadi\n");
    }
}
    fclose(fptr);
}
void kirala() {
    char kiralaPlaka[10];
    int bulundu=0;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Kiralanacak mevcut playaki giriniz: ");
        scanf("%s",kiralaPlaka);
        while (fscanf(fptr,"%s %s %s %s",isim,soyIsim,plaka,marka)==4) {
            if (strcmp(kiralaPlaka,plaka)==0){
                bulundu=1;
                printf("Kiralanacak mevcut plaka bulundu ve kiralandi\n");
                break;
    }
}
        if (bulundu==0) {
            printf("Kirala mevcut plaka bulunamadi ve kiralanamdi\n");
        }
    }
        fclose(fptr);
    }
void kiralamaucreti() {
    int kiralamaucreti=0;
    int ucret;
    int gunSayisi;
    FILE* fptr;
    fptr=fopen("aracUcret.txt","w");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Arabayi kiralamak istediginiz gun sayisini giriniz: ");
        scanf("%d",&gunSayisi);
        if (gunSayisi<=2) {
            ucret=1000;
        }
        else if (gunSayisi<=4) {
            ucret=1300;
        }
        else {
            ucret=1600;
        }
        fprintf(fptr,"%s %s %s %s\n",isim,soyIsim,plaka,marka);
        fclose(fptr);
    }
    fptr=fopen("aracUcret.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        while (fscanf(fptr,"%s %s %s %s",isim,soyIsim,plaka,marka)==4) {
            kiralamaucreti=gunSayisi*ucret;
            printf("Kiralama ucreti %d'dir\n",kiralamaucreti);
        }
    }
    fclose(fptr);
}
void aracIade() {
    char arananIsim[30];
    int bulundu=0;
    FILE* fptr;
    fptr=fopen("arac.txt","r");
    if(fptr==NULL) {
        printf("Dosya basarisiz\n");
    }
    else {
        printf("Aranan mevcut ismi giriniz: ");
        scanf("%s",arananIsim);
        while (fscanf(fptr,"%s %s %s %s",isim,soyIsim,plaka,marka)==4) {
            if (strcmp(arananIsim,isim)==0) {
                bulundu=1;
                printf("Aranan mevcut isim bulundu ve iade edildi\n");
                break;
            }
        }
        if (bulundu==0) {
            printf("Aranan mevcut ismi bulunamadi ve iade edilemedi\n");
        }
        fclose(fptr);
    }
}
void cikis() {
    printf("Cikis yapildi\n");
}
int main() {
    int sec;
    do{
        printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("             Arac Kiralama Sistemi           \n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("1-Bilgileri Gir\n");
        printf("2-Listele\n");
        printf("3-Ara\n");
        printf("4-Kirala\n");
        printf("5-Kiralama Ucreti\n");
        printf("6-Arac İade Et\n");
        printf("7-Cikis\n");
        printf("1-7 arasinda bir secim yapiniz: ");
        scanf("%d",&sec);
        switch(sec) {
            case 1:bilgileriAl();
                break;
            case 2:listele();
                break;
            case 3:ara();
                break;
            case 4:kirala();
                break;
            case 5:kiralamaucreti();
                break;
            case 6:aracIade();
                break;
            case 7:cikis();
                break;
        }
    }while(sec!=7);
    return 0;
}