#include <iostream>
#include <string>
using namespace std;
// Furkan KOCA 221030910028
class TicTacToe
{
private:
    int tablo[3][3];
    string name1;
    int oyuncu1;
    int oyuncu2;
    string name2;

public:
    TicTacToe();
    void OyuncuAta()
    {
        int secim;
        cout << "Kacinci oyuncu olmak istersiniz? (1-2)" << endl;
        cin >> secim;
        oyuncu1 = secim;
        if (secim == 1)
            oyuncu2 = 2;
        else
            oyuncu2 = 1;
        cout << oyuncu1 << " secen oyuncu ismi:" << endl;
        cin >> name1;
        cout << oyuncu2 << " secen oyuncu ismi:" << endl;
        cin >> name2;
    }
    void Tablo()
    {

        cout << "     |     |     " << endl;
        cout << "  " << tablo[0][0] << "  |  " << tablo[0][1] << "  |  " << tablo[0][2] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;

        cout << "  " << tablo[1][0] << "  |  " << tablo[1][1] << "  |  " << tablo[1][2] << endl;

        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;

        cout << "  " << tablo[2][0] << "  |  " << tablo[2][1] << "  |  " << tablo[2][2] << endl;

        cout << "     |     |     " << endl
             << endl;
    }
    void oyna()
    {
        int secilen1, secilen2, secilen3, secilen4;
        do
        {
            cout << "Oynama sirasi " << name1 << endl;
            Tablo();
            cout<<"Oynamak istedigin satir ve sutunu gir: ";
            cin>>secilen1>>secilen2;
            if (tablo[secilen1 - 1][secilen2 - 1] == 1 || tablo[secilen1 - 1][secilen2 - 1] == 2)
            {
                cout << "Hata onceden oynanan yere oynandi. Programi tekrar baslatin" << endl;
                break;
            }

            tablo[secilen1 - 1][secilen2 - 1] = oyuncu1;
            if (Kontrol())
            {
                cout << name1 << " kazandi" << endl;
                break;
            }
            cout<<endl;
            cout<<endl;
            cout << "Oynama sirasi " << name2 << endl;
            Tablo();
           cout<<"Oynamak istedigin satir ve sutunu gir: ";
            cin>>secilen3>>secilen4;
            if (tablo[secilen3 - 1][secilen4 - 1] == 1 || tablo[secilen3 - 1][secilen4 - 1] == 2)
            {
                cout << "Hata onceden oynanan yere oynandı tekrar baslatın" << endl;
                break;
            }
            tablo[secilen3 - 1][secilen4 - 1] = oyuncu2;
            if (Kontrol())
            {
                cout << name2 << " kazandi" << endl;
                break;
            }
            cout<<endl;
            cout<<endl;
        } while (true);
        Tablo();
    }
    int Kontrol()
    {
        if (tablo[0][0] == tablo[0][1] && tablo[0][1] == tablo[0][2] && tablo[0][0] != 0 && tablo[0][1] != 0 && tablo[0][2])
            return 1;
        else if (tablo[1][0] == tablo[1][1] && tablo[1][1] == tablo[1][2] && tablo[1][0] != 0 && tablo[1][1] != 0 && tablo[1][2])
            return 1;
        else if (tablo[2][0] == tablo[2][1] && tablo[2][1] == tablo[2][2] && tablo[2][0] != 0 && tablo[2][1] != 0 && tablo[2][2])
            return 1;
        else if (tablo[0][0] == tablo[1][0] && tablo[1][0] == tablo[2][0] && tablo[0][0] != 0 && tablo[1][0] != 0 && tablo[2][0])
            return 1;
        else if (tablo[0][1] == tablo[1][1] && tablo[1][1] == tablo[2][1] && tablo[0][1] != 0 && tablo[1][1] != 0 && tablo[2][1])
            return 1;
        else if (tablo[0][2] == tablo[1][2] && tablo[1][2] == tablo[2][2] && tablo[0][2] != 0 && tablo[1][2] != 0 && tablo[2][2])
            return 1;
        else if (tablo[0][0] == tablo[1][1] && tablo[1][1] == tablo[2][2] && tablo[0][0] != 0 && tablo[1][1] != 0 && tablo[2][2])
            return 1;
        else if (tablo[0][2] == tablo[1][1] && tablo[1][1] == tablo[2][0] && tablo[0][2] != 0 && tablo[1][1] != 0 && tablo[2][0])
            return 1;
        else
            return 0;
    }
};
TicTacToe::TicTacToe()
{
    tablo[0][0] = 0;
    tablo[0][1] = 0;
    tablo[0][2] = 0;

    tablo[1][0] = 0;
    tablo[1][1] = 0;
    tablo[1][2] = 0;

    tablo[2][0] = 0;
    tablo[2][1] = 0;
    tablo[2][2] = 0;
}

int main()
{
    cout << "Tic Tac Toe oyununa HOSGELDIINN!!" << endl;
    TicTacToe oyun;
    oyun.OyuncuAta();
    oyun.oyna();
}
