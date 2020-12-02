/******************************************************************************
Resolución del primer problema del examen de Noviembre mediante uso de
bucles y de recursividad.

a) Dado un vector, imprimir en pantalla los elementos que son divisores del primer elemento


*******************************************************************************/

#include <iostream>
using namespace std;

/*
// VERSION 1. SIN FUNCIONES (NI POR TANTO RECURSIVIDAD)
int main()
{
    int v[]={24,6,2,8,10};
    int cont_v=5;
    cout << "Los divisores de " << v[0] << " son " << endl;
    for ( int i=0; i<cont_v; ++i ) {
        if( v[0]%v[i]==0 ) {
            cout << v[i] << ", ";
        }
    }
    cout<<endl;

    return 0;
}

// FIN VERSION 1
*/

/*
// VERSION 2. CON FUNCIONES PERO SIN RECURSIVIDAD
void divisores_de( const int numero, const int vector[], const int tama) {
    for ( int i=0; i<tama; ++i ) {
        if( numero%vector[i]==0 ) {
            cout << vector[i] << ", ";
        }
    }
}
int main()
{
    int v[]={24,6,2,8,10};
    int cont_v=5;
    cout << "Los divisores de " << v[0] << " son " << endl;
    divisores_de( v[0], v, cont_v);
    cout<<endl;

    return 0;
}

// FIN VERSION 2
*/


// VERSION 3. CON  RECURSIVIDAD
void divisores_de_recursiva( const int numero, const int vector[], const int posicion, const int ultimo) {
    if( posicion>=ultimo ) return;
    if( numero%vector[posicion]==0) {
        cout << vector[posicion] << ", ";
    }
    divisores_de_recursiva( numero, vector, posicion+1, ultimo );
}
int main()
{
    int v[]={24,6,2,8,10};
    int cont_v=5;
    cout << "Los divisores de " << v[0] << " son " << endl;
    divisores_de_recursiva( v[0], v, 0, cont_v);
    cout<<endl;

    return 0;
}

// FIN VERSION 3
