using System.Collections.Generic;

namespace Zad02___Fakat___Knjiga
{
    internal class bookTitleDescComparer : IComparer<Book>
    {
        public int Compare(Book x, Book y) => -x.Title.CompareTo(y.Title);
    }
}