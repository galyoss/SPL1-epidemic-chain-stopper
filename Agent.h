//
// Created by galyo on 03/11/2020.
//

#ifndef SPL_ASSIGNMENT1_AGENT_H
#define SPL_ASSIGNMENT1_AGENT_H

#include <vector>
#include "Session.h"
#include <algorithm>


class Agent{
public:
    Agent();
    virtual ~Agent()=0;
    virtual Agent* clone() const;
    virtual void act(Session& session)=0;
    virtual bool isVirus()=0;
private:
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    ~ContactTracer();
    ContactTracer(const ContactTracer& other);
    ContactTracer* clone() const;
    bool isVirus();
    void act(Session& session);
private:
   const bool isVirus;
};


class Virus: public Agent{
public:
    Virus(int _nodeInd);
    Virus(const Virus& vir);
    ~Virus();
    Virus* clone() const;
    int getNode();
    bool isVirus();
    bool isDead(int nodeInd);
    void act(Session& session);
private:
    const int nodeInd;
    const bool isVirus;
};

#endif //SPL_ASSIGNMENT1_AGENT_H
