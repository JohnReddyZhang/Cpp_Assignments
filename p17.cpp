#include <iostream>
using namespace std;

class MyString
{
private:
   char* Buffer;
   // Notice that in this case the member data is on the free store...
public:
   // Constructor
   MyString(const char* InitialInput = NULL)
   {
      if(InitialInput != NULL)
      {
         Buffer = new char [strlen(InitialInput) + 1];
         strcpy_s(Buffer, strlen(InitialInput) + 1, InitialInput);
      }
      else 
         Buffer = NULL;
   }

   // Destructor: clears the buffer allocated in constructor
   ~MyString()
   {
      cout << "Invoking destructor, clearing up\n";
      if (Buffer != NULL)
         delete [] Buffer;
   }

   int GetLength() const
   {
      return strlen(Buffer);
   }

   const char* GetString() const
   {
	   return Buffer;
   }
};

int main()
{
   MyString SayHello("Hello from String Class");
   cout << "String buffer in MyString is " << SayHello.GetLength();
   cout << " characters long\n";
   cout << "Buffer contains: " << SayHello.GetString() << endl;
   return 0;
}
