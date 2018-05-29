#ifndef LINESTRING_H
#define LINESTRING_H

#include "mystring.h"

class LineString
{
   private :
     MyString *arr;
     int m_length,size; 
   
   public:
      LineString();
      LineString (int length);
      int GetSize ();
      int IsMember (char *str);
      int IsMember (MyString& str);
      void clear ();
      LineString& Insert (const MyString& str, int index);
      LineString& Delete (int index);
       
      LineString& operator+= (const LineString &line);
      LineString& operator-= (const MyString &str);
      LineString& operator! ();
      
      MyString& operator[] (int index) const;   
      bool operator<= (const LineString &line1);
      
      friend LineString operator+ (const LineString &line1, const LineString &line2); 
      friend bool operator== (const LineString &line1, const LineString &line2);
      friend int operator< (const LineString str1, const LineString str2);
      friend int operator> (const LineString str1, const LineString str2);
      friend ostream& operator<< (ostream &out, const LineString& line);
      friend istream& operator>> (istream &in, LineString& line); 
};   

#endif