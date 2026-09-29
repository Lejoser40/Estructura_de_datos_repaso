#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>

template <typename T>
class Queue
{
private:
    std::deque<T> data;

public:
    void enqueue(const T &element)
    {
        data.push_back(element); // push o guardar element al final de la fila
    }

    void dequeue()
    {
        if (data.empty())
        {
            std::cout << "Queue is empty\n";
            return;
        }
        data.pop_front(); // Pop elemento que esta al frente de la fila
    }

    int size()
    {
        return data.size();
    }

    T &front()
    {
        if (data.empty())
        {
            throw std::runtime_error(" Queue is empty ");
        }
        return data.front();
    }

    bool isEmpty()
    {
        return data.empty();
    }
};

int main()
{
    Queue<int> cola;

    std::cout << "\n-----------Probando Cola------------\n";

    // cola.enqueue(1);
    // cola.enqueue(2);
    // cola.enqueue(3);

    std::cout << "\n-----------Agregar elementos------------\n";
    for (int x = 0; x < 11; x++)
    {
        std::cout << x << " ";
        cola.enqueue(x);
    }

    std::cout << "\n-----------Comprobando elementos------------\n";
    std::cout << "primer elemento " << cola.front() << " \n";
    std::cout << "Tamano " << cola.size() << " \n";
    std::cout << "Esta vacia " << cola.isEmpty() << " \n";

    std::cout << "\n------Eliminando Elementos------" << "\n";
    while (!cola.isEmpty())
    {
        std::cout << cola.front() << " ";
        cola.dequeue();
    }

    std::cout << "\n-----------Comprobando elementos------------\n";

    try
    {
        std::cout << "primer elemento " << cola.front() << " \n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << e.what() << '\n';
    }

    std::cout << "Tamano " << cola.size() << " \n";
    std::cout << "Esta vacia " << cola.isEmpty() << " \n";

    return 0;
}