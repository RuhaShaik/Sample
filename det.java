import java.util.*;
import java.util.Scanner;
import java.io.*;
public class hai{
    public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("enter k:");
        int k = s.nextInt();
		double[][] a = new double[k][k];
		double[][] b = new double[k][1];
		System.out.println("enter a:");
		for(int i=0; i<k; i++) {
			for(int j=0; j<k; j++) {
				a[i][j] = s.nextInt();
			}
		}
		System.out.println("enter b:");
		for(int i=0; i<k; i++) {
				b[i][0] = s.nextInt();
		}
		double d = determinant(a, k);
		//System.out.println(d);
		if (d == 0)
			System.out.println("\nInverse of Entered Matrix is not possible\n");
		else
			eachdeterminant(a,b,k,d);
    }
	public static void eachdeterminant(double a[][], double b[][], int k, double d){
		int i,j;
		double[][] c = new double[k][k];
		for(j=0;j<k;j++){
			for (int l = 0; l < k; l++) {		    
                		System.arraycopy(a[l], 0, c[l], 0, k);         
            		}
			for(i=0;i<k;i++){
				c[i][j]=b[i][0];
			}
			System.out.println("\n"+(determinant(c,k)/d));
		}
	}
	
	public static double determinant(double a[][], int k){
		double s = 1, det = 0;
		double[][] b = new double[k][k];
		int i, j, m, n, c;
		if (k == 1){
			return (a[0][0]);
		}
		else{
			det = 0;
			for (c = 0; c < k; c++){
				m = 0;
				n = 0;
				for (i = 0;i < k; i++){
					for (j = 0 ;j < k; j++)	{
						b[i][j] = 0;
						if (i != 0 && j != c){
							b[m][n] = a[i][j];
							if (n < (k - 2))
								n++;
							else{
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
}

