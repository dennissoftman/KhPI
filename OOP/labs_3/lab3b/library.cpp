#include "library.hpp"

Book::Book(cstrref t, cstrref a, std::size_t p)
    : title(t), author(a), pages(p)
{

}

cstrref Book::GetTitle() const
{
    return title;
}

cstrref Book::GetAuthor() const
{
    return author;
}

Library::Library()
{

}

Library::~Library()
{
    for(BookRecord *i : books)
        delete i;
    books.clear();
}

void Library::AddBook(Book *nb, int cat_id)
{
    books.push_back(new BookRecord(nb, cat_id));
}

void Library::TakeBook(cstrref title)
{
    BookRecord *ip = FindBook(title);
    if(ip)
    {
        ip->present = false;
    }
}

void Library::RemoveBook(cstrref title)
{
    BookRecord *ip = FindBook(title);
    if(ip)
    {
        books.remove(ip);
        delete ip;
    }
}

void Library::ReturnBook(cstrref title)
{
    BookRecord *ip = FindBook(title);
    if(ip)
    {
        ip->present = true;
    }
}

BookRecord *Library::FindBook(cstrref title) const
{
    for(BookRecord *i : books)
    {
        if(i->ptr->GetTitle() == title)
            return i;
    }
    return nullptr;
}

bool Library::BookExists(cstrref title) const
{
    return (FindBook(title) != nullptr);
}

bool Library::BookAvailable(cstrref title) const
{
    if(!BookExists(title))
        return false;
    return (FindBook(title)->present);
}

bool Library::BookTaken(cstrref title) const
{
    if(BookExists(title))
        return !(FindBook(title)->present);
    return true;
}

std::ostream &operator <<(std::ostream &out, const Library &lib)
{
    for(BookRecord *i : lib.books)
    {
        out << "- " << i->ptr->GetAuthor() << ". " << i->ptr->GetTitle() << " ("
            << (i->present ? "в наличии" : "отсутствует") << ")\n";
    }
    return out;
}

BookRecord::BookRecord(const Book *p, int cat_id)
    : catalogue_id(cat_id), present(true), ptr(p)
{

}
