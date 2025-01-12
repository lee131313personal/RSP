class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1) return 1;

        int start = 0; 
        int end = 0;
        int maxLength = 0;

        std::set<char> charSet;
        while (end < s.length ()) {
            if (charSet.find(s[end]) == charSet.end()) {
                charSet.insert(s[end]);
                maxLength = std::max(maxLength, end - start + 1);
                end ++;
            }
            else {
                charSet.erase(s[start]);
                start++;
            }
        }
        return maxLength;
    }
};
