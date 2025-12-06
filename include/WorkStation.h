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
    [[maybe_unused]]virtual void processAction(ActionType action,
                               Ingredient* ingredient,
                               Order& order,
                               Player& player) = 0;

    [[maybe_unused]]void print(std::ostream& os) const; //NVI
    [[maybe_unused]]virtual std::unique_ptr<WorkStation> clone() const = 0;
protected:
    [[maybe_unused]]virtual void printImpl(std::ostream& os) const = 0;
};
#endif //OOP_WORKSTATION_H