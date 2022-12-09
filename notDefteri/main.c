#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void yeni()
{

    char dosyaAdi[32];
    char ch;
    int secim1;
    char metin[2048];
    system("cls");
    printf("***Yeni Not Defteri belgesi olustuma islemi baslatiliyor...\n");
    sleep(2);
    printf("-Dosyaya bir isim veriniz:");
    scanf("%s",dosyaAdi);

    FILE *ptr = fopen(dosyaAdi,"w");

    if(ptr != NULL)
    {
        printf("\t***%s isimli dosya olusturuldu.***\n",dosyaAdi);
        sleep(2);
bas :
        printf("\n1- Metin ekle\n");
        printf("2- Dosya icerigini goster\n");
        printf("3- Dosya icerigini sil\n");
        printf("4- Ana menuye don\n");
        printf("Seciminizi giriniz:");
        scanf("%d",&secim1);
        if(secim1==1)
        {
            system("cls");
            printf("Metin giriniz:");
            scanf("%s[^\n]",&metin);
            ptr=fopen(dosyaAdi,"a");
            fprintf(ptr,"%s ",metin);
            fclose(ptr);
            printf("Metin ekleme tamamlandi.\n");

        }
        else if(secim1==2)
        {

            ptr=fopen(dosyaAdi,"r");
            system("cls");
            printf("\tDosya icerigi gosteriliyor...\n\n");
            while(!feof(ptr))
            {
                ch=fgetc(ptr);
                printf("%c",ch);
            }
            fclose(ptr);
        }

        else if(secim1==3)
        {

            ptr=fopen(dosyaAdi,"w");
            fclose(ptr);
            system("cls");
            sleep(2);
            printf("\t Dosya icerigi temizlendi\n");
        }

        else if(secim1==4)
        {
            system("cls");
            fclose(ptr);
            return 0;
        }
        else
        {
            system("cls");
            fclose(ptr);
            printf("Hatali bir tuslama yaptiniz!\n");
        }
        goto bas;

    }
    else
    {
        printf("Dosya olusturulamadi!\n");
    }



}

void ac() /// AÇ KONTROL ET !
{
    char dosyaAdi[32];
    char ch;
    int secim1;
    char metin[2048];
    system("cls");
    printf("\t***Dosya acma sayfasi aciliyor...***\n");
    sleep(2);
    printf("Acmak istediginiz dosya :");
    scanf("%s",dosyaAdi);
    FILE *ptr=fopen(dosyaAdi,"r");
    if(ptr!=NULL)
    {
        printf("\t%s isimli dosya acildi.\n",dosyaAdi);
        sleep(2);
        bas :
        printf("\n1- Metin ekle\n");
        printf("2- Dosya icerigini goster\n");
        printf("3- Dosya icerigini sil\n");
        printf("4- Ana menuye don\n");
        printf("Seciminizi giriniz:");
        scanf("%d",&secim1);
        if(secim1==1)
        {
            system("cls");
            printf("Metin giriniz:");
            scanf(" %s[^\n]",&metin);
            ptr=fopen(dosyaAdi,"a");
            fprintf(ptr,"%s ",metin);
            fclose(ptr);
            printf("Metin ekleme tamamlandi.\n");

        }
        else if(secim1==2)
        {

            ptr=fopen(dosyaAdi,"r");
            system("cls");
            printf("\tDosya icerigi gosteriliyor...\n");
            while(!feof(ptr))
            {
                ch=fgetc(ptr);
                printf("%c",ch);
            }
            fclose(ptr);
        }

        else if(secim1==3)
        {

            ptr=fopen(dosyaAdi,"w");

            fclose(ptr);
            system("cls");
            printf("\t Dosya icerigi temizlendi\n");
        }

        else if(secim1==4)
        {

            system("cls");

            fclose(ptr);
            return 0;
        }
        else
        {
            system("cls");
            fclose(ptr);
            printf("Hatali bir tuslama yaptiniz!\n");
        }
        goto bas;

    }
    else
    {
        system("cls");
        printf("\tAcmak istediginiz %s isimli dosya bulunamadi!\n",dosyaAdi);
    }



}

int menu()
{
    printf("\tNOT DEFTERI\n");
    int secim;
    printf("\n1- Yeni not defteri belgesi olustur \n");
    printf("2- Not defterini ac\n");
    printf("0- Cikis\n");
    sleep(1);
    printf("Seciminizi giriniz:");
    scanf("%d",&secim);

    return secim;
}


int main()
{
    int secim=menu();
    while(secim!=0)
    {
        switch (secim)
        {
        case 1:
            yeni();
            break;

        case 2:
            ac();

        case 0:
            break;

        default:
            printf("Hatali secim yaptiniz!!\n");


        }
        secim=menu();

    }
}
