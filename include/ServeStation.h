//
// Created by Catalin on 12/3/2025.
//

#ifndef OOP_SERVESTATION_H
#define OOP_SERVESTATION_H
#include <memory>
#include "Order.h"
#include "Player.h"
#include "WorkStation.h"
#include "ActionType.h"
#include "Ingredient.h"

class ServeStation: public WorkStation {
public:
    ServeStation();
    void processAction(ActionType action,
                           Ingredient* ingredient,
                           Order& order,
                           Player& player) override;
    [[nodiscard]]std::unique_ptr<WorkStation> clone() const override;
protected:
    void printImpl(std::ostream& os) const override;
};
#endif //OOP_SERVESTATION_H