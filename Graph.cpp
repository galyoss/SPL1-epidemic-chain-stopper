//
// Created by galyo on 03/11/2020.
//

#include "Graph.h"
#include <iostream>

void Graph::removeEdge(int vertexA, int vertexB) {
    edges [vertexA][vertexB]=0;
    edges [vertexB][vertexA]=0;

}
// going over neighbors and returning vector with their number
vector<int> Graph::neighborsOf(int vertexA) {
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

bool Graph::isDead(int nodeInd) {
    for (int i = 0; i <dead.size() ; ++i)
        if (dead[i]==nodeInd)
            return true;

    return false;
}

void Graph::moveToDead(int nodeInd) {
    dead.push_back(nodeInd);

}

bool Graph::isInfected(int nodeInd) {
    for (int i = 0; i < infectedNodes.size(); ++i)
        if (infectedNodes[i]==nodeInd)
            return true;
    return false;
}

void Graph::infectNode(int nodeInd) {
    infectedNodes.push_back(nodeInd);
    infectedQ.push(nodeInd);
}
