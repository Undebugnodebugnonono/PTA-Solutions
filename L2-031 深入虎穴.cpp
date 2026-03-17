#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
const int N = 1e5+7;
bool vis[N];
vector<int> edge[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x;cin>>x;
            edge[i].push_back(x);
            edge[x].push_back(i);
        }
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto x:edge[t]){
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
            }
        }
    }
    cout<<q.front();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}