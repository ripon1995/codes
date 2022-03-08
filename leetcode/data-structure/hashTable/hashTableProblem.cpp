#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<string>vs;
typedef vector<int>vi;
typedef vector<vector<string>>vvs;

void findingTheusersActiveMinutes(vector<vector<int>>logs,int k) {
    map<int,set<int>>data;
    for(int i=0;i<logs.size();i++) {
        data[logs[i][0]].insert(logs[i][1]);
    }

    map<int,int>mp;
    for(auto d:data) {
        mp[d.second.size()]++;
    }

    vector<int>res(k,0);
    for(auto m:mp) {
        res[m.first - 1] = m.second ;
    }

    for(auto r:res){
        cout<<r<<" ";
    }
}

void minimumStepToMakeAnagram(string s,string t) {
    map<char,int>sString;
    for(auto ch:s){
        sString[ch]++;
    }

    for(auto s:sString) {
        cout<<s.first<<" "<<s.second<<endl;
    }
    cout<<endl<<endl;
    map<char,int>tString;
    for(auto ch:t) {
        tString[ch]++;
    }
    for(auto t:tString) {
        cout<<t.first<<" "<<t.second<<endl;
    }
    int ans = 0;
    for(auto s:sString) {
        char ch = s.first;
        int chCount = s.second;
        if(!tString.count(ch)){
            ans+=chCount;
        }
        else {
            if(tString[ch]<chCount) {
                ans+=abs(chCount - tString[ch]);
            }
        }
    }
    cout<<ans<<endl;
}

void subdomainVisitCount(vector<string>cpdomains) {
    map<string,int>mp;
    for(auto dom:cpdomains) {
        int count = 0;
        int i=0;
        for(i=0;i<dom.length();i++) {
            char ch = dom[i];
            if(ch == ' '){
                string c = dom.substr(0,i);
                count = stoi(c);
                break;
            }
        }
        for(int j=i;j<dom.length();j++) {
            char ch = dom[j];
            if(ch == '.') {
                string subStr = dom.substr(j+1,dom.length()-(j+1));
                mp[subStr]+=count;
            }
        }
        string s = dom.substr(i+1,dom.length()-i);
        mp[s]+=count;
    }
    vector<string>res;
    for(auto m:mp) {
        string d = to_string(m.second)+" "+ m.first;
        res.push_back(d);
    }

    for(auto r:res){
        cout<<r<<endl;
    }
}

void findAllDuplicatesInAnArray(vector<int>nums) {
    map<int,set<int>>data;
    for(int i=0;i<nums.size();i++) {
        data[nums[i]].insert(i);
    }

    vector<int>res;
    for(auto d:data) {
        if(d.second.size()==2) {
            res.push_back(d.first);
        }
    }
    for(auto r:res) {
        cout<<r<<" ";
    }
}

void findAndReplacePattern(vector<string>words,string pattern) {
    vector<string>res;
    
    for(auto word:words) {
        map<char,char>wordToPattern;
        map<char,char>patternToWord;
        bool isMatched = true;
        for(int i=0;i<word.length();i++) {
            char w = word.at(i);
            char p = pattern.at(i);
            bool isPresent = wordToPattern.find(w)!=wordToPattern.end();
            if(!isPresent) {
                wordToPattern[w] = p;
            }
            isPresent = patternToWord.find(p)!=patternToWord.end();
            if(!isPresent) {
                patternToWord[p] = w;
            }

            if(patternToWord[p] != w || wordToPattern[w] != p) {
                isMatched = false;
                break;
            }
        }
        if(isMatched) {
            res.push_back(word);
        }
    }

    for(auto r:res) {
        cout<<r<<endl;
    }
}

void evaluateTheBreacketPairOfAString(string s,vector<vector<string>>knowledge) {
    map<string,string>data;
    for(int i=0;i<knowledge.size();i++) {
        string key = knowledge[i][0];
        string value = knowledge[i][1];
        data[key] = value;
    }


    string res="";
    string key="";
    bool foundOpening = false;
    for(int i=0;i<s.length();i++) {
        char c = s.at(i) ;
        if(c == '(') {
            foundOpening = true;
        }
        if(c == ')') {
            key.erase(key.begin()+0);
            cout<<data[key]<<endl;
            bool isPresent = data.find(key)!=data.end();
            if(isPresent == true) {
                res+=data[key];
            }
            else {
                res+='?';
            }
            
            key.clear();
            foundOpening = false;
            continue;
        }
        if(foundOpening == false) {
            res.push_back(c);
            //cout<<res<<endl;
        }
        if(foundOpening == true) {
            key.push_back(c);
        }
    }
    cout<<res<<endl;
}


void isomorphicString(string s,string t) {
    bool ans = true ;
    map<char,char>sTt;
    map<char,char>tTs;
    for(int i=0;i<s.length();i++) {
        char chs = s.at(i);
        char cht = t.at(i);

        bool isPresent = sTt.find(chs)!=sTt.end();
        if(isPresent == false) {
            sTt[chs] = cht;
        }

        isPresent = tTs.find(cht)!=tTs.end();
        if(isPresent == false) {
            tTs[cht] = chs ;
        }

        if(sTt[chs] != cht || tTs[cht] != chs){
            ans = false;
            break;
        }
    }
    cout<<ans<<endl;
}



int main() {
    
    vvs v ={
        {"name","bob"},
        {"age","two"}
    };
    string pattern = "abba";
    string s ="dog cat cat dog";
    return 0;
}
