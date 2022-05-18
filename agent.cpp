#include "agent.h"

agent::agent(const char &agent) : symbol(agent)
{
    for(int numbMarbles = 1; numbMarbles < 4; numbMarbles++)
    {
        //create 6 moves for numbMarbles = 1;
        for(int fd = 0; fd < 6; fd++)
        {
            if(numbMarbles == 1)
            {
                vector<int> tv;
                tv.push_back(numbMarbles);
                tv.push_back(fd);
                tv.push_back(getAdjacentIndex(fd));
                pmd.push_back(tv);

            }
            else{
                //create 60 moves for numbMarbles 2,3
                for(int md=0; md < 6; md++)
                {
                    if(md == fd)
                    {
                        //do nothing
                    }
                    else{
                        vector<int> tv;
                        tv.push_back(numbMarbles);
                        tv.push_back(fd);
                        tv.push_back(md);
                        pmd.push_back(tv);
                    }
                }

            }
        }
    }
}

vector<moves> agent::findMoves(const board& bod) const
{
    vector<moves> mv;
    map<string, cell*> cells = bod.cells;
}