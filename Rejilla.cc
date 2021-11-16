#include "Rejilla.hh"

Rejilla::Rejilla() {
    n = 0;
    k = 0;
    huecos = vector<vector<pair<int,int>>>(4);
}

bool Rejilla::comp_pair_int(pair<int,int> a, pair<int,int> b) {
    if (a.first > b.first) return true;
    return a.second > b.second;
}

void Rejilla::insertar_huecos(const vector<pair<int,int>>& original) {
    huecos[0] = original;
    vector<pair<int,int>> vaux;
    vaux = girar_huecos(original);
    huecos[1] = vaux;
    vaux = girar_huecos(vaux);
    huecos[2] = vaux;
    vaux = girar_huecos(vaux);
    huecos[3] = vaux;
}

vector<pair<int,int>> Rejilla::girar_huecos(const vector<pair<int,int>>& v) {
    int vSize = v.size();
    vector <pair<int,int>> girado(vSize);
    for (int i = 0; i < vSize; ++i) {
        girado[i].first = vSize - v[i].second + 1;
        girado[i].second = v[i].first;
    }
    sort(girado.begin(),girado.end(),comp_pair_int);
    return girado;
}

bool Rejilla::validez_dimension() {
    return n * n == 4 * k;
}

bool Rejilla::validez_huecos() {
    vector < vector<bool> > huecos_leidos(n,vector<bool>(n,false));
    bool valida = true;
    for (int i = 0; i < 4 and valida; ++i) {
        for (int j = 0; j < k and valida; ++j) {
            pair<int,int> pos;
            pos = huecos[i][j];
            if (huecos_leidos[pos.first][pos.second]) valida = false;
            else huecos_leidos[pos.first][pos.second] = true;
        }
    }
    return valida;
}

int Rejilla::consultar_n() const {
    return n;
}

int Rejilla::consultar_k() const {
    return k;
}

bool Rejilla::leer() {
    cin >> n >> k;
    cout << "dentro rejilla" << endl;
    vector<pair<int,int>> sin_giros(k);
    for (int i = 0; i < k; ++i) {
        int p,s;
        cin >> p >> s;
        sin_giros[p] = make_pair(p,s);
    }
    if (validez_dimension()) {
        sort(sin_giros.begin(),sin_giros.end(),comp_pair_int);
        insertar_huecos(sin_giros);
        return validez_huecos();
    }
    return false;
}

void Rejilla::escribir() const {
    for (int i = 0; i < 4; ++i) {
        cout << "Rejilla " << i + 1 << ':' << endl;
        for (int j = 0; j < k - 1; ++j) {
            cout << '(' << huecos[i][j].first << ','
                << huecos[i][j].second << ") ";
        }
        cout << '(' << huecos[i][k-1].first << ','
                << huecos[i][k-1].second << ')';
        cout << endl;
    }
}

void Rejilla::codificar(string msj) const {
    cout << msj;
}

void Rejilla::decodificar(string msj) const {
    cout << msj;
}
