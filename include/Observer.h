#ifndef OOP_OBSERVER_H
#define OOP_OBSERVER_H

#include <algorithm>
#include <vector>

class Order;

class Observer {
public:
  virtual ~Observer() = default;
  virtual void update(Order *order) = 0;
};

class Subject {
private:
  std::vector<Observer *> observers;

public:
  Subject() = default;
  virtual ~Subject() = default;

  Subject(const Subject &other) { (void)other; }
  Subject &operator=(const Subject &other) {
    (void)other;
    return *this;
  }

  void addObserver(Observer *observer) { observers.push_back(observer); }

  void removeObserver(Observer *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());
  }

  void notifyObservers(Order *order) {
    for (Observer *observer : observers) {
      if (observer) {
        observer->update(order);
      }
    }
  }
};

#endif // OOP_OBSERVER_H