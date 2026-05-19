#include <iostream>
#include <string>
using namespace std;

class RekeningBank
{
protected:
    string nama;
    double saldo;

public:
    RekeningBank(string n, double s)
    {
        nama = n;
        saldo = s;
    }

    virtual void potongAdmin() = 0;

    void info()
    {
        cout << nama << " - Saldo Akhir: Rp " << saldo << endl;
    }
};

class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(string n, double s) : RekeningBank(n, s) {}

    void potongAdmin() override
    {

    }
};

class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(string n, double s) : RekeningBank(n, s) {}

    void potongAdmin() override
    {
        saldo -= 15000;
    }
};

class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(string n, double s) : RekeningBank(n, s) {}

    void potongAdmin() override
    {
        if (saldo <= 10000000)
        {
            saldo -= 50000;
        }
    }
};

int main()
{
    // Membuat objek nasabah
    RekeningSyariah r1("Ahmad (Syariah)", 5000000);
    RekeningKonvensional r2("Budi (Konvensional)", 2500000);
    RekeningPremium r3("Citra (Premium >10Jt)", 15000000);
    RekeningPremium r4("Dewi (Premium <10Jt)", 8000000);

    // Array pointer base class
    RekeningBank *daftarRekening[] = {&r1, &r2, &r3, &r4};

    cout << "=== HASIL POTONGAN AKHIR BULAN ===" << endl;

    for (int i = 0; i < 4; i++)
    {
        daftarRekening[i]->potongAdmin();
        daftarRekening[i]->info();
    }

    return 0;
}