#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define rep2(i,m,n) for(ll i=ll(m);i<ll(n);i++)
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using vvpl = vector<vpl>;
#define pb push_back

const long double EPS = 0.0000000001;
const ll INF = 1000000000000000000;
const double pi = std::acos(-1.0);

__int128 read_int128(){ //__int128を入力する
  string S;
  cin >> S;
  int N = S.size();
  int st = 0;
  bool minus = false;
  if(S[0] == '-'){
    minus = true;
    st = 1;
  }
  __int128 res = 0;
  rep2(i,st,N) res = res*10+int(S[i]-'0');
  if(minus) res *= -1;
  return res;
}

std::ostream &operator<<(std::ostream &dest, __int128_t value) { //これでcoutで__int128を出力できるように
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

void Yes(){ cout << "Yes" << endl; } //文字列"Yes"を標準出力
void No(){ cout << "No" << endl; } //文字列"No"を標準出力

int main(){
  for(;;){
    int N;
    cin >> N;
    if(N == 0) break;
    ll a,b,d;
    cin >> a >> b >> d;
    vector<vector<bool>> obs(101,vector<bool>(101,false));
    rep(i,N){
        int x,y;
        cin >> x >> y;
        obs[x][y] = true;
    }
    ll nowx = a,nowy = b,nowd = d,nowdir = 0;
    vl dx = {1,0,-1,0};
    vl dy = {0,1,0,-1};
    vvvl dist(101,vvl(101,vl(4,-1)));
    dist[a][b][0] = d;
    bool ok = false,loop = false;
    while(ok==false&&nowd>0){
        //cout << nowx << " " << nowy << " " << nowdir << endl;
        ll newx = nowx+dx[nowdir];
        ll newy = nowy+dy[nowdir];
        if(newx < 0 || newx > 100 || newy < 0 || newy > 100){
            ll ansx = nowx+dx[nowdir]*nowd;
            ll ansy = nowy+dy[nowdir]*nowd;
            ok = true;
            cout << ansx << " " << ansy << endl;
            break;
        }
        else{
            while(obs[newx][newy]){
                nowdir++;
                nowdir %= 4;
                newx = nowx+dx[nowdir];
                newy = nowy+dy[nowdir];
                if(newx < 0 || newx > 100 || newy < 0 || newy > 100) break;
            }
            if(newx < 0 || newx > 100 || newy < 0 || newy > 100){
            ll ansx = nowx+dx[nowdir]*nowd;
            ll ansy = nowy+dy[nowdir]*nowd;
            ok = true;
            cout << ansx << " " << ansy << endl;
            break;
        }
            nowd--;
            if(dist[newx][newy][nowdir] == -1) dist[newx][newy][nowdir] = nowd;
            else if(!loop){
                ll len = dist[newx][newy][nowdir]-nowd;
                if(len > 0) nowd %= len;
            }
        }
        nowx = newx;
        nowy = newy;
    }
    if(!ok) cout << nowx << " " << nowy << endl;
  }
}