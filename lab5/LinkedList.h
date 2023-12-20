#include <iostream>
#include <memory>

template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <class T, class Allocator = std::allocator<T>>
class LinkedList {
private:
    using NodeAllocator = typename Allocator::template rebind<Node<T>>::other;

public:
    class Iterator {
    public:
        Iterator(Node<T>* node) : current(node) {}

        // Конструктор для константного итератора
        Iterator(const Node<T>* node) : current(const_cast<Node<T>*>(node)) {}

        T& operator*() {
            return current->data;
        }

        // Оператор разыменования для константного итератора
        const T& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        Node<T>* current;
    };

    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void push_back(const T& value) {
        Node<T>* newNode = allocateNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        if (!tail) {
            return; // List is empty
        }

        Node<T>* prevNode = tail->prev;
        deallocateNode(tail);
        tail = prevNode;

        if (!tail) {
            head = nullptr; // The list is now empty
        } else {
            tail->next = nullptr;
        }
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end()  {
        return Iterator(static_cast<Node<T>*>(nullptr));
    }

    // Метод для получения константного итератора на начало списка
    Iterator begin() const {
        return Iterator(head);
    }

    // Метод для получения константного итератора на конец списка
    Iterator end() const {
        return Iterator(static_cast<const Node<T>*>(nullptr));
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            deallocateNode(current);
            current = nextNode;
        }

        head = tail = nullptr;
    }

private:
    NodeAllocator nodeAllocator;

    Node<T>* head;
    Node<T>* tail;

    Node<T>* allocateNode(const T& value) {
        Node<T>* newNode = nodeAllocator.allocate(1);
        nodeAllocator.construct(newNode, value);
        return newNode;
    }

    void deallocateNode(Node<T>* node) {
        nodeAllocator.destroy(node);
        nodeAllocator.deallocate(node, 1);
    }
};

// Пример использования

// int main() {
//     // Используем аллокатор из стандартной библиотеки
//     LinkedList<int> myList;

//     myList.push_back(1);
//     myList.push_back(2);
//     myList.push_back(3);

//     // Итерируемся по списку
//     for (auto it = myList.begin(); it != myList.end(); ++it) {
//         std::cout << *it <<std::endl;
//     }
    
//     return 0;
// }
