#include "Ej1.h"

int main(){ 
    vector<vector<int>> a = create_matrix(3); 
    print_matrix(3, a); 
    return 0; 
}

vector<vector<int>> create_matrix(int n){ 
    vector<vector<int>> matrix(n,vector<int>(n,0)); 
    int numb = 1;
    for(int i =0; i<n; i++){ 
        for(int j =0; j<n ;j++){ 
            matrix[i][j] = numb; 
            numb +=1 ; 
        }
    }
    return matrix; 
}


void print_matrix(int n, vector<vector<int>> matrix){ 
    int row = n-1;
    int colum= n-1; 

    for(int i=0; i<n*n ; i++){ 
        if (colum == -1){ 
            colum = n-1; 
            row -=1; 
            cout<<endl;
        }
        cout<<matrix[row][colum]<<" "; 
        colum -=1; 
    }
    cout<<endl;
}