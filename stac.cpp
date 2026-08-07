#include <iostream>
#include <string>
#include <array>
#include <vector>

template <typename T> // vuelve la clase un template
class Stack
{
public:
    std::vector<T> data; // vector de tipo template

    // ver el primer elemento del stack
    void peek()
    {
        if (data.empty())
        {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "top element: " << data.back() << "\n";
    }

    // agregar un nuevo elemento
    void push(const T &element)
    {
        data.push_back(element);
    }

    // retirar/eliminar un elemento del stack
    void pop()
    {
        if (data.empty())
        {
            std::cout << "Stack is empty.\n";
            return;
        }
        data.pop_back();
    }

    // confirmar si es stack esta vacio
    bool isEmpty()
    {
        return data.empty();
    }

    // retorna tamaño del stack
    int size()
    {
        return data.size();
    }

    // limpia/ elimina todos los elementos del stack
    void clear()
    {
        data.clear();
    }
};

int main()
{
    // Create a Stack that holds integers
    Stack<int> intStack;
    intStack.push(10);
    intStack.peek();
    intStack.push(20);
    intStack.peek(); // Output: top element: 20
    std::cout << "Size: " << intStack.size() << "\n";

    // while (stop != true)
    // {
    //     std::cout << "Press E";
    // }

    std::cout << "\nPress Enter to continue...";
    std::cin.get();

    return 0;
}