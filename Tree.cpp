//
// Created by galyo on 03/11/2020.
//

#include "Tree.h"
#include <vector>
#include "Session.h"
using namespace std;



//=======Tree constructor=======
Tree::Tree(int rootLabel): node(rootLabel),children(){}
//destructor
Tree::~Tree(){
    for (int i = 0; i <children.size() ; ++i)
        delete children[i];

}
//copy constructor
Tree::Tree(const Tree &other):node(other.node) , children(vector<Tree*>(other.children.size())){

    for (int i=0;i<other.children.size();i++)
    {
        children[i] = other.children[i]->clone();
    }


}
//=========Root tree constructors=========



//destructor
RootTree::~RootTree(){}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {

}

RootTree::RootTree(int rootLabel, const RootTree &other) : Tree(rootLabel) {}

int RootTree::getNode() {
    return Tree::getNode();
}

int RootTree::traceTree() {
    return this->getNode();
}

RootTree *RootTree::clone() const {
    return new RootTree(*this);
}
//TODO: verify make it work

//=========MaxRankTree constructors========
MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}
//destructor
MaxRankTree:: ~MaxRankTree() {}

MaxRankTree::MaxRankTree(const MaxRankTree &other):Tree(other) { //TODO: make it work in office hours

}

 MaxRankTree *MaxRankTree::clone() const {
    return new MaxRankTree(*this);
}

int MaxRankTree::getNode() {
    return Tree::getNode();
}

int MaxRankTree::traceTree() {
    vector<MaxRankTree*> queue;
    queue.push_back(this);

    int maxNode = -1;
    int maxValue = -1;

    while (!queue.empty())
    {
        MaxRankTree* curr = queue.front();
        queue.erase(queue.begin());
        if (curr->getChildrenNum()>maxValue) {
            maxNode=curr->getNode();
            maxValue=curr->getChildrenNum();
        }
        for (Tree* son : curr->children)
            queue.push_back((MaxRankTree*)son);

    } //while
    return maxNode;
}



int MaxRankTree::getChildrenNum() {
    return this->children.size();
}


void Tree::addChild(const Tree& child) {
    Tree* newSon = child.clone(); // cloning the given tree
    children.push_back(newSon); // pushing the clone into the vector
}

Tree *Tree::createTree(const Session &session, int rootLabel) {
    if (session.getTreeType() == Cycle)
    {
        return new CycleTree(rootLabel, session.getCycleNum());

    }
    else if (session.getTreeType() == MaxRank)
    {
        return new MaxRankTree(rootLabel);

    }
    else //ROOT TREE
    {
        return new MaxRankTree(rootLabel);

    }

}

void Tree::runBFS(Tree &tr, Session& session) {
    vector<bool> visited(session.getGraph().getSize(), false);
    vector<Tree*> queue;
    queue.push_back(&tr);
    visited.at(tr.getNode())= true;


    while (!queue.empty())
    {
        Tree* curr = queue.front();
        queue.erase(queue.begin());
        for (int neighbor : session.getGraph().neighborsOf(curr->getNode()))
        {
            if (!visited.at(neighbor)) {
               Tree* son= createTree(session, neighbor);

               curr->addChild(*son);
                queue.push_back(curr->children.back());
               visited[neighbor]= true;

            }
        }

    }

return;
}

int Tree::getNode() {
    return node;
}






//==========CycleTree constructors=========



    CycleTree::CycleTree(int rootLabel, int currCycle): Tree(rootLabel), currCycle(currCycle) {

    }

    CycleTree::~CycleTree()    {

}

CycleTree::CycleTree(const CycleTree &other):Tree(other) { //copy constructor //TODO: make it work, how to deep copy?

}

CycleTree *CycleTree::clone() const {
    return new CycleTree(*this);
}

int CycleTree::getNode() {
    return Tree::getNode();
}

int CycleTree::traceTree() {
    int cycle = this->currCycle;
    CycleTree* curr = this;
    while(cycle>0&&curr->children.size()!=0){
        curr = (CycleTree*)curr->children.at(0);
        cycle--;
    }
   return curr->getNode();
}



