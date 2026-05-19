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