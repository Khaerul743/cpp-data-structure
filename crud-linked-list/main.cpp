#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Node{
    int angka;
    Node* next;
};
void tampilkanNode(Node* &head){
    if(head == nullptr){
        cout<<"Linked list masih kosong"<<endl;
    }else{
        Node* cur = head;
        cout<<"List Data"<<endl;
        cout<<"=============="<<endl;
        cout<<"|     DATA    | \n";
        cout<<"=============="<<endl;
        while(cur != nullptr){
            cout<<left<<"|      "<<setw(7)<<cur->angka<<"|"<<endl;
            cur = cur->next;
        }
        cout<<"=============="<<endl;
    }
}
void insertNode(Node* &head,int &value,Node* &tail){
    Node* newNode = new Node();
    newNode->angka = value;
    if(head == nullptr){
        head = newNode;
        tail = head;
    }else{
        newNode->next = head;
        head = newNode;
    }
}
void removeNode(Node* &head,Node* &tail){
    if(tail == nullptr){
        cout<<"Linked list masih kosong"<<endl;
    }else if(head == tail){
        Node* del = head;
        head = nullptr;
        tail = nullptr;
        delete del;
    }
    else{
        Node* del = tail;
        Node* cur = head;
        while(cur->next != tail){
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete del;
        cout<<"Baris belakang berhasil dihapus."<<endl;
    }
}
void searchValue(Node* &head){
    if(head == nullptr){
        cout<<"Linked list masih kosong"<<endl;
    }else{
        vector<int>data;
        Node* cur = head;
        while(cur != nullptr){
            data.push_back(cur->angka);
            cur = cur->next;
        }  
        sort(data.begin(),data.end());
        cout<<"====================="<<endl;
        for(int i = 0;i<data.size();i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        cout<<"====================="<<endl;
        cout<<"Nilai terkecil = "<<data[0]<<endl;
        cout<<"Nilai terbesar = "<<data[data.size()-1]<<endl;
        cout<<"====================="<<endl;
    }
}
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int pilihan;
    do{
        clearScreen();
        cout<<"========================="<<endl;
        cout<<"   PROGRAM LINKED LIST\n";
        cout<<"========================="<<endl;
        cout<<"1. Tambahkan Data\n";
        cout<<"2. Hapus Data\n";
        cout<<"3. Tampilkan Data\n";
        cout<<"4. Nilai terbesar dan terkecil\n";
        cout<<"5. Exit\n";
        cout<<"========================="<<endl;
        cout<<"pilih (1-5) => ";
        cin>>pilihan;
        switch(pilihan){
            case 1:
                clearScreen();
                cout<<"==================\n";
                cout<<"   TAMBAH DATA\n";
                cout<<"==================\n";
                int value;
                cout<<"Masukan data baru => ";cin>>value;
                insertNode(head,value,tail);
                break;
            case 2:
                clearScreen();
                if(head == nullptr){
                    cout<<"Linked list masih kosong"<<endl;
                    system("pause");
                }else{
                    cout<<"==================\n";
                    cout<<"    HAPUS DATA\n";
                    cout<<"==================\n";
                    removeNode(head,tail);
                    system("pause");
                }
                break;
            case 3:
                clearScreen();
                if(head == nullptr){
                    cout<<"Linked list masih kosong"<<endl;
                    system("pause");
                }else{
                    tampilkanNode(head);
                    system("pause");
                }
                break;
            case 4:
                clearScreen();
                if(head == nullptr){
                    cout<<"Linked list masih kosong"<<endl;
                    system("pause");
                }else{
                    searchValue(head);
                    system("pause");
                }
                break;
            case 5:
                cout<<"Nama : KHAERUL LUTFI"<<endl;
                cout<<"NIM  : 41824010057"<<endl;
                break;
        }
    }while(pilihan != 5);
    return 0;
}