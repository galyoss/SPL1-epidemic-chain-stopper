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
    static void runBFS(Tree &tr, int root, Session& session);
    static Tree* createTree(const Session& session, int rootLabel); //creating runs BFS
    virtual int traceTree()=0;

protected:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
    using Tree::Tree;
public:
    CycleTree(int rootLabel, int currCycle);
    CycleTree(const CycleTree& other);
    ~CycleTree();
    CycleTree* clone() const;
    virtual int traceTree();//returns next node to act on
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    MaxRankTree(const MaxRankTree& other);
    MaxRankTree* clone() const;
    ~MaxRankTree();
    virtual int traceTree();
};

class RootTree: public Tree{
    using Tree::Tree;
public:
    RootTree(int rootLabel);
    RootTree(const RootTree& other);
    RootTree* clone () const;
    ~RootTree();
    virtual int traceTree();
};

#endif //SPL_ASSIGNMENT1_TREE_H