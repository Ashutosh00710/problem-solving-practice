#include<bits/stdc++.h>

using namespace std;

using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::milliseconds;

int getTime() {
    auto t = high_resolution_clock::now();
    return duration_cast<milliseconds>(t.time_since_epoch()).count();
}
