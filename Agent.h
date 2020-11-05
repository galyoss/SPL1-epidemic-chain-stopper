//
// Created by galyo on 03/11/2020.
//

#ifndef SPL_ASSIGNMENT1_AGENT_H
#define SPL_ASSIGNMENT1_AGENT_H

#include <vector>
#include "Session.h"



class Agent{
public:
    Agent();
    virtual ~Agent()=0;
    virtual Agent* clone() const;
    virtual void act(Session& session)=0;
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    ~ContactTracer();
    ContactTracer(const ContactTracer& other);
    ContactTracer* clone() const;

    virtual void act(Session& session);
};


class Virus: public Agent{
public:
    Virus(int _nodeInd);
    Virus(const Virus& vir);
    ~Virus();
    Virus* clone() const;

    virtual void act(Session& session);
private:
    const int nodeInd;
};

#endif //SPL_ASSIGNMENT1_AGENT_H
