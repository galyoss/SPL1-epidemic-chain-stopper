//
// Created by galyo on 03/11/2020.
//

#include "Tree.h"
#include <vector>
#include <queue>
#include "Session.h"
using namespace std;



//=======Tree constructor=======
Tree::Tree(int rootLabel): node(rootLabel){}
//destructor
Tree::~Tree(){
    for (int i = 0; i <children.size() ; ++i) {
        delete children[i];
    }
};

//=========Root tree constructors=========


RootTree::RootTree(int rootLabel1, int rootLabel) : Tree(rootLabel1) {}



//destructor
RootTree::~RootTree(){}

//=========MaxRankTree constructors========
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}
//destructor
MaxRankTree:: ~MaxRankTree() {}


Tree * Tree::createTree(const Session &session, int rootLabel) {
/*

Tree *Tree::createTree(const Session &session, int rootLabel) {
    /* returns vector visited, each vertex's distance from the origin is its value
/i.e. :
                         4
                      /      \
                    2          1
                /                           3
            0
running the the BFS from 5 will give the following vector: <2,1,2,0,-1>
 0 means unreachable from this node, -1 is the source, all other numbers are distance from origin
    */
Graph g = session.getGraph();

vector<int> visited(g.getSize(),0);
queue<int> Q;
visited.at(rootLabel)=-1;
// visited source
Q.push(rootLabel);
visited[rootLabel]=true;
int distance = 1;
while (!Q.empty()){
int curr = Q.front();
Q.pop();
vector<int> neighbors = g.neighborsOf(curr);
for (int i = 0; i < neighbors.size(); ++i) {
if (visited.at(neighbors.at(i))==0)
Q.push(neighbors.at(i));
visited.at(neighbors.at(i))=distance;
}
distance++;
}
}






void Tree::addChild(const Tree &child) {

//==========CycleTree constructors=========

    CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel):curr{}

    CycleTree::~CycleTree()    {}


    CycleTree::CycleTree(int
    rootLabel, int
    currCycle){

    }
    CycleTree::CycleTree(int
    rootLabel, int
    currCycle){

    }
    CycleTree::CycleTree(int
    rootLabel, int
    currCycle){

    }
}



