## 🚀 Knuth Morris Pratt (KMP) Algorithm

- Time Complexity - `O(n + m)` where n is the length of string and m is the length of pattern that we have to search
- Spce complexity - `O(m)`
- The naive string matching algorithm would either use a sliding window, or a two pointer approach which would result in extra comparisons. The time complexity for the naive algorithm would be `O(m * n)`
- Components - `prefix`, `suffix`, `LPS table : Table for detecting the Longest Proper Prefix that is also a Suffix`
- The only disadvantage of the algorithm is that it is very complex to understand
- Applications - `checking for plagiarism in documents`, `spelling checkers`, `search engines, for searching content in large databases`, `Bioinformatics and DNA sequencing`, etc. The most common and easiest use case is plagiarism. The flowchart below describes the process.

```
  Document1               Document2
      |                       |
      |                       |
  Decompose into          Decompose into
  string tokens           string tokens
          \                   /
            \               /
        String Matching Algorithm
                    |
                    |
            Matching Results
```
```cpp
class Solution {
  public:
      void computeLPS(string& pat, vector<int>& lps){
          int n = pat.size();
          int len = 0;
          int i = 1;
          while(i < n){
              if(pat[i] == pat[len]){
                  len++;
                  lps[i] = len;
                  i++;
              }else{
                  if(len != 0){
                      len = lps[len - 1];
                  }else{
                      lps[i] = 0;
                      i++;
                  }
              }
          }
      }
      vector <int> search(string pat, string txt){
          int n = txt.size(), m = pat.size();
          vector<int> lps(m, 0);
          computeLPS(pat, lps);
          vector<int> ans;
          int i = 0;  // index for text
          int j = 0;  // index for pattern
          while(i < n){
              if(txt[i] == pat[j]){
                  i++, j++;
              }
              if(j == m){
                  ans.push_back(i - j + 1); // pattern found at index
                  j = lps[j - 1];
              }else if(i < n && txt[i] != pat[j]){
                  if(j != 0){
                      j = lps[j - 1];
                  }else{
                      i++;
                  }
              }
          }
          return ans;
      }
};
```
