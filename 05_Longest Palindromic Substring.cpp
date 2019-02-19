
/*
  my solution
  methods : dynamic programming(自底向上)
  思路：用dp[i][j]来表示s的字串(i, j)回文的长度，如果不是则为0。最后的结果是dp数组中的最大值对应的i, j。
  递归式: if s[i] == s[j]  dp[i][j] = dp[i+1][j-1]
          else  dp[i][j] = 0
  其他：dp写出递归式后就可以自己写代码了，递归式和最终的代码还是有出入的，但个人认为看别人的代码不如自己了解过程后直接上手写（精简的可借鉴代码除外）
  过程：1. 构造dp[s.len][s.len]，目的如上
       2. 例子"ababc"，先算单个字符，再算ab, ba, ab....故：i作为长度, j作为字符串起始位置，这样做的好处是在计算dp[i][j]时确保已经计算过dp[i+1][j-1]（这个长度更短）
       3. 其他则是一些特殊情况用if else控制即可
*/
class Solution {
public:
    int *dp;
    string longestPalindrome(string s) {
        //cout << s << endl;
        int **dp;
        int len = s.length();
        int max_len = 0;
        int dp_begin = 0, dp_end = 0;
        dp = new int*[len];
        for(int i=0; i<len; i++){
            dp[i] = new int[len];
        }
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                dp[i][j] = -1;
            }
        }
        for(int i=0; i<len; i++){
            for(int j=0; i+j<len; j++){
               // cout << j << ": " << s[j] << i+j << ": " << s[i+j] << endl;
                if(j==i+j)    dp[j][i+j] = 1;
                else if(s[j] == s[i+j]){
                    if(j+1 <= i+j-1 && dp[j+1][i+j-1]!=0)
                        dp[j][i+j] = dp[j+1][i+j-1] + 2;
                    else if(j == i+j-1)
                    dp[j][i+j] = 2;
                    else
                        dp[j][i+j] = 0;
                }
                else    dp[j][i+j] = 0;
            }
        }
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(dp[i][j] > max_len){
                    max_len = dp[i][j];
                    dp_begin = i;
                    dp_end = j;
                }
            }
        }
        return s.substr(dp_begin, dp_end - dp_begin + 1);
        }
};
