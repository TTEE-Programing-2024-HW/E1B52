#include<stdio.h> 
#include<stdlib.h> 
int main(void)
{
	
	void menu(void);
	void picture(void); 
	int count=0;
	int password=2024;
	while(count<3)
	{
		printf("請輸入密碼:/n");
		scanf("%d",&password);
		count++;
		if(password==2024);
		{
			printf("輸入正確/n");
			break;
		}
		else{
			printf("輸入錯誤/n");
			if(count==3)
			printf("已連續錯誤3次/a/n");
			}
	}
}
system("CLS");
while(1)
	{
		menu();
		printf("    請輸入想執行的選項: ");
		fflush(stdin);
		scanf("%c",&MENU);
		switch(MENU) 
		{
			case 'a':
			case 'A':
				system("CLS"); 
				do 
				{
					printf("    請輸入一個‘a’到‘n’的字元: ");		
					fflush(stdin); 					
					scanf("%c",&c);
					if(c < 'a' || c > 'n')				 
 		  		    {
 		  		    	printf("輸入錯誤!請重新輸入~\n"); 
					}
				}
				while(c < 'a' || c > 'n');		
				for(A= c ; A>='a' ;A-- )	 	
				{
					for (space ='a' ; space <A ; space++)
					{
            			printf(" ");
        			}
					for( B = A ; B <= c ; B++ )
					{
						printf("%c",B);			
					}
					printf("\n");		
				}
    	    	getch();						
				system("CLS"); 							
				break;
				case 'b':
			case 'B':
				system("cls"); // 清除螢幕
				do//do-while迴圈 
				{				
 	  	    	 	printf("請輸入一個1至9的整數n：");
 	 	     	 	fflush(stdin); 					
 	  			    scanf("%d", &n);
 	  			    if(n < 1 || n > 9)		
 	 	 		    {
 	 	 		    	printf("輸入錯誤!請重新輸入~\n");	
					}
    			}
    	   		while(n < 1 || n > 9);
     	  		printf("乘法表：\n");
      	  		for (i = 1; i <= n; i++) 
						{
      			      	for (j = 1; j <= n; j++) 
						{
      			          printf("  %d * %d = %2d  ",i,j, i * j);
      			      	}
      			     	printf("\n");
       	 		}
        		getch();						
				system("CLS"); 					
				break;
				case 'c':
			case 'C':
				do 
				{
					printf("是否要繼續執行程式? [是] 請輸入(Y or y)，[否] 請輸入(N or n) :\n"); 
					fflush(stdin);
					scanf("%c",&OPTION);
					if(OPTION=='y'||OPTION=='Y')		
					{
						getch();						
						system("CLS"); 					
						break;							
					}
					else if(OPTION=='n'||OPTION=='N')
					{
						return 0;
					}
					else 
					{
					 	printf("輸入錯誤\n");
					}
				}
				while( (OPTION!='y'||OPTION!='Y') || (OPTION!='n'||OPTION!='N') );
		}
	}
	
	system("PAUSE");
	return 0;
	void picture(void)
{
printf("**********************************");
printf("         歡迎進入程式設計作業!\n");
printf("**********************************");
printf("          今天是2024年5月5日\n");
printf("**********************************");
printf("           '\我是E1B52'\ \n \a");
printf("**********************************");

}
/*____________________________________________*/ 
void menu(void) 
{
	printf("\n");
	printf("\n");
	printf("         |**********************************|\n");
	printf("         |                                  |\n");
	printf("         |    ***              ***          |\n");
	printf("         |     **  E1B52       **           |\n");
	printf("         |      *              *            |\n");
	printf("         |__________________________________|\n");
	printf("         |                                  |\n");
	printf("         |      *        MENU        *      |\n");
	printf("         |                                  |\n");
	printf("         |    * **a. 畫出直角三角形 **  *   |\n");
	printf("         |     * **b. 顯示乘法表   ** *     |\n");
	printf("         |      * **c. 結束      ** *       |\n");
	printf("         |                                  |\n");
	printf("         |                                  |\n");
	printf("         |**********************************|\n");
	return 0;
*\心得:這次的作業在上次的作業上多了更多指令的練習，結合了老師們多次的上課內容，例如dowhile和switch，但是過程中無法執行很多次，測試了很久才成功，希望下次練習時能更細心。
