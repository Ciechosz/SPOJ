/*
 * PP0506A
 * http://pl.spoj.com/problems/PP0506A/
 */
using System;
using System.Collections.Generic;


namespace SPOJ
{
    class Program
    {
        static void Main()
        {
            short tests = Convert.ToInt16(Console.ReadLine());
            for (int i = 0; i < tests; ++i)
            {
                short points = Convert.ToInt16(Console.ReadLine());
                List<Point> result = new List<Point>();
                for (int j = 0; j < points; ++j)
                {
                    Point p = new Point(Console.ReadLine());
                    //Finding right place to insert it
                    double distance = p.distance;
                    int size = result.Count;
                    if (size == 0)
                    {
                        result.Add(p);
                    }else{
                        bool added = false;
                        for (int k = 0; k < size; ++k)
                        {
                            if (distance <= result[k].distance)
                            {
                                added = true;
                                result.Insert(k, p);
                                break;
                            }
                        }
                        if(!added){
                            result.Add(p);
                        }
                    }
                }
                foreach (Point p in result)
                {
                    Console.WriteLine(p.ToString());
                }
                Console.ReadLine();
                Console.WriteLine();
            }

        }
    }
    class Point
    {
        public short x;
        public short y;
        public string name;

        public double distance
        {
            get
            {
                return Math.Sqrt((double)(x * x + y * y));
            }

        }

        public Point(short x, short y, string name)
        {
            this.x = x;
            this.y = y;
            this.name = name;
        }
        public Point(string data)
        {
            string[] parts = data.Split();
            name = parts[0];
            x = Convert.ToInt16(parts[1]);
            y = Convert.ToInt16(parts[2]);


        }
        public string ToString()
        {
            return name + " " + x + " " + y;
        }
    }
}

