#include "../include/WorkStation.h"

void WorkStation::print(std::ostream &os) const { // interfață NON-virtuală
  // aici ai comportament comun
  os << "WorkStation: ";
  printImpl(os); // se apelează VIRTUAL
}
WorkStation::WorkStation(const std::string &nume) : name(nume) {}