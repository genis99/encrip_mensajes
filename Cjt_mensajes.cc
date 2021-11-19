#include "Cjt_mensajes.hh"

void Cjt_mensajes::leer_msj(string& idm, string& m) const {
    cin >> idm;
    cin.ignore();
    getline(cin,m);
}

Cjt_mensajes::Cjt_mensajes() {}

void Cjt_mensajes::nuevo_mensaje() {
    string idm, mensaje;
    leer_msj(idm, mensaje);
    cout << ' ' << idm << endl;
    pair<map<string,string>::iterator, bool> ins = mensajes.insert(make_pair(idm,mensaje));
    if (!ins.second) cout << "error: ya existe un mensaje con ese identificador";
    else cout << mensajes.size();
    cout << endl;
}

void Cjt_mensajes::borrar_mensaje(string idm) {
    if (mensajes.erase(idm) == 0) cout << "ERROR EL MENSAJE NO SE ENCUENTRA EN EL CONJUNTO"; // TODO cambiar
    else cout << mensajes.size();
    cout << endl;
}
    
string Cjt_mensajes::consultar_mensaje_idm(string idm) const {
    map<string,string>::const_iterator it = mensajes.find(idm);
    if (it == mensajes.end()) cout << "ERROR MENSAJE NO ENCONTRADO" << endl; // TODO cambiar
    else return it->second;
    return "";
}

void Cjt_mensajes::leer() {
    int n;
    cin >> n;
    string idm, mensaje;
    for (int i = 0; i < n; ++i) {
        leer_msj(idm,mensaje);
        cout << idm << ' ' << mensaje << endl; // TODO borrar
        mensajes[idm] = mensaje;
    }
}

void Cjt_mensajes::escribir() const {
    map<string,string>::const_iterator it = mensajes.begin();
    while (it != mensajes.end()) {
        cout << it->first << endl;
        cout << '"' << it->second << '"' << endl;
        ++it;
    }
}
