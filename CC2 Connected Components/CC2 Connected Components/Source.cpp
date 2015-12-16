#include <iostream>
using namespace std;
int N, adj[1002][1002], vis[1002];
int dfs(int v){
       vis[v] = 1;
       for (int i = 1; i<=N;i++)
           if (adj[v][i]==1&&vis[i]==0){
              cout<<' '<<i;
              dfs(i);
           }
}
int main() {
    cin>>N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin>>adj[i][j];
    for (int i = 1; i <= N; i++)
        if (vis[i]==0){
            cout<<i;
            dfs(i);
            cout<<endl;
        }
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++)
            cout<<adj[i][j];
        cout<<endl;
    }
}
