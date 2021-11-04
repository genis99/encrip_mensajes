#include "Cjt_mensajes.hh"

Cjt_mensajes::Cjt_mensajes() {}

void Cjt_mensajes::nuevo_mensaje(string m) {
    m = m + ' ';
}

string Cjt_mensajes::consultar_mensaje_idm(string idm) const {
    return idm;
}

void Cjt_mensajes::leer_conjunto() {}

void Cjt_mensajes::escribir() const {}
