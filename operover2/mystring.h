#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream.h>

class MyString
{
private:
   char* m_str;
   int m_ilen;
public:
   MyString(char* str=NULL);
   char* get_str();
   
   MyString& operator= (const MyString &str);
   MyString& operator+= (const MyString &str);
   MyString& operator! ();
   operator char*() const;

   friend MyString operator+ (const MyString &str1, const MyString &str2); 
   friend bool operator== (const MyString str1, const MyString str2);
   friend int operator< (const MyString str1, const MyString str2);
   friend int operator> (const MyString str1, const MyString str2);
   friend ostream& operator<< (ostream &out, const MyString& str);
   friend istream& operator>> (istream &in, MyString& str); 
};   
#endif