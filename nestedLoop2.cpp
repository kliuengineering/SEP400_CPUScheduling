#include <iostream>
using namespace std;
int main() 
{
    cout << "nestedLoop2: performing 3 dimensional nested loops"<<endl;
    for(int i=0; i<=30000; i+=1000) 
    {
        for(int j=0; j<i; ++j) 
        {
            for(int k=0; k<i; ++k) 
            {
                int l=j*k;//do something
            }
        }
    }
    cout << "nestedLoop2: DONE"<<endl;
    return 0;
}