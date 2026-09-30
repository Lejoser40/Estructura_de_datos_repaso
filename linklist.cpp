#include <iostream>

struct Node
{
    int data;
    Node *next; // Puntero: variable que guarda una direccion de memoria

    Node(int value) // constructor
    {
        data = value;
        next = nullptr; // iniciar puntero no apunte a nada
    }
};

class LinkedList
{
private:
    Node *head; // head/cabeza de tipo Node

public:
    LinkedList()
    {
        head = nullptr; // inicializar head en null;
    }

    void push_front(int value) // insertar al inicio
    {
        Node *newNode = new Node(value); // crear nuevo nodo

        newNode->next = head; // nuevo nodo apunta a primer nodo(nodo head)

        head = newNode; // nuevo nodo es el nodo head
    }

    void push_back(int value) // Insertar al final
    {
        Node *newNode = new Node(value);

        if (head == nullptr) // Si la lista esta vacia, nuevo nodo es la cabeza
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
    }

    void pop_front() // Eliminar del incio
    {
        if (head == nullptr)
        {
            std::cout << "Lista vacia\n";
            return;
        }

        Node *temp = head; // guardar de forma temporal la cabeza/head

        head = head->next; // mover la cabeza/head al siguiente nodo

        delete temp; // eliminar la cabeza/head
    }

    void print() // mostrar lista
    {
        Node *current = head;
        while (current != nullptr)
        {
            // std::cout << "------\n"
            //           << "|" << current->data << "|\n"
            //           << "|---------|\n"
            //           << "|" << current->next << "|\n"
            //           << "------\n";

            std::cout << current->data << " → ";

            current = current->next;
        }

        std::cout << "null\n";
    }

    ~LinkedList() // Destrucutor: libera toda la memoria y destruye la lista
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pop_back() // Eliminar ultimo nodo
    {
        // Si no hay nodos
        if (head == nullptr)
        {
            std::cout << "Lista vacia";
            return;
        }

        // Si solo hay 1 nodo
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        // General : Cuando hay mas de 2 nodos
        Node *temp = head;
        Node *newTail;
        while (temp->next != nullptr) // bucle para encontrar ultimo nodo o nodo cola
        {
            newTail = temp;    // guardar nodo anterior al ultimo nodo o anterior al nodo cola
            temp = temp->next; // mover temp al siguiente nodo
        }
        newTail->next = nullptr; // resetear puntero del nuevo nodo cola
        delete temp;             // eliminar la antigua cola
    }

    int size() // Contar cuantos nodo hay
    {
        if (head == nullptr)
        {
            std::cout << "Size: Lista vacia \n";
            return 0;
        }

        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void search(int value) // Buscar un valor en los nodos
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                std::cout << "Nodo encontrado: " << temp->data << "\n ";
                return;
            }
            temp = temp->next;
        }
        std::cout << "No se encontro un Nodo \n";
    }

    void remove(int value)
    {
        // Caso 1 lista vacia
        if (head == nullptr) // Si la lista esta vacia
        {
            std::cout << "Lista vacia";
            return;
        }
        // Caso 2 El nodo a eliminar es el primero
        if (head->data == value)
        {
            Node *temp = head;
            head = temp->next; // mover cabeza al siguiente nodo
            delete temp;       // eliminar antiguo head
            std::cout << "Nodo eliminado inicio";
            return;
        }

        // Caso 3 El nodo a eliminar esta en el medio o en el final
        Node *current = head;
        Node *prevNode = nullptr;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                prevNode->next = current->next; // Reconectar nodo previo al siguiente
                delete current;                 // eliminar nodo
                std::cout << "Nodo eliminado";
                return;
            }
            prevNode = current;
            current = current->next;
        }

        // Caso 4 Valor no encontrado
        std::cout << "Valor " << value << " no encontrado\n";
    }

    void insert_at(int position, int value)
    {
        // Caso 1 posicion invalida
        if (position < 0 || position > size())
        {
            std::cout << "Posición inválida: " << position << "\n";
            return;
        }

        // Caso 2 Insertar al inicio
        if (position == 0)
        {
            push_front(value);
            return;
        }

        // Caso 5 posicion al final
        if (position == size())
        {
            push_back(value);
            return;
        }

        // Caso 3 Posicion en el medio
        Node *newNode = new Node(value);
        Node *current = head;
        Node *prevNode = nullptr;
        for (int x = 0; x < position; x++)
        {
            prevNode = current;
            current = current->next;
        }
        prevNode->next = newNode; // Nodo previo apuntar al nuevo nodo
        newNode->next = current;  // y nuevo nodo apuntar al existente
        return;
    }

    void reverse()
    {
        Node *current = head;
        Node *prevNode = nullptr;
        Node *nextNode = nullptr;
        while (current != nullptr)
        {
            nextNode = current->next; // Guardar siguiente nodo

            current->next = prevNode; // invertir nodo actual

            prevNode = current; // Avanzar Nodo previo al siguiente
            current = nextNode; // Avanzar Nodo actual al siguiente
        }
        head = prevNode;
        return;
    }
};

int main()
{
    LinkedList list;

    std::cout << "====== Probando LinkList ======\n\n";

    // insertar al final
    std::cout << "\nInsertar al final\n";
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(50);
    list.push_back(60);
    list.print();

    std::cout << "\nPrueba remove \n";
    list.remove(20);
    std::cout << "\n";
    list.print();
    std::cout << "\n";

    std::cout << "\nPrueba insert_at \n";
    list.insert_at(1, 40);
    std::cout << "\n";
    list.print();
    std::cout << "\n";

    std::cout << "\nPrueba reverse \n";
    list.reverse();
    std::cout << "\n";
    list.print();
    std::cout << "\n";

    std::cout << "\nPrueba size \n";
    std::cout << list.size() << " \n";

    std::cout << "\nPrueba search \n";
    list.search(30);
    std::cout << "\n";
    list.print();

    std::cout << "\nInsertar al inicio\n";
    list.push_front(50);
    list.print();

    std::cout << "\nPop_back prueba \n";
    list.pop_back();
    list.pop_back();
    list.print();

    std::cout << "\nPresiona Enter para salir...";
    std::cin.get();

    list.~LinkedList();

    return 0;
}