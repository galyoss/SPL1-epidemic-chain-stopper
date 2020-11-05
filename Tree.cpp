//
// Created by galyo on 03/11/2020.
//

#include "Tree.h"
#include <vector>
#include <queue>
#include "Session.h"
using namespace std;

//=========Root tree constructors=========

//
RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}



Tree *Tree::createTree(const Session &session, int rootLabel) {
    Graph g = session.getGraph();

    vector<bool> visited(g.getSize(),false);
    queue<int> Q;

    // visited source
    Q.push(rootLabel);
    visited[rootLabel]=true;

    while (!Q.empty()){
        int curr = Q.pop();
    }





}

Tree::Tree(int rootLabel):node(0), children() {
    std::cout << "built tree" << std::endl;
}

//TreeType treeType1 = session.getTreeType();
//if (treeType1==Cycle)
//CycleTree* root =new CycleTree(rootLabel,session.getCycleNum());
//else if(treeType1=Root)
//RootTree* root = new RootTree(rootLabel);
//else
//MaxRankTree* root = new MaxRankTree(rootLabel);

int CycleTree::traceTree() {
    return 0;
}

