class Stack:
    """Stack using list.
    """
    def __init__(self):
        self._size = 0
        self._container = list()
    
    def empty(self):
        return self._size == 0
    
    def push(self, element):
        self._container.append(element)
        self._size += 1
    
    def pop(self):
        if not self.empty():
            self._size -= 1
            self._container.pop()
    
    def top(self):
        if self.empty():
            # Use one of the below return statements.
            # return None
            raise Exception("Stack is empty.")
        
        return self._container[self._size - 1]
