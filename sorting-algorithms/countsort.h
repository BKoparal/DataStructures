#ifndef SORTINGALGORITMS_COUNTSORT_H
#define SORTINGALGORITMS_COUNTSORT_H


#include "myutil.h"

class Countsort {
private:
    MyUtil p;
public:
    void saymasiralama(int arr[], int n);
};


void Countsort::saymasiralama(int arr[], int n) {
    int countArrLength=getMax(arr,n)+1;
    cout<<"\nsiralanacak dizi: "; p.myPrintArray(arr,n);
    cout<<"\ncount sort basladi ";
    //dizileri olustur
    int output[n]; // output array
    int count[countArrLength];
    //Count dizisini sifirla doldur
    cout<<"\nAdim 1 count dizisini sifir ile doldur:"<<endl;
    for (int i = 0; i <=countArrLength; ++i)  count[i]=0;
    p.myPrintArray(count,countArrLength);
    cout<<"\ncount algoritmasi cout ve output dizilerini olusturur ve kullanir";
    cout<<"\nAdim 2. count dizisini hesapla:"<<endl;
    //siralanacak dizideki her eleman
    for (int i = 0; i < n; i++){
        int pozisyon=arr[i];
        //myPrintArray(count,10);
        count[pozisyon]++;
        cout<<pozisyon<<" elemani icin, count["<<pozisyon<<"] arttirildi "<<count[pozisyon]<<" oldu";
        //p.myPrintArray(count,countArrLength);
        cout<<endl;
    }

    cout<<"\ncount dizi su sekilde olusur: ";p.myPrintArray(count,countArrLength);
    //count dizi userinde kumulatif toplam
    for (int i = 1; i < countArrLength; i++)
        count[i] += count[i - 1];

    cout<<"\nAdim 3. KUMULATIF TOPLAM hesapla : "; p.myPrintArray(count,countArrLength);


    cout<<"\nAdim 4. output diziyi olustur\n";
    for (int i = n - 1; i >= 0; i--) {
        int hangiCountIndexi=arr[i];
        int hangiIndex=count[hangiCountIndexi] - 1;
        cout<<"dizi["<<i<<"]="<<hangiCountIndexi<<" ohalde count["<<hangiCountIndexi<<"] bak ";
        cout<< "count["<<hangiCountIndexi<<"]="<<count[hangiCountIndexi]<<" ve ";
        cout<<count[hangiCountIndexi]<<"-1 yap "<<hangiIndex<<" eder ohalde ";
        cout<<" output["<<hangiIndex<<"]="<<arr[i];
        cout<<endl;
        //cout<<"\noutput["<<hangiIndex<<"] ="<<arr[i];
        output[hangiIndex] = arr[i];

        count[hangiCountIndexi]--;
       // cout<<"\tve count["<<hangiCountIndexi<<"]-- ";
    }
    cout<<"\noutputa her eleman eklendiginde count dizinin ilgili indis degeri 1 eksiltilir.\ncount dizinin son durumu:\n";
    p.myPrintArray(count,countArrLength);cout<<endl;
    cout<<"\noutput dizi artik siralanmis dizidir"<<endl;
    cout<<"output dizi: "; p.myPrintArray(output,n);cout<<endl;

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
#endif //SORTINGALGORITMS_COUNTSORT_H
