using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zad02___Fakat___Knjiga
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Book> List = new List<Book>
            {
                new Book(1234567890123, "nives celzijus", "istina gola"),
                new Book(1234567890124, "isac asimov", "i robot"),
                new Book(1234567890125, "jerzy kosinski", "obojena ptica")
            };

            //prva varianta
            //foreach (var book in List)
            //{
            //    Console.WriteLine(book);
            //}

            //druga varianta
            //List.ForEach(book => Console.WriteLine(book));
            
            //treca varianta
            List.ForEach(Console.WriteLine);
            Console.WriteLine("--------------------------------");

            IntsDemo();

            Console.WriteLine("Isbn desc");
            List.Sort();
            List.ForEach(Console.WriteLine);

            Console.WriteLine("Author asc");
            List.Sort(new bookAuthorAscComparer());
            List.ForEach(Console.WriteLine);

            Console.WriteLine("Title desc");
            List.Sort((x, y) => -x.Title.CompareTo(y.Title)); //on zna da je x i y book zato nemoramo to podesiti. 
            List.ForEach(b => Console.WriteLine(b)); // i to je varianta


        }

        private static void IntsDemo()
        {
            List<int> list = new List<int>
            {
                2,1,3
            };
            list.Sort();
            list.ForEach(Console.WriteLine);
        }
    }
}
