#include <iostream>
using namespace std;

// Entrenamiento OIE 2023
// Nivel 1 - Reto 5 - Goteras
// https://aceptaelreto.com/problem/statement.php?id=216

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
        int gotas;
        cin >> gotas;  // Gotas que entran en el cubo

        int horas = gotas / 3600;
        int resto = gotas % 3600;
        int minutos = resto / 60;
        int segundos = resto % 60; 
        
        string horasStr, minutosStr, segundosStr;
        // Pasamos a string los resultados
        if (horas < 10){
            horasStr = "0"+to_string(horas) + ":";
        } else{
            horasStr = to_string(horas) + ":";
        }
        if (minutos < 10){
            minutosStr = "0"+to_string(minutos) + ":";
        } else{
            minutosStr = to_string(minutos) + ":";
        }
        if (segundos < 10){
            segundosStr = "0"+to_string(segundos);
        } else{
            segundosStr = to_string(segundos);
        }
        
        string str = horasStr + minutosStr + segundosStr;
        if (horas >= 24){
            str = str + " --> Cuidado, no puedes tener un cubo mas de 24 horas";
        }
        resultadoStr = resultadoStr + str + "\n";
             
        i++;
    }

    cout << resultadoStr << endl;
    return 0;
}

