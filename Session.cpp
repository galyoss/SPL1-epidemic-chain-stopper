//
// Created by galyo on 03/11/2020.
//

#include "Agent.h"
#include "Session.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <sstream>
#include "vector"
#include "Graph.h"
#include "queue"




using namespace std;
using json=nlohmann::json;

//=======Rule of five==========

Session::Session(const std::string &path):g(), cycleNum(0) {
    std::ifstream f(path);
    json j = json::parse(f);
    vector<vector<int>> matrix = j["graph"];
    g.updateGraph(matrix);
    std::string ttype = j["tree"];
    if (ttype == "M")
        treeType = MaxRank;
    if (ttype == "C")
        treeType = Cycle;
    if (ttype == "R")
        treeType = Root;
    json age = j["agents"];

    for (int i=0;i<age.size();i++)
    if (((std::string)age[i][0]=="V"))
    {
        Virus vr(age[i][1]);
        addAgent(vr);
     }
    else
    {
        ContactTracer ct;
        addAgent(ct);
    }

}



Session::~Session()  { //destructor
    clear();
}

//copy constructor
Session::Session(const Session &session) {
    copy(session);
}


//move constructor
Session::Session(Session &&other) {
    steal(other);
}
//move assignment operator
Session &Session::operator=(Session &&session) {
    if (this!=&session)
    {
        clear();
        steal(session);
    }
    return *this;
}

//copy assignment
Session &Session::operator=(const Session &other) {
    if (this!=&other) {
        clear();
        copy(other);
    }
    return *this;
}


void Session::copy(const Session &session) { //deep copy of graph, agents, etc.

    g = session.g; //TODO: make sure graph is deep copied in this way
    for (Agent* age: session.agents)
        agents.push_back(age->clone());
    cycleNum=session.cycleNum;
    treeType=session.treeType;

}

void Session::clear() {

    for (auto ag:agents)
        if (ag)
            delete ag;

}

void Session::steal(Session &session) {
    g = session.g;
    treeType=session.treeType;
    cycleNum=session.cycleNum;
    agents=session.agents;
    for (Agent* age: session.agents)
        age= nullptr;

}

void Session::simulate() {
    int sick_num_before = g.getInfectedNum();
    int sick_num_after = 0;

    while (sick_num_after!=sick_num_before){

        sick_num_before=g.getInfectedNum();
        int agents_num=agents.size();
        for (int i=0;i<agents_num;i++)
            agents.at(i)->act(*this);

        sick_num_after=g.getInfectedNum();
        cycleNum++;
    }

    json out;

    out["graph"] = g.getEdges();
    out["infected"] = g.getInfectedNodes();
    ofstream i("output4_4.json");
    i << out;
    std::cout << out << std::endl;



    std::cout << "finished game" << std::endl;
    //TODO: session finished, build output json here
}
void Session::enqueueInfected(int a) {
    g.infectNode(a);
}


void Session::setGraph(const Graph &graph) {
    g = graph;
}

 Graph& Session::getGraph()  {
    return g;
}

void Session::addAgent(const Agent &agent) {
    Agent* age = agent.clone();
    agents.push_back(age);
    if (age->getNode()!=-1 && !g.isInfected(age->getNode()))
        enqueueInfected(age->getNode());

}

int Session::dequeueInfected() {
    if (!g.getInfQ().empty()) {
        int ans = g.getInfQ().front();
        g.getInfQ().pop();
        return ans;
    }
    return -1;
}


TreeType Session::getTreeType() const {
    return treeType;
}

int Session::getCycleNum() const {
    return cycleNum;
}








