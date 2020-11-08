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


Tree::~Tree() {
    delete &children;
}

//=========Root tree constructors=========





RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}

RootTree::RootTree(const RootTree &other) : Tree(other){}; //TODO: verify make it work

//destructor
RootTree::~RootTree(){

}

RootTree *RootTree::clone() const {
    return nullptr;
}

int RootTree::traceTree() {
    return 0;
}

//=========MaxRankTree constructors========
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}
//destructor
MaxRankTree:: ~MaxRankTree() {}

MaxRankTree::MaxRankTree(const MaxRankTree &other):Tree(other) { //TODO: make it work in office hours

}

MaxRankTree *MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

int MaxRankTree::traceTree() {
    return 0;
}


//Tree * Tree::createTree(const Session &session, int rootLabel) {
///*
//
//Tree *Tree::createTree(const Session &session, int rootLabel) {
//    /* returns vector visited, each vertex's distance from the origin is its value
///i.e. :
//                         4
//                      /      \
//                    2          1
//                /                           3
//            0
//running the the BFS from 5 will give the following vector: <2,1,2,0,-1>
// 0 means unreachable from this node, -1 is the source, all other numbers are distance from origin
//    */
//Graph g = session.getGraph();
//
//vector<int> visited(g.getSize(),0);
//queue<int> Q;
//visited.at(rootLabel)=-1;
//// visited source
//Q.push(rootLabel);
//visited[rootLabel]=true;
//int distance = 1;
//while (!Q.empty()){
//int curr = Q.front();
//Q.pop();
//vector<int> neighbors = g.neighborsOf(curr);
//for (int i = 0; i < neighbors.size(); ++i) {
//if (visited.at(neighbors.at(i))==0)
//Q.push(neighbors.at(i));
//visited.at(neighbors.at(i))=distance;
//}
//distance++;
//}
//}






void Tree::addChild(const Tree &child) {
    children.push_back(child.clone());
}

Tree *Tree::createTree(const Session &session, int rootLabel) {
    if (session.getTreeType() == Cycle)
    {
        CycleTree* tr = new CycleTree(rootLabel, session.getCycleNum());

    }
    else if (session.getTreeType() == MaxRank)
    {
        MaxRankTree* tr = new MaxRankTree(rootLabel);

    }
    else //ROOT TREE
    {
        MaxRankTree* tr = new MaxRankTree(rootLabel);

    }
}

void Tree::runBFS(Tree &tr, int root, Session& session) {
    vector<bool> visited(session.getGraph().getSize(), false);
    queue<int> queue;
    queue.push(root);
    visited.at(root)= true;

    Tree &curr = tr;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        for (int neighbor : session.getGraph().neighborsOf(node))
        {
            if (!visited.at(neighbor)) {
                curr.addChild(*createTree(session, neighbor));
            }
        }

    }


}



//==========CycleTree constructors=========



    CycleTree::CycleTree(int rootLabel, int currCycle): Tree(rootLabel), currCycle(currCycle) {

    }

    CycleTree::~CycleTree()    {}

CycleTree::CycleTree(const CycleTree &other):Tree(other) { //copy constructor //TODO: make it work, how to deep copy?

}

CycleTree *CycleTree::clone() const {
    return new CycleTree(*this);
}

int CycleTree::traceTree() {
    return 0;
}



