class Solution {
public:

    // string helper(string old_string){
    //     size_t AB_position = old_string.find("AB");
    //     size_t CD_position = old_string.find("CD");
        
    //     if (AB_position != std::string::npos) {
    //         old_string.erase(AB_position, 2);
    //         return helper(old_string);
    //     }
    //     else if (CD_position != std::string::npos) {
    //         old_string.erase(CD_position, 2);
    //         return helper(old_string);
    //     }
    //     return old_string;
    // }

    // int minLength(string s) {
    //    return helper(s).length();
    // }
    // old_string = "ACDBQK" ; 
    
    int minLength(string s) {
        // use two pointers / indexing low and high to scan the string 
        // the 'high' is the upper bound of the scanning area
        // the 'low' is the lower bound of the scanning area 
        // operations: 
        //          Once we found "AB" or "CD": (1) increase the 'high' 
        //                                      (2) decrease the 'low'
        //          Once we cant find "AB" or "CD": 
        int low = 0; 
        for (int high = 0; high < s.length(); ++high) {
            s[low] =s[high];
            if (low>=1 && ((s[low-1] == 'A' && s[low] == 'B') || (s[low-1] == 'C' && s[low] == 'D') )) low -= 2;
            low ++;
        }
        return low;
    }
    /*
            String = "ACDBQK"

            High            Low             Scanning area               Action
            0               0                   A                       No match, we going to increamet low
            1               1                   AC                      No match, increament low 
            2               2                   ACD                     Found "CD", remove CD, low -=2 ;
            3               0                   AB                      No match yet
            4               1                   ABQ                     Found "AB" ,remove AB, low -= 2;
            5               0                   
            6
            7
            8
            9
            10
    
    */


};
