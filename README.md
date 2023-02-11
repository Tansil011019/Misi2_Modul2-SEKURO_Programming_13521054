# Misi2_Modul2_Programming_13521054
Second Mission of Programming Second Module

Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force

## Table of Contents
* [General Info](#general-information)
* [How To Run](#how-to-run)
* [Tech Stack](#tech-stack)
* [Project Structure](#project-structure)
* [Credits](#credits)

## General Information
1. Program pada awalnya bisa memilih untuk tutup atau pelanggan masuk (view: Pemilik Toko)
2. Jika pelanggan masuk, program meminta nama pelanggan (tidak ada batasan format nama)
3. Setelah nama pelanggan dimasukkan, pelanggan bisa memilih untuk melihat menu pada
warung, membeli makanan/minuman yang tersedia di warung, atau keluar dari warung. (view:
Pelanggan)
4. Jika pelanggan memilih untuk melihat menu, menu ditampilkan dengan format minimal ID
menu, nama menu, kategori (makanan/minuman), dan harga dari menu. Menu yang tersedia
minimal ada 10 buah . Setelah menu ditampilkan, tampilan program akan kembali seperti
poin 3.
5. Jika pelanggan memilih untuk membeli makanan/minuman, pelanggan harus memasukkan
minimal nama atau ID menu dan jumlahnya. Setelah pembelian, tampilan program akan
kembali seperti poin 3.
6. Jika pelanggan memilih keluar, tampilan program akan kembali seperti poin 1.
7. Jika pemilik memilih untuk tutup, program menampilkan riwayat penjualan dengan format
minimal nama pelanggan, nama menu, jumlah, dan total harga. Jika tidak terjadi transaksi,
cukup tampilkan “Tidak Ada Penjualan”


## How To Run
### Run Using Windows Batch File
1. Di terminal (cmd), jalankan:
```shell
./run
```
2. Atau double klik pada file `run.bat`

### Run Manually 
1. Pastikan anda berada pada dir `bin` dengan :
```shell
cd bin
```
2. Jalankan perintah berikut:
```shell
./out
```

## Tech Stack
### Programming Languange
* C++ language 6.3.0

### Libraries
* iostream
* string
* vector
* sstream
* fstream
* stdlib.h

## Project Structure
```bash
.
├── README.md
├── run.bat
│
├── bin
│    │
│    └── out.exe
│
├── doc
│    │
│    └── Dokumentasi_Misi2_modul2_13521054_Wilson Tansil.pdf
│
└── src
     │
     ├── data
     │     |
     │     ├── food.csv
     │     |
     │     └── user.csv
     │     
     └── main.cpop
```

## Credits
This project is implemented by: Wilson Tansil (13521054)
