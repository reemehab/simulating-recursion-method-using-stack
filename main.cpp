#include <iostream>
#include<stack>
using namespace std;
int F(int n)
{
    if (n <= 1) return 1;
    int a = n + F(n - 1);
    int b = n * F(n / 2);
    int c = n - 2 - (a + b) % 2;
    int d = F(c);
    return a + b + d;
}

// a struct called snapshot to hold a , b, c, n , address of the next instruction
struct SnapShot
{
    int a, b, c, n, address;
};

int F_iterative(int n)
{
    int retVal = 0;  // initialize with default returning value
    stack<SnapShot> snapshotStack; // intializing stack of type SnapShot
    SnapShot currentSnapshot; // creating an instance of type SnapShot to be pushed in the Stack as the first call
    currentSnapshot.n=n;     // intializig the instance's n with the n coming from the actual parammeter
    currentSnapshot.a=0;    // intializing the instance's a with 0 to be calculated later
    currentSnapshot.b=0;   // intializing the instance's b with 0 to be calculated later
    currentSnapshot.c=0;   // intializing the instance's c with 0 to be calculated later
    currentSnapshot.address=10;  // intializing the instance's address with 10 to make this object enter case 10 in the switch case down
    snapshotStack.push(currentSnapshot);  //push this instance in the stack
    while(!snapshotStack.empty())
    {
        currentSnapshot=snapshotStack.top(); // holds the top of the stack in current snap shot variable
        snapshotStack.pop(); //delets the top of the stack
        //each address in the switch case points to a call to be done
        switch(currentSnapshot.address)
        {
            case 10:
                //we are pushing instances from instance.n=n to  instance.n=1 at n=n-1 until base case is reached
                {
                 if(currentSnapshot.n<=1)
                {
                    retVal=1;
                    continue;
                }
                else
                {
                    currentSnapshot.address = 20; //chanding the adress of the instance that is pushed in the stack with adrress 10  to be 20 to be ready to enter new call
                    snapshotStack.push(currentSnapshot);
                    SnapShot newSnapshot;
                    newSnapshot.n= currentSnapshot.n-1; // pushing a new instance of n = previous n -1
                    newSnapshot.a=0; //intializing the instance's a with 0 to be calculated later in case 20
                    newSnapshot.b=0; //intializing the instance's b with 0 to be calculated later in  case 30
                    newSnapshot.c=0; //intializing the instance's c with 0 to be calculated later  in case 30
                    newSnapshot.address=10; //intializing the instance's address with 10 to make this object enter case 10 again
                    snapshotStack.push(newSnapshot);
                }
                break;
            }

            case 20:
                // Compute a
            {
                currentSnapshot.a=currentSnapshot.n+retVal;  //a=N+ previous retVal
                currentSnapshot.address=30; // change the adress of this instance to indicate that its next stage is 30 to compute b , c
                snapshotStack.push(currentSnapshot); //push this instance in the stack
                currentSnapshot.address=10; // change the address of this call to 10
                currentSnapshot.n=currentSnapshot.n/2; // with n=n/2 to be prepared to enter case 30 to compute its b
                snapshotStack.push(currentSnapshot); // push to the stack
                break;
            }
            case 30:
                // Compute b and c
            {
                currentSnapshot.b=currentSnapshot.n*retVal; //b-n* result of previous N/2
                currentSnapshot.c=currentSnapshot.n-2-(currentSnapshot.a+currentSnapshot.b)%2; // c= n-2 -(a+b)%2
                currentSnapshot.address=40; // changing the adddress of the call to be wo to compute d
                snapshotStack.push(currentSnapshot); //pushing this call to stack
                SnapShot newCall; //new instance to be prepared to compute the d
                newCall.n = currentSnapshot.c; // which has its n = to c
                newCall.address = 10; // the adress of this new call is to be 10 to start computing a, b , c ,d from the begining for d=f(c) which is equals to reVal
                snapshotStack.push(newCall); // pushing the new call to the stack
            }
                break;
            case 40:
                // Compute d
            {   int d=retVal; // d is equal to previous reVal from newCall in case 30
                retVal=currentSnapshot.a+currentSnapshot.b+d;
                break;
            }
        }
    }
    return retVal;
}
int main()
{

    for (int i = 1; i <=20 ; i++)
    {
        cout<<F(i)<<endl;
        cout<<F_iterative(i)<<endl ;
    }

    return 0;
}