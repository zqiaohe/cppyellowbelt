#include <iostream>
#include <cmath>
using namespace std;

float* read_array(float a[], int len);
void print_array(float arr[], int len);
void Sort(float arr[], int len, bool asc);

float* read_array(float a[], int len)
{
    float* ptr;
    float s;
    for (ptr = a; ptr - a < len; ptr++)
    {
        cin >> s;
        *ptr = s;
    }
    return a;
}
void print_array(float arr[], int len)
{
    float* ptr;
    for (ptr = arr; ptr - arr < len; ptr++)
        cout << *ptr << " ";
    cout << endl;
}

void print_array(int arr[], int len)
{
    int* ptr;
    for (ptr = arr; ptr - arr < len; ptr++)
        cout << *ptr << " ";
    cout << endl;
}

void Swap(float& a, float& b)
{
    float c = a;
    a = b;
    b = c;
}

void Sort(float arr[], int len, bool asc)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (asc)
                if (arr[i] > arr[j])
                    Swap(arr[i], arr[j]);
            else
                if (arr[i] < arr[j])
                    Swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int len, k = 0;
    cout << "Введите количество элементов:" << endl;
    cin >> len;
    float* a = new float[len];
    cout << "Введите элементы массива A:" << endl;
    read_array(a, len);
    float* b = new float[len];
    cout << "Введите элементы массива B:" << endl;
    read_array(b, len);
    float* d = new float[len];//расстояние до центра
    float* e = new float[len];//расстояние до центра v2, в условии должен был быть C
    float* c = new float[len];//четверти
    float* ptra, * ptrb, * ptrd, * ptre, * ptrc;

    //отмечаем четверти
    for (ptra = a, ptrb = b, ptrd = d, ptrc = c, ptre = e; ptra - a < len; ptra++, ptrb++, ptrd++, ptrc++, ptre++)
    {
        *ptrd = sqrt(pow((*ptra - 0), 2) + pow((*ptrb - 0), 2));//считаем и заполняем d. A - ординаты, B - абсциссы, должно было быть наоборот, простите, пожалуйста
        *ptre = *ptrd;// заполняем е
        //cout<<*ptrd<<endl;
        if (*ptra >= 0 && *ptrb > 0)
            *ptrc = 1; //заполняем с
        if (*ptra < 0 && *ptrb >= 0)
            *ptrc = 2;
        if (*ptra <= 0 && *ptrb < 0)
            *ptrc = 3;
        if (*ptra < 0 && *ptrb > 0)
            *ptrc = 4;
    }

    Sort(d, len, 1);
    float* s = ptrd;
    for (ptrd = d; ptrd - d < len; ptrd++)
    {
        if (*s == *ptrd)
            ++k;
        else
        {
            *s = *ptrd;
            k = 1;
        }
    }
    if (k < 3)
        cout << "Трёх равноудаленных точек нет!";
    else
    {
        //cout << endl << k << endl;
        int part[100];
        int nums[100];
        int i = 0;
        print_array(c, k);
        for (ptre = e, ptrc = c; ptre - e < len; ptre++, ptrc++)
        {
            if (*ptre == *s)
            {
                nums[i] = ptre - e;
                part[i] = *ptrc;
                ++i;
            }

        }
        int ch0 = 0;
        int ch1 = 0;
        int ch2 = 0;
        int ch3 = 0;
        int ch4 = 0;
        for (int i = 0; i <= k; i++)
        {
            //cout<<part[i]<<endl;
            if (ceil(part[i]) == 0) ch0 = 1;
            if (ceil(part[i]) == 1) ch1 = 1;
            if (ceil(part[i]) == 2) ch2 = 1;
            if (ceil(part[i]) == 3) ch3 = 1;
            if (ceil(part[i]) == 4) ch4 = 1;
        }
        //cout<<"CH"<<endl;
        //cout << ch0 +ch1 + ch2 + ch3 + ch4<<0;
        if (ch0 +ch1+ch2+ch3+ch4>=3)
            print_array(nums, 3);//все в разных четвертях
        else
            cout << "Трёх равноудаленных точек в разных четвертях нет!";
    }
    system("pause");
    return 0;
}
// 3 -1 -1 1
// 1 3 -3 -3

/*Введите количество элементов:
4
Введите элементы массива A:
1 2 2 -2
Введите элементы массива B:
2 1 -1 -1
Трёх равноудаленных точек в разных четвертях нет!
Для продолжения нажмите любую клавишу . . .



*/
