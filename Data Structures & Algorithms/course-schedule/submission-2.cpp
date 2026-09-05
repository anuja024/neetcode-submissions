class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> list(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& pre : prerequisites){
            int course = pre[0];
            int prerequisite = pre[1];

            list[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0; i< numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int completed = 0;
        while(! q.empty()){
            int course = q.front();
            q.pop();
            completed ++;

            for(int next: list[course]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return completed == numCourses;
    }
};
