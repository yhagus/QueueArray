#include <iostream>
#include <conio.h>
#define MAX 5


using namespace std;

struct queue{
    int data[MAX];
    int awal,akhir;
}antrean;

void init(){
    antrean.awal = -1;
    antrean.akhir = -1;
}

bool full(){
    return antrean.akhir == MAX - 1;
}

bool empty(){
    return antrean.akhir == -1;
}

void tampildata(){
    int i;
    if(!empty()){
        for (i=antrean.awal; i<antrean.akhir;i++){
            cout << antrean.data[i] << " | ";
        }
    }
    cout << "\n";
}

void inQueue(){
    int elemen;
    if (!full()){
        cout << "Data yang akan dimasukkan: ";
        cin>> elemen;
        cout << "Data berhasil ditambahkan\n";
        antrean.data[antrean.akhir] = elemen;
        antrean.akhir++;
        system("CLS");
    } else {
        cout << "Queue penuh";
    }
    getchar();
}

void deQueue(){
    int i;
    tampildata();
    if(!empty()){
        cout<< "\nMengambil data " << antrean.data[antrean.awal] << " ..." << endl;
        for (i = antrean.awal; i<antrean.akhir; i++){
            antrean.data[i] = antrean.data[i+1];
        }
        antrean.akhir--;
    } else {
        cout << "Antrean kosong";
    }
    getchar();
}

void clear(){
    antrean.awal = -1;
    antrean.akhir = -1;
}

void search() {
    int cari;
    bool ketemu = false;
    cout << "Input bilangan yang dicari: ";
    cin >> cari;
    for (int i = -1; i < antrean.akhir; i++) {
        if (cari == antrean.data[i]) {
            ketemu = true;
            cout << "Data ditemukkan pada indeks ke-" << (i+1) << endl;
        }
    }
    if (ketemu == false) {
        cout << "Data tidak ditemukkan\n";
    }
}

void count(){
    float average=0.0;
    float sum=0.0;
    int max,min,indexLocation;
    min = antrean.data[0];
    max = antrean.data[0];

    for (int i = -1; i < antrean.akhir; i++){
        //NILAI MIN
        if(antrean.data[i] < min){
            min = antrean.data[i];
            indexLocation = i + 1;
        }
        //NILAI MAX
        if (antrean.data[i] > max){
            max = antrean.data[i];
            indexLocation = i + 1;
        }
    }

    int n;
    n = sizeof(antrean.data) / sizeof(antrean.data[0]);
    //TOTAL NILAI
    for (int i = -1; i < n; i++){
        sum += antrean.data[i];
    }
    //RATA-RATA
    average = sum / n;

    cout << "Average: " << average << endl;
    cout << "Total: " << sum << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}

void Loading(string text){
    cout << text << " . ";
    _sleep(500);
    cout << " . ";
    _sleep(500);
    cout << " . ";
    _sleep(500);
    system("CLS");
}

int main() {
    int pilihan,elemen;
    init();
    cout << "Demo queue dengan linear array" << endl;
    do {
        tampildata();
        cout << "\nMenu Utama\n";
        cout << "=============\n";
        cout << "[1] Init\n[2] InQueue\n[3] DeQueue\n[4] Clear\n[5] Search\n[6] Count\n[9] Tampilkan Data\n[0] Keluar\n";
        cout << "=============\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cout << "=============\n";
        switch (pilihan) {
            case 1:
                Loading("\n\nLoading");
                init();
                break;
            case 2:
                Loading("\n\nLoading");
                tampildata();
                inQueue();
                break;
            case 3:
                Loading("\n\nLoading");
                tampildata();
                deQueue();
                break;
            case 4:
                Loading("\n\nLoading");
                tampildata();
                clear();
                break;
            case 5:
                Loading("\n\nLoading");
                search();
                break;
            case 6:
                Loading("\n\nLoading");
                count();
                break;
            case 9:
                Loading("\n\nLoading");
                break;
            case 0:
                return 0;
            default:
                return 0;
        }
    } while (pilihan!=0);
}
