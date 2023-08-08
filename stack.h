#include <vector>

#ifndef __STACK_H__
#define __STACK_H__

template <typename type> class Stack {
    private:
        std::vector<type> items;
    public:
        Stack() {};
        Stack(const Stack &other) { this->items = other.items; };

        int size() { return items.size(); };
        bool empty() { return !items.size(); };
        void push(type element) { items.push_back(element); };
        type pop() { int val = items.back(); items.pop_back(); return val; };
        type peek() { return items.back(); };
};

#endif
