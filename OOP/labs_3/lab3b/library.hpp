#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <ostream>
#include <list>

typedef std::string str;
typedef const str & cstrref;

class Book
{
public:
    Book(cstrref t="Untitled", cstrref a="Unknown", std::size_t p=0);

    cstrref GetTitle() const;
    cstrref GetAuthor() const;
private:
    str title;
    std::string author;
    std::size_t pages;
};

struct BookRecord
{
    BookRecord(const Book *p, int cat_id);

    int catalogue_id;
    bool present;
    const Book *ptr;
};

class Library
{
public:
    Library();
    ~Library();

    void AddBook(Book *nb, int cat_id);
    void RemoveBook(cstrref title);

    void ReturnBook(cstrref title);
    void TakeBook(cstrref title);

    BookRecord *FindBook(cstrref title) const;
    bool BookExists(cstrref title) const;
    bool BookAvailable(cstrref title) const;
    bool BookTaken(cstrref title) const;

    friend std::ostream &operator <<(std::ostream &out, const Library &lib);
private:
    std::list<BookRecord*> books;
};

/*
//
#define общее public
#define личное private
#define сущность class
//

сущность Книга
{
общее:
    Книга(cstrref t="Untitled", cstrref a="Unknown", std::size_t p=0);

    cstrref Название() const;
    cstrref Автор() const;
личное:
    str название;
    std::string автор;
    std::size_t страниц;
};

struct КнижнаяЗапись
{
    КнижнаяЗапись(const Книга *p, int cat_id);

    int каталог;
    bool вналичии;
    const Книга *ptr;
};

сущность Библиотека
{
общее:
    Библиотека();
    ~Библиотека();

    void ДобавитьКнигу(Книга *nb, int cat_id);
    void УдалитьКнигу(cstrref title);

    void ВернутьКнигу(cstrref title);
    void ВзятьКнигу(cstrref title);

    КнижнаяЗапись *НайтиКнигу(cstrref title) const;
    bool КнигаЕсть(cstrref title) const;
    bool КнигаДоступна(cstrref title) const;
    bool КнигуЗабрали(cstrref title) const;

    friend std::ostream &operator <<(std::ostream &out, const Библиотека &lib);
личное:
    std::list<КнижнаяЗапись*> books;
};
*/
#endif // LIBRARY_HPP
