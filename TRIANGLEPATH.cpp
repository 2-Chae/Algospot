// TRIANGLEPATH
// https://algospot.com/judge/problem/read/TRIANGLEPATH
#include <iostream>
using namespace std;

int n;
int triangle[101][101];
int maxSum[101][101];

int findMax(int x, int y){
    // base case
    if(x == n-1) return triangle[x][y];
    if(maxSum[x][y]) return maxSum[x][y];
    maxSum[x][y] = max(findMax(x+1, y), findMax(x+1, y+1)) + triangle[x][y];
    return maxSum[x][y];
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
            maxSum[i][j] = 0;
        }
    cout <<findMax(0, 0) << endl;
    
}
int main(){
    int c;
    cin >> c;
    for(int t = 0; t < c; t++){
        solve();
    }
    return 0;
}
