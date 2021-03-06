#include <bits/stdc++.h>

using namespace std;

hash<string> hash_fn;

class HashClass
{
public:
    size_t operator()(constvector<string> &x) const
    {
        unsigned long int hash_value = hash_fn(x[0]);
        cout << x[0] << ", "<< x[1] << ", " << hash_value << endl;
        return hash_value;
    }
};

void test_ump();
void print_ump(unordered_map<vector<string>, unsigned long int, HashClass>);
bool exist_ump(string);
int add_ump(string);
//int delete_ump(string);

unordered_map<vector<string>, unsigned long int, HashClass> ump;

int main()
{
    test_ump();
}

void test_ump()
{
    //    add_ump("acc/2019/07/16/acc.log");

    add_ump("2019/07/17");
    add_ump("2019/07/18");

    for (int i = 0; i < 1000000000; i++)
    {
        int a = 100;
    }

    add_ump("2019/07/17");
    add_ump("2019/07/18");

    print_ump(ump);

    exist_ump("2019/07/17");
}


bool exist_ump(string file_pass) 
{
    unsigned long int hash_key = hash_fn(file_pass);
    vector<string> tmp = {file_pass, "a"};
    auto itr = ump.find(tmp);
    if(itr != ump.end()) {
        cout << file_pass <<" is existed" << endl;
        return true;
    } else {
        cout << file_pass <<" is not existed" << endl;
        return false;
    }
}


int add_ump(string file_pass)
{
    unsigned long int hash_key = hash_fn(file_pass);
    auto time_now = chrono::system_clock::now();
    auto time_ms = chrono::time_point_cast<chrono::milliseconds>(time_now);
    long time_unix = time_ms.time_since_epoch().count();
    //vector<string> tmp = {file_pass, to_string(time_unix)};
    vector<string> tmp = {file_pass, ""};
    ump[tmp] = hash_key;
    return 0;
}

/*
int delete_ump(string file_pass) 
{
    auto itr = ump.find(file_pass);
    if(itr != ump.end()) {
        ump.erase(itr);
        return true;
    } else {
        return false;
    }
}
*/

void print_ump(unordered_map<vector<string>, unsigned long int, HashClass>)
{
    for (auto itr = ump.begin(); itr != ump.end(); ++itr)
    {
        cout << "key = " << itr->first[0] << ", val = " << itr->second << ", last-ref = " << itr->first[1] << "\n";
    }
}