/** @file Rejilla.hh
    @brief Especificación de la clase Rejilla 
*/
#ifndef REJILLA_HH
#define REJILLA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include "ParInt.hh"
#endif
using namespace std;

/** @class Rejilla
    @brief Representa una rejilla
    
    Tipo de modulo: datos
    Descripcion del tipo: contiene el id. de rejilla idr, la dimension n y los huecos k de las rejillas de
    0, 90, 180 y 270 grados. n y k son enteros y los huecos son vectores de pares de enteros.
    Las dimensiones validas son numeros pares y el numero de huecos validos son del tipo
    k = n²/ 4 . La validez se indica en el atributo es_valida
    
*/
class Rejilla {

    
private:
    int n, k;
    vector<vector<ParInt>> huecos; // 0, 90, 180 y 270 grados
    bool valida;
    
    /** @brief Añade los huecos girados a partir del original 

        \pre cierto
        \post se ha rellenado el vector de huecos del parametro implicito a partir del original
    */
    void insertar_huecos(const vector<ParInt>& original);
    
    /** @brief Calcula la validez de la rejilla.

        \pre cierto
        \post el atributo es_valida indica si el parametro implicito es una rejilla valida
    */
    void calcular_validez(); 
    
    
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

    ~Rejilla();
    
    
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
    
    /** @brief Consulta el vector de huecos, segun el numero de veces que se ha girado

        \pre cierto
        \post el resultado es el vector de huecos (del giro indicado: 0 sin girar,
        1 1er giro-> 90º, 2 -> 180Cjt_patrones.leer();º, 3 -> 270º) del parametro implicito
    */
    vector<ParInt> consultar_huecos(int giro) const; // TODO això desvela la implementació de la classe
    
    /** @brief Consulta si la rejilla es valida

        \pre cierto
        \post el resultado nos dice si la rejilla es valida o no
    */
    bool es_valida() const;
    /* Pre: cierto  */
    /* Post: el resultado nos dice si la rejilla es valida o no */
    
    // Lectura y escriptura
    
    /** @brief Lee una rejilla

        \pre hay preparados en el canal estandard d'entrada dos enteros n,k y 
        una secuencia de posiciones(pares de enteros) de long k
        \post el parametro implicito pasa a tener los atributos leidos del canal
        estandar de entrada y tambien los giros de la rejilla y si es valida o no
    */
    void leer();
    
    /** @brief Lee una rejilla

        \pre cierto
        \post se han escrito los atributos del parametro implicito
        en el canal estandard de salida
    */
    void escribir();
};
#endif