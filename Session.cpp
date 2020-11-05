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
        }
        else
        {

        }
    }



}

void Session::simulate() {
    std::cout << g.neighborsOf(1).size() << std::endl;
}

void Session::setGraph(const Graph &graph) {
    g = graph;
}

Graph Session::getGraph() const {
    return g;
}

void Session::addAgent(const Agent &agent) {
    agents.push_back(agent.clone());
}






