#include "Cjt_rejillas.hh"

Cjt_rejillas::Cjt_rejillas() {
    nr = 0;
}

Rejilla Cjt_rejillas::consultar_rejilla_idr(int idr) const {
    return vrej[idr];
}


void Cjt_rejillas::nueva_rejilla() {
    if (r.leer()) {
        ++nr;
        vrej[nr-1] = r;
    }
    else
        cout << "TODO IMPRIMIR ERROR" << endl;
    // TODO imprimir nº rejillas
}


void Cjt_rejillas::codificar_rejilla(int idr) const {
    string mensaje;
    cin >> mensaje;
    vrej[idr-1].codificar(mensaje);
}


Cjt_rejillas::


Cjt_rejillas::


Cjt_rejillas::
