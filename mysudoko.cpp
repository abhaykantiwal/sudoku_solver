#include<iostream>
using namespace std;
#include<vector>
#include<ctime>

//function to check whether the value (from 1 to 9) can be placed at a particular index or not
bool canbeplaced(vector<vector<int>> &board,int row,int column,int value){
    for(int i=0;i<board[0].size();i++){
        //checking whether there is an element in the same row 
        if(board[row][i]==value){
            return false;
        }
        //checking whether there is an element in the same column
        if(board[i][column]==value){
            return false;
        }
        //checking whether there is an element is the same grid
        if(board[3*(row/3)+i/3][3*(column/3)+i%3]==value){
            return false;
        }
    }
    return true;
}

//this function is solving the given sudoku
bool solve(vector<vector<int>>& sudoku){
    int n = sudoku[0].size();
    for(int row =0;row<n ; row++){
        for(int column=0;column<n;column++){
           if(sudoku[row][column]==0){
                for(int value = 1;value<=9;value++){     
                    if(canbeplaced(sudoku,row,column,value)){
                        sudoku[row][column] = value;
                        //to make the recursive call 
                        if(solve(sudoku)){
                            return true;
                        }
                        else{
                            sudoku[row][column]=0;
                        }
                    }
                }
                return false;                          //none of the value can be put at that index 
            } 
        }
    }
    return true;
}

int main(){
    vector<vector<int>> sudoku(9,vector<int>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    //measuring time along with solving the sudoku
    clock_t start=clock();
    bool valid=solve(sudoku);
    clock_t end = clock();
    double time_taken = static_cast<double>(end-start)/CLOCKS_PER_SEC;
    if(valid){
        cout<<"\n";
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    if(!valid){
        cout<<"The given matrix is an invalid matrix";
    }
    cout<<"Time taken to solve sudoku = "<<time_taken<<" seconds";
}
