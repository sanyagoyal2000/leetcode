class Solution {
public:
    int strStr(string haystack, string needle) {
          int len=needle.size();
    int len2=haystack.size();
    
    if(len>len2)
        return -1;
    
    if(needle=="")
        return 0;
      
    int ptr2=0;
    int ptr=0,count=0;   
    
    while(ptr2<len2 && ptr<len)           // Using ptr2 to track 'hackstack' and ptr to track 'needle' 
    {
       if(haystack[ptr2]==needle[ptr])
       {
           count++;
           ptr2++;
           ptr++;
           if(count==len)
               return ptr2-len;
        }
        else
        {
            ptr2=ptr2-ptr+1;
            count=0;
            ptr=0;
         }
        
        if(count==len)
            return ptr;
    }
    return -1;
    }
};