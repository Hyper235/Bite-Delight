#ifndef OOP_PRICINGSTRATEGY_H
#define OOP_PRICINGSTRATEGY_H

class PricingStrategy {
public:
  virtual ~PricingStrategy() = default;
  virtual float calculate(float basePrice) const = 0;
};

class EasyPricingStrategy : public PricingStrategy {
public:
  float calculate(float basePrice) const override {
    return basePrice;
  }
};

class MediumPricingStrategy : public PricingStrategy {
public:
  float calculate(float basePrice) const override { return basePrice * 1.3f; }
};

class HardPricingStrategy : public PricingStrategy {
public:
  float calculate(float basePrice) const override { return basePrice * 1.5f; }
};

#endif // OOP_PRICINGSTRATEGY_H
