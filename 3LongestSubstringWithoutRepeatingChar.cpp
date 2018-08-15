# mycodes

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, max = 1, start = 0;
        if(s.length()==0)   return 0;
        for(i=0; i<s.length(); i++){
            for(j=start; j<i+1; j++){
                if(s[i+1]==s[j] || i==s.length()-1){
                    if(max < i - start + 1)     max = i - start + 1;
                    start = j + 1;
                    break;
                }
            }
        }
        return max;
    }
};


/*
*       Solution 1 ： 暴力破解，检查所有的字串（做时候没想到过，直接用了上述方法），复杂度高
*       Solution 2 ： Sliding Window，只需检查每个字母与之前的字符串中字符是否重合  O(n^2) （针对我的代码，solution中的代码给出的复杂度是O(2n)(Java代码)）
*/


# Solution from discussion part
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
