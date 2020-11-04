//
// Created by galyo on 03/11/2020.
//

#include "Session.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <sstream>
#include "vector"
#include "Graph.h"
#include "Agent.h"

using namespace std;
using json=nlohmann::json;

Session::Session(const std::string &path):g() {
    std::ifstream f(path);
    json j = json::parse(f);
    vector<vector<int>> matrix = j["graph"];
    Graph gr(matrix);
    setGraph(gr);
    std::string ttype = j["tree"];
    if (ttype == "M")
        treeType = MaxRank;
    if (ttype == "C")
        treeType = Cycle;
    if (ttype == "R")
        treeType = Root;







}

void Session::simulate() {
    std::cout << g.neighborsOf(1).size() << std::endl;
}

void Session::setGraph(const Graph &graph) {
    g = graph;
}


