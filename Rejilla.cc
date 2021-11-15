#include "Rejilla.hh"

Rejilla::Rejilla() {
    n = 0;
    k = 0;
    valida = false;
}

void Rejilla::insertar_huecos(const vector<pair<int,int>>& original) {
    pair<int,int> p;
    p = original[0];
}

void Rejilla::calcular_validez() {}


int Rejilla::consultar_n() const {
    return n;
}

int Rejilla::consultar_k() const {
    return k;
}

bool Rejilla::es_valida() const {
    return true;
}

void Rejilla::leer() {

}

void Rejilla::escribir() {

}
