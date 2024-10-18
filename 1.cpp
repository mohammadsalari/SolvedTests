//url: https://quera.org/contest/assignments/52348/problems/176711

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int main(){

    int n;
    int m[26][26];

#pragma region read_inputs
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> m[i][j];
        }
    }
#pragma endregion

    vector<tuple<int, int, int>> v;
    for(int i=0;i<n;i++){
        int index, score=0, diff=0;
        index = i;
        for(int j=0;j<n;j++){
            if(m[i][j]>m[j][i]){
                score += 3;
            } else if(m[i][j]==m[j][i]){
                score += 1;
            }
            diff += (m[i][j] - m[j][i]);
        }
        v.push_back({index, score, diff});
    }

    sort(v.begin(), v.end(),[](tuple<int,int,int> a, tuple<int,int,int> b){
        return (get<1>(a)>get<1>(b) || (get<1>(a)==get<1>(b) && get<2>(a)>get<2>(b)) || (get<1>(a)==get<1>(b) && get<2>(a)==get<2>(b) && get<0>(a)<get<0>(b)));
    });

    for(auto i:v){
        cout << (char)(get<0>(i)+97);
    }
    cout << endl;

    return 0;
}