/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: MSCS
 *
 * Created on 12 March 2020, 8:38 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "board.h"
#include "cell.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int userSelect;
    cout << "choose your marbles " <<endl;
    cout << "Enter 1 for 0 and 2 for @ marbles: ";
    cin >> userSelect;
    switch (userSelect)
    {
    case 1: 
        if(argc==2){
            board abalone;
            string ibs(abalone);
            cout<<"Initial Abalone board state:"<<endl;
            cout<<ibs<<endl;        
            ifstream log(argv[1]);//sequence of game moves
            string l;
            int n, fd, md;
            while(log>>l>>n>>fd>>md){
                cout<<"Move: "<<l<<" "<<n<<" "<<fd<<" "<<md;
                
                
                if(abalone.executeMove(l,n, fd, md)){
                    string nbs(abalone);
                    cout<<" - Next Abalone board state:"<<endl;
                    cout<<nbs<<endl;
                }
                else{
                    cout<<" - Invalid move!"<<endl;
                }
            }    
            return 0;
        }
        return -1;
    break;

    case 2:
        if(argc==2){
            board abalone;
            string ibs(abalone);
            cout<<"Initial Abalone board state:"<<endl;
            cout<<ibs<<endl;        
            ifstream log(argv[1]);//sequence of game moves
            string l;
            int n, fd, md;
            while(log>>l>>n>>fd>>md){
                cout<<"Move: "<<l<<" "<<n<<" "<<fd<<" "<<md;
                
                
                if(abalone.executeMove(l,n, fd, md)){
                    string nbs(abalone);
                    cout<<" - Next Abalone board state:"<<endl;
                    cout<<nbs<<endl;
                }
                else{
                    cout<<" - Invalid move!"<<endl;
                }
            }    
            return 0;
        }
        return -1;
        break;
    default:
        cout << "user score: ";
    }
}
