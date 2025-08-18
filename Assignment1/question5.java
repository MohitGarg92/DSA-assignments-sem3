import java.util.*;
public class question5 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int mat[][] = new int[5][5];
        int rowsum[] = new int[mat.length];
        int colsum[] = new int[mat[0].length];
        for(int i=0;i<mat.length;i++)
        {
            for(int j=0;j<mat[0].length;j++)
            {
                mat[i][j]=sc.nextInt();
            }
        } 
        for(int i=0;i<mat.length;i++)
        {
            for(int j=0;j<mat[0].length;j++)
            {
                rowsum[i]+=mat[i][j];
                colsum[j]+=mat[i][j];
            }
        }

        //printing the sum of nth row
        for(int i=0;i<rowsum.length;i++)
        {
            System.out.println("the sum of row "+i+" is "+rowsum[i]);
        }
        for(int i=0;i<colsum.length;i++)
        {
            System.out.println("the sum of column "+i+" is "+colsum[i]);
        }
        sc.close();
    }
}
