# Aplikasi Array of Single Linked List

Ini adalah program C yang mengimplementasikan struktur data Array of Single Linked List.

## Prasyarat

Sebelum menjalankan aplikasi ini, pastikan Anda memiliki:
- GCC (GNU Compiler Collection) terinstal di sistem Anda
- Git Bash (untuk pengguna Windows) atau Terminal (untuk pengguna Linux/Mac)

## Cara Menjalankan Aplikasi

Ada dua cara untuk menjalankan aplikasi ini:

### 1. Menggunakan Shell Script (Direkomendasikan)

1. Buka terminal di direktori proyek
2. Buat script menjadi dapat dieksekusi (hanya pertama kali):
   ```bash
   chmod +x run.sh
   ```
3. Jalankan script:
   ```bash
   ./run.sh
   ```

Script akan:
- Mengompilasi semua file .c di direktori
- Membuat file executable bernama "program"
- Menjalankan program jika kompilasi berhasil
- Menampilkan pesan error jika kompilasi gagal

### 2. Kompilasi Manual

Jika Anda lebih memilih untuk mengompilasi secara manual, ikuti langkah-langkah berikut:

1. Buka terminal di direktori proyek
2. Kompilasi semua file sumber:
   ```bash
   gcc *.c -o program
   ```
3. Jalankan program yang telah dikompilasi:
   ```bash
   ./program
   ```

## Struktur Proyek

- `main.c` - Berisi logika program utama
- `kota.c/h` - Implementasi fungsi-fungsi terkait kota
- `warga.c/h` - Implementasi fungsi-fungsi terkait warga
- `linked.c/h` - Implementasi fungsi-fungsi linked list
- `utils.c/h` - Fungsi-fungsi utilitas
- `BOOLEAN.H` - Definisi tipe boolean
- `run.sh` - Shell script untuk kompilasi dan eksekusi yang mudah

## Pemecahan Masalah

Jika Anda mengalami masalah kompilasi:
1. Pastikan semua file header berada di direktori yang benar
2. Periksa bahwa GCC telah terinstal dengan benar dan dapat diakses dari terminal
3. Verifikasi bahwa semua file sumber (.c) dan file header (.h) ada

## Catatan

Program ini dikembangkan dan diuji pada sistem Windows menggunakan GCC. Jika Anda menggunakan sistem operasi yang berbeda, Anda mungkin perlu memodifikasi perintah kompilasi sesuai kebutuhan.