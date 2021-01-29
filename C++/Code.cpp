#include <iostream>
using namespace std;

int pos = 0;
int angka = 10;
int counterx = 0;
string kombinasi;

int main()
{
    cout<<"==========================================================\n";
    cout<<"**********************************************************\n";
    cout<<"      RRRRRRRR      IIII   FFFFFFF  KKK    KK  IIII       \n";
    cout<<"       RRRRRRRR      II    FFFFFFF  KK   KK     II        \n";
    cout<<"       RRR   RRR     II    FFF      KK  KK      II        \n";
    cout<<"       RRR   RRR     II    FFFFFFF  KK KK       II        \n";
    cout<<"       RRRRRRRRR     II    FFFFFFF  KK  KK      II        \n";
    cout<<"       RRR    RRR    II    FFF      KK   KK     II        \n";
    cout<<"      RRRRR   RRRR  IIII  FFFFF     KKK    KK  IIII       \n";
    cout<<endl;
    cout<<"  *PROGRAM MENCARI BERAPA PERTUKARAN ARAH TOMBOL PUTAR*   \n";
    cout<<endl;
    cout<<"**********************************************************\n";
    cout<<"==========================================================\n";
    cout<<endl;
    cout << "Masukkan kombinasi angka (1 - 100 digit): ";

    cin >> kombinasi;
    if ((kombinasi.size() < 1) || (kombinasi.size() > 100))
    {
        cout << "Maaf kombinasi angka tidak sesuai ketentuan!" << endl;
        exit(0);
    }
    else
    {
        int arr_kombinasi[kombinasi.size()];
        for (int i = 0; i < kombinasi.size(); i++)
        {
            arr_kombinasi[i] = kombinasi[i] - '0';  //mengisi array
        }
    
        bool kanan = false, kiri = false, tempsaatini, temp;
        int counter = 0;
        for (int i = 0; i < kombinasi.size(); i++)
        {
            int stepkanan = 0, stepkiri = 0, kiritemp;
            while (true)    //menghitung perputaran ke kanan
            {
                stepkanan += 1;
                if (((pos + (stepkanan % angka)) % angka) == arr_kombinasi[i]) break;
            }
            kiritemp = pos;
    
            while (true)    //menghitung perputaran ke kiri
            {
                stepkiri += 1;
                if ((angka - abs(kiritemp - 1)) == arr_kombinasi[i]) break;
                kiritemp -= 1;
            }
            stepkanan %= angka;
            stepkiri %= angka;
            pos = arr_kombinasi[i];

            if (counter == 0)
            {
                if (stepkanan < stepkiri)
                {
                    kanan = true;
                    tempsaatini = kanan;
                };
            
                if (stepkanan > stepkiri)
                {
                    kiri = true;
                    tempsaatini = kiri;
                };
                temp = tempsaatini;
            }
            else
            {
                if (stepkanan < stepkiri)
                {
                    kanan = true;
                };

                if (stepkanan > stepkiri)
                {
                    kanan = false;
                };
                tempsaatini = kanan;

                if (temp != tempsaatini)
                {
                    temp = tempsaatini;
                    counterx += 1;
                }
            }
            counter += 1;
        }
    }
    cout << "Perubahan arah sebanyak : " << counterx << " kali" << endl;
    return 0;
}
