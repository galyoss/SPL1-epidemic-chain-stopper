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


    std::cout << agents.size() << std::endl;
    std::cout << treeType << std::endl;
    std::cout << g.getSize() << std::endl;

}

// running the whole thing (functions and workflow)

void Session::simulate() {
    int sick_num_before = g.getInfectedNum();
    int sick_num_after = 0;

    while (checkGraph()){
        cycleNum++;
        sick_num_before=g.getInfectedNum();
        int agents_num=agents.size();
        for (int i=0;i<agents_num;i++)
            agents.at(i)->act(*this);

        sick_num_after=g.getInfectedNum();
    }

    json out;

    out["header"] = {"infected", "graph"};
    out["graph"] = {1,2,3};
    out["infected"] = g.getInfectedNodes();
    ofstream i("output.json");
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


    Session::~Session()  { //TODO: complete
        for (auto ag:agents)
            delete ag;
    }

TreeType Session::getTreeType() const {
    return treeType;
}

int Session::getCycleNum() const {
    return cycleNum;
}

bool Session::checkGraph() {
    vector<bool> visited(g.getSize(), false);
    for (int i = 0; i <visited.size() ; ++i) {
        if(!visited[i]){ //not visited in this node
            vector<int> queue;
            bool firstStatus = g.isInfected(i);
            queue.push_back(i);

            while (!queue.empty()){ //starting BFS
                int curr = queue.front();
                queue.erase(queue.begin());
                visited[curr]=true;
                for (int n: g.neighborsOf(curr)) {
                    if (!visited[n])
                    {

                        if (g.isInfected(n) != firstStatus)
                        return true;
                   else
                        queue.push_back(n);}

                }
                }

            }
        }
    return false;
    }




