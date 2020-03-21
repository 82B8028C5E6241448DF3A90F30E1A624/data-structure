#include <iostream>

class SequentialList {
 private:
  unsigned int size;
  unsigned int capacity;
  int* data;

 public:
  SequentialList(unsigned int);
  ~SequentialList();
  bool insert(int value);
  void traversal() const;
};

SequentialList::SequentialList(unsigned int _capacity)
    : size(0), capacity(_capacity), data(new int[_capacity]) {}

SequentialList::~SequentialList() {}

bool SequentialList::insert(int value) {
  if (size == capacity) return false;
  data[size] = value;
  size++;
  return true;
}

void SequentialList::traversal() const {
  for (int i = 0; i < size; i++) {
    std::cout << data[i] << '\n';
  }
}
