#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
const int N = 1e4+7;
int cnt[N],cntt[N];

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edge(n+1);

    for(int i=1;i<=m;i++){//我真服。。
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    
    int k;cin>>k;
    while(k--){
        for(int i=1;i<=n;i++) cntt[i]=cnt[i];//
        int tx;cin>>tx;
        for(int i=0;i<tx;i++){
            int t;cin>>t;
            cntt[t]=0;
            for(auto x:edge[t]){
                cntt[x]--;
            }
        }
        bool ok=1;
        for(int i=1;i<=n;i++){
            if(cntt[i]>0){
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}