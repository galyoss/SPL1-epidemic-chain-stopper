//
// Created by galyo on 03/11/2020.
//

#include "Agent.h"
#include "iostream"


Agent::Agent() {}





//============RULE OF 5============

//Empty constructor
ContactTracer::ContactTracer() {
        //IMPLEMENTED
}

//COPY constructor
ContactTracer::ContactTracer(const ContactTracer &other) {
    //IMPLEMENTED
}


//Destruct
ContactTracer::~ContactTracer() {}


ContactTracer *ContactTracer::clone() const {
    return new ContactTracer(*this);
}

//void ContactTracer::act(Session &session) {} //TBD

//============================================================================

//========= RULE OF 5=============

//constructor
Virus::Virus(int _nodeInd):nodeInd(_nodeInd) {
        //IMPLEMENTED!!!
}
//copy constructor
Virus::Virus(const Virus& vir):nodeInd(vir.nodeInd) {
        //IMPLEMENTED!!!
}
//destructor
Virus::~Virus() {
    delete &nodeInd;
}

//void Virus::act(Session &session) {} TBD!!!

Virus *Virus::clone() const {
    return new Virus(*this);
}



