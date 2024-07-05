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
#include <ito/lib/debug.hpp>
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


using P = pair<int,pair<int,int>>;

vector<vector<P>> ma(5e6);

void solve(int a,int b,int x,int y,int n){
    auto idx=[&](int i)->int{
        return i + 2*a + 5;
    };
    rep(i,2*(b+a) + 10)ma[i].clear();
    auto add_ma = [&](int t,P p)->void{
        ma[idx(t)].emplace_back(p);
        return;
    };
    auto addpoint = [&](int i,int x,int y)->void{
        add_ma(y-x, {i,{x,y}});
        add_ma((2*b-y) - (2*a-x), {-i,{2*a-x,2*b-y}});
        add_ma(y-(2*a-x), {-i, {2*a-x, y}});
        add_ma((2*b-y) - x, {-i, {x, 2*b-y}});
    };
    addpoint(0,x,y);

    rep2(i,1,n+1){
        int s,t;
        cin >> s >> t;
        addpoint(i, s,t);
    }
    add_ma(0,{0,{0,0}});
    add_ma(b-a,{0,{a,b}});
    add_ma(0-a,{0,{a,0}});
    add_ma(b-0,{0,{0,b}});

    vector<pair<int,int>> coin;
    coin.push_back({x,y});
    coin.push_back({2*a-x,2*y-b});
    coin.push_back({2*a-x,y});
    coin.push_back({x,2*b-y});
    

    for(int t = -2*a+1;t<=2*b-1;t++){
        sort(ALL(ma[idx(t)]), [&](P l, P r)->bool{
            return l.second.first < r.second.first;
        });
    }
    auto nxt=[&](int t)->int{
        if(t==0)return 2*b-2*a;
        if(t>0)return t-2*a;
        return 2*b+t;
    };
    vector<int> ans;
    for(auto p:coin){
        if(ans.size() == 4)break;
        auto [a,b] = p;
        int t = b-a;
        bool found = false;
        int ls = -1;
        if(ma[idx(t)].size() > 1){
            rep(i,ma[idx(t)].size()-1){
                if(ma[idx(t)][i+1].second == p){
                    //これが答え?
                    if(ma[idx(t)][i].first > 0){
                        ans.emplace_back(ma[idx(t)][i].first);
                        found = true;
                    }
                    else if(i==0 && ma[idx(t)][i].first < 0){
                        ls = -ma[idx(t)][i].first;
                    }
                    break;
                }
            }
            if(found)continue;
        }
        //ひたすら戻りつづける
        auto beg = std::chrono::high_resolution_clock::now();
        while(true && std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - beg).count()< 3000){
            //dbg(t);
            if(ans.size() == 4)break;
            t = nxt(t);
            if(!ma[idx(t)].empty()){
                auto [i,p] = ma[idx(t)].back();
                if(i > 0){
                    ans.emplace_back(i);
                }
                else if(i < 0){
                    if(abs(i) == ls){
                        ans.emplace_back(ls);
                    }
                    else if(ls == -1){
                        ls = -i;
                        continue;
                    }
                }
                break;
            }
        }
        dbg("here");
    }
    if(ans.empty())cout << "No" << endl;
    else{
        sort(ALL(ans));
        rep(i,ans.size())cout << ans[i] << " \n"[i+1==ans.size()];
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
/*------------------------------------*/
    
    int a,b,x,y,n;
    while(cin >> a >> b >> x >> y >> n, a){
        solve(a,b,x,y,n);
    }
}