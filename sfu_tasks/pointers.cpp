#include <iostream>

using namespace std;

int *read_array(int len);
void print_array(int arr[], int len);
int my_task(int A[], int lenA, int B[], int lenB);
int *find_last_positive_index();
int *read_array(int len) {
    int *a = new int[len];
    int * ptr;
    int s;
    for ( ptr = a; ptr-a < len; ptr++ ) {
        cin >> s;
        * ptr = s;
    }
    return a;
}
void print_array(int arr[], int len) {
    int *ptr;
    for ( ptr = arr; ptr-arr < len; ptr++ ) {
        cout << *ptr << endl;
    }
}
int find_last_positive_index(int A[], int len){
    int *ptr;
    int *posptr;
    for ( ptr = A; ptr-A < len; ptr++ ) {
        if (*ptr > 0) *posptr = ptr-A;
    }
    int ind = *posptr;
    return ind;
}
int my_task(int A[], int lenA, int B[], int lenB) {
    int count = 0;
    int *ptr;
    int *ptr1;
    //cout<< "MY_TASK" << endl;
    int posind = find_last_positive_index(A, lenA);
    ptr1 = B;
    for ( ptr = A; ptr-A < lenA; ptr++) {
        if (ptr-A > posind) {
            *ptr1 = *ptr;
            //cout << *ptr1 << endl;
            ptr1++;
            ++ count;
        }
    }
    return count;
}
int main() {

    int * ptr;
    int len;
    cin >> len;
    int * a = read_array(len);
    int b [len];
    int Count = my_task(a, len, b, len);
    cout<<Count<<endl;
    print_array(b, Count);
return 0;
 }
