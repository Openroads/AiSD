#include <iostream>

using namespace std;
const int R = 5;
int N=R;
int rozmiarKolejki = 0;
int kopiec[R]={0};

void zatapianie(int i);
void wynurzanie(int i );

void insert(int i);
int extract();

void wyswietl();

int main(){ //po każdej operacji należy wyświetlić stan kolejki

    insert(12);insert(15);insert(10);insert(3); insert(5); insert(4); insert(1111);
    wyswietl();
    extract();  wyswietl();
    extract();  wyswietl();
    extract();  wyswietl();
    extract();  wyswietl();
    extract();  wyswietl();
    extract();  wyswietl();
    insert(7);insert(5);//insert(9);insert(11);
    wyswietl();
    extract();extract();extract();extract();extract();
    extract();
    wyswietl();

    return 0;
}


void zatapianie(int i){
    int wiekszy;
    int lewy=2*i+1;
    int prawy=2*i+2;
    if(lewy<N && kopiec[lewy] > kopiec[i]){
        wiekszy = lewy;
    }else{
        wiekszy=i;
    }
    if(prawy<N && kopiec[prawy] > kopiec[wiekszy])
    {
       wiekszy = prawy;
    }
    if(wiekszy != i){
        swap(kopiec[i],kopiec[wiekszy]);
        zatapianie(wiekszy);
    }
}
void wynurzanie(int i )
{
    if(i>0){
    int ojciec = (i-1)/2;
    if(kopiec[ojciec] < kopiec[i])
    {
        swap(kopiec[ojciec],kopiec[i]);
         wynurzanie(ojciec);
    }
    }
}


void insert(int i){
    if(rozmiarKolejki<N){
        kopiec[rozmiarKolejki]=i;
        wynurzanie(rozmiarKolejki);
        rozmiarKolejki++;
    }
    else
    {
        cout<<"Kolejka przepełniona, nie udało się dodać elementu: "<<i<<endl;
    }
}
void wyswietl()
{
    for(int i =0;i<R;i++)
    {
        cout<<kopiec[i]<<", ";
    }
    cout<<endl;
}

int extract(){
   if(rozmiarKolejki>0)
   {
        int x = kopiec[0];
        cout<<"Pobieram "<< x <<endl;
        kopiec[0]=0;            // 0 niech oznacza ze nie ma nic
        swap(kopiec[0],kopiec[rozmiarKolejki]);
        zatapianie(0);
        rozmiarKolejki--;
        return x;
   }
   else
   {
        cout<<"Kolejka pusta"<<endl;
        return -1;
   }
}
