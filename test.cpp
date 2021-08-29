#include <iostream>
#include <iomanip>
#include <cmath>
#include "insertsort.h"
#include "selectionsort.h"
#include "bublesort.h"
#include "quicksort.h"
#include "radixsort.h"
#include "countsort.h"
#include "heapsort.h"
#include "heapsort_string.h"
using namespace std;


int main() {
    Printarrays p;
    Insertsort i;
    Selectionsort s;
    Bublesort b;
    Quicksort q;
    Radixsort r;
    Countsort c;
    Heapsort h;
    Heapsort_string hs;


    int sirasizIntDizi[] = {15,12,4,44,25,70,96,6,55,47};
    //string sirasizStrDizi[]={"aAhmea","Mehmet","Abuzer","aYeliz","aMetin","aHalil","aaRiza","Bulent"};
    string sirasizStrDizi[]={"rush","korn","fixx","devo","cars","enya","devo","fuel","tato","blue","moby","abba","styx","dido","beck","cake","cher","mims","lons"};

    //int sirasizIntDizi[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    //int sirasizIntDizi[] = {117, 3, 523, 348, 562, 919, 104, 105, 326,48};
    // int sirasizIntDizi[] = {8000,2000,4000,5000,6000,7000,1000,3000,9000,9500};

    /* Dizi Boyutu N en usttedir */

    //i.arayaSokma(sirasizStrDizi, N);
    //i.arayaSokma(sirasizIntDizi, 8);
    //b.kabarcik(sirasizIntDizi,8);
    //s.secmelisirala(sirasizIntDizi,8);


    //q.hizlisirala(sirasizIntDizi,0,9);   //index istiyor yani leftIndex=0, rigthIndex ise diziBoyutu-1
    q.hizlisirala(sirasizStrDizi,0,18);
    //r.kovasirala(sirasizStrDizi,8);
    //c.saymasiralama(sirasizIntDizi,10);
    //printHeap(sirasizIntDizi,15);
    //hs.maxheapSort(sirasizStrDizi,8);
    //h.maxheapSort(sirasizIntDizi,10);
    //p.diziYaz(sirasizStrDizi,8);
    return 0;
}


/* iki boyutlu dizi oluştur ve fonksiyona gönder
 * int matrix[][3]={
         {1,2,3},
         {4,5,6},
         {7,8,9},
         {9,1,2},
         {5,2,7},
         {5,0,6} };
 p.diziYaz(matrix);*/