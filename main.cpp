#include <iostream>
#include <vector>
#include "Session.h"
using  namespace std;
int main() {
    std::cout << "working on dev1" << std::endl;
    Session *sesh = new Session(5);
    sesh->simulate();

    return 0;
}
