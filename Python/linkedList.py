class Node[T]:
    def __init__(self, data: T) -> None:
        self.data: T = data
        self.next: Node | None = None

    def __repr__(self) -> str:
        return str(self.data)


class LinkedList[T]:
    def __init__(self, nodes: list[T] | None = None) -> None:
        self.__head: Node | None = None
        if nodes:
            node = Node(nodes.pop(0))
            self.__head = node
            for n in nodes:
                node = Node(n)
                node.next = self.__head
                self.__head = node

    def append(self, data: T) -> T:
        # empty list
        if not self.__head:
            self.__head = Node(data)
            self.__head.next = None
        # the list has at least one node
        else:
            current: Node | None = self.__head
            self.__head = Node(data)
            self.__head.next = current

        return self.__head.data

    def __repr__(self) -> str:
        current: Node | None = self.__head
        temp_list = []
        # the list has at least one node
        while current:
            temp_list.append(current.data)
            current = current.next
        return str(temp_list)

    def remove(self, data: T) -> None:
        current: Node | None = self.__head
        previous: Node | None = None

        # empty list
        if not current:
            return

        # the list has one node
        if not current.next and current.data == data:
            self.__head = None
            return

        # several nodes
        while current and current.data != data:
            previous = current
            current = current.next

        # the item was found
        if current and current.data == data:
            if current == self.__head:
                self.__head = current.next
            else:
                if previous:
                    previous.next = current.next


my_list = LinkedList(['a', 'b', 'x'])
my_list.append('y')
my_list.append('z')
my_list.remove('b')
print(my_list)
