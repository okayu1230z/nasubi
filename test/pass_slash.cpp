#include <string>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

vector<string> split_path(const string, char);

int main () {
    string path = "/mnt/nas04";
    vector<string> vec_path = split_path(path, '/');

    for(int i=0; i < vec_path.size(); i++)
        cout << vec_path[i] << endl;

    return 0;
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