Uma lista ligada ou lista encadeada (linked-list) é uma estrutura de dados do tipo container, em que, cada novo nó possui o endereço 
de memório do próixmo nó, servindo para agrupar elementos do mesmo tipo.

A grande vantagem de listas ligadas é que seu crescimento é dinâmico, ou seja, em tempo de execução podemos fazer um crud completo.
A grande desvantagem é que para cada operação é necessário percorrer a lista completa, e dependendo da quantidade de nós, pode tornar
inviável a sua utilização. Sendo assim, sua indicação de uso seria para casos mais simples, em que há uma quantidade restrita de nós.

Existem dois tipos de listas ligadas: lista ligada simples e lista ligada dupla.
A lista ligada simples é aquela que cada nó possui o endereço de memória do próximo nó, contudo, um nó não conhece o elemento anterior.
Já a lista ligada dupla, é aquela em que cada nó conhece o nó anterior e o nó posterior.

Para implementar uma lista ligada, é preciso: uma classe Node (nó) para criar novos nós, uma classe List para gerenciar os nós, e um poteiro
dentro da classe List utilizado para indiciar o início da lista.
