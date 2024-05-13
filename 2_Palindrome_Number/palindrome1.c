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
            reverse_sum = (reverse_sum*10) + remainder;
        }

        if(reverse_sum == remainder){
            return true;
        }
        else{
            return false;
        }

    }
    
}
