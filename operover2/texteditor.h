#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "linestring.h"

class TextEditor
{
   private :
	   LineString **m_line_arr;
	   int m_size;
	
   public :
	   TextEditor();
	   ~TextEditor();
	   void main_menu();
	   
	   int arrlen ();
	   LineString** Renew(int size);
	   void InsertWord(const MyString& str, int row, int mila); 
       	   void InsertWord(char* str, int row, int mila);
	   void InsertLine(int line1,int line2);
	   void AppendLine();

	   void DeleteWord(int row,int mila);
	   void DeleteString(const MyString& str);
	   TextEditor& DeleteLine (int row);

	   int Compare (int row1, int row2);
	   bool IsMember(const MyString& str);

	   TextEditor& Clear();
	   TextEditor& Replace(MyString& str1,MyString& str2);
	   int Search(const MyString& str);
	   TextEditor& Sort(int n);

	   int contain(int row1, int row2);
	   TextEditor& LowerCase();
	   void Print();
};

#endif