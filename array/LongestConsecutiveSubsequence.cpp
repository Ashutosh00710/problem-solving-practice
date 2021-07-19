#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
      set<int> s;
      int mxm = 0, prevMax = 0;
      vector<int> v;
      for(int i = 0; i < N; i++) {
          s.insert(arr[i]);
      }
      for (auto it : s) {
        v.push_back(it);
      }
      for(int i = 0; i < v.size(); i++) {
        if(v[i+1] - v[i] == 1) {
          mxm++;
        } else {
          prevMax = max(prevMax, mxm);
          mxm = 0;
        }
      }
      return max(mxm, prevMax) + 1;
    }
};

int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }

    return 0;
}