/** @file Patron.hh
    @brief Especificación de la clase Patron 
*/

#ifndef PATRON_HH
#define PATRON_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif
using namespace std;


/** @class Patron
    @brief Representa un patron
    
    Tipo de modulo: datos
    Descripcion del tipo: contiene el arbol binario patron.
    
*/

class Patron {
    
private:
    BinTree<int> patron;
    
public:
    // Constructores

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un patron.
        \pre cierto
        \post patron, arbol vacio
    */
    Patron();
    
    // Consultores
    
    /** @brief Consulta el arbol patron. 

        \pre cierto
        \post el resultado es el arbol binario patron del parametro implicito
    */
    BinTree<int> consultar_patron() const;

    // Lectura y escriptura
    
    /** @brief Lee el arbol. 

        \pre hay preparados en el canal estandard d'entrada hay un arbol en preorder
        con marca -1
        \post el parametro implicito pasa a tener los atributos leidos del canal
        estandar de entrada
    */
    void leer();
    
    /** @brief Lee un patron

        \pre cierto
        \post se han escrito los atributos del parametro implicito
        en el canal estandard de salida
    */
    void escribir();

};
#endif
