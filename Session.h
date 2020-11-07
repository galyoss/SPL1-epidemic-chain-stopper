//
// Created by galyo on 03/11/2020.
//

#ifndef ASSIGNMENT1_SESSION_H
#define ASSIGNMENT1_SESSION_H

#include "Graph.h"
#include <iostream>
#include "Agent.h"
#include <queue>
class Agent;
using namespace std;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:

    Session(const std::string& path);
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    Graph getGraph() const;
    int getCycleNum() const;
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    void decreaseViruses();
    void increaseViruses();

    void deactivateVirus(int nodeInd);

private:
    Graph g;
    TreeType treeType;
    vector<Agent*> agents;
    int cycleNum;
    queue<int> turns;
    int numOfViruses;
};

#endif //ASSIGNMENT1_SESSION_H
