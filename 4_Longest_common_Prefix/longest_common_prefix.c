#include<string.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    
    char* result_string = (char*)malloc(strlen(*strs) + 1);
    strcpy(result_string, "");
 
    char* current_string = *strs;
    char current_character = *current_string;
 
    char temp;
    int incre = 0;
    char* count = *strs;
    char str[2];

    while(current_character != '\0'){
        for(char** strings = strs + 1; strings < strs + strsSize; strings++){
          temp = *((*strings) + incre);
          if(temp == current_character){
            continue;
          }
          else{
            return result_string;
          }  
        }
        str[0] = current_character;
        str[1] = '\0';
        strcat(result_string, str);
        count += 1;
        current_character = *count;
        incre += 1;
    }
    return result_string;
}
