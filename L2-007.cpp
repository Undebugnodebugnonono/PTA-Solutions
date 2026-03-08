#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353; 
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
int gcd(const int a,const int b){return b ? gcd(b,a%b) : a;}
int lcm(const int a,const int b){return a / gcd(a, b) * b;}
int qw(int a,int k){int res = 1;while(k){if(k&1) res *= a;a*=a;k>>=1;}return res;}
const int N = 1e4;
int fa[N];
bool vis[N];

int find(int x){
    if(fa[x]==x)return x;
    return fa[x] = find(fa[x]);
}

void unite(int x,int y){
    int rootx=find(x),rooty=find(y);
    if(rootx!=rooty){
        if(rootx<rooty) fa[rooty]=rootx;
        else fa[rootx]=rooty;
    }
}

void init(){
    for(int i = 0;i < N;i ++) fa[i] = i;
    for(int i = 0;i < N;i ++) vis[i] = 0;
}

struct Node{
    int id;
    int cnt;
    double area;//double?
};
struct Family{
    int id;
    int sum;
    double avg,avgg;
    double totavg,totavgg;
};

bool cmp(Family a,Family b){
    //if(a.avgg!=b.avgg) return a.avgg>b.avgg; double要注意
    if(abs(a.avgg-b.avgg)>1e-8) return a.avgg>b.avgg;
    return a.id<b.id;
}

void solve() {
    init();
    int n;cin>>n;
    vector<Node> p(n);
    for(int i = 0;i < n;i ++){
        int id,f,m,k;
        cin>>id>>f>>m>>k;
        p[i].id=id;
        vis[id]=1;
        if(f!=-1) vis[f]=1,unite(id,f);
        if(m!=-1) vis[m]=1,unite(id,m);
        for(int j = 0;j < k;j ++){
            int t;cin>>t;
            vis[t]=1;
            unite(id,t);
        }
        cin>>p[i].cnt>>p[i].area;
    }
    vector<Family> ff(N);
    for(int i = 0;i < N;i ++){
        ff[i].id=i;
        ff[i].sum=0;
        ff[i].totavg=0;
        ff[i].totavgg=0;
    }
    for(int i = 0;i < N;i ++)
        if(vis[i]) ff[find(i)].sum++;
    for(int i = 0;i < n;i ++){
        int t = p[i].id;
        int pt=find(t);
        ff[pt].totavg+=p[i].cnt;
        ff[pt].totavgg+=p[i].area;
    }
    vector<Family> ans;
    for(int i = 0;i < N;i ++){
        if(vis[i]&&find(i)==i){
            ff[i].avg=ff[i].totavg/ff[i].sum;
            ff[i].avgg=ff[i].totavgg/ff[i].sum;
            ans.push_back(ff[i]);
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end(),cmp);
    for(int i = 0;i < ans.size();i ++)
        cout << setfill('0')<<setw(4)<<ans[i].id<<' '<<ans[i].sum<<' '
            <<fixed<<setprecision(3)<<ans[i].avg<<' '<<ans[i].avgg<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;cin >> T;while (T--) 
    solve();
}
