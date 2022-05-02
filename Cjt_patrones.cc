#include "Cjt_patrones.hh"

Cjt_patrones::Cjt_patrones() {}

Patron Cjt_patrones::consultar_patron_idp(int idp) const {
    return vpatr[idp-1];
}

void Cjt_patrones::nuevo_patron() {
    Patron p;
    p.leer();
    
}

