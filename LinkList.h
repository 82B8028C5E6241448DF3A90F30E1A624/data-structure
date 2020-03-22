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
};
