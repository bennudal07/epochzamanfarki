#include <stdio.h>
#include <time.h>

struct TarihSaat {
    int yil, ay, gun, saat, dakika, saniye;
};

time_t tarihiEpochCevir(struct TarihSaat t) {
    struct tm tarih = {0};
    tarih.tm_year = t.yil - 1900;
    tarih.tm_mon = t.ay - 1;
    tarih.tm_mday = t.gun;
    tarih.tm_hour = t.saat;
    tarih.tm_min = t.dakika;
    tarih.tm_sec = t.saniye;
    
    return mktime(&tarih);
}

int main() {
    struct TarihSaat randevu;
    time_t suan, randevu_tarihi;
    
    time(&suan);
    
  
    printf("Randevu tarihini gir (YYYY AA GG SS DD SS): ");
    scanf("%d %d %d %d %d %d", &randevu.yil, &randevu.ay, &randevu.gun, 
                               &randevu.saat, &randevu.dakika, &randevu.saniye);
    
    randevu_tarihi = tarihiEpochCevir(randevu);
    
    double fark = difftime(randevu_tarihi, suan);
    
    int kalanGun = fark/ 86400;
    int kalanSaat = ((int)fark % 86400) / 3600;
    int kalanDakika = ((int)fark % 3600) / 60;
    

    if (fark > 0) {
        printf("\nRandevunuz kalan sUre: %d g�n, %d saat, %d dakika \n", 
               kalanGun, kalanSaat, kalanDakika);
    } else {
        kalanGun = fark / 86400;
        kalanSaat = ((int)fark % 86400) / 3600;
        kalanDakika = ((int)fark % 3600) / 60;
        printf("\nRandevunuz %d g�n, %d saat, %d dakika onceydi! \n", 
               kalanGun, kalanSaat, kalanDakika);
    }

    return 0;
}
