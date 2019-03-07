class Solution {
public:
    string convert(string s, int numRows) {
        long len = s.length();
        int divert = 0;
        int pos;
        if(numRows <= 0)    return "";
        if(numRows == 1)    return s;
        string * result = new string[numRows];
        string str;
        for(long i = 0, j = 0; i < len; i++, j++){
            pos = j % numRows;
            if(pos==0 && i != 0){
                i--;
                divert = divert == 0 ? 1 : 0;
                continue;
            }
            if(divert)  pos = numRows - pos - 1;
            result[pos] += s[i];
        }

        for(int i = 0; i < numRows; i++){
            str += result[i];
        }
        return str;
    }
};
