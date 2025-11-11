#include<bits/stdc++.h>
using namespace std;


bool issafe(int col,int row,vector<string>&board,int n){
    for(int r=0;r<n;r++){
        if(r!=row&&board[r][col]=='Q')return false;
    }
    for(int c=0;c<n;c++){
        if(c!=col&&board[row][c]=='Q')return false;
    }

    int r=row+1,c=col+1;
    while(r<n&&c<n){
        if(board[r][c]=='Q')return false;
        r++;
        c++;
    }

    r=row-1;
    c=col-1;
    while(r>=0&&c>=0){
        if(board[r][c]=='Q')return false;
        r--;
        c--;
    }

    r=row+1;
    c=col-1;
    while(r<n&&c>=0){
        if(board[r][c]=='Q')return false;
        r++;
        c--;
    }
    
    r=row-1;
    c=col+1;
    while(r>=0&&c<n){
        if(board[r][c]=='Q')return false;
        r--;
        c++;
    }
    return true;
}



void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    
    int f=0;
    for(int row=0;row<n;row++){
        if(board[row][col]=='Q'){
            f=1;
            break;
        }
    }
    if(f==1){
        solve(col+1,ans,board,n);
        return;
    }

    for(int row=0;row<n;row++){
        if(issafe(col,row,board,n)){
            board[row][col]='Q';
            solve(col+1,ans,board,n);
            board[row][col]='.';
        }
    }
}


int main(){

    int n;
    cout<<"Enter n : ";
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)board[i]=s;
    cout<<"Enter row and col for 1st Q : ";
    int r,c;
    cin>>r>>c;
    if(r>=0&&r<n&&c>=0&&c<n){
        board[r][c]='Q';
        solve(0,ans,board,n);
        if(ans.size()==0){
            cout<<"No combinations present "<<endl;
            return 0;
        }

        for(int i=0;i<ans.size();i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(ans[i][j][k]=='Q'){
                        cout<<"Q"<<" ";
                    }
                    else{
                        cout<<"_"<<" ";
                    }
                }
                cout<<endl;
            }
            cout<<"\n\n";
            cout<<"---------------------------------"<<endl;
        }
    }
    else{
        cout<<"Invalid index !!!!!! "<<endl;
    }
    return 0;
}







