#include <stdio.h>
#include <stdlib.h>
#include <string.h>//strlen fonksiyonunu kullanabilmek i�in gerekli k�t�phane
#include <ctype.h>//isalpha fonksiyonunu kullanabilmek i�in gerekli k�t�phane

void sifrele(char *metin1, int anahtar1) {
    int boyut1 = strlen(metin1);
    int i;
//Burada karakterlerin harf olup olmad���n� ve b�y�k harf olup olmad���  kontrol eden e�er harf b�y�kse k���k harfe �eviren daha sonra �ifreleyen bir fonksiyon tan�mlad�m
    for (i = 0; i < boyut1; i++) {
        char harf1 = metin1[i];
        if (isalpha(harf1)) {

            char taban1 = isupper(harf1) ? 'A' : 'a';//Normalde sadece isupper kullanmak yeterli ama ak�� �emas�nda tolower kullan�ld��� i�in ikisini de kulland�m.
            metin1[i] = tolower(taban1 + (harf1 - taban1 + anahtar1) % 26);
        }
    }
}
//�ifrelenmi� dosyay� de�ifre etmek i�in ayn� mant�kta bir fonksiyon tan�mlad�m
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
	//Gerekli uyar�lar
	printf("!Input.txt isimli dosya kodun bulundugu main dosyasiyla ayni konumda bulunmalidir!\n");
    printf("Bu program kodun calistigi klasorde bulunan input.txt isimli dosyayi sifreli ve desifreli bir sekilde yine ayni klasore kaydeder\n");
    printf("Sifreleme algoritmasina gore bazi sifrelenmis kelimeler:\n");
    printf("hello= khoor\n");
    printf("exit= halw\n");
    printf("music= pxvlf\n");
    printf("Sifreli dosyayi 'sifrelenmis_input.txt' isminde input.txt dosyasiyla ayni klasorun icine kaydeder\n");
    printf("Desifrelenmis dosyayi 'desifrelenmis_input.txt' isminde input.txt dosyasiyla ayni klasorun icine kaydeder\n");
    
    FILE *anaDosya, *sifre, *desifre; //Dosyalar� tan�mlad�m
    char dosyaAdi[] = "input.txt";  //Dosya ad�
    char satir[1000]; //Maksimum sat�r say�s�n� tan�mlad�m
    int anahtar = 3;  //Anahtar miktar�n� belirledim
//Ana dosyada bir hata olmas� halinde �al��acak kod
    anaDosya = fopen(dosyaAdi, "r");
    if (anaDosya == NULL) {
        perror("Dosyada bir hata olustu");
        return 1;
    }
//Dosyan�n �ifreli halini yeniden kaydeden kod
    sifre = fopen("sifrelenmis_input.txt", "w");
    while (fgets(satir, sizeof(satir), anaDosya) != NULL) {
        sifrele(satir, anahtar);
        fputs(satir, sifre);
    }
//A��k olan dosyalar� kapatmak i�in olan kod
    fclose(anaDosya);
    fclose(sifre);
//�ifrelenmi� dosyada bir hata olmas� halinde �al��acak kod
    sifre = fopen("sifrelenmis_input.txt", "r");
    if (sifre == NULL) {
        perror("Sifrelenmis dosyada bir hata olustu\n");
        return 1;
    }
//Dosyan�n de�ifreli halini yeniden kaydeden kod    
    desifre = fopen("desifrelenmis_input.txt", "w");
    while (fgets(satir, sizeof(satir), sifre) != NULL) {
        desifrele(satir, anahtar);
        fputs(satir, desifre);
    }
//A��k olan dosyalar� kapatmak i�in olan kod
    fclose(sifre);
    fclose(desifre);
//De�ifrelenmi� dosyada bir hata olmas� halinde �al��acak kod    
    desifre = fopen("desifrelenmis_input.txt", "r");
    if (desifre == NULL) {
        perror("Desifrelenmis dosyada bir hata olustu\n");
        return 1;
    }
//��lemin ba�ar�yla tamamland���n� g�steren kod
    printf("Sifreleme ve desifreleme islemleri basariyla yapildi.\n");

    return 0;
}

