using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Euler6
{
    class Program
    {
        static void Main(string[] args)
        {
            int sumSquares = 0;
            int square = (100 * 100 + 100) / 2;
            //Thank you Calc2
            square *= square;
            int i = 1;
            while (i < 101)
            {
                sumSquares += i * i;
                i++;
            }
            Console.WriteLine(square + " - " + sumSquares + " = " +(square - sumSquares));
        }
    }
}
