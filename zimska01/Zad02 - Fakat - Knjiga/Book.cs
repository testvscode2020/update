using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zad02___Fakat___Knjiga
{
    class Book :IComparable<Book>
    {
        private int id;
        private static int idGenerator; 

        private long isbn;

        public Book(long isbn, string author, string title)
        {
            id = ++idGenerator;
            Isbn = isbn;
            Author = author;
            Title = title;
        }

        public long Isbn
        {
            get => isbn;
            set
            {
                if (value.ToString().Length !=13
                    || !value.ToString().All(c=> char.IsDigit(c))
                    //prva varianta 
                    //!value.ToString().All(char.IsDigit)
                    //druga varianta 
                    //!value.ToString().All(c=> char.IsDigit(c)) 
                    )
                {
                    throw new Exception("ISBN must be 13 digits");
                }
                isbn = value;



            }
        }
        public string Author { get; set; }
        public string Title { get; set; }

        public override string ToString() => $"Book: {isbn}\t{id}\t{Author}\t{Title}";

        public int CompareTo(Book other) => -Isbn.CompareTo(other.Isbn);
    }
}
