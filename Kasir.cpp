#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>

#define MAX_DATA 5
#define MAX_K 3
using namespace std;

/*Mahasiswa UTY - INFORMARTIKA - 2017/208 
* TUGAS BESAR STRUKTUR DATA *
	Nama : M Dhifta Ramadhan
	NIM  : 5170411036
	PRODI: INFORMATIKA (A)
	
	Program ini dibuat menggunakan Visual Studio 2010
	Apabila ada Error dan Bug bisa di akibatkan karna 
	Compailer dengan versi yang berbeda (karna sudah di-
	coba saat pengerjaan) atau juga karna keteledoran pem-
	buat program.
	*/

void hari_jam(){ //prosedure memanggil jam dan tanggal
	time_t waktu;
	time(&waktu);//mengambil alamat data waktu
	cout<<"\t\t"<<ctime(&waktu); //ctime adalah kunci utama pemanggilan
}

typedef struct barang{ //struct barang
	string nabar;
	int jum;
}brg;
brg tampung;

typedef struct keranjang{ //struct keranjang
	int top[MAX_DATA];
	int da_krj;
	double harga;
	brg data_barang[MAX_K][MAX_DATA];
}krj;

void initStack(krj &in) {
	for (int i = 0; i < MAX_K; i++) {
		in.top[i] = -1;
	}
	in.da_krj = 0;
	in.harga = 0;
}

int isEmpty(krj in) {
	return in.top[in.da_krj] == -1;
}

int isFull(krj in) {
	return in.top[in.da_krj] == MAX_DATA - 1;
}

brg OnTop(krj in) {
	if (isEmpty(in)) {
		cout << "Tidak Ada Antrian Keranjang!";
	}
	else {
		return in.data_barang[in.da_krj][in.top[in.da_krj]];
	}
}

void push(krj &in, brg on) {

	if (isFull(in)) {
		cout << "Keranjang Sudah Penuh\n";
	}
	else {
		in.top[in.da_krj]++; //menambah data baru
		in.data_barang[in.da_krj][in.top[in.da_krj]] = on; //menampung data yang dimasukkan ke dalam krj
	}
}

void Print_barang(krj in, brg on){
	if (isEmpty(in)) {
		cout << "\n\n\t\t\tKeranjang masih kosong!!\n";
	}else {
		while (in.top[in.da_krj] != -1){ //kondisi untuk menampilkan data

			on = in.data_barang[in.da_krj][in.top[in.da_krj]]; //menampung sementara data
			in.top[in.da_krj]--; //mengurangi setiap menampilkan data baru
			
			cout<<"\t\t=Nama Barang   : "<<on.nabar<<endl;
			cout<<"\t\t=Jumlah Barang : "<<on.jum<<" Pcs"<<endl;
			cout<<"\t\t=Harga Barang  : Rp.-"<<endl;
			cout<<"\t\t-----------------------------------"<<endl;
		}
	}
	cout<<"\t\t";
}

brg Kembalikan_barang(krj &in){
	int nobar=0; //kondisi awal
	barang outbar;

	if (isEmpty(in)){
		cout<<"\n\n\t\t\tDATA KOSONG!!"; //kondisi yang tak dipenuhi
	} else {
		for(int i=0; i<=in.top[in.da_krj]; i++){ //tampilkan data awal
			outbar = in.data_barang[in.da_krj][i];
			cout<<"\t\t=NO."<<i+1<<endl;
			cout<<"\t\t=Nama Barang   : "<<outbar.nabar<<endl;
			cout<<"\t\t=Jumlah Barang : "<<outbar.jum<<" Pcs"<<endl;
			cout<<"\t\t=Harga Barang  : Rp.-"<<endl;
			cout<<"\t\t--------------------------------------"<<endl;
		}
		cout<<"\n\t\tMasukkan Nomor Barang yang ingin di hapus : "; cin>>nobar; //meminta no data yang ingin dihapus
		nobar=nobar-1;
		for(int j=0; j<=in.top[in.da_krj]; j++){ //eksekusi data yang akan dihapus
				if(nobar==j){
					if(j>in.da_krj){
						in.data_barang[in.da_krj][j] = in.data_barang[in.da_krj][j+1]; //kondisi yang dihapus
						break;
					} else if (j == MAX_DATA){
						in.top[in.da_krj]--; //mengurangi data
					} else {
						//..
					}
				}
			}
			in.top[in.da_krj]--; //data penting yang harus ada
		}
		system("cls");
		cout << "\t\t=========MENU HAPUS BARANG=========\n";
	cout<<"\n\n\t\t\tDATA SUDAH DIKEMBALIKAN!\n";
	return outbar; //mengembalikan data baru
}

brg ubah_barang(krj &in, brg chg){
	int change=0;

	if (isEmpty(in)){
		cout<<"\n\n\t\t\tDATA KOSONG!!"; //kondisi yang tak terpenuhi
	} else {
		for(int j=0; j<=in.top[in.da_krj]; j++){ //menampilkan barang
			chg = in.data_barang[in.da_krj][j];
			cout<<"\t\t=NO."<<j+1<<endl;
			cout<<"\t\t=Nama Barang   : "<<chg.nabar<<endl;
			cout<<"\t\t=Jumlah Barang : "<<chg.jum<<" Pcs"<<endl;
			cout<<"\t\t=Harga Barang  : Rp.-"<<endl;
			cout<<"\t\t----------------------------------------"<<endl;
		}
		cout<<"\t\tMasukkan Nomor Barang yang ingin di ubah: "; cin>>change; //input no barang yang diubah
		change = change-1;
		for(int i = 0; i<=in.top[in.da_krj]; i++){ //pengeksekusian untuk mengubah data
			if(change==i){
				for(int j=i; j<=in.top[in.da_krj]; j++){
					if(j==i){
						system("cls");
						cin.sync(); //teman getline
						cout << "\t\t============MENU UBAH BARANG============\n";
						cout<<"\t\t="<<endl; //memasukan data baru
						cout<<"\t\t=Masukkan Nama Barang   : "; getline(cin,in.data_barang[in.da_krj][i].nabar);
						cout<<"\t\t=Masukkan Jumlah Barang : "; cin>>in.data_barang[in.da_krj][i].jum;
					} 
				}
			}
		}
		system("cls");
		cout << "\t\t============MENU UBAH BARANG============\n";
		cout << "\n\n\t\t\t    BERHASIL DIUBAH!"<<endl;
		cout << "\t\t----------------------------------------\n";
		cout<<"\t\t";
	return chg; //mengembalikan data baru
	}
}

int main() {
	krj in; brg dat_ksr; //deklarasi data
	brg on; int inlop=0;
	initStack(in); //mendeklarasikan stac awal
	int datbar = 0; int pilih,pilih_pel,pilih_kas; //deklarasi pilihan
	double total=0, pendapatan=0, kembalian, subtotal; //deklarasi variable untuk kasir
	system("color 02"); //mengubah warna background dan tulisan
	do {	
		system("cls");
		hari_jam();
		cout << "\t\t========= SYSTEM PROGRAM USER MENU ==========\n";
		cout << "\t\t= (1) Masuk sebagai pelanggan               =\n";
		cout << "\t\t= (2) Masuk sebagai kasir                   =\n";
		cout << "\t\t= (3) Keluar Program                        =\n";
		cout << "\t\tPilih Menu  : ";
		cin >> pilih;

		switch(pilih) {
		case 1 :
		if(inlop>=MAX_K){
			cout<<"\n\n\t\t\t[KERANJANG SUDAH HABIS]"<<endl;
						cout<<"\t\t\t";
						system("pause");
		} else {
			do { //proses program ke pelanggan
				system("cls");
				cout << "\t\t\t======= MENU PELANGGAN =======\n";
				cout << "\t\t\t= 1- Tambah barang           =\n";
				cout << "\t\t\t= 2- lihat barang            =\n";
				cout << "\t\t\t= 3- Keluarkan barang        =\n";
				cout << "\t\t\t= 4- Ubah barang             =\n";
				cout << "\t\t\t= 5- Antrikan keranjang      =\n";
				cout << "\t\t\tPilih Menu : "; cin>>pilih_pel;

				switch (pilih_pel) {
				case 1 :
					system("cls");
				if (in.da_krj>=MAX_K) {
						cout<<"\n\n\t\t\t[BARANG TAK BISA DIMASUKKAN]"<<endl;
						cout<<"\t\t\t";
						system("pause");
					} else {
						if (datbar!=MAX_DATA) {
							cout << "\t\t============MENU MASUK BARANG============\n";
							cin.sync(); //fungsi untuk menambahkan sepasi bergabung dengan getline
							cout << "\t\tMasukkan nama barang	: "; getline(cin, on.nabar); //bisa menggunakan cin>> jika error atau versi c++ 2017++
							cout << "\t\tMasukkan jumlah barang	: "; cin>>on.jum; //input barang dan jumlahnya
							push(in , on);
							system("cls");
							cout << "\t\t============MENU MASUK BARANG============\n";
							cout << "\n\n\t\t\tBARANG SUDAH DIMASUKKAN!\n";
							cout<<"\t\t";
							datbar++; //penampungan sementara untuk kondisi
						}
						else {
							cout << "\t\t============MENU MASUK BARANG============\n";
							cout << "\n\n\t\t\tKERANJANG SUDAH PENUH!\n";
							cout<<"\t\t";
						}
					}
					system("pause");
					system("cls");
					break;
				case 2 :
					system("cls");
					cout << "\t\t=========MENU LIHAT BARANG=========\n";
					Print_barang(in,on); //memanggil prosedure print barang
					system("pause");
					system("cls");
					break;
				case 3 :
					system("cls");
					cout << "\t\t=========MENU HAPUS BARANG=========\n";
					Kembalikan_barang(in); //memanggil fungsi kembalikan barang
					system("pause");
					system("cls");
					break;
				case 4 :
					system("cls");
					cout << "\t\t============MENU UBAH BARANG============\n";
					ubah_barang(in,on); //memanggil fungsi ubah barang
					system("pause");
					system("cls");
					break;
				case 5 : 
					system("cls");
					//... tidak kondisi
					cout<<"\n\n\t\t\t[BARANG SUDAH DIANTRIKAN!]"<<endl;
					cout<<"\t\t\t";
					system("pause");
					break;
				default : //jika input lebih dari 5 data
					system("cls");
					cout << "\n\n\t\t\t[Error! INPUT YANG BENAR!]\n";
					cout<<"\t\t\t";
					system("pause");
					system("cls");
					break;
				}
			} while (pilih_pel!=5);
		}
			inlop++;
			in.data_barang[in.da_krj++][in.top[in.da_krj]]; //oprasi penambahan data
			datbar = 0; //mengembalikan nilai kondisi menjadi 0
			break;
		case 2 :
			do { //proses programan ke kasir

				system("cls");
				cout << "\t\t\t===========MENU KASIR===========\n";
				cout << "\t\t\t= 1- Proses Pembayaran         =\n";
				cout << "\t\t\t= 2- Lihat Antrian             =\n";
				cout << "\t\t\t= 3- Lihat Total Pendapatan    =\n";
				cout << "\t\t\t= 4- kembali ke menu utama     =\n";
				cout << "\t\t\tPilih menu : "; cin >> pilih_kas;

				switch (pilih_kas) {
				case 1 :
					system("cls");
					if (in.da_krj==0) {
						cout << "\t\t==========MENU PEMBAYARAN==========\n";
						cout << "\n\n\t\t\t[ANTRIAN KOSONG!]\n";
						cout<<"\t\t\t";
						system("Pause");
						system("cls");
					}
					else { //eksekusi data perhitungan harga dan pengurangan data
						for (int i = 0; i<=in.da_krj; i++) {
							cout << "\t\t==========MENU PEMBAYARAN==========\n";
							cout << "\t\tAntrian ke-" << i + 1 << "\n";
							for (int j = 0; j<=in.top[i]; j++) {
								dat_ksr = in.data_barang[i][j];
								cout << "\t\tNama barang	: " << dat_ksr.nabar;
								cout << "\n\t\tJumlah		: " << dat_ksr.jum;
								cout << "\n\t\tHarga		: Rp."; cin >> in.harga;
								subtotal = ((in.harga)*(in.data_barang[i][j].jum)); //rumus sub total dalam perhitungan
								cout << "\n\t\t================================\n";
								cout << "\t\tSubtotal	: Rp." <<subtotal<<endl;
								total = total + subtotal; //rumus total
								cout << "\t\tTotal	    : Rp." <<total;
								cout << "\n\t\t================================\n";
							
							}
							double bayar = 0;
							cout << "\t\tTotal Belanja Anda		: Rp." <<total <<"\n";
							while(true){
								cout << "\t\tMasukkan jumlah pembayaran	: Rp."; cin >>bayar; //eksekusi bayar 
								if(bayar<total){
									cout << "\n\t\tPEMBAYARAN KURANG! TIDAK BOLEH UTANG!\n";
								}else{
									double kembalian = bayar - total; //rumus kembalian 
									cout << "\n\t\tKembalian	: Rp." <<kembalian;
									break;
								}
							}
						pendapatan = pendapatan + total; //menampung data pendapatan
						in.da_krj--; //mengurangi data 
						total = 0; //membuat total menjadi 0 kembali
						cout << "\n\n\t\t[TERIMA KASIH SUDAH BELANJA & TIDAK CASS BON]\n";
						cout<<"\t\t";
						system("Pause");
						system("cls");
					}
				}
					in.da_krj=0;
					break;
				case 2 :
					system("cls");
					cout << "\t\t\t===========MENU ANTRIAN===========\n";
					if (in.da_krj== 0) {
						cout << "\n\n\t\t\t      [TIDAK ADA ANTRIAN!]\n";
					}else{
						//menampilkan data antrian
						for (int i = 0; i <in.da_krj; i++) {
							cout << "\t\t\tAntrian ke -" << i + 1;
						for (int j = 0; j<=in.top[i]; j++) {
							dat_ksr = in.data_barang[i][j];
							cout << "\n\t\t\t=Nama barang	: " << dat_ksr.nabar;
							cout << "\n\t\t\t Jumlah barang	: " << dat_ksr.jum;
							cout << "\n\t\t\t Harga		: Rp.-"<<endl;
						}
						cout<<"\t\t\t----------------------------------"<<endl;
					}
				}
					cout<<"\t\t\t      ";
					system("pause");
					system("cls");
					break;
				case 3 :
					system("cls"); //menampilkan total pendapatan
					cout << "\t\t=============TOTAL PENDAPATAN=============\n";
					cout << "\t\t="<<endl;
					cout << "\t\t= Total pendapatan hari ini : Rp." <<pendapatan<<endl;
					cout << "\t\t==========================================\n"<<endl;
					cout << "\t\t";
					system("pause");
					system("cls");
					break;
				case 4 :
					system("cls");
					//.... tidak memiliki kondisi
					cout<<"\n\n\t\t\t[KEMBALI KEMENU UTAMA!]"<<endl;
					cout<<"\t\t\t";
					system("pause");
					break;
				default : //kondisi saat input lebih dari 4
					system("cls");
					cout<<"\n\n\t\t\t[ERRO TOLONG INPUT YANG BENAR!]"<<endl;
					cout<<"\t\t\t";
					system("pause");
					break;

				}

			} while (pilih_kas!=4);
			break;
		case 3 : //keluar program
			system("cls");
			cout<<"\n\n\t\t\t[KELUAR DARI PROGRAM!]"<<endl;
			cout<<"\t\t\t";
			system("pause");
			exit(0);
			break;
		default :
			system("cls"); //jika input data yang lainnya
			cout<<"\n\n\t\t\t[BARANG SUDAH DIANTRIKAN!]"<<endl;
			cout<<"\t\t\t";
			system("pause");
			break;
		}
	} while (pilih!=3);
}

