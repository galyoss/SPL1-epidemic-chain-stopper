//
// Created by galyo on 03/11/2020.
//

#include "../Include/Graph.h"
#include <queue>
#include <vector>

void Graph::removeEdge(int vertexA, int vertexB) {
    edges [vertexA][vertexB]=0;
    edges [vertexB][vertexA]=0;

}
// going over neighbors and returning vector with their number
vector<int> Graph::neighborsOf(int vertexA) const {
    vector<int> ans;
    for (unsigned int i = 0; i < edges.size(); ++i) {
        if (edges[vertexA][i]==1)
            ans.push_back(i);
    }
    return ans;
}

Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix),infectedQ(), infectedNodes() {

}

Graph::Graph() :edges(),infectedQ(), infectedNodes(){

}


void Graph::updateGraph(vector <vector<int>> matrix) {
    edges = matrix;

}

int Graph::getSize() const {
    return edges.size();
}




bool Graph::isInfected(int nodeInd) const {
    for (unsigned int i = 0; i < infectedNodes.size(); ++i)
        if (infectedNodes[i]==nodeInd)
            return true;
    return false;
}

void Graph::infectNode(int nodeInd)  {

    infectedNodes.push_back(nodeInd);
//    infectedQ.push(nodeInd);


}


void Graph::isolateNode(int node) {
    for (unsigned int i = 0; i < edges.size(); ++i)
        removeEdge(node,i);

}

queue<int> &Graph::getInfQ() {
    return infectedQ;
}

int Graph::getInfectedNum() const {
    return infectedNodes.size();
}

vector<int> &Graph::getInfectedNodes() {
    return infectedNodes;
}

vector<vector<int>> &Graph::getEdges() {
    return edges;
}
