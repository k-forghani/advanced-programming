class Account:
    def __init__ (self, id, inventory, name):
        self.id = id
        self.inventory = inventory
        self.name = name

    def deposit (self, amount):
        self.inventory += amount
    
    def withdraw (self, amount):
        if amount <= self.inventory:
            self.inventory -= amount
            print(f"{items[1]} has been withdrawn from your account")
        else:
            print("Insufficient balance")

    def display (self):
        print(self.inventory)

id, inventory, name = input().split()
account = Account(id, int(inventory), name)

while True:
    try:
        items = list(map(int, input().split()))
    except EOFError:
        break

    if items:
        if items[0] == 1:
            account.deposit(int(items[1]))
        elif items[0] == 2:
            account.withdraw(int(items[1]))
        elif items[0] == 3:
            account.display()
        else:
            break
    else:
        break