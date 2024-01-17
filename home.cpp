#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <conio.h>

int score = 0;
int count =0;
bool playable = true;
using namespace std;
int error = 0;
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

// void generate(int arr[4][4]){
//     srand(time(0));
//     for(int i =0;i<4;i++){
//         for(int j =0;i<4;j++){
//             if(arr[i][j]==0){
//                 cout<<arr[rand()%4][rand()%4] ;
//             }
//         }
//     }
// }

void moveleft(int arr[4][4]){
   for(int i =0;i<4;i++){
       int pcount = 0;
     for(int a =0;a<4;a++){
        if(arr[i][a]==0){
            continue;
        }else{
            for(int j =a;j>0;j--){
        if((arr[i][j-1]==arr[i][j])&&pcount ==0){
            arr[i][j-1] += arr[i][j];
            score += arr[i][j-1];
            arr[i][j] = 0;
            pcount = 1;
        }
        if(arr[i][j-1] ==0){
            int temp = arr[i][j];
            arr[i][j] = arr[i][j-1];
            arr[i][j-1]= temp;
        }
    }
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
    int pcount = 0;
    for(int a =3;a>=0;a--){
        if(arr[i][a]==0){
            continue;
        }else{
            for(int j =a;j<3;j++){
              if(arr[i][j+1]==arr[i][j]&&pcount ==0){
              arr[i][j+1] += arr[i][j];
              score +=arr[i][j+1];
               arr[i][j] = 0;
               pcount =1;
              }
        if(arr[i][j+1] ==0){
            arr[i][j+1] = arr[i][j];
            arr[i][j] =0;
        }
    }

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
      int pcount =0;
      for(int a =0;a<4;a++){
        
        if(arr[a][j]==0){
            continue;
        }
        else{
             for(int i =a;i>=0;i--){
        if(arr[i-1][j]==arr[i][j]&&pcount ==0){
            arr[i-1][j] += arr[i][j];
            score += arr[i-1][j];
            arr[i][j]=0;
            pcount =1;
        }
        if(arr[i-1][j] ==0 ){
            arr[i-1][j] = arr[i][j];
            arr[i][j] =0;
        }
    }
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
   for(int j =3;j>=0;j--){
   int pcount =0;
      for(int a =3;a>=0;a--){
        
        if(arr[a][j]==0){
            continue;
        }else{
            for(int i =a;i<4;i++){
        if(arr[i+1][j]==arr[i][j]&&pcount ==0){
            arr[i+1][j] += arr[i][j];
            score += arr[i+1][j];
            arr[i][j]=0;
            pcount=1;
        }
        if(arr[i+1][j]==0){
           arr[i+1][j] =arr[i][j];
           arr[i][j] =0;
        }
    }
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
    count =0;
    for(int i =0;i<4;i++){
        for(int j =0;j<3;j++){
            if(arr[i][j]==0){
                break;
            }
            
            if(arr[i][j] != arr[i+1][j] 
            && arr[i][j] != arr[i][j+1] 
            && arr[i-1][j] != arr[i][j]
            && arr[i][j-1] != arr[i][j]){ 
                   
                    count ++;
                    // cout << "You lost!" << endl;
                    // playable = false;
                    // return 0;
            }
           
            if(arr[i][j] ==2048){
                cout<<"You won!"<<endl;

                playable = false;
            }
          
        }
    }
    if(count == 12){
            cout << "You lost!" << endl;
                playable = false;

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
    if(x =='a'){
        moveleft(arr);
    }
    else if(x == 'd'){
        moveright(arr);
    }
    else if(x == 'w'){
        moveup(arr);
    }
    else if(x =='s'){
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
    int playground[4][4];
    char ans;
    memset(playground,0,sizeof(playground));
    
    playground[3][1] =4;
    cout<<"How to play:2048 is played on a plain 4x4 grid, with numbered tiles that slide when a player moves them using the four arrow keys.\n"
    <<"Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid.\n"
    <<"If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles that collided.\n"
    <<"When the player has no legal moves(there are no empty spaces and no adjacent tiles with the same value), the game ends. \n"
    <<"A scoreboard on the upper-right keeps track of the user's score.\n \n \n";
   
    cout<<"Ready to play?Type c if yes or any letter if no(lowercase)"<<endl;
    cin >> ans;
    getch();
    system("cls");
    if(ans == 'c'){
        while(playable){
           
           print(playground);
           cout << "Score:"<<score<<endl;
           cout << "Type a to move left"
           <<endl<<"     d to move right"
           <<endl<<"     w to move up "
           <<endl<<"     s to move down"
           <<endl<<"     R to restart the game"
           <<endl;
           cout <<"Type S to stop the game"<<endl;
           play(playground);
           check(playground);
           getch();
           system("cls");
        }
    }else{
        cout<<"You choose not to play"<<endl;
        return 0;
    }
    // generate(playground);
    return 0;
}