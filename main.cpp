#include <iostream>

using namespace std;

    int cad_tam(char *cad){
        int cont=0;
        while(*cad++!='\0')
            cont++;
        return cont;
    }

    int rec_tam(char *cad){
        if(*cad=='\0')
            return 0;
        else
            return 1+rec_tam(++cad);
    }

    void inver(char *cad){
        char *ini=cad;
        char *fin=cad + cad_tam(cad)-1;
        int me=cad_tam(cad)/2;
        for (int i=0;i<me;i++){
            int c=*ini;
            *ini=*fin;
            *fin=c;
            fin--;
            ini++;
        }
    }

    void rec_inver(char *cad,int i=0){
        char *fin=cad + cad_tam(cad)-1-i;
        if(fin<=cad)
            return ;
        int c=*cad;
        *cad=*fin;
        *fin=c;
        return rec_inver(++cad,++i);
    }

    bool pali(char *cad){
        char *fin=cad + cad_tam(cad)-1;
        while(fin-->=cad++){
            if (*fin==*cad)
                return true;
            else
                return false;
        }
    }

int main()
{
    char cad[]="luz azul";
    cout<<cad_tam(cad)<<endl;
    cout<<rec_tam(cad)<<endl;
    inver(cad);
    cout<<cad<<endl;
    rec_inver(cad);
    cout<<cad<<endl;
    if (pali(cad)==1)
        cout<<"Es palindrome"<<endl;
    else
        cout<<"No es palindrome"<<endl;

    return 0;
}
