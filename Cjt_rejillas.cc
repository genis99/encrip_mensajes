#include "Cjt_rejillas.hh"

Cjt_rejillas::Cjt_rejillas() {
    nr = 0;
}

Rejilla Cjt_rejillas::consultar_rejilla_idr(int idr) const {
    return vrej[idr];
}


void Cjt_rejillas::nueva_rejilla() {
    Rejilla r;
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
    if (idr <= nr and idr > 0) vrej[idr-1].codificar(mensaje);
    else cout << "error: la rejilla no existe" << endl;
}


void Cjt_rejillas::codificar_guardado_rejilla(string idm, int idr, const Cjt_mensajes& cm) const {
    if (idr <= nr and idr > 0) 
        vrej[idr-1].codificar(cm.consultar_mensaje_idm(idm));
    else cout << "error: la rejilla no existe" << endl;
}


void Cjt_rejillas::decodificar_rejilla(int idr) const {
    string mensaje;
    cin >> mensaje;
    if (idr > nr or idr <= 0) 
        cout << "error: la rejilla no existe" << endl;
    else  vrej[idr-1].decodificar(mensaje);
}

void Cjt_rejillas::leer() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "rejilla" << endl;
        ++nr;
        Rejilla r;
        r.leer();
        vrej.push_back(r);
    }
}

void Cjt_rejillas::escribir() const {
    
}
