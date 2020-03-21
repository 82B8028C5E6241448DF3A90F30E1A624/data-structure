#include "SequentialList.h"

int main() {
  bool sign;
  int count = 10;
  SequentialList *list = new SequentialList(count);

  for (int i = 0; i < count; i++) {
    sign = list->insert(i);
  }

  sign = list->insert(count);
  list->traversal();

  return 0;
}
