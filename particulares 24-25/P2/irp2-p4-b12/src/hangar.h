#ifndef HANGAR_H
#define HANGAR_H

#include "container.h"
#include "ship.h"
#include <string>
#include <sstream>

// template <typename T>
// class SigoGenerica: public Cottainer<T>{

namespace P4 {

  class Hangar : public Container<ShipPtr> { // T = ShipPtr
    friend std::ostream &operator<<(std::ostream &os, const Hangar &h);
      public:
          Hangar(const std::string& name);
          virtual ~Hangar() = default;

	  // redefinicion
          void remove(size_t index);
  };

} // namespace P4

#endif /* HANGAR_H */

