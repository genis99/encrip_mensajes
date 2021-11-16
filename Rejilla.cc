#include "Rejilla.hh"

Rejilla::Rejilla() {
    n = 0;
    k = 0;
    huecos = vector<vector<pair<int,int>>>(4);
}

void Rejilla::insertar_huecos(const vector<pair<int,int>>& original) {
    huecos[0] = original;
    pair<int,int> p;
    p = original[0];
}

vector<pair<int,int>> Rejilla::girar_huecos(const vector<pair<int,int>>& v) {
    int vSize = v.size();
    vector <pair<int,int>> girado(vSize);
    for (int i = 0; i < vSize; ++i) {
        girado[i].first = vSize - v[i].second + 1;
        girado[i].second = v[i].first;
    }
    return girado;
}

bool Rejilla::calcular_validez() {
    return true;
}


int Rejilla::consultar_n() const {
    return n;
}

int Rejilla::consultar_k() const {
    return k;
}

bool Rejilla::leer() {
    cin >> n >> k;
    vector<pair<int,int>> sin_giros(k);
    for (int i = 0; i < k; ++i) {
        int p,s;
        cin >> p >> s;
        sin_giros[i] = make_pair(p,s);
    }
    insertar_huecos(sin_giros);
    return calcular_validez();
}

void Rejilla::escribir() {

}
