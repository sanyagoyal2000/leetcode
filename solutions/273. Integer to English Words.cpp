        }
        else if(num > 20 && num < 100){
            ans = ans + caviats(num - num % 10);
            if(num % 10 != 0){
                ans = ans + " " + caviats(num % 10);    
            }
        }
        else if(num >= 100 && num <= 999){
            ans = ans + caviats(num/100) + " Hundred";
            if(num % 100 != 0){
                ans = ans + " ";
                solve(num % 100);   
            }            
        }
        else if(num >= 1000 && num <= 999999){
            solve(num / 1000);
            ans = ans + " Thousand";
            if(num % 1000 != 0){
                ans = ans + " ";
                solve(num % 1000);
            }            
        }
        if(num >= 1000000 && num <= 999999999){
            solve(num / 1000000);
            ans = ans + " Million";
            if(num % 1000000 != 0){
                ans = ans + " ";
                solve(num % 1000000);
            }            
        }
        if(num >= 1000000000 && num <= 9999999999){
            solve(num / 1000000000);
            ans = ans + " Billion";
            if(num % 1000000000 != 0){
                ans = ans + " ";
                solve(num % 1000000000);
            }            
        }
    }
    
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        solve(num);
        return ans;
    } 
    
};
