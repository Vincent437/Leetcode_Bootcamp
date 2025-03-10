class Solution {
    public:
        int myAtoi(string s) {
            int sign = 1;
            long num = 0;
            int flag = 0;
            int ans;
            int i = 0;
    
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
    
            if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
                sign = (s[i] == '-') ? -1 : 1;
                i++;
            }
    
            while (i < s.size()) {
                if (s[i]>='0'&&s[i]<='9') {
                    num = num * 10 + (s[i] - '0');
    
                    if (num * sign > INT_MAX) return INT_MAX;
                    if (num * sign < INT_MIN) return INT_MIN;
                } else {
                    break;
                }
                i++;
            }
    
            return (int)(num * sign);
        }

        vector<int> findAnagrams(string s, string p) {
            int sLen = s.size(), pLen = p.size();
    
            if (sLen < pLen) {
                return vector<int>();
            }
    
            vector<int> ans;
            vector<int> count(26);
            for (int i = 0; i < pLen; ++i) {
                ++count[s[i] - 'a'];
                --count[p[i] - 'a'];
            }
    
            int differ = 0;
            for (int j = 0; j < 26; ++j) {
                if (count[j] != 0) {
                    ++differ;
                }
            }
    
            if (differ == 0) {
                ans.emplace_back(0);
            }
    
            for (int i = 0; i < sLen - pLen; ++i) {
                if (count[s[i] - 'a'] == 1) {
                    --differ;
                } else if (count[s[i] - 'a'] == 0) {
                    ++differ;
                }
                --count[s[i] - 'a'];
    
                if (count[s[i + pLen] - 'a'] == -1) {
                    --differ;
                } else if (count[s[i + pLen] - 'a'] == 0) {
                    ++differ;
                }
                ++count[s[i + pLen] - 'a'];
                
                if (differ == 0) {
                    ans.emplace_back(i + 1);
                }
            }
    
            return ans;
        }

        string trim(string s){
            for(int i =0; i<s.size();i++){
                if(s[i]!=' '){
                    s = s.substr(i,s.size()-i);
                    break;
                }
            }
            for(int i =0; i<s.size();i++){
                if(s[s.size()-i-1]!=' '){
                    s = s.substr(0,s.size()-i);
                    break;
                }
            }
            return s;
        }
        string reverseWords(string s) {
            s = trim(s);
    
            vector<string> v;
            size_t left = 0;
            size_t pos = s.find(' ');
    
            while (pos != string::npos) {
                if(s[left]!=' '){
                    v.emplace_back(s.substr(left, pos - left));
                }
                
                left = pos + 1;
                pos = s.find(' ', left);
            }
    
            v.emplace_back(s.substr(left));
    
            string ans;
            for (int i = v.size() - 1; i >= 0; i--) {
                ans += v[i];
                if (i > 0) ans += " ";
            }
    
            return ans;
        }
        
    };