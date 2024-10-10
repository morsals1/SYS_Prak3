// Prak3Sys.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList { 
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int data) {
        Node* tmp = new Node(data);
        tmp->next = head;
        if (head != nullptr) {
            head -> prev = tmp;
        }
        if (tail == nullptr){
            tail = tmp;
        }
        head = tmp;
    }

    void push_back(int data) {
        Node* tmp = new Node(data);
        tmp -> prev = tail;
        if (tail != nullptr) {
            tail -> next = tmp;
        }
        if (head == nullptr) {
            head = tmp;
        }
        tail = tmp;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node* tmp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        if(tmp == nullptr){
            tail = nullptr;
        }
        delete tmp;
    }

    void pop_back() {
        if (tail == nullptr) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete tmp;
    }

    void display() {
        Node* tmp = head;
        while (tmp) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    void sort() {
        if (!head) return;

        bool swapped;
        do {
            swapped = false;
            Node* tmp = head;

            while (tmp->next) {
                if (tmp->data > tmp->next->data) {

                    int tempData = tmp->data;
                    tmp->data = tmp->next->data;
                    tmp->next->data = tempData;
                    swapped = true;
                }
                tmp = tmp->next;
            }
        } while (swapped);
    }

    void remove_duplicates() {
        Node* curr = head;

        while (curr != nullptr) {
            Node* tmp = curr;
            while (tmp->next != nullptr) {
                if (tmp->next->data == curr->data) {
                    Node* duplicate = tmp->next;
                    tmp->next = tmp->next->next;
                    if (tmp->next != nullptr)
                        tmp->next->prev = tmp;
                    delete duplicate;
                }
                else {
                    tmp = tmp->next;
                }
            }
            curr = curr->next;
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");

    DoublyLinkedList doublyLinkedList;

    std::cout << "1)Добавить элемент в начало.\n2)Добавить элемент в конец.\n3)Удалить элемент с начала.\n4)Удалить элемент с конца.\n5)Отобразить список.\n6)Сортировать список.\n7)Удалить дубликаты.\n8)Выйти.\n";

    int input;

    int a = 0;

    do
    {
        input = 0;
        std::cout << "Введите число (1 - 8): ";
        std::cin >> a;
        switch (a)
        {
        case 1:
            std::cout << "Добавить элемент в начало.\n";
            std::cout << "Введите число:\n";
            std::cin >> input;
            doublyLinkedList.push_front(input);
            break;
        case 2:
            std::cout << "Добавить элемент в конец.\n";
            std::cout << "Введите число:\n";
            std::cin >> input;
            doublyLinkedList.push_back(input);
            break;
        case 3:
            std::cout << "Удалить элемент с начала.\n";
            doublyLinkedList.pop_front();
            break;
        case 4:
            std::cout << "Удалить элемент с конца.\n";
            doublyLinkedList.pop_back();
            break;
        case 5:
            std::cout << "Отобразить список.\n";
            doublyLinkedList.display();
            break;
        case 6:
            std::cout << "Сортировать список.\n";
            doublyLinkedList.sort();
            break;
        case 7:
            std::cout << "Удалить дубликаты.\n";
            doublyLinkedList.remove_duplicates();
            break;
        case 8:
            std::cout << "Выйти.\n";
            break;
        default:
            std::cout << "Вы нажали не ту кнопку\n";
            break;
        }

    } while (a != 8);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
