class Solution {
public:
    bool check_cycle = false;
       list<int> *adj;

    void addEdge(int v,int w){
        adj[v].push_back(w);
    }

    bool DFSUtil(int v,bool visited[],bool recStack[]){
        if(visited[v]==true){
            check_cycle = true;
            return true;
        }
        visited[v]=true;
        recStack[v]=true;
        list<int>::iterator it;
        for(it = adj[v].begin();it!=adj[v].end();++it){
            if(visited[*it]==false){
                DFSUtil(*it,visited,recStack);
            }
            else if(recStack[*it]==true){
                check_cycle = true;
           // return true;
            }
        }
        recStack[v]=false;
        return false;
    }
    bool DFS(int V){
        bool *visited = new bool[V];
         bool  *recStack = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;

        }

        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFSUtil(i,visited,recStack);
            }
        }
        return check_cycle;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        adj = new list<int>[numCourses];
        for(unsigned i=0;i<prerequisites.size();i++){
           addEdge(prerequisites[i][0],prerequisites[i][1]);
        }
    if(DFS(numCourses)){
        return false;
    }
        else{
            return true;
        }
    }
};
