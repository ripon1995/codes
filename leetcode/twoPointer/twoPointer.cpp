#include<bits/stdc++.h>
using namespace std;

void reversePrefix(string word, char ch) {
    int startPoint = 0;
    int endPoint = 0;
    string res=word;
    for(startPoint=0 ; startPoint<word.length() ; startPoint++) {
        if(word.at(startPoint) == ch) {
            res = word.substr(endPoint , startPoint+1);
            reverse(res.begin(),res.end());
            res+=word.substr(startPoint+1,word.length()-startPoint+1);
            break;
        }
    }
    
    cout<<res<<endl;
}
 
void reverseWordsInAString3(string s) {
    int startPoint = 0;
    int endPoint = 0;
    string res="";
    string temp="";
    for(startPoint=0;startPoint<s.length();startPoint++) {
        temp+=s.at(startPoint);
        if(isspace(s.at(startPoint))) {
            temp.pop_back();
            reverse(temp.begin(),temp.end());
            temp+=" ";
            res+=temp;
            //update endPoint
            endPoint=startPoint+1;
            temp="";
        }

        if(startPoint==s.length()-1) {
            reverse(temp.begin(),temp.end());
            res+=temp;
        }
    }
    cout<<res<<endl;
}

void mergeStringAlternately(string word1, string word2) {
    
    int w1StartPoint=0;
    int w2StartPoint=0;

    string res="";
    while(w1StartPoint<word1.length() && w2StartPoint<word2.length()) {
        res += word1[w1StartPoint++]; 
        res += word2[w2StartPoint++];
        cout<<res<<endl;
    }

    while(w1StartPoint<word1.length()) {
        res+=word1[w1StartPoint++];
    }

    while(w2StartPoint<word2.length()) {
        res+=word2[w2StartPoint++];
    }
    cout<<res<<endl;
}

void countBinarySubstring(string s) {
    vector<int>groups;
    int currentGroup=1;
    for(int i=1;i<s.length();i++) {
        if(s[i-1]==s[i]) currentGroup++;
        else {
            groups.push_back(currentGroup);
            currentGroup = 1 ;
        }
    }
    groups.push_back(currentGroup);
    
    int ans=0;
    for(int i=1;i<groups.size();i++) {
        ans+=min(groups[i-1],groups[i]);
    }

    cout<<ans<<endl;
}

void reverseOnlyLetters(string s) {
    
    int start = 0;
    int end = s.length()-1;

    while(start < end) {
        // check both start and end character are alphabet or not
        if(!isalpha(s[start])) {
            start++;
            continue;
        }
        if(!isalpha(s[end])) {
            end--;
            continue;
        }
        swap(s[start],s[end]);
        start++;
        end--; 
    }
    cout<<s<<endl;
}

void duplicateZeros(vector<int> arr) {
    int last = arr.size()-1;
    int fast = 0;



    for(fast=0;fast<arr.size();fast++) {
        if(arr[fast] != 0) {
            continue;
        }

        for(int i=last ; i>fast ; i--) {
            arr[i] = arr[i-1] ;
        }
        arr[fast + 1] = arr[fast] ;
        fast = fast + 1 ;
    }

    for(auto a:arr) cout<<a<<" ";
}


void backspaceStringCompare(string s , string t) {
    stack<char>st;
    for(auto ch : s) {
        if(isalpha(ch)) {
            st.push(ch);
        }
        if(ch == '#') {
            st.pop();
        }
    }

    string res="";
    while(!st.empty()) {
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}

void reverseVowelsOfAstring(string s) {
    set<char>vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int start = 0 ;
    int end = s.length()-1 ;

    while(start < end) {
        if( !vowels.count(s[start] )) {
            start++ ;
            continue ;
        }
        if( !vowels.count(s[end]) ) {
            end-- ;
            continue ;
        }
        swap(s[start],s[end]) ;
        start++ ;
        end-- ;
    }

    cout<<s<<endl;
}

void validPalindrome(string s) {
    for(int i=0;i<s.length();i++) {
        char ch = s[i];
        if(isalnum(ch)) {
            continue ;
        }
        s.erase(s.begin()+i) ;
        i-- ;
    }

    int start = 0 ;
    int end = s.length() - 1 ;

    bool ans = true ;
    while(start < end) {
        if(s[start] != s[end]) {
            ans = false ;
            break ;
        }

        start++ ;
        end-- ;
    }

    cout<< ans <<endl;
}

bool palindrome(string s,int start , int end) {
    
    bool ans = true ;
    while(start < end ) {
        if(s[start] != s[end]) {
            ans = false ;
            break ;
        }
        start++ ;
        end-- ;
    }
    return ans ;
}

void validPalindrome2(string s) {
    int start = 0 ;
    int end = s.length() - 1 ;
    
    int deletedChar = 1 ;

    bool ans = true ;
    while(start <= end) {
        if(deletedChar < 0) {
            ans = false ;
            break ;
        }
        if(s[start] != s[end]) {
            
            ans = palindrome(s,start+1,end) || palindrome(s,start,end-1) ;
            break ; 
        }

        start++ ;
        end-- ;
    }

    cout << ans << endl ;
}


void implementStrStr(string haystack, string needle) {
    int fast = 0 ;
    int last = 0 ;
    int firstIndex = 0 ;
    bool isSet = false ;
    
    for(fast=0 ; fast<haystack.length(); fast++) {
        if(haystack[fast] == needle[last] ) {
            if(isSet == false) {
                firstIndex = fast ;
                isSet = true;
            }
            last++ ;
        }
        else {
            last = 0 ;
            isSet = false ;
        }
    }
    cout << firstIndex << endl ;
}

void partitionLabels(string s) {
    map<char,int>index;
    for(int i=0;i<s.length();i++) {
        index[s[i]] = i;
    }

    vector<int>res;
    int len = 0;
    int lastIndex = 0;
    for(int i=0;i<s.length();i++) {
        char ch = s[i];
        if(index[ch] > lastIndex)lastIndex = index[ch];
        len++;
        if(i == lastIndex) {
            res.push_back(len);
            len = 0;
        }
    }

    for(auto l : res)cout << l << endl;
}

void minimumNumberOfSwapsToMakeString(string s) {
    int start = 0;
    int end = s.length() - 1;
    int front = 0; // this will be positive for opening bracket
    int back = 0; // this will be positive for closing bracket
    int ans = 0;

    while(start < end) {
        if(s[start] == '[') {
            front++;
        }
        if(s[end] == ']') {
            back++;
        }
        if(s[start] == ']') {
            front--;
        }
        if(s[end] == '[') {
            back--;
        }
        if(front < 0 && back < 0) {
            ans++;
            cout<<front<<" "<<back<<endl;
            swap(s[start],s[end]);
            front++;
            back++;
        }
        cout<<front<<" "<<back<<endl;
        start++;
        end--;
        cout<<s<<endl;
    }
    cout << ans << endl;

}

void containerWithMostWater(vector<int>height) {
    int maxArea = 0;
    int start = 0;
    int end = height.size() - 1;
    while(start < end) {
        int area = (end-start) * min(height[start],height[end]);
        maxArea = max(maxArea , area);
        if(height[start] > height[end]) {
            end--;
        }
        else if(height[start]<height[end]) {
            start++;
        }
        else {
            start++;
            end--;
        }
    }
    cout<<maxArea<<endl;
}


void rotatingTheBox(vector<vector<char>> box) {
    for(int i=0;i<box.size();i++) {
        int start = box[i].size() - 1;
        int end = box[i].size() - 1;
        int emptySpace = 0;
        for(start = box[i].size() - 1 ;start>=0;start--) {
            if(box[i][start] == '*') {
                end = start - 1;
                emptySpace=0;
            }
            if(box[i][start] == '.') {
                emptySpace++;
            }
            if(box[i][start] == '#') {
                for(int s=start;s<end;s++) {
                    swap(box[i][s],box[i][s+1]);
                }
                end--;
            }
        }
    }

    int row = box.size();
    int col = box[0].size();
    vector<vector<char>>res;
    vector<char>r;
    for(int i=0;i<box[0].size();i++) {
        for(int j=box.size()-1;j>=0;j--) {
            //cout<<box[j][i]<< " ";
            r.push_back(box[j][i]);
        }
        res.push_back(r);
        r.clear();
        //cout<<endl;
    }

    for(auto rr:res) {
        for(auto r:rr) {
            cout<<r<<" ";
        }
        cout<<endl;
    }
}

void removeDuplicatesFromSortedArray2(vector<int>nums) {
    int len = nums.size() - 1;
    int start = 0;
    int end = 0;
    int count = 2;

    for(start=0;start<=len;start++) {
        if(nums[start] == nums[end]) {
            count--;
        }
        if(nums[start] != nums[end]) {
            end = start ;
            count=1;
        }
        if(count<0) {
            for(int s=start;s<len;s++){
                swap(nums[s],nums[s+1]);
            }
            len--;
            start--;
        }
    }

    for(auto n:nums)cout<<n<<" ";
    cout<<endl;

    for(int i=0;i<=len;i++) {
        cout<<nums[i]<<" ";
    }
}

void reverseWordsInAString(string s) {
    int start = 0;
    int end = 0;
    int len = 0;
    vector<string>words;
    for(start=0;start<s.length();start++) {
        if(len == 0 && isspace(s[start])){
            end=start+1;
            continue;
        }
        if(isalnum(s[start])) {
            len++;
        }
        if(isspace(s[start]) || start == s.length()-1) {
            string word = s.substr(end,len);
            words.push_back(word);
            len = 0;
            end = start+1;
        }
    }

    string res = "";
    for(int i=words.size()-1;i>=0;i--) {
        res+=words[i];
        if(i>0)res+=' ';
    }
    cout<<res<<endl;
}


void boatsToSavePeople(vector<int>people, int limit) {
    sort(people.begin(),people.end());
    int start = 0;
    int end = people.size()-1;
    int boat = 0;
    while(start<=end){
        boat++;
        if(people[start]+people[end] <= limit) {
            start++;
        }
        end--;
    }
    cout<<boat<<endl;
}



int main() {

    vector<int>v={3,2,2,1};
    boatsToSavePeople(v,3);
    return 0;
}