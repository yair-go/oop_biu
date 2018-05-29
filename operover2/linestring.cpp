#include "linestring.h"
#include <string.h>

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  init a new line string 
***********************************************************************************************/

LineString::LineString()
{
   size=4;
   arr=new MyString[size];
   m_length=0;
}

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  init a new line string with length
***********************************************************************************************/

LineString::LineString(int length)
{
   size=length*2;
   arr=new MyString[size];
   m_length=length;
}

/***********************************************************************************************
*function name : GetSize                                                                      
*The Input: none                                                        
*The Output: size of LineString       
*function operation :  return the size of LineString   
***********************************************************************************************/

int LineString::GetSize()
{
   return m_length;
}

/***********************************************************************************************
*function name : IsMember                                                                      
*The Input: pointer to char                                               
*The Output: 1 if str is member in this LineString, else 0       
*function operation :  check if str is member in this LineString
***********************************************************************************************/

int LineString::IsMember (char *str)
{
   MyString istr(str);
   MyString istr1;
   int i,b;
   !(istr);
   for (i=0;i<m_length;i++)
   { 
      istr1=arr[i];
      !(istr1);
      b=(istr1==istr);
      if (b==1) return 1;
   }
   return 0;
}

/***********************************************************************************************
*function name : IsMember                                                                      
*The Input: MyString                                               
*The Output: 1 if str is member in this LineString, else 0       
*function operation :  check if str is member in this LineString
***********************************************************************************************/

int LineString::IsMember (MyString& str)
{
   MyString istr=str;
   MyString istr1;
   int i,b;
   !(istr);
   for (i=0;i<m_length;i++)
   { 
      istr1=arr[i];
      !(istr1);
      b=(istr1==istr);
      if (b==1) return 1;
   }
   return 0;
}

/***********************************************************************************************
*function name : Clear                                                                       
*The Input: none                                               
*The Output: none
*function operation :  clear this LineString
***********************************************************************************************/

void LineString::clear ()
{
    arr=new MyString[4];
    m_length=0;
}

/***********************************************************************************************
*function name : Insert
*The Input: MyString, index                                               
*The Output: this LineString       
*function operation :  insert the MyString to the index place in this LineString
***********************************************************************************************/

LineString& LineString::Insert (const MyString& str, int index)
{
    int i;
    index--;
    LineString L2(size);
    for (i=0;i<m_length;i++)
       {
          L2.arr[i]=arr[i];
       }
    L2.m_length=m_length;
    if (index+1>m_length) index=m_length; 
    if (m_length<size) arr[index]=str;
    else {
	   arr=new MyString[size*2];
	   size*=2;
	   for (i=0;i<m_length;i++){
          arr[i]=L2.arr[i];
	   }
	   arr[index]=str;
    }
    for (i=index;i<m_length;i++){
       arr[i+1]=L2.arr[i];
    } 
    m_length++;
    return *this;
}

/***********************************************************************************************
*function name : Delete                                                                      
*The Input: index                                               
*The Output: this LineString      
*function operation :  delete the MyString in tha index place
***********************************************************************************************/

LineString& LineString::Delete (int index)
{
   int i;
   index--;
   LineString L2(size);
   for (i=0;i<m_length;i++){
          L2.arr[i]=arr[i];
   }
   L2.m_length=m_length;
   for (i=index;i<m_length-1;i++)
   {
      arr[i]=L2.arr[i+1];
   } 
   m_length--; 
   return *this;
}

/***********************************************************************************************
*function name :operator+=                                                                     
*The Input: LineString                                              
*The Output: this LineString      
*function operation :  the right operand add to this LineString
***********************************************************************************************/

LineString& LineString:: operator+= (const LineString &line)
{
   int i;
   LineString L2(size);
   if (m_length+line.m_length>size) 
   {
      for (i=0;i<m_length;i++)
      {
         L2.arr[i]=arr[i];
      }
      L2.m_length=m_length;
      arr=new MyString[(m_length+line.m_length)*2];
      for (i=0;i<m_length;i++) 
         arr[i]=L2.arr[i];
    }
    else i=m_length;
    for (i=m_length;i<m_length+line.m_length;i++) 
         arr[i]=line.arr[i-m_length]; 
    m_length+=line.m_length;
    return *this;
}


/***********************************************************************************************
*function name :operator-=                                                                     
*The Input: MyString                                              
*The Output: this LineString      
*function operation :  all the MyString that appear in the LineString deleted
***********************************************************************************************/

LineString& LineString:: operator-= (const MyString &str)
{
   int i;
   for (i=0;i<m_length;i++)
      if (arr[i]==str) Delete(i);
   return *this;
}


/***********************************************************************************************
*function name :operator!                                                                     
*The Input: none                                              
*The Output: this LineString      
*function operation :  all letter be lowercase
***********************************************************************************************/

LineString& LineString:: operator! ()
{
   int i;
   for (i=0;i<m_length;i++)
     !(arr[i]);
   return *this;
}

/***********************************************************************************************
*function name :operator[]                                                                     
*The Input: index                                              
*The Output: MyString      
*function operation :  return the MyString in place index
***********************************************************************************************/

MyString& LineString:: operator[] (int index) const
{  
   return arr[index-1];

}

/***********************************************************************************************
*function name :operator<=
*The Input: LineString                                              
*The Output: boolean function      
*function operation :  check if the right operand contain in the left
***********************************************************************************************/

bool LineString:: operator<= (const LineString &line1)
{
   int i;
   MyString str;
   for (i=0;i<line1.m_length;i++)
   {
      str=line1.arr[i];
      if (IsMember(str)==0) return 0;
   }
   return 1;
}

/***********************************************************************************************
*function name :operator+                                                                     
*The Input: 2 LineString                                              
*The Output: LineString      
*function operation :  add 2 Linestring
***********************************************************************************************/

LineString operator+ (const LineString &line1, const LineString &line2)
{
  LineString Line3;
  Line3+=line1;
  Line3+=line2;
  return Line3;
}
       
/***********************************************************************************************
*function name :operator==
*The Input: 2 LineString                                              
*The Output: boolean function      
*function operation :  check if 2 LineString equal
***********************************************************************************************/

bool operator== (const LineString &line1, const LineString &line2)
{
   if (line1.m_length==line2.m_length) return 0;
   int i;
   for (i=0; i<line2.m_length;i++){
     if (line1.arr[i]!=line2.arr[i]) return 0;
   }
   return 1;  
}

/***********************************************************************************************
*function name :operator<<
*The Input:  LineString                                             
*The Output: none      
*function operation :  print the LineSting to the screen
***********************************************************************************************/

ostream& operator<< (ostream &out, const LineString& line)
{
   int i;
   for (i=0; i<line.m_length;i++)
   {
      cout<<line.arr[i]<<" ";
   }
   cout<<endl;
   return out; 
}

/***********************************************************************************************
*function name :operator>>
*The Input: LineString                                              
*The Output: none      
*function operation :  get linestring from the user
***********************************************************************************************/
       
istream& operator>> (istream &in, LineString& line)
{
	MyString str;
	MyString et("@");
	int i=1;
	do {
		cin>>str;
		if ((str==et)==false){
			line.Insert(str,i);
			i++;
		}
	} while ((str==et)==false);
	return in;
}
