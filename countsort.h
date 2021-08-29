#ifndef SORTINGALGORITMS_COUNTSORT_H
#define SORTINGALGORITMS_COUNTSORT_H


class Countsort {
public:
    void saymasiralama(int arr[], int n);
};
/*
 void saymasiralama(int sirasizDizi[], int n) {
    //count dizisinin size ni bulmak ici gelen dizideki max elemani bul
    int countArrLength=sirasizDizi[0];
    for (int i = 1; i < n; ++i) {
        if(sirasizDizi[i]>countArrLength)
            countArrLength=sirasizDizi[i];
    }

    //count ve output dizilerini olustur
    int output[n]; // output sirasizDiziay
    int count[countArrLength];

    //Count dizisini sifirla doldur
    for (int i = 0; i <=countArrLength; ++i)
        count[i]=0;

    //siralanacak dizideki her eleman icin elemanin degerini indis olarak kullanarak count dizideki degeri 1 attir.
    for (int i = 0; i < n; i++){
        int pozisyon=sirasizDizi[i];
        count[pozisyon]++;
    }

    //count dizi uzerinde kumulatif toplam  butun elemanlari toplayarak ilerle
    for (int i = 1; i < countArrLength; i++)
        count[i] += count[i - 1];

    //output dizi hesaplanacak
    //formul şu: dizinin i'inci elemanini count dizisinde indis olarak kullanmak icin al,
    //counttaki indis elemani da indis_output olarak al ve indis_output'u 1 eksilt output dizide indis olarak  indis_output kullanilacak
    //outputun indis_output'ine ise dizinin i indisli elemanini yerlestir ve sonra counttaki degeri bir eksilt
    for (int i = n - 1; i >= 0; i--) {
        int hangiCountIndexi=sirasizDizi[i];
        int hangiIndex=count[hangiCountIndexi] - 1;
        output[hangiIndex] = sirasizDizi[i];
        count[hangiCountIndexi]--;
    }
    //artik elimizde duzgun siralanmis output dizisi var ve bu diziyi sirasiz diziye aktar
    for (int i = 0; i < n; i++)
        sirasizDizi[i] = output[i];
}
 */


void Countsort::saymasiralama(int arr[], int n) {
    int countArrLength=getMax(arr,n)+1;
    cout<<"\nsiralanacak dizi: "; p.diziYaz(arr,n);
    cout<<"\ncount sort basladi ";
    //dizileri olustur
    int output[n]; // output array
    int count[countArrLength];
    //Count dizisini sifirla doldur
    cout<<"\nAdim 1 count dizisini sifir ile doldur:"<<endl;
    for (int i = 0; i <=countArrLength; ++i)  count[i]=0;
    p.diziYaz(count,countArrLength);
    cout<<"\ncount algoritmasi cout ve output dizilerini olusturur ve kullanir";
    cout<<"\nAdim 2. count dizisini hesapla:"<<endl;
    //siralanacak dizideki her eleman
    for (int i = 0; i < n; i++){
        int pozisyon=arr[i];
        //diziYaz(count,10);
        count[pozisyon]++;
        cout<<pozisyon<<" elemani icin, count["<<pozisyon<<"] arttirildi "<<count[pozisyon]<<" oldu";
        //p.diziYaz(count,countArrLength);
        cout<<endl;
    }

    cout<<"\ncount dizi su sekilde olusur: ";p.diziYaz(count,countArrLength);
    //count dizi userinde kumulatif toplam
    for (int i = 1; i < countArrLength; i++)
        count[i] += count[i - 1];

    cout<<"\nAdim 3. KUMULATIF TOPLAM hesapla : "; p.diziYaz(count,countArrLength);


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
    p.diziYaz(count,countArrLength);cout<<endl;
    cout<<"\noutput dizi artik siralanmis dizidir"<<endl;
    cout<<"output dizi: "; p.diziYaz(output,n);cout<<endl;

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
#endif //SORTINGALGORITMS_COUNTSORT_H
