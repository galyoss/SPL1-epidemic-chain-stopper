//
// Created by galyo on 03/11/2020.
//

#include "Graph.h"
#include <iostream>
#include <queue>
#include <vector>

void Graph::removeEdge(int vertexA, int vertexB) {
    edges [vertexA][vertexB]=0;
    edges [vertexB][vertexA]=0;

}
// going over neighbors and returning vector with their number
vector<int> Graph::neighborsOf(int vertexA) const {
    vector<int> ans;
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[vertexA][i]==1)
            ans.push_back(i);
    }
    return ans;
}

Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix) {

}

Graph::Graph() {

}

void Graph::updateGraph(vector <vector<int>> matrix) {
    edges = matrix;

}

int Graph::getSize() const {
    return edges.size();
}




bool Graph::isInfected(int nodeInd) const {
    for (int i = 0; i < infectedNodes.size(); ++i)
        if (infectedNodes[i]==nodeInd)
            return true;
    return false;
}

void Graph::infectNode(int nodeInd)  {

    infectedNodes.push_back(nodeInd);
    infectedQ.push(nodeInd);

}

int Graph::getSickNode()  {
    if (!infectedQ.empty()){
        int ans = infectedQ.front();
        infectedQ.pop();
        return ans;
    }

    return -1;
}
