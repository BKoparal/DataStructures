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
#include "myutil.h"
using namespace std;

/* TEST function
 * for correct results dont forgot using tolower function for string arrays
 * */
int main() {
    MyUtil p;
    Insertsort i;
    Selectionsort s;
    Bublesort b;
    Quicksort q;
    Radixsort r;
    Countsort c;
    Heapsort h;
    Heapsort_string hs;

    //arrays
    int arrayINT[] = {15,12,4,44,25,70,96,6,55,47};
    string arraySTR[]={"RuSh","korn","fiXX","devo","cars","enya","blue","moby","abba","STYX","dido","beck","cake","cher"};

    //sizes of arrays
    int intArrLeng=sizeof arrayINT / sizeof arrayINT[0];
    int strArrLeng=sizeof arraySTR / sizeof arraySTR[0];

    //to lower str array
    p.mytolower(arraySTR,strArrLeng);

    /****** SORT ALGORITMS **********/


    //b.kabarcik(arraySTR,strArrLeng);
    //b.kabarcik(arrayINT, intArrLeng);

    //c.saymasiralama(arrayINT, intArrLeng);

    //i.arayaSokma(arraySTR,strArrLeng);
    //i.arayaSokma(arrayINT, intArrLeng);

    //s.secmelisirala(arraySTR,strArrLeng);
    //s.secmelisirala(arrayINT, intArrLeng);


    //q.hizlisirala(arraySTR,0,strArrLeng-1);;   //index istiyor yani leftIndex=0, rigthIndex ise diziBoyutu-1
    //q.hizlisirala(arrayINT, 0,intArrLeng-1);

    r.kovasirala(arrayINT, intArrLeng);
    //printHeap(sirasizIntDizi,15);
    //hs.maxheapSort(sirasizStrDizi,8);
    //h.maxheapSort(sirasizIntDizi,10);
    //p.myPrintArray(sirasizStrDizi,8);
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
 p.myPrintArray(matrix);*/