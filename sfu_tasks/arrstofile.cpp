#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    fstream file("C:/inputyes.txt"); // ������ ������
    string line;
    string newfile = "";
    if (!file.is_open()) // ���� ���� �� ������
		cout << "���� �� ������!\n"; // �������� �� ����
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
    file.close(); // ��������� ����
    return 0;
}
