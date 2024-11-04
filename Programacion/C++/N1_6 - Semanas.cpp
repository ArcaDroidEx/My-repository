#include <iostream>
using namespace std;

// Entrenamiento OIE 2023
// Nivel 1 - Reto 6 - Semanas
// https://aceptaelreto.com/pub/problems/v002/74/st/problem.pdf

#include <iostream>
#include <string>
using namespace std;

int numCasos;
string resultadoStr;

int main() {
    cin >> numCasos;

    // Procesar cada caso de prueba
    int i = 0;
    while (i < numCasos) {
        int diasAño, diasSemana, diaComienzoAño;
        int diasSobraPrincipio, numSemanas, diasSobraFinal;
        
        cin >> diasAño >> diasSemana >> diaComienzoAño;  

        // De aquí salen los días que sobran al comienzo del año
        diasSobraPrincipio = (diasSemana-diaComienzoAño+1) % diasSemana;
        // De aquí salen las semanas completas
        numSemanas = (diasAño - diasSobraPrincipio) / diasSemana;        
        // El resto de esa división nos da los días sobrantes en la última semana
        diasSobraFinal = (diasAño - diasSobraPrincipio) % diasSemana; 
        
        string str;
        str = to_string(numSemanas);
        resultadoStr = resultadoStr + str + "\n";
             
        i++;
    }

    cout << resultadoStr << endl;
    return 0;
}

