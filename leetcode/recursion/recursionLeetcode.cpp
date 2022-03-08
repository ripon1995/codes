#include<bits/stdc++.h>
using namespace std;

string convertString(string num,string data) {
    string res = "";
    int n = stoi(num);
    for(int i=0;i<n;i++) {
        res += data;
    }
    return res;
}


pair<string,int> decodeString(string &s , int index) {
    string res = "";
    string num = "";
    string data = "";
    for(int i=index;i<s.length();i++) {
        if(s[i] == '[') {
            cout << "Calling: "<<i+1<<endl;
            auto d = decodeString(s,i+1);
            cout<<"Returned: ";
            cout << d.first << d.second << endl;
            res = convertString(num,d.first);
            cout << res << endl;

            s.erase(s.begin()+i-1,s.begin()+d.second);
            s.insert(i,res);
        }
        else if(s[i] == ']') {
            cout << data << " " << i << endl; 
            return {data,i};
        }
        else if(isalpha(s[i])) {
            data += s[i];
        }
        else if(isdigit(s[i])) {
            num += s[i];
        }
    }
    return {s,index};
} 

int main() {
    string s = "3[a]2[c]5[f]";
    int index = 0;
    cout<<decodeString(s,index).first<<endl;
    return 0;
}