import java.util.ArrayList;
import java.util.Arrays;

public class Sort {
	
	public static int[] data1 = {26,21,11,14,51,1,2,5,9,98,87,7,5,66,35,48,82,27,96,86,64,45,43,};
	public static int[] data2 = {26,21,11,14,51,1,2,5,9,98,87,7,5,66,35,48,82,27,96,86,64,45,43,};
    public static void swap(int[] d, int a, int b){
        int tmp = d[a];
        d[a] = d[b];
        d[b] = tmp;
    }
    public static void print(int[] d, String name){
    	System.out.println(name+" Sort : "+" length : "+d.length);
        for(int i:d){
            System.out.print(i+",");
        }
        System.out.println();
    }
    public static void print(int i){
    	System.out.println(i);
    }
    public static void print(int[] d){
        for(int i:d){
            System.out.print(i+",");
        }
        System.out.println();
    }
    public static void corret(int[] d){
        for (int i=1;i<d.length;i++){
            int j=i;
            int tmp=d[j];
            while (j>0&&tmp<d[j-1]){
                d[j]=d[--j];
            }
            d[j]=tmp;
        }
    }
	public static void main(String[] args){
		corret(data1);
		print(data1,"corret");
/****************************************************************************************************************/
		binarySort(data2);
		print(data2,"binarySort");
	}
/*******************************************************************************************************************
*/	    
    public static void binarySort(int[] d){
        for (int i=1;i<d.length;i++){
            int l=0,r=i-1;
            int j=i,tmp=d[i];
            while (l<=r){
                int mid=l+(r-l)/2;
                if (d[i]<d[mid]){
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            while (j>l){
                d[j]=d[--j];
            }
            d[j]=tmp;
        }
    }
}
