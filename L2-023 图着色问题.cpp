#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
vector<vector<int>> v(510);
vector<int> color(510);

bool f(int x){
    for(int i=0;i<v[x].size();i++)
        if(color[x] == color[v[x][i]])
            return 0;
    return 1;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int q;cin>>q;
    while(q--){
        set<int> s;
        for(int i=1;i<=n;i++){
            cin>>color[i];
            s.insert(color[i]);
        }
        bool ok = 1;
        if(s.size()!=k) ok=0;
        for(int i=1;i<=n;i++){
            if(!f(i)){
                ok=0;
                break;
            }
        }
        if(ok==1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}