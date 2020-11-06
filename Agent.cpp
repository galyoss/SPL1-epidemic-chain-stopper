//
// Created by galyo on 03/11/2020.
//

#include "Agent.h"
#include "iostream"


Agent::Agent() {}






//============RULE OF 5============

//Empty constructor
ContactTracer::ContactTracer():isVirus(false) {
        //IMPLEMENTED
}

//COPY constructor
ContactTracer::ContactTracer(const ContactTracer &other):isVirus(other.isVirus) {
    //IMPLEMENTED
}


//Destruct
ContactTracer::~ContactTracer() {}


ContactTracer *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

void ContactTracer::act(Session &session) {} //TBD

bool ContactTracer::isVirus() {
    return isVirus;
}

//============================================================================

//========= RULE OF 5=============

//constructor
Virus::Virus(int _nodeInd):nodeInd(_nodeInd), isVirus(true){
        //IMPLEMENTED!!!
}
//copy constructor
Virus::Virus(const Virus& vir):nodeInd(vir.nodeInd) ,isVirus(vir.isVirus){
        //IMPLEMENTED!!!
}
//destructor
Virus::~Virus() {
    delete &nodeInd;
    delete &isVirus;
}


bool Virus::isVirus() {
    return isVirus;
}

void Virus::act(Session &session) {
    vector<int> neighbors = session.getGraph().neighborsOf(nodeInd); //saving neighbors in vector
    if(!session.getGraph().isInfected(nodeInd))     //if this node is not infected yet, infect it
          session.getGraph().infectNode(nodeInd);

    if (!session.getGraph().isDead(nodeInd)) //it is\was in infected Q, just need to kill it
        session.getGraph().moveToDead(nodeInd);

    sort(neighbors.begin(),neighbors.end()); //sorting neighbors by size
    bool didInfect = false;
    for (int i = 0; i <neighbors.size() ; ++i) { //finding lowest neighbor to infect
        if (!session.getGraph().isInfected(neighbors[i])) {
//            Virus vir(i);//TODO
            session.addAgent(vir);
            session.increaseViruses();
            didInfect=true;
            break;
        }
    }
    if (isDead(nodeInd)&&!didInfect) //we didnt infect anyone, and we are red already
        session.

    }



Virus *Virus::clone() const {
    return new Virus(*this);
}

int Virus::getNode() {
    return nodeInd;
}




