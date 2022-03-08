#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void removeOutMostParenthesis(string s) {
    stack<char>st;
    string res="";
    for(auto ch:s) {
        if(ch=='(') {
            st.push('(');
            if(st.size()>1) {
                res += ch;
            }
        }
        else if(ch ==')') {
            if(st.size() > 1) {
                res += ch ;
            }
            st.pop();
        }
    }
    cout << res <<endl;
}

void minimumAddToMakeParenthesesValid(string s) {
    int parenthesesNeed = 0;
    stack<char>st;
    for(auto ch:s) {
        if(ch == '(') {
            st.push(ch);
        }
        else if(ch == ')') {
            if(st.empty() == true) {
                parenthesesNeed++;
            }
            else {
                st.pop();
            }
        }
    }
    parenthesesNeed += st.size();
    cout<<parenthesesNeed<<endl;
}

void minimumNumberOfSwapToMakeTheStringBalanced(string s) {
    stack<char>st;
    int minSwap = 0;
    int endPoint = s.length() - 1;
    for(int i=0;i<s.length();i++) {
        char ch = s[i];
        if(ch == ']') {
            if(st.empty() == true) {
                while(s[endPoint] != '[') {
                    endPoint--;
                }
                swap(s[i],s[endPoint]);
                minSwap++;
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }
        if(ch =='[') {
            st.push(ch);
        }
    }
    cout<<minSwap<<endl;
}


void simplifyPath(string path) {
    stack<string>st;
    string current="";
    for(auto ch: path+"/") {
        if(ch =='/'){
            if(current == ".."){
                if(!st.empty()) st.pop();
            }
            else if(current != "" && current != ".") {
                st.push(current);
            }
            current = "";
        }

        else {
            current += ch;
        }
    }

    string res = "";
    if(st.empty()==true) {
        res="/";
    }
    while(!st.empty()){
        string temp = "/";
        temp += st.top();
        res = temp+res;
        st.pop();
    }
    cout << res <<endl;
}

void dailyTemparatures(vector<int>temperatures) {
    stack<int>mono_dec_stack;
    vector<int>res(temperatures.size(),0);
    for(int i=0;i<temperatures.size();i++) {
        int currentValue = temperatures[i];

            while(!mono_dec_stack.empty() && currentValue >= temperatures[mono_dec_stack.top()]) {
                res[mono_dec_stack.top()] = i - mono_dec_stack.top();
                mono_dec_stack.pop();
            }
        mono_dec_stack.push(i);
    }

    for(auto r:res) {
        cout<<r<<" ";
    }
}

void scoreOfParentheses(string s) {
    stack<char>st;
    st.push(0);
    for(auto ch:s) {
        if(ch =='(') {
            st.push(0);
        }
        else if(ch == ')') {
            int firstTop = st.top();
            st.pop();
            int secondTop = st.top();
            st.pop();
            int newTop = secondTop + max(2*firstTop , 1);
            st.push(newTop);
        }
    }
    int res = st.top();
    cout<<res<<endl;
}

void largestRectangleInHistogram(vector<int>heights) {
    stack<int>mono_dec_st;
    heights.push_back(0);
    int area = 0;
    for(int i=0;i<heights.size();i++) {
        
        while(!mono_dec_st.empty() && (heights[i] < heights[mono_dec_st.top()])) {
            int width = 0;
            int height = heights[mono_dec_st.top()];
            mono_dec_st.pop();

            if(!mono_dec_st.empty()) {
                width = i - mono_dec_st.top() - 1;
            }
            else {
                width = i ;
            }
            area = max(area,width*height);
        }

        mono_dec_st.push(i);
    }
    cout<<area<<endl;
}

void reverseSubstringBetweenEachPairOfParentheses(string s) {
    stack<int>st;
    for(int i=0;i<s.length();i++) {
        char ch = s[i];
        if(ch == '(' || ch=='[') {
            st.push(i);
        }
        else if(ch == ')' || ch==']') {
            int startIndex = st.top();
            int endIndex = i;
            reverse(s.begin()+startIndex,s.begin()+endIndex);
            st.pop();            
        }
    }

    string res = "";
    for(auto ch:s) {
        if(ch != '(' && ch != ')') {
            res+=ch;
        }
    }
    cout<<res<<endl;
}

void validateStackSequence(vector<int>pushed,vector<int>popped) {
    stack<int>st;
    int poppedIndex = 0;
    for(int pushedIndex = 0;pushedIndex<pushed.size();pushedIndex++) {
        while(!st.empty() && st.top() == popped[poppedIndex]) {
            cout<<"POPPED"<<endl;
            st.pop();
            poppedIndex++;
        }
        st.push(pushed[pushedIndex]);
    }

    cout<<st.top()<<endl;
    cout<<poppedIndex<<endl;
    while(poppedIndex < popped.size()) {
        if(st.top() == popped[poppedIndex]) {
            cout<<st.top()<<" "<<popped[poppedIndex]<<endl;
            st.pop();
        }
        else {
            break;
        }
        poppedIndex++;
    }
    if(st.empty() == true) {
        cout<<"TRUE"<<endl;
    }
    else cout<<"False"<<endl;
}


void nextGreaterElements(vector<int>nums) {
    vector<int>res(nums.size(),-1);
    stack<int>mono_dec_stack;
    for(int i=0;i<nums.size();i++) {
        int currentElement = nums[i];
        while(!mono_dec_stack.empty() && currentElement > nums[mono_dec_stack.top()]){
            res[mono_dec_stack.top()] = currentElement;
            mono_dec_stack.pop();
        }
        mono_dec_stack.push(i);
    }

    for(int i=0;i<nums.size();i++) {
        if(mono_dec_stack.empty() == true) {
            break;
        }
        int currentElement = nums[i];
        while(!mono_dec_stack.empty() && currentElement > nums[mono_dec_stack.top()]){
            res[mono_dec_stack.top()] = currentElement;
            mono_dec_stack.pop();
        }
    }

    for(auto r:res) {
        cout<<r<<" ";
    }
}

void minimumRemoveToMakeValidParentheses(string s) {
    //stores the index
    stack<int>st;
    for(int i=0;i<s.length();i++) {
        char ch = s[i];
        if(ch == '(') {
            st.push(i);
        }
        else if(ch ==')') {
            if(st.empty() == true) {
                s.erase(s.begin()+i);
                i--;
            }
            else {
                st.pop();
            }
        }
    }
    while(!st.empty()) {
        s.erase(s.begin()+st.top());
        st.pop();
    }
    cout<<s<<endl;
}

void removeKDigits(string num,int k) {
    stack<int>mono_asc_stack;
    for(int i=0;i<num.length();i++) {
        if(k == 0) {
            break;
        }
        char cur = num[i];
        while(mono_asc_stack.empty() == false && cur < num[mono_asc_stack.top()]) {
            if(k==0) {
                break;
            }

            num[mono_asc_stack.top()] = '#';
            mono_asc_stack.pop();
            k--;
        }
        mono_asc_stack.push(i);
    }
    int topVal = mono_asc_stack.top();
    string res = "";
    for(int i=topVal;i<num.length();i++) {
        res += num[i];
    }
    while(res[0] == '0') {
        res.erase(res.begin()+0);
    }
    
    cout << res << endl;
}

int main() {

    string s = "54321";
    removeKDigits(s,3);
    return 0;
}

//73,74,75,71,69,72,76,73
// 1  1  4  2  1  1  0  0        

