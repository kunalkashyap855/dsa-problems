/*
    There is a programming language with only four operations and one variable X:
    ++X and X++ increments the value of the variable X by 1.
    --X and X-- decrements the value of the variable X by 1.
    
    Initially, the value of X is 0.
    Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

    Example 1:
      Input: operations = ["--X","X++","X++"]
      Output: 1
      Explanation: The operations are performed as follows:
      Initially, X = 0.
      --X: X is decremented by 1, X =  0 - 1 = -1.
      X++: X is incremented by 1, X = -1 + 1 =  0.
      X++: X is incremented by 1, X =  0 + 1 =  1.
*/



int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;

    for(int i = 0; i < operations.size(); i++) {
        string op = operations[i];
        // ASCII value of '+' is 43 and that of '-' is 45
        ans += (44 - op[1]);
    }

    return ans;
}

int finalValueAfterOperations(vector<string>& operations) {
    int ans = 0;

    for(int i = 0; i < operations.size(); i++) {
        string op = operations[i];
        if(op == "X--" || op == "--X")
            ans--;
        else ans++;
    }
}

// Time Complexity = O(n)

        return ans;
    }
