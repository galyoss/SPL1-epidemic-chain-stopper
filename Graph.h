//
// Created by galyo on 03/11/2020.
//

#ifndef SPL_ASSIGNMENT1_GRAPH_H
#define SPL_ASSIGNMENT1_GRAPH_H
using namespace std;
#include <vector>
#include "Tree.h"
#include <queue>
class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    Graph();
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    void updateGraph(vector<vector<int>> matrix);
    int getSize() const;
    void removeEdge(int vertexA, int vertexB);
    vector<int> neighborsOf(int vertexA);
    bool isDead(int nodeInd);
    void moveToDead(int nodeInd);

private:
    std::vector<std::vector<int>> edges;
    queue<int> infectedQ;
    vector<int> infectedNodes;


};

#endif //SPL_ASSIGNMENT1_GRAPH_H
