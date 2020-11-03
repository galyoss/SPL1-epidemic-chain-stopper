//
// Created by galyo on 03/11/2020.
//

#ifndef SPL_ASSIGNMENT1_AGENT_H
#define SPL_ASSIGNMENT1_AGENT_H

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& session);

    virtual void act()=0;
private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, Session& session);

    virtual void act();
private:
    const int nodeInd;
};

#endif //SPL_ASSIGNMENT1_AGENT_H
