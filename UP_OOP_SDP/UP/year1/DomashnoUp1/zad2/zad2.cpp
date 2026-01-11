#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int borovinki = 0, praskovi = 0, shipka = 0;
    int kodVid = 0;
    for(int i=0; i<N; i++){
        int vhod;
        cin>>vhod;
        switch(i%8){
            /*
            case 0:
                break;
            case 1:

                break;
            case 2:

                break;
            */
            case 3:
                kodVid = kodVid + (vhod*1000);
                break;
            case 4:

                kodVid = kodVid + (vhod*100);
                break;
            case 5:

                kodVid = kodVid + (vhod*10);
                break;
            case 6:

                kodVid = kodVid + (vhod*1);
                break;
            case 7:
                if (kodVid % 7 == 0){
                    borovinki++;
                }else{
                    if (kodVid % 13 == 0){
                        praskovi++;
                    }else{
                        if (kodVid % 17 == 0){
                            shipka++;
                        }
                    }
                }
                kodVid = 0;
                break;
            default:
                break;
        }
    }

    cout<<"Marmalad ot borovinki: "<<borovinki<<endl;
    cout<<"Marmalad ot praskovi: " <<praskovi<<endl;
    cout<<"Shipkov marmalad: : "<<shipka<<endl;
}
