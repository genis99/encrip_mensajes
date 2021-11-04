/** @file Cjt_patrones.hh
    @brief Especificación de la clase Cjt_patrones 
*/
#ifndef CJT_PATRONES_HH
#define CJT_PATRONES_HH

#include "Patron.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif
using namespace std;

/** @class Cjt_patrones
    @brief Representa un conjunto de patrones
    
    Tipus de modulo: datos
    Descripcion del tipo: representa un conjunto de patrones ordenado por su identificador
*/

class Cjt_patrones {
    
private:
    int np;
    vector<Patron> vpatr;
    static const int MAX_NPATR = 20;
    
public:
    // Constructores
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un cjt de patrones.
        \pre cierto
        \post el resultado es un conjunto de patrones vacio
    */
    Cjt_patrones();
    /* Pre: cierto */
    /* Post: el resultado es un conjunto de patrones vacio */
    
    // Consultores
    /** @brief Devuelve el patron con identificador idp

        \pre cierto
        \post el resultado es el patron con identificador idp
    */
    Patron consultar_patron_idp(int idp) const;
    
    // Modificadores
    
    /** @brief Añade un patron al conjunto 

        \pre cierto
        \post si el identificador del patron ya estaba en el conjunto muestra un error
        y si no lo añade al conjunto
    */
    void anadir_patron(Patron& p);
    
    // Lectura y escriptura
    
    /** @brief Lee unos cuantos patrones y los añade al conjunto 

        \pre hay preparados en el canal estandard d'entrada un entero que representa
       cuantos patrones leeremos y los datos de esos patrones
        \post el parametro implicito pasa a tener los atributos leidos del canal
       estandar de entrada.
    */
    void leer();
    
    /** @brief Escribe el conjunto de patrones

        \pre cierto
        cuantos mensajes leeremos y los datos de esos mensajes
        \post se ha escrito el conjunto de patrones en orden de entrada al conjunto
    */
    void escribir();
};
#endif
