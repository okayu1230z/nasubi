#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <vector>

#include <unordered_map>
#include <chrono>

//#include <bits/stdc++.h>

using namespace std;

vector<string> split_path(const string path, char seq);
static int mkdir_parents_process_test(const char *path, mode_t mode);
void print(unordered_map<string, unsigned long int>);
bool exist_ump(string);
int add_ump(string);
bool delete_ump(string);

unordered_map<string, unsigned long int> ump;

int main() {
    mkdir_parents_process_test("/1996/05/07", 0777);

    print(ump);
}

static int mkdir_parents_process_test(const char *path, mode_t mode) {
    vector<string> vec_path = split_path(path, '/');

    string s = "";
    for(auto itr = vec_path.begin(); itr != vec_path.end(); ++itr)
    {
        //    cout << *itr << endl;
        if(*itr != "") {
            s = s + "/" + *itr;
            //cout << s << endl;
            add_ump(s);
        }
    }

    print(ump);

    string s_path = path;
    delete_ump(s_path);
}

vector<string> split_path(const string path, char seq) {
    vector<string> vec_path;
    stringstream ss_path(path);
    string buffer;
    while(getline(ss_path, buffer, seq)) {
        vec_path.push_back(buffer);
    }
    return vec_path;
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