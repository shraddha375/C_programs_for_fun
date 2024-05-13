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
            remainder = n % 10;
            reverse_half = (reverse_half*10) + remainder;
            n = n/10;
            
        }

        // For even no. of digits : n == reverse_half 
        // For odd no. of digits : n == reverse_half/10
        if(reverse_half == n || n == reverse_half/10){
            return true;
        }
        else{
            return false;
        }

    }  
}
