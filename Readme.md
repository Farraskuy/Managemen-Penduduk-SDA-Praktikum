# Aplikasi Array Single Linked List

> **Catatan**: Proyek ini memiliki dua implementasi berbeda:
> 1. **Versi DLL** (dalam folder `/DLL`):
> - Implementasi penuh linked list
> - Alokasi karakter dinamis
> - Fungsionalitas linked list lengkap
>
> 2. **Versi SSL** (dalam folder `/SSL`):
> - Alokasi array dinamis
> - Penanganan karakter dinamis
> - Implementasi linked list dasar

Ini adalah program C yang mengimplementasikan struktur data Array Single Linked List.

## Prasyarat

Sebelum menjalankan aplikasi ini, pastikan Anda memiliki yang berikut ini:
- GCC (GNU Compiler Collection) terinstal di sistem Anda
- Git Bash (untuk pengguna Windows) atau Terminal (untuk pengguna Linux/Mac)

## Cara Menjalankan Aplikasi

Ada dua cara untuk menjalankan aplikasi ini:

### 1. Menggunakan Shell Script (Disarankan)

1. Buka terminal di direktori proyek
2. Jadikan skrip dapat dieksekusi (hanya untuk pertama kali):
```bash
chmod +x run.sh
```
3. Jalankan skrip:
```bash
./run.sh
```

Script akan:
- Mengompilasi semua file .c di direktori
- Membuat file yang dapat dieksekusi bernama "program"
- Menjalankan program jika kompilasi berhasil
- Menampilkan pesan kesalahan jika kompilasi gagal

### 2. Kompilasi Manual

1. Buka terminal di direktori proyek
2. Kompilasi semua file sumber:
```bash
gcc *.c -o program
```
3. Jalankan program yang dikompilasi:
```bash
./program
```

## Struktur Proyek

- `main.c` - Berisi logika program utama
- `kota.c/h` - Implementasi fungsi terkait kota
- `warga.c/h` - Implementasi fungsi terkait warga
- `linked.c/h` - Implementasi fungsi linked list
- `utils.c/h` - Fungsi utilitas
- `BOOLEAN.H` - Definisi tipe Boolean
- `run.sh` - Skrip shell untuk kompilasi dan eksekusi yang mudah

## Catatan

Program ini dikembangkan dan diuji pada sistem Windows menggunakan GCC. Jika Anda menggunakan sistem operasi yang berbeda, Anda mungkin perlu mengubah perintah kompilasi seperlunya.
