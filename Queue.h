#include "LinkList.h"

template <typename T>
class Queue : public ::LinkList<T> {
 public:
  Queue(){};
  ~Queue(){};

  void push(T data) { LinkList<T>::insert(data); }

  void pop() { LinkList<T>::remove(0); }

  T back() {
    int size = LinkList<T>::getSize();
    return LinkList<T>::get(size - 1);
  }

  T front() { return LinkList<T>::get(0); }
};
