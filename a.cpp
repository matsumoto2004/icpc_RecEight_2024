#ifdef LOGX
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;

/*---------macro---------*/
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define unless(x) if(!(x))
#define until(x) while(!(x))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define mybit(i,j) (((i)>>(j))&1)

/*---------type/const---------*/
constexpr int big=1000000007;
//constexpr int big=998244353;
constexpr double EPS=1e-8; //適宜変える
typedef long long ll;
typedef unsigned long long ull;
typedef std::string::const_iterator state; //構文解析
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
constexpr char newl='\n';
struct{
    constexpr operator int(){return -int(1e9)-10;}
    constexpr operator ll(){return -ll(1e18)-10;}
}neginf;
struct{
    constexpr operator int(){return int(1e9)+10;}
    constexpr operator ll(){return ll(1e18)+10;}
    constexpr auto operator -(){return neginf;}
}inf;

/*---------debug---------*/
#ifdef LOGX
#include <ito/debug.hpp>
#else
#define dbg(...) ;
#define dbgnewl ;
#define prt(x) ;
#define _prt(x) ;
#endif

/*---------function---------*/
template<typename T> T max(const std::vector<T> &a){T ans=a[0];for(T elem:a){ans=max(ans,elem);}return ans;}
template<typename T> T min(const std::vector<T> &a){T ans=a[0];for(T elem:a){ans=min(ans,elem);}return ans;}
template<typename T,typename U> bool chmin(T &a,const U b){if(a>b){a=b;return true;}return false;}
template<typename T,typename U> bool chmax(T &a,const U b){if(a<b){a=b;return true;}return false;}
bool valid(int i,int j,int h,int w){return (i>=0 && j>=0 && i<h && j<w);}
template<class T,class U>T expm(T x,U y,const ll mod=big){T res=1;while(y){if(y&1)(res*=x)%=mod;(x*=x)%=mod;y>>=1;}return res;}
template<class T,class U>T exp(T x,U y){T res=1;while(y){if(y&1)res*=x;x*=x;y>>=1;}return res;}

void solve(int n){
    int sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(sum + a <= 300)sum += a;
    }
    cout << sum << newl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
/*------------------------------------*/
    
    int n;
    while(cin >> n,n){
        solve(n);
    }
}
