#include<bits/stdc++.h>
#include "./testing_utilities.h"

using namespace std;

int findSum(int a, int b) {
    return a + b;
}

int main(void) {
    test<int> t;
    t.description("Test 1").expect(8).toBe(findSum(2, 7));
    cout << "\n\n";
    t.description("Test 2").expect(7).toBe(findSum(2, 5));
    return 0;
}
