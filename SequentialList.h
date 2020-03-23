#include <functional>
#include <iostream>
#include "List.h"

template <typename T>
class SequentialList : public List<T> {
 private:
  int size;
  int capacity;
  T* data;

 public:
  SequentialList() : size(0), capacity(1024), data(new T[1024]) {}

  virtual ~SequentialList(){};

  bool insert(T value) {
    if (size >= capacity) return false;
    data[size] = value;
    size++;
    return true;
  }

  void traversal(std::function<void(T)> visit) const {
    for (T index = 0; index != size; index++) {
      visit(data[index]);
    }
  }

  bool isEmpty() { return size == 0; }

  T get(int index) {
    if (index >= size || index < 0) exit(1);
    return data[index];
  }

  bool set(int index, T _data) {
    if (index >= size || index < 0) exit(1);
    data[index] = _data;
    return true;
  }

  void insert(int index, T _data) {
    if (size >= capacity || index > size || index < 0) exit(1);
    for (int i = size; size != index; size--) {
      data[i] = data[i - 1];
    }
    data[index] = _data;
    size++;
  }

  T remove(int index) {
    if (index >= size || index < 0) exit(1);
    T value = data[index];
    for (int i = index; size != index; index++) {
      data[i] = data[i + 1];
    }
    size--;
    return value;
  }

  int removeAll(T _data) {
    int count = 0;
    for (int index = 0; index != size; index++)
      if (data[index] == _data) {
        remove(index);
        count++;
      }
    return count;
  }

  int contains(T _data) {
    int count = 0;
    for (int index = 0; index != size; index++)
      if (data[index] == _data) count++;
    return count;
  }

  int getSize() { return size; }

  class Iterator {
   private:
    int pointer;
    T* data;

   public:
    explicit Iterator(int _pointer, T* _data)
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
