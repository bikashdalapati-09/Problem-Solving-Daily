class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lowercaseSet;
        unordered_set<char> uppercaseSet;
        
        for (char c : word) {
            if (islower(c)) lowercaseSet.insert(c);
            if (isupper(c)) uppercaseSet.insert(c);
        }
        int count = 0;

        for(auto ch : uppercaseSet){
            if(lowercaseSet.count(tolower(ch))){
                count++;
            }
        }
        return count;
    }
};