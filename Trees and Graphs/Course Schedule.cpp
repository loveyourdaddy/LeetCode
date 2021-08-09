// worst case O(n^2)
// Runtime: 20 ms
// Memory Usage: 13.5 MB
class Solution {
public:
    vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { //courese , prerequist
        //hash_map<int, vector<int>> hashmap;
        
        // pre requisti의 갯수만큼 그래프를 만들어 줍니다. 
        graph.resize(numCourses);
        int length = prerequisites.size();
        for (int i = 0; i < length; i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited; visited.resize(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            if (isVisited(i, visited))
                return false;            
        }
        return true; 
    }

    bool isVisited(int i, vector<int> &visited) {
		// visiting = 1, visited = 2
        if (visited[i] == 2)
            return false;
		if (visited[i] == 1)
			return true;
		visited[i] = 1;

		for (auto a : graph[i])
		{ 
			if (isVisited(a, visited))
				return true;
        }
        
        // 모든 방문이 끝났다면 더이상 체크하지 않음으로 표시 
        visited[i] = 2;
        return false;
    }
};
