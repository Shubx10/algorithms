class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> justified;
        for(int i = 0; i < n; ++i){
            int j = i + 1;
            int charLength = words[i].size();
            int emptySlots = 0;
            while(j < n && words[j].size() + charLength + emptySlots + 1 <= maxWidth){
                charLength += words[j].size();
                emptySlots += 1;
                j++;
            }
            int spaces = maxWidth - charLength;
            int eachSlotSize = emptySlots ? spaces / emptySlots : 0;
            int extraSpaces = emptySlots ? spaces % emptySlots : 0;
            string temp = "";
            if(j == n){
                for(int k = i; k < j; ++k){
                    temp += words[k];
                    if(k != j - 1){
                        temp += ' ';
                    }
                }
            }else{
                for(int k = i; k < j; ++k){
                    temp += words[k];
                    if(k != j - 1){
                        temp += string(eachSlotSize, ' ');
                        if(extraSpaces){
                            temp += ' ';
                            extraSpaces--;
                        }
                    }
                }
            }
            if(temp.size() < maxWidth){
                temp += string(maxWidth - temp.size(), ' ');
            }
            justified.push_back(temp);
            i = j - 1;
        }
        return justified;
    }
};
