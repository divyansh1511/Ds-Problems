#include<bits/stdc++.h>
using namespace std;

int AmazonProductSearchFeature(string search , string result){
    int ptr1 = 0 , ptr2 = 0;
    while (ptr1 < search.length())
    {
        if (ptr2 < result.length() && search[ptr1] == result[ptr2])
        {
            ptr1++;
            ptr2++;
        }
        else
        {
            while (ptr1 < search.length() && search[ptr1] != result[ptr2])
            {
                ptr1++;
            }
        }
        if (ptr2 >= result.length())
        {
            break;
        }
    }
    return result.length() - ptr2;
}

//2. question was on sliding window ----> stock problem

int main(){

}