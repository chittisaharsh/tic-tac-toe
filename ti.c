 /* 
This is tic tac toe game made using c language
Name - Chitti Saharsh
Class   - Computer Science & Business System
Division- J1
Roll no - RBT22CB003


Name - Shantanu Wararkar
Class - Electrical Engg
Divisiom - C2
Roll no - RBT22EL044

*/


/*
VARIABLES:
p    - player no
ele  - element no.
input- input no, (selected element)
i    - loop for taking 9 inputs
j    - array to check if a no is not repeated
k    - element of loop to check array j
win  - winning condition variable
mark - mark the element
*/


#include<stdio.h>
char ele[]={'0','1','2','3','4','5','6','7','8','9'};     //Defining the global variable for elements and element number for the game
int main()
{
 int p=1,input,i,j[9],k=0,win=0;
 char mark;
 void board();                                           //funtion to print the board
 int checkwin();                                        //function to check the winning condition 
 for(i=1;i<=9;i++)                                     //loop for 9 turns
 {
  if(i%2==0)
  {
   p=2;
  }
  else
  {
   p=1;
  }
  pro:                                                 // label pro
  board();
  printf("\n\nPlayer %d choose the element no: ",p);
  scanf("%d",&input);
  j[i]=input;                                          //array tu check if an element if not used twice  
  if(input<1 || input>9)                              //condition to check if an element is not used twice
  {
   error:                                             //label error
   printf("\n\nNO CHEATING PLAYER %d ",p);
   goto pro;
  }
  else
  {
   for(k=0;k<i;k++)
   {
    if(j[k]==input)                                    //condition to check if an element is not used twice
    {
     goto error;
    }
   }
   if(p==1)
   {
    mark='X';                                          // X mark for player 1
   }
   else
   {
    mark='O';                                          // O mark for player 2 
   }
   ele[input]=mark;
  }
  win=checkwin();                                      // checking if a player has won
  if(win==0)                                          //if the return value given by checkwin function is 0 
  {
   continue;                                          // that means no one has won , hence continue
  }
  if(win==1)                                          //if the return value given by checkwin function is 1 
  {
   goto end;                                          // that means someone has won , hence exit the loop
  }
 }
 end:                                                 //label end
 if(win==1)                                           // declaration of winning player 
 {
  board();
  printf("\n\n\nPlayer %d Won",p);
 }
 else
   if(win==0)                                        //if the loop is completed and no one has won then its a draw
   {
     board();
    printf("\n\n\nIts a DRAW");
   }
 return 0;
}

void board()                                                 // funtion where the board exists 
{
 printf("\n=TIC TAC TOE=\n\n");
 printf("Player 1 - X\n");
 printf("Player 2 - O\n\n");
 printf("   |   |   \n");
 printf(" %c | %c | %c \n",ele[1],ele[2],ele[3]);
 printf("---|---|---\n");
 printf(" %c | %c | %c \n",ele[4],ele[5],ele[6]);
 printf("---|---|---\n");
 printf(" %c | %c | %c \n",ele[7],ele[8],ele[9]);
 printf("   |   |   \n");
}

int checkwin()                                              // function to check if a player has won 
{
 if(ele[1]==ele[2] && ele[2]==ele[3])
 {
  return 1;
 }
 if(ele[4]==ele[5] && ele[5]==ele[6])
 {
  return 1;
 }
 if(ele[7]==ele[8] && ele[8]==ele[9])
 {
  return 1;
 }
 if(ele[1]==ele[4] && ele[4]==ele[7])
 {
  return 1;
 }
 if(ele[2]==ele[5] && ele[5]==ele[8])
 {
  return 1;
 }
 if(ele[3]==ele[6] && ele[6]==ele[9])
 {
  return 1;
 }
 if(ele[1]==ele[5] && ele[5]==ele[9])
 {
  return 1;
 }
 if(ele[3]==ele[5] && ele[5]==ele[7])
 {
  return 1;
 }
 else
 {
  return 0;
 }
}
