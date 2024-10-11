# Exemplo do funcionamento de uma Pilha de Chamadas

![Imagem 41.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20ED/Documenta%C3%A7%C3%A3o/Imagens/Imagem%201.png)

![Imagem 42.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20ED/Documenta%C3%A7%C3%A3o/Imagens/Imagem%202.png)

![Imagem 43.png](https://github.com/gabrafo/Algoritmos-ED/blob/master/Implementa%C3%A7%C3%B5es%20de%20ED/Documenta%C3%A7%C3%A3o/Imagens/Imagem%203.png)

Código descrito no exemplo acima:
```python
# -*- coding: utf-8 -*-

# Pyhon 2.7, exemplo do livro Entendendo Algoritmos.

def sauda(nome):
    print ("Olá, " + nome + "!")
    sauda2(nome)
    print ("preparando para dizer tchau...")
    tchau()

def sauda2(nome):
    print ("Como vai " + nome + "?")

def tchau():
    print ("ok, tchau!")

sauda("Gabriel")
```
