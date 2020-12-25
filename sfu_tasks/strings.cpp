#include <iostream>
#include <string>
#include <sstream>
using namespace std;

 void Is_digit(string & str) {
    for (int i = 0; i < str.size(); ++i){
        if (str[i]<'0'||str[i]>'9'){
            cout<<"Неверный формат даты!"<<endl;
            exit(0);
        }
    }
}

int To_int (string & str) {
    stringstream num;
    num << str;
    int x;
    num >> x;
    return x;
}

string To_string (int Int) {
    stringstream num;
    num << Int;
    string x;
    num >> x;
    return x;
}

void Is_correct_date(string & date) {
    bool format = (date[2]=='-'&&date[5]=='-'&&date[5]=='-');
    if (!format) {
        cout<<"Неверный формат даты!"<<endl;
        exit(0);
    }

    string Day = date.substr(0,2);
    string Month = date.substr(3,2);
    string Year = date.substr(6,4);
    Is_digit(Day);
    Is_digit(Month);
    Is_digit(Year);
    int day = To_int(Day);
    int month = To_int(Month);
    int year = To_int(Year);
    //cout<<Day<<"."<<Month<<"."<<Year<<endl;
    if (year%4 != 0&&year%100 == 0&&year%400 != 0) {
        if (month<=12) {
            int maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            month = month-1;
            if (day<=maxDays[month]) {
                cout<<Day<<"."<<Month<<"."<<Year[2]<<Year[3];
            }
            else {
                cout<<"Неверный формат даты!"<<endl;
                exit(0);
            }
        }
        else {
            cout<<"Неверный формат даты!"<<endl;
            exit(0);
        }
    }
    else {
        if (month<=12) {
            int maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            month = month-1;
            if (day<=maxDays[month]) {
                cout<<Day<<"."<<Month<<"."<<Year[2]<<Year[3];
            }
            else {
                cout<<"Неверный формат даты!"<<endl;
                exit(0);
            }
        }
        else{cout<<"Неверный формат даты!"<<endl;}
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    string mydate;
    cin >> mydate;
    Is_correct_date(mydate);
    return 0;
}
