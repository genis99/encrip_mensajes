/** @file Rejilla.hh
    @brief Especificación de la clase Rejilla 
*/
#ifndef REJILLA_HH
#define REJILLA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <algorithm>
#include <vector>
#endif
using namespace std;

/** @class Rejilla
    @brief Representa una rejilla
    
    Tipo de modulo: datos
    Descripcion del tipo: contiene el id. de rejilla idr, la dimension n y los huecos k de las rejillas de
    0, 90, 180 y 270 grados. n y k son enteros y los huecos son vectores de pares de enteros.
    Las dimensiones validas son numeros pares y el numero de huecos validos son del tipo
    k = n²/ 4 .
    
*/
class Rejilla {

    
private:
    int n, k;
    vector<vector<pair<int,int>>> huecos; // 0, 90, 180 y 270 grados

    /** @brief Funcion para el sort de los huecos

        \pre cierto
        \post devuelve si a > b
    */
    static bool comp_pair_int(pair<int,int> a, pair<int,int> b);
    
    /** @brief Añade los huecos girados a partir del original 

        \pre cierto
        \post se ha rellenado el vector de huecos del parametro implicito a partir del original
    */
    void insertar_huecos(const vector<pair<int,int>>& original);
    
    /** @brief Gira un vector de huecos

        \pre cierto
        \post se han girado 90 grados las posiciones de los huecos
    */
    vector<pair<int,int>> girar_huecos(const vector<pair<int,int>>& v);
    
    /** @brief Calcula la validez de la dimension de la rejilla

        \pre cierto
        \post indica si la dimension de la rejilla es valida
    */
    bool validez_dimension(); 
    
    /** @brief Calcula la validez de la dimension de la rejilla

        \pre cierto
        \post indica si la dimension de la rejilla es valida
    */
    bool validez_huecos(); 
    
    
public:
    // Constructores
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar una rejilla.
        \pre cierto
        \post rejilla de identificador 0, dimension 0 y 0 huecos, no valida
    */
    Rejilla();
    /* Pre: cierto */
    /* Post: rejilla de identificador 0, dimension 0 y 0 huecos, no valida */
    
    // Consultores
    
    /** @brief Consulta la dimension de la rejilla 

        \pre cierto
        \post el resultado es la dimension del parametro implicito
    */
    int consultar_n() const;
    
    /** @brief Consulta el numero de huecos

        \pre cierto
        \post el resultado es el numero de huecos del parametro implicito
    */
    int consultar_k() const;
    
    // Lectura y escriptura
    
    /** @brief Lee una rejilla

        \pre hay preparados en el canal estandard d'entrada dos enteros n,k y 
        una secuencia de posiciones(pares de enteros) de long k
        \post el parametro implicito pasa a tener los atributos leidos del canal
        estandar de entrada y tambien los giros de la rejilla ordenados de forma
        creciente. Devuelve un booleano que indica si la rejilla es valida o no
        y, si no lo es, escribe su correspondiente error
    */
    bool leer();
    
    /** @brief Escribe una rejilla

        \pre cierto
        \post se han escrito los atributos del parametro implicito
        en el canal estandard de salida
    */
    void escribir() const;
    
    /** @brief Codifica un mensaje y lo imprime

        \pre cierto
        \post se ha escrito el mensaje encriptado con la rejilla
    */
    void codificar(string msj) const;
    
    /** @brief Codifica un mensaje y lo imprime si es valido

        \pre cierto
        \post si el mensaje tiene longitud multiple de n² se ha escrito el mensaje desencriptado
        utilizando la rejilla, si no, se escribe un mensaje de error
    */
    void decodificar(string msj) const;
};
#endif
