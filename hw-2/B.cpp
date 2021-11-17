#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ios ::sync_with_stdio(false);

    int a[101];
    for (int i = 0; i < 101; i++)
        a[i] = 0;

    string str;
    getline(cin, str);
    istringstream ss(str);

    int index;
    while (ss >> index)
        a[index]++;

    for (int i = 0; i < 101; i++)
        if (a[i]) {
            a[i]--;
            cout << i-- << ' ';
        }

    return 0;
}

//7 3 4 2 5 2 3 4 10 50