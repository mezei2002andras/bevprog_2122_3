#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

#define ellenoriz(felt, pont) if (felt) pont++; else cerr << "Nem teljesul a feltetel a " << __LINE__<< ". sorban." <<endl;

/* Szabalyok:
    - csak az a beugró érvényes, amely nem tartalmaz semmilyen változtatást a main()-ben,
        és már nincs benne kommentezve semmi
    - az "ellenoriz"-en kívül nem tartalmaz #define sorokat, és azt sem szabad megváltoztatni
*/

const vector<int> honapok_napjai = {31,28,31,30,31,30,31,31,30,31,30,31}; // nem kötelező használni, segítségképpen megadunk egy ilyen tömböt

// Innentol

int negyzet(int n) {
    return n * n;
}

struct Mikor {
    int ev;
    int ho;
    int nap;
};

Mikor datum(int ev, int ho, int nap) {
    Mikor m;
    m.ev = ev;
    m.ho = ho;
    m.nap = nap;
    return m;
}

void leptet(Mikor &m) {
    m.nap++;
    if (m.nap > honapok_napjai[m.ho - 1]) {
        m.nap = 1;
        m.ho++;
        if (m.ho > 12) {
            m.ho = 1;
            m.ev++;
        }
    }
}

vector<int> rejtveny() {
    vector<int> result(10, 0);
    for (int i = 0; i < 5; ++i) {
        result[i] = -1 - rand() % 10;
        result[i + 5] = 1 + rand() % 10;
    }
    return result;
}

// Idaig

int main()
{
    int pont = 0;
    srand(time(0));

    int x = negyzet(negyzet(3));
    int y = rand()%10+1;
    ellenoriz(x==3*3*3*3 && negyzet(2*y)==4*negyzet(y), pont)

    Mikor m;
    m.ev = 1993;
    m.ho = 4;
    m.nap = 8;
    ellenoriz(m.ev == 1993 && m.nap == 8, pont)

    Mikor m2 = datum(1994, 2, 28);
    ellenoriz(m2.ev = 1994 && m2.nap == 28, pont)

    leptet(m);
    leptet(m2);
    ellenoriz(m.ev == 1993 && m.nap == 9 && m2.ho == 3 && m2.nap == 1, pont)

    vector<int> r = rejtveny();
    bool ok = r.size()==10;
    int sum=0;
    for (int i=0;i<10;i++) {
            sum+=r[i];
        int rand1 = rand()%10;
        if (rand1 < 5 && r[rand1] >= 0) {
            ok=false;
        }
        if (rand1 >= 5 && r[rand1] <= 0) {
            ok=false;
        }
    }
    if (sum!=0) ok=false;
    ellenoriz(ok, pont)

    cout << endl << pont << "/5 pont";
}
