namespace Euler4
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 100;
            int[] answer = new int[3];
            while (i < 1000)
            {
                int j = 100;
                while (j < 1000)
                {
                    if (j*i >answer[0] && isPalindrome(j*i)){
                        answer[0] = i * j;
                        answer[1] = i;
                        answer[2] = j;
                    }
                    j++;
                }
                i++;
            }
            System.Console.WriteLine("The answer is " + answer[0] + " Which is the product of " + answer[1] + "*" + answer[2]);
        }

        static int getPlace(int num, int place)
        {
            int mod = System.Convert.ToInt32(System.Math.Pow(10, place));
            //Eliminates all numbers to the left of our number
            num = num % mod;
            //returns our numbers place
            return (10 * num) / mod;
        }
        //returns true if number is a palindrome ie 9009
        // Must be greater than 9
        static bool isPalindrome(int x)
        {
            bool answer = true;
            int digits = numDigits(x);
            
                int place2 = 1;
                while(digits>place2)
                {
                    if (getPlace(x,digits)!= getPlace(x, place2)){
                        answer = false;
                    }
                    digits--;
                    place2++;
                }
            if (answer)
            {
                System.Console.WriteLine(x);
            }
            return answer;
        }
        static int numDigits(int x)
        {
            int digits = 1;
            while (true)
            {
                if (x / (System.Convert.ToInt32(System.Math.Pow(10,digits))) == 0)
                {
                    return digits;
                }
                digits += 1;
            }
        }
    }
}
