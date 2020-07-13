/**
 * You are given a data structure of employee information,
 * which includes the employee's unique id, their importance value
 * and their direct subordinates' id.
 *
 *
 * Note:
 * 1. One employee has at most one direct leader and may have several subordinates.
 * 2. The maximum number of employees won't exceed 2000.
 */
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;

        queue<Employee*> queue;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                queue.push(employees[i]);
                break;
            }
        }
       
        while (!queue.empty()) {
            int n = queue.size();

            for (int i = 0; i < n; i++) {
                Employee * tmp = queue.front();
                queue.pop();
                res += tmp->importance;

                for (int j = 0; j < tmp->subordinates.size(); j++) {
                    for (int k = 0; k < employees.size(); k++) {
                        if (employees[k]->id == tmp->subordinates[j])
                            queue.push(employees[k]);
                    }
                }
            }
        }
        
        return res;
    }
};
