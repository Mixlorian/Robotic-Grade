// -*- mode: c++ -*-

#ifndef NODE_H
#define NODE_H

namespace C3 {

  template<typename T> class Node; // Declaracion adelantada
  template<typename T> using NodePtr = Node<T>*;  // typedef con genericidad

  template<typename T>
  class Node
  {
  public:
    Node(const T& k);
    ~Node();

    T& get_key();
    const T& get_key() const;
    NodePtr<T> get_next() const;
    void set_next(NodePtr<T> n);
    NodePtr<T> get_prev() const;
    void set_prev(NodePtr<T> n);

    bool has_next() const;
    bool has_prev() const;

  private:
    T key;
    NodePtr<T> next;
    NodePtr<T> prev;
  };

}  // C3

#endif /* NODE_H */
