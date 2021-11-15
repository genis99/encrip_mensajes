/** @file Cjt_mensajes.hh
    @brief Especificación de la clase Cjt_mensajes 
*/
#ifndef CJT_MENSAJES_HH
#define CJT_MENSAJES_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Cjt_mensajes
    @brief Representa un cjt de mensajes
    
    Tipo de modulo: datos
    Descripcion del tipo: representa un conjunto de mensajes ordenado por su identificador
*/

class Cjt_mensajes {
    
private:

    map<string,string> mensajes;

public:
    // Constructores
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un cjt de mensajes.
        \pre cierto
        \post el resultado es un conjunto de mensajes vacio
    */
    Cjt_mensajes();
    
    // Consultores
    
    /** @brief Devuelve el mensaje con identificador idm

        \pre cierto
        \post el resultado es el mensaje con identificador idm
    */
    string consultar_mensaje_idm(string idm) const;

    // Modificadores
    
    /** @brief Borra un mensaje del conjunto 

        \pre cierto
        \post si no existe el identificador en el conjunto se muestra un error 
        y si no se borra del conjunto
    */
    void borrar_mensaje(string idm);

    // Lectura y escriptura
    
    /** @brief Lee el idm y el mensaje y lo añade al conjunto 

        \pre hay preparado en el canal estandard d'entrada un string que representa el identificador
        de mensaje y un string que representa el contenido del mensaje
        \post si el identificador del mensaje ya estaba en el conjunto muestra un error
        y si no lo añade al conjunto
    */
    void nuevo_mensaje();
    
    /** @brief Lee unos cuantos mensajes y los añade al conjunto 

        \pre hay preparados en el canal estandard d'entrada un entero que representa
        cuantos mensajes leeremos y los datos de esos mensajes, su id y su msj.
        \post el parametro implicito pasa a tener los atributos leidos del canal
        estandar de entrada.
    */
    void leer_conjunto();
    
    /** @brief Escribe el conjunto de mensajes

        \pre cierto
        cuantos mensajes leeremos y los datos de esos mensajes
        \post se ha escrito el conjunto de mensajes en orden alfabetico de identificador
    */
    void escribir() const;
};
#endif
