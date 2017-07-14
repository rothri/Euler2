using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Euler2
{
    class Program
    {
        static void Main(string[] args)
        {
            var fib1 = 1;
            var fib2 = 1;
            var sum =  0;
            while (fib2 < 4000000)
            {
                fib2 += fib1;
                fib1 = fib2 - fib1;
                if (fib2%2 == 0)
                {
                    sum += fib2;
                }
            }
            Console.WriteLine("The answer is:" + sum);
            Console.Read();
        }
    }
}
