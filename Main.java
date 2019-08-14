/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
		
		int ar[][] = { {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
                };
        
       int  n=3;
        int m=2;
    
        
        
        for(int i=0;i<=n-m;i++)
        {
            for(int j=0;j<=n-m;j++)
            {
                int sum=0;
                for(int p=i;p<i+m;p++)
                {
                    for(int q=j;q<j+m;q++)
                        sum+=ar[p][q];
                }
                System.out.print(sum+" ");
            }
            System.out.println();
        }
	}
}
