#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define PLANET_COUNT 8
#define PI 3.14159

/* FONKSIYON PROTOTIPLERI */
double input_kontrol(double val);
double sayi_al(char *input); //  sadece sayi alma fonksiyonu

void menu_goster();
void serbest_dusme(double *g_ptr, char **isim_ptr);
void yukari_atis(double *g_ptr, char **isim_ptr);
void agirlik_hesapla(double *g_ptr, char **isim_ptr);
void potansiyel_enerji(double *g_ptr, char **isim_ptr);
void hidrostatik_basinc(double *g_ptr, char **isim_ptr);
void arsimet_kaldirma(double *g_ptr, char **isim_ptr);
void basit_sarkac(double *g_ptr, char **isim_ptr);
void ip_gerilmesi(double *g_ptr, char **isim_ptr);
void asansor_deneyi(double *g_ptr, char **isim_ptr);

int main() {
    double g_values[PLANET_COUNT] = {3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};                           //yercekimi ivmesi degerleri
    char *p_names[PLANET_COUNT] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};   //gunese en yakın olmasına gore gezegenler

    char bilim_insani[50];
    int secim = 0;

    printf("==========================================\n");
    printf("    UZAY SIMULASYONUNA HOS GELDINIZ    \n");
    printf("==========================================\n");
    printf("Bilim Insani Adi Soyadi: ");
    fgets(bilim_insani, sizeof(bilim_insani), stdin);
    bilim_insani[strcspn(bilim_insani, "\n")] = 0;     //enter tusu girilene kadar ismi alır

    printf("\nHos geldin, Sayin %s. Sistemler yukleniyor...\n", bilim_insani);

    while (secim != -1) {
        menu_goster();

        double girilen = sayi_al("Deney Seciniz (-1 Cikis): ");
        secim = (int)girilen;

        if (secim == -1) {
            printf("\nSimulasyon sonlandiriliyor. Iyi gunler Sayin %s.\n", bilim_insani);
            break;
        }

        switch (secim) {
            case 1: serbest_dusme(g_values, p_names);
             break;
            case 2: yukari_atis(g_values, p_names);
             break;
            case 3: agirlik_hesapla(g_values, p_names);
             break;
            case 4: potansiyel_enerji(g_values, p_names);
             break;
            case 5: hidrostatik_basinc(g_values, p_names);
             break;
            case 6: arsimet_kaldirma(g_values, p_names);
             break;
            case 7: basit_sarkac(g_values, p_names);
             break;
            case 8: ip_gerilmesi(g_values, p_names);
             break;
            case 9: asansor_deneyi(g_values, p_names);
            break;
            default: printf(">> Hatali secim! Lutfen menudeki numaralardan birini girin.\n");
        }
    }

    return 0;
}
double sayi_al(char *input) {
    double sayi;
    int kontrol; // scanf basarili mi(1: Evet, 0: Hayir)

    do {
        printf("%s", input);
        kontrol = scanf("%lf", &sayi);

        if (kontrol != 1) {
            printf(">> HATA: Harf girdiniz! Lutfen sayi giriniz.\n");
            while(getchar() != '\n');
        }

    } while (kontrol != 1); // Sayi girilene kadar sormaya devam et
      return sayi;
}

double input_kontrol(double val) {  // Negatif kontrolü (Ternary ile)
    return (val < 0) ? -val : val;
}

void menu_goster() {
    printf("\n--- DENEY LISTESI ---\n");
    printf("1. Serbest Dusme (h)\n");
    printf("2. Yukari Atis (h_max)\n");
    printf("3. Agirlik (G)\n");
    printf("4. Potansiyel Enerji (Ep)\n");
    printf("5. Hidrostatik Basinc (P)\n");
    printf("6. Arsimet Kaldirma Kuvveti (Fk)\n");
    printf("7. Basit Sarkac (Periyot)\n");
    printf("8. Ip Gerilmesi (T)\n");
    printf("9. Asansor Deneyi (N)\n");
    printf("---------------------\n");
}

// DENEY FONKSIYONLARI

void serbest_dusme(double *g_ptr, char **isim_ptr) {  //serbest dusme fonksiyonu
    double t = sayi_al("Dusus suresi (sn): ");
    t = input_kontrol(t);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "DUSUS MESAFESI");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double h = 0.5 * g * pow(t, 2);
        printf("%-10s | %.2f Metre\n", isim, h);
    }
}

void yukari_atis(double *g_ptr, char **isim_ptr) {    // yukarı atıs fonksiyonu
    double v0 = sayi_al("Ilk Hiz (m/s): ");
    v0 = input_kontrol(v0);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "MAX YUKSEKLIK");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double h_max = pow(v0, 2) / (2 * g);
        printf("%-10s | %.2f Metre\n", isim, h_max);
    }
}

void agirlik_hesapla(double *g_ptr, char **isim_ptr) {       // agirlik hesaplama fonksiyonu
    double m = sayi_al("Cisim Kutlesi (kg): ");
    m = input_kontrol(m);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "AGIRLIK");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double G = m * g;
        printf("%-10s | %.2f Newton\n", isim, G);
    }
}

void potansiyel_enerji(double *g_ptr, char **isim_ptr) {      // potansiyel enerji hesaplama fonksiyonu
    double m = sayi_al("Kutle (kg): ");
    m = input_kontrol(m);
    double h = sayi_al("Yukseklik (m): ");
    h = input_kontrol(h);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "KUTLE CEKIMSEL POTANSIYEL ENERJI");
    printf("---------------------------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double Ep = m * g * h;
        printf("%-10s | %.2f Joule\n", isim, Ep);
    }
}

void hidrostatik_basinc(double *g_ptr, char **isim_ptr) {      // hidrostatik basýnç hesaplama fonksiyonu
    double rho = sayi_al("Sivi Yogunlugu (kg/m^3): ");
    rho = input_kontrol(rho);
    double h = sayi_al("Derinlik (m): ");
    h = input_kontrol(h);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "HIDROSTATIK BASINC");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double P = rho * g * h;
        printf("%-10s | %.2f Pascal\n", isim, P);
    }
}

void arsimet_kaldirma(double *g_ptr, char **isim_ptr) {           // arþimet kaldýrma deneyi fonksiyonu
    double rho = sayi_al("Sivi Yogunlugu (kg/m^3): ");
    rho = input_kontrol(rho);
    double V = sayi_al("Batan Hacim (m^3): ");
    V = input_kontrol(V);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "KALDIRMA KUVVETI");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double Fk = rho * g * V;
        printf("%-10s | %.2f Newton\n", isim, Fk);
    }
}

void basit_sarkac(double *g_ptr, char **isim_ptr) {              //basit sarkaç periyodu hesaplama fonksiyonu
    double L = sayi_al("Ip Uzunlugu (m): ");
    L = input_kontrol(L);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "SARKAC PERIYODU (SURE)");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double T = 2 * PI * sqrt(L / g);
        printf("%-10s | %.2f Saniye\n", isim, T);
    }
}

void ip_gerilmesi(double *g_ptr, char **isim_ptr) {              // sabit ip gerilimi hesaplama fonksiyonu
    double m = sayi_al("Asili Kutle (kg): ");
    m = input_kontrol(m);

    printf("\n%-10s | %-15s\n", "GEZEGEN", "IP GERILME KUVVETI");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double T = m * g;
        printf("%-10s | %.2f Newton\n", isim, T);
    }
}

void asansor_deneyi(double *g_ptr, char **isim_ptr) {
    double m = sayi_al("Kutle (kg): ");
    m = input_kontrol(m);

    double a = sayi_al("Asansor Ivmesi (m/s^2): ");
    a = input_kontrol(a);

    double girilen = sayi_al("Yon (1: Yukari, 0: Asagi): ");
    int yon = (int)girilen;

    if (yon != 1 && yon != 0) {
        printf(">> HATA: Sadece 1 veya 0 girebilirsiniz! Deney iptal edildi.\n");
        return;
    }
    printf("\n%-10s | %-15s\n", "GEZEGEN", "ETKIN AGIRLIK");
    printf("-----------------------------\n");

    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        char *isim = *(isim_ptr + i);
        double N;

        if (yon == 1) {
            N = m * (g + a);
        } else {
            N = m * (g - a);
        }
        printf("%-10s | %.2f Newton\n", isim, N);
    }
}
