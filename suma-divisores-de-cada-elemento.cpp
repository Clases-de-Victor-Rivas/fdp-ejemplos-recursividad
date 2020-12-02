/******************************************************************************
Resolución del primer problema del examen de Noviembre mediante uso de
bucles y de recursividad.

b) Genere y muestre en pantalla otro vector de enteros (w), en el que el elemento de la posición i se
calcula como suma de los elementos del vector v que son divisores de dicho elemento. Por
ejemplo, dado el vector {1, 3, 5, 8, 2, 3, 7, 10} se obtiene el vector {1, 7, 6, 11, 3, 7, 8, 18}, es decir:
la suma de divisores de 1 es 1 ya que solo se tiene a él como divisor, la suma de los divisores de 3 es
7 (1 + 3+ 3) y así sucesivamente.


*******************************************************************************/

#include <iostream>
using namespace std;

/*
// VERSION 1. SIN FUNCIONES (NI POR TANTO RECURSIVIDAD)
int main()
{
    const int MAX = 20;
    int v[MAX]={1, 3, 5, 8, 2, 3, 7, 10};
    int cont_v=8;
    
    // inicializamos a 0 el vector donde se guardarán las sumas
    int w[MAX];
    for( int i=0; i<MAX; ++i ) {
        w[i]=0;
    }

    for( int i=0; i<cont_v; ++i ) {
        for( int j=0; j<cont_v; ++j ) {
            if( v[i]%v[j]==0 ) {
                w[i]+=v[j];
            }
        }
    }
    
    cout << "El vector w resultante es: " << endl;
    for ( int i=0; i<cont_v; ++i ) {
        cout << w[i] << ", ";
    }
    cout << endl;
    
    cout << "(El resultado debería ser: "<< endl 
         << "1, 7, 6, 11, 3, 7, 8, 18,)" << endl;
    return 0;
}

*/

/*
// VERSION 2. CON FUNCIONES PERO SIN RECURSIVIDAD
void inicializa_vector( int vector[], const int tama ) {
    for( int i=0; i<tama; ++i ) {
        vector[i]=0;
    }
}

void calcula_suma_divisores(const int v_entrada[], const int tama, int v_salida[]) {
    for( int i=0; i<tama; ++i ) {
        for( int j=0; j<tama; ++j ) {
            if( v_entrada[i]%v_entrada[j]==0 ) {
                v_salida[i]+=v_entrada[j];
            }
        } // for j
    } // for i
} // void calcula_suma_divisores

void imprime_vector_resultante( const int vector[], const int tama ) {
   for ( int i=0; i<tama; ++i ) {
        cout << vector[i] << ", ";
    }
}

int main()
{
    const int MAX = 20;
    int v[MAX]={1, 3, 5, 8, 2, 3, 7, 10};
    int cont_v=8;
    
    // inicializamos a 0 el vector donde se guardarán las sumas
    int w[MAX];
    inicializa_vector( w, MAX );

    calcula_suma_divisores( v, cont_v, w);
    
    cout << "El vector w resultante es: " << endl;

    cout << endl;
    
    cout << "(El resultado debería ser: "<< endl 
        << "1, 7, 6, 11, 3, 7, 8, 18,)" << endl;
    return 0;
}

*/


// VERSION 3. CON  RECURSIVIDAD
void inicializa_vector_recursividad( int vector[], const int posicion, const int tama ) {
    if ( posicion>=tama ) return;
    // Pongo a cero SOLAMENTE el elemento que está en la celda POSICION
    vector[posicion]=0;
    inicializa_vector_recursividad( vector, posicion+1, tama );
}

void calcula_suma_divisores_recursividad(const int v_entrada[], int posicion, const int tama, int v_salida[]) {
    if ( posicion>=tama ) return;
    // Calculo la suma de los divisores SOLAMENTE del elemento que está en la celda POSICION
    for( int j=0; j<tama; ++j ) {
        if( v_entrada[posicion]%v_entrada[j]==0 ) {
            v_salida[posicion]+=v_entrada[j];
        }
    } // for j
    calcula_suma_divisores_recursividad( v_entrada, posicion+1, tama, v_salida);
} // void calcula_suma_divisores_recursividad

int main()
{
    const int MAX = 20;
    int v[MAX]={1, 3, 5, 8, 2, 3, 7, 10};
    int cont_v=8;
    
    // inicializamos a 0 el vector donde se guardarán las sumas
    int w[MAX];
    inicializa_vector_recursividad( w, 0, MAX );

    calcula_suma_divisores_recursividad( v, 0, cont_v, w);
    
    cout << "El vector w resultante es: " << endl;
    for ( int i=0; i<cont_v; ++i ) {
        cout << w[i] << ", ";
    }
    cout << endl;
    
    cout << "(El resultado debería ser: "<< endl 
        << "1, 7, 6, 11, 3, 7, 8, 18,)" << endl;
    return 0;
}

// FIN VERSION 3
