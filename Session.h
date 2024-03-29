//
// Created by galyo on 03/11/2020.
//

#ifndef ASSIGNMENT1_SESSION_H
#define ASSIGNMENT1_SESSION_H

#include "Graph.h"
#include <iostream>
#include "Agent.h"
class Agent;
using namespace std;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:

    Session(const std::string& path); //constructor

    ~Session(); //destructor

    Session(const Session& session); //copy constructor

    Session& operator=(const Session &other); //copy assignment

    Session(Session&& other); //move constructor

    Session& operator=(Session&& session); //move assignment operator

    void simulate();

    void addAgent(const Agent& agent);

    void setGraph(const Graph& graph);

    Graph& getGraph() ;

    int getCycleNum() const;

    void enqueueInfected(int);

    int dequeueInfected();

    TreeType getTreeType() const;





private:

    void steal(Session& session);

    void copy(const Session& session);

    void clear();

    Graph g;
    TreeType treeType;
    vector<Agent*> agents;
    int cycleNum;

};

#endif //ASSIGNMENT1_SESSION_H
