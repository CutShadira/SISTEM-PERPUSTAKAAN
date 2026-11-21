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
    // Periksa apakah kata menggunakan tanda petik
    if (teks[*pos] == '"')
    {
        (*pos)++;

        // Ambil teks sampai menemukan tanda petik penutup
        while (teks[*pos] != '"' && teks[*pos] != '\0' &&
               teks[*pos] != '\n' && teks[*pos] != '\r')
        {

            if (i < maks - 1)
            {
                hasil[i++] = teks[*pos];
            }

            (*pos)++;
        }

        // Lewati tanda petik penutup
        if (teks[*pos] == '"')
        {
            (*pos)++;
        }
    }
    else
    {

        // Ambil kata biasa sampai menemukan spasi
        while (teks[*pos] != ' ' && teks[*pos] != '\t' &&
               teks[*pos] != '\0' && teks[*pos] != '\n' &&
               teks[*pos] != '\r')
        {

            if (i < maks - 1)
            {
                hasil[i++] = teks[*pos];
            }

            (*pos)++;
        }
    }

    // Akhiri string
    hasil[i] = '\0';

    return 1;
}