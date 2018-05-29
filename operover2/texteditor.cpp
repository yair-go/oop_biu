#include "texteditor.h"
#include "linestring.h"
#include "mystring.h"

/***********************************************************************************************
*function name : constructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  init a new text editor 
***********************************************************************************************/

TextEditor:: TextEditor()
{
	m_size=10;
	m_line_arr=new LineString* [m_size];
	int i;
	for (i=0;i<m_size;i++) m_line_arr[i]=NULL;
	main_menu();
}

/***********************************************************************************************
*function name : destructor                                                                      
*The Input: none                                                        
*The Output: none       
*function operation :  delete text editor 
***********************************************************************************************/

TextEditor:: ~TextEditor()
{
  delete[] m_line_arr;
}

/***********************************************************************************************
*function name : Renew                                                                      
*The Input: size                                                        
*The Output: text editor       
*function operation :  init a new text editor with the old and new size
***********************************************************************************************/

LineString** TextEditor::Renew(int size)
{
   LineString** n_arr;
   n_arr=new LineString* [size];
   int i;
   for (i=0;i<m_size;i++) n_arr[i]=m_line_arr[i];
   m_line_arr=new LineString* [size];
   for (i=0;i<m_size;i++) m_line_arr[i]=n_arr[i];
   m_size=size;
   return m_line_arr;
}

/***********************************************************************************************
*function name : arrlen                                                                      
*The Input: none                                                        
*The Output: int    
*function operation :  return number of line in text editor
***********************************************************************************************/

int TextEditor:: arrlen()
{
   int i=0;
   do {
      if (m_line_arr[i]!=NULL) i++;
   } while (m_line_arr[i]!=NULL);
   return i;
}

/***********************************************************************************************
*function name : InsertWord                                                                      
*The Input: MyString, num of row, index                                                        
*The Output: none    
*function operation :  insert word to her place
***********************************************************************************************/

void TextEditor:: InsertWord(const MyString& str, int row, int mila) 
{
	int irow,len;
	irow=row-1;
	len=arrlen();
	if (len<irow) irow=len;
	if (irow>m_size) m_line_arr=Renew(m_size*2);
	if (m_line_arr[irow]==NULL) m_line_arr[irow]=new LineString;
	m_line_arr[irow]->Insert(str,mila);
}

/***********************************************************************************************
*function name : InsertWord                                                                      
*The Input: MyString, num of row, index                                                        
*The Output: none    
*function operation :  insert word to her place
***********************************************************************************************/

void TextEditor:: InsertWord(char* str1, int row, int mila)
{
	int irow,len;
	irow=row-1;
	len=arrlen();
	if (len<irow) irow=len+1;
	if (irow>m_size) m_line_arr=Renew(m_size*2);
        MyString str(str1);
	if (m_line_arr[irow]==NULL) m_line_arr[irow]=new LineString;
	m_line_arr[irow]->Insert(str,mila);
}

/***********************************************************************************************
*function name : InsertLine                                                                      
*The Input: 2 num of row's index                                                        
*The Output: none    
*function operation :  add 2 lines
***********************************************************************************************/

void TextEditor:: InsertLine(int line1,int line2)
{
   *(m_line_arr[line1-1])+=*(m_line_arr[line2-1]);
   if (line1!=line2) DeleteLine(line2);
}

/***********************************************************************************************
*function name : AppendLine                                                                      
*The Input: none                                                       
*The Output: none    
*function operation :  insert new line to text editor
***********************************************************************************************/

void TextEditor:: AppendLine()
{
   int len;
   len=arrlen();
   LineString L1;
   cin>>L1;
   if (len+1>m_size) m_line_arr=Renew(m_size*2);
   m_line_arr[len]=new LineString; 
   *(m_line_arr[len])+=L1;
}

/***********************************************************************************************
*function name : DeleteWord                                                                      
*The Input:  num of row, index                                                        
*The Output: none    
*function operation :  delete word from her place
***********************************************************************************************/

void TextEditor:: DeleteWord(int row,int mila)
{
   m_line_arr[row-1]->Delete(mila);
   if (m_line_arr[row-1]->GetSize()==0) DeleteLine(row);
}

/***********************************************************************************************
*function name : DeleteString                                                                      
*The Input:  MyString                                                     
*The Output: none    
*function operation :  delete stirng from text
***********************************************************************************************/

void TextEditor:: DeleteString(const MyString& str)
{
   int i,j;
   for (i=0;i<m_size;i++)
     if (m_line_arr[i]!=NULL)
        for (j=0;m_line_arr[i]&&j<m_line_arr[i]->GetSize();j++)
	   if ((m_line_arr[i])&&(*(m_line_arr[i]))[j+1]==str) {
	      DeleteWord(i+1,j+1);
	      if (j!=0) j--;
	      else j=-1;
	   }
}

/***********************************************************************************************
*function name : DeleteLine                                                                      
*The Input:  num of row
*The Output: this text editir    
*function operation :  delete line from text
***********************************************************************************************/

TextEditor& TextEditor:: DeleteLine (int row)
{ 
   int i=row-1;
   while (m_line_arr[i+1]!=NULL){ 
      m_line_arr[i]->clear();
      *(m_line_arr[i])+=*(m_line_arr[i+1]);
      i++;
   }
   m_line_arr[i]=NULL;
   return *this;
}

/***********************************************************************************************
*function name : Compare                                                                      
*The Input:  2 num of rows index                                                        
*The Output: boolean    
*function operation :  compare 2 rows
***********************************************************************************************/

int TextEditor:: Compare (int row1, int row2)
{
   int i;
   if (m_line_arr[row1-1]->GetSize()!=m_line_arr[row2-1]->GetSize()) return 0;
   for (i=1;i<m_line_arr[row1-1]->GetSize();i++)
      if ((*(m_line_arr[row1-1]))[i]==((*(m_line_arr[row2-1]))[i])==0) return 0;
   return 1;
}

/***********************************************************************************************
*function name : IsMember                                                                      
*The Input:  MyString                                                        
*The Output: boolean    
*function operation : check if string appear in text ***********************************************************************************************/

bool TextEditor:: IsMember(const MyString& str)
{ 
   int i=0;
   bool b=0;
   while (m_line_arr[i]!=NULL){
      b=m_line_arr[i]->IsMember(str);
      i++;
      if (b) return b;
   }
   return b;
}

/***********************************************************************************************
*function name : Clear                                                                      
*The Input: none                                                       
*The Output: this text editor    
*function operation :  delete all line
***********************************************************************************************/

TextEditor& TextEditor:: Clear()
{ 
	m_size=10;
	m_line_arr=new LineString* [m_size];
	int i;
	for (i=0;i<m_size;i++) m_line_arr[i]=NULL;
	return *this;
}

/***********************************************************************************************
*function name : Replace                                                                      
*The Input:  2 MyString                                                        
*The Output: this text editor    
*function operation :  replace every time erite str1 to str2
***********************************************************************************************/

TextEditor& TextEditor:: Replace(MyString& str1,MyString& str2)
{ 
   int i=0,j;
   while (m_line_arr[i]!=NULL){
      for (j=0;j<m_line_arr[i]->GetSize();j++)
         if ((*(m_line_arr[i]))[j+1]==str1) {
	    m_line_arr[i]->Delete(j+1);
	    m_line_arr[i]->Insert(str2,j+1);
	 }
      i++;
   }
   return *this;
}

/***********************************************************************************************
*function name : Search
*The Input:  MyString                                                        
*The Output: int
*function operation :  print all row's num that str appear
***********************************************************************************************/

int TextEditor:: Search(const MyString& str)
{ 
   int i=0,flag=0;
   while (m_line_arr[i]!=NULL){
      if ((m_line_arr[i])->IsMember(str)) {
         cout<<i+1<<" ";
	 flag=1;
      }
	  i++;
   }
   return flag;
}

/***********************************************************************************************
*function name : Sort                                                                      
*The Input:  length                                                        
*The Output: none    
*function operation : sort the text
***********************************************************************************************/

TextEditor& TextEditor:: Sort(int n)
{ 
	int i=1,j=2,k=1,flag=0;
	LineString* temp;
	if (n>0){
	 for (i=1;i<n;i++){
	  k=1; 
	  while ((*(m_line_arr[i-1]))[k]==(*(m_line_arr[i]))[k] && k<m_line_arr[i-1]->GetSize() && k<m_line_arr[i]->GetSize()) k++;
	  if (((*(m_line_arr[i-1]))[k]>((*(m_line_arr[i]))[k]))>0) {
		temp=m_line_arr[i];
		m_line_arr[i]=m_line_arr[i-1];
		m_line_arr[i-1]=temp;
	      }
	   Sort(n-1);
	  }
	}
   return *this;
}

/***********************************************************************************************
*function name : contain                                                                       
*The Input: 2 num of rows index                                                        
*The Output: boolean     
*function operation :  check if row 1 contain row2
***********************************************************************************************/

int TextEditor:: contain(int row1, int row2)
{ 
    if (m_line_arr[row1-1]<=m_line_arr[row2-1]) return 1;
    else return 0;
}

TextEditor& TextEditor:: LowerCase()
{ 
   int i=0;
   while (m_line_arr[i]!=NULL){
      !(*m_line_arr[i]);
      i++;
   } 
   return *this;
}

/***********************************************************************************************
*function name : Print                                                                      
*The Input:  none                                                        
*The Output: none    
*function operation :  print text to screen 
***********************************************************************************************/

void TextEditor:: Print()
{
   int i=0;
   while (m_line_arr[i]!=NULL){
      cout<<*m_line_arr[i];
      i++;
   }
}

int get_data()
{
   int data;
      cin>>data;
   return data;
}

void TextEditor:: main_menu()
{
   char choice;
   int row1,row2,word;
   MyString str,str2;
   LineString L1;
   do {
      cin>>choice;
      switch (choice)
      {
         case 'a': 
	           cin>>str;
		   row1=get_data();
		   word=get_data();
		   if (row1<1||word<1) cout<<"Not Available\n";
		   else InsertWord(str,row1,word);
		   break;
	case 'b':
	           row1=get_data();
		   row2=get_data();
		   if (row1>arrlen()||row2>arrlen()||row1<1||row2<1) cout<<"Not Available\n";
		   else InsertLine(row1,row2);
		   break;
	case 'c': 
		   AppendLine();
		   break;
	case 'd':
		   row1=get_data();
		   word=get_data();
		   if (row1>arrlen()||row1<1) cout<<"Not Available\n";
		   else if (word>m_line_arr[row1-1]->GetSize()||word<1) cout<<"Not Available\n";
		       else DeleteWord(row1,word); 
		   break;
	case 'e':
	           cin>>str;
		   DeleteString(str);
		   break;
	case 'f':
	           row1=get_data();
		   if (row1>arrlen()||row1<1) cout<<"Not Available\n";
		   else DeleteLine(row1);
		   break;
	case 'g':   
	           Clear();
		   break;
	case 'h':
		   row1=get_data();
		   row2=get_data();
		   if (row1>arrlen()||row2>arrlen()||row1<1||row2<1) cout<<"Not Available\n";
		   else cout<<Compare(row1,row2)<<endl;
		   break;
	case 'i':   
		   cin>>str;
		   cout<<IsMember(str)<<endl;
		   break;
	case 'j':
	     	   cin>>str>>str2;
		   Replace(str,str2);
		   break;
	case 'k':
		   cin>>str;
		   if (!Search(str)) cout<<"empty";
		   cout<<endl;
		   break;
	case 'l':
			if (m_line_arr[0]!=NULL) Sort(arrlen());
		   else cout<<"empty\n";
		   break;
	case 'm':
	           row1=get_data();
		   row2=get_data();
		   if (row1>arrlen()||row2>arrlen()||row1<1||row2<1) cout<<"Not Available\n";
		   else cout<<contain(row1,row2)<<endl;
		   break;
	case 'n':
	           if (m_line_arr[0]!=NULL) LowerCase();
		   else cout<<"empty\n";
		   break;
	case 'o':
		   if (m_line_arr[0]!=NULL) Print();
		   else cout<<"empty\n";
		   break;
	case 'z':
	           break;
        default :  
                   cout<<"Not Available\n";    
      }   // end of switch
   } while (choice!='z');
}

