#include <functional>
#include <iostream>

template <typename T>
class LinkList {
 private:
  class ListNode {
   public:
    T data;
    ListNode *next;
  };

  ListNode *head;
  ListNode *tail;
  int size;

 public:
  LinkList() : head(nullptr), tail(nullptr), size(0) {}

  ~LinkList() {}

  void insert(T _data) {
    ListNode *node = new ListNode();
    if (size == 0) tail = node;
    node->data = _data;
    node->next = head;
    head = node;
    size++;
  }

  void traversal(std::function<void(T)> visit) {
    for (ListNode *node = head; node != nullptr; node = node->next) {
      visit(node->data);
    }
  }

  class iterator {
    ListNode *node;

   public:
    explicit iterator(ListNode *node) : node(node) {}
    iterator &operator++() {
      node = node->next;
      return *this;
    }

    iterator operator++(int) {
      iterator retval = *this;
      ++(*this);
      return retval;
    }

    bool operator==(iterator other) const { return node == other.node; }
    bool operator!=(iterator other) const { return !(*this == other); }
    T operator*() const { return node->data; }
  };

  iterator begin() const { return iterator(head); }
  iterator end() const { return iterator(nullptr); }

  bool isEmpty() { return size == 0; }

  T get(int index) {
    if (index >= size || index < 0) exit(1);

    ListNode *node = head;
    for (int i = 1; i <= index; i++) {
      node = node->next;
    }
    return node->data;
  }

  bool set(int index, T _data) {
    if (index >= size || index < 0) return false;
    ListNode *node = head;
    for (int i = 1; i <= index; i++) {
      node = node->next;
    }
    node->data = _data;
    return true;
  }

  void insert(int index, T _data) {
    if (index > size || index < 0) exit(0);

    ListNode *temp = head;
    ListNode *prev = nullptr;
    ListNode *node = new ListNode();
    node->data = _data;

    if (index == size) {
      temp = nullptr;
      prev = tail;
      tail = node;
    } else {
      int n = 0;
      while (n < index) {
        prev = temp;
        temp = temp->next;
        n++;
      }
    }

    if (temp == head) {
      node->next = head;
      head = node;
    } else {
      node->next = temp;
      prev->next = node;
    }
    size++;
  }

  T remove(int index) {
    if (index >= size || index < 0) exit(0);

    int n = 0;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (n < index) {
      prev = temp;
      temp = temp->next;
      n++;
    }

    T value = temp->data;

    if (temp == head) {
      head = head->next;
    } else if (temp = tail) {
      prev->next = nullptr;
      tail = prev;
    } else {
      prev->next = temp->next;
    }

    temp->next = nullptr;
    delete (temp);
    size--;
    return value;
  }

  int removeAll(T _data) {
    int count = 0;
    int index = 0;
    ListNode *node = head;
    while (node) {
      ListNode *temp = node;
      node = node->next;
      if (temp->data == _data) {
        remove(index);
        count++;
      } else {
        index++;
      }
    }
    return count;
  }

  int contains(T _data) {
    int count = 0;
    ListNode *node = head;
    for (int index = 0; index < size; index++) {
      if (node->data == _data) count++;
      node = node->next;
    }
    return count;
  }
  
  int getSize() { return size; }
};
