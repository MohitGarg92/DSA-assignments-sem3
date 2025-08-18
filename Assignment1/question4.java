import java.util.Arrays;
public class question4 {
    public static void main(String args[])
    {
        Solution obj1 = new Solution(10);
        int[] reverse = obj1.Reverse();
        System.out.println(Arrays.toString(reverse));
    }
    
}
class Solution
{
    int length;
    int arr[];
    // default constructor
    Solution(int length)
    {
        this.length=length;
        this.arr = new int[length];
    }
    int[] Reverse()
    {
        for(int i=0;i<length/2;i++)
        {
            int temp=arr[i];
            arr[i]=arr[length-1-i];
            arr[length-1-i]=temp;
        }
        return this.arr;
    }
    void Multiply(int arr2[][])
    {

    }
    int[][] Transpose(int matrix[][])
    {
        int r=matrix.length;
        int c = matrix[0].length;
        int[][] transpose = new int[c][r];
        for(int i=0;i<matrix.length;i++)
        {
            for(int j=0;i<matrix[0].length;j++)
            {
                transpose[i][j]=matrix[j][i];
            }
        }
        return transpose;
    }
}