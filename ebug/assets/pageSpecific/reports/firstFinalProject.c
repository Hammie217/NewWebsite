#include <stdio.h>

int marksArray[5][2]; //defines global array memory location

int scanfint()//check if input is a integer
{
    char input[10];
    scanf("%s",&input);
    int i =0,ii,failed=0,value=0;
    for (i=0;i<10;i++)
    {
        if(input[i] == 0)
        {
           ii=i;//finds length of string
           break;         
                    }
        }
    for(i=0;i<ii;i++)
    {
          if((input[i]>57)||(input[i]<48))//checks askii values
          {
                failed=1;                      
                                       }           
    }
    if(failed)
              return(-1);
    for(i=0;i<ii;i++){
           value = value * 10 + ( input[i] - '0' );    //puts value into int       
                      
                      }
    return(value);
}


int getValue(char subject[10]) //function that gets a 0-100 integer value 
{
    int value,error=0;
    do
    {
        if (error==1)
        {
               printf("Invalid, Try again \n");      //checks if there has been an error
        }
    printf("Enter mark awarded for %s \n",subject);  
    value = scanfint();
    error = 1; // shows an error has occured
    }
    while(value>100||value<0);
    system("cls");  //clears screen to keep program tidy and understandable
    return(value);
}

void inputData(void)//procedure that stores function data in the array
{
     marksArray[0][0] =getValue("Maths 1");
     marksArray[1][0] =getValue("Maths 2");
     marksArray[2][0] =getValue("Tech 1");
     marksArray[3][0] =getValue("Tech 2");
     marksArray[4][0] =getValue("Coursework"); 
}

int credits(void) // initialises the array and calculates the credits awarded
{
	int i,count =0;
	for(i=0;i<5;i++)
	{
			marksArray[i][1]=0; //initialises array
	}
	for(i=0;i<4;i++)
	{
		if(marksArray[i][0]>=40) // if the mark is above 40
		{
			marksArray[i][1]=10; // set credits to 10
			count++; // count the number of passed modules
		}
	}
	count *= 10; // *10 passed modules finding out the total credits
	if(marksArray[4][0]>=40) //if coursework is above 40
	{
		marksArray[i][1]=20; // set credits got as 20
		count += 20; // add 20 to total credits if so
	}
	return(count);
}

float average()         //this returns the weighted average of marks
{
	int i; float total=0,pointPart ;
	for(i=0;i<4;i++)
	{
		total = total + (float)marksArray[i][0];
	}
	total = total + 2*(float)marksArray[4][0];  // all of this calculates average
	total /= 6;
	//pointPart = modf(total,&i);								|
	//pointPart /= 10;											|
	//printf("%f %.1f %f",total,total, pointPart);              this is needed on certain versions of compiler
	//if(pointPart>=0.05)										|
	//{															|
	//	total = total + 0.1;									|
	//}															|
	return(total);
}


void DrawTable() //main table being drawn and calls functions to calculate values 
{
	int total =credits();
   printf("----------------------------------------------------------------------------\n");
   printf("Subject | Maths 1 | Maths 2 | Tech 1 | Tech 2 | Course | Credits | Overall |\n");
   printf("        |         |         |        |        |  work  | awarded | average |\n");
   printf("----------------------------------------------------------------------------\n");
   printf(" Mark   | %7d | %7d | %6d | %6d | %6d |    -    | %7.1f |\n",marksArray[0][0],marksArray[1][0],marksArray[2][0],marksArray[3][0],marksArray[4][0],average());
   printf("Awarded |         |         |        |        |        |         |         |\n");
   printf("----------------------------------------------------------------------------\n");
   printf("Possible|      10 |      10 |     10 |      10|     20 |    -    |    -    |\n");
   printf("Awarded |         |         |        |        |        |         |         |\n");
   printf("----------------------------------------------------------------------------\n");
   printf("Credits | %7d | %7d | %6d | %6d | %6d | %7d |    -    |\n",marksArray[0][1],marksArray[1][1],marksArray[2][1],marksArray[3][1],marksArray[4][1],total);
   printf("Awarded |         |         |        |        |        |         |         |\n");
   printf("----------------------------------------------------------------------------\n"); //big table print lines
   if((average()>=39.5)&&(total>=40)&&(marksArray[4][0]>=40))//checks if student passes or not
   		printf("Overall Result: Pass \n");
	else
   		printf("Overall Result: Failed \n");
   }
   
void printSubject(int position)//prints the subject equal to the array position
{
	switch(position)
	{
		case 0:
			printf("   Maths 1  |");
			break;
		case 1:
			printf("   Maths 2  |");
			break;
		case 2:
			printf("   Tech 1   |");
			break;
		case 3:
			printf("   Tech 2   |");
			break;
		case 4:
			printf(" Coursework |");
			break;
			
	}
}
   
void minMax() // calculates and prints minMax modules
{
	int i,max=-1,maxPos=0,min=101,minPos=0,maxes=0,mins=0;
	for(i=0;i<5;i++)
	{
		if(marksArray[i][0]>max)
		{
			max = marksArray[i][0]; // finds how many have the same value of max
			maxPos = i;
		}
		if(marksArray[i][0]<min)
		{
			min = marksArray[i][0];// finds how many have the same value of min
			minPos = i;
		}
		
	}
	int maxPoses[5],minPoses[5];
	printf("\nMaxProject(s)\nMark: %3d|",max);//prints all max projects
	for(i=0;i<5;i++)
	{
                    if(marksArray[i][0]==max)
                    {
                    printSubject(i);
			          maxes++;
                    }
}

	printf("\n\nMinProject(s)\nMark: %3d|",min);//prints all min projects 
	for(i=0;i<5;i++)
	{
                    if(marksArray[i][0]==min) 
                    {
                    printSubject(i);
			          mins++;
                    }
}
printf("\n\n");
}

void PresentMinMax() // supplys the query for if minMax should be presented
{
	char ch;
	int failed =0;
	do
	{
	printf("Would you like to see the lowest and highest modules? (y/n) \n");//querey if they want to see or not
	ch = getch();
	switch(ch) // switch all different possible values
	{
		case 'y':
			failed = 0;
			minMax();
			break;
		case 'n':
			failed = 0;
			printf("Not displaying MinMax \n");
			break;
		default:
			printf("Error in answer please use y or n \n");
			failed = 1;
			break;
	}
	}while(failed);
}



int main(void) // Main that calls all functions and procedures and asks if the user would like to repeat
{
	char ch;
	system("COLOR F0");
	printf("----------Module results calculator-------------\n");
	do
	{ 
	system("cls");   
    inputData();
    DrawTable();
    PresentMinMax();
	printf("Would you like to restart? (y/n) \n");
	ch = getch();
	}while(ch == 'y');  //getchar(); in some compiler versions
	return(0);
    
}
