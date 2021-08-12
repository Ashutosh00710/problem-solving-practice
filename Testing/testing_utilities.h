#include<bits/stdc++.h>
#define LOG(S) cout << S << "\n";
#define ERROR_LOG() cout << "\x1B[31m!! Failed Test Case !!\033[0m\t\t" << "\n";
#define SUCCESS_LOG() cout << "\x1B[32mPassed\033[0m\t\t" << "\n";
using namespace std;

template<typename T>
class test {
    string desc;
    T exp;
  public:
    test& description(string des = "") {
        desc = des;
        return *this;
    }
    test& expect(T value) {
        exp = value;
        return *this;
    }
    void toBe(T to_be) {
        if(exp == to_be) {
            if(desc.length()) {
                LOG(desc);
            }
            SUCCESS_LOG();
        } else {
            ERROR_LOG();
            if(desc.length()) {
                LOG(desc);
            }
            cout << "Expcted: " << exp << " found " << to_be;
        }
    }
};
