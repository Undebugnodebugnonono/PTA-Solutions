#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
const int N = 105;
int fa[N];

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry) fa[rx]=ry;
}

void init(){
    for(int i = 0;i < N;i ++) fa[i] = i;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    init();
    unordered_set<pair<int,int>> s;
    for(int i=0;i<m;i++){
        int a,b,op;
        cin>>a>>b>>op;
        if(op==1) unite(a,b);
        else{
            if(a>b) swap(a,b);//fi小se大
            s.insert({a,b});
        }
    }
    while(k--){
        int x,y;
        cin>>x>>y;
        int tx=x,ty=y;
        bool is_f = 0,is_e = 0;
        if(tx>ty) swap(tx,ty);
        if(find(x)==find(y)) is_f = 1;
        if(s.count({tx,ty})) is_e = 1;
        if(is_f&&!is_e) cout <<"No problem\n";
        else if(!is_f&&!is_e) cout << "OK\n";
        else if(is_e&&is_f) cout << "OK but...\n";
        else cout << "No way\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}
