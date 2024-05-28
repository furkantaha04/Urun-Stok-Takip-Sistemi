#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Ürün struct'ı
struct Urun {
    string ad;
    double fiyat;
    int stokMiktari;
};

// Ürün bulma fonksiyonu
Urun* urunBul(vector<Urun>& urunler, const string& urunAdi) {
    for (size_t i = 0; i < urunler.size(); ++i) {
        if (urunler[i].ad == urunAdi) {
            return &urunler[i];
        }
    }
    return nullptr; // Ürün bulunamadı
}

// Ürün güncelleme fonksiyonu
void urunGuncelle(vector<Urun>& urunler, const string& urunAdi, double yeniFiyat, int yeniStokMiktari) {
    Urun* urun = urunBul(urunler, urunAdi);
    if (urun != nullptr) {
        urun->fiyat = yeniFiyat;
        urun->stokMiktari = yeniStokMiktari;
        cout << urunAdi << " isimli urunun fiyati ve stok miktari guncellendi." << endl;
    }
    else {
        cout << "Urun bulunamadi!" << endl;
    }
}

// Ürün silme fonksiyonu
void urunSil(vector<Urun>& urunler, const string& urunAdi) {
    for (auto it = urunler.begin(); it != urunler.end(); ++it) {
        if (it->ad == urunAdi) {
            urunler.erase(it);
            cout << urunAdi << " isimli urun sistemden silindi." << endl;
            return;
        }
    }
    cout << "Urun bulunamadi!" << endl;
}

// Ürünleri listeleme fonksiyonu
void urunleriListele(const vector<Urun>& urunler) {
    cout << "Sistemde kayitli olan urunler:" << endl;
    for (const auto& urun : urunler) {
        cout << "Ad: " << urun.ad << ", Fiyat: " << urun.fiyat << ", Stok Miktari: " << urun.stokMiktari << endl;
    }
}

int main() {
    vector<Urun> urunListesi = {
        {"Bilgisayar", 3000.0, 10},
        {"Telefon", 2000.0, 15}
    };

    // Ürünleri listelemek için
    urunleriListele(urunListesi);

    // Ürün güncelleme
    urunGuncelle(urunListesi, "Bilgisayar", 3500.0, 8);

    // Ürünleri listelemek için
    urunleriListele(urunListesi);

    // Ürün silme
    urunSil(urunListesi, "Telefon");

    // Ürünleri listelemek için
    urunleriListele(urunListesi);

    return 0;
}
