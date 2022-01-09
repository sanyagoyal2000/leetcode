class Solution {
public:
    bool isRobotBounded(string instructions) {
        int path[4][2]={{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int d=0,x=0,y=0;
        for(int i=0;i<instructions.size();i++){
            if(instructions[i]=='L'){
                d=(d+1)%4;
                
            }
            else if(instructions[i]=='R'){
                d=(d+3)%4;
                }
            else{
                x+=path[d][0];
                y+=path[d][1];
            }
        }
        if(d>0 or (x==0 and y==0))return true;
        return false;
    }
};
