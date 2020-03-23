#include <string>
#include "Stack.h"

bool bracket(std::string str) {
  Stack<char> stack;
  bool result = false;

  for (int i = 0; i <= str.length(); i++) {
    char value = str[i];
    if (value == '(' || value == '{' || value == '[')
      stack.push(value);
    else if (value == ')' || value == '}' || value == ']') {
      if (!stack.isEmpty()) {
        if (value == ')' && stack.top() == '(' ||
            value == '}' && stack.top() == '{' ||
            value == ']' && stack.top() == '[') {
          stack.pop();
          continue;
        }
      }
      return result;
    }
  }

  if (stack.isEmpty()) result = true;

  return result;
}
