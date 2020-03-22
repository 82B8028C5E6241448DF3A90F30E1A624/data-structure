#ifndef __LIST_H__
#define __LIST_H__
#include <functional>

template <typename T>
class List {
 public:
  List(){};
  virtual ~List(){};
  virtual bool insert(T) = 0;
  virtual void traversal(std::function<void(T)> visit) const = 0;
};

#endif
