//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_SELECTIONSORT_H
#define SORTINGALGORITMS_SELECTIONSORT_H
#include "printarrays.h"



class Selectionsort {
private:
    Printarrays p;
public:
    void secmelisirala ( int [], int );
    void secmelisirala ( string [], int );
};

/*

 void secmelisirala (int D[], int N) {
    int index, enkucuk;
    for (int i=0; i<N-1; i++) {
        enkucuk=D[N-1];
        index=N-1;
        for (int j=i; j<(N-1); j++){
            if (D[j]<enkucuk) {
                enkucuk= D[j];
                index=j;
            }
        }
        D[index]=D[i];
        D[i]= enkucuk;
    }
}

 */



void Selectionsort::secmelisirala ( int D[], int N) {
    cout<<"Selection Sort (Secmeli Siralama)"<<endl;
    int tplKarsilastirma=0;int swapCount=0;
    int i, index, j, enkucuk;
    for (i=0; i<N-1; i++) {
        enkucuk=D[N-1];
        index=N-1;
        cout<<i+1<<") Before : "; p.diziYaz(D,N);
        for (j=i; j<(N-1); j++){
            tplKarsilastirma++;
            if (D[j]<enkucuk) {

                enkucuk= D[j];
                index=j;
            }
        }

        D[index]=D[i];
        D[i]= enkucuk;

        cout<<"\n   After  : ";p.diziYaz(D,N); cout;
        if(D[index]!=D[i]) {
            cout<<"  ("<<D[index]<< " ile "<<D[i]<<" yer degistirdi)";
            swapCount++;
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------------------";
    cout<<"\nToplam: "<<tplKarsilastirma<<" karsilastirma,";
    cout<<"\nToplam: "<<swapCount<<" yer degistirme yapildi, ancak esasen her dongude bir yer degistirme,";
    cout<<"\nmutlaka yapilir. Yani en kucuk kendisi ise dahi kendisiyle swap yapilir";
    cout<<endl<<"-------------------------------------------------------"<<endl;
}



void Selectionsort::secmelisirala (string D[], int N) {
    cout<<"Selection Sort (Secmeli Siralama)"<<endl;
    int tplKarsilastirma=0;int swapCount=0;
    int i, index, j;
    string enkucuk;
    for (i=0; i<N-1; i++) {
        enkucuk=D[N-1];
        index=N-1;
        cout<<i+1<<") Before : "; p.diziYaz(D,N);
        for (j=i; j<(N-1); j++){
            tplKarsilastirma++;
            if (D[j].compare(enkucuk)<0) {
                enkucuk= D[j];
                index=j;
            }
        }

        D[index]=D[i];
        D[i]= enkucuk;

        cout<<"\n   After  : ";p.diziYaz(D,N); cout;
        if(D[index].compare(D[i])!=0) {
            cout<<"  ("<<D[index]<< " ile "<<D[i]<<" yer degistirdi)";
            swapCount++;
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------------------";
    cout<<"\nToplam: "<<tplKarsilastirma<<" karsilastirma,";
    cout<<"\nToplam: "<<swapCount<<" yer degistirme yapildi, ancak esasen her dongude bir yer degistirme,";
    cout<<"\nmutlaka yapilir. Yani en kucuk kendisi ise dahi kendisiyle swap yapilir";
    cout<<endl<<"-------------------------------------------------------"<<endl;
}
#endif //SORTINGALGORITMS_SELECTIONSORT_H
