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
    virtual ~Tree();

    static Tree* createTree(const Session& session, int rootLabel); //creating runs BFS
    virtual int traceTree()=0;

protected:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    ~CycleTree();
    virtual int traceTree();//returns next node to act on
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    ~MaxRankTree();
    virtual int traceTree();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel1, int rootLabel);
    ~RootTree();
    virtual int traceTree();
};

#endif //SPL_ASSIGNMENT1_TREE_H