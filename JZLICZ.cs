using System;
using System.Collections.Generic;

/*JZLICZ*/
namespace SPOJ
{
    class Program
    {

        static void Main(string[] args)
        {
            int linii = Convert.ToInt32(Console.ReadLine());
            string line;
            Dictionary<char, int> litery = new Dictionary<char, int>(26);
            for (int i = 0; i < linii;++i )
            {
                line = Console.ReadLine();
                foreach (char znak in line)
                {
                    if (Char.IsWhiteSpace(znak))
                    {
                        continue;
                    }
                    int poprzednia;
                    litery.TryGetValue(znak, out poprzednia);
                    litery[znak] = poprzednia + 1;
                    
                }
            }
            for (char i = 'a'; i <= 'z'; ++i)
            {
                int ilosc;
                litery.TryGetValue(i, out ilosc);
                if (ilosc > 0)
                {
                    Console.WriteLine(i + " " + ilosc);
                }
            }
            for (char i = 'A'; i <= 'Z'; ++i)
            {
                int ilosc;
                litery.TryGetValue(i, out ilosc);
                if (ilosc > 0)
                {
                    Console.WriteLine(i + " " + ilosc);
                }
            }
        }
    }
}
