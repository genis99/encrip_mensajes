/** @file Cjt_rejillas.hh
    @brief Especificación de la clase Cjt_rejillas
*/
#ifndef CJT_REJILLAS_HH
#define CJT_REJILLAS_HH

#include "Rejilla.hh"
#include "Cjt_mensajes.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/** @class Cjt_rejillas
    @brief Representa un conjunto de rejillas
    
    Tipus de modulo: datos
    Descripcion del tipo: representa un conjunto de rejillas ordenado por su identificador
*/

class Cjt_rejillas {
    
private:
    vector<Rejilla> vrej;
    
public:
    // Constructores
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un conjunto de rejillas.
        \pre cierto
        \post el resultado es un conjunto de rejillas vacio
    */
    Cjt_rejillas();
    
    // Consultores
    
    /** @brief Devuelve la rejilla con identificador idr

        \pre cierto
        \post el resultado es la rejilla con identificador idr
    */
    Rejilla consultar_rejilla_idr(int idr) const;
    
    // Modificadores
    
    /** @brief Añade una rejilla al conjunto 

        \pre cierto
        \post añade al conjunto con idr del numero actual de rejillas
    */
    void nueva_rejilla();
    
    // Lectura y escriptura
    
    /** @brief Lee un mensaje y un idr. Escribe el mensaje codificado con una rejilla

        \pre cierto
        \post se ha escrito el mensaje leido codificado con la rejilla idr
    */
    void codificar_rejilla(int idr, string mensaje) const;
    
    /** @brief Codifica un mensaje del conjunto de mensajes con una rejilla y se escribe

        \pre cierto
        \post se ha escrito el mensaje idm codificado con la rejilla idr
    */
    void codificar_guardado_rejilla(string idm, int idr, const Cjt_mensajes& cm) const;
    
    /** @brief Lee un mensaje codificado, lo decodifica y lo escribe

        \pre cierto
        \post se ha escrito el mensaje decodificado con la rejilla idr
    */
    void decodificar_rejilla(int idr) const;
    
    /** @brief Lee unas cuantas rejillas y las añade al conjunto 

        \pre hay preparados en el canal estandard d'entrada un entero que representa
        cuantas rejillas leeremos y los datos de esas rejillas
        \post el parametro implicito pasa a tener los atributos leidos del canal
        estandar de entrada.
    */
    void leer();

    /** @brief Escribe las rejillas del conjunto

        \pre cierto
        \post se ha escrito el conjunto de rejillas en orden de entrada al conjunto
        cada una precedida por su tamaña y numero de huecos
    */
    void escribir() const;
};
#endif
