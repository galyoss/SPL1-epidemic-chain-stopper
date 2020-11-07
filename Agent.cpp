//
// Created by galyo on 03/11/2020.
//

#include "Agent.h"
#include "iostream"


Agent::Agent() {}



//============RULE OF 5============

//Empty constructor
ContactTracer::ContactTracer():VIRUS(false) {
        //IMPLEMENTED
}

//COPY constructor
ContactTracer::ContactTracer(const ContactTracer &other):VIRUS(other.isVirus()) {
    //IMPLEMENTED
}


//Destruct
ContactTracer::~ContactTracer() {
    delete &VIRUS;
}


ContactTracer *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

void ContactTracer::act(Session &session) {

}

 bool ContactTracer::isVirus() const {
    return VIRUS;

}

//============================================================================

//========= RULE OF 5=============

//constructor
Virus::Virus(int _nodeInd):nodeInd(_nodeInd), VIRUS(true){
        //IMPLEMENTED!!!
}
//copy constructor
Virus::Virus(const Virus& vir):nodeInd(vir.nodeInd) ,VIRUS(vir.isVirus()){
        //IMPLEMENTED!!!
}
//destructor
Virus::~Virus() {
    delete &nodeInd;
    delete &VIRUS;
}


bool Virus::isVirus() const {
    return VIRUS;
}

void Virus::act(Session &session) {
    vector<int> neighbors = session.getGraph().neighborsOf(nodeInd); //saving neighbors in vector
    if(!session.getGraph().isInfected(nodeInd))     //if this node is not infectedQ yet, infect it
          session.getGraph().infectNode(nodeInd);


    sort(neighbors.begin(),neighbors.end()); //sorting neighbors by size
    bool didInfect = false;
    for (int i = 0; i <neighbors.size() ; ++i) { //finding lowest neighbor to infect
        if (!session.getGraph().isInfected(neighbors[i])) {
            Virus vir(i);
            session.addAgent(vir);
            session.increaseViruses();
            didInfect=true;
            break;
        }
    }
    if (!didInfect) //we didnt infect anyone, and we are red already
        session.deactivateVirus(nodeInd);

    }



Virus *Virus::clone() const {
    return new Virus(*this);
}

int Virus::getNode() {
    return nodeInd;
}




