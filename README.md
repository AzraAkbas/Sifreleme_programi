# Şifreleme ve Deşifreleme Uygulaması

C dilinde,Dev-c++ uygulamasında yazılan bu uygulama kodun çalıştığı klasörde bulunan “input.txt” isimli dosyayı şifreli ve deşifreli bir şekilde yine aynı klasöre kaydeder.

## Kullanılan Algoritma

Uygulamada şifreleme ve deşifreleme işlemleri için basit bir Caesar Cipher/Shift Cipher algoritması kullanır. Her harfi belirli bir anahtar (kaydırma miktarı) kadar ileri veya geri kaydırarak şifreleme ve deşifre etme işlemlerini gerçekleştirir. Bu kodda anahtar değer “3” olarak belirlenmiştir

# Kullanım

Uygulamayı kullanabilmek için öncelikle kodun yazılı olduğu main dosyasıyla şifrelenecek dosya aynı konumda bulunmalıdır. Sonrasında programı derleyip çalıştırmanız yeterlidir. Program, input.txt dosyasını şifreleyecek, şifrelenmiş halini “sifrelenmis_input.txt” dosyasına kaydedecek ve ardından deşifreleyerek “desifrelenmis_input.txt” dosyasına kaydedecektir. Şifreli ve deşifreli dosyalar input.txt dosyasıyla aynı konuma kaydolur.
+ Kodu çalıştırdığınızda alabileceğiniz uyarılar;
- Şifreleme ve deşifreleme işlemleri başarıyla yapıldı: İşlemin başarıyla tamamlandığını gösterir.
- Dosyada bir hata oluştu: Ana dosyada bir hata olduğunu gösterir.
- Şifrelenmiş dosyada bir hata oluştu: Şifrelenmiş dosyada bir hata olduğunu gösterir.
- Deşifrelenmiş dosyada bir hata oluştu: Deşifrelenmiş dosyada bir hata olduğunu gösterir.

# Örnek Ekran Çıktısı

Şifreleme algoritmasına göre bazı şifrelenmiş kelime örnekleri verecek olursak;
- hello= khoor
- flower= iorzhu
- music= pxvlf
- happy= kdssb
- exit= halw

# Notlar

- Eğer ismi input.txt olmayan bir dosyayı şifrelemek istiyorsanız 
    char dosyaAdi[] = "input.txt";
burada bulunan input.txt yerine şifrelemek istediğiniz metin dosyasının adını yazmalısınız.
- Eğer kaydırma değerini değiştirmek istiyorsanız 
    int anahtar = 3;
burada bulunan anahtar değerini değiştirmeniz yeterlidir.
- Şifrelemek istediğiniz dosya kodun yazılı olduğu main dosyasıyla aynı konumda bulunmalıdır.

