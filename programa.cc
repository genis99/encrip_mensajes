/**
 * @mainpage Encriptación de mensajes
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Cjt_mensajes</em>, <em>Cjt_rejillas</em>, <em>Cjt_patrones</em>, <em>Mensaje</em>, <em>Rejilla</em> y <em>Patron</em>

*/

/** @file programa.cc
    @brief Programa principal de la <em>Encriptación de mensajes</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Cjt_mensajes.hh"
#include "Rejilla.hh"
#include "Cjt_rejillas.hh"
#include "Patron.hh"
#include "Cjt_patrones.hh"

/** @brief Programa principal para la <em>Encriptación de mensajes</em>.
*/
int main ()
{
    Cjt_mensajes cm;
    cm.leer();
    Cjt_rejillas cr;
    cr.leer();
    Cjt_patrones cp;
    cp.leer();
    string comando;
    cin >> comando;
    while (comando != "fin") {
        if (comando = "nuevo_mensaje") {
            Cjt_mensajes.nuevo_mensaje();
        }
        else if (comando = "nueva_rejilla") {
            Cjt_rejillas.nueva_rejilla();
        }
        else if (comando = "nuevo_patron") {
            Cjt_patrones.nuevo_patron();
        }
        else if (comando = "borrar_mensaje") {
            string idm;
            cin >> idm;
            Cjt_mensajes.borrar_mensaje(idm);
        }
        else if (comando = "listar_mensajes") {
            Cjt_mensajes.escribir();
        }
        else if (comando = "listar_rejillas") {
            Cjt_rejillas.escribir();
        }
        else if (comando = "listar_patrones") {
            Cjt_patrones.escrbir();
        }
        else if (comando = "codificar_rejilla") {
            string mensaje;
            int idr;
            Cjt_rejillas.codificar_rejilla(idr);
        }
        else if (comando = "codificar_guardado_rejilla") {
            string idm;
            int idr;
            cin >> idm >> idr;
            Cjt_rejillas.codificar_guardado_rejilla(idm,idr,cm);
        }
        else if (comando = "decodificar_rejilla") {
            int idr;
            cin >> idr;
            Cjt_rejillas.decodificar_rejilla(idr);
        }
        else if (comando = "codificar_patron") {
            int idp, b;
            cin >> idp >> b;
            Cjt_patrones.codificar_patron(idp, b); // TODO
        }
        else if (comando = "codificar_guardado_patron") {
            string idm;
            int idp, b;
            cin >> idm >> idp >> b;
            Cjt_patrones.codificar_guardado_patron(idm, idp, b); // TODO
        }
        else if (comando = "decodificar_patron") {
            int idp, b;
            cin >> idp >> b;
            Cjt_patrones.decodificar_patron(idp, b); // TODO
        }
    }
}
