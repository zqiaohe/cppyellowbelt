#include <iostream>

using namespace std;

int main()
{
    int n, d, m, x, y;
    cin >> n >> d >> m;
    for (int i = 0; i < m; ++i) {
        cin>>x>>y;
        if (d*x+d*y-d*d < 0) {cout << "NO" << endl;
        continue;
        }
        if ((d-n)*x + (n-d)*y - (n-d)*d > 0) {cout << "NO" << endl;
        continue;
        }
        if (d*x + d*y + ((n-d)*(n-d) - n*n) > 0) {cout << "NO" << endl;
        continue;
        }
        if (((n-d)*x) + ((d-n)*y) - d*(n-d) > 0) {cout << "NO" << endl; continue;}
        else { cout<< "YES" << endl; continue;}
    }
    return 0;
}
