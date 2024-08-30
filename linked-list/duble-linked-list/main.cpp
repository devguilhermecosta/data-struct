#include <iostream>

template <typename T>
class Node
{
public:
    T value;
    Node* prev;
    Node* next;

    Node()
    {
        prev = nullptr;
        next = nullptr;
    }
  
    Node(T _value)
    {
        value = _value;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
class DubleList
{
public:
    Node<T>* head;

    DubleList() { head = nullptr; }

    ~DubleList()
    {
        Node<T>* current = head;
        Node<T>* next {nullptr};

        while (current)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // adiciona um novo nó ao início da lista
    void push(T _value)
    {
        Node<T>* node = new Node<T>(_value);

        // caso 01: se a lista estiver vazia, o novo nó será o head;
        if (empty())
        {
            head = node;
            return;
        }

        /*
            caso 02:
            Aqui vem um ponto muito importante.
            Quando a lista não estiver vazia, será necessário atualizar o ponteiro head, e também o ponteiro
            prev e next do novo nó.
            Por definição o ponteiro prev do novo nó será null, então não é necessário fazer nada com ele,
            enquando o ponteiro next passará a apontar para o head.
            Porém agora, o novo nó passará a ser o head.
        */
        head->prev = node;
        node->next = head;
        head = node;
    }

    // adiciona um novo nó ao final da lista
    void pushBack(T _value)
    {
        Node<T>* node = new Node<T>(_value);

        // caso 01: se a lista estiver vazia, o novo nó será o head;
        if (empty())
        {
            head = node;
            return;
        }

        /*
            caso 02:
            checa se existe somente um item na lista.
            se existe um único item na lista, o novo nó deve ser adicionado após o head, e o ponteiro prev do novo
            nó deve apontar para o head.
        */
        if (!head->next)
        {
            head->next = node;
            node->prev = head;
            return;
        }

        /* 
            caso 03:
            se nenhuma das condições anteriores for verdadeira, significa que existem dois ou mais itens na lista.
            agora devemos fazer o último elemento da lista apontar para o novo nó, e o ponteiro prev do novo nó
            deve apontar para o elemento anterior.
        */
        Node<T>* current = head;
        while (current->next)
        {
            current  = current->next;
        }
        current->next = node;
        node->prev = current;
    }

    // retorna o primeiro valor da lista (o head) ou null, se a lista estiver vazia
    auto first()
    {
        return head->value;
    }

    // retorna o último valor da lista ou null se a lista estiver vazia
    T last()
    {
        Node<T>* temp = head;

        if (!temp->next)
        {
            return temp->value;
        }

        while (temp->next)
        {
            temp = temp->next;
        }

        return temp->value;
    }

    // procura um nó pelo seu valor
    auto find(T _value)
    {
        Node<T>* current { nullptr };

        // se a lista estiver vazia, retorna um ponteiro contendo nullptr;
        if (empty())
        {
            return current;
        }

        // percorre toda a lista enquanto existirem nós e também enquanto o valor procurado não for encontrado
        Node<T>* temp = head;
        while (temp && temp->value != _value)
        {
            temp = temp->next;
        }

        // após percorrer a lista, checa se o valor existe
        if (temp && temp->value == _value)
        {
            current = temp;
        }

        return current;
    }

    // deleta o último nó da lista
    void pop()
    {
        // caso 01: lista vazia
        if (empty())
        {
            return;
        }

        // caso 02: existe somente o head
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }

        // caso 03: existem dois ou mais nós
        Node<T>* current = head;
        while (current->next->next)
        {
            current = current->next;
        }

        // checa se current existe antes de tentar deletar
        if (current)
        {
            delete current->next;
            current->next = nullptr;
            return;
        }
    }

    // deleta um elemento de valor específico da lista
    void pop(T _value)
    {
        // caso 01: a lista está vazia
        if (empty())
        {
            return;
        }

        // caso 02: o valor está no head
        if (head->value == _value)
        {
            // existe algum nó após o head?
            if (head->next)
            {
                Node<T>* current = head; // ponteiro para o primeiro nó da lista (head)
                head = current->next; // o próximo valor da lista para a ser o head
                head->prev = nullptr; // o ponteiro prev do novo head não aponta para mais nada
                delete current; // deleta o primeiro valor da lista
                current = nullptr;
                return;
            }

            // não existe outro nó após o head
            delete head;
            head = nullptr;
            return;
        }

        // caso 03: o valor não estão no head e existem vários nós
        Node<T>* current = head;
        while (current->next && current->next->value != _value)
        {
            current = current->next;
        }

        // checa se o valor existe
        if (current->next && current->next->value == _value)
        {
            // o valor a ser deletado é o último valor da lista?
            if (!current->next->next)
            {
                Node<T>* temp = current->next; // aponta para o último nó
                delete temp;
                temp = nullptr;
                current->next = nullptr; // o ponteiro next do penúltimo nó aponta para nada
                return;
            }

            // o valor a ser deletado não é o último da lista
            Node<T>* temp = current->next->next; // aponta para o nó seguinte ao nó a ser deletado
            temp->prev = current; // o ponteiro prev do nó seguinte aponta para o nó atual
            current->next = temp; // o nó atual aponta para o nó posterior ao nó a ser deletado
            delete temp;
            temp = nullptr;
            return;
        }
    }

    // imprime todos os valores da lista
    void print()
    {
        // checa se a lista está vazia
        if (empty())
        {
            return;
        }

        Node<T>* temp = head;

        while (temp)
        {
            std::cout << temp->value << '\n';
            temp = temp->next;
        }
    }

private:
    // checa se a lista está vazia
    bool empty()
    {
        if (!head)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    system("cls");

    DubleList<int> numbers;

    /*
        Os métodos find(), first() e last() tem um sério problema de não tratamento de erro.
        Quando nenhum valor é encontrado o programa quebra.
        Quando 
    */
    return 0;
}
