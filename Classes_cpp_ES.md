
# Introducción a Clases en C++

En C++, una **clase** es una estructura que te permite definir un tipo de dato personalizado, que puede incluir tanto datos como funciones. Las clases son una forma de organizar y estructurar el código, permitiendo agrupar atributos (variables) y métodos (funciones) que están relacionados entre sí.

## Explicación sencilla

Piensa en una clase como una plantilla o un molde para crear objetos. Un objeto es una instancia de esa clase. Por ejemplo, si tienes una clase llamada `Coche`, cada coche específico que crees usando esa clase será un objeto diferente, pero todos compartirán las características y comportamientos definidos en la clase `Coche`.

## Contenidos de una clase

Una clase en C++ generalmente tiene los siguientes componentes:

1. **Nombre de la clase**: Es el identificador que das a la clase. Por ejemplo: `class Coche { ... };`.

2. **Atributos (variables miembro)**: Son las variables que pertenecen a la clase y representan las propiedades o características de los objetos que se crean a partir de la clase.
   - Ejemplo: `int velocidad;`, `string color;`.

3. **Métodos (funciones miembro)**: Son las funciones que pertenecen a la clase y definen los comportamientos de los objetos creados a partir de la clase.
   - Ejemplo: `void acelerar();`, `void frenar();`.

4. **Constructores**: Son funciones especiales que se llaman automáticamente cuando se crea un objeto de la clase. Se usan para inicializar los atributos.
   - Ejemplo: `Coche(string c, int v) { color = c; velocidad = v; }`.

5. **Destructores**: Son funciones especiales que se llaman cuando un objeto de la clase es destruido (por ejemplo, cuando sale del alcance). Se utilizan para limpiar recursos si es necesario.
   - Ejemplo: `~Coche() { // liberar recursos }`.

6. **Modificadores de acceso**: Son palabras clave que determinan quién puede acceder a los miembros de la clase. Los principales son:
   - `public`: Los miembros son accesibles desde fuera de la clase.
   - `private`: Los miembros solo son accesibles desde dentro de la clase.
   - `protected`: Los miembros son accesibles desde la clase y desde clases derivadas (herencia).

## Ejemplo de una clase en C++

```cpp
#include <iostream>
using namespace std;

class Coche {
private:
    int velocidad;
    string color;

public:
    // Constructor
    Coche(string c, int v) {
        color = c;
        velocidad = v;
    }

    // Método para acelerar
    void acelerar() {
        velocidad += 10;
    }

    // Método para mostrar detalles
    void mostrarDetalles() {
        cout << "Color: " << color << ", Velocidad: " << velocidad << " km/h" << endl;
    }
};

int main() {
    // Crear un objeto de la clase Coche
    Coche miCoche("Rojo", 50);

    // Usar métodos del objeto
    miCoche.acelerar();
    miCoche.mostrarDetalles();

    return 0;
}
```

En este ejemplo, `Coche` es una clase con dos atributos (`velocidad` y `color`) y dos métodos (`acelerar` y `mostrarDetalles`). El constructor se usa para inicializar un objeto `miCoche` con un color y una velocidad inicial. Luego, puedes llamar a los métodos para manipular el objeto.

Esta estructura te permite modelar conceptos del mundo real en tu programa, lo que facilita la organización y reutilización del código.
