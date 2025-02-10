#include <stdio.h>
#include <time.h>

struct TarihSaat {
    int yil, ay, gun, saat, dakika, saniye;
};


union Tarih {
    struct TarihSaat ts;
    time_t epoch;
};


time_t tarihiEpochCevir(struct TarihSaat ts) {
    struct tm tarih;
    
    tarih.tm_year = ts.yil - 1900; 
    tarih.tm_mon = ts.ay - 1;      
    tarih.tm_mday = ts.gun;
    tarih.tm_hour = ts.saat;
    tarih.tm_min = ts.dakika;
    tarih.tm_sec = ts.saniye;
    
    return mktime(&tarih);
}

int main() {
    union Tarih tarih1, tarih2;
    
 
    printf("1. Tarihi girin (YYYY AA GG SS DD SS): ");
    scanf("%d %d %d %d %d %d", &tarih1.ts.yil, &tarih1.ts.ay, &tarih1.ts.gun, 
                               &tarih1.ts.saat, &tarih1.ts.dakika, &tarih1.ts.saniye);

 
    printf("2. Tarihi girin (YYYY AA GG SS DD SS): ");
    scanf("%d %d %d %d %d %d", &tarih2.ts.yil, &tarih2.ts.ay, &tarih2.ts.gun, 
                               &tarih2.ts.saat, &tarih2.ts.dakika, &tarih2.ts.saniye);
    
    tarih1.epoch = tarihiEpochCevir(tarih1.ts);
    tarih2.epoch = tarihiEpochCevir(tarih2.ts);


    printf("\n1. Tarihin Epoch Zamani: %ld\n", tarih1.epoch);
    printf("2. Tarihin Epoch Zamani: %ld\n", tarih2.epoch);

   
    double fark = difftime(tarih2.epoch, tarih1.epoch);
    printf("\nÝki tarih arasindaki fark: %.0f saniye\n", fark);
    
    int gun = fark / (86400); 
    fark -= gun * (86400);     
    int saat = fark / (3600);      
    fark -= saat * (3600);         
    int dakika = fark / 60;           
    fark -= dakika * 60;             
    int saniye = fark;               

    printf("\nÝki tarih arasindaki fark: %d gün, %d saat, %d dakika, %d saniye\n", gun, saat, dakika, saniye);

    return 0;
}
