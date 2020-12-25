#include <iostream>
#include <cmath>
using namespace std;

float *read_array(int len);
void print_array(float arr[], int len);
void Sort(float arr[], int len,  bool asc);

float *read_array(int len) {
    float *a = new float[len];
    float * ptr;
    float s;
    for ( ptr = a; ptr-a < len; ptr++ ) {
        cin >> s;
        * ptr = s;
    }
    return a;
}
void print_array(float arr[], int len) {
    float * ptr;
    for ( ptr = arr; ptr-arr < len; ptr++ ){cout << *ptr << " ";}
    cout<<endl;
}

void Swap (float& a, float& b ){ float c(a); a=b; b=c;}

void Sort(float arr[], int len, bool asc) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len; j++) {
            if (asc) {
                if(arr[i] > arr[j]) Swap(arr[i], arr[j]);
            }
            else {
                if(arr[i] < arr[j]) Swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int len;
    cin >> len;
    float * a = read_array(len);
    float * b = read_array(len);
    float * d = new float[len];
    float * e = new float[len];
    float * c = new float[len];
    float * ptra, * ptrb, * ptrd, * ptre, *ptrc;

    //отмечаем четверти
    for ( ptra = a, ptrb = b, ptrd = d, ptrc = c, ptre = e; ptra-a < len; ptra ++, ptrb++, ptrd++, ptrc++, ptre ++ ) {
        * ptrd = sqrt(pow((* ptra-0),2)+pow((* ptrb-0),2));
        * ptre = *ptrd;
        if (*ptra>=0&&*ptrb>0) {*ptrc = 1;}
        if (*ptra<0&&*ptrb>=0) {*ptrc = 2;}
        if (*ptra<=0&&*ptrb<0) {*ptrc = 3;}
        if (*ptra<0&&*ptrb>-0) {*ptrc = 4;}
    }

    Sort(d, len, 1);
    float *s = ptrd;
    int k = 0;
    for ( ptrd = d; ptrd-d < len; ptrd ++ ) {
        if (*s == * ptrd) {
            ++k;
            if (k>=3) break;
        }
        else {
            *s = * ptrd;
            k = 1;
        }
    }
    if (k < 3) cout<< "Трёх равноудаленных точек нет!";
    else {
        float part[3];
        float nums[3];
        int i=0;
        for ( ptre = e, ptrc = c; ptre-e < len; ptre ++, ptrc ++ ) {
            if (*ptre == *s) {
                nums[i] = ptre-e;
                part[i] = *ptrc;
                ++i;
            }
        }
        if (part[0]!=part[1]&&part[1]!=part[2]&&part[2]!=part[0]) print_array(nums, 3);
        else cout<<"Трёх равноудаленных точек в разных четвертях нет!";
    }
    return 0;
 }
