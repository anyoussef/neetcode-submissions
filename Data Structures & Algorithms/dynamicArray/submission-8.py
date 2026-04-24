class DynamicArray:
    def __init__(self, capacity: int):
        if capacity <= 0:
            raise ValueError("capacity must be > 0")
        self.capacity = capacity
        self.length = 0
        self.arr = [0] * self.capacity

    def get(self, i: int) -> int:
        return self.arr[i]  # assuming 0 <= i < self.length

    def set(self, i: int, n: int) -> None:
        self.arr[i] = n  # assuming 0 <= i < self.length

    def pushback(self, n: int) -> None:
        if self.length == self.capacity:
            self.resize()
        self.arr[self.length] = n
        self.length += 1

    def popback(self) -> int:
        # assume non-empty
        value = self.arr[self.length - 1]
        self.length -= 1
        return value

    def resize(self) -> None:
        new_capacity = self.capacity * 2
        new_arr = [0] * new_capacity
        for i in range(self.length):
            new_arr[i] = self.arr[i]
        self.arr = new_arr
        self.capacity = new_capacity

    def getSize(self) -> int:
        return self.length

    def getCapacity(self) -> int:
        return self.capacity