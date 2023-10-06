#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Graph 
{
public:
    Graph(int numVertices);
    void addEdge(int from, int to);
    void findPairsWithinThreeHandshakes();

private:
    int numVertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int numVertices) : numVertices(numVertices) 
{
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int from, int to) 
{
    adjacencyList[from].push_back(to);
    adjacencyList[to].push_back(from);
}

void Graph::findPairsWithinThreeHandshakes() 
{
    for (int i = 0; i < numVertices; ++i)
    {
        queue<pair<int, int>> bfsQueue;
        set<int> visited;

        bfsQueue.push({ i, 0 });
        visited.insert(i);

        while (!bfsQueue.empty()) 
        {
            int currentVertex = bfsQueue.front().first;
            int distance = bfsQueue.front().second;
            bfsQueue.pop();

            if (distance > 3) 
            {
                break; 
            }

            if (distance > 0 && distance <= 3) 
            {
                cout << "Знакомы: " << i << " и " << currentVertex << endl;
            }

            for (int neighbor : adjacencyList[currentVertex])
            {
                if (visited.find(neighbor) == visited.end()) 
                {
                    bfsQueue.push({ neighbor, distance + 1 });
                    visited.insert(neighbor);
                }
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    Graph socialNetwork(7);

    socialNetwork.addEdge(0, 1);
    socialNetwork.addEdge(0, 2);
    socialNetwork.addEdge(1, 3);
    socialNetwork.addEdge(2, 4);
    socialNetwork.addEdge(3, 5);
    socialNetwork.addEdge(4, 6);

    socialNetwork.findPairsWithinThreeHandshakes();

    return 0;
}
