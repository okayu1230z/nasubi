#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unsigned long int> ump;
hash<string> hash_fn;

void test_ump();
void print_ump(unordered_map<string, unsigned long int>);
bool exist_ump(string);
int add_ump(string);
int delete_ump(string);

int main() {
    test_ump();
}

void test_ump() {
//    add_ump("acc/2019/07/16/acc.log");

    add_ump("2019/07/17");
    add_ump("2019/07/18");
    add_ump("2019/08/17");

    print_ump(ump);

    if(exist_ump("2019/08/17")) cout << "2019/08/17" <<" is exist" << "\n";
    if(exist_ump("aiueo")) cout << "aiueo" <<" is exist" << "\n";
    
    delete_ump("2019/08/17");
    delete_ump("aiueo");

    print_ump(ump);
    
    if(exist_ump("2019/08/17")) cout << "2019/08/17" <<" is exist" << "\n";
}

bool exist_ump(string file_pass) {
    auto itr = ump.find(file_pass);
    if(itr != ump.end()) {
        return true;
    } else {
        return false;
    }
}

int add_ump(string file_pass) {
    unsigned long int hash_key = hash_fn(file_pass);
    ump[file_pass] = hash_key;
    return 0;
}

int delete_ump(string file_pass) {
    auto itr = ump.find(file_pass);
    if(itr != ump.end()) {
        ump.erase(itr);
        return true;
    } else {
        return false;
    }
}

void print_ump(unordered_map<string, unsigned long int> tmp_ump) {
    for(auto itr = ump.begin(); itr != ump.end(); ++itr) {
        cout << "key = " << itr->first << ", val = " << itr->second << "\n";
    }
}