/*
    There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
    You begin the journey with an empty tank at one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction,
    otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int remaining = 0, prev_remaining = 0, candidate = 0;

    for(int i = 0; i < gas.size(); i++) {
        remaining += gas[i] - cost[i];
        if(remaining < 0) {
            candidate = i+1;
            prev_remaining += remaining;
            remaining = 0;     
        }
    }

    if(candidate == gas.size() || remaining + prev_remaining < 0)
        return -1;

    return candidate;
}

// Time Complexity = O(n)
