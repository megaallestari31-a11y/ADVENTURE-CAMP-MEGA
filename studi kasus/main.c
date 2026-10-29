#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TRANSAKSI 10
#define JUMLAH_PERALATAN 5

// Array data peralatan
char namaPeralatan[JUMLAH_PERALATAN][50] = {
    "Tenda Kapasitas 4 Orang",
    "Sleeping Bag",
    "Kompor Portable",
    "Matras Camping",
    "Lampu Camping"
};

int hargaPeralatan[JUMLAH_PERALATAN] = {
    50000,
    15000,
    20000,
    10000,
    12000
};

// Array untuk menyimpan riwayat transaksi
char namaPenyewa[MAX_TRANSAKSI][50];
int nomorPeralatan[MAX_TRANSAKSI];
int jumlahUnit[MAX_TRANSAKSI];
int lamaSewa[MAX_TRANSAKSI];
int totalPembayaran[MAX_TRANSAKSI];

int jumlahTransaksi = 0;

// Fungsi menampilkan daftar peralatan
void tampilkanPeralatan() {
    printf("\n========================================\n");
    printf("          DAFTAR PERALATAN\n");
    printf("========================================\n");

    for (int i = 0; i < JUMLAH_PERALATAN; i++) {
        printf("%d. %-30s Rp%d/hari\n",
               i + 1, namaPeralatan[i], hargaPeralatan[i]);
    }

    printf("========================================\n");
}

// Fungsi menghitung diskon
float hitungDiskon(int lama) {
    if (lama >= 5) {
        return 0.15;
    } else if (lama >= 3) {
        return 0.10;
    } else {
        return 0.0;
    }
}

// Fungsi melakukan penyewaan
void sewaPeralatan() {

    if (jumlahTransaksi >= MAX_TRANSAKSI) {
        printf("\nKapasitas transaksi sudah penuh.\n");
        printf("Tidak dapat menerima transaksi baru.\n");
        return;
    }

    int pilihan, jumlah, lama;
    int subtotal, diskon, total;
    float persentaseDiskon;

    printf("\n========================================\n");
    printf("          SEWA PERALATAN\n");
    printf("========================================\n");

    // Input nama penyewa
    printf("Nama Penyewa : ");
    scanf(" %[^\n]", namaPenyewa[jumlahTransaksi]);

    // Menampilkan peralatan
    tampilkanPeralatan();

    // Validasi nomor peralatan
    do {
        printf("Pilih nomor peralatan [1-5] : ");
        scanf("%d", &pilihan);

        if (pilihan < 1 || pilihan > JUMLAH_PERALATAN) {
            printf("Nomor peralatan tidak tersedia!\n");
        }

    } while (pilihan < 1 || pilihan > JUMLAH_PERALATAN);

    // Validasi jumlah unit
    do {
        printf("Jumlah unit : ");
        scanf("%d", &jumlah);

        if (jumlah < 1) {
            printf("Jumlah unit minimal 1!\n");
        }

    } while (jumlah < 1);

    // Validasi lama penyewaan
    do {
        printf("Lama penyewaan (hari) : ");
        scanf("%d", &lama);

        if (lama < 1) {
            printf("Lama penyewaan minimal 1 hari!\n");
        }

    } while (lama < 1);

    // Menghitung subtotal
    subtotal = hargaPeralatan[pilihan - 1] * jumlah * lama;

    // Menghitung diskon
    persentaseDiskon = hitungDiskon(lama);
    diskon = subtotal * persentaseDiskon;

    // Menghitung total pembayaran
    total = subtotal - diskon;

    // Menyimpan data transaksi
    nomorPeralatan[jumlahTransaksi] = pilihan - 1;
    jumlahUnit[jumlahTransaksi] = jumlah;
    lamaSewa[jumlahTransaksi] = lama;
    totalPembayaran[jumlahTransaksi] = total;

    jumlahTransaksi++;

    // Menampilkan struk
    printf("\n========================================\n");
    printf("          ADVENTURE CAMP\n");
    printf("           STRUK PENYEWAAN\n");
    printf("========================================\n");
    printf("Nama Penyewa   : %s\n", namaPenyewa[jumlahTransaksi - 1]);
    printf("Peralatan      : %s\n", namaPeralatan[pilihan - 1]);
    printf("Harga per Hari : Rp%d\n", hargaPeralatan[pilihan - 1]);
    printf("Jumlah Unit    : %d\n", jumlah);
    printf("Lama Sewa      : %d hari\n", lama);
    printf("----------------------------------------\n");
    printf("Subtotal       : Rp%d\n", subtotal);
    printf("Diskon (%.0f%%)   : Rp%d\n",
           persentaseDiskon * 100, diskon);
    printf("----------------------------------------\n");
    printf("TOTAL BAYAR    : Rp%d\n", total);
    printf("========================================\n");
    printf("Terima kasih telah menggunakan\n");
    printf("layanan Adventure Camp!\n");
    printf("========================================\n");
}

// Fungsi menampilkan riwayat transaksi
void tampilkanRiwayat() {

    if (jumlahTransaksi == 0) {
        printf("\nBelum ada transaksi penyewaan.\n");
        return;
    }

    int totalPendapatan = 0;

    printf("\n========================================\n");
    printf("          RIWAYAT TRANSAKSI\n");
    printf("========================================\n");

    printf("%-3s %-15s %-25s %-12s\n",
           "No", "Nama", "Peralatan", "Total");
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahTransaksi; i++) {

        printf("%-3d %-15s %-25s Rp%-10d\n",
               i + 1,
               namaPenyewa[i],
               namaPeralatan[nomorPeralatan[i]],
               totalPembayaran[i]);

        totalPendapatan += totalPembayaran[i];
    }

    printf("----------------------------------------\n");
    printf("Jumlah Transaksi : %d\n", jumlahTransaksi);
    printf("Total Pendapatan : Rp%d\n", totalPendapatan);
    printf("========================================\n");
}

// Fungsi menu utama
void tampilkanMenu() {
    printf("\n========================================\n");
    printf("          ADVENTURE CAMP\n");
    printf("     SISTEM PENYEWAAN PERALATAN\n");
    printf("========================================\n");
    printf("1. Lihat Daftar Peralatan\n");
    printf("2. Sewa Peralatan\n");
    printf("3. Lihat Riwayat Transaksi\n");
    printf("4. Keluar\n");
    printf("========================================\n");
}

// Fungsi utama
int main() {

    int pilihanMenu;

    do {
        tampilkanMenu();

        printf("Pilih menu [1-4] : ");
        scanf("%d", &pilihanMenu);

        switch (pilihanMenu) {

            case 1:
                tampilkanPeralatan();
                break;

            case 2:
                sewaPeralatan();
                break;

            case 3:
                tampilkanRiwayat();
                break;

            case 4:
                printf("\n========================================\n");
                printf("Terima kasih telah menggunakan\n");
                printf("sistem Adventure Camp!\n");
                printf("Program selesai.\n");
                printf("========================================\n");
                break;

            default:
                printf("\nPilihan menu tidak tersedia!\n");
                printf("Silakan pilih menu 1-4.\n");
        }

    } while (pilihanMenu != 4);

    return 0;
}
