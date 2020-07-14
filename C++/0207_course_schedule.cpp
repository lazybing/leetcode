/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 *
 * Some courses may have prerequisites, for example to tak course 0 you have to first take course 1, which is expressed as a pair:[0, 1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is ti possible for you to finish all courses?
 *
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1, 0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 *          To take course 1 you should have finished course 0. So it is possible.
 *
 *  Example 2:
 *  Input: numCourses = 2, prerequisites = [[1, 0], [0, 1]]
 *  Output: false
 *  Explanation: There are a total of 2 courses to take.
 *          To take course 1 you should have finished courese 0, and to take course 0 you should
 *          also have finished courese1, So it is impossible.
 *
 *  Constraints:
 *  1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
 *      Read more about how a graph is represented.
 *  2. You may assume that there are no duplicate edged in the input prerequisites.
 *  3. 1 <= numCourses <= 10^5
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        for(int i = 0; i<prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        
        for(int i = 0; i<degree.size(); i++){
            if(degree[i] == 0){
                zeroDegree.push(i);
                numCourses--;
            }
        }
        
        while(!zeroDegree.empty()){
            int node = zeroDegree.front();
            zeroDegree.pop();
            for(int i = 0; i<graph[node].size(); i++){
                int connectedNode = graph[node][i];
                degree[connectedNode]--;
                if(degree[connectedNode] == 0){
                    zeroDegree.push(connectedNode);
                    numCourses--;
                }
            }
        }
        
        return numCourses == 0;
    } 
};
