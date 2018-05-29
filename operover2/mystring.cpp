#include "mystring.h"
#include <string.h>


/***********************************************************************************************
*function name :consturctor
*The Input: pointer to char                                      
*The Output: none      
*The function operation : init MyString with string
***********************************************************************************************/

MyString:: MyString(char* str)
{
   if (str){
      m_ilen=strlen(str);
      m_str=new char[m_ilen+1];
      strcpy (m_str,str);
   }
   else {
      m_str=NULL;
      m_ilen=0;
   }
}

/***********************************************************************************************
*function name : get_str
*The Input: none                                              
*The Output: char*    
*function operation :  return the string
***********************************************************************************************/

char* MyString:: get_str()
{
    return m_str;
}

/***********************************************************************************************
*function name :operator=
*The Input: MyString                                              
*The Output: MyString      
*function operation :  init MyStirng with other
***********************************************************************************************/

MyString& MyString:: operator= (const MyString &str)
{
   if (this!=&str){
      if (m_str){
         delete[] m_str;
         m_str=NULL;
      }
      m_ilen=str.m_ilen;
      m_str=new char[m_ilen+1];
      strcpy(m_str,str.m_str);
   }
   return *this;
}

/***********************************************************************************************
*function name :operator+=
*The Input: MyString                                              
*The Output: this MyString      
*function operation :  add the right operand to the left
***********************************************************************************************/

MyString& MyString:: operator+= (const MyString &str)
{
   if (m_str){
      int inewlen=m_ilen+str.m_ilen;
      char* new_str=new char[inewlen+1];
      strcpy(new_str,m_str);
      strcat(new_str,str.m_str);
      delete[] m_str;
      m_str=NULL;
      m_str=new_str;
      m_ilen=inewlen;
   }
   else {
      m_ilen=str.m_ilen;
      m_str=new char[m_ilen+1];
      strcpy(m_str,str.m_str);
   }
   return *this;
}

/***********************************************************************************************
*function name :operator!
*The Input: MyString                                             
*The Output: this MyString      
*function operation :  all the letter be lower case
***********************************************************************************************/

MyString& MyString:: operator! ()
{
   int i;
   for (i=0;i<m_ilen;i++)
     if ((m_str[i]>=65)&&(m_str[i]<=90)) m_str[i]+=32;
   return *this;
}

/***********************************************************************************************
*function name : operator ()
*The Input: none                                              
*The Output: char*    
*function operation :  return the string
***********************************************************************************************/

MyString:: operator char*() const
{
   return m_str;
}

/***********************************************************************************************
*function name : operator+
*The Input: 2 MyString                                            
*The Output: mystring
*function operation :  add 2 MyString
***********************************************************************************************/

MyString operator+ (const MyString &str1, const MyString &str2)
{
   MyString str3(str1.m_str);
   str3+=str2;
   return str3;
}

bool operator== (const MyString str1, const MyString str2)
{
   MyString ezer1(str1.m_str),ezer2(str2.m_str);
   !(ezer1); !(ezer2);
   return strcmp(ezer1,ezer2)==0;
}

int operator< (const MyString str1, const MyString str2)
{
  MyString istr1(str1.m_str);
  MyString istr2(str2.m_str);
  !(istr1);
  !(istr2);
  return strcmp(istr1.m_str,istr2.m_str)<0;
}

int operator> (const MyString str1, const MyString str2)
{
  MyString istr1(str1.m_str);
  MyString istr2(str2.m_str);
  !(istr1);
  !(istr2);
  return strcmp(istr1.m_str,istr2.m_str)>0;
}
 
ostream& operator<< (ostream &out, const MyString& str) 
{
   if (str.m_str){
      out<<str.m_str;
   }
   return out;
}

istream& operator>> (istream &in, MyString& str)
{
   char ibuffer[256];
   cin>>ibuffer;
   str=ibuffer;
   return in;
}
   
