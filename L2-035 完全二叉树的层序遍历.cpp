//dfs前/中/后序列 + 层序输出
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
int n,cnt=0;
int a[33],aa[33];

void dfs(int x){
    if(x>n) return;
    dfs(x<<1);//左，*2
    dfs(x<<1|1);//右*2+1
    aa[x]=a[cnt++];
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    dfs(1);
    for(int i=1;i<=n;i++){
        if(i!=1) cout<<' ';
        cout<<aa[i];
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}