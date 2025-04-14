#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void iniciar();
void empezarJuego(char palabras[15]);
void salir();
void dibujo(int intentos);

// FUNCION PRINCIPAL MAIN
int main() {
    iniciar();
    system("pause");
    return 0;
}

//IMPRIME EN PANTALLA LA OPCION DE EMPEZAR O TERMINR EL JUEGO
void iniciar() {
    int op = 0;
    char palabra[15] = "PROGRAMACION";
    
    do {
        system("cls");
        cout << "\n\t\t\t\tJUEGO EL AHORCADO\n\n";
        cout << " TECLEA 1 PARA INICIAR EL PROGRAMA O 0 PARA SALIR: ";
        cin >> op;
    } while (op != 1 && op != 0);

    if (op == 1) {
        empezarJuego(palabra);
    } else {
        salir();
    }
}

void salir() {
    cout << " GRACIAS POR JUGAR ";
}

// FUNCION QUE CONTIENE EL ALGORITMO DEL JUEGO
void empezarJuego(char palabra[15]) {
    int opcion, i, j, k, longitud, espacios;
    char letra;
    int aciertos = 0;
    int intentos = 0;
    int ganar = 0;
    

    
    longitud = strlen(palabra); 
    char frase[longitud];

    //sE COLOCAN GUIONES BAJOS
    for (i = 0; i < longitud; i++) {
        frase[i] = '_';
    }

    do {
        aciertos = 0;
        system("cls");
        cout << "\n\t\t\t\tJUEGO EL AHORCADO\n\n";
        cout << " Intentos Disponibles: " << 6 - intentos<< "\n\n";
        dibujo(intentos);

        // IMPRIME EL ARRAY DE CARACTERES FRASE
        cout << "\n\n\n";
        for (i = 0; i < longitud; i++) {
            cout << " " << frase[i] << " ";
        }

        if (intentos == 6) {
            cout << "\n\n PERDISTE!!\n";
            cout << " LA SOLUCION ERA: " << palabra[opcion] << "\n\n";
            cout << " Presiona Enter para volver a jugar..";
            cin.ignore();  // Limpiar el buffer
            cin.get();  // Espera una tecla (Enter)
            iniciar();
        }

        //COMPRUEBA SI SE HA ADIVINADO LA PALABRA
        espacios = 0;
        for (i = 0; i < longitud; i++) {
            if (frase[i] == '_')
                espacios++;
        }

        if (espacios == 0) {
            cout << "\n\n FELICIDADES.. GANASTE!!\n\n";
            cout << " Presiona Enter para volver a jugar..";
            cin.ignore();  // Limpiar el buffer
            cin.get();  // Espera una tecla (Enter)
            iniciar();
        }

        cout << "\n\n Digite una letra: ";
        cin >> letra;

        // SE REEMPLAZA EL CARACTER GUION BAJO POR LA LETRA INGRESADA
        for (j = 0; j < longitud; j++) {

            if (letra == palabra[j]) {

                frase[j] = letra;
                aciertos++;
            }
        }

        if (aciertos == 0) {
            intentos++;
            
        }

    } while (intentos != 7);
    
    cout << "\n\n";
}

//DIBUJO 
void dibujo(int intentos) {
    switch (intentos) {
        case 0:
            cout << "\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------";
            break;
        case 1:
            cout << "\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------";
            break;
        case 2:
            cout << "\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------";
            break;
        case 3:
            cout << "\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------";
            break;
        case 4:
            cout << "\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |\n    |\n    |\n ----------";
            break;
        case 5:
            cout << "\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      /\n    |\n    |\n ----------";
            break;
        case 6:
            cout << "\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      / \\\n    |\n    |\n ----------";
            break;
    }
}
