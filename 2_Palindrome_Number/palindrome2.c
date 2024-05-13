bool isPalindrome(int x) {

    int reverse_half = 0;
    int remainder = 0;
    int n = x;
    int n1;

    if (x < 0 || (x != 0 && x % 10 == 0)){
        return false;
    }
    else if(x == 0){
        return true;
    }
    else{
        while(n > reverse_half){
            n1 = n;
            remainder = n % 10;

            // Check for overflow before updating reverse_sum
            //if (reverse_half > INT_MAX / 10 || (reverse_half == INT_MAX / 10 && remainder > 7)) {
            //    return false;
            //}
            reverse_half = (reverse_half*10) + remainder;
            n = n/10;
            
        }
        if(reverse_half == n || n == reverse_half/10){
            return true;
        }
        else{
            return false;
        }

    }  
}
