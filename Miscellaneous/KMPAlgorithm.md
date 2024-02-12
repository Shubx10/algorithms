## 🚀 KMP Algorithm

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
   string tokens          string tokens
          \                   /
            \               /
        String Matching Algorithm
                    |
                    |
            Matching Results
  ```
