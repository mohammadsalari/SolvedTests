//url: https://quera.org/problemset/252334

#include <iostream>
#include <list>
#include <vector>
using namespace std;
using ll=long long;

vector<ll> solve(vector<ll>& g, int w, vector<ll>& a, int n){
    vector<ll> res(w,0);

    for(ll i=0, ai;i<n;i++){
        ai = a[i];
        for(ll j=0;j<w && ai!=0;j++){
            res[j] += (ai - ai%g[j]);
            ai = ai%g[j];
        }
    }
    return res;
}

int main(){

    int c;
    cin >> c;

    while(c--){ // do for each country
        ll n, w;
        vector<ll> a,g;
        cin >> n;
        cin >> w;

        a.resize(n);
        g.resize(w);

        for(ll i=0,tmp;i<n;i++){
            cin >> tmp;
            a[i]=tmp;
        } 
        for(ll i=0,tmp;i<w;i++){
            cin >> tmp;
            g[i]=tmp;
        }

        vector<ll> res = solve(g, w, a, n);
        for(ll i:res){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}