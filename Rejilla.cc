#include "Rejilla.hh"

Rejilla::Rejilla() {
    n = 0;
    k = 0;
    huecos = vector<vector<pair<int,int>>>(4);
}

bool Rejilla::comp_pair_int(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
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
        girado[i].first = n - v[i].second + 1;
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
//             cout << "CCCCC" << endl;
            pos = huecos[i][j];
            if (huecos_leidos[pos.first-1][pos.second-1]) valida = false;
            else huecos_leidos[pos.first-1][pos.second-1] = true;
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

bool Rejilla::leer() { // TODO aquesta funcio fa massa coses ?
    cin >> n >> k;
    vector<pair<int,int>> sin_giros(k);
    for (int i = 0; i < k; ++i) {
        int p,s;
        cin >> p >> s;
        sin_giros[i] = make_pair(p,s);
    }
    if (validez_dimension()) {
        sort(sin_giros.begin(),sin_giros.end(),comp_pair_int);
//         cout << "AAAAA" << endl;
        insertar_huecos(sin_giros);
//         for (int i = 0; i < 4; ++i) {
//             cout << "giro" << i << endl;
//             for (int j = 0; j < k; ++j) {
//                 cout << huecos[i][j].first << ' ' << huecos[i][j].second << endl;
//             }
//         }
//         cout << "BBBBB" << endl;
        if(validez_huecos()) return true;
        else {
            cout << "error: la rejilla con sus giros no cubre todas las posiciones N x N" << endl;
            return false;
        }
    }
    cout << "error: dimensiones incorrectas de la rejilla" << endl;
    return false;
}

void Rejilla::escribir() const {
    for (int i = 0; i < 4; ++i) {
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
    // Crear matriz n * n
    vector < vector<char> > bloque;
    // Rellenar matriz
    int i, j, l;
    i = j = l = 0;
    while (l < msj.length()) {
        bloque = vector <vector<char> >(n, vector<char>(n, ' '));
        i = 0;
        while (i < 4) {
            j = 0;
            while (j < k and l < msj.length()) {
                bloque[huecos[i][j].first-1][huecos[i][j].second-1] = msj[l];
                ++l;
                ++j;
            }
            ++i;
        }
        // Leer la matriz
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                cout << bloque[a][b];
            }
        }
    }
}

void Rejilla::decodificar(string msj) const {
    // Crear matriz n * n
    vector < vector<char> > bloque(n,vector<char>(n));
    // Rellenar matriz
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < msj.length(); ++j) {
                bloque[i][j] = msj[i*n+j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << bloque[i][j];
            }
        }
}
