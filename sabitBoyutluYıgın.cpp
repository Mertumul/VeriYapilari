#include<iostream>
#include <string>
#include <iomanip>

using namespace std;
const int MAX=8;

class Yigin{

    private:
        int tepe;
        int veriler[];

    public:
        Yigin(){
            tepe=-1;

        }
        void ekle(int veri){
            if(tepe<MAX-1){
                tepe++;
                veriler[tepe]=veri;
            }
        }
        void cikar(){
            tepe--;

        }

        int getir(){
            if(tepe!=-1)
                return veriler[tepe];
            throw out_of_range("Yigin bos");


        }


        friend ostream &operator <<(ostream& os ,Yigin& yigin){


            for(int i=yigin.tepe;i>=0;i--){
                os<<"->"<<yigin.veriler[i]<<endl;
            }
            os<<endl;

            return os;
        }

        int yiginTepe(){
            return tepe;
        }

};

int main(){

Yigin *yigin=new Yigin();

yigin->ekle(15);
yigin->ekle(30);
yigin->ekle(45);
yigin->ekle(60);
yigin->ekle(75);
yigin->ekle(90);

cout<<*yigin;

for(int i=yigin->yiginTepe();i>=0;i--){

    cout<<"silinecek yigin ="<<yigin->getir()<<endl;
    yigin->cikar();

}

cout<<*yigin;



}
