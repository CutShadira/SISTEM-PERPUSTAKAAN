#ifndef MODELS_H // if not defined, Jika belum didefinisikan, lanjutkan membaca kode. Jika sudah didefinisikan, lewati kode sampai #endif.

#define MODELS_H

#define FILE_BUKU "data/Books.txt"
#define FILE_USER "data/User.txt"
#define FILE_PINJAM "data/Peminjaman.txt"

#define STOK_AWAL 5

typedef struct {
    char ocaid[64];
    char title[256];
    char author[256];
    int year;
    int page_count;
    char openlibrary_edition[32];
    char openlibrary_work[32];
    char full_text_url[256];
    int stok;
} Buku;