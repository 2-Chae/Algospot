#include <iostream>

using namespace std;

int n, board[100][100];
int memo[100][100];
int jump(int x, int y){
    if(x >= n || y >= n) return 0;
    if(x == n-1 && y == n-1) return 1;
    
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    
    int jumpSize = board[x][y];
    return memo[x][y] =  jump(x+jumpSize, y) || jump(x, y+jumpSize);
}
int main(){
    int test;
    cin >> test;
    for(int t = 0; t < test; t++){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> board[i][j];
                memo[i][j] = -1;
            }
        }
        if(jump(0, 0) == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
