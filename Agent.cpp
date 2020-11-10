//
// Created by galyo on 03/11/2020.
//

#include "Agent.h"
#include "iostream"
using namespace std;


Agent::Agent() {}

Agent::~Agent() {

}



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

}


ContactTracer *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

void ContactTracer::act(Session &session) {
    int sick = session.dequeueInfected();
    if (sick != -1) //Contact tracer has a node to isolate
    {

       Tree* tr = Tree::createTree(session,sick);
       Tree::runBFS(*tr,session);
       int isolate = tr->traceTree();
       session.getGraph().isolateNode(isolate);
       delete tr;
    }

}

 bool ContactTracer::isVirus() const {
    return VIRUS;

}

int ContactTracer::getNode() const {
    return -1;
}

//============================================================================

//========= RULE OF 5=============

//constructor
Virus::Virus(int _nodeInd):nodeInd(_nodeInd), VIRUS(true), acted(false){
        //IMPLEMENTED!!!
}
//copy constructor
Virus::Virus(const Virus& vir):nodeInd(vir.nodeInd) ,VIRUS(vir.isVirus()), acted(vir.acted){
        //IMPLEMENTED!!!
}
//destructor
Virus::~Virus() {

}


bool Virus::isVirus() const {
    return VIRUS;
}
bool Virus::hasActed() const{
    return acted;
}

void Virus::act(Session &session) {
    vector<int> neighbors = session.getGraph().neighborsOf(nodeInd); //saving neighbors in vector
    if(!this->hasActed()) {  //if this node is not infectedQ yet, infect it
        session.getGraph().getInfQ().push(this->nodeInd);
        this->acted=true;
    }

    sort(neighbors.begin(),neighbors.end()); //sorting neighbors by size
    bool didInfect = false;
    for (int i = 0; i <neighbors.size() && !didInfect ; ++i) { //finding lowest neighbor to infect
        if (!session.getGraph().isInfected(neighbors[i])) {
            Virus vir(neighbors[i]);
            session.addAgent(vir);



            didInfect=true;
        }
    }

    }



Virus *Virus::clone() const {
    return new Virus(*this);
}

int Virus::getNode() const {
    return nodeInd;
}




