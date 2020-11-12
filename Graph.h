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

    void infectNode(int nodeInd) ;

    bool isInfected(int nodeInd) const;

    void updateGraph(vector<vector<int>> matrix);

    int getSize() const;

    void removeEdge(int vertexA, int vertexB);

    vector<int> neighborsOf(int vertexA) const;

    void isolateNode(int node);

    queue<int>& getInfQ();

    int getInfectedNum() const;

    vector<int>& getInfectedNodes();

    vector<vector<int>>& getEdges();


private:
    std::vector<std::vector<int>> edges;

    queue<int> infectedQ;

    vector<int> infectedNodes;


};

#endif //SPL_ASSIGNMENT1_GRAPH_H
