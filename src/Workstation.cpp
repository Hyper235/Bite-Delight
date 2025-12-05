//
// Created by Catalin on 12/3/2025.
//
#include "../include/WorkStation.h"

void WorkStation::print(std::ostream& os) const {  // interfață NON-virtuală
    // aici ai comportament comun
    os << "WorkStation: ";
    printImpl(os);                   // se apelează VIRTUAL
}
WorkStation::WorkStation(const std::string& nume): name(nume){}