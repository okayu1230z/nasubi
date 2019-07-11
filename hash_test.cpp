#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> mp;
  mp["xyz"] = 123;
  auto itr = mp.find("xyz");
  if( itr != mp.end() ) {
      cout << "itr->first " << itr->first << "\n";      cout << "itr->second " << itr->second << "\n";
      mp.erase(itr);
  } else {
      cout << "aiueo!" << "\n
  }
}
