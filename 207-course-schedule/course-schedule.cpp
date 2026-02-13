class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>graph(n);
        vector<int>ind(n, 0);
        vector<int>topo;
        
        for(auto it: prerequisites){
            graph[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(ind[i]==0)q.push(i);
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();

            topo.push_back(a);

            for(auto itr: graph[a]){
                ind[itr]--;
                if(ind[itr]==0)q.push(itr);
            }
        }
        return topo.size() == n;


    }
};