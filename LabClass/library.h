#ifndef _library_h
#define _library_h

#include <sstream>
using std::string;
using std::ostream;
class LibraryRecord
{
    string title;
    string author;
    string congCatNum;
    string publisher;
    int publishYear;
    bool circulating;
public:
    LibraryRecord();
    LibraryRecord(string, string, string, string, int, bool circulating = true);
    //LibraryRecord(string, string, string, string, int);
    /// toString
    const string toString() const;
    /// getter section.
    /// indicating that the getter method cannot modify its object through the "this" pointer.
    const string getTitle() const;
    const string getAuthor() const;
    const string getCongCatNum() const;
    const string getPublisher() const;
    const int getPublishYear() const;
    const bool isCirculating() const;
    /// setter section.
    void setTitle(string);
    void setAuthor(string);
    void setCongCatNum(string);
    void setPublisher(string);
    void setPublishYear(int);
    void setCirculation(bool);
    //friend ostream& operator<<(ostream &out, const LibraryRecord &rec);
};
    /// misc. function section.
    const string itos(int number);
    const string btos(bool expression);
    /// overloading operator section.
    ostream& operator<<(ostream &out, const LibraryRecord &rec);
#endif
