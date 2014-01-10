
struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
        {
            map<UndirectedGraphNode *, int> visited;
            map<UndirectedGraphNode *, int> ::iterator p;
            map<int, UndirectedGraphNode *> graph;
            map<int, UndirectedGraphNode *> ::iterator q;

            int top  = 0;

            queue<UndirectedGraphNode *> Q;
            Q.push(node);
            visited.insert(make_pair(node, top));

            while(!Q.empty())
            {
                UndirectedGraphNode *item = Q.front();
                Q.pop();

                if(item == NULL)continue;

                UndirectedGraphNode *new_item = new UndirectedGraphNode(item->label);
                graph.insert(make_pair(visited.find(item)->second, new_item));
                ++top;

                for(int i = 0, n = item->neighbors.size(); i < n; i++)
                {
                    UndirectedGraphNode *xx = item->neighbors[i];

                    if(visited.find(xx) == visited.end())
                    {
                        Q.push(xx);
                        visited.insert(make_pair(xx, ++top));
                    }
                }
            }

            set<UndirectedGraphNode *> st;
            Q.push(node);
            st.insert(node);


            while(!Q.empty())
            {
                UndirectedGraphNode *item = Q.front();
                Q.pop();

                if(item == NULL)continue;

                p = visited.find(item);
                UndirectedGraphNode *new_item = graph.find(p->second)->second;

                for(int i = 0, n = item->neighbors.size(); i < n; i++)
                {
                    UndirectedGraphNode *xx = item->neighbors[i];

                    if(xx == NULL)
                    {
                        new_item->neighbors.push_back(NULL);
                    }
                    else
                    {
                        new_item->neighbors.push_back(graph.find(visited.find(xx)->second)->second);

                        if(st.find(xx) == st.end())
                        {
                            Q.push(xx);
                            st.insert(xx);
                        }
                    }

                }
            }

            return graph.size() > 0 ? graph.find(0)->second : NULL;
        }
};
