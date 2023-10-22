#include <stdio.h>

int main()
{
   int side_x,side_y,side_z,volume;
   scanf("%d %d %d", &side_x, &side_y, &side_z);
   if (side_x>0 && side_y>0 && side_z>0){
       volume=2*(side_x*side_y+side_x*side_z+side_y*side_z);
       printf("%d",volume);
   }
    else if(side_x<=0){
       printf("-1");
   }
   else if(side_y<=0){
       printf("-2");
   }
   else{
       printf("-3");
   }
   return 0;
}