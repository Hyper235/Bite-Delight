#ifndef OOP_WORKSTATION_H
#define OOP_WORKSTATION_H
#include "Order.h"
#include "Player.h"
#include "ActionType.h"
#include "Ingredient.h"
#include <memory>
class WorkStation {
protected:
    std::string name;
public:
    explicit WorkStation(const std::string& name);
    virtual ~WorkStation() = default;
    // virtual pur
    virtual void processAction(ActionType action,
                               Ingredient* ingredient,
                               Order& order,
                               Player& player) = 0;

    void print(std::ostream& os) const; //NVI
    virtual std::unique_ptr<WorkStation> clone() const = 0;
protected:
    virtual void printImpl(std::ostream& os) const = 0;
};
#endif //OOP_WORKSTATION_H