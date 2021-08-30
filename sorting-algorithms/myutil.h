//
// Created by blnk on 28.08.2021.
//

#ifndef SORTINGALGORITMS_MYUtil_H
#define SORTINGALGORITMS_MYUtil_H
//#include <string>

using namespace std;

class MyUtil {
public:
    template<typename T> void myPrintArray(T D[],int N,int left=0 );                //for printing string and int arrays
    template< typename T, size_t N, size_t M > void myPrintArray(T(&thearray) [N][M]);  //for printing string and int matrix
    int mycompare(int first, int second);                          //compare two int
    int mycompare(string first, string second);                    //compare two string
    string mytolower(string word);                                 //to lower case
    void mytolower(string D[],int N);
    template<typename  T>
    void swap(T* a, T* b);

};


//Since array size has to be known during compile time, we can use templates to provide flexibility to the function.
template< typename T, size_t N, size_t M >
void MyUtil:: myPrintArray(T (&thearray)[N][M]) {
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
void MyUtil::myPrintArray(T *D, int N, int start) {
    cout << right;
    for (int i = start; i < N; ++i) {
        cout << D[i] ;
        if(i<N-1) cout<<", ";
    }
    cout << setw(0);
}


//overload functions 
int MyUtil::mycompare(int first, int second){
    if(first==second) return 0;
    if(first<second) return -1;
    return 1;
}

int MyUtil::mycompare(string first, string second){
    return first.compare(second);
}

string MyUtil::mytolower(string word) {
    locale l;
    for (string::size_type i = 0; i<word.length(); ++i)
        word[i] = tolower(word[i], l);
    return word;
}

void MyUtil::mytolower(string D[],int N) {
    for (int i = 0; i < N; ++i) {
        D[i]= mytolower(D[i]);
    }
}

template<typename  T>
void MyUtil::swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

#endif //SORTINGALGORITMS_MYUtil_H
