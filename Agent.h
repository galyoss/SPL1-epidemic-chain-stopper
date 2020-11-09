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
    virtual ~Agent();
    virtual Agent* clone() const =0;
    virtual void act(Session& session)=0;
    virtual int getNode() const =0;
    virtual bool isVirus() const =0;
private:



};

class ContactTracer: public Agent{
public:
    ContactTracer();
    virtual ~ContactTracer();
    ContactTracer(const ContactTracer& other);
    ContactTracer* clone() const;
    bool isVirus() const;
    virtual int getNode() const;
    void act(Session& session);
private:
    bool VIRUS;

};


class Virus: public Agent{
public:
    Virus(int _nodeInd);
    Virus(const Virus& vir);
    virtual ~Virus();
    Virus* clone() const;
    virtual int getNode() const ;
    bool isVirus() const;
    void act(Session& session);
private:
    const int nodeInd;
    bool VIRUS;

};

#endif //SPL_ASSIGNMENT1_AGENT_H
