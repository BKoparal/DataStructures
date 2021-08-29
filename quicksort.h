//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_QUICKSORT_H
#define SORTINGALGORITMS_QUICKSORT_H
#include "printarrays.h"

class Quicksort {
private:
    Printarrays p;
    int adim=0;
    int karsilastirma=0;
    int swapCount=0;
public:
    void hizlisirala(int D[], int leftIndex, int rightIndex);
    void hizlisirala(string D[], int leftIndex, int rightIndex);
    friend int partition (int D[], int leftIndex, int rightIndex);
    friend int partition (string D[], int leftIndex, int rightIndex);
};


//QuickSort
template<typename  T>
void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}






Quicksort q;
/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to leftIndex of pivot and all greater elements to rightIndex
of pivot */
int partition (int D[], int leftIndex, int rightIndex) {
    cout<<"\n\n\n------------------------------------------"<<endl;
    cout<<"<<< adim: "<<++q.adim<<"  partition >>>"<<endl;
    cout<<"------------------------------------------"<<endl;


    int pivotIndex = rightIndex; // pivot
    int i = (leftIndex - 1); // Index of smaller element and indicates the rightIndex position of pivot found so far

    cout<<"i           : "<<i<<"\t\t(leftIndex-1)";
    cout<<"\npivot       : "<<D[pivotIndex];
    cout <<"\nstart index : "<<leftIndex;
    cout<< "\nend index   : "<<rightIndex;
    cout<<"\ndizi        : ";
    q.p.diziYaz(D,rightIndex+1,leftIndex);
    cout<<endl;
    for (int j = leftIndex; j <= rightIndex-1; j++) {
        //cout<<"\ni: "<<leftIndex<<setw(3)<<i<<" j="<<j<<setw(0)<<", if (D[j] < pivot) "<<D[j]<<"<"<<pivot;
        printf("\ni:%-3d j=%-4d if(D[j]<pivot) %d<%d",i,j,D[j], D[pivotIndex]);
        // If current element is smaller than the pivot
        q.karsilastirma++;
        if (D[j] < D[pivotIndex]) {
            i++; // increment index of smaller element
            cout<<" evet i++ ve D[i]<-><D[j] swap yani "<<D[i]<<"<->"<<D[j];
            swap(&D[i], &D[j]);
            if(D[i]!=D[j]) q.swapCount++;
        }
    }
    cout<<"\ndongu bitti. simdi swap(D[i+1],D[pivotIndex])  yani  "<<D[i + 1]<<"<->"<<D[pivotIndex];
    swap(&D[i + 1], &D[pivotIndex]);
    if(D[i + 1]!= D[pivotIndex]) q.swapCount++;
    cout<<"\ndizi  : "; q.p.diziYaz(D,rightIndex+1,leftIndex);
    cout<<"\n\nTum Dizi: "; q.p.diziYaz(D,rightIndex);

    return (i + 1);
}



int partition (string D[], int leftIndex, int rightIndex) {
    cout<<"\n\n\n------------------------------------------"<<endl;
    cout<<"<<< adim: "<<++q.adim<<"  partition >>>"<<endl;
    cout<<"------------------------------------------"<<endl;
    int pivotIndex = rightIndex; // pivot
    int i = (leftIndex - 1); // Index of smaller element and indicates the rightIndex position of pivot found so far

    cout<<"i           : "<<i<<"\t\t(leftIndex-1)";
    cout<<"\npivot       : "<<D[pivotIndex];
    cout <<"\nstart index : "<<leftIndex;
    cout<< "\nend index   : "<<rightIndex;
    cout<<"\ndizi        : ";
    q.p.diziYaz(D,rightIndex+1,leftIndex);
    cout<<endl;
    for (int j = leftIndex; j <= rightIndex-1; j++) {
        //cout<<"\ni: "<<leftIndex<<setw(3)<<i<<" j="<<j<<setw(0)<<", if (D[j] < pivot) "<<D[j]<<"<"<<pivot;
        printf("\ni:%-3d j=%-4d if(D[j]<pivot)",i,j);cout<<D[j]<<"<"<<D[pivotIndex];
        // If current element is smaller than the pivot
        q.karsilastirma++;
        if (D[j].compare(D[pivotIndex]) < 0) {
            i++; // increment index of smaller element
            cout<<" evet i++ ve D[i]<-><D[j] swap yani "<<D[i]<<"<->"<<D[j];
            swap(&D[i], &D[j]);
            if(D[i].compare(D[j])!=0) q.swapCount++;
        }
    }
    cout<<"\ndongu bitti. simdi swap(D[i+1],D[pivotIndex])  yani  "<<D[i + 1]<<"<->"<<D[pivotIndex];
    swap(&D[i + 1], &D[pivotIndex]);
    if(D[i + 1].compare(D[pivotIndex])!= 0) q.swapCount++;
    cout<<"\ndizi  : "; q.p.diziYaz(D,rightIndex+1,leftIndex);

    cout<<"\n\nTum Dizi: "; q.p.diziYaz(D,rightIndex);

    return (i + 1);
}


/* The main function that implements QuickSort
    D[] --> Array to be sorted,
    leftIndex --> Starting index,
    rightIndex --> Ending index */
void  quickSort(int D[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        /* partitionIndex is partitioning index, D[p] is now at rightIndex place */
        int partitionIndex = partition(D, leftIndex, rightIndex);
        // Separately sort elements before // partition and after partition
        quickSort(D, leftIndex, partitionIndex - 1);
        quickSort(D, partitionIndex + 1, rightIndex);
    }
}


void  quickSort(string D[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        /* partitionIndex is partitioning index, D[p] is now at rightIndex place */
        int partitionIndex = partition(D, leftIndex, rightIndex);

        // Separately sort elements before // partition and after partition
        quickSort(D, leftIndex, partitionIndex - 1);
        quickSort(D, partitionIndex + 1, rightIndex);
    }
}


void Quicksort::hizlisirala(int *D, int leftIndex, int rightIndex) {
    cout<<endl<<"Quick Sort (Hizli Siralama Algoritmasi)";
    quickSort(D,  leftIndex,  rightIndex);
    cout<<endl<<"----------------- SONUC -----------------";
    cout<<endl<<"Toplam yer degistirme sayis: "<<q.swapCount;
    cout<<endl<<"toplam karsilastirma sayisi: "<<q.karsilastirma;
    cout<<endl<<"swaplar dizi uzerinde yapildiginden birlestirme islemine gerek yoktur.";
    cout<<endl<<"SONUC: ";
    Printarrays p;
    p.diziYaz(D,rightIndex);
    cout<<endl<<"------------------------------------"<<endl;
}

void Quicksort::hizlisirala(string *D, int leftIndex, int rightIndex) {
    cout<<endl<<"Quick Sort (Hizli Siralama Algoritmasi)";
    quickSort(D,  leftIndex,  rightIndex);
    cout<<endl<<"----------------- SONUC -----------------";
    cout<<endl<<"Toplam yer degistirme sayis: "<<q.swapCount;
    cout<<endl<<"toplam karsilastirma sayisi: "<<q.karsilastirma;
    cout<<endl<<"swaplar dizi uzerinde yapildiginden birlestirme islemine gerek yoktur.";
    cout<<endl<<"SONUC: ";
    Printarrays p;
    p.diziYaz(D,rightIndex);
    cout<<endl<<"------------------------------------"<<endl;

}
#endif //SORTINGALGORITMS_QUICKSORT_H
