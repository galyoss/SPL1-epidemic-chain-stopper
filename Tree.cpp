//
// Created by galyo on 03/11/2020.
//

#include "Tree.h"
#include <vector>
#include "Session.h"
using namespace std;



//=======Tree constructor=======
Tree::Tree(int rootLabel): node(rootLabel){}
//destructor
Tree::~Tree(){
    for (int i = 0; i <children.size() ; ++i)
        delete children[i];

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
    return nullptr;
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
    vector<vector<int>> *treeInfo = this->scanTree(); //scanTree performs new, need to delete end of function

    //find max
    int maxval=-1;
    for (int i=0;i<treeInfo->size();i++){ //finding max num of children
        if ((*treeInfo)[i][1]>maxval)
            maxval=(*treeInfo)[i][1];}
    vector<int> candidates;
    for (int i=0;i<treeInfo->size();i++){ //inserting all nodes with max value
        if ((*treeInfo)[i][1]==maxval)
            candidates.push_back(i);}
    if(candidates.size()==1) //if done, return
        return candidates[0];

    int minDeg= 10000;
    for (int i: candidates) //looking for minimal depth
    {
        if ((*treeInfo)[i][2]<minDeg)
            minDeg=(*treeInfo)[i][2];
    }
    for (int i=0;i<candidates.size();i++) //kicking all nodes deeper than minimal
    {
        if ((*treeInfo)[i][2]>minDeg)
            candidates.erase(candidates.begin()+i);
    }
    if(candidates.size()==1) //if done, return
        return candidates[0];

    int minIndex = 10000;
    for (int i: candidates) //looking for minimal index
    {
        if ((*treeInfo)[i][0] < minIndex)
            minIndex = (*treeInfo)[i][0];
    }
    delete treeInfo;//freeing memory
    return minIndex;
}

vector<vector<int>>* MaxRankTree::scanTree() {
    vector<vector<int>> *output = new vector<vector<int>>; //output must survive the scope, thus new
    vector<MaxRankTree*> queue;
    queue.push_back(this);
    MaxRankTree* flag = new MaxRankTree(-1);
    queue.push_back(flag);
    int depth_counter=0;
    while (!queue.empty()) {
        MaxRankTree *curr = queue.front();
        if (curr->getNode()==-1) { //we got to the flag, thus we need to push it again and increase depth
            queue.push_back(flag);
            depth_counter++;
        }
       else { //creating the info array, and pushing it into the output vector
            int sons = curr->getChildrenNum();
            int index = curr->getNode();
            vector<int> *stats = new vector<int>(3) ; //need a vector which will survive this scope
            stats->push_back(index);
            stats->push_back(sons);
            stats->push_back(depth_counter);
            output->push_back(*stats);
        }
        queue.erase(queue.begin());
    }
    delete flag;
    return output;
}


int MaxRankTree::getChildrenNum() {
    return this->children.size();
}


void Tree::addChild(const Tree& child) {
    Tree* newSon = child.clone(); // cloning the given tree
    children.push_back(newSon); // pushing the clone into the vector
}

Tree *Tree::createTree(const Session &session, int rootLabel) {
    Tree* tr;
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
    return tr;
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
               queue.push_back(son);
               curr->addChild(*son);
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



