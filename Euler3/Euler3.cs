using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Euler3
{
    class Program
    {
        static void Main(string[] args)
        {
            long prime = 1;
            long subject = 600851475143;
            int loopcounter = 0;
            while (subject > 1)
            {
                prime++;
                if (subject % prime == 0)
                {
                    Console.WriteLine(prime);
                    subject = subject / prime;
                }
                if (prime > 3000000000)
                {
                    prime = 0;
                    loopcounter += 1;
                }
                if (loopcounter > 3)
                {
                    Console.WriteLine("Failure");
                    break;
                }
            }
           
        }
    }
}
