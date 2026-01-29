#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H
#include "FoodItem.h"
#include "Observer.h"
#include "Order.h"
#include <string>
#include <vector>

enum class CustomerMood { WAITING, HAPPY, ANGRY };
enum class CustomerType { REGULAR, RUSH_HOUR };

class Customer : public Observer {
private:
  std::string Name;
  Order order;
  CustomerMood mood;
  static Order generateRandomOrder(const std::vector<FoodItem> &menu);
  static std::string generateRandomName();
  std::string textureLocation;

  explicit Customer(const std::vector<FoodItem> &m);
  Customer(const std::string &n, const Order &o);

public:
  static Customer create(CustomerType type, const std::vector<FoodItem> &menu);

  Customer();
  Customer(const Customer &alt);

  void update(Order *order) override;

  friend std::ostream &operator<<(std::ostream &os, const Customer &c);
  Customer &operator=(const Customer &other);
  const std::string &getName() const { return Name; }
  Order &getOrder() { return order; }

  ~Customer();
};
#endif