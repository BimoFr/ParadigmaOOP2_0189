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