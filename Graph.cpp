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
