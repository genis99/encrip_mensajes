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
//     Cjt_patrones cp;
//     cp.leer();
    string comando;
    cin >> comando;
    while (comando != "fin") {
        // TODO funcio leer comando per a separar l'string del int
        if (comando == "nuevo_mensaje" or comando == "nm") {
            cout << '#' << comando << endl;
            cm.nuevo_mensaje();
        }
        else if (comando == "nueva_rejilla" or comando == "nr") {
            cout << '#' << comando << endl;
            cr.nueva_rejilla();
        }
        else if (comando == "nuevo_patron" or comando == "np") {
            cout << '#' << comando << endl;
//             cp.nuevo_patron();
        }
        else if (comando == "borra_mensaje" or comando == "bm") {
            cout << '#' << comando << endl;
            string idm;
            cin >> idm;
            cm.borrar_mensaje(idm);
        }
        else if (comando == "listar_mensajes" or comando == "lm") {
            cout << '#' << comando << endl;
            cm.escribir();
        }
        else if (comando == "listar_rejillas" or comando == "lr") {
            cout << '#' << comando << endl;
            cr.escribir();
        }
        else if (comando == "listar_patrones" or comando == "lp") {
            cout << '#' << comando << endl;
//             cp.escrbir();
        }
        else if (comando == "codificar_rejilla" or comando == "cr") {
            
            int idr;
            cin >> idr;
            cout << '#' << comando << ' ' << idr << endl;
            cr.codificar_rejilla(idr);
        }
        else if (comando == "codificar_guardado_rejilla" or comando == "cgr") {
            cout << '#' << comando << endl;
            string idm;
            int idr;
            cin >> idm >> idr;
            cr.codificar_guardado_rejilla(idm,idr,cm);
        }
        else if (comando == "decodificar_rejilla" or comando == "dr") {
            int idr;
            cin >> idr;
            cout << '#' << comando << ' ' << idr << endl;
            cr.decodificar_rejilla(idr);
        }
        else if (comando == "codificar_patron" or comando == "cp") {
            cout << '#' << comando << endl;
            int idp, b;
            cin >> idp >> b;
//             cp.codificar_patron(idp, b); // TODO
        }
        else if (comando == "codificar_guardado_patron" or comando == "cgp") {
            cout << '#' << comando << endl;
            string idm;
            int idp, b;
            cin >> idm >> idp >> b;
//             cp.codificar_guardado_patron(idm, idp, b); // TODO
        }
        else if (comando == "decodificar_patron" or comando == "dp") {
            cout << '#' << comando << endl;
            int idp, b;
            cin >> idp >> b;
//             cp.decodificar_patron(idp, b); // TODO
        }
    }
}
