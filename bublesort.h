//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_BUBLESORT_H
#define SORTINGALGORITMS_BUBLESORT_H
#include "printarrays.h"

class Bublesort {
private:
    Printarrays p;
public:
    void kabarcik(int[] , int );      //sort int array
    void kabarcik(string[], int);     //sory string array
};

/*
 void kabarcik(int D[], int N) {
    int gecici, k;
    for (int i = 0; i < N - 1; i++) {
        for (k = 0; k < N - 1 - i; k++) {
            //eger buyukse swap
            if (D[k] > D[k + 1]) {
                gecici = D[k];
                D[k] = D[k + 1];
                D[k + 1] = gecici;
            }
        }
    }
}
 */

void Bublesort:: kabarcik(int D[], int N) {
    cout<<"\nsiralanacak dizi: ";p.diziYaz(D, N);
    cout << endl << "------------------------------------------------" << endl;
    int kiyasSayisi = 0, swapSayisi=0;
    cout << "Buble Sort (Kabarcik Siralama)" << endl;
    int gecici, k, hareket;
    for (hareket = 0; hareket < N - 1; hareket++) {
        cout << "hareket " << hareket + 1 << " icin" << setw(0) << left << endl;
        for (k = 0; k < N - 1 - hareket; k++) {
            cout << "\t" << D[k] << " buyuk mu " << D[k + 1] << " den";
            kiyasSayisi++;
            if (D[k] > D[k + 1]) {
                swapSayisi++;
                gecici = D[k];
                D[k] = D[k + 1];
                D[k + 1] = gecici;
                cout << "\t (evet) swap yapildi";
            }
            cout << endl;
        }
        cout << "Dizi Icerigi: ";
        p.diziYaz(D, N);
        cout << endl;
    }

    cout << "\n--------------------------------------------------";
    cout << "\n TOPLAM " << kiyasSayisi << " ADET KIYASLAMA ve "<<swapSayisi<<" TANE SWAP YAPILDI\n";
    cout << "---------------------------------------------------\n";
}



void Bublesort::  kabarcik(string D[], int N) {
    cout<<"\nsiralanacak dizi: ";p.diziYaz(D, N);
    cout << endl << "------------------------------------------------" << endl;
    int kiyasSayisi = 0, swapSayisi=0;
    cout << "Buble Sort (Kabarcik Siralama)" << endl;
    int  k, hareket;
    string gecici;
    for (hareket = 0; hareket < N - 1; hareket++) {
        cout << "hareket " << hareket + 1 << " icin" << setw(0) << left << endl;
        for (k = 0; k < N - 1 - hareket; k++) {
            cout << "\t" << D[k] << " buyuk mu " << D[k + 1] << " den";
            kiyasSayisi++;
            if (D[k].compare(D[k + 1]) > 0) {
                swapSayisi++;
                gecici = D[k];
                D[k] = D[k + 1];
                D[k + 1] = gecici;
                cout << "\t (evet) swap yapildi";
            }
            cout << endl;
        }
        cout << "Dizi Icerigi: ";
        p.diziYaz(D, N);
        cout << endl;
    }

    cout << "\n--------------------------------------------------";
    cout << "\n TOPLAM " << kiyasSayisi << " ADET KIYASLAMA ve "<<swapSayisi<<" TANE SWAP YAPILDI\n";
    cout << "---------------------------------------------------\n";
}


#endif //SORTINGALGORITMS_BUBLESORT_H
