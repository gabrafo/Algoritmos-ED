# Implementação de Classe em C++
Implementação de métodos em uma classe podem ser *Inline* (dentro da classe) ou fora da classe (utilizando o operador de escopo `::`).

## *Inline*
Uma função *inline* é uma **sugestão** para o compilador fazer uma cópia de seu código ao invés da chamada de função. Isso gera um pequeno aumento de eficiência. 

Geralmente usa-se *inline* com **funções pequenas e que são chamadas com frequência**. O compilador pode aceitar, ou não, a sugestão, dependendo de opções de otimização.

Funções ou procedimentos que são **implementados dentro da declaração da classe** são compiladas como *inline*. Outra alternativa é usar a diretiva *inline* antes da declaração da função.

- Sem diretiva ***inline***:
```cpp
class Foo {  

    ...

public:  
    bool inicializa() {  
      n = 0;
      c = 'a';
      f = 0;
      s = "a";

      vet = new int[10];  
      return true;
    }  
    
    ...
    
 bool finaliza() {
      delete[] vet;  
      return true;  
    }

    float calcula(int x) {
      return x * f;  
    }

    void imprime() {
      cout << n << " " 
           << c << " "
           << f << " " 
           << s << endl;
    }
};
```

- Utilizando a diretiva ***inline***:
```cpp
class Foo {  

    ...

    bool finaliza() {

      delete[] vet;  
      return true;  
    }  

    inline float calcula(int x);
};

```

```cpp
float Foo::calcula(int x) {
      return x * f;  
}
```
No caso acima, tanto `finaliza()`, quanto `calcula()` são funções *inline*.

## Implementação externa (sem *inline*)
```cpp
class Foo {  
    ...
};
```

```cpp
bool Foo::inicializa() {  
  n = 0;

  c = 'a';

  f = 0;

  s = "a";

  vet = new int[10];  
  return true;

}  

bool Foo::finaliza() {

  delete[] vet;  
  return true;  
} 

float Foo::calcula(int x) {
      return x * f;  
}

void Foo::imprime() {
  cout << n << " " 
       << c << " "
       << f << " " 
       << s << endl;
}
```

## Implementação interna ou externa?
Uma diferença prática entre implementação interna ou externa é que a interna é automaticamente *inline*.  Nesse sentido, é importante lembrar que o compilador pode, ou não, acatar a sugestão de utilizar *inline*.

A implementação externa permite que o código seja separado em arquivos diferentes: um arquivo .h ou .hpp com a declaração (o cabeçalho) e um arquivo .cpp com a implementação dos métodos. Nesse caso, pode-se disponibilizar a implementação já compilada em forma de código-objeto, sem necessidade de disponibilizar o código da implementação.

Tirando-se os detalhes da declaração inline automática, ou a possibilidade de disponibilização de bibliotecas sem o código-fonte da implementação, na grande maioria dos casos a opção por implementação interna ou externa é uma questão de estilo.