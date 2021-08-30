//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_BUBLESORT_H
#define SORTINGALGORITMS_BUBLESORT_H
#include "myutil.h"

class Bublesort {
private:
    MyUtil p;
public:
    template<typename T> void kabarcik(T D[] , int N );      //can sort both string and int array

};



template<typename T>
void Bublesort::kabarcik(T D[], int N) {
    cout<<"\nsiralanacak dizi: ";p.myPrintArray(D, N);
    cout << endl << "------------------------------------------------" << endl;
    int kiyasSayisi = 0, swapSayisi=0;
    cout << "Buble Sort (Kabarcik Siralama)" << endl;
    int  k, hareket;
    T gecici;
    for (hareket = 0; hareket < N - 1; hareket++) {
        cout << "hareket " << hareket + 1 << " icin" << setw(0) << left << endl;
        for (k = 0; k < N - 1 - hareket; k++) {
            cout << "\t" << D[k] << " buyuk mu " << D[k + 1] << " den";
            kiyasSayisi++;
            if (p.mycompare(D[k],D[k + 1]) > 0) {
                swapSayisi++;
                gecici = D[k];
                D[k] = D[k + 1];
                D[k + 1] = gecici;
                cout << "\t (evet) swap yapildi";
            }
            cout << endl;
        }
        cout << "Dizi Icerigi: ";
        p.myPrintArray(D, N);
        cout << endl;
    }

    cout << "\n--------------------------------------------------";
    cout << "\n TOPLAM " << kiyasSayisi << " ADET KIYASLAMA ve "<<swapSayisi<<" TANE SWAP YAPILDI\n";
    cout << "---------------------------------------------------\n";
}



/*  IMPLEMENTATION OF THE ALGORITM
 *
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



#endif //SORTINGALGORITMS_BUBLESORT_H
