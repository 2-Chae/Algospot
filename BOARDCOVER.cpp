#include <iostream>

using namespace std;


int h, w;

int ways = 0;

void dropBlock(char mat[][21], int blockCount){
    if(blockCount == 0){
        ways++;
        return;
    }
    
    int i, j, x, y;
    bool flag = false;
    //가장 빨리 비어있는 공간 찾기
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            if(mat[i][j] == '.'){
                x = i; y = j;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(x >= 0 && x+1 < h && y >= 0 && y+1 < w){ //first
        if(mat[x+1][y] == '.' &&  mat[x][y] == '.' && mat[x+1][y+1] == '.'){
            mat[x+1][y] = mat[x][y] = mat[x+1][y+1] = 'A';
            dropBlock(mat, blockCount-1);
            mat[x+1][y] = mat[x][y] = mat[x+1][y+1] = '.';
        }
    }
    if(x >= 0 && x+1 < h && y >= 0 && y+1 < w){
        if(mat[x+1][y] == '.' &&  mat[x][y] == '.' && mat[x][y+1] == '.'){
            mat[x+1][y] = mat[x][y] = mat[x][y+1] = 'B';
            dropBlock(mat, blockCount-1);
            mat[x+1][y] = mat[x][y] = mat[x][y+1] = '.';
        }
    }
    if(x >= 0 && x+1 < h && y >= 0 && y+1 < w){
        if(mat[x][y+1] == '.' &&  mat[x][y] == '.' && mat[x+1][y+1] == '.'){
            mat[x][y+1] = mat[x][y] = mat[x+1][y+1] = 'C';
            dropBlock(mat, blockCount-1);
            mat[x][y+1] = mat[x][y] = mat[x+1][y+1] = '.';
        }
    }
    if(x >= 0 && x+1 < h && y-1 >= 0 && y < w){
        if(mat[x+1][y-1] == '.' &&  mat[x][y] == '.' && mat[x+1][y] == '.'){
            mat[x+1][y-1] = mat[x][y] = mat[x+1][y] = 'D';
            dropBlock(mat, blockCount-1);
            mat[x+1][y-1] = mat[x][y] = mat[x+1][y] =  '.';
        }
    }

}

int main(){
    int testCase;
    cin >> testCase;
    for(int testCount = 0; testCount < testCase; testCount++){
        char mat[21][21];
        int dotCount = 0;
        ways = 0;
        cin >> h >> w;
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == '.')
                    dotCount++;
            }
        }
        
        if(dotCount % 3 != 0){
            cout << 0 << endl;
            continue;
        }
        dropBlock(mat, dotCount/3);
        cout << ways << endl;
    }
    
    return 0;
}
