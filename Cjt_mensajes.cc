#include "Cjt_mensajes.hh"

Cjt_mensajes::Cjt_mensajes() {}

void Cjt_mensajes::nuevo_mensaje() {
    string idm, mensaje;
    cin >> idm >> mensaje;
    mensajes[idm] = mensaje;
}

void Cjt_mensajes::borrar_mensaje(string idm) {
    if (mensajes.erase(idm) == 0) cout << "ERROR EL MENSAJE NO SE ENCUENTRA EN EL CONJUNTO";
    else cout << mensajes.size();
    cout << endl;
}
    
string Cjt_mensajes::consultar_mensaje_idm(string idm) const {
    map<string,string>::const_iterator it = mensajes.find(idm);
    if (it == mensajes.end()) cout << "ERROR MENSAJE NO ENCONTRADO" << endl;
    else return it->second;
    return "";
}

void Cjt_mensajes::leer() {
    int n;
    cin >> n;
    string idm, mensaje;
    for (int i = 0; i < n; ++i) {
        cin >> idm;
        cin.ignore();
        getline(cin,mensaje);
        cout << idm << ' ' << mensaje << endl;
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
