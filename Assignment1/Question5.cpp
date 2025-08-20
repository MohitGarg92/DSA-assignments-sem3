#include<iostream>
using namespace std;
class Matrix
{
    int rows;
    int cols;
    int mat[100][100];
    public:
    Matrix(int r,int c)
    {
        rows=r;
        cols=c;
        int mat[rows][cols];
    }
    void input()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cin>>mat[i][j];
            }
        }
    }
    void Calculate()
    {
        // for rows sum;
        int sum=0;
        cout<<"the sum of rows are "<<endl;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                sum+=mat[i][j];
            }
            cout<<sum<<endl;
            sum=0;
        }
        cout<<"the sum of columns are "<<endl;
        for(int i=0;i<cols;i++)
        {
            for(int j=0;j<rows;j++)
            {
                sum+=mat[j][i];
            }
            cout<<sum<<endl;
            sum=0;
        }
    }
};
int main()
{
    Matrix m(3,2);
    m.input();
    m.Calculate();
    return 0;
}