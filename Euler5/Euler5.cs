using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Euler5
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            int answer = 1;
            int[] primes = new int[] { 2, 3, 5, 7, 11, 13, 17, 19};
            int temp=0;
            while (i < primes.Length)
            {
                if (temp == 0)
                {
                    temp = primes[i];
                }
                answer *= primes[i];
                temp *= primes[i];
                if (temp > 20)
                {
                    temp = 0;
                    i++;
                }
            }
            Console.WriteLine(answer);
            Console.Read();
        }
    }
}
