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
    vl S(N);
    rep(i,N) cin >> S[i];
    ll SumofS = 0;
    rep(i,N) SumofS += S[i];
    if(SumofS%2 != 0) No();
    else{
        if(N%2 == 1){
            ll AltS = 0;
            rep(i,N){
                if(i%2 == 0) AltS += S[N-1-i];
                else AltS -= S[N-1-i];
            }
            vl a(N),b(N);
            a[0] = AltS/2;
            rep(i,N-1){
                b[i] = S[i]-a[i];
                a[i+1] = b[i];
            }
            b[N-1] = S[N-1]-a[N-1];
            Yes();
            rep(i,N){
                if(i != 0) cout << " ";
                cout << a[i];
            }
            cout << endl;
            rep(i,N){
                if(i != 0) cout << " ";
                cout << b[i];
            }
            cout << endl;
        }
        else{
            int even = -1;
            rep(i,N) if(S[i]%2 == 0) even = i;
            if(even != -1){
                vl a(N),b(N);
                a[even] = S[even]/2;
                b[even] = S[even]/2;
                ll AltS = 0;
                vl lis(0);
                rep(i,N) if(i != even) lis.push_back(i);
                rep(i,N-1){
                    if(i%2 == 0) AltS += S[lis[N-2-i]];
                    else AltS -= S[lis[N-2-i]];
                }
                a[lis[0]] = AltS/2;
                rep(i,N-2){
                    b[lis[i]] = S[lis[i]]-a[lis[i]];
                    a[lis[i+1]] = b[lis[i]];
                }
                b[lis[N-2]] = S[lis[N-2]]-a[lis[N-2]];
                Yes();
                rep(i,N){
                    if(i != 0) cout << " ";
                    cout << a[i];
                 }
                 cout << endl;
                 rep(i,N){
                     if(i != 0) cout << " ";
                     cout << b[i];
                 }
                 cout << endl;
            }
            else{
                int M = 10500;
                vector<vector<bitset<21001>>> dp(N+1,vector<bitset<21001>>(N/2+1));
                dp[0][0][M] = 1;
                rep(i,N){
                    rep(j,N/2+1){
                        if(j < N/2){
                            if(S[i] >= 0) dp[i+1][j+1] |= dp[i][j]<<S[i];
                            else dp[i+1][j+1] |= dp[i][j]>>(-S[i]);
                        }
                        //cout << "S" << S[i] << endl;
                        if(S[i] >= 0) dp[i+1][j] |= dp[i][j]>>S[i];
                        else dp[i+1][j] |= dp[i][j]<<(-S[i]);
                    }
                }
                
                if(dp[N][N/2][M] == 0) No();
                else{
                    int nowj=N/2,nowS=M;
                    vl plus(0),minus(0);
                    for(int i=N-1;i>=0;i--){
                         if(nowj > 0 && nowS-S[i] >= 0 && nowS-S[i] <=2*M){
                             if(dp[i][nowj-1][nowS-S[i]] == 1){
                                 nowj--;
                                 nowS -= S[i];
                                 plus.push_back(i);
                                 continue;
                             }
                         }
                        minus.push_back(i);
                        nowS += S[i];                       
                    }
                    //cout << plus.size() << " " << minus.size() << endl;
                    vector<int> P(0);
                    rep(i,N/2){
                        P.push_back(plus[i]);
                        P.push_back(minus[i]);
                    }
                    reverse(P.begin(),P.end());
                    vl a(N),b(N);
                    a[P[0]] = 0;
                    rep(i,N-1){
                        b[P[i]] = S[P[i]]-a[P[i]];
                        a[P[i+1]] = b[P[i]];
                    }
                    b[P[N-1]] = S[P[N-1]]-a[P[N-1]];
                    Yes();
                    rep(i,N){
                        if(i != 0) cout << " ";
                        cout << a[i];
                     }
                     cout << endl;
                     rep(i,N){
                         if(i != 0) cout << " ";
                         cout << b[i];
                     }
                     cout << endl;
                }
            }
        }
    }
  }
}