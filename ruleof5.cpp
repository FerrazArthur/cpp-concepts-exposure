#include <utility>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class rule_of_five
{
    char* cstring; // raw pointer used as a handle to a
                   // dynamically-allocated memory block
public:
    virtual char* get () {return this->cstring;}
    explicit rule_of_five(const char* s = "") : cstring(nullptr)
    { 
        if (s)
        {
            size_t n = strlen(s) + 1;
            cstring = new char[n];      // allocate
            memcpy(cstring, s, n); // populate 
        } 
    }
 
    ~rule_of_five()
    {
        delete[] cstring; // deallocate
    }
 
    rule_of_five(const rule_of_five& other) // copy constructor
        : rule_of_five(other.cstring) {}
 
    rule_of_five(rule_of_five&& other) noexcept // move constructor
        : cstring(exchange(other.cstring, nullptr)) {}
 
    rule_of_five& operator=(const rule_of_five& other) // copy assignment
    {
        return *this = rule_of_five(other);
    }
 
    rule_of_five& operator=(rule_of_five&& other) noexcept // move assignment
    {
        swap(cstring, other.cstring);
        return *this;
    }
};

auto printrule(rule_of_five& a)
{
    try{
        if (a.get() == nullptr)
            throw "nullptr";
        return a.get();
    }
    catch(...)
    {
        return new char();
    }
}

int main()
{
    rule_of_five a("Hello World!");
    rule_of_five b = a;
    rule_of_five c(b);

    cout<<"após fazer copias:"<<endl;
    cout<<"a = "<<printrule(a)<<endl;
    cout<<"b = "<<printrule(b)<<endl;
    cout<<"c = "<<printrule(c)<<endl;


    rule_of_five d("Hello World!");
    rule_of_five e = move(d);
    rule_of_five f(move(e));

    cout<<"após mover:"<<endl;
    cout<<"d = "<<printrule(d)<<endl;
    cout<<"e = "<<printrule(e)<<endl;
    cout<<"f = "<<printrule(f)<<endl;

    return 0;
}