// -*- mode: c++ -*-

#ifndef LIST_H
#define LIST_H

#include <bits/stdint-uintn.h>
#include <cstdint>
#include "node.h"
#include <iostream>
using namespace std;

namespace C3 {
  template<typename T> using fn_t = void (*)(NodePtr<T>);

  template<typename T> class List; // Declaracion adelantada

  template<typename T>
  class List
  {
  
  template <typename U>
  friend ostream &operator<<(ostream &os, const List<U> &lista);
 
  public:
    List();
    ~List();

    uint32_t length() const;
    bool insert_at(uint32_t p, const T& k);
    bool insert_front(const T& k);
    bool insert_back(const T& k);
    void for_each(fn_t<T> f);
    void for_each_reverse(fn_t<T> f);

  private:
    NodePtr<T> first;
    NodePtr<T> last;
    uint32_t nNodes;
  };

}  // C3

#endif /* LIST_H */
