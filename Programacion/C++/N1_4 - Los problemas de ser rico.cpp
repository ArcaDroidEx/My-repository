#include <iostream>
using namespace std;

// Entrenamiento OIE 2023
// Nivel 1 - Reto 4 - Los problemas de ser rico
// https://aceptaelreto.com/pub/problems/v001/91/st/problem.pdf

#include <iostream>
using namespace std;

int numCasos;  // Casos a introducir
int compartimentos;  // Número de compartimentos del acuario
int capacidad;  // Capacidad del compartimento más grande
int diferenciaLitros;  // Diferencia de litros entre compartimentos
int capacidadTotal = 0;  // Capacidad total del acuario
string capacidadTotalString = "";  // Para imprimirlo todo junto

int main() {
    cin >> numCasos;

    // Procesar cada caso de prueba
    int i = 0;
    while (i < numCasos) {
        cin >> compartimentos >> capacidad >> diferenciaLitros;
        if (compartimentos>0 and capacidad>0 and diferenciaLitros>0 and 
            compartimentos<10000 and capacidad<10000 and diferenciaLitros<10000){
            capacidadTotal = 0; 
            while (compartimentos > 0){
                capacidadTotal = capacidadTotal + capacidad;
                capacidad = capacidad - diferenciaLitros;
                if (capacidad<0){ // Si la capacidad es negativa la quedamos en 0
                    cout << "Cuidado,hay una capacidad negativa revisa la diferencia de litros" << endl;
                    capacidad = 0;
                }
                compartimentos--;
            } 
            // Pasamos a string la capacidad total para mostrar todos los resultados
            string str = to_string(capacidadTotal);
            capacidadTotalString = capacidadTotalString + str + "\n";
        } else {
            cout << "Cuidado, las cantidades deben estar entre 0 y 10000" << endl;
        }
        i++;
    }   

    // Mostramos el saludo para todas las personas
    cout << capacidadTotalString;
    return 0;
}
