#ifndef AUXCLASS_H
#define AUXCLASS_H
#include <QString>
#include <string>
using namespace std;

class Graph {

    int src, target;
    int dist[100];
    bool visited[100];
    int parent[100];
    int count = 0;
public:
    int vertArr[20][20];
    int vertices = 0;

public:
    Graph(int src, int target, string file_name);
    void init();
    int getNearest();
    void dijkstra();
    string display();
    void dijkstra_Algorithm();
    void generateGraph(string file_name);
    void displayMatrix(int v);
    void add_edge(int u, int v, int weight);
    void readRecord();


};

#endif // AUXCLASS_H
