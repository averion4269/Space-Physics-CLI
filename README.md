# Space-Physics-CLI
# Uzay Fizik Simülasyonu (C Projesi)

Bu proje, Bursa Teknik Üniversitesi "Algoritmalar ve Programlama" dersi dönem ödevi olarak hazırlanmıştır. Güneş sistemindeki gezegenlerin yerçekimi verilerini kullanarak çeşitli fizik formüllerini simüle eden C tabanlı bir konsol uygulamasıdır.

## Öğrenci Bilgileri
* **Ad Soyad:** Hamza ÖZÜTÜRK
* **Öğrenci No:** 25360859334
* **UNIVERSITE:** BURSA TEKNIK UNIVERSITESI
* **Bölüm:** Bilgisayar Mühendisliği
* **Ders:** Algoritmalar ve Programlama

## Proje Hakkında
Program, kullanıcıdan alınan verileri pointer aritmetiği kullanarak işler ve Merkür'den Neptün'e kadar olan gezegenlerdeki sonuçları hesaplar.

### Özellikler
* Saf C dili ile geliştirilmiştir.
* Dizi erişimleri pointer aritmetiği (`*(ptr+i)`) ile yapılmıştır.
* Hatalı girişleri engellemek için güvenli input fonksiyonları kullanılmıştır.
* Negatif değer kontrolü Ternary operatörü ile sağlanmıştır.

### İçerdiği Deneyler
1. Serbest Düşme
2. Yukarı Atış
3. Ağırlık Hesaplama
4. Potansiyel Enerji
5. Hidrostatik Basınç
6. Kaldırma Kuvveti
7. Basit Sarkaç
8. İp Gerilmesi
9. Asansör Deneyi

## Nasıl Çalıştırılır?

Kodu derlemek ve çalıştırmak için terminalde şu komutları kullanabilirsiniz:

**Windows:**
```bash
gcc main.c -o main.exe
./main.exe
