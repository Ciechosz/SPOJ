/*
 * BFNTEST
 * Precz z komentarzami!
 * http://pl.spoj.com/problems/BFNTEST/
 * Wynik: 8/12
 */ 
using System;

namespace SPOJ
{
    class Program
    {
        static void Main(string[] args)
        {
            string read;
            int readInt;
            char readChar;
            string buffer = "";
            bool bigComment = false;
            bool inlineComment = false;
            bool DobuleQuote = false;
            bool SingleQuote = false;
            while ((readInt = Console.Read()) > 0)
            {
                readChar = (char)readInt;
                read = new string(readChar, 1);
                if (DobuleQuote)
                {
                    Console.Write(readChar);
                    if (read == "\"")
                    {
                        DobuleQuote = false;
                    }
                    continue;
                }
                else if (SingleQuote)
                {
                    Console.Write(readChar);
                    if (read == "'")
                    {
                        SingleQuote = false;
                    }
                    continue;
                }
                else if (bigComment)
                {
                    if (read == "*")
                    {//Possible end of big comment
                        buffer = "*";
                        continue;
                    }
                    else if (read == "/" && buffer == "*")
                    {//End of big comment
                        bigComment = false;
                        buffer = "";
                        continue;
                    }
                    else
                    {
                        buffer = "";
                        continue;
                    }
                }
                else if (inlineComment)
                {
                    if (read == "\n" || read == "\r\n")
                    {
                        inlineComment = false;
                        buffer = "";
                        Console.Write(readChar);
                        continue;
                    }
                }
                else
                {
                    if (read == "\"")
                    {//Comment start
                        DobuleQuote = true;
                        Console.Write(buffer);
                        Console.Write(readChar);
                        buffer = "";
                        continue;
                    }
                    else if (read == "'")
                    {
                        SingleQuote = true;
                        Console.Write(buffer);
                        Console.Write(readChar);
                        buffer = "";
                        continue;
                    }
                    if (read == "/")
                    {//Possible comment start
                        if (buffer == "/")
                        {
                            inlineComment = true;
                            buffer = "";
                            continue;
                        }
                        else
                        {
                            buffer = "/";
                            continue;
                        }
                    }
                    else if (read == "*")
                    {
                        if (buffer == "/")
                        {
                            bigComment = true;
                            buffer = "";
                            continue;
                        }
                        else
                        {
                            Console.Write(buffer);
                            Console.Write(readChar);
                            buffer = "";
                            continue;
                        }
                    }
                    else
                    {


                        Console.Write(buffer);
                        Console.Write(readChar);
                        buffer = "";
                    }
                }

            }


            return;
        }
    }
}

