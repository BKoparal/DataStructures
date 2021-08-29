//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_PRINTARRAYS_H
#define SORTINGALGORITMS_PRINTARRAYS_H
#include <string>

using namespace std;

/*
    NOT: iki boyutlu diziden satir sayisi ve kolon sayisi elde etmek
    int satirSayisi =  sizeof D / sizeof D[0];
    int kolonSayisi = sizeof D[0] / sizeof(int);
 */


class Printarrays {
public:
    template<typename T>
    void diziYaz(T D[],int N,int left=0 );
    template< typename T, size_t N, size_t M >
    void diziYaz(T(&thearray) [N][M]);
};


//Since array size has to be known during compile time, we can use templates to provide flexibility to the function.
template< typename T, size_t N, size_t M >
void Printarrays:: diziYaz(T (&thearray)[N][M]) {
    cout <<endl;
    for (int satir = 0; satir < N; ++satir) {
        for (int sutun = 0; sutun < M; ++sutun){
            cout << thearray[satir][sutun] ;
            if(sutun<M-1) cout<<", ";
        }
        cout<<endl;
    }
    cout << setw(0);
}


template <typename T>
void Printarrays::diziYaz(T *D, int N, int start) {
    cout << right;
    for (int i = start; i < N; ++i) {
        cout << D[i] ;
        if(i<N-1) cout<<", ";
    }
    cout << setw(0);
}


#endif //SORTINGALGORITMS_PRINTARRAYS_H
