#include <iostream>
using namespace std;

// Entrenamiento OIE 2023
// Nivel 1 - Reto 3 - La fiesta aburrida
// https://aceptaelreto.com/problem/statement.php?id=117

#include <iostream>
using namespace std;

int numCasos;  // Casos a introducir
string entrada;  // Leemos por teclado: "Soy + nombre de persona"
string nombre ="";
string saludo ="";  

int main() {
    cin >> numCasos;
    cin.ignore();

    // Procesar cada caso de prueba
    int i = 0;
    while (i < numCasos) {
        getline(cin, entrada);
        // Leemos el nombre de cada persona
        nombre = "Hola, " + entrada.substr(4) + ".\n";
        // Variable para guardar los datos leídos para mostrarlos al final
        saludo = saludo + nombre;
        i++;
    }   

    // Mostramos el saludo para todas las personas
    cout << saludo;
    return 0;
}

