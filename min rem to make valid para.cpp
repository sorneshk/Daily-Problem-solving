class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<pair<char,int>> st;
        vector<int> idx;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])) continue;
            if(s[i]=='('){
                st.push({s[i],i});
                continue;
            }
            if(st.empty()) st.push({s[i],i});
            else{
                if(s[i]==')' && (st.top().first=='(')) st.pop();
                else st.push({s[i],i});
            }
        }
        string dup="";
        int point=0;
        while(!st.empty()){
            idx.push_back(st.top().second);
            st.pop();
        }
        sort(idx.begin(),idx.end());
        for(int i=0;i<n;i++){
            if(point<idx.size() && i==idx[point]){
                point++;
                continue;
            }
            else dup+=s[i];
        }
        return dup;
        
    }
};