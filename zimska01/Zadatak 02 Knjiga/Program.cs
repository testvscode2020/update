using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadatak_02_Knjiga
{
    class Program
    {
        static void Main(string[] args)
        {
            Student s1 = new Student("milica", "krmpotic");
            Student s2 = new Student("gojko", "mrnjavcevic");

            Console.WriteLine(Student.GetCounter());
        }
    }
}
