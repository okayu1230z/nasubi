#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;

unordered_map<string, unsigned long int> ump;
hash<string> hash_fn;

void test_ump();
void print(unordered_map<string, unsigned long int>);
bool exist_ump(string);
int add_ump(string);
bool delete_ump(string);
int organize_ump(unsigned long int interval);
void *do_organize_pthread(void *pArgs);

int main()
{
    test_ump();
}

void test_ump()
{
    
    pthread_t handle;
    int interval = 3;
    pthread_create(&handle, NULL, do_organize_pthread, &interval);

    add_ump("2019/");
    for(int i=0; i < 10; i++){
        string s = "2019/07/17/" + to_string(i) + ".acc";
        add_ump(s);
    }

    print(ump);

    sleep(4);
    
    exist_ump("2019/");

    sleep(2);

    add_ump("2019/08/");
    for(int i=0; i < 10; i++){
        string s = "2020/07/17/" + to_string(i) + ".acc";
        add_ump(s);
    }
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

int organize_ump(unsigned long int memory_span)
{
    auto time_now = chrono::system_clock::now();
    auto time_ms = chrono::time_point_cast<chrono::milliseconds>(time_now);
    long time = time_ms.time_since_epoch().count();
    vector<string> vec_erase;

    for (auto itr = ump.begin(); itr != ump.end(); itr++)
    {
        if (time - itr->second > memory_span)
        {
            vec_erase.push_back(itr->first);;
        }
    }

    for(auto itr = vec_erase.begin(); itr != vec_erase.end(); ++itr) {
        delete_ump(*itr);
    }

    return 0;
}

void *do_organize_pthread(void *pArg)
{
    int *interval = (int*) pArg;
    unsigned long int memory_span = (*interval) * 1000;
    while(1) {
        sleep(*interval);
        organize_ump(memory_span);
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