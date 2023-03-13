#include<iostream>
#include<cmath>

using namespace std;

double determinant( double matrix[10][10], int dimension) {
   double result_of_determine = 0;
   double submatrix[10][10];
   int sign=1;

   if (dimension>2)
    {
       for (int x = 0; x < dimension; x++)
       {
                  int subA = 0;
          for (int a = 1; a <dimension; a++)
               {
                   int subB = 0;
              for (int b = 0; b < dimension; b++)
                   {
                        if (b == x)
                          continue;
                      submatrix[subA][subB] = matrix[a][b];
                        subB++;
  }
   subA++;
   }
        result_of_determine = result_of_determine + (sign * matrix[0][x] * determinant( submatrix, dimension - 1 ));
        sign*=-1;
  }
      return result_of_determine;
   }
    else if (dimension == 2)

         return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else if(dimension==1)
            return matrix[0][0];
}

void inverse(double mat[10][10],int dimension,double arr2[10][10])
{
if(dimension==2)
{
 arr2[0][0]=(1/determinant(mat,dimension))*mat[1][1];
 arr2[0][1]=-(1/determinant(mat,dimension))*mat[0][1];
 arr2[1][0]=-(1/determinant(mat,dimension))*mat[1][0];
 arr2[1][1]=(1/determinant(mat,dimension))*mat[0][0];

}
else if(dimension==1)
    arr2[0][0]=1/determinant(mat,dimension);
else{
 int sign=-1;
    int temp,temp2;
    double submat[10][10];
    double arr1[10][10];
    for(int z=0;z<dimension;z++  )
        {sign*=-1;
         for (int x = 0; x < dimension; x++)
           {
            int subA = 0;

              for (int row = 0; row <dimension; row++)
                {
                 int subB = 0;
                if(z==row)
                 continue;
             for (int col = 0; col < dimension; col++)
             {
              if (col == x)
               continue;
            submat[subA][subB] = mat[row][col];
                subB++;

                           }
                      subA++;

                         }

arr1[z][x] =determinant(submat,dimension-1)*pow(-1,x+z);


}
}
    //to swap the element

for(int i=0;i<dimension;i++)
        {
        for(int j=0;j<dimension;j++)
            {

            temp=i;

           temp2=j;
       arr2[i][j]= arr1[temp2][temp]*(1/determinant(mat,dimension));//arr2 is the inverse of matrix "mat"



            }

        }
    }

}


void result_of_AinverseB (double arrA[10][10],double invB[10][10],int dimension,int colnA,int rowA)
{

         double arrayMultiplication[10][10];

         for(int i=0;i<rowA;i++)
    {
         for(int j=0;j<dimension;j++)
            {
                double elementResult=0;
                    arrayMultiplication[i][j]=0;
             for(int e=0;e<colnA;e++)
                {
                 elementResult+=arrA[i][e]*invB[e][j];
                }
                if( elementResult>0){

              arrayMultiplication[i][j]=round(elementResult) ;}

              else{
              int negativeAprox=elementResult-0.5;
                arrayMultiplication[i][j]=negativeAprox;}

              elementResult=0;
              if(arrayMultiplication[i][j]==-0)
              arrayMultiplication[i][j]==0;}



    }

  for(int i=0;i<rowA;i++){
		for(int j=0;j<dimension;j++){
			cout<< arrayMultiplication[i][j]<<" ";
		}
	cout<<endl;}
  }



int main()
{
     const int ROWS=10,COLS=10;
    int op;
      cout<<"Please enter dimensions of Matrix A:"<<endl;
	int rowA,columnA;
	cin>>rowA>>columnA;
	double arrA[ROWS][COLS];
	 cout<<"Please enter dimensions of Matrix B:"<<endl;
	int rowB,columnB;
	cin>>rowB>>columnB;
	double arrB[ROWS][COLS];

	cout<<"Please enter values of Matrix A:"<<endl;
	//to fill the first array
	for(int i=0;i<rowA;i++){
		for(int j=0;j<columnA;j++){
			cin>>arrA[i][j];
		}
	}
	cout<<"Please enter values of Matrix B:"<<endl;
	//to fill second array
	for(int i=0;i<rowB;i++){

		for(int j=0;j<columnB;j++){
			cin>>arrB[i][j];
		}
	}
	cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
	cin>>op;

    while(op>=1 && op<=7){

   //sum of two matrices
   if (op==1)
    {
        if(rowA==rowB&&columnA==columnB){
      double arraysum[ROWS][COLS];

      for(int i=0;i<rowA;i++)
        {


		 for(int j=0;j<columnA;j++)
		 {
			arraysum[i][j]=arrA[i][j]+arrB[i][j];
			cout<<arraysum[i][j]<<" ";
		 }
	   cout<<endl;
	     }
	   }
	   else
        cout<<"The operation you chose is invalid for the given matrices."<<endl;
    }
    //subtract two matrices

    if (op==2)
    {
        if(rowA==rowB&&columnA==columnB){
      double arraysub[ROWS][COLS];

      for(int i=0;i<rowA;i++)
        {


		    for(int j=0;j<columnA;j++)
		    {
			arraysub[i][j]=arrA[i][j]-arrB[i][j];
			cout<<arraysub[i][j]<<" ";
		    }

	     cout<<endl;
	    }
	    }
	   cout<<"The operation you chose is invalid for the given matrices."<<endl;

    }

    //the  multiplication
     if (op==3)
        {
      double arrayMultiplication[ROWS][COLS];
      int elementResult=0;

        if(columnA==rowB)
    {//to calculate the result of each element
      for(int i=0;i<rowA;i++)
    {


         for(int j=0;j<columnB;j++)
            {
                    arrayMultiplication[i][j]=0;
             for(int e=0;e<columnA;e++)
                {
                 elementResult+=arrA[i][e]*arrB[e][j];
                }
              arrayMultiplication[i][j]=elementResult;
              elementResult=0;
               cout<< arrayMultiplication[i][j]<<" ";
            }
              cout<<endl;
    }
    }
    else
        cout<<"The operation you chose is invalid for the given matrices."<<endl;
    }
   //Determine of first matrix
    if(op==5)
    {
        if(rowA==columnA){
         cout<<  determinant(arrA,rowA)<<endl;
        }
        else
    cout<<"The operation you chose is invalid for the given matrices."<<endl;

    }
    //Determine of second matrix
    if(op==6)
    {
        if(rowB==columnB){
         cout<<  determinant(arrB,rowB)<<endl;
        }
        else
    cout<<"The operation you chose is invalid for the given matrices."<<endl;

    }
    if(op==4)
    {
        if(rowB==columnA&&determinant(arrB,rowB)!=0&&rowB==columnB){
         double arr2[10][10];
         inverse(arrB,rowB,arr2);
         result_of_AinverseB(arrA,arr2,rowB,columnA,rowA);
        }
        else
    cout<<"The operation you chose is invalid for the given matrices."<<endl;

    }
    // to exit
     if (op==7)
    {
      cout<<"Thank you!"<<endl;
      break;

    }


cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
    cin>>op;

    }

}

