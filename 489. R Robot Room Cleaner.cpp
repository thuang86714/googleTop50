/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
#include <unordered_map>
#include <vector>
using namespace std;
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        if(visited[x][y] == 1){
            return;
        }
        visited[x][y] = 1;
        robot.clean();
        for(int i = 0; i < 4; i++){//cannot use dirs.size()
            if(robot.move()){
                x += dirs[dir].first;
                y += dirs[dir].second;
                cleanRoom(robot);
                goBack(robot);
                x -= dirs[dir].first;
                y -= dirs[dir].second;
            }
            robot.turnRight();
            dir = (dir + 1)%4;
        }
    }
private:
    unordered_map<int, unordered_map<int, int>> visited;
    int x = 0, y = 0, dir = 0;
    vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    /*
    Explore 4 directions: up, right, down, and left (the order of dirs is important since the idea is always to turn right) :
    */
    void goBack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};