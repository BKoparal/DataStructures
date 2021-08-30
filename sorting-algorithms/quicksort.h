//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_QUICKSORT_H
#define SORTINGALGORITMS_QUICKSORT_H
#include "myutil.h"

class Quicksort {
private:
    MyUtil p;
    int arraySize=0;
    int adim=0;
    int karsilastirma=0;
    int swapCount=0;
    template<typename T>
    void quickSort(T D[], int leftIndex, int rightIndex);
    template<typename T>
    int partition (T D[], int leftIndex, int rightIndex);
public:
    template<typename T>
    void hizlisirala(T D[], int leftIndex, int rightIndex);
};

template<typename T>
int Quicksort::partition (T D[], int leftIndex, int rightIndex) {
    cout<<"\n\n\n------------------------------------------"<<endl;
    cout<<"<<< adim: "<<++adim<<"  partition >>>"<<endl;
    cout<<"------------------------------------------"<<endl;
    int pivotIndex = rightIndex; // pivot
    int i = (leftIndex - 1); // Index of smaller element and indicates the rightIndex position of pivot found so far

    cout<<"i           : "<<i<<"\t\t(leftIndex-1)";
    cout<<"\npivot       : "<<D[pivotIndex];
    cout <<"\nstart index : "<<leftIndex;
    cout<< "\nend index   : "<<rightIndex;
    cout<<"\nBefore       : ";
    p.myPrintArray(D,rightIndex+1,leftIndex);
    cout<<endl;
    for (int j = leftIndex; j <= rightIndex-1; j++) {
        //cout<<"\ni: "<<leftIndex<<setw(3)<<i<<" j="<<j<<setw(0)<<", if (D[j] < pivot) "<<D[j]<<"<"<<pivot;
        printf("\ni:%-3d j=%-4d if(D[j]<pivot)",i,j);cout<<D[j]<<"<"<<D[pivotIndex];
        // If current element is smaller than the pivot
        karsilastirma++;
        if (p.mycompare(D[j],D[pivotIndex]) < 0) {
            i++; // increment index of smaller element
            cout<<" evet i++ ve D[i]<-><D[j] swap yani "<<D[i]<<"<->"<<D[j];
            p.swap(&D[i], &D[j]);
            if(p.mycompare(D[i],D[j])!=0) swapCount++;
        }
    }
    cout<<"\ndongu bitti. simdi swap(D[i+1],D[pivotIndex])  yani  "<<D[i + 1]<<"<->"<<D[pivotIndex];
    p.swap(&D[i + 1], &D[pivotIndex]);
    if (p.mycompare(D[i + 1], D[pivotIndex]) != 0) swapCount++;
    cout<<"\nAfter : "; p.myPrintArray(D,rightIndex+1,leftIndex);
    cout<<"\n\nTum Dizi: "; p.myPrintArray(D,arraySize);
    return (i + 1);
}



template<typename T>
void  Quicksort::quickSort(T D[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        /* partitionIndex is partitioning index, D[p] is now at rightIndex place */
        int partitionIndex = partition(D, leftIndex, rightIndex);
        // Separately sort elements before // partition and after partition
        quickSort(D, leftIndex, partitionIndex - 1);
        quickSort(D, partitionIndex + 1, rightIndex);
    }
}



template<typename T>
void Quicksort::hizlisirala(T *D, int leftIndex, int rightIndex) {
    arraySize=rightIndex+1;
    cout<<endl<<"Quick Sort (Hizli Siralama Algoritmasi)";
    quickSort(D,  leftIndex,  rightIndex);
    cout<<endl<<"----------------- SONUC -----------------";
    cout<<endl<<"Toplam yer degistirme sayis: "<<swapCount;
    cout<<endl<<"toplam karsilastirma sayisi: "<<karsilastirma;
    cout<<endl<<"swaplar dizi uzerinde yapildiginden birlestirme islemine gerek yoktur.";
    cout<<endl<<"SONUC: ";
    p.myPrintArray(D,rightIndex);
    cout<<endl<<"------------------------------------"<<endl;
}


#endif //SORTINGALGORITMS_QUICKSORT_H
