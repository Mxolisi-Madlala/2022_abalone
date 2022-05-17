#include "board.h"
#include "cell.h"
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdlib>
/*
#ifndef _SLP_CL_EG
   #define _SLP_CL_EG
   #define C(x) #x 
   #ifdef _WIN32
     	#define SLP(t) Sleep(t*1000)
     	#include <windows.h> 
     	#define CL C(cls)
   #endif
   #ifdef unix
      #define SLP(t) sleep(t)
      #include <unistd.h>
      #define CL C(clear)
   #endif
#endif */

struct moves{
    string l;//location
    int nmarbles, fd, md, d2e, mtype;//number of current player's marbles moving
    //int fd;//direction from leading marbles to following marbles
    //int md;//direction in which n marbles seek to move
    //int d2e;//distance from leading marble to the edge of the board in move direction
    //int mtype;//-1 broad-side 0-2 for in-line depending on how many opponent marbles are to be pushed
    bool scoreMove;//opponent marble to be pushed off the board?
    moves(const string& l,const int& nmarbles,const int& fd,const int& md,const int& d2e,const int& mtype,const bool& scoreMove);
    moves(const moves&);
};
double score(const moves&);
struct moveTNDPriority{//priority based on move types and distance to edge    
   inline bool operator()(const moves& a, const moves& b) {
       return score(a)<score(b);
   }     
}; 



class agent : board, cell{
protected:
    char symbol;
    vector<vector<int> > pmd;//potential move details.
    vector<moves> findMoves(const board&) const;
public:
    agent(const char&);
    char getSymbol()
        {
            return symbol;
        }
    virtual moves move(moves const* const,board)=0;//pure virtual function
};

class randAgent: public agent, board{
public:
    randAgent(const char&);
    moves move(moves const* const, board);
};
class distAgent: public agent, board{
public:
    distAgent(const char&);
    moves move(moves const* const,board);
};


//#endif /* AGENT_H */

