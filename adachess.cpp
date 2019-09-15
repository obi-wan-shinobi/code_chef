#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int>> pawn;  //Vector of touples that'll store the positions of pawns
int N;
vector<tuple<int,int,char>> move(int**,int,int);               //Function for killing and moving pawns on the board
int main()
{
  int T;          //Test cases
  cin>>T;
  long int sum=0;     //Sum of N^2 should not exceed 10^5
  while(T>0)
  {
    int N;
    cin>>N;
    if(N>100 || N<1)
      return 0;
    sum+=N*N;
    if(sum>pow(10,5))
      return 0;

    ::N=N;                      //Assigning global variable from local scope

    int **chess;              //Creating the board
    chess = new int*[N];
    for(int i=0; i<N; i++)
      chess[i]=new int[N];


    int size = 0;

    while(size<N)
    {
      string line;
      cin>>line;              //Read the positions of pawns
      for(int i=0; i<line.length(); i++)
      {
        if(line[i]=='O')
        {
          chess[size][i] = 1;             //If pawn, assign 1.
          pawn.push_back(make_tuple(size,i));     //Storing the location of pawns in the tuple and pushing it into the vector
        }
        else
          chess[size][i] = 0;           //Else assign 0
      }
      size++;
    }
    cout<<"\n";

    vector<tuple<int,int,char>> *endf;
    endf = new vector<tuple<int,int,char>>[pawn.size()];
    for(int i=0; i<pawn.size();i++)
      endf[i] = move(chess, pawn.size(),i);//Call to the function to kill and move the pawns

    vector<tuple<int,int,char>> final;
    final = endf[0];
    for(int i=0; i<pawn.size();i++)
      if(endf[i].size() < final.size())
        final = endf[i];
    cout<<final.size()<<endl;
    for(auto i=final.begin();i!= final.end();i++)
    {
      cout<<get<0>(*i)<<" "<<get<1>(*i)<<" "<<get<2>(*i)<<endl;
    }
    final.clear();        //Clearing the vector
    pawn.clear();        //Clearing the vector
    T--;
    cout<<"\n";
  }
}

vector<tuple<int,int,char>> move(int **temp,int size,int index)
{
  int **kill;
  vector<tuple<int,int,char>> endf;
  if(size>=0)               //Recursion until vector is empty
  {
    kill = new int*[N];             //Creating a new chessboard
    for(int i=0; i<N; i++)
    {
      kill[i]=new int[N];
      for(int j=0; j<N; j++)
        kill[i][j] = temp[i][j];
    }
    int i=index;
    do
    {
      int row=get<0>(pawn[i]), col=get<1>(pawn[i]);     //Getting the row and col number of last pawn from the vector

      //Checking if pawn has any diagonal neighbour

      if(col>0 && row>0 && temp[row-1][col-1] == 1)
      {
        kill[row][col] = 0;
        kill[row-1][col-1] = 1;
        endf.push_back(make_tuple(row+1,col+1,'L'));
      }
      else if(col<N-1 && row>0 && temp[row-1][col+1] == 1)
      {
        kill[row][col] = 0;
        kill[row-1][col+1] = 1;
        endf.push_back(make_tuple(row+1,col+1,'R'));
      }
      //move(kill, pawn.size());       //Recursive call to the function to move all pawns
      i = (i+1)%(pawn.size());

      temp = kill;
    }while(i != index);

    return endf;
  }
}
