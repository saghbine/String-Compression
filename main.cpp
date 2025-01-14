//
//  main.cpp
//  String Compression
//
//  Created by daniel saghbine on 12/17/24.
//  CTCI 1.6 String Compression

#include <iostream>
using namespace std;

string String_Compression(const string &s);

int main()
{
    string str;
    
    cout<<"problem\n-------\n\tImplement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the \"compressed\" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).\n\n";
    
    cout<<"input\n-----\n\tType: ";
    cin>>str;
    
    cout<<"\noutput\n------\n\tThe compressed string is: "<<String_Compression(str)<<".\n\n";
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(n); time complexity: O(n).\n\n";
    
    return 0;
}

string String_Compression(const string &s) // s is input string
{
    string compress; // "compressed" string to return
    int counter=0; // counter mechanism to count repeated characters
    int i; // index for s
    
    for(i=0; i < s.size()-1; i++) // check char at indices 0...size-1 in s
    {
        counter++; // increment counter for select char
        
        while(s[i] == s[i+1]) // check how many repeats of select char
        {
            counter++; // increment counter for select char
            i++; // move i to next index in s
        }
        
        compress+=s[i]+to_string(counter); // accumulate compress with char and its repeat count
        counter=0; // reset counter of select char
    }
    
    if(i != 0 && s[i-1] != s[i]) // if s got checked and now checks last pair if last letter is unique
        compress+=s[i]+to_string(1); // add to compress with constant 1 as repeat
    
    if(!compress.empty() && compress.size() < s.size()) // if compress isn't empty and its size is less than s
        return compress; // compress is shortest
    
    return s; // s is shortest
}
