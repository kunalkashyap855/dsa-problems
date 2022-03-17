/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
    Return the answer in any order.

    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:
      Input: digits = "23"
      Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

vector<string> letterCombinations(string digits) {
    if(digits.size() == 0)
        return {};

    vector<string> ans;

    unordered_map<char, string> numToLetter;

    numToLetter['2'] = "abc";
    numToLetter['3'] = "def";
    numToLetter['4'] = "ghi";
    numToLetter['5'] = "jkl";
    numToLetter['6'] = "mno";
    numToLetter['7'] = "pqrs";
    numToLetter['8'] = "tuv";
    numToLetter['9'] = "wxyz";

    string str = numToLetter[digits[0]];
    for(int i = 0; i < str.size(); i++) {
        string s(1, str[i]);
        ans.push_back(s);
    }


    for(int i = 1; i < digits.size(); i++) {
        vector<string> temp;
        string curr = numToLetter[digits[i]];
        for(int j = 0; j < ans.size(); j++) {
            for(int k = 0; k < curr.size(); k++) {
                temp.push_back(ans[j] + curr[k]);
            }
        }
        ans = temp;
    }

    return ans;
}
