#include <iostream>

using namespace std;

void pfunction(string str, int* p) {
    int n = str.length();

    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int k = p[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = p[k - 1];
        }

        if (str[i] == str[k]) {
            k++;
        }

        p[i] = k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str_p;
    string str_t;
    cin >> str_p >> str_t;

    str_t = str_p + "#" + str_t;

    int* p = new int[str_t.length()];
    pfunction(str_t, p);

    string result;
    int number_entry = 0;
    for (size_t i = str_p.length(); i < str_t.length(); ++i)
        if (str_p.length() == p[i]) {
            ++number_entry;
            result += to_string(i + 1 - 2 * str_p.length()) + " ";
        }

    result = to_string(number_entry) + "\n" + result;
    cout << result;

    delete[] p;
    return 0;
}