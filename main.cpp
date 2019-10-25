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

    int pali(char *cad){
        int a=0;
        char *fin=cad + cad_tam(cad)-1;
        while(fin>=cad){
            if (*fin==*cad)
                a+=1;
            else
                return 0;
            fin--;
            cad++;
        }
        return a;
    }

    /*int rec_pali(char *cad,int a=0){
        if (cad_tam(cad)==1)
            return 1;
        if (cad_tam(cad)==2){
            char *fin=cad + cad_tam(cad)-1;
            if(*cad==*fin)
                return 1;
            else{
                a=0;
                return 0;
            }
        }
        else{
            char *fin=cad + cad_tam(cad)-1;
            if (*cad==*fin){
                a+=1;
                return a+rec_pali(cad-1,a++);
            }
            else{
                a=0;
                return 0;
            }
        }
    }*/

    int rec_pali(char *ini, char *fin){
        if (ini==fin)
            return 1;
        if(*ini!=*fin)
            return 0;
        rec_pali(++ini,--fin);
    }
    int call_rec_pali(char *cad){
        char *fin=cad+cad_tam(cad)-1;
        return rec_pali(cad,fin);
    }

int main()
{
    char cad[]="luzul";
    cout<<cad_tam(cad)<<endl;
    cout<<rec_tam(cad)<<endl;
    inver(cad);
    cout<<cad<<endl;
    rec_inver(cad);
    cout<<cad<<endl;
    if (pali(cad))
        cout<<"Es palindrome"<<endl;
    else
        cout<<"No es palindrome"<<endl;

    if (call_rec_pali(cad))
        cout<<"Es palindrome"<<endl;
    else
        cout<<"No es palindrome"<<endl;

    return 0;
}
