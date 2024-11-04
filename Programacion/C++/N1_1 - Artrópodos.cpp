#include <iostream>
using namespace std;

// Entrenamiento OIE 2023
// Nivel 1 - Reto 1 - Artrópodos
// https://aceptaelreto.com/problem/statement.php?id=293

int casosPrueba;  // Casos a evaluar
// Patas de cada artrópodo
const int patasInsectos = 6;
const int patasAracnicos = 8;
const int patasCrustaceos = 10;

// Número de artrópodos que introduciremos por teclado
int numInsectos, numAracnidos, numCrustaceos, numEscolopendras, numAnillos;
int totalPatas = 0;  // Variable para contar las patas de los artrópodos

int main() {
    cout << "Introduce los casos de prueba: ";
    cin >> casosPrueba;
    int i = 0;
    while (i < casosPrueba){
        // Pedimos por teclado el número de diferentes artrópodos
        cout << "Insectos Aracnidos Crustaceos Escolopendras Anillos: ";
        cin >> numInsectos >> numAracnidos >> numCrustaceos >> numEscolopendras >> numAnillos;
        
        // Calculamos el total de patas
        totalPatas = totalPatas + numInsectos*patasInsectos + numAracnidos*patasAracnicos + 
        + numCrustaceos*patasCrustaceos + numEscolopendras*numAnillos*2;
        i++;
    }
    if (totalPatas < 1000000000){
        cout << "Total patas: " << totalPatas;
    } else {
        cout << "Es imposible que haya mas de 1000000000";
    }
    return 0;
}