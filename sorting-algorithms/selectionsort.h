//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_SELECTIONSORT_H
#define SORTINGALGORITMS_SELECTIONSORT_H
#include "myutil.h"



class Selectionsort {
private:
    MyUtil p;
public:
    template<typename T>
    void secmelisirala (T [], int );

};

/*    IMPLEMENTATION OF THE ALGORITM

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


template<typename T>
void Selectionsort::secmelisirala(T D[], int N) {
    cout<<"Selection Sort (Secmeli Siralama)"<<endl;
    int tplKarsilastirma=0;int swapCount=0;
    int i, index, j;
    T enkucuk;
    for (i=0; i<N-1; i++) {
        enkucuk=D[N-1];
        index=N-1;
        cout<<i+1<<") Before : "; p.myPrintArray(D,N);
        for (j=i; j<(N-1); j++){
            tplKarsilastirma++;
            if (p.mycompare(D[j],enkucuk) < 0) {

                enkucuk= D[j];
                index=j;
            }
        }

        D[index]=D[i];
        D[i]= enkucuk;

        cout<<"\n   After  : ";p.myPrintArray(D,N); cout;
        if(D[index]!=D[i]) {
            cout<<"\n   Swap   : "<<D[index]<< " <--> "<<D[i]<<endl;
            swapCount++;
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------------------";
    cout<<"\nToplam: "<<tplKarsilastirma<<" karsilastirma,";
    cout<<"\nToplam: "<<swapCount<<" yer degistirme yapildi, ancak esasen her dongude toplam bir yer degistirme,";
    cout<<"\nmutlaka yapilir. Yani en kucuk kendisi ise dahi algortima kendisiyle swap yaptırır.";
    cout<<endl<<"-------------------------------------------------------"<<endl;
}



#endif //SORTINGALGORITMS_SELECTIONSORT_H
