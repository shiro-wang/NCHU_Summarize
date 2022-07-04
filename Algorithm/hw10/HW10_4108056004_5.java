
public class HW10_4108056004_5 extends SortingArray{
    public HW10_4108056004_5(){
    }
    static int[] aux = new int [1000000];
    
    public int[] sorting(int [] array){
        int n=array.length;
        merge(array,n);
        return array;
    }
    
    public static void merge(int[] number,int n){
        for(int i=0;i<n;i++){
            aux[i] = number[i];
        }
        sort(number, aux, 0, n-1,n);
    }
    public static void shellSort(int[] array, int lo, int hi){
        int h=1;
        int n=hi-lo;
        while(h<n/3) h=3*h+1;
        while(h>=1){
            for(int i=h+lo;i<hi+1;i++){
                for(int j=i;j>=h+lo && array[j]<array[j-h];j-=h){
                    swap(array, j, j-h);
                }
            }
            h=h/3;
        }
    }
    private static void sort(int[] number, int[] aux, int lo, int hi, int n) {
        if(hi<=lo) return;
        if(hi-lo<20){
            shellSort(number, lo, hi);
            for(int i=lo;i<=hi;i++){
                aux[i]=number[i];
            }
            return;
        }
        int mid = lo + (hi - lo)/2;
        sort(number,aux,lo,mid,n);
        sort(number,aux,mid+1,hi,n);
        if(number[mid+1]>=number[mid]) return;
        mergesort(number,aux,lo,mid,hi);
    }
    public static void insertionSort(int[] arr, int left, int right, int n)
    {
        for(int i=left+1;i<=right;i++){
            int j = i;
            while(j>left){
                if(arr[j]<arr[j-1]){
                    swap(arr, j, j-1);
                }else{
                    break;
                }
                j--;
            }
        }
        for(int i=0;i<n;i++){
            aux[i] = arr[i];
        }
    }
    private static void mergesort(int number[],int[] aux, int lo,int mid, int hi) {  
        int i = lo;
        int j = mid+1;
        for(int k=lo; k<=hi; k++){
            if(i>mid) number[k] = aux[j++];
            else if(j>hi) number[k] = aux[i++];
            else if(aux[i] < aux[j]){
                number[k] = aux[i++];
            }else{
                number[k] = aux[j++];
            }
        }
        for(i=lo;i<=hi;i++){
            aux[i]=number[i];
        }
    }
    private static void swap(int[] number, int i, int j) {
        int tmp = number[i];
        number[i]=number[j];
        number[j]=tmp;
    }
}
