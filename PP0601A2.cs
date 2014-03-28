/*
 * PP0601A2
 * Test 3
 * http://pl.spoj.com/problems/PP0601A2/
 */ 
using System;

namespace SPOJ{
    class Program
    {
        static void Main(string[] args)
        {
            byte count = 0;
            byte read;
            bool prev42 = true;
            while(true){
                Console.WriteLine(read = Convert.ToByte(Console.ReadLine().Split()[0]));
                if (read== 42)
                {
                    if (!prev42)
                    {
                        ++count;
                        prev42 = true;
                    }
                    if (count == 3)
                    {
                        return;
                    }
                }
                else
                {
                    prev42 = false;
                }
            }
        }
    }
}

