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

int F_iterative(int n)
{   int original_n=n;
    int address = 10; // Entry point for each each "call"
    stack<int> s;
    int temp=n;
    int a=1, b=1 , c , d;
    int *arr;
    arr= new int [n]; // i will store in it the value of the Functions mo2akatan
   s.push(30); // Initial return address
   s.push(n);
   int index=0;
    while(!s.empty())
    {
        switch(address)
        {
            case 10:
            {
                n = s.top();
                s.pop();
                if(n <=1)
                { // The base case
                    address = s.top();
                    s.pop();
                    arr[index]=1;
                }
                else
                {
                    s.push(n);
                    s.push(20); // Address to point to it after finishing case 10
                    s.push(n-1);
                    address = 10; // Make another "call"
                }
                break;
            }
            case 20:  // address 20
            { // Compute and return
                temp = s.top();
                s.pop();
                a=arr[temp-2]+temp;
                b=temp*arr[(temp/2)-1];
                c=temp-2-(a+b)%2;
                if(c<0){c=0;}
                else {c--;}
                d=arr[c];
                index++;
                arr[index]=a+b+d;
               // cout<<arr[index]<<endl;
                address = s.top();
                s.pop();
                break;
            }
            case 30:
                // The final return value to break the loop
                temp = s.top();
                s.pop();
        }
    }
    return arr[original_n-1];
}
int main() {

    cout<<F(2)<<endl;
    cout<<F_iterative(2)<<endl ;
    cout<<F(3)<<endl;
    cout<<F_iterative(3)<<endl ;
    cout<<F(4)<<endl;
    cout<<F_iterative(4)<<endl ;
    cout<<F(6)<<endl;
    cout<<F_iterative(6)<<endl ;
    cout<<F(7)<<endl;
    cout<<F_iterative(7)<<endl ;
    cout<<F(8)<<endl;
    cout<<F_iterative(8)<<endl ;
    cout<<F(9)<<endl;
    cout<<F_iterative(9)<<endl ;
    cout<<F(10)<<endl;
    cout<<F_iterative(10)<<endl ;
    return 0;
}
