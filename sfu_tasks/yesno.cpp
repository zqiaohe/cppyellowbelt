#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    ifstream file("C:/inputyes.txt"); // создаём объект
    string line;
    string newfile = "";
    if (!file.is_open()) // если файл не открыт
		cout << "Файл не найден!\n"; // сообщить об этом
    else{
        while (getline(file, line)) {
            string myline = "";
            for (int i = 0; i < line.size(); ++i) {
                if (line[i]=='Y'&&line[i+1]=='E'&&line[i+2]=='S'){
                    myline = myline + "NO";
                    i = i + 2;
                    continue;
                }
                else {
                    myline = myline + line[i];
                }
            }
            newfile = newfile + myline + "\n";
        }
        cout<<newfile;
    }
    file.close(); // закрываем файл
    ofstream out("C:/inputyes.txt");
    if (out.is_open())
    {
        out << newfile;
    }
    out.close();
    return 0;
}

