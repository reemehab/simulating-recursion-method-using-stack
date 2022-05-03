#include <iostream>
#include <stack>
using namespace  std;
int F(int n)
{
    if(n<=1)
        return 1;
    int a=n+F(n-1);
    int b=n*F(n/2);
    int c=n-2-(a+b)%2;
    int d=F(c);
    return a+b+d;
}

struct SnapShotStruct{
    int a , b , c,n,stage;
};

int F_iterative(int n)
{   int retVal = 0;  // initialize with default returning value
    stack<SnapShotStruct> snapshotStack;
    SnapShotStruct currentSnapshot;
    int for_a , for_b  , d;
    currentSnapshot.n=n;
    currentSnapshot.a=0;
    currentSnapshot.b=0;
    currentSnapshot.c=0;
    currentSnapshot.stage=10;
    snapshotStack.push(currentSnapshot);
    while(!snapshotStack.empty())
    {   currentSnapshot=snapshotStack.top();
        snapshotStack.pop();
        switch(currentSnapshot.stage)
        {
            case 10:
            {
                if(currentSnapshot.n <=1)
                { // The base case
                    retVal=1;
                    for_a=1;
                    for_b=0;
                    continue;

                }
                else
                {
                    currentSnapshot.stage = 20;
                    snapshotStack.push(currentSnapshot);
                    SnapShotStruct newSnapshot;
                    newSnapshot.n= currentSnapshot.n-1;
                    newSnapshot.a=0;
                    newSnapshot.b=0;
                    newSnapshot.c=0;
                    newSnapshot.stage=10;
                    snapshotStack.push(newSnapshot);
                }
                break;
            }

            case 20:
            //compute a
            {
                currentSnapshot.a=currentSnapshot.n+for_a;
                currentSnapshot.stage=30;
                snapshotStack.push(currentSnapshot);
                break;
            }
            case 30:
            //compute b
                {
                    if(currentSnapshot.b%2==0){
                        for_b++;
                    }
                    SnapShotStruct newCall;
                    snapshotStack.push(currentSnapshot);
                    newCall.n = for_b;
                    newCall.stage = 10;
                    snapshotStack.push(newCall);

                    currentSnapshot.b=currentSnapshot.n*retVal;
                    currentSnapshot.c=currentSnapshot.n-2-(currentSnapshot.a+currentSnapshot.b)%2;
                    currentSnapshot.stage=40;
                    snapshotStack.push(currentSnapshot);

                }
                break;
            case 40:// compute d
            {
                    if(currentSnapshot.c<=1){
                       d=1;

                    }
                else {
                        SnapShotStruct newCall;
                        newCall.n = currentSnapshot.c;
                        newCall.stage = 10;
                        snapshotStack.push(currentSnapshot);
                        snapshotStack.push(newCall);
                    }

                retVal=currentSnapshot.a+currentSnapshot.b+d;
                for_a=retVal;
                break;
        }

        }
    }
    return retVal;
}
int main() {

    /*for (int i = 1; i <20 ; i++) {
        cout<<F(i)<<endl;
        cout<<F_iterative(i)<<endl ;
    }*/

    cout<<F_iterative(5)<<endl ;

    return 0;
}
