//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_INSERTSORT_H
#define SORTINGALGORITMS_INSERTSORT_H
#include "myutil.h"
using namespace std;

class Insertsort {
private:
    MyUtil p;
public:
    template<typename T>
    void  arayaSokma(T D[], int N);

};
/* IMPLEMENTATION OF THE ALGORITM

void arayaSokma(int *D, int N) {
    int pozisyonuDuzeltilecekEleman;
    int k;
    for (int i = 1; i < N; i++) {
        pozisyonuDuzeltilecekEleman = D[i];
        for ( k= i - 1; k >= 0 && pozisyonuDuzeltilecekEleman <= D[k]; k--)
            D[k + 1] = D[k];
            D[k + 1] = pozisyonuDuzeltilecekEleman;
    }
}
 */


template<typename T>
void Insertsort::arayaSokma(T *D, int N) {
    cout<<"\nInsert Sort (Araya Sokma Siralamasi)"<<endl;
    int i, k,sayac=0,tplSwap=0,ilkfor=0,ikinciFor=0;
    T ekle;

    for (i = 1; i < N; i++) {
        ilkfor++;
        ekle = D[i];
        cout<<"\n"<<i<<")\nBefore: ";p.myPrintArray(D,N);
        //i.inci elemandan basa dogru 0nci elemana kadar ve
        cout<<"\n";
        for (k = i - 1; k >= 0; k--){  // bu harika :for (k = i - 1; k >= 0 && ekle <= D[k]; k--)
            ikinciFor++;
            if(p.mycompare(ekle, D[k]) > 0) break;

            cout<< "\tSWAP : "<<D[k + 1]<<"<->"<<D[k]<<"\n";
            tplSwap++;
            D[k + 1] = D[k];
            sayac++;
        }
        cout<<"\tyer degistirme : "<<sayac<<" tane";
        D[k + 1] = ekle;
        cout<<"\nAfter : ";p.myPrintArray(D,N); cout<<endl<<endl;

        sayac=0;
    }
    cout<<"\n-----------------------------------\n";
    cout<<"toplam yer degistirme     : "<<tplSwap<<"\nilk for dongusu toplam    : "<<ilkfor<<"\nikinci for dongusu toplam : "<<ikinciFor;
    cout<<"\nkarsilastirma ve toplam dongu sayisi: "<< ikinciFor;
    cout<<"\n-----------------------------------\n";
}

#endif //SORTINGALGORITMS_INSERTSORT_H
