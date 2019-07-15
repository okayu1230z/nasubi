#include <bits/stdc++.h>

using namespace std;

int main() {
    auto start_now = chrono::system_clock::now();
    auto start_ms = chrono::time_point_cast<chrono::milliseconds>(start_now);
    long start_unix = start_ms.time_since_epoch().count();
    cout << start_unix << endl;

    for (int i = 0; i < 1000000000; i++)
    {
        int a = 100;
    }

    auto end_now = chrono::system_clock::now();
    auto end_ms = chrono::time_point_cast<chrono::milliseconds>(end_now);
    long end_unix = end_ms.time_since_epoch().count();
    cout << end_unix << endl;


    cout << (double)(end_unix-start_unix) / 1000 << endl;
}