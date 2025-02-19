#include <iostream>
#define MAX 8

using namespace std;

struct Queue{
    int head,tail,data[MAX];
}Q;

bool isFull(){
    return Q.tail == MAX;
}

bool isEmty(){
    return Q.tail == 0;
}

void printQueue(){
    if(isEmty()){
        cout<<"antrian kosong"<<endl;
    }else{
        cout<<"QUEUE : "<<endl;
        for(int i = Q.head;i<Q.tail;i++){
            cout<<Q.data[i] << ((Q.tail-1 == i) ? "" : ",");
        cout<<endl;
        }
    }
}

void enqueue(){
    if(isFull()){
        cout<<"antrian penuh!"<<endl;;
    }else{
        int data;
        cout<<"masukan data : ";cin>>data;
        Q.data[Q.tail] = data;
        Q.tail ++;
        cout<<"data ditambahkan \n";
        printQueue();
    }
}

void dequeue(){
    if(isEmty()){
        cout<<"antrian masih kosong."<<endl;
    }else{
        cout<<"mengambil data \""<<Q.data[Q.head]<<"\"...."<<endl;
        for(int i = Q.head;i<Q.tail;i++){
            Q.data[i] = Q.data[i+1];
            Q.tail--;
            printQueue;
        }
    }
}

int main(){
    int pilih;
    do{
        cout<<"====================="<<endl;
        cout<<"        MENU"<<endl;
        cout<<"====================="<<endl;
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Keluar\n";
        cin>>pilih;
        switch (pilih)
        {
        case 1:
            enqueue();
            break;
        
        case 2:
            dequeue();
            break;
        default:
            cout<<"pilihan tidak tersedia"<<endl;
            break;
        }
    }while(pilih != 3);
    return 0;
}