#include <iostream>

using namespace std;
const int R = 10;
int N=10;
int rozmarKolejki = 0;
int kopiec[R]={4,1,3,2,15,9,10,13,7,8};

void utworz_kopiec();
void sortowanie_kopcowe();

void zatapianie(int i);
void wynurzanie(int i);
void wyswietl();

int main(){ //po każdej operacji należy wyświetlić stan kolejki

    wyswietl();
    cout<<endl;
    utworz_kopiec();

    wyswietl();
    sortowanie_kopcowe();
    cout<<"Posortowana:"<<endl;
    wyswietl();

return 0;
}
void sortowanie_kopcowe()
{
    int i=N-1;
    for(i;i>=1;i--)
    {
        swap(kopiec[i],kopiec[0]);
        N--;
        zatapianie(0);
    }
}
void utworz_kopiec()
{
    int i=(N-1)/2;
    for(i;i>=0;i--)
    {
        zatapianie(i);
    }
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
void wyswietl()
{
    for(int i =0;i<R;i++)
    {
        cout<<kopiec[i]<<", ";
    }
    cout<<endl;
}
