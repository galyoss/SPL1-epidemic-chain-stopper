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


using namespace std;
using json=nlohmann::json;





Session::Session(const std::string &path):g() {
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
    for (auto ag : j["agent"])
    {
        if (ag[0]="V")
        {
            Virus vr(ag[1]);
            addAgent(vr);
            numOfViruses++;
        }
        else
        {
            ContactTracer ct();
            addAgent(ct())
        }
    }
}

// running the whole thing (functions and workflow)

void Session::simulate() {
    while (hasVirus()==true){
    // creating turns in each cycle
    for (int i = 0; i < agents.size() ; ++i) {}
        // turns is only with ints, any int which is a number means its a virus, if its -1 its contact tracer
//        turns.push() (agents number (-1 for CT, or other non negative int based of the virus's location));


            int current = turns.front();
            turns.pop();
            if (current==-1) {
                ContactTracer ct;
                ct.act(*this);
            }
            else{
                Virus vir(current);
                vir.act(*this);
            }
    }
}
void Session::enqueueInfected(int a) {} //TBD!!!


void Session::setGraph(const Graph &graph) {
    g = graph;
}

Graph Session::getGraph() const {
    return g;
}

void Session::addAgent(const Agent &agent) {
    agents.push_back(agent.clone());
}

int Session::dequeueInfected() {}

void Session::decreaseViruses(){
    numOfViruses--;
}

void Session::increaseViruses() {
    numOfViruses++;
}
void Session::eraseAgent(int nodeInd){
    for (int i = 0; i < agents.size(); ++i) {
        if (agents[i].==nodeInd)

    }
}
//TBD!!!


