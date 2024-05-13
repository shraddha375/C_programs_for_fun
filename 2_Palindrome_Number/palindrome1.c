bool isPalindrome(int x) {

    int reverse_sum = 0;
    int remainder;
    int n = x;

    if (x < 0){
        return false;
    }
    else{
        while(n > 0){
            remainder = n % 10;

            // Check for overflow before updating reverse_sum
            //This is added so that reverse_sum*10 + remainder does not exceed the INT_MAX = 2,147,483,647. If reverse_sum > INT_MAX / 10, then the condition fails.
            //It also fails when the reverse_sum == INT_MAX/10 and remainder is 8 or 9 as the resultant (reverse_sum*10 + remainder) is greater than INT_MAX.
            if (reverse_sum > INT_MAX / 10 || (reverse_sum == INT_MAX / 10 && remainder > 7)) {
                return false;
            }
            reverse_sum = (reverse_sum*10) + remainder;
            n= n/10;
        }

        if(reverse_sum == x){
            return true;
        }
        else{
            return false;
        }

    }
    
}
