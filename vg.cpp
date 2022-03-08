#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
double readDouble (const char prompt[]);
int readInt(const char prompt[]);
// Creates a struct
struct Videogames
{
enum {MAX_CHAR_LEN=100};
char title [200];
double Numsales;
char plat[200];
char date [200];
char dev [200];
char publisher[200];
bool isValid;
Videogames();

};

// Default constructor
const int MAX_GAME=200;
Videogames::Videogames() {
    for (int x = 0; x< 200; x++){
      title[x] = '\0';
      plat[x] = '\0';
      dev[x] = '\0';
      publisher[x] = '\0';
      date[x] = '\0';

      
    }
Numsales = 0.0;
  
}
// Read the game file
Videogames readgame(ifstream &inFile){
  
    Videogames game;
    inFile.get(game.title,(Videogames::MAX_CHAR_LEN),';');
    inFile.ignore(100,';');
   inFile >>(game.Numsales);
    inFile.ignore(100,';');
    inFile.get(game.plat,(Videogames::MAX_CHAR_LEN),';');
    inFile.ignore(100,';');
  inFile >>(game.date);
  inFile.ignore(100,';');
    inFile.get(game.dev,(Videogames::MAX_CHAR_LEN),';');
    inFile.ignore(100,';');
     inFile.get(game.publisher,(Videogames::MAX_CHAR_LEN),'\n');
    inFile.ignore(100,'\n');

    
    
   
    
    
    

    return(game);
}
// validates a double
double readDouble (const char prompt[]){ 
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;

}
// validates an Int
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

// Reads from a specific file
int readgames(Videogames game[]) {
    ifstream gameFile("videogames.txt");
    int numgame = 0;
    
    while(gameFile.peek() != EOF && numgame < MAX_GAME) {
        game[numgame] = readgame(gameFile);
        numgame++;
    }
    return numgame;
    
}

// prints a single game

void printV(ostream &out, Videogames print){
    out << print.title << ";";
    out << print.Numsales << ";";
    out << print.plat << ";";
  out<<fixed;
  out << print.date << ";";
  out << print.dev << ";";
    out << print.publisher<< endl;
}
// prints all of the games

void printArrayToScreen(Videogames array[], int numExamples) {
  // cout << "here" << endl; 
    for (int index = 0; index < numExamples; index++) {
        cout << "Index " << index << ": ";
        printV(cout, array[index]);
    }
}


// adds a game

void addgame (Videogames game[], int x){
   
cout << "Enter the details of the game" << endl;
cout << "Game Name :";
//cin.ignore(100, '\n');
cin.getline(game[x].title,MAX_GAME);

game[x].Numsales = readDouble("Game Sales : ");
      cin.ignore(100, '\n');
cout << "Game Platform :";
cin.getline(game[x].plat,MAX_GAME);
 cout << "Game Date :";
cin.getline(game[x].date,MAX_GAME);
 cout << "Game Developers:";
cin.getline(game[x].dev,MAX_GAME);
 cout << "Game publisher :";
cin.getline(game[x].publisher,MAX_GAME);

  
}

// removes a game

void removegame(Videogames games[], int x, int end){

  for (int z = x; z < end ; z++){
 games[z] = games[z+1];
    
    }
  
  }

// prints by developer

 void printO (Videogames games[], int num){
   string Eorigin = "";
  cout <<"Enter Developer: ";
  getline(cin,Eorigin);


    for (int x = 0; x < num; x++){
   
      if (games[x].dev == Eorigin){
      
          printV(cout, games[x]);
        cout << endl;
}
}
}

//saves the changes to the file

void printArrayToFile(const char fileName[], Videogames array[], int numExamples) {
  //cout << "here" << endl; 
  ofstream outFile(fileName);
    for (int index = 0; index < numExamples; index++) {
        printV(outFile, array[index]);
    }
}
// main function

int main() {

    Videogames Array[MAX_GAME];
    int nums = readgames(Array);
  int ind = 0;
  string in = "";
  int numb = 0;
   readgames(Array);
  while (numb != -1){
    cout << '\n';
    cout << "Enter 1 to remove game" << endl;
    cout << "Enter 2 to add game" << endl;
     cout << "Enter 3 to display games by developers " << endl;
     cout << "Enter 4 to display games" << endl;
    cout << "Enter 5 to save changes to the file" << endl;
    cout << "Enter 6 to reload datatbase" << endl;
     numb = readInt( "Enter -1 to leave");
     cout << endl;
     cin.ignore(100,'\n');
  
 // menu
 if (nums < MAX_GAME && numb == 2){
  addgame(Array, nums);
  nums++;
  }
  if (nums < MAX_GAME && numb ==1){
    cout << "Enter index to remove";
    cin >> ind;
removegame(Array, ind , nums);
  nums--;
  
}  
  if (nums < MAX_GAME && numb == 3){
    printO(Array,nums);

}
    if (nums < MAX_GAME && numb == 4){
printArrayToScreen(Array,nums);
      }

    if (nums < MAX_GAME && numb == 6){
  readgames(Array);
      nums = readgames(Array);
      }
  if (nums < MAX_GAME && numb == 5){
  printArrayToFile("VG2.txt",Array, nums);
      }
    
    }
}
  