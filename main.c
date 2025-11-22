#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Türkçe karakter sorunu yaşamamak için locale.h eklenebilir
// Ancak en garantisi İngilizce karakter kullanmaktır, o yüzden
// çıktıları Türkçe ama karakterleri ASCII (ş, ı, ğ yok) tuttum.

int main() {
    // Rastgele sayılar için seed (tohum) oluşturuyoruz.
    srand(time(NULL));

    // 4. Durum Yönetimi: Değişkenlerin Tanımlanması [cite: 22]
    int saglik = 100;      // Sağlık (0-100) [cite: 23]
    int enerji = 100;      // Enerji (0-100) [cite: 24]
    int yemek = 0;         // Yemek Sayısı [cite: 25]
    int siginak = 0;       // Sığınak Durumu (0: Yok, 1: Var) [cite: 26]
    
    char komut;            // Kullanıcının gireceği komut

    printf("--- HAYATTA KALMA SIMULATORU ---\n");
    printf("Komutlar: [A]vlan, [S]iginak, [R]Dinlen, [E]nvanter, [F]Tehlike, [P]Engel, [X]Cikis\n");

    // 7. Ana Oyun Döngüsü (Do-While) 
    do {
        printf("\nBir komut giriniz (A, S, R, E, F, P, X): ");
        // scanf'ten önce boşluk bırakmak, önceki enter karakterini yutar.
        scanf(" %c", &komut);

        // Küçük harf girilirse büyüğe çevirelim (Kullanıcı dostu olması için)
        if(komut >= 'a' && komut <= 'z') {
            komut -= 32;
        }

        // 9. Komut Sistemi (Switch-Case) 
        switch (komut) {
            
            case 'A': // AVLANMA
                // 13. Avlanma mantığı (Enerji kontrolü ve Şans) 
                if (enerji >= 20) {
                    enerji -= 20; // Aritmetik işlem: Enerji azalır
                    printf("Avlanmaya ciktin... (Enerji -20)\n");
                    
                    // Rastgele sayı (0-99). %50 şans ile yemek bulma
                    int sans = rand() % 100; 
                    
                    // Mantıksal Operatörler (&&, ||) kullanımı
                    if (sans < 50) {
                        yemek++;
                        printf("BASARILI! Bir yemek buldun. (Yemek Sayisi: %d)\n", yemek);
                    } else {
                        printf("BASARISIZ! Hicbir sey bulamadin.\n");
                    }
                } else {
                    printf("UYARI: Avlanmak icin yeterli enerjin yok! (Gereken: 20, Mevcut: %d)\n", enerji);
                }
                break;

            case 'S': // SIĞINAK ARAMA
                // 14. Sığınak ihtimali (If-Else) [cite: 14]
                if (siginak == 1) {
                    printf("Zaten guvenli bir siginagin var.\n");
                } else {
                    printf("Siginak ariyorsun...\n");
                    if (enerji >= 10) {
                        enerji -= 10;
                        // %40 şansla sığınak bulma
                        if (rand() % 100 < 40) {
                            siginak = 1;
                            printf("TEBRIKLER! Guvenli bir siginak buldun.\n");
                        } else {
                            printf("Maalesef uygun bir yer bulamadin.\n");
                        }
                    } else {
                        printf("Aramak icin cok yorgunsun.\n");
                    }
                }
                break;

            case 'E': // ENVANTER GÖRÜNTÜLEME
                printf("\n--- DURUM RAPORU ---\n");
                printf("Saglik : %d\n", saglik);
                printf("Enerji : %d\n", enerji);
                printf("Yemek  : %d\n", yemek);
                printf("Siginak: %s\n", siginak == 1 ? "VAR" : "YOK");
                break;

            case 'R': // DİNLENME
                // Sığınak varsa daha iyi dinlenilir (Ekstra mantık)
                printf("Dinleniyorsun...\n");
                
                // Aritmetik işlemlerle artış [cite: 14]
                int enerjiArtis = (siginak == 1) ? 40 : 20; // Sığınak varsa +40, yoksa +20
                int saglikArtis = 10;

                enerji += enerjiArtis;
                saglik += saglikArtis;

                // 100 sınırını aşmamak için kontrol
                if(enerji > 100) enerji = 100;
                if(saglik > 100) saglik = 100;

                printf("Dinlendin. Enerji +%d, Saglik +%d\n", enerjiArtis, saglikArtis);
                break;

            case 'F': // TEHLİKE (FOR DÖNGÜSÜ)
                // 17. "Tehlike Dalgası" Simülasyonu [cite: 17]
                printf("\n!!! TEHLIKE DALGASI BASLADI !!!\n");
                
                // 16. For döngüsü ile 3 dalga saldırı [cite: 16]
                for (int i = 1; i <= 3; i++) {
                    int hasar = rand() % 15 + 5; // 5 ile 20 arası hasar
                    saglik -= hasar;
                    printf("%d. Dalga Saldiri: %d hasar aldin! (Kalan Saglik: %d)\n", i, hasar, saglik);
                    
                    if (saglik <= 0) {
                        printf("Saldiri sirasinda hayatini kaybettin...\n");
                        break; // Döngüyü kır
                    }
                }
                break;

            case 'P': // ŞİFRELİ İLERLEME (DO-WHILE)
                // 20. Engel aşma döngüsü 
                {
                    int girilenSifre;
                    int dogruSifre = 1234;
                    printf("\nKarsina kilitli bir kapi cikti. Gecmek icin sifreyi cozmelisin!\n");
                    
                    do {
                        printf("Sifreyi giriniz (Ipucu: 1234): ");
                        scanf("%d", &girilenSifre);
                        
                        if (girilenSifre != dogruSifre) {
                            printf("Hatali sifre! Tekrar dene.\n");
                        }
                    } while (girilenSifre != dogruSifre);
                    
                    printf("Sifre Dogru! Kapi acildi ve engeli astin.\n");
                }
                break;

            case 'X': // ÇIKIŞ
                printf("Simulasyondan cikiliyor...\n");
                break;

            default:
                printf("Gecersiz komut! Lutfen tekrar deneyin.\n");
        }

        // Oyun Bitiş Kontrolü (Sağlık 0 ise)
        if (saglik <= 0) {
            printf("\n--- OYUN BITTI ---\n");
            printf("Sagliginiz tukendi ve hayatta kalamadiniz.\n");
            break; // Ana döngüyü kırar ve programı sonlandırır
        }

    } while (komut != 'X'); // 7. Çıkış komutu verilmedikçe devam et 

    printf("Program sonlandi.\n");
    return 0;
}
