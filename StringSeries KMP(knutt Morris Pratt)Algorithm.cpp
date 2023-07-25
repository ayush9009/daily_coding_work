class Solution {
public:
   // KMP ALGORITHM
        // First make lps array then searching
        // Idea: preprocess the pattern to avoid redundancies and get linear time in the worst-case scenario
    void helper(string pat, vector<int>& lps) {
        int n = pat.size();
        int i = 1, len = 0;
        lps[0] = 0;
        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                }
                else
                    len = lps[len - 1];
            }
        }
    }

    int strStr(string txt, string pat) {
        // KMP ALGORITHM
        int n = pat.size();
        vector<int> lps(n);
        helper(pat, lps);  //function for finding longest proper prfix suffix arrya

        int m = txt.size();
        int i = 0, j = 0;
        while (i < m) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == n) {
                return (i - j);
                j = lps[j - 1];
            }
            else if (i < m && txt[i] != pat[j]) {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1]; // last matched character index
            }
        }
        return -1;
    }
};
