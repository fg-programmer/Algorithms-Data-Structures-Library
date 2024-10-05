#include <string>
#include <cctype> 
#include "Stack.h"
#include "Queue.h"


bool isPalindrome(const std::string& str) {
    Stack stack;
    Queue queue;
    
    // Push and enqueue each character (ignoring spaces and case)
    for (char ch : str) {
        if (isalpha(ch)) { // Only consider alphabetic characters
            char lowerCh = static_cast<char>(tolower(ch));  // Ensure we convert to char
            stack.push(lowerCh);
            queue.enqueue(lowerCh);
        }
    }
    
    // Compare characters by popping from stack and dequeuing from queue
    while (!stack.isEmpty() && !queue.isEmpty()) {
        if (stack.pop() != queue.dequeue()) {
            return false;
        }
    }
    return true;
}
 