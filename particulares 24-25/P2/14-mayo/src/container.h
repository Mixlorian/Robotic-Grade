#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <boost/signals2.hpp>
#include <string>
#include <iostream>
#include <cstdint>


using namechange_sig_t = boost::signals2::signal<void (const std::string&, const std::string&)>;

namespace P4 {

  template <typename T>
  class Container {

    // a las funciones amigas no les sirve el typename de la clase
    // porque no son miembros de la clase ;)
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Container<U> &c);
    
  public:
    Container(const std::string& name="Container");
    virtual ~Container() = default;

    void set_name(const std::string& name);
    const std::string& get_name() const;
    void add(const T& item);
    void remove(const T& item);
    uint16_t find(const T& item) const;

    T& operator[](size_t i);
    size_t size() const;

  protected:  // es para que las derivadas puedan acceder
  		// directamente, para el resto de clase seguira siendo
  		// privado
    std::string cname;
    std::vector<T> items;
  };

} // namespace P4
#include "container.tcc" // eto hay que hacerlo para las plantillicah

#endif /* CONTAINER_H */




