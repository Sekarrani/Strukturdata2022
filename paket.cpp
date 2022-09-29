#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;
int datake=0;
int maks=5;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[50];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void tambahdata(int x)
{
    if(datake<maks){
        gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[x].jenis_brg;
        gotoxy(20,16);cout<<"Inputkan Berat (Kg)    :";
        cin>>kirim[x].berat;
        gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[x].kota;
    }
    else{
        gotoxy(40,19);
        cout << "Data penuh";
        gotoxy(40,20);
        cout<<"Press Any Key To Continue...";
        getch();
    }
}

void tampildata(int x)
{
    gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=0; a<datake; a++)
    {
        gotoxy(40,19-a);
        cout<<a+1<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" kg ";
        cout<<kirim[a].kota<<endl;
    }
    gotoxy(40,20);
    cout<<"Press Any Key To Continue...";
    getch();
   // harus Ijin --> tambahkan #include<conio.h>
}

void hapusdata(int x)
{
    if(datake>0){
        gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
        cout<<kirim[x].berat<<" Kg ";
        cout<<kirim[x].kota<<endl<<endl;

        gotoxy(40,15);cout<<"Press Any Key To Continue...";
        getch();
    }
    else{
        gotoxy(40,19);
        cout << "Data kosong";
        gotoxy(40,20);
        cout<<"Press Any Key To Continue...";
        getch();
    }
}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            {
//                Menambah data baru diletakan di DATAKE
                tambahdata(datake);
                datake++;
            }
        if(pilih==2)
            {
//                Menghapus Data Terakhir (DATAKE-1)
                hapusdata(datake-1);
                datake--;
            }
        if(pilih==3)
            {
           // Menampilkan semua Data
            tampildata(datake);
            }
    }
    while(pilih!=9);
    return 0;
}
