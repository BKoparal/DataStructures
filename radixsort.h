//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_RADIXSORT_H
#define SORTINGALGORITMS_RADIXSORT_H
#include <string>

#include "printarrays.h"

Printarrays p;

class Radixsort {
private:
    Printarrays p;
public:
    void kovasirala(int D[], int N);
    void kovasirala(string D[], int N );
};


/* RADIX SORT */

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

int getMax(string arr[], int n) {
    string mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i].length() > mx.length())
            mx = arr[i];
    return mx.length();
}



// A function to do counting sort of arr[] according to
// the digit represented by countDizininBoyutu.
void countSort(int arr[], int n, int countDizininBoyutu)
{
    cout<<"\nsiralanacak dizi: "; p.diziYaz(arr,n);
    cout<<"\ncount sort basladi ";
    int output[n]; // output array
    int i, count[10] = { 0 };
    cout<<"\ncount algoritmasi cout ve output dizilerini olusturur ve kullanir";
    cout<<"\nher basamaktaki rakamlar 10 tane olacagindan  10 elemanli olan count dizisi olusturulup sifirlarla dolduruldu";
    cout<<"\nAsama 1 count dizisini doldur:"<<endl;
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++){
        int index=(arr[i] / countDizininBoyutu) % 10;
        //diziYaz(count,10);
        cout<<arr[i]<<"'nin "<<countDizininBoyutu<<" basamagindaki sayi indextir, count["<<index<<"] arttirildi son hali: ";
        count[index]++;
        p.diziYaz(count,10);
        cout<<endl;
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    cout<<"           KUMULATIF TOPLAM : "; p.diziYaz(count,10);


    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        int hangiCountIndexi=(arr[i] / countDizininBoyutu) % 10;
        int hangiIndex=count[hangiCountIndexi] - 1;

        cout<<"\noutput["<<hangiIndex<<"] ="<<arr[i];
        output[hangiIndex] = arr[i];

        count[hangiCountIndexi]--;
        cout<<"\tve count["<<hangiCountIndexi<<"]-- yap ";
    }
    cout<<"\ncount dizi : "; p.diziYaz(count,10);cout<<endl;
    cout<<"\noutput dizi: "; p.diziYaz(output,n);cout<<endl;

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void Radixsort::kovasirala(int D[], int n) {
    int maxEleman = getMax(D, n); // Find the maximum number to know number of digits
    cout<< "max deger= "<<maxEleman;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, countDizininBoyutu is passed. countDizininBoyutu is 10^i
    // where i is current digit number
    for (int countDizininBoyutu = 1; maxEleman/ countDizininBoyutu > 0; countDizininBoyutu *= 10){
        cout<<"\ncountSort(dizi[], diziBoyutu="<<n<<","<<countDizininBoyutu<<") cagriliyor";
        cout<<"\n**********************************************";
        countSort(D, n, countDizininBoyutu);
    }
}


string mytolower(string s) {
    locale loc;
    for (string::size_type i = 0; i<s.length(); ++i)
        s[i] = tolower(s[i], loc);
    return s;
}


void countSort(string arr[], int n, int siralananIndex) {
    cout<<"\nsiralanacak dizi: "; p.diziYaz(arr,n);
    cout<<"\ncount sort basladi ";
    string output[n]; // output array
    int i, count[26] = { 0 };
    cout<<"\ncount algoritmasi cout ve output dizilerini olusturur ve kullanir";
    cout<<"\nher basamaktaki harfler max 26 tane olacagindan  26 elemanli olan count dizisi olusturulup sifirlarla dolduruldu";
    cout<<"\nilk asama count dizisini olustur her kelimenin "<<siralananIndex<<" karakterine gore" <<endl;
    cout<<"-----------------------------------------------"<<endl;
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++){
        char ch=arr[i].at(siralananIndex);
        int index=ch-97;//alfabedeki sirasina gore sirala
        //diziYaz(count,10);
        cout<<arr[i]<<" -> "<<ch<<" count["<<index<<"] arttirildi ";
        count[index]++;
        p.diziYaz(count,26);
        cout<<endl;
    }

    for (i = 1; i < 26; i++)
        count[i] += count[i - 1];
    cout<<"\nAsama 2: KUMULATIF TOPLAM = "; p.diziYaz(count,26);

    cout<<"\nAsama 3: Output dizisini olustur";
    for (i = n - 1; i >= 0; i--) {
        int chIndex=arr[i].at(siralananIndex)-97;
        int hangiIndex=count[chIndex] - 1;
        cout<<"\noutput["<<hangiIndex<<"] ="<<arr[i];
        output[hangiIndex] = arr[i];

        count[chIndex]--;
        cout<<"\tve count["<<chIndex<<"]-- ";
    }
    cout<<"\ncount dizi : "; p.diziYaz(count,26);cout;
    cout<<"\noutput dizi: "; p.diziYaz(output,n);cout<<endl;

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}




void Radixsort::kovasirala(string D[], int N) {
    int len=D[0].length();
    for (int i = 0; i < N; ++i) {
        if(len!=D[i].length()){
            cout<<"\n\nHATA\nDizinizde yer alan butun kelimelerin lengthi esit olmak zorunda..  ";
            return;
        }
        D[i]= mytolower(D[i]); //butun diziyi kucuk harfe cevir
    }

    int m = getMax(D, N);
    cout<< "max uzunluktaki kelime = "<<m<<" yani countsort "<<m<< " defa cagrilacak";
    for (int i = m-1; i >=0; --i) {
        countSort(D, N, i);
    }
}


#endif //SORTINGALGORITMS_RADIXSORT_H
