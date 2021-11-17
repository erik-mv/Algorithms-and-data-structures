#include <iostream>
#include <string>
using namespace std;

struct kings
{
    string name;
    string romNum;
    int arabNum;
};

int romToArab(string romNum)
{
    int n = romNum.length();
    int a[n];

    for (int i = 0; i < n; i++)
        switch (romNum[n - 1 - i])
        {
        case 'I':
            a[i] = 1;
            break;
        case 'V':
            a[i] = 5;
            break;
        case 'X':
            a[i] = 10;
            break;
        case 'L':
            a[i] = 50;
            break;
        }

    int sum = a[0];
    for (int i = 1; i < n; i++)
        if (3 * a[i] < sum)
            sum -= a[i];
        else
            sum += a[i];

    return sum;
}

void sortNum(kings king[], int n)
{
    if (n == 1)
        return;

    int m = n / 2;
    sortNum(king, m);
    sortNum(king + m, n - m);

    kings *temp = new kings[n + 1];
    int l = 0, r = m, i = 0;
    while (n > i)
    {
        if (l >= m || r < n && king[r].arabNum < king[l].arabNum)
            temp[i++] = king[r++];
        else
            temp[i++] = king[l++];
    }

    copy(temp, temp + i, king);
    delete[] temp;
}

void sortName(kings king[], int n)
{
    if (n == 1)
        return;

    int m = n / 2;
    sortName(king, m);
    sortName(king + m, n - m);

    kings *temp = new kings[n + 1];
    int l = 0, r = m, i = 0;
    while (n > i)
    {
        if (l >= m || r < n && king[r].name < king[l].name)
            temp[i++] = king[r++];
        else
            temp[i++] = king[l++];
    }

    copy(temp, temp + i, king);
    delete[] temp;
}

int main()
{
    std ::ios ::sync_with_stdio(false);

    int n;
    cin >> n;

    kings king[n];
    for (int i = 0; i < n; i++)
    {
        cin >> king[i].name;
        cin >> king[i].romNum;
        king[i].arabNum = romToArab(king[i].romNum);
    }

    sortNum(king, n);
    sortName(king, n);

    for (int i = 0; i < n; i++)
        cout << king[i].name << ' ' << king[i].romNum << '\n';

    return 0;
}

/*
10
Philip XVII
Louis XL
Philippe XLIX
Louis V
Louis I
Louis II
Philippe III
Louis IV
Louis IX
Louis VIII
*/