/*
 * 2014-03-28
 * FANGEN
 * http://pl.spoj.com/problems/FANGEN/
 * score: 8/15
 */

using System;
using System.Collections.Generic;

namespace SPOJ
{
    class Program
    {
        static void Main()
        {
            char[,] result;
            bool rightturn = false;
            while (true)
            {
                rightturn = false;
                short r = Int16.Parse(Console.ReadLine().Split()[0]);
                if (r == 0)
                {
                    break;
                }
                if (r < 0)
                {
                    rightturn = true;
                    r *= -1;
                }
                result = recursiveGenerateFan(r, rightturn);
                //output
                writeFan(result, r);
            }

        }

        private static void writeFan(char[,] result, short r)
        {

            for (int y = r*2 - 1; y >= 0; --y)
            {
                for (int x = 0; x < 2 * r; ++x)
                {
                    Console.Write(result[x, y]);
                }
                Console.Write(Environment.NewLine);
            }
            Console.WriteLine();
        }
        /// <summary>
        /// 
        /// </summary>
        /// <param name="newRad">Radius (half of width) of fan to generate</param>
        /// <returns>Fan</returns>
        static char[,] recursiveGenerateFan(int newRad, bool rightturn)
        {
            int dim = newRad*2;//=width=height
            int prevRad = newRad-1;
            char[,] result = new char[dim, dim];
            if (newRad == 1)
            {
                result[newRad - 1, newRad - 1] = '*';
                result[newRad, newRad - 1] = '*';
                result[newRad - 1, newRad] = '*';
                result[newRad, newRad] = '*';
                return result;
            }

            char[,] prevFan = recursiveGenerateFan(prevRad,rightturn);

            //paste previous
            for (int x = 0; x < prevRad*2; ++x)
            {
                for (int y = 0; y < prevRad * 2; ++y)
                {
                    result[x + 1, y + 1] = prevFan[x, y];
                }
            }
            //prevRad is the number of consecutive dots/stars
            short dots = 0;
            short stars = 0;
            //stars in all corners
            result[0, 0] = '*';
            result[dim - 1, 0] = '*';
            result[0, dim - 1] = '*';
            result[dim - 1, dim - 1] = '*';
            if (rightturn)
            {
                //First row
                for (int i = 1; i < dim-1; ++i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[i, dim - 1] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[i, dim - 1] = '.';
                        ++dots;
                    }
                }
                //Right column
                for (int i = dim - 2 ; i > 0; --i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[dim-1, i] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[dim - 1, i] = '.';
                        ++dots;
                    }
                }
                //Last row
                for (int i = dim -2 ; i > 0; --i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[i, 0] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[i, 0] = '.';
                        ++dots;
                    }
                }
                //First column
                for (int i = 1; i < dim-1; ++i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[0, i] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[0, i] = '.';
                        ++dots;
                    }
                }
            }
            else
            {
                //First row
                for (int i = dim-2; i > 0; --i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[i, dim-1] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[i, dim-1] = '.';
                        ++dots;
                    }
                }

                //Left column
                for (int i = dim - 2; i > 0; --i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[0, i] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[0, i] = '.';
                        ++dots;
                    }
                }
                //Last row
                for (int i = 1; i < dim - 1; ++i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[i, 0] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[i, 0] = '.';
                        ++dots;
                    }
                }
                //Right column
                for (int i = 1; i < dim - 1; ++i)
                {
                    if (dots >= prevRad && stars >= prevRad)
                    {
                        stars = 0;
                        dots = 0;
                    }
                    if (stars < prevRad)
                    {
                        result[dim-1, i] = '*';
                        ++stars;
                    }
                    else
                    {
                        result[dim-1, i] = '.';
                        ++dots;
                    }
                }

            }



            return result;
        }

    }
}

