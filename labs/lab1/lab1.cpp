/*
lab1, Q2
Place n queens on an n × n chessboard so that no two queens attack each other by being in the
same column, row, or diagonal.
*/

#include <iostream>
using namespace std;

int main() 
{
    int n, i, j;
    int queen_i =0, queen_j =0;
    int pCm=0, nCm =0, C_m=0;
    int no_queen =0;
    int no_try =-1;

    cin >> n;

    for (;;)
    {
        for (i = 0; i<n; i++)
        {
            for (j = 0; j<n; j++)
            {
                if ( (i==0) && (no_try >=j))
                {
                    cout <<"0"<<" ";
                    continue;
                }

                else
                {
                    if (!((queen_i & (1<<i)) || (queen_j & (1<<j))))
                    {
                        if ( (i>j) && (!(pCm & (1<<(i-j)))) && !(C_m & (1<<(i+j))) )
                        {
                            cout <<1<<" ";
                            no_queen++;
                            queen_i |= (1<<i);
                            queen_j |= (1<<j);
                            pCm |= (1<<(i-j));
                            C_m |= (1<<(i+j));

                        }
                        else if ( (i<j) && !(nCm & (1<<(j-i))) && !(C_m & (1<<(i+j))) )
                        {
                            cout <<1<<" ";
                            no_queen++;
                            queen_i |= (1<<i);
                            queen_j |= (1<<j);
                            nCm |= (1<<(j-i));
                            C_m |= (1<<(i+j));

                        }
                        else if ((i==j) && !(pCm & (1<<(i-j))) && !(C_m & (1<<(i+j))) )
                        {
                            cout <<1<<" ";
                            no_queen++;
                            queen_i |= (1<<i);
                            queen_j |= (1<<j);
                            pCm |= (1<<(i-j));
                            C_m |= (1<<(i+j));

                        }
                        else
                        {
                            cout <<"0"<<" ";
                        }
                    }
                    else
                    {
                        cout <<"0"<<" ";
                    }
                }
            }
            cout <<endl;
        }
        if (no_queen == n)
        {
            cout <<"Try Succeeded";
            cout <<endl;
            break;
        }
        else
        {
            cout <<"Try Faild";
            cout <<endl;
            cout <<endl;

            no_queen =0;
            queen_i =0;
            queen_j =0;
            pCm=0;
            nCm =0;
            C_m=0;

            if (no_try == (n-2))
            {
                cout <<"Not Applicable";
                cout <<endl;
                break;
            }
            no_try++;
        }        
    }
    
    return 0;
}