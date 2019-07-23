#include <iostream>
#include <string>

using namespace std;

void solve(string::iterator& it){
    return;
}

string my(string::iterator& it){
    char head = *it;
    ++it;
    if(head == 'w' || head == 'b') return string(1, head);
    string first = my(it);
    string second = my(it);
    string third = my(it);
    string fourth = my(it);
    return string("x") + third + fourth + first + second;
}

int main(){
    int testCase;
    cin >> testCase;
    for(int test = 0; test < testCase; test++){
        string str;
        cin >> str;
        string::iterator it = str.begin();
        string temp = my(it);
        cout << temp << endl;
    }
    
    return 0;
}
