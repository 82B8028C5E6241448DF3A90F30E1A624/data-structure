#include <functional>
#include <iostream>
#include "List.h"

template <class T>
class SequentialList : public List<T> {
 private:
  unsigned int size;
  unsigned int capacity;
  T* data;

 public:
  SequentialList() : size(0), capacity(8), data(new T[8]) {}

  virtual ~SequentialList(){};

  bool insert(T value) {
    if (size == capacity) return false;
    data[size] = value;
    size++;
    return true;
  }

  void traversal(std::function<void(T)> visit) const {
    for (T index = 0; index != size; index++) {
      visit(data[index]);
    }
  }

  class Iterator {
   private:
    unsigned int pointer;
    T* data;

   public:
    explicit Iterator(unsigned int _pointer, T* _data)
        : pointer(_pointer), data(_data) {}

    bool operator!=(Iterator other) const {
      return !(pointer == other.pointer);
    }

    bool operator==(Iterator other) const { return pointer == other.pointer; }

    Iterator& operator++() {
      pointer++;
      return *this;
    }

    Iterator operator++(int) {
      Iterator retval = *this;
      ++(*this);
      return retval;
    }

    T operator*() const { return data[pointer]; }
  };

  Iterator begin() const { return Iterator(0, data); }
  Iterator end() const { return Iterator(size, data); }
};
