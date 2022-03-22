/*
    On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

    The north direction is the positive direction of the y-axis.
    The south direction is the negative direction of the y-axis.
    The east direction is the positive direction of the x-axis.
    The west direction is the negative direction of the x-axis.
    The robot can receive one of three instructions:

    "G": go straight 1 unit.
    "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
    "R": turn 90 degrees to the right (i.e., clockwise direction).
    The robot performs the instructions given in order, and repeats them forever.

    Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

    Example 1:
      Input: instructions = "GGLLGG"
      Output: true
      Explanation: The robot is initially at (0, 0) facing the north direction.
      "G": move one step. Position: (0, 1). Direction: North.
      "G": move one step. Position: (0, 2). Direction: North.
      "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
      "L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
      "G": move one step. Position: (0, 1). Direction: South.
      "G": move one step. Position: (0, 0). Direction: South.
      Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
      Based on that, we return true.
*/

bool isRobotBounded(string instructions) {
    int dirX = 0, dirY = 1, x = 0, y = 0;

    for(int i = 0; i < instructions.size(); i++) {
        if(instructions[i] == 'G') {
            x += dirX;
            y += dirY;
        } else if(instructions[i] == 'L') {
            int temp = dirX;
            dirX = -1*dirY;
            dirY = temp;
        } else {
            int temp = -1*dirX;
            dirX = dirY;
            dirY = temp;
        }
    }

    return (x == 0 && y == 0) || (dirX != 0 || dirY != 1);
}

// Time Complexity = O(n)
