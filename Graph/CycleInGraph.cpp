#include<bits/stdc++.h>

using namespace std;

class Solution {
  bool isCycleBFS(int i, int V, vector<int>adj[], vector<bool>& visited) {
      queue<pair<int, int>> q;

      visited[i] = true;
      q.push({i, -1});

      while(!q.empty()) {
        int node = q.front().first;
        int ad = q.front().second;
        q.pop();

        for (auto it : adj[node]) {
          if(!visited[it]) {
            visited[it] = true;
            q.push({it, node});
          } else if(ad != it)
              return true;
        }
      }
      return false;
  }
public:
	bool isCycle(int V, vector<int>adj[]) {
    vector<bool> visited(V + 1, false);
    for (int i = 0; i < V; i++) {
      if(!visited[i]) {
          if (isCycleBFS(i, V, adj, visited)) return true;
      }
    }
    return false;
  }
};

int main() {
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}