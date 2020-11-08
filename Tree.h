//
// Created by galyo on 03/11/2020.
//

#ifndef SPL_ASSIGNMENT1_TREE_H
#define SPL_ASSIGNMENT1_TREE_H
#include <iostream>
#include <vector>
using namespace std;
class Session;
class Tree{
public:
    Tree(int rootLabel);
    void addChild(const Tree& child);
    ~Tree();
    virtual Tree* clone() const =0;
    static void runBFS(Tree &tr, Session& session);
    static Tree* createTree(const Session& session, int rootLabel); //creating runs BFS
    virtual int traceTree()=0;
    virtual int getNode();

protected:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    CycleTree(const CycleTree& other);
    ~CycleTree();
    CycleTree* clone() const;
    int traceTree();//returns next node to act on
    int getNode();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    MaxRankTree(const MaxRankTree& other);
    MaxRankTree* clone() const;
    int getChildrenNum();
    vector<vector<int>> * scanTree();
    ~MaxRankTree();
    int traceTree();
    int getNode();


};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    RootTree(int rootLabel, const RootTree &other);
    RootTree* clone () const;
    ~RootTree();
    int traceTree();
    int getNode();

};

#endif //SPL_ASSIGNMENT1_TREE_H