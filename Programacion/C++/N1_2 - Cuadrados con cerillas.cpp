#include <iostream>
using namespace std;

// Entrenamiento OIE 2023
// Nivel 1 - Reto 2 - Cuadrados con cerillas
// https://aceptaelreto.com/problem/statement.php?id=340

#include <iostream>
#include <string>
using namespace std;

int numCasos;
string totalCerillasString;

int main() {
    cin >> numCasos;

    // Procesar cada caso de prueba
    int i = 0;
    while (i < numCasos) {
        int m, n;
        cin >> m >> n;  // m filas y n columnas

        // Calcular el número total de cerillas

        // m+1 filas de cerillas * cerillas que hay por columna
        int cerillasHorizontales = (m + 1) * n; 
        // n+1 columnas de cerillas * cerillas que hay por fila
        int cerillasVerticales = (n + 1) * m;
        int totalCerillas = cerillasHorizontales + cerillasVerticales;

        // Pasamos a string el total de cuadrados
        string str = to_string(totalCerillas);
        totalCerillasString = totalCerillasString + str + "\n";
             
        i++;
    }

    cout << totalCerillasString << endl;
    return 0;
}

