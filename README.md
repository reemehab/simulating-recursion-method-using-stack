# simulating-recursion-method-using-stack
* This assignment can be done in teams of 5 students or less.
* Team members must be from the same lab so the TA can discuss all of them in one lab time.
* Each team must come up with their own implementation.
* Each student in the team must understand all details of the implementation.
* The code must contain no more than 50,000 characters.
* Your code must NOT include any TAB character. Convert each TAB to 4 spaces before submitting.
* You are not allowed to copy any piece of code from the internet or from any other resource.
* You are not allowed to copy any piece of code from other students.
* You are not allowed to include any files or built-in libraries, except for the described ones.
* Your coding style must follow exactly the coding style specified in CodingStyle.pdf.
* Half the mark is dedicatd to comments explaining the code, test cases, and following CodingStyle.
* If you have issue regarding the assignment, contact the TA, not the doctor.
* Get your submission on a flash drive and discuss your submission with the TA during the first lab after the deadline.
* The TA will not tell you your mark. He will report his evaluation to me and I will make the final evaluation.
To submit the code:
* Write your code in exactly one cpp text file such as myfile.cpp.
* Make sure that myfile.cpp contains the actual code, for example open it in Notepad (do not confuse it with cbp file).
* Encode the file using the assign_encoder tool as the following:
g++ -O3 -o assign_encoder.exe assign_encoder.cpp
assign_encoder.exe ./myfile.cpp 1 3 20101111 20102222 20113333
* The 1 in the above line is the assignment ID. The 3 in the above line is number of students.
* Submit the resulting assign_1_20101111_20102222_20113333.bin file and do not submit the original myfile.cpp.
* Do not change the name of the resulting file.
* Do not compress the resulting file. Just send it exactly as it is.
Consider the following recursive function:
------------------------------------------
int F(int n)
{
    if(n<=1) return 1;
    int a=n+F(n-1);
    int b=n*F(n/2);
    int c=n-2-(a+b)%2;
    int d=F(c);
    return a+b+d;
}
------------------------------------------
* Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: <cstdlib>, <cstdio>, <cstring>, <iostream>, <stack>.
* You are not allowed to use string class, vector, or anything from STL libraries except <stack>.
* Convert the above function to a non-recursive function using the simulating recursion method using stack in Lecture04_Subprograms.
* Simulate recursion as specified in our lecture, without using any recursive call directly or indirectly.
* You are not allowed to use any other method than the method described in Lecture04_Subprograms applied to the above function.
* Your code must be general to handle all input values.
* Write at least 20 test case statements (F(1),F(2),..,F(20)) that make sure that your output matches the original function output.
* Half the mark is dedicatd to comments explaining the code before each code line, test cases, and following the CodingStyle.pdf file.
