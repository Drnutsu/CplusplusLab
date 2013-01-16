/// note: const after function definition means function shall not modify anything.
#include <iostream>
//#include <cstdlib>
//#include <sstream>
#include "library.h"
using namespace std;

int main()
{
    LibraryRecord lrec1,lrec2("1", "2", "3", "4", 5, false),lrec3("11", "22", "33", "44", 55);
    cout<<lrec1<<endl;
    cout<<lrec2<<endl;
    cout<<lrec3<<endl;
    lrec1.setAuthor("Noob ofTheYear");
    cout<<lrec1<<endl;
    return 0;
}
const string itos(int number)
{
   stringstream ss;//create a stringstream
   ss<<number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
const string btos(bool expression)
{
    stringstream ss;
    ss<<(expression?"true":"false");
    return ss.str();
}

LibraryRecord::LibraryRecord()
{
    title = "noTitle";
    author = "noAuthor";
    congCatNum = "No Library of Congress Number";
    publisher = "noPublisher";
    publishYear = -1;
    circulating = false;
}
LibraryRecord::LibraryRecord(string title, string author, string congCatNum, string publisher, int publishYear, bool circulating)
{
    this->title = title;
    this->author = author;
    this->congCatNum = congCatNum;
    this->publisher = publisher;
    this->publishYear = publishYear;
    this->circulating = circulating;
}
//c++11 delegating constructor
/*LibraryRecord::LibraryRecord(string title, string author, string congCatNum, string publisher, int publishYear)
    : LibraryRecord(title, author, congCatNum, publisher, publishYear, true)
{   }*/
const string LibraryRecord::toString() const
{
    return "["+title+", "+author+", "+congCatNum+", "+publisher+", "+itos(publishYear)+", "+btos(circulating)+"]";
}
ostream& operator<<(ostream &out, const LibraryRecord &rec)
{
    return out<<rec.toString();
}
void LibraryRecord::setAuthor(string author)
{    this->author = author;}
void LibraryRecord::setCirculation(bool circulating)
{    this->circulating = circulating;}
void LibraryRecord::setCongCatNum(string congCatNum)
{    this->congCatNum = congCatNum;}
void LibraryRecord::setPublisher(string publisher)
{   this->publisher = publisher;}
void LibraryRecord::setPublishYear(int publishYear)
{   this->publishYear = publishYear;}
void LibraryRecord::setTitle(string title)
{   this->title = title;}

const string LibraryRecord::getAuthor() const
{   return author;}
const string LibraryRecord::getCongCatNum() const
{   return congCatNum;}
const string LibraryRecord::getPublisher() const
{   return publisher;}
const int LibraryRecord::getPublishYear() const
{   return publishYear;}
const string LibraryRecord::getTitle() const
{   return title;}
const bool LibraryRecord::isCirculating() const
{   return circulating;}
