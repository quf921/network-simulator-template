#ifndef IP_H
#define IP_H

#include <string>

#include "object.h"

// 주소를 나타내는 클래스
class Address : public Object {
private:
  std::string address_;

  virtual std::string name() override { return "Address"; }

public:
  Address(std::string address) : address_(address) {}
  std::string toString() const { return address_; }
  bool operator==(const Address &rhs) const { return address_ == rhs.address_; }
};

#endif