//
// Created by galyo on 03/11/2020.
//

#ifndef SPL_ASSIGNMENT1_TREE_H
#define SPL_ASSIGNMENT1_TREE_H
#include <iostream>
#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    void addChild(const Tree& child);


    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
private:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
};

#endif //SPL_ASSIGNMENT1_TREE_H
