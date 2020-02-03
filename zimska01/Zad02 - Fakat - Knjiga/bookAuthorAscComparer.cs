using System.Collections.Generic;

namespace Zad02___Fakat___Knjiga
{
    internal class bookAuthorAscComparer : IComparer<Book>
    {
        public int Compare(Book x, Book y) => x.Author.CompareTo(y.Author);
    }
}