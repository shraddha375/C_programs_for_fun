int romanToInt(char* s) {
    int sum = 0;
    char literal[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    int j1, j2;
    int i = 0;

    while (s[i] != '\0') {
        for(int j = 0; j < sizeof(literal) / sizeof(literal[0]); j++){
            if(s[i] == literal[j]){
                j1 = j;
                break;
            }
        }
        
        if (s[i + 1] != '\0') {
            for(int j = 0; j < sizeof(literal) / sizeof(literal[0]); j++){
                if(s[i + 1] == literal[j]){
                    j2 = j;
                    break;
                }
            }
            if(j1 < j2){
                sum = sum + values[j2] - values[j1];
                i += 2;
            }
            else{
                sum = sum + values[j1];
                i++;
            } 
        }
        else {
            sum = sum + values[j1];
            i++;
        }
        
    }
    return sum;
}
