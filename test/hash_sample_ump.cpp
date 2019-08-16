//#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libgen.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include <unordered_map>
#include <chrono>

using namespace std;

unordered_map<string, unsigned long int> ump;
hash<string> hash_fn;

void test_ump();
void print(unordered_map<string, unsigned long int>);
bool exist_ump(string);
int add_ump(string);
bool delete_ump(string);

int main()
{
    test_ump();
}

void test_ump()
{
    add_ump("2019/");
    for(int i=0; i < 10; i++){
        string s = "2019/07/17/" + to_string(i) + ".acc";
        add_ump(s);
    }

    print(ump);

    sleep(4);

    add_ump("2019/08/");
    add_ump("2019/07/17/1.acc");

    print(ump);
    
}

bool exist_ump(string file_pass)
{
    auto time_now = chrono::system_clock::now();
    auto time_ms = chrono::time_point_cast<chrono::milliseconds>(time_now);
    long time = time_ms.time_since_epoch().count();
    auto itr = ump.find(file_pass);
    if (itr != ump.end())
    {
        itr->second = time;
        return true;
    }
    else
    {
        return false;
    }
}

int add_ump(string file_pass)
{
    auto time_now = chrono::system_clock::now();
    auto time_ms = chrono::time_point_cast<chrono::milliseconds>(time_now);
    long time = time_ms.time_since_epoch().count();
    ump[file_pass] = time;
    return 0;
}

bool delete_ump(string file_pass)
{
    auto itr = ump.find(file_pass);
    if (itr != ump.end())
    {
        ump.erase(itr);
        return true;
    }
    else
    {
        return false;
    }
}

void print(unordered_map<string, unsigned long int> tmp_ump)
{
    for (auto itr = tmp_ump.begin(); itr != tmp_ump.end(); ++itr)
    {
        cout << "key = " << itr->first << ", val = " << itr->second << "\n";
    }
    cout << "" << endl;
}