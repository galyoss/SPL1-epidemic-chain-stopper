//
// Created by galyo on 03/11/2020.
//

#include "Graph.h"
#include <iostream>

void Graph::removeEdge(int vertexA, int vertexB) {
    edges [vertexA][vertexB]=0;
    edges [vertexB][vertexA]=0;

}
