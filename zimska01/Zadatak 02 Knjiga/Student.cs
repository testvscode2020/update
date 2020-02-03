using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadatak_02_Knjiga
{
    class Student
    {
        private int id;
        public Student(string ime, string prezime)
        {
            id= ++counter; 
            Ime = ime;
            Prezime = prezime;
        }
        private static int counter;
        public static int GetCounter() => counter;

        public string Ime { get; set; }
        public string Prezime { get; set; }

    }
}
