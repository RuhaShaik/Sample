#include <stdio.h>
#include <string.h>
#include<math.h>
float determinant(float [][3], float);
float eachdeterminant(float [][3],float [][1],float,float);
int main()
{
float a[3][3]={{2,2,3},{4,5,2},{7,8,9}}, k=3, d,b[3][1]={{6},{2},{3}};
  d = determinant(a, k);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   eachdeterminant(a,b,k,d);
    return 0;
}
float  eachdeterminant(float a[][3],float b[3][1],float k,float d){
int i,j,l,m;
float c[3][3];
for(j=0;j<k;j++){
   for(l=0;l<k;l++){
        for(m=0;m<k;m++){
            c[l][m]=a[l][m];
        }
    }
    for(i=0;i<k;i++){
    c[i][j]=b[i][0];
    
    }
   //for(l=0;l<k;l++){
   //    for(m=0;m<k;m++){
   //        printf("%f* ",c[l][m]);
   //    }
   //    printf("\n");
   //}
   //for(i=0;i<k;i++){
   //   
   //    c[j][i]=b[j][0];
   //   printf("%f ",c[j][i]);    
   //}
    printf("\n %f ", (determinant(c,k)/d));
}
}

float determinant(float a[3][3], float k)
{
  float s = 1, det = 0, b[3][3];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
}
 