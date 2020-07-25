#include <iostream>
#include <string>

using namespace std;

int main(){
    int cnt = 0, len = 0;
    string str;

    getline(cin, str, '\n');

    len = str.length();

    for(int i = 0; i < len; i++)
        if(str.at(i) == ' ')
            cnt++;

    if(str.at(0) == ' ')
        cnt--;

    if(str.at(len - 1) == ' ')
        cnt--;

    cout << cnt + 1 << endl;
}
