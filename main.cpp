#include <iostream>

using namespace std;

    void imprimirDigitos (int n){
        int a,b,c,d,e;
        a = n/10000;
        b = (n - a*10000)/1000;
        c = (n - a*10000 - b*1000)/100;
        d = (n - a*10000 - b*1000 - c*100)/10;
        e = n - a*10000 - b*1000 - c*100 - d*10;
        cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << endl;
    }

    int contarDigitos (int m){
        int cont = 1;
        int me = 10;
        while (m > me){
            cont++;
            me = me*10;
        }
        return m;
    }

    bool palindromo (int s){
        int a,b,c,d,e;
        a = s/10000;
        b = (s - a*10000)/1000;
        c = (s - a*10000 - b*1000)/100;
        d = (s - a*10000 - b*1000 - c*100)/10;
        e = s - a*10000 - b*1000 - c*100 - d*10;
        if ((a==e) and (b==d))
            true;
        else
            false;
    }

    int fibo (int n){
        int a = 1;
        int b = 1;
        int m;

        if (n%2==0)
            m = 0;
        else
            m = 1;

        while (m<n){
            if (n%2!=0){
                a = a+b;
                n--;
            }
            else{
                b = b+a;
                n--;
            }
        }
        if (a>b)
            return a;
        else
            return b;
    }

    bool num (char n){
        int a = static_cast<int>(n);
        if (a>=48 && a<=57){
            return true;
        }
        else{
            return false;
        }
    }

    int letra (char n){
        int a = static_cast<int>(n);
        if ((a>=65 && a<=90) || (a>=97 && a<=122)) return a;
        else return -1;
    }

    char Mm (int b){
        return static_cast <char> (b+32);
    }

    char mM (int b){
        return static_cast <char> (b-32);
    }

    void endme(char n){
        int s = letra(n);
        if (s != -1){
            if (s<91)
                cout << (Mm(s)) << endl;
            else
                cout <<(mM(s)) << endl;
        }
        else
            cout << "no es numero";
        }


int main()
{
    int a;
    int b;
    int c;
    int d;
    char e;
    char f;

    cout << "Ingrese 5 digitos: ";
    cin >> a;
    imprimirDigitos(a);
    cout << endl;

    cout << "Ingrese un numero: ";
    cin >> b;
    contarDigitos(b);
    cout << endl;

    cout << "Ingrese 5 digitos: ";
    cin >> c;
    palindromo(c);
    cout << endl;

    cout << "Ingrese un numero: ";
    cin >> d;
    fibo(d);
    cout << endl;

    cout << "Ingrese un caracter: ";
    cin >> e;
    num(e);
    cout << endl;

    cout << "Ingrese un caracter: ";
    cin >> f;
    endme(f);
    cout << endl;

    return 0;
}
