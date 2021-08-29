//
// Created by blnk on 29.08.2021.
//

#ifndef SORTINGALGORITMS_HEAPSORT_H
#define SORTINGALGORITMS_HEAPSORT_H


class Heapsort {
private:
    int swapCount;
    int heapifyCount;
    void heapify(int array[] , int i, int m,int N);
    void swapKeys(int array[], int i, int j,int N);
    void printHeap(int array[],int N);

public:
    //constructure
    Heapsort(): swapCount(0),heapifyCount(0){};

public:
    void maxheapSort(int array[],int N);
};


void Heapsort::printHeap(int array[],int N){
    int logResult=(double) log2(N);
    int boslukSabiti=8;
    int maxGenislik=1;
    for (int i = 0; i <logResult; ++i) maxGenislik*=2;
    int sabitGenislik=boslukSabiti*maxGenislik;
    cout<<endl;
    int dugumSayisi=1;
    for (int i = 0; i < N; ++i) {
        int bosluk1=(sabitGenislik-dugumSayisi)/(dugumSayisi+1);
        for (int j = 0; j < dugumSayisi && i<N; ++j,++i) {
            for (int k = 0; k<bosluk1; ++k)  cout<<" ";
            cout<<array[i];
        }

        i--;
        cout<<"\n\n";
        dugumSayisi*=2;
    }
}




 void Heapsort::maxheapSort(int array[], int N) {
     cout<<"\nBaslangic dizisi: "; p.diziYaz(array,N);cout<<endl;
     cout<<"\nBaslangic dizisinin agaca sirasiyla eklenmesi: ";
     printHeap(array,N);
     cout<<"\n\n                               **   MAX HEAP  ** "<<endl;
     cout<<"                        HEAP AGACI OLUSTURMA ADIMLARI "<<endl<<endl;
     cout<<"yaprak olmayan son dugumu heapify 'e gonder. formulu: (diziLength-2)/2 yani index: "<<(N - 2) / 2<<endl;
     cout<<"NOT: heapify hangi elemana yapiliyorsa asagi dogru tum dugumler bitene kadar calisir"<<endl;
     cout<<"ama asla daha yukarida olan bir eleman icin calismaz. (yani yukari dogru calismaz)"<<endl;
    for (int i = (N - 2) / 2; i >= 0; i--)
        heapify( array , i , N - 1,N );

    int araSwap= swapCount;
    int araHeapify= heapifyCount;

    cout<<"             YUKARIDA HEAP AGACI OLUSTURULDU VE   "<<endl;
    cout<<"           BURADAN SONRASI AGACTAN SILME ISLEMLERI "<<endl;
    cout<<"               YANI SIRALI DIZI OLUSTURULUYOR "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"buradan asamadan sonra heapify root icin cagrilacaktir."<<endl;
    for (int i = N - 1; i > 0; i--) {
        cout<<"(En sondaki dugum ile root yer degistirilir yani, )";
        swapKeys( array , 0 , i,N);
        heapify(array , 0 , i - 1,N );
    }
     cout<<"\n-------------------------------- SONUC ----------------------------"<<endl;
     cout<<"Heap agaci olusturulurken swap sayisi     : "<<araSwap<<endl;
     cout<<"Heap agaci olusturulurken heapify cagirma : "<<araHeapify<<endl;
     cout<<"Tum Program Boyunca toplam swap sayisi    : "<<swapCount<<endl;
     cout<<"Tum Program Boyunca toplam heapify sayisi : "<<heapifyCount<<endl;
     cout<<"-------------------------------------------------------------------"<<endl;
 }




 void Heapsort::heapify(int array[], int i, int m,int N) {
    heapifyCount++;
    cout<<"\nheapify "<<array[i]<<" icin" <<endl;
    int j;
    while ( 2 * i + 1 <= m ) {
        j = 2 * i + 1;
        if ( j < m ) {
            cout<<"if "<<array[j]<<" < "<<array[j + 1]<<", ";
            if ( array[j] < array[j + 1] )
                j++;
        }
        cout<<"if "<<array[i]<<" < "<<array[j]<<"  ";
        if (array[ i ] < array[ j ]) {
            swapKeys( array , i , j,N);
            i = j;
        } else
            i = m;
    }
    cout<<endl<<endl;
}




void Heapsort::swapKeys(int array[], int i, int j,int N) {
    swapCount++;
    int temp;
    cout<<"\nafter swap "<<array[ i ]<<"<->"<<array[ j ]<<"  : ";
    temp = array[ i ];
    array[ i ] = array[ j ];
    array[ j ] = temp;
    p.diziYaz(array,N);cout<<"\n";
    printHeap(array,N);cout<<endl;
}



#endif
