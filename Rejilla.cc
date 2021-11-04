#include "Rejilla.hh"

Rejilla::Rejilla() {
    n = 0;
    k = 0;
    valida = false;
}

void Rejilla::insertar_huecos(const vector<ParInt>& original) {
    ParInt p;
    p = original[0];
}

void Rejilla::calcular_validez() {}


int Rejilla::consultar_n() const {
    return n;
}

int Rejilla::consultar_k() const {
    return k;
}

vector< ParInt > Rejilla::consultar_huecos(int giro) const {
    giro++;
    vector< ParInt > s;
    return s;
}

bool Rejilla::es_valida() const {
    return true;
}

void Rejilla::leer() {

}

void Rejilla::escribir() {

}
