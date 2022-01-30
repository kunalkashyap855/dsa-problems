/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    
    Example: 
      Input: n = 3
      Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

void rec(int n, int diff, string comb, vector<string>& combs) {
    if(diff < 0 || diff > n)
        return;
    else if(n == 0) {
        if(diff == 0)
            combs.push_back(comb);
    } else {
        comb.append("(");
        rec(n-1, diff+1, comb, combs);
        comb.pop_back();
        comb.append(")");
        rec(n-1, diff-1, comb, combs);
        comb.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> combs;
    rec(2*n, 0, "", combs);
    return combs;
}

// Time Complexity = O(n * 2^n) <- Although due to backtracking, the actual number of operations will be less than (n * 2^n).
