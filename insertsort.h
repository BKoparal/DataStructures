//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_INSERTSORT_H
#define SORTINGALGORITMS_INSERTSORT_H
#include "printarrays.h"
using namespace std;

class Insertsort {
private:
    Printarrays p;
public:
    void  arayaSokma(int D[], int N);
    void arayaSokma(string D[], int N);
};
/* SADECE KOD

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
void Insertsort::arayaSokma(int *D, int N) {
    cout<<"\nInsert Sort (Araya Sokma Siralamasi)"<<endl;
    int i, k, ekle;
    int sayac=0;
    int tplSwap=0;
    int ilkfor=0;
    int ikinciFor=0;

    for (i = 1; i < N; i++) {
        ilkfor++;
        ekle = D[i];
        cout<<i<<") Before: ";p.diziYaz(D,N);
        //i.inci elemandan basa dogru 0nci elemana kadar ve
        cout<<"\t";
        for (k = i - 1; k >= 0; k--){  // bu harika :for (k = i - 1; k >= 0 && ekle <= D[k]; k--)
            ikinciFor++;
            if(ekle > D[k]) break;
            if(k!=i-1)cout <<", ";
            cout<< D[k + 1]<<"<->"<<D[k];
            tplSwap++;
            D[k + 1] = D[k];
            sayac++;
        }

        D[k + 1] = ekle;
        cout<<"\n   After : ";p.diziYaz(D,N); cout;
        cout<<"\tyer degistirme : "<<sayac<<" tane"<<endl;
        sayac=0;
    }
    cout<<"\n-----------------------------------\n";
    cout<<"toplam yer degistirme     : "<<tplSwap<<"\nilk for dongusu toplam    : "<<ilkfor<<"\nikinci for dongusu toplam : "<<ikinciFor;
    cout<<"\nkarsilastirma ve toplam dongu sayisi: "<< ikinciFor;
    cout<<"\n-----------------------------------\n";
}

void Insertsort::arayaSokma(string *D, int N) {
    cout<<"\nInsert Sort (Araya Sokma Siralamasi)"<<endl;
    int i, k;
    string ekle;
    int sayac=0;
    int tplSwap=0;
    int ilkfor=0;
    int ikinciFor=0;

    for (i = 1; i < N; i++) {
        ilkfor++;
        ekle = D[i];
        cout<<i<<") Before: ";p.diziYaz(D,N);
        //i.inci elemandan basa dogru 0nci elemana kadar ve
        cout<<"\t";
        for (k = i - 1; k >= 0; k--){  // bu harika :for (k = i - 1; k >= 0 && ekle <= D[k]; k--)
            ikinciFor++;
            if(ekle.compare(D[k]) > 0) break;
            if(k!=i-1)cout <<", ";
            cout<< D[k + 1]<<"<->"<<D[k];
            tplSwap++;
            D[k + 1] = D[k];
            sayac++;
        }

        D[k + 1] = ekle;
        cout<<"\n   After : ";p.diziYaz(D,N); cout;
        cout<<"\tyer degistirme : "<<sayac<<" tane"<<endl;
        sayac=0;
    }
    cout<<"\n-----------------------------------\n";
    cout<<"toplam yer degistirme     : "<<tplSwap<<"\nilk for dongusu toplam    : "<<ilkfor<<"\nikinci for dongusu toplam : "<<ikinciFor;
    cout<<"\nkarsilastirma ve toplam dongu sayisi: "<< ikinciFor;
    cout<<"\n-----------------------------------\n";
}

#endif //SORTINGALGORITMS_INSERTSORT_H
