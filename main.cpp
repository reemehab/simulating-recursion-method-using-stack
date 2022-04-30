#include <iostream>
#include <stack>
using namespace  std;
int F(int n)
{
    if(n<=1)
        return 1;
    int a=n+F(n-1);
    int b=n*F(n/2);
   // int c=n-2-(a+b)%2;
    //int d=F(c);
    //cout<<"a "<<a<<" b "<<b<<endl;
    return a+b;
}

int F_iterative(int n)
{
    int address = 10; // Entry point for each each "call"
    int temp_B = n;
    int temp_A=n;
    int n2=n;
    stack<int> s ;
    int a=0 , b=0;
    //computing A
   s.push(30); // Initial return address
    s.push(temp_A);
    while(!s.empty())
    {
        switch(address)
        {
            case 10: //if call type equals 3
            {
                n2 = s.top();
                s.pop();
                if(n2 <=1)
                { // The base case
                    address = s.top();
                    s.pop();
                    s.push(1);
                }
                else
                {
                    s.push(n2);
                    s.push(20); // Where should I return?
                    s.push(n2-1);
                    address = 10; // Make another "call"
                }
                break;
            }
            case 20:  // if call type equals compute
            { // Compute and return
                temp_A = s.top();
                s.pop();
                n2 = s.top();
                s.pop();
                address = s.top();
                s.pop();
                temp_A = n2 + temp_A;
                s.push(temp_A);
                break;
            }
            case 30:  // if call type equals call
                // The final return value
                temp_A = s.top();
                s.pop();

        }}
        a =a+ temp_A;

    address=10;
    s.push(30); // Initial return address
    s.push(temp_B);
    while(!s.empty()) {
        switch (address) {
            case 10: //if call type equals 3
            {
                n = s.top();
                s.pop();
                if (n <= 1) { // The base case
                    address = s.top();
                    s.pop();
                    s.push(1);
                } else {
                    s.push(n);
                    s.push(20); // Where should I return?
                    s.push(n / 2);
                    address = 10; // Make another "call"
                }
                break;
            }
            case 20:  // if call type equals compute
            { // Compute and return
                temp_B = s.top();
                s.pop();
                n = s.top();
                s.pop();
                address = s.top();
                s.pop();
                temp_B = n * temp_B;
                s.push(temp_B);
                break;
            }
            case 30:  // if call type equals call
                // The final return value
                temp_B = s.top();
                s.pop();
        }
    }
        b= b+temp_B;

  //  cout<<"a "<<a<<" b "<<b<<endl;
    return a+b;
}
int main() {

    cout<<F(2)<<endl;
    cout<<F_iterative(2)<<endl ;
    cout<<F(4)<<endl;
    cout<<F_iterative(4)<<endl ;
    cout<<F(5)<<endl;
    cout<<F_iterative(5)<<endl ;
    return 0;
}
