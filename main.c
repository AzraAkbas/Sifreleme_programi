#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strlen fonksiyonunu kullanabilmek için gerekli kütüphane
#include <ctype.h>//isalpha fonksiyonunu kullanabilmek için gerekli kütüphane

void sifrele(char *metin1, int anahtar1) {
    int boyut1 = strlen(metin1);
    int i;
//Burada karakterlerin harf olup olmadýðýný ve büyük harf olup olmadýðý  kontrol eden eðer harf büyükse küçük harfe çeviren daha sonra þifreleyen bir fonksiyon tanýmladým
    for (i = 0; i < boyut1; i++) {
        char harf1 = metin1[i];
        if (isalpha(harf1)) {

            char taban1 = isupper(harf1) ? 'A' : 'a';//Normalde sadece isupper kullanmak yeterli ama akýþ þemasýnda tolower kullanýldýðý için ikisini de kullandým.
            metin1[i] = tolower(taban1 + (harf1 - taban1 + anahtar1) % 26);
        }
    }
}
//Þifrelenmiþ dosyayý deþifre etmek için ayný mantýkta bir fonksiyon tanýmladým
void desifrele(char *metin2, int anahtar2) {
    int boyut2 = strlen(metin2);
    int i;

    for (i = 0; i < boyut2; i++) {
        char harf2 = metin2[i];
        if (isalpha(harf2)) {

            char taban2 = isupper(harf2) ? 'A' : 'a';
            metin2[i] = tolower(taban2 + (harf2 - taban2 - anahtar2 + 26) % 26);
        }
    }
}

int main() {
	//Gerekli uyarýlar
	printf("!Input.txt isimli dosya kodun bulundugu main dosyasiyla ayni konumda bulunmalidir!\n");
    printf("Bu program kodun calistigi klasorde bulunan input.txt isimli dosyayi sifreli ve desifreli bir sekilde yine ayni klasore kaydeder\n");
    printf("Sifreleme algoritmasina gore bazi sifrelenmis kelimeler:\n");
    printf("hello= khoor\n");
    printf("exit= halw\n");
    printf("music= pxvlf\n");
    printf("Sifreli dosyayi 'sifrelenmis_input.txt' isminde input.txt dosyasiyla ayni klasorun icine kaydeder\n");
    printf("Desifrelenmis dosyayi 'desifrelenmis_input.txt' isminde input.txt dosyasiyla ayni klasorun icine kaydeder\n");
    
    FILE *anaDosya, *sifre, *desifre; //Dosyalarý tanýmladým
    char dosyaAdi[] = "input.txt";  //Dosya adý
    char satir[1000]; //Maksimum satýr sayýsýný tanýmladým
    int anahtar = 3;  //Anahtar miktarýný belirledim
//Ana dosyada bir hata olmasý halinde çalýþacak kod
    anaDosya = fopen(dosyaAdi, "r");
    if (anaDosya == NULL) {
        perror("Dosyada bir hata olustu");
        return 1;
    }
//Dosyanýn þifreli halini yeniden kaydeden kod
    sifre = fopen("sifrelenmis_input.txt", "w");
    while (fgets(satir, sizeof(satir), anaDosya) != NULL) {
        sifrele(satir, anahtar);
        fputs(satir, sifre);
    }
//Açýk olan dosyalarý kapatmak için olan kod
    fclose(anaDosya);
    fclose(sifre);
//Þifrelenmiþ dosyada bir hata olmasý halinde çalýþacak kod
    sifre = fopen("sifrelenmis_input.txt", "r");
    if (sifre == NULL) {
        perror("Sifrelenmis dosyada bir hata olustu\n");
        return 1;
    }
//Dosyanýn deþifreli halini yeniden kaydeden kod    
    desifre = fopen("desifrelenmis_input.txt", "w");
    while (fgets(satir, sizeof(satir), sifre) != NULL) {
        desifrele(satir, anahtar);
        fputs(satir, desifre);
    }
//Açýk olan dosyalarý kapatmak için olan kod
    fclose(sifre);
    fclose(desifre);
//Deþifrelenmiþ dosyada bir hata olmasý halinde çalýþacak kod    
    desifre = fopen("desifrelenmis_input.txt", "r");
    if (desifre == NULL) {
        perror("Desifrelenmis dosyada bir hata olustu\n");
        return 1;
    }
//Ýþlemin baþarýyla tamamlandýðýný gösteren kod
    printf("Sifreleme ve desifreleme islemleri basariyla yapildi.\n");

    return 0;
}

