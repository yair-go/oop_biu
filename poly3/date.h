class Date
{
private:
    int day;
    int month;
    int year;
    static Date* pdate;
protected:
   Date();
   Date(Date&);
public:
   static Date* getDate(); 
   int getday();
   int getmonth();
   int getyear();
   int update_date();
   
};