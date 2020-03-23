#include "SequentialList.h"

template <typename T>
class Stack : public SequentialList<T> {
 public:
  Stack() {}
  ~Stack() {}
  bool push(T value) { return SequentialList<T>::insert(value); }

  void pop() {
    int size = SequentialList<T>::getSize();
    SequentialList<T>::remove(size - 1);
  }

  T top() {
    int size = SequentialList<T>::getSize();
    return SequentialList<T>::get(size - 1);
  }
};
