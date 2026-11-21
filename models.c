#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"

Buku *dataBuku = NULL;
int jumlahBuku = 0;

User *dataUser = NULL;
int jumlahUser = 0;

Peminjaman *dataPinjam = NULL;
int jumlahPinjam = 0;
/*
Mengambil satu kata dari baris.
Jika menggunakan tanda petik, ambil seluruh teks di dalamnya.
Return 0 jika tidak ada kata.
*/
static int ambilKata(char *teks, int *pos, char *hasil, int maks)
{
    int i = 0;

    // Lewati spasi dan tab
    while (teks[*pos] == ' ' || teks[*pos] == '\t')
    {
        (*pos)++;
    }

    // Periksa apakah teks sudah habis
    if (teks[*pos] == '\0' || teks[*pos] == '\n' || teks[*pos] == '\r')
    {
        return 0;
    }