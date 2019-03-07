/* 
  字符串匹配问题，正确解法待补充
*/

//不知道为什么runtime error, heap-buffer-overflow了。。
//不过解法确实是错的。虽然我一开始就知道是dp，但看了题目后天真的以为直接能接QAQ，当然结果就是自己理解错题目的意思了。

/* 放上错误的解法
    错误原因：这种解法中，一旦某对字符匹配成功了，直接往下走，不管是不是错位了
*/
/*
  s = "duuppa"
  p = "d.*ppa"
  正确是true，我的解法也是true
  
  s = "duuppauuuppa"
  p = "d.*ppa"
  这种情况下应该是true，但我的解法认为这是false
  
  以及
  s = "duupppa"
  p = "d.*ppa"
  也是错误的。
  
  其他还有一些小问题，可以改（但没有必要了）。上面的问题是这个解法下必然出现的错误。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int s_len = s.length();
        int p_len = p.length();
        char s_pre = '#';
        char p_pre = '#';
        bool match = true;
        bool need_match = false;
        for(i = 0, j = 0; i < s_len, j < p_len; i++, j++){
            if(s[i]==p[j])  continue;
            else if(p[j]=='*'){
                if(s[i]!=s_pre && p_pre!='.'){
                    match = false;
                    break;
                }
            }
            else if(p[j]=='.'){
                // do nothing
            }
            else if(p_pre=='*'){
                if(s[i]!=s[j]){
                    match = false;
                    break;
                }
            }
            else{
                if(j + 1 < p_len && p[j+1]=='*'){
                    i--;
                    continue;
                    // s_pre & p_pre no change
                }
            }
            s_pre = s[i];
            p_pre = p[i];
        }
        if(j<p_len) return false;
        if(i<s_len){
            if(p_pre!='*')  match = false;
            else{
                for(; i < s_len; i++){
                    if(s[i]!=s_pre){
                        match = false;
                        break;
                    }
                }
            }
        }
        return match;
    }
};
