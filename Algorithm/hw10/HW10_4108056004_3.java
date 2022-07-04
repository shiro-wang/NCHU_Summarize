
public class HW10_4108056004_3 extends SortingArray{
    public HW10_4108056004_3(){
    }
    
    public int[] sorting(int [] array){
        int n = array.length;
        shellSort(array,n);
        return array;
    }
    
    public static void shellSort(int[] array, int n){
        int h=1;
        while(h<n/3) h=3*h+1;
        while(h>=1){
            for(int i=h;i<n;i++){
                for(int j=i;j>=h && array[j]<array[j-h];j-=h){
                    swap(array, j, j-h);
                }
            }
            h=h/3;
        }
    }
    
    private static void swap(int[] number, int i, int j) {
        int tmp = number[i];
        number[i]=number[j];
        number[j]=tmp;
    }
}
