#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <conio.h>

int score = 0;
bool playable = true;
using namespace std;

class Playground{
    int size;
    public:
    Playground(){
       size =0;
    }
    void createPlayground(int i){
        if(i >=3){
            size = i;
            int Playground[size][size] ;
        }else{
            cout <<"Size not allowed"<<endl;
        }
    }


    
};

void generate(int arr[4][4]){
    srand(time(0));
    for(int i =0;i<4;i++){
        for(int j =0;i<4;j++){
            if(arr[i][j]==0){
                cout<<arr[rand()%4][rand()%4] ;
            }
        }
    }
}

void moveleft(int arr[4][4]){
   for(int i =0;i<4;i++){
    for(int j =3;j>0;j--){
        if(  arr[i][j-1]==arr[i][j]){
            arr[i][j-1] += arr[i][j];
            score += arr[i][j-1];
            arr[i][j] = 0;
        }
        if(arr[i][j-1] ==0){
            int temp = arr[i][j];
            arr[i][j] = arr[i][j-1];
            arr[i][j-1]= temp;
        }
    }
   }
   for(int a =0;a<4;a++){
    if(arr[a][3] == 0){
        arr[a][3] =2;
        break;
    }
   }
}
void moveright(int arr[4][4]){
   for(int i =0;i<4;i++){
    for(int j =0;j<3;j++){
        if(  arr[i][j+1]==arr[i][j]){
            arr[i][j+1] += arr[i][j];
            score +=arr[i][j+1];
            arr[i][j] = 0;
        }
        if(arr[i][j+1] ==0){
            arr[i][j+1] = arr[i][j];
            arr[i][j] =0;
        }
    }
   }
   for(int a =0;a<4;a++){
    if(arr[a][0]==0){
        arr[a][0] = 2;
        break;
    }
    }
   
}
void moveup(int arr[4][4]){
   for(int j=3;j>=0;j--){
    for(int i =3;i>=0;i--){
        if(arr[i-1][j]==arr[i][j]){
            arr[i-1][j] += arr[i][j];
            score += arr[i-1][j];
            arr[i][j]=0;
        }
        if(arr[i-1][j] ==0 ){
            arr[i-1][j] = arr[i][j];
            arr[i][j] =0;
        }
    }
   }
   for(int a =0;a<4;a++){
    if(arr[3][a]==0){
        arr[3][a] =2;
        break;
    }
   }
}
void movedown(int arr[4][4]){
   for(int j =0;j<4;j++){
    for(int i =0;i<4;i++){
        if(arr[i+1][j]==arr[i][j]){
            arr[i+1][j] += arr[i][j];
            score += arr[i+1][j];
            arr[i][j]=0;
        }
        if(arr[i+1][j]==0){
            int temp = arr[i][j];
            arr[i][j] = arr[i+1][j];
            arr[i+1][j] = temp;
        }
    }
   }
   for(int a =0;a<4;a++){
    if(arr[0][a]==0){
        arr[0][a] =2;
        break;
    }
   }
}
int check(int arr[4][4]){
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            // if((arr[i][j] != arr[i+1][j] && arr[i+1][j]!=0) 
            // && (arr[i][j] != arr[i][j+1] && arr[i][j+1] != 0)
            // && (arr[i-1][j] != arr[i][j] && arr[i-1][j]!=0) 
            // && (arr[i][j-1] != arr[i][j]&& arr[i][j-1])!=0){ 
            //         cout << arr[i][j]<<endl;
            //         cout << "You lost!" << endl;
            //         playable = false;
            //         return 0;
            // }
            // else{
            //     return 1;
            // }
            if(arr[i][j] ==2048){
                cout<<"You won!"<<endl;
                playable = false;
            }
        }
    }
}
void print(int arr[4][4]){
      for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            cout<<setw(5)<<left<<arr[i][j]<<"  ";
        }
        cout<<"\n"<<"\n";
    }
}
void Restart(int arr[4][4]){
    memset(arr,0,sizeof(arr));
    // playground[0][0] =4;
    // playground[0][1] =4;
    arr[0][3] =2;
    score = 0;

}
void play(int arr[4][4]){
    char x;
    cin >> x;
    if(x =='l'){
        moveleft(arr);
    }
    else if(x == 'r'){
        moveright(arr);
    }
    else if(x == 'u'){
        moveup(arr);
    }
    else if(x =='d'){
        movedown(arr);
    }
    else if(x == 'S'){
        playable = false;
        cout<<
        "Game stopped"<<endl;
    }
    else if(x == 'R'){
        Restart(arr);
    }
    else{
        cout<<"Wrong letter,try again"<<endl;
    }
}

int main(){
    int playground[4][4];char ans;
    memset(playground,0,sizeof(playground));
    // playground[0][0] =4;
    // playground[0][1] =4;
    playground[0][3] =2;
    cout<<"Ready to play?Type c if yes or any letter if no(lowercase)"<<endl;
    cin >> ans;
    if(ans == 'c'){
        while(playable){
           check(playground);
           print(playground);
           cout << "Score:"<<score<<endl;
           cout << "Type l to move left"
           <<endl<<"     r to move right"
           <<endl<<"     u to move up "
           <<endl<<"     d to move down"
           <<endl<<"     R to restart the game"
           <<endl;
           cout <<"Type S to stop the game"<<endl;
           play(playground);
           system("cls");
        }
    }else{
        return 0;
    }
    // generate(playground);
    return 0;
}