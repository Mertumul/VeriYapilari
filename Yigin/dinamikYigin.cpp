#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

class dinamkiYigin{

    private:
        int tepe;
        int kapasite;
        int * veriler;
        void genislet(int boyut){
            int * yeniAlan=new int[kapasite+boyut];
            for(int i=0;i<=tepe;i++){
                yeniAlan[i]=veriler[i];
            }

            if(veriler)
                delete[] veriler;
            veriler=yeniAlan;
            kapasite +=boyut;
        }

    public:
        dinamkiYigin(){
            tepe=-1;
            kapasite=0;
            veriler=0;
            genislet(5);
            

        }
        void ekle(int veri){
            if(tepe==kapasite-1)
                genislet(kapasite);
            
            tepe++;
            veriler[tepe]=veri;
        }
        void cikar(){
            tepe--;

        }

        int getir(){
            if(tepe!=-1)
                return veriler[tepe];
            throw out_of_range("Yigin bos");

        }

        ~dinamkiYigin(){
            delete[] veriler;
        }


        friend ostream &operator <<(ostream& os ,dinamkiYigin& yigin){


            for(int i=yigin.tepe;i>=0;i--){
                os<<"->"<<yigin.veriler[i]<<endl;
            }
            os<<endl;

            return os;
        }

        int yiginTepe(){
            return tepe;
        }

        int kapasiteBul(){
            return kapasite;
        }

};

int main(){

dinamkiYigin *yigin=new dinamkiYigin();

cout<<"kapasite:"<<yigin->kapasiteBul()<<endl;

yigin->ekle(15);
yigin->ekle(30);
yigin->ekle(45);
yigin->ekle(60);
yigin->ekle(75);

cout<<*yigin;

yigin->ekle(90);
yigin->ekle(105);
cout<<" yeni kapasite:"<<yigin->kapasiteBul()<<endl;

cout<<*yigin;


for(int i=0;i<16;i++){

    yigin->ekle(i*11);
}

cout<<*yigin;

/*
for(int i=yigin->yiginTepe();i>=0;i--){

    cout<<"silinecek yigin ="<<yigin->getir()<<endl;
    yigin->cikar();

}

cout<<*yigin;
*/


}
