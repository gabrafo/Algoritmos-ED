# Pyhon 2.7, exemplo do livro Entendendo Algoritmos.

def fat(x):
    if x == 1:
        return 1
    else:
        return x * fat(x-1)

print(fat(3))