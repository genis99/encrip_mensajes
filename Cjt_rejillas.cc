#include "Cjt_rejillas.hh"

Cjt_rejillas::Cjt_rejillas() {}

Rejilla Cjt_rejillas::consultar_rejilla_idr(int idr) const {
    return vrej[idr];
}


void Cjt_rejillas::nueva_rejilla() {
    cout << endl;
    Rejilla r;
    if (r.leer()) {
        vrej.push_back(r);
        cout << vrej.size() << endl;
    }
}


void Cjt_rejillas::codificar_rejilla(int idr, string mensaje) const {
    if (idr <= vrej.size() and idr > 0){
        cout << '"';
        vrej[idr-1].codificar(mensaje);
        cout << '"' << endl;
    }
    else cout << "error: la rejilla no existe" << endl;
}


void Cjt_rejillas::codificar_guardado_rejilla(string idm, int idr, const Cjt_mensajes& cm) const {
    if (idr <= vrej.size() and idr > 0) {
        string mensaje = cm.consultar_mensaje_idm(idm);
        if (mensaje != "") {
            cout << '"';
            vrej[idr-1].codificar(cm.consultar_mensaje_idm(idm));
            cout << '"' << endl;
        }
    }
    else cout << "error: la rejilla no existe" << endl;
}


void Cjt_rejillas::decodificar_rejilla(int idr) const {
    string mensaje;
    cin >> mensaje;
    if (idr > vrej.size() or idr <= 0) 
        cout << "error: la rejilla no existe" << endl;
    else  vrej[idr-1].decodificar(mensaje);
}

void Cjt_rejillas::leer() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Rejilla r;
        r.leer();
        vrej.push_back(r);
    }
}

void Cjt_rejillas::escribir() const {
    for (int i = 0; i < vrej.size(); ++i) {
        cout << "Rejilla " << i+1 << ':' << endl;
        cout << vrej[i].consultar_n() << ' ' << vrej[i].consultar_k() << endl;
        vrej[i].escribir();
    }
}
