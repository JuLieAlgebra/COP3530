
#include <iostream>
using namespace std;

void christmas(int layers, int total, int mid, int radius){
    if( layers == 0){
        int i = 0;
        while (i < total/2){
            cout << ' ';
            i++;
        }
        cout << 'X' << endl;
        return;
    }
    if(layers == total){

        for(int l = 0; l < (mid-1); l++){
            cout << ' ';
        }
        cout << 'X';
    }
    else {
        cout << mid-radius << endl;
        cout << mid << endl;
        cout << radius << endl;
        int j = 0;
        while (j < (mid-radius)){
            cout << ' ';
            j++;
        }
        for(int k = (mid-radius); k < (mid+radius); k++){
            cout << 'X';
        }
    }
    cout << endl;
    christmas(layers = layers-1, total = total, mid = (layers-1)/2, radius = radius+1);
};


int main (){
    cout << (3)/2 << endl;
    int layers;
    cin >> layers;
    cout << "hello?" << endl;
    christmas(layers, layers, layers, 0);
    return 0;
};

