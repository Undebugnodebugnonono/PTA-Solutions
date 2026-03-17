#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
const int N = 1e4+7;
int fa[N];
bool vis[N];//set和vis选一个即可，优先vis

int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);//= ==
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    if(rx!=ry) fa[rx]=ry;//?if丢哪去了
}

void init(){
    for(int i=0;i<N;i++) fa[i] = i;
}

void solve(){
    init();
    int n;cin>>n;
    set<int> s;
    
    for(int i=0;i<n;i++){
        int k;cin>>k;
        vector<int> a(k);
        for(int j=0;j<k;j++){
            cin>>a[j];
            vis[a[j]]=1;
            s.insert(a[j]);
        }
        for(int j=0;j<k-1;j++){
            unite(a[j],a[j+1]);
        }
    }
    // vector<int> ans;
    // for(int i=0;i<N;i++){
    //     if(find(i)==i&&vis[i])ans.push_back(fa[i]);
    // }
    int cnt=0;
    for(auto x:s){
        if(x==find(x)) cnt++;
    }
    cout<<s.size()<<' '<<cnt<<'\n';
     int q;cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(find(x)!=find(y)) cout <<"N\n";
        else cout<<"Y\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}