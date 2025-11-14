#include <iostream>
#include <string>

template <typename T>
class Node
{
public:
  // membros 
  T value;
  Node<T>* pNext;

  // construtor sem parâmetros
  Node() {
    this->pNext = nullptr;
  }

  // construtor com parâmetros
  Node(T _value)
  {
    this->value = _value;
    this->pNext = nullptr;
  }
};

template <typename T>
class List
{
public:
  // indica o elemento que dá início à lista.
  Node<T>* pHead;

  // construtor padrão.
  List()
  {
    this->pHead = nullptr;
  }

  // destrutor
  ~List()
  {
    Node<T>* current = pHead;
    Node<T>* next {nullptr};

    while (current)
    {
      next = current->pNext;
      delete current;
      current = next;
    }
  }

  // adiciona um novo nó ao início da lista
  void push(T _value)
  {
    // cria um novo nó
    Node<T>* node = new Node<T>(_value);

    // primeiramente checa se existe algum Head.
    // se Head for falso, significa que é o primeiro elemento.
    if (pHead == nullptr)
    {
      pHead = node;
      return;
    }

    // se pHead não for nullptr, significa que algum nó já foi inserido,
    // então esse novo nó passa a ser o head e o head anterior passa a ser o próximo valor da lista.
    node->pNext = pHead;
    pHead = node;
  }

  // adiciona um novo nó ao final da lista
  void pushBack(T _value)
  {
    Node<T>* node = new Node<T>(_value);

    // primeiro checa se a lista está vazia.
    if (!pHead)
    {
      pHead = node;
      return;
    }

    // se a lista não estiver vazia, percorre a lista até achar o valor null.
    // quando encontra o valor null, significa que chegou ao final da lista, então, o ponteiro pNext
    // do último valor passa a apontar para este nó que está sendo criado agora, e o ponteiro pNext
    // deste nó, por padrão é null
    Node<T>* temp = pHead;

    while (temp->pNext)
    {
      temp = temp->pNext;
    }
    temp->pNext = node;
  }

  // deleta o último elemento da lista
  void pop()
  {
    // checa se a lista está vazia
    if (!pHead)
    {
      return;
    }

    // verifica se há apens um nó na lista.
    // se há apenas um nó, não há porque fazer um loop while
    if (!pHead->pNext)
    {
      delete pHead;
      pHead = nullptr;
      return;
    }

    // se o ponteiro pNext do head não for null, significa que existem dois ou mais valores na lista.
    // percorrer a lista completa até que o penúlitmo valor da lista seja null, então atualizar
    // o ponteiro pNext do penúltimo valor para null. Assim, o último valor não existirá mais
    Node<T>* temp = pHead;
    while (temp->pNext->pNext)
    {
      temp = temp->pNext;
    }
    delete temp->pNext;
    temp->pNext = nullptr;
    return;
  }

  // deleta um elemento pelo seu valor
  void pop(T _value)
  {
    // checa se a lista está vazia
    if (!pHead)
    {
      return;
    }

    // se o valor procurado for o valor do head, não há necessidade de fazer um loop while.
    // basta atualizar o head para o próximo ponteiro pNext.
    if (pHead->value == _value)
    {
      Node<T>* current = pHead;
      current = pHead->pNext;
      delete current;
      return;
    }

    // agora, quando houver muitos itens, faz um loop até encontrar o nó anterior ao nó do valor procurado.
    // o ponteiro pNext deste nó anterior será atualizado para o próximo nó após o nó que se deseja deletar.
    Node<T>* current = pHead;
    while (current->pNext && current->pNext->value != _value)
    {
      current = current->pNext;
    }

    // checa se existe um valor após current. Se existir, isso significa que este é o valor que se deseja deletar,
    // então o seu valor será atualizado para o valor valor seguinte da lista.
    if (current->pNext)
    {
      current->pNext = current->pNext->pNext;
    }
  }

  // retorna true ou false para um valor procurado.
  bool find(T _value)
  {
    // checa se a lista está vazia
    if (!pHead)
    {
      return false;
    }

    // checa se o valor do head é o valor procurado
    if (pHead->value == _value)
    {
      return true;
    }

    // se o valor do head não for o valor procurado, faz um loop while para tentar encontrar
    Node<T>* current = pHead;
    while (current->pNext && current->pNext->value != _value)
    {
      current = current->pNext;
    }

    if (current->pNext && current->pNext->value == _value)
    {
      return true;
    }

    return false;
  }

  // edita o valor de um nó
  void set(T _search, T _value)
  {
    // checa se a lista está vazia
    if (!pHead)
    {
      return;
    }

    // verifica se o valor procurado está no head
    if (pHead->value == _search)
    {
      pHead->value = _value;
      return;
    }

    // caso o valor procurado não esteja no head, percorre a lista até encontrar o nó
    // anterior ao nó cujo valor deve ser atualizado
    Node<T>* current = pHead;
    while (current->pNext && current->pNext->value != _search)
    {
      current = current->pNext;
    }

    if (current && current->pNext->value == _search)
    {
      current->pNext->value = _value;
    }
  }

  // imprime todos os valores
  void print()
  {
    // checar se a lista está vazia
    if (!pHead)
    {
      return;
    }

    Node<T>* temp = pHead;

    // por padrão o ponteiro pNext de cada novo nó inicia como null.
    // isso significa que o último valor inserido na lista terá seu ponteiro pNext como null.
    // o que está sendo feito aqui é percorrer a lista inteira até achar o valor null.
    // quando o valor null for encontrado, o loop é encerrado e significa que a lista chegou ao fim.
    while (temp)
    {
      std::cout << temp->value << '\n';
      temp = temp->pNext;
    }
  }
};
