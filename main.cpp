#include <iostream>
#include <stack>
using namespace  std;
int F(int n)
{
    if(n<=1)
        return 1;
    int b=n*F(n/2);
    return b;
}
enum CallType {Resume, Call};

struct Fcall
{
    int data;
    CallType type;

};

int F_iterative(int n)
{
    Fcall stcall;
    stcall.type=Call;
    stcall.data=0;
    stack <Fcall> s;
    s.push(stcall);
    int result=0;
    while(!s.empty())
    {
        Fcall call=s.top();
        s.pop();
        if(call.type==Call) {
            n = call.data;
            continue;
        }
            if (n <= 1)
                result = 1; /// base case
            ///int a=n+F(n-1);

        Fcall c1;
        c1.type=Resume;
        c1.data=n;
        s.push(c1);

    }

return result;
}
int main() {
    cout<<F(2)<<endl;
    cout<<F_iterative(2)<<endl ;
    return 0;
}
