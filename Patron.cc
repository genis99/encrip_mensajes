#include "Patron.hh"

void read_bintree_int(BinTree<int>& a) {
    int x;
    cin >> x;
    if (x != -1){
        BinTree<int> l;
        read_bintree_int(l);
        BinTree<int> r;
        read_bintree_int(r);
        a = BinTree<int>(x,l,r);
    }
}

void write_bintree_int(const BinTree<int> &a) {
    if (not a.empty()) {
        cout << '(';
        int x = a.value();
        cout << " " << x;
        write_bintree_int(a.left()); 
        write_bintree_int(a.right());
        cout << ')';
    }
    else cout << "()";
}

Patron::Patron() {}

void Patron::leer() {
    read_bintree_int(pat);
}

void Patron::escribir() {
    write_bintree_int(pat);
}
